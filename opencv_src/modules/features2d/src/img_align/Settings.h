#ifndef IMGALIGN_SETTINGSH
#define IMGALIGN_SETTINGSH


#include <map>
#include <vector>
#include <string>
#include "EnumTypes.h"

namespace imgalign
{
  enum ParamType {
    
    eImageCap = 10,
    eImageCapInput = 11,
    
    eSift_featuresN = 20,
    eSift_octaveLayersN = 21,
    eSift_contrastThresh = 22,
    eSift_edgeThresh = 23,
    eSift_sigma = 24,
    
    eSurf_hessianThresh = 30,
    eSurf_octavesN = 31,
    eSurf_octaveLayersN = 32,
    eSurf_extended = 33,

    eOrb_featuresN = 40,
    eOrb_scale = 41,
    eOrb_levelsN = 42,
    eOrb_edgeThresh = 43,
    eOrb_patchSize = 44,

    eBrisk_thresh = 50,
    eBrisk_octavesN = 51,
    eBrisk_patternScale = 52,

    eKaze_thresh = 53,
    eKaze_octavesN = 54,
    eKaze_octaveLayersN = 55,
    
    eAkaze_thresh = 56,
    eAkaze_octavesN = 57,
    eAkaze_octaveLayersN = 58,

    eDetType_sift = 60,
    eDetType_surf = 61,
    eDetType_orb = 62,
    eDetType_brisk = 63,
    eDetType_kaze = 64,
    eDetType_akaze = 65,

    eDesType_sift = 80,
    eDesType_surf = 81,
    eDesType_orb = 82,
    eDesType_brisk = 83,
    eDesType_freak = 84,
    eDesType_kaze = 85,
    eDesType_akaze = 86,

    eMatcherType_flann = 100,
    eMatcherType_bfhamming = 101,
    eMatcherType_bfhamming2 = 102,
    eMatcherType_auto = 103,

    eTransformFinderType_ransac = 120,
    eTransformFinderType_rho = 121,
    eTransformFinderType_lmeds = 122,

    eCompareImageTypeFixed = 130,
    eCompareImageTypeMoving = 131,

    eMatchFilterSpreadAuto = 140,
    eMatchFilterSpreadFactor = 141,
    eMatchFilterMinMatchesToRetain = 142,
    eMatchFilterMaxMatchesToRetain = 143,

    eFloodFillTolerance = 150,
    eAlignSelectionOverlay = 151,
    eLogInfoEnabled = 152,
    eLogErrorEnabled = 153,
    eLogAssertEnabled = 154,
    eLogExternEnabled = 155,

    eDetType = 200,
    eDesType = 201,
    eMatcherType = 202,
    eTransformFinderType = 203,

    eCompareDetType = 301,
    eCompareImageType = 302,

    eStitch_projection = 303,
    eStitch_projection2 = 304,
    eStitch_seamBlend = 501,
    eStitch_colorTransfer = 502,
    eStitch_viewAngle1 = 511,
    eStitch_yaw1 = 513,
    eStitch_pitch1 = 514,
    eStitch_viewAngle2 = 521,
    eStitch_yaw2 = 523,
    eStitch_pitch2 = 524,

    eStitch_yaw2Auto = 525,
    eStitch_pitch2Auto = 526,

    eStitch_projectionTypePlane = 550,
    eStitch_projectionTypeAffine = 551,
    eStitch_projectionTypeCylindrical = 552,
    eStitch_projectionTypeSpherical = 553,
    eStitch_projectionTypeFisheye = 554,
    eStitch_projectionTypeStereographic = 555,
    eStitch_projectionTypeRectilinear = 556,
    eStitch_projectionTypeRectilinearPortrait = 557,
    eStitch_projectionTypePanini = 558,
    eStitch_projectionTypeMercator = 559,
    eStitch_projectionTypeTransverseMercator = 560,
    eStitch_projectionTypeNone = 561,

    eBundleAdjustType_none = 570,
    eBundleAdjustType_ray = 571,
    eBundleAdjustType_reproj = 572,

    eMultiStitch_projection = 305,
    eMultiStitch_rectify = 581,
    eMultiStitch_camEstimate = 582,
    eMultiStitch_bundleAdjustType = 583,
    eMultiStitch_waveCorrection = 584,
    eMultiStitch_seamBlend = 585,
    eMultiStitch_colorTransfer = 586,
    eMultiStitch_calcImageOrder = 587,
    eMultiStitch_calcCenterImage = 588,
    eMultiStitch_confidenceThresh = 589,
    eMultiStitch_exposureCompensator = 590


    // eStitch_projectionTypePlane2 = 570,
    // eStitch_projectionTypeAffine2 = 571,
    // eStitch_projectionTypeCylindrical2 = 572,
    // eStitch_projectionTypeSpherical2 = 573,
    // eStitch_projectionTypeFisheye2 = 574,
    // eStitch_projectionTypeStereographic2 = 575,
    // eStitch_projectionTypeRectilinear2 = 576,
    // eStitch_projectionTypeRectilinearPortrait2 = 577,
    // eStitch_projectionTypePanini2 = 578,
    // eStitch_projectionTypeMercator2 = 579,
    // eStitch_projectionTypeTransverseMercator2 = 580,
    // eStitch_projectionTypeNone2 = 581
  };

  class Settings {
    public:
      struct Param {
        float value;
        std::string name;
      };

    public:
      Settings();

      DetType getDetType() const;
      DesType getDesType() const;
      MatcherType getMatcherType() const;
      TransformFinderType getTransformFinderType() const;
      BundleAdjustType getBundleAdjustType() const;
      
      void init();
      float getValue(ParamType paramType) const;
      void setValues(
        const std::vector<int> &paramTypes,
        const std::vector<float> &paramValues);

      void logParams() const;

      static DetType getDetType(ParamType eDetType);

    private:
      std::map<ParamType, Param> paramValuesExt;

  };

} // imgalign

#endif