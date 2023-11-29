/*
 * autosarproject.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "autosarproject".
 *
 * Model version              : 18.2
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Nov 29 15:06:25 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_autosarproject_h_
#define RTW_HEADER_autosarproject_h_
#ifndef autosarproject_COMMON_INCLUDES_
#define autosarproject_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "HostLib_MMFile.h"
#include "HostLib_Multimedia.h"
#include "vipdrawtext_rt.h"
#endif                                 /* autosarproject_COMMON_INCLUDES_ */

#include "autosarproject_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T ColorSpaceConversion1_o1[64800];/* '<S3>/Color Space  Conversion1' */
  real32_T ColorSpaceConversion1_o2[64800];/* '<S3>/Color Space  Conversion1' */
  real32_T ColorSpaceConversion1_o3[64800];/* '<S3>/Color Space  Conversion1' */
  real32_T FromMultimediaFile_o1[64800];/* '<S3>/From Multimedia File' */
  real32_T FromMultimediaFile_o2[64800];/* '<S3>/From Multimedia File' */
  real32_T FromMultimediaFile_o3[64800];/* '<S3>/From Multimedia File' */
  real32_T DrawShapes1[194400];        /* '<S2>/Draw Shapes1' */
  real32_T Bias[18];                   /* '<S2>/Bias' */
  real32_T InsertText1[194400];        /* '<S2>/Insert Text1' */
  uint8_T BlobAnalysis1_o2[64800];     /* '<S1>/Blob Analysis1' */
  uint8_T Message[162];                /* '<S5>/MATLAB Function' */
  boolean_T Constant;                  /* '<S11>/Constant' */
  boolean_T Closing[64800];            /* '<S1>/Closing' */
  boolean_T Compare_j[64800];          /* '<S7>/Compare' */
} B_autosarproject_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_T BlobAnalysis1_STACK_DW[64800];/* '<S1>/Blob Analysis1' */
  int16_T BlobAnalysis1_N_PIXLIST_DW[64800];/* '<S1>/Blob Analysis1' */
  int16_T BlobAnalysis1_M_PIXLIST_DW[64800];/* '<S1>/Blob Analysis1' */
  boolean_T Closing_ONE_PAD_IMG_DW[81301];/* '<S1>/Closing' */
  boolean_T Closing_TWO_PAD_IMG_DW[81301];/* '<S1>/Closing' */
  uint8_T BlobAnalysis1_PAD_DW[65884]; /* '<S1>/Blob Analysis1' */
  real_T FromMultimediaFile_HostLib[137];/* '<S3>/From Multimedia File' */
  real_T FromMultimediaFile_AudioInfo[5];/* '<S3>/From Multimedia File' */
  real_T FromMultimediaFile_VideoInfo[11];/* '<S3>/From Multimedia File' */
  real32_T UnitDelay1_DSTATE[36];      /* '<S6>/Unit Delay1' */
  real32_T UnitDelay_DSTATE[9];        /* '<S6>/Unit Delay' */
  real32_T UnitDelay2_DSTATE;          /* '<S6>/Unit Delay2' */
  real32_T UnitDelay4_DSTATE[9];       /* '<S5>/Unit Delay4' */
  real32_T UnitDelay3_DSTATE[9];       /* '<S5>/Unit Delay3' */
  real32_T ColorSpaceConversion1_DWORK1[64800];/* '<S3>/Color Space  Conversion1' */
  real32_T DrawShapes1_DW_FillColorAdd[27];/* '<S2>/Draw Shapes1' */
  real32_T DrawShapes1_DW_OneMOpacity; /* '<S2>/Draw Shapes1' */
  real32_T InsertText1_colorVectorDW[3];/* '<S2>/Insert Text1' */
  int32_T Closing_NUMNONZ_DW[2];       /* '<S1>/Closing' */
  int32_T Closing_STREL_DW[2];         /* '<S1>/Closing' */
  int32_T Closing_ERODE_OFF_DW[30];    /* '<S1>/Closing' */
  int32_T Closing_DILATE_OFF_DW[30];   /* '<S1>/Closing' */
  int32_T BlobAnalysis1_DIMS1[2];      /* '<S1>/Blob Analysis1' */
  int32_T InsertText1_TxtLoc[2];       /* '<S2>/Insert Text1' */
  int32_T SFunction_DIMS2[2];          /* '<S1>/MATLAB Function' */
  uint32_T InsertText1_TxtSelctn;      /* '<S2>/Insert Text1' */
  uint8_T Output_DSTATE;               /* '<S10>/Output' */
  uint8_T InsertText1_RepBuf[167];     /* '<S2>/Insert Text1' */
  uint8_T InsertText1_VarHolder[163];  /* '<S2>/Insert Text1' */
  uint8_T InsertText1_StringDataDW[3]; /* '<S2>/Insert Text1' */
} DW_autosarproject_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: BlobAnalysis1_WALKER_RTP
   * Referenced by: '<S1>/Blob Analysis1'
   */
  int32_T BlobAnalysis1_WALKER_RTP[8];

  /* Computed Parameter: InsertText1_GlyLBearings
   * Referenced by: '<S2>/Insert Text1'
   */
  int32_T InsertText1_GlyLBearings[256];

  /* Computed Parameter: InsertText1_GlyTBearings
   * Referenced by: '<S2>/Insert Text1'
   */
  int32_T InsertText1_GlyTBearings[256];

  /* Computed Parameter: InsertText1_GlyIndexes
   * Referenced by: '<S2>/Insert Text1'
   */
  uint32_T InsertText1_GlyIndexes[256];

  /* Computed Parameter: InsertText1_GlyWidths
   * Referenced by: '<S2>/Insert Text1'
   */
  uint16_T InsertText1_GlyWidths[256];

  /* Computed Parameter: InsertText1_GlyHeights
   * Referenced by: '<S2>/Insert Text1'
   */
  uint16_T InsertText1_GlyHeights[256];

  /* Computed Parameter: InsertText1_GlyXAdvances
   * Referenced by: '<S2>/Insert Text1'
   */
  uint16_T InsertText1_GlyXAdvances[256];

  /* Computed Parameter: InsertText1_GlyData
   * Referenced by: '<S2>/Insert Text1'
   */
  uint8_T InsertText1_GlyData[4885];
} ConstP_autosarproject_T;

