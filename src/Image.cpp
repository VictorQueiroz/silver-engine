#include "Image.h"
#include "TypeConverter.h"
#include "Geometry.h"
#include "Color.h"

using Nan::Set;
using v8::FunctionTemplate;
using v8::Local;
using v8::Value;

Nan::Persistent<v8::Function> Image::constructor;

void Image::Init(v8::Local<v8::Object> exports) {
    auto tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("Image").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl,"read",Read);
    Nan::SetPrototypeMethod(tpl,"write",Write);
    Nan::SetPrototypeMethod(tpl,"composite",Composite);
    Nan::SetPrototypeMethod(tpl,"backgroundColor",BackgroundColor);
    Nan::SetPrototypeMethod(tpl,"density",Density);
    Nan::SetPrototypeMethod(tpl,"magick",Magick);
    Nan::SetPrototypeMethod(tpl,"emboss",Emboss);
    Nan::SetPrototypeMethod(tpl,"negate",Negate);
    Nan::SetPrototypeMethod(tpl,"crop",Crop);
    Nan::SetPrototypeMethod(tpl,"compare",Compare);
    Nan::SetPrototypeMethod(tpl,"sample",Sample);
    Nan::SetPrototypeMethod(tpl,"normalize",Normalize);
    Nan::SetPrototypeMethod(tpl,"oilPaint",OilPaint);
    Nan::SetPrototypeMethod(tpl,"size",Size);
    Nan::SetPrototypeMethod(tpl,"motionBlur",MotionBlur);
    Nan::SetPrototypeMethod(tpl,"resize",Resize);
    Nan::SetPrototypeMethod(tpl,"shave",Shave);
    Nan::SetPrototypeMethod(tpl,"scale",Scale);
    Nan::SetPrototypeMethod(tpl,"rotate",Rotate);
    Nan::SetPrototypeMethod(tpl,"sample",Sample);
    Nan::SetPrototypeMethod(tpl,"scale",Scale);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());

    Set(exports,Nan::New("Image").ToLocalChecked(),Nan::GetFunction(tpl).ToLocalChecked());
}

NAN_METHOD(Image::New) {
    auto* img = new Image();
    img->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Image::Read) {
    std::string file;
    if(!TypeConverter::GetArgument(info[0],file)) {
        Nan::ThrowError("First argument must be a string");
        return;
    }
    auto* img = Unwrap<Image>(info.This());
    if(!img) {
        Nan::ThrowError("read() called under an invalid context");
        return;
    }
    try {
        img->value.read(file);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Write) {
    std::string file;
    if(!TypeConverter::GetArgument(info[0],file)) {
        Nan::ThrowError("First argument must be a string");
        return;
    }
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("write() called under an invalid context");
        return;
    }
    try {
        img->value.write(file);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Crop) {
    Geometry* g;
    if(!TypeConverter::Unwrap(info[0], &g)) {
        Nan::ThrowError("First argument must be a valid instance of the Geometry class");
        return;
    }
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("crop() called under invalid context");
        return;
    }
    try {
        img->value.crop(g->value);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Resize) {
    Geometry* g;
    if(!TypeConverter::Unwrap(info[0], &g)) {
        Nan::ThrowError("First argument must be a valid instance of the Geometry class");
        return;
    }
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("crop() called under invalid context");
        return;
    }
    try {
        img->value.resize(g->value);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Shave) {
    Geometry* g;
    if(!TypeConverter::Unwrap(info[0], &g)) {
        Nan::ThrowError("First argument must be a valid instance of the Geometry class");
        return;
    }
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("resize() called under invalid context");
        return;
    }
    try {
        img->value.shave(g->value);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::BackgroundColor) {
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("backgroundColor() called under invalid context");
        return;
    }
    Color* color;
    if(TypeConverter::Unwrap(info[0],&color)) {
        img->value.backgroundColor(color->value);
    } else {
        v8::Local<v8::Value> argv[] = {
            Nan::New(std::string(img->value.backgroundColor())).ToLocalChecked()
        };
        info.GetReturnValue().Set(Nan::NewInstance(
            Nan::New(Color::constructor),
            1,
            argv
        ).ToLocalChecked());
    }
}

