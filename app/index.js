"use strict";
Object.defineProperty(exports, "__esModule", { value: true });

exports.ChannelType = void 0;
var ChannelType;
(function (ChannelType) {
    ChannelType[ChannelType["UndefinedChannel"] = 0] = "UndefinedChannel";
    ChannelType[ChannelType["RedChannel"] = 1] = "RedChannel";
    ChannelType[ChannelType["GrayChannel"] = 1] = "GrayChannel";
    ChannelType[ChannelType["CyanChannel"] = 1] = "CyanChannel";
    ChannelType[ChannelType["LChannel"] = 1] = "LChannel";
    ChannelType[ChannelType["GreenChannel"] = 2] = "GreenChannel";
    ChannelType[ChannelType["MagentaChannel"] = 2] = "MagentaChannel";
    ChannelType[ChannelType["aChannel"] = 2] = "aChannel";
    ChannelType[ChannelType["BlueChannel"] = 4] = "BlueChannel";
    ChannelType[ChannelType["bChannel"] = 2] = "bChannel";
    ChannelType[ChannelType["YellowChannel"] = 4] = "YellowChannel";
    ChannelType[ChannelType["BlackChannel"] = 8] = "BlackChannel";
    ChannelType[ChannelType["AlphaChannel"] = 16] = "AlphaChannel";
    ChannelType[ChannelType["OpacityChannel"] = 16] = "OpacityChannel";
    ChannelType[ChannelType["IndexChannel"] = 32] = "IndexChannel";
    ChannelType[ChannelType["ReadMaskChannel"] = 64] = "ReadMaskChannel";
    ChannelType[ChannelType["WriteMaskChannel"] = 128] = "WriteMaskChannel";
    ChannelType[ChannelType["MetaChannel"] = 256] = "MetaChannel";
    ChannelType[ChannelType["CompositeMaskChannel"] = 512] = "CompositeMaskChannel";
    ChannelType[ChannelType["CompositeChannels"] = 31] = "CompositeChannels";
    ChannelType[ChannelType["AllChannels"] = 134217727] = "AllChannels";
    /*
        Special purpose channel types.
        FUTURE: are these needed any more - they are more like hacks
        SyncChannels for example is NOT a real channel but a 'flag'
        It really says -- "User has not defined channels"
        Though it does have extra meaning in the "-auto-level" operator
    */
    ChannelType[ChannelType["TrueAlphaChannel"] = 256] = "TrueAlphaChannel";
    ChannelType[ChannelType["RGBChannels"] = 512] = "RGBChannels";
    ChannelType[ChannelType["GrayChannels"] = 1024] = "GrayChannels";
    ChannelType[ChannelType["SyncChannels"] = 131072] = "SyncChannels";
    ChannelType[ChannelType["DefaultChannels"] = 134217727] = "DefaultChannels";
})(ChannelType = exports.ChannelType || (exports.ChannelType = {}));

exports.MetricType = void 0;
var MetricType;
(function (MetricType) {
    MetricType[MetricType["UndefinedMetric"] = 0] = "UndefinedMetric";
    MetricType[MetricType["AbsoluteErrorMetric"] = 1] = "AbsoluteErrorMetric";
    MetricType[MetricType["MeanAbsoluteErrorMetric"] = 2] = "MeanAbsoluteErrorMetric";
    MetricType[MetricType["MeanErrorPerPixelMetric"] = 3] = "MeanErrorPerPixelMetric";
    MetricType[MetricType["MeanSquaredErrorMetric"] = 4] = "MeanSquaredErrorMetric";
    MetricType[MetricType["PeakAbsoluteErrorMetric"] = 5] = "PeakAbsoluteErrorMetric";
    MetricType[MetricType["PeakSignalToNoiseRatioMetric"] = 6] = "PeakSignalToNoiseRatioMetric";
    MetricType[MetricType["RootMeanSquaredErrorMetric"] = 7] = "RootMeanSquaredErrorMetric";
    MetricType[MetricType["NormalizedCrossCorrelationErrorMetric"] = 8] = "NormalizedCrossCorrelationErrorMetric";
    MetricType[MetricType["FuzzErrorMetric"] = 9] = "FuzzErrorMetric";
    MetricType[MetricType["UndefinedErrorMetric"] = 10] = "UndefinedErrorMetric";
    MetricType[MetricType["PerceptualHashErrorMetric"] = 11] = "PerceptualHashErrorMetric";
})(MetricType = exports.MetricType || (exports.MetricType = {}));

