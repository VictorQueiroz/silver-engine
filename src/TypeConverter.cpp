#include "TypeConverter.h"

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, uint32_t & out) {
    if(!val->IsUint32()) {
        return false;
    }
    out = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, double & out) {
    if(!val->IsNumber()) {
        return false;
    }
    out = Nan::To<v8::Number>(val).ToLocalChecked()->Value();
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, std::string & out) {
    if(!val->IsString()) {
        return false;
    }
    ssize_t len = Nan::DecodeBytes(val,Nan::Encoding::BINARY);
    char value[len];
    if(Nan::DecodeWrite(value, len, val, Nan::Encoding::BINARY) != len) return false;
    out = std::string(value,len);
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, bool& out) {
    if(!val->IsBoolean()) {
        return false;
    }
    out = Nan::To<v8::Boolean>(val).ToLocalChecked()->Value();
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, Magick::CompositeOperator& out) {
    uint32_t compositeOpInt;
    if(!TypeConverter::GetArgument(val,compositeOpInt)) {
        return false;
    }
    switch(compositeOpInt) {
        case 0:
            out = Magick::CompositeOperator::UndefinedCompositeOp;
            break;
        case 1:
            out = Magick::CompositeOperator::OverCompositeOp;
            break;
        case 2:
            out = Magick::CompositeOperator::InCompositeOp;
            break;
        case 3:
            out = Magick::CompositeOperator::OutCompositeOp;
            break;
        case 4:
            out = Magick::CompositeOperator::AtopCompositeOp;
            break;
        case 5:
            out = Magick::CompositeOperator::XorCompositeOp;
            break;
        case 6:
            out = Magick::CompositeOperator::PlusCompositeOp;
            break;
        case 7:
            out = Magick::CompositeOperator::MinusCompositeOp;
            break;
        case 8:
            out = Magick::CompositeOperator::AddCompositeOp;
            break;
        case 9:
            out = Magick::CompositeOperator::SubtractCompositeOp;
            break;
        case 10:
            out = Magick::CompositeOperator::DifferenceCompositeOp;
            break;
        case 11:
            out = Magick::CompositeOperator::MultiplyCompositeOp;
            break;
        case 12:
            out = Magick::CompositeOperator::BumpmapCompositeOp;
            break;
        case 13:
            out = Magick::CompositeOperator::CopyCompositeOp;
            break;
        case 14:
            out = Magick::CompositeOperator::CopyRedCompositeOp;
            break;
        case 15:
            out = Magick::CompositeOperator::CopyGreenCompositeOp;
            break;
        case 16:
            out = Magick::CompositeOperator::CopyBlueCompositeOp;
            break;
        case 17:
            out = Magick::CompositeOperator::CopyOpacityCompositeOp;
            break;
        case 18:
            out = Magick::CompositeOperator::ClearCompositeOp;
            break;
        case 19:
            out = Magick::CompositeOperator::DissolveCompositeOp;
            break;
        case 20:
            out = Magick::CompositeOperator::DisplaceCompositeOp;
            break;
        case 21:
            out = Magick::CompositeOperator::ModulateCompositeOp;
            break;
        case 22:
            out = Magick::CompositeOperator::ThresholdCompositeOp;
            break;
        case 23:
            out = Magick::CompositeOperator::NoCompositeOp;
            break;
        case 24:
            out = Magick::CompositeOperator::DarkenCompositeOp;
            break;
        case 25:
            out = Magick::CompositeOperator::LightenCompositeOp;
            break;
        case 26:
            out = Magick::CompositeOperator::HueCompositeOp;
            break;
        case 27:
            out = Magick::CompositeOperator::SaturateCompositeOp;
            break;
        case 28:
            out = Magick::CompositeOperator::ColorizeCompositeOp;
            break;
        case 29:
            out = Magick::CompositeOperator::LuminizeCompositeOp;
            break;
        case 30:
            out = Magick::CompositeOperator::ScreenCompositeOp;
            break;
        case 31:
            out = Magick::CompositeOperator::OverlayCompositeOp;
            break;
        case 32:
            out = Magick::CompositeOperator::CopyCyanCompositeOp;
            break;
        case 33:
            out = Magick::CompositeOperator::CopyMagentaCompositeOp;
            break;
        case 34:
            out = Magick::CompositeOperator::CopyYellowCompositeOp;
            break;
        case 35:
            out = Magick::CompositeOperator::CopyBlackCompositeOp;
            break;
        case 36:
            out = Magick::CompositeOperator::DivideCompositeOp;
            break;
        case 37:
            out = Magick::CompositeOperator::HardLightCompositeOp;
            break;
        case 38:
            out = Magick::CompositeOperator::ExclusionCompositeOp;
            break;
        case 39:
            out = Magick::CompositeOperator::ColorDodgeCompositeOp;
            break;
        case 40:
            out = Magick::CompositeOperator::ColorBurnCompositeOp;
            break;
        case 41:
            out = Magick::CompositeOperator::SoftLightCompositeOp;
            break;
        case 42:
            out = Magick::CompositeOperator::LinearBurnCompositeOp;
            break;
        case 43:
            out = Magick::CompositeOperator::LinearDodgeCompositeOp;
            break;
        case 44:
            out = Magick::CompositeOperator::LinearLightCompositeOp;
            break;
        case 45:
            out = Magick::CompositeOperator::VividLightCompositeOp;
            break;
        case 46:
            out = Magick::CompositeOperator::PinLightCompositeOp;
            break;
        case 47:
            out = Magick::CompositeOperator::HardMixCompositeOp;
            break;
        default:
            return false;
    }
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> value, float& v) {
    if(!value->IsNumber()) return false;
    v = float(Nan::To<v8::Number>(value).ToLocalChecked()->Value());
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, unsigned short& out) {
    if(!val->IsInt32()) return false;
    out = uint16_t(Nan::To<v8::Uint32>(val).ToLocalChecked()->Value());
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, unsigned char& out) {
    if(!val->IsUint32()) {
        return false;
    }
    out = uint8_t(Nan::To<v8::Uint32>(val).ToLocalChecked()->Value());
    return true;
}