NAN_METHOD(Image::Roll) {
    Geometry* g;
    if(!TypeConverter::Unwrap(info[0], &g)) {
        Nan::ThrowError("First argument must be a valid instance of the Geometry class");
        return;
    }
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("resize() called under invalid context");
        return;
    }
    try {
        img->value.roll(g->value);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Composite) {
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("composite() called under invalid context");
        return;
    }
    Image* compositeImage;
    if(!TypeConverter::Unwrap(info[0],&compositeImage)) {
        Nan::ThrowError("First argument must be a valid Image instance");
        return;
    }
    Geometry* g;
    if(!TypeConverter::Unwrap(info[1], &g)) {
        Nan::ThrowError("Second argument must be a valid instance of the Geometry class");
        return;
    }
    Magick::CompositeOperator compositeOp;
    if(!TypeConverter::GetArgument(info[2], compositeOp)) {
        compositeOp = Magick::CompositeOperator::InCompositeOp;
    }
    try {
        img->value.composite(compositeImage->value, g->value, compositeOp);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Scale) {
    Geometry* g;
    if(!TypeConverter::Unwrap(info[0], &g)) {
        Nan::ThrowError("First argument must be a valid instance of the Geometry class");
        return;
    }
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("resize() called under invalid context");
        return;
    }
    try {
        img->value.scale(g->value);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Sample) {
    Geometry* g;
    if(!TypeConverter::Unwrap(info[0], &g)) {
        Nan::ThrowError("First argument must be a valid instance of the Geometry class");
        return;
    }
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("resize() called under invalid context");
        return;
    }
    try {
        img->value.sample(g->value);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::MotionBlur) {
    double radius;
    double sigma;
    double angle;
    if(!TypeConverter::GetArgument(info[0], radius)) {
        Nan::ThrowError("First argument must be a valid double-precision integer");
        return;
    }
    if(!TypeConverter::GetArgument(info[1], sigma)) {
        Nan::ThrowError("Second argument must be a valid double-precision integer");
        return;
    }
    if(!TypeConverter::GetArgument(info[2], angle)) {
        Nan::ThrowError("Third argument must be a valid double-precision integer");
        return;
    }
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("resize() called under invalid context");
        return;
    }
    try {
        img->value.motionBlur(radius,sigma,angle);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Normalize) {
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("resize() called under invalid context");
        return;
    }
    try {
        img->value.normalize();
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Rotate) {
    double degrees;
    if(!TypeConverter::GetArgument(info[0], degrees)) {
        Nan::ThrowError("First argument must be a valid double-precision integer");
        return;
    }
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("resize() called under invalid context");
        return;
    }
    try {
        img->value.rotate(degrees);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::OilPaint) {
    double radius;
    if(!TypeConverter::GetArgument(info[0], radius)) {
        Nan::ThrowError("First argument must be a valid double-precision integer");
        return;
    }
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("resize() called under invalid context");
        return;
    }
    try {
        img->value.oilPaint(radius);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Emboss) {
    double radius;
    double sigma;
    if(!TypeConverter::GetArgument(info[0], radius)) {
        Nan::ThrowError("First argument must be a valid double-precision integer");
        return;
    }
    if(!TypeConverter::GetArgument(info[1], sigma)) {
        Nan::ThrowError("Second argument must be a valid double-precision integer");
        return;
    }
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("resize() called under invalid context");
        return;
    }
    try {
        img->value.emboss(radius,sigma);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Negate) {
    bool grayscale;
    if(!TypeConverter::GetArgument(info[0], grayscale)) {
        Nan::ThrowError("First argument must be a valid double-precision integer");
        return;
    }
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("resize() called under invalid context");
        return;
    }
    try {
        img->value.negate(grayscale);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Compare) {
    Image* img, *ref;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("compare() called under invalid context");
        return;
    }
    if(!TypeConverter::Unwrap(info[0],&ref)) {
        Nan::ThrowError("compare() called under invalid context");
        return;
    }
    try {
        info.GetReturnValue().Set(Nan::New(img->value.compare(ref->value)));
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Magick) {
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("magick() called under invalid context");
        return;
    }
    try {
        std::string format;
        if(TypeConverter::GetArgument(info[0],format)) {
            img->value.magick(format);
        } else {
            info.GetReturnValue().Set(Nan::New(img->value.magick()).ToLocalChecked());
        }
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Density) {
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("density() called under invalid context");
        return;
    }
    try {
        Geometry* density;
        if(TypeConverter::Unwrap(info[0],&density)) {
            img->value.density(density->value);
            return;
        }
        Local<v8::Value> argv[] {
            Nan::New(std::string(img->value.density())).ToLocalChecked()
        };
        info.GetReturnValue().Set(Nan::NewInstance(
            Nan::New(Geometry::constructor),
            1,
            argv
        ).ToLocalChecked());
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Size) {
    Image* img;
    if(!TypeConverter::Unwrap(info.This(),&img)) {
        Nan::ThrowError("density() called under invalid context");
        return;
    }
    try {
        Geometry* density;
        if(TypeConverter::Unwrap(info[0],&density)) {
            img->value.size(density->value);
            return;
        }
        Local<v8::Value> argv[] {
            Nan::New(std::string(img->value.size())).ToLocalChecked()
        };
        info.GetReturnValue().Set(Nan::NewInstance(
            Nan::New(Geometry::constructor),
            1,
            argv
        ).ToLocalChecked());
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}