exports.CompositeOperator = void 0;
var CompositeOperator;
(function (CompositeOperator) {
    CompositeOperator[CompositeOperator["UndefinedCompositeOp"] = 0] = "UndefinedCompositeOp";
    CompositeOperator[CompositeOperator["OverCompositeOp"] = 1] = "OverCompositeOp";
    CompositeOperator[CompositeOperator["InCompositeOp"] = 2] = "InCompositeOp";
    CompositeOperator[CompositeOperator["OutCompositeOp"] = 3] = "OutCompositeOp";
    CompositeOperator[CompositeOperator["AtopCompositeOp"] = 4] = "AtopCompositeOp";
    CompositeOperator[CompositeOperator["XorCompositeOp"] = 5] = "XorCompositeOp";
    CompositeOperator[CompositeOperator["PlusCompositeOp"] = 6] = "PlusCompositeOp";
    CompositeOperator[CompositeOperator["MinusCompositeOp"] = 7] = "MinusCompositeOp";
    CompositeOperator[CompositeOperator["AddCompositeOp"] = 8] = "AddCompositeOp";
    CompositeOperator[CompositeOperator["SubtractCompositeOp"] = 9] = "SubtractCompositeOp";
    CompositeOperator[CompositeOperator["DifferenceCompositeOp"] = 10] = "DifferenceCompositeOp";
    CompositeOperator[CompositeOperator["MultiplyCompositeOp"] = 11] = "MultiplyCompositeOp";
    CompositeOperator[CompositeOperator["BumpmapCompositeOp"] = 12] = "BumpmapCompositeOp";
    CompositeOperator[CompositeOperator["CopyCompositeOp"] = 13] = "CopyCompositeOp";
    CompositeOperator[CompositeOperator["CopyRedCompositeOp"] = 14] = "CopyRedCompositeOp";
    CompositeOperator[CompositeOperator["CopyGreenCompositeOp"] = 15] = "CopyGreenCompositeOp";
    CompositeOperator[CompositeOperator["CopyBlueCompositeOp"] = 16] = "CopyBlueCompositeOp";
    CompositeOperator[CompositeOperator["CopyOpacityCompositeOp"] = 17] = "CopyOpacityCompositeOp";
    CompositeOperator[CompositeOperator["ClearCompositeOp"] = 18] = "ClearCompositeOp";
    CompositeOperator[CompositeOperator["DissolveCompositeOp"] = 19] = "DissolveCompositeOp";
    CompositeOperator[CompositeOperator["DisplaceCompositeOp"] = 20] = "DisplaceCompositeOp";
    CompositeOperator[CompositeOperator["ModulateCompositeOp"] = 21] = "ModulateCompositeOp";
    CompositeOperator[CompositeOperator["ThresholdCompositeOp"] = 22] = "ThresholdCompositeOp";
    CompositeOperator[CompositeOperator["NoCompositeOp"] = 23] = "NoCompositeOp";
    CompositeOperator[CompositeOperator["DarkenCompositeOp"] = 24] = "DarkenCompositeOp";
    CompositeOperator[CompositeOperator["LightenCompositeOp"] = 25] = "LightenCompositeOp";
    CompositeOperator[CompositeOperator["HueCompositeOp"] = 26] = "HueCompositeOp";
    CompositeOperator[CompositeOperator["SaturateCompositeOp"] = 27] = "SaturateCompositeOp";
    CompositeOperator[CompositeOperator["ColorizeCompositeOp"] = 28] = "ColorizeCompositeOp";
    CompositeOperator[CompositeOperator["LuminizeCompositeOp"] = 29] = "LuminizeCompositeOp";
    CompositeOperator[CompositeOperator["ScreenCompositeOp"] = 30] = "ScreenCompositeOp";
    CompositeOperator[CompositeOperator["OverlayCompositeOp"] = 31] = "OverlayCompositeOp";
    CompositeOperator[CompositeOperator["CopyCyanCompositeOp"] = 32] = "CopyCyanCompositeOp";
    CompositeOperator[CompositeOperator["CopyMagentaCompositeOp"] = 33] = "CopyMagentaCompositeOp";
    CompositeOperator[CompositeOperator["CopyYellowCompositeOp"] = 34] = "CopyYellowCompositeOp";
    CompositeOperator[CompositeOperator["CopyBlackCompositeOp"] = 35] = "CopyBlackCompositeOp";
    CompositeOperator[CompositeOperator["DivideCompositeOp"] = 36] = "DivideCompositeOp";
    CompositeOperator[CompositeOperator["HardLightCompositeOp"] = 37] = "HardLightCompositeOp";
    CompositeOperator[CompositeOperator["ExclusionCompositeOp"] = 38] = "ExclusionCompositeOp";
    CompositeOperator[CompositeOperator["ColorDodgeCompositeOp"] = 39] = "ColorDodgeCompositeOp";
    CompositeOperator[CompositeOperator["ColorBurnCompositeOp"] = 40] = "ColorBurnCompositeOp";
    CompositeOperator[CompositeOperator["SoftLightCompositeOp"] = 41] = "SoftLightCompositeOp";
    CompositeOperator[CompositeOperator["LinearBurnCompositeOp"] = 42] = "LinearBurnCompositeOp";
    CompositeOperator[CompositeOperator["LinearDodgeCompositeOp"] = 43] = "LinearDodgeCompositeOp";
    CompositeOperator[CompositeOperator["LinearLightCompositeOp"] = 44] = "LinearLightCompositeOp";
    CompositeOperator[CompositeOperator["VividLightCompositeOp"] = 45] = "VividLightCompositeOp";
    CompositeOperator[CompositeOperator["PinLightCompositeOp"] = 46] = "PinLightCompositeOp";
    CompositeOperator[CompositeOperator["HardMixCompositeOp"] = 47] = "HardMixCompositeOp";
})(CompositeOperator = exports.CompositeOperator || (exports.CompositeOperator = {}));

Object.assign(exports, (
    process.env['NODE_ENV'] === 'development' ?
        require('../build/Debug/Debug/gmagick') :
        require('../build/Release/Release/gmagick')
));