/* Parameters (default storage) */
struct P_autosarproject_T_ {
  real32_T template_detection[432];    /* Variable: template_detection
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real32_T template_detection_display[432];/* Variable: template_detection_display
                                            * Referenced by: '<S2>/Constant6'
                                            */
  real32_T template_ids[9];            /* Variable: template_ids
                                        * Referenced by: '<S5>/Constant5'
                                        */
  real32_T template_recognition[2916]; /* Variable: template_recognition
                                        * Referenced by: '<S5>/Constant8'
                                        */
  real32_T template_recognition_display[2916];/* Variable: template_recognition_display
                                               * Referenced by: '<S2>/Constant8'
                                               */
  uint8_T template_names[36];          /* Variable: template_names
                                        * Referenced by: '<S5>/Constant12'
                                        */
  int32_T DrawShapes_lineWidth;        /* Mask Parameter: DrawShapes_lineWidth
                                        * Referenced by: '<S2>/Draw Shapes'
                                        */
  real32_T DrawShapes_color[3];        /* Mask Parameter: DrawShapes_color
                                        * Referenced by: '<S2>/Draw Shapes'
                                        */
  real32_T DrawShapes1_color[3];       /* Mask Parameter: DrawShapes1_color
                                        * Referenced by: '<S2>/Draw Shapes1'
                                        */
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S7>/Constant'
                                       */
  real32_T ComparewithThreshold_const;
                                   /* Mask Parameter: ComparewithThreshold_const
                                    * Referenced by: '<S15>/Constant'
                                    */
  real32_T DrawShapes1_opacity;        /* Mask Parameter: DrawShapes1_opacity
                                        * Referenced by: '<S2>/Draw Shapes1'
                                        */
  real32_T InsertText1_textColor[3];   /* Mask Parameter: InsertText1_textColor
                                        * Referenced by: '<S2>/Insert Text1'
                                        */
  real32_T InsertText1_textOpacity;   /* Mask Parameter: InsertText1_textOpacity
                                       * Referenced by: '<S2>/Insert Text1'
                                       */
  uint8_T NSampleEnable_sample;        /* Mask Parameter: NSampleEnable_sample
                                        * Referenced by:
                                        *   '<S4>/Switch'
                                        *   '<S13>/FixPt Switch'
                                        */
  real32_T Constant7_Value[9];         /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S5>/Constant7'
                                        */
  real32_T Constant9_Value[9];         /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S5>/Constant9'
                                        */
  real32_T Constant3_Value[9];         /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S6>/Constant4'
                                        */
  real32_T Constant2_Value[36];        /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S9>/Constant'
                                        */
  real32_T UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<S6>/Unit Delay1'
                               */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S6>/Unit Delay'
                                */
  real32_T UnitDelay2_InitialCondition;
                              /* Computed Parameter: UnitDelay2_InitialCondition
                               * Referenced by: '<S6>/Unit Delay2'
                               */
  real32_T Threshold_Value;            /* Computed Parameter: Threshold_Value
                                        * Referenced by: '<S1>/Threshold'
                                        */
  real32_T Constant2_Value_g[18];      /* Computed Parameter: Constant2_Value_g
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real32_T MinimumCountNumber_Value;
                                 /* Computed Parameter: MinimumCountNumber_Value
                                  * Referenced by: '<S5>/Minimum Count Number'
                                  */
  real32_T MinimumSimilarity_Value;
                                  /* Computed Parameter: MinimumSimilarity_Value
                                   * Referenced by: '<S5>/Minimum Similarity'
                                   */
  real32_T UnitDelay4_InitialCondition;
                              /* Computed Parameter: UnitDelay4_InitialCondition
                               * Referenced by: '<S5>/Unit Delay4'
                               */
  real32_T UnitDelay3_InitialCondition;
                              /* Computed Parameter: UnitDelay3_InitialCondition
                               * Referenced by: '<S5>/Unit Delay3'
                               */
  real32_T Bias_Bias;                  /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S2>/Bias'
                                        */
  boolean_T Out1_Y0;                   /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S11>/Out1'
                                        */
  boolean_T Constant_Value_m;          /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S11>/Constant'
                                        */
  boolean_T Constant_Value_mm;         /* Computed Parameter: Constant_Value_mm
                                        * Referenced by: '<S4>/Constant'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S4>/Constant1'
                                        */
  uint8_T Constant_Value_b;            /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S13>/Constant'
                                        */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S10>/Output'
                                   */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S12>/FixPt Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_autosarproject_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_autosarproject_T autosarproject_P;

/* Block signals (default storage) */
extern B_autosarproject_T autosarproject_B;

/* Block states (default storage) */
extern DW_autosarproject_T autosarproject_DW;

/* Constant parameters (default storage) */
extern const ConstP_autosarproject_T autosarproject_ConstP;

/* Model entry point functions */
extern void autosarproject_initialize(void);
extern void autosarproject_step(void);
extern void autosarproject_terminate(void);

/* Real-time Model object */
extern RT_MODEL_autosarproject_T *const autosarproject_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'autosarproject'
 * '<S1>'   : 'autosarproject/Detection'
 * '<S2>'   : 'autosarproject/Display'
 * '<S3>'   : 'autosarproject/Input Video'
 * '<S4>'   : 'autosarproject/N-Sample Enable'
 * '<S5>'   : 'autosarproject/Recognition'
 * '<S6>'   : 'autosarproject/Tracking'
 * '<S7>'   : 'autosarproject/Detection/Compare To Constant'
 * '<S8>'   : 'autosarproject/Detection/MATLAB Function'
 * '<S9>'   : 'autosarproject/Display/Compare To Zero'
 * '<S10>'  : 'autosarproject/N-Sample Enable/Counter Limited'
 * '<S11>'  : 'autosarproject/N-Sample Enable/Enabled Subsystem'
 * '<S12>'  : 'autosarproject/N-Sample Enable/Counter Limited/Increment Real World'
 * '<S13>'  : 'autosarproject/N-Sample Enable/Counter Limited/Wrap To Zero'
 * '<S14>'  : 'autosarproject/Recognition/MATLAB Function'
 * '<S15>'  : 'autosarproject/Tracking/Compare with Threshold'
 * '<S16>'  : 'autosarproject/Tracking/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_autosarproject_h_ */
