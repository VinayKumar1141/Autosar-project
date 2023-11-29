/*
 * autosarproject.c
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

#include "autosarproject.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <string.h>
#include <xmmintrin.h>
#include <math.h>
#include "rt_nonfinite.h"
#include "autosarproject_private.h"

/* Block signals (default storage) */
B_autosarproject_T autosarproject_B;

/* Block states (default storage) */
DW_autosarproject_T autosarproject_DW;

/* Real-time model */
static RT_MODEL_autosarproject_T autosarproject_M_;
RT_MODEL_autosarproject_T *const autosarproject_M = &autosarproject_M_;
int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absDenominator;
  uint32_T absNumerator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void autosarproject_step(void)
{
  __m128 tmp_0;
  __m128 tmp_1;
  __m128 tmp_2;
  __m128 tmp_3;
  __m128 tmp_4;
  int32_T rtb_BlobAnalysis1_o1[36];
  int32_T bufIdx;
  int32_T centerM;
  int32_T i;
  int32_T inIdx;
  int32_T j_pixListNinc;
  int32_T ku;
  int32_T line_idx_3;
  int32_T maxr;
  int32_T outIdx;
  int32_T outRedIndx;
  int32_T similarity_tmp;
  int32_T startC;
  int32_T startColList_tmp_tmp;
  int32_T startRowList_tmp_tmp;
  int32_T stepCols_tmp_tmp;
  real32_T feature_0[324];
  real32_T feature[144];
  real32_T disMatrix_data[81];
  real32_T bbox_data[36];
  real32_T rtb_BBox[36];
  real32_T rtb_BBox_e[36];
  real32_T rtb_Switch[36];
  real32_T rtb_MatrixConcatenate1[18];
  real32_T tmp[18];
  real32_T rtb_Count[9];
  real32_T rtb_Count_n[9];
  real32_T rtb_Status[9];
  real32_T rtb_Switch1[9];
  real32_T rtb_Switch3[9];
  real32_T endColList[3];
  real32_T endColList_0[3];
  real32_T endRowList[3];
  real32_T endRowList_0[3];
  real32_T startColList[3];
  real32_T startColList_0[3];
  real32_T startRowList[3];
  real32_T startRowList_0[3];
  real32_T bestConfidence;
  real32_T bestSimilarity;
  real32_T colSrc;
  real32_T colSrcFlt;
  real32_T ratioRows;
  real32_T similarity;
  real32_T startRow;
  real32_T stepCols;
  real32_T stepCols_tmp;
  real32_T stepRows;
  uint32_T BlobAnalysis1_NUM_PIX_DW[9];
  uint32_T padIdx;
  uint32_T pixIdx;
  uint32_T stackIdx;
  uint32_T walkerIdx;
  char_T *sErr;
  int8_T lenNames[3];
  int8_T inCol_tmp;
  uint8_T currentLabel;
  uint8_T rtb_Output;
  boolean_T rtb_Compare_f[9];
  boolean_T done;
  boolean_T exitg1;
  boolean_T maxNumBlobsReached;
  boolean_T visited1;
  boolean_T visited2;
  void *source_B;
  void *source_G;
  void *source_R;

  /* S-Function (sdspwmmfi2): '<S3>/From Multimedia File' */
  sErr = GetErrorBuffer(&autosarproject_DW.FromMultimediaFile_HostLib[0U]);
  source_R = (void *)&autosarproject_B.FromMultimediaFile_o1[0U];
  source_G = (void *)&autosarproject_B.FromMultimediaFile_o2[0U];
  source_B = (void *)&autosarproject_B.FromMultimediaFile_o3[0U];
  LibOutputs_FromMMFile(&autosarproject_DW.FromMultimediaFile_HostLib[0U],
                        GetNullPointer(), GetNullPointer(), source_R, source_G,
                        source_B);
  if (*sErr != 0) {
    rtmSetErrorStatus(autosarproject_M, sErr);
    rtmSetStopRequested(autosarproject_M, 1);
  }

  /* End of S-Function (sdspwmmfi2): '<S3>/From Multimedia File' */

  /* SignalConversion generated from: '<S3>/Matrix Concatenate' incorporates:
   *  S-Function (sdspwmmfi2): '<S3>/From Multimedia File'
   *  S-Function (svipdrawshapes): '<S2>/Draw Shapes'
   *  S-Function (svipdrawshapes): '<S2>/Draw Shapes1'
   */
  memcpy(&autosarproject_B.DrawShapes1[0],
         &autosarproject_B.FromMultimediaFile_o1[0], 64800U * sizeof(real32_T));

  /* SignalConversion generated from: '<S3>/Matrix Concatenate' incorporates:
   *  S-Function (sdspwmmfi2): '<S3>/From Multimedia File'
   *  S-Function (svipdrawshapes): '<S2>/Draw Shapes'
   *  S-Function (svipdrawshapes): '<S2>/Draw Shapes1'
   */
  memcpy(&autosarproject_B.DrawShapes1[64800],
         &autosarproject_B.FromMultimediaFile_o2[0], 64800U * sizeof(real32_T));

  /* SignalConversion generated from: '<S3>/Matrix Concatenate' incorporates:
   *  S-Function (sdspwmmfi2): '<S3>/From Multimedia File'
   *  S-Function (svipdrawshapes): '<S2>/Draw Shapes'
   *  S-Function (svipdrawshapes): '<S2>/Draw Shapes1'
   */
  memcpy(&autosarproject_B.DrawShapes1[129600],
         &autosarproject_B.FromMultimediaFile_o3[0], 64800U * sizeof(real32_T));

  /* UnitDelay: '<S10>/Output' */
  rtb_Output = autosarproject_DW.Output_DSTATE;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  UnitDelay: '<S10>/Output'
   */
  if (autosarproject_DW.Output_DSTATE >= autosarproject_P.NSampleEnable_sample)
  {
    maxNumBlobsReached = autosarproject_P.Constant_Value_mm;
  } else {
    maxNumBlobsReached = autosarproject_P.Constant1_Value;
  }

  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (maxNumBlobsReached) {
    autosarproject_B.Constant = autosarproject_P.Constant_Value_m;
  }

  /* End of Switch: '<S4>/Switch' */
  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant2'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  if (autosarproject_B.Constant) {
    memcpy(&rtb_Switch[0], &autosarproject_P.Constant2_Value[0], 36U * sizeof
           (real32_T));
  } else {
    memcpy(&rtb_Switch[0], &autosarproject_DW.UnitDelay1_DSTATE[0], 36U * sizeof
           (real32_T));
  }

  /* End of Switch: '<S6>/Switch' */

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/Constant3'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  for (i = 0; i < 9; i++) {
    if (autosarproject_B.Constant) {
      rtb_Switch1[i] = autosarproject_P.Constant3_Value[i];
    } else {
      rtb_Switch1[i] = autosarproject_DW.UnitDelay_DSTATE[i];
    }
  }

  /* End of Switch: '<S6>/Switch1' */
  for (i = 0; i <= 64796; i += 4) {
    /* S-Function (svipcolorconv): '<S3>/Color Space  Conversion1' incorporates:
     *  S-Function (sdspwmmfi2): '<S3>/From Multimedia File'
     */
    tmp_0 = _mm_loadu_ps(&autosarproject_B.FromMultimediaFile_o1[i]);
    tmp_1 = _mm_loadu_ps(&autosarproject_B.FromMultimediaFile_o2[i]);
    tmp_2 = _mm_loadu_ps(&autosarproject_B.FromMultimediaFile_o3[i]);

    /* S-Function (svipcolorconv): '<S3>/Color Space  Conversion1' */
    _mm_storeu_ps(&autosarproject_B.ColorSpaceConversion1_o1[i], _mm_add_ps
                  (_mm_add_ps(_mm_add_ps(_mm_mul_ps(tmp_0, _mm_set1_ps
      (0.256788224F)), _mm_set1_ps(0.0627451F)), _mm_mul_ps(tmp_1, _mm_set1_ps
      (0.50412941F))), _mm_mul_ps(tmp_2, _mm_set1_ps(0.0979058817F))));

    /* S-Function (svipcolorconv): '<S3>/Color Space  Conversion1' incorporates:
     *  S-Function (sdspwmmfi2): '<S3>/From Multimedia File'
     */
    tmp_0 = _mm_loadu_ps(&autosarproject_B.FromMultimediaFile_o1[i]);
    tmp_1 = _mm_set1_ps(0.501960814F);
    tmp_2 = _mm_loadu_ps(&autosarproject_B.FromMultimediaFile_o2[i]);
    tmp_3 = _mm_loadu_ps(&autosarproject_B.FromMultimediaFile_o3[i]);
    tmp_4 = _mm_set1_ps(0.43921569F);

    /* S-Function (svipcolorconv): '<S3>/Color Space  Conversion1' */
    _mm_storeu_ps(&autosarproject_B.ColorSpaceConversion1_o2[i], _mm_add_ps
                  (_mm_add_ps(_mm_add_ps(_mm_mul_ps(tmp_0, _mm_set1_ps
      (-0.148222893F)), tmp_1), _mm_mul_ps(tmp_2, _mm_set1_ps(-0.290992796F))),
                   _mm_mul_ps(tmp_3, tmp_4)));

    /* S-Function (svipcolorconv): '<S3>/Color Space  Conversion1' incorporates:
     *  S-Function (sdspwmmfi2): '<S3>/From Multimedia File'
     */
    tmp_0 = _mm_loadu_ps(&autosarproject_B.FromMultimediaFile_o1[i]);
    tmp_2 = _mm_loadu_ps(&autosarproject_B.FromMultimediaFile_o2[i]);
    tmp_3 = _mm_loadu_ps(&autosarproject_B.FromMultimediaFile_o3[i]);

    /* S-Function (svipcolorconv): '<S3>/Color Space  Conversion1' */
    _mm_storeu_ps(&autosarproject_B.ColorSpaceConversion1_o3[i], _mm_add_ps
                  (_mm_add_ps(_mm_add_ps(_mm_mul_ps(tmp_0, tmp_4), tmp_1),
      _mm_mul_ps(tmp_2, _mm_set1_ps(-0.367788315F))), _mm_mul_ps(tmp_3,
      _mm_set1_ps(-0.0714273751F))));
  }

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   *  S-Function (svipcolorconv): '<S3>/Color Space  Conversion1'
   */
  for (i = 0; i < 64800; i++) {
    autosarproject_B.Compare_j[i] = (autosarproject_B.ColorSpaceConversion1_o3[i]
      >= autosarproject_P.CompareToConstant_const);
  }

  /* End of RelationalOperator: '<S7>/Compare' */

  /* S-Function (svipmorphop): '<S1>/Closing' incorporates:
   *  RelationalOperator: '<S7>/Compare'
   */
  memset(&autosarproject_DW.Closing_ONE_PAD_IMG_DW[0], 0, 81301U * sizeof
         (boolean_T));
  for (inIdx = 0; inIdx < 64800; inIdx++) {
    if (autosarproject_B.Compare_j[inIdx]) {
      i = inIdx / 180;
      outIdx = (inIdx - i * 180) + i * 209;
      for (i = 0; i < autosarproject_DW.Closing_NUMNONZ_DW[0]; i++) {
        autosarproject_DW.Closing_ONE_PAD_IMG_DW[outIdx +
          autosarproject_DW.Closing_DILATE_OFF_DW[i]] = true;
      }
    }
  }

  memset(&autosarproject_DW.Closing_TWO_PAD_IMG_DW[0], 0, 81301U * sizeof
         (boolean_T));
  for (inIdx = 0; inIdx < 81301; inIdx++) {
    if (autosarproject_DW.Closing_ONE_PAD_IMG_DW[inIdx]) {
      for (i = 0; i < autosarproject_DW.Closing_NUMNONZ_DW[1]; i++) {
        autosarproject_DW.Closing_TWO_PAD_IMG_DW[inIdx +
          autosarproject_DW.Closing_DILATE_OFF_DW[autosarproject_DW.Closing_NUMNONZ_DW
          [0] + i]] = true;
      }
    }
  }

  inIdx = 1470;
  outIdx = 0;
  for (centerM = 0; centerM < 360; centerM++) {
    for (ku = 0; ku < 180; ku++) {
      autosarproject_B.Closing[outIdx] =
        autosarproject_DW.Closing_TWO_PAD_IMG_DW[inIdx];
      outIdx++;
      inIdx++;
    }

    inIdx += 29;
  }

  inIdx = 0;
  ku = 0;
  for (i = 0; i < 7; i++) {
    for (centerM = 0; centerM < 209; centerM++) {
      autosarproject_DW.Closing_ONE_PAD_IMG_DW[inIdx] = true;
      inIdx++;
    }
  }

  for (i = 0; i < 360; i++) {
    for (centerM = 0; centerM < 7; centerM++) {
      autosarproject_DW.Closing_ONE_PAD_IMG_DW[inIdx] = true;
      inIdx++;
    }

    memcpy(&autosarproject_DW.Closing_ONE_PAD_IMG_DW[inIdx],
           &autosarproject_B.Closing[ku], 180U * sizeof(boolean_T));
    inIdx += 180;
    ku += 180;
    for (centerM = 0; centerM < 22; centerM++) {
      autosarproject_DW.Closing_ONE_PAD_IMG_DW[inIdx] = true;
      inIdx++;
    }
  }

  for (i = 0; i < 22; i++) {
    for (centerM = 0; centerM < 209; centerM++) {
      autosarproject_DW.Closing_ONE_PAD_IMG_DW[inIdx] = true;
      inIdx++;
    }
  }

  for (i = 0; i < 81301; i++) {
    autosarproject_DW.Closing_TWO_PAD_IMG_DW[i] = true;
  }

  bufIdx = 0;
  for (centerM = 0; centerM < 389; centerM++) {
    for (ku = 0; ku < 195; ku++) {
      autosarproject_DW.Closing_TWO_PAD_IMG_DW[bufIdx + 7] = true;
      i = 0;
      while (i < autosarproject_DW.Closing_NUMNONZ_DW[0]) {
        if (!autosarproject_DW.Closing_ONE_PAD_IMG_DW[bufIdx +
            autosarproject_DW.Closing_ERODE_OFF_DW[i]]) {
          autosarproject_DW.Closing_TWO_PAD_IMG_DW[bufIdx + 7] = false;
          i = autosarproject_DW.Closing_NUMNONZ_DW[0];
        }

        i++;
      }

      bufIdx++;
    }

    bufIdx += 14;
  }

  inIdx = 7;
  outIdx = 0;
  for (centerM = 0; centerM < 360; centerM++) {
    for (ku = 7; ku < 187; ku++) {
      autosarproject_B.Closing[outIdx] = true;
      i = 0;
      while (i < autosarproject_DW.Closing_NUMNONZ_DW[1]) {
        if (!autosarproject_DW.Closing_TWO_PAD_IMG_DW[autosarproject_DW.Closing_ERODE_OFF_DW
            [i + autosarproject_DW.Closing_NUMNONZ_DW[0]] + inIdx]) {
          autosarproject_B.Closing[outIdx] = false;
          i = autosarproject_DW.Closing_NUMNONZ_DW[1];
        }

        i++;
      }

      inIdx++;
      outIdx++;
    }

    inIdx += 29;
  }

  /* End of S-Function (svipmorphop): '<S1>/Closing' */

  /* S-Function (svipblob): '<S1>/Blob Analysis1' incorporates:
   *  S-Function (svipmorphop): '<S1>/Closing'
   */
  maxNumBlobsReached = false;
  memset(&autosarproject_DW.BlobAnalysis1_PAD_DW[0], 0, 183U * sizeof(uint8_T));
  currentLabel = 1U;
  i = 0;
  inIdx = 183;
  for (centerM = 0; centerM < 360; centerM++) {
    for (ku = 0; ku < 180; ku++) {
      autosarproject_DW.BlobAnalysis1_PAD_DW[inIdx] = (uint8_T)
        (autosarproject_B.Closing[i] ? 255 : 0);
      i++;
      inIdx++;
    }

    autosarproject_DW.BlobAnalysis1_PAD_DW[inIdx] = 0U;
    autosarproject_DW.BlobAnalysis1_PAD_DW[inIdx + 1] = 0U;
    inIdx += 2;
  }

  memset(&autosarproject_DW.BlobAnalysis1_PAD_DW[inIdx], 0, 181U * sizeof
         (uint8_T));
  inIdx = 0;
  pixIdx = 0U;
  centerM = 0;
  while (centerM < 360) {
    outIdx = 0;
    bufIdx = (inIdx + 1) * 182;
    ku = 0;
    while (ku < 180) {
      padIdx = (uint32_T)((bufIdx + outIdx) + 1);
      if (autosarproject_DW.BlobAnalysis1_PAD_DW[padIdx] == 255) {
        autosarproject_DW.BlobAnalysis1_PAD_DW[padIdx] = currentLabel;
        autosarproject_DW.BlobAnalysis1_N_PIXLIST_DW[pixIdx] = (int16_T)inIdx;
        autosarproject_DW.BlobAnalysis1_M_PIXLIST_DW[pixIdx] = (int16_T)outIdx;
        pixIdx++;
        BlobAnalysis1_NUM_PIX_DW[currentLabel - 1] = 1U;
        autosarproject_DW.BlobAnalysis1_STACK_DW[0U] = padIdx;
        stackIdx = 1U;
        while (stackIdx != 0U) {
          stackIdx--;
          padIdx = autosarproject_DW.BlobAnalysis1_STACK_DW[stackIdx];
          for (i = 0; i < 8; i++) {
            walkerIdx = (uint32_T)((int32_T)padIdx +
              autosarproject_ConstP.BlobAnalysis1_WALKER_RTP[i]);
            if (autosarproject_DW.BlobAnalysis1_PAD_DW[walkerIdx] == 255) {
              autosarproject_DW.BlobAnalysis1_PAD_DW[walkerIdx] = currentLabel;
              autosarproject_DW.BlobAnalysis1_N_PIXLIST_DW[pixIdx] = (int16_T)
                ((int16_T)(walkerIdx / 182U) - 1);
              autosarproject_DW.BlobAnalysis1_M_PIXLIST_DW[pixIdx] = (int16_T)
                (walkerIdx % 182U - 1U);
              pixIdx++;
              BlobAnalysis1_NUM_PIX_DW[currentLabel - 1]++;
              autosarproject_DW.BlobAnalysis1_STACK_DW[stackIdx] = walkerIdx;
              stackIdx++;
            }
          }
        }

        if (currentLabel == 9) {
          maxNumBlobsReached = true;
          centerM = 360;
          ku = 180;
        } else {
          currentLabel++;
        }
      }

      outIdx++;
      ku++;
    }

    inIdx++;
    centerM++;
  }

  stackIdx = (uint32_T)(maxNumBlobsReached ? (int32_T)currentLabel : (int32_T)
                        (uint8_T)(currentLabel - 1));
  i = 0;
  inIdx = 183;
  for (centerM = 0; centerM < 360; centerM++) {
    memcpy(&autosarproject_B.BlobAnalysis1_o2[i],
           &autosarproject_DW.BlobAnalysis1_PAD_DW[inIdx], 180U * sizeof(uint8_T));
    i += 180;
    inIdx += 182;
  }

  if (currentLabel == 9) {
    for (i = 0; i < 64800; i++) {
      if (autosarproject_B.BlobAnalysis1_o2[i] == 255) {
        autosarproject_B.BlobAnalysis1_o2[i] = 0U;
      }
    }
  }

  inIdx = 0;
  ku = 0;
  for (i = 0; i < (int32_T)stackIdx; i++) {
    outIdx = 360;
    bufIdx = 180;
    startC = 0;
    maxr = 0;
    for (centerM = 0; centerM < (int32_T)BlobAnalysis1_NUM_PIX_DW[i]; centerM++)
    {
      j_pixListNinc = centerM + ku;
      if (autosarproject_DW.BlobAnalysis1_N_PIXLIST_DW[j_pixListNinc] < outIdx)
      {
        outIdx = autosarproject_DW.BlobAnalysis1_N_PIXLIST_DW[j_pixListNinc];
      }

      if (autosarproject_DW.BlobAnalysis1_N_PIXLIST_DW[j_pixListNinc] > startC)
      {
        startC = autosarproject_DW.BlobAnalysis1_N_PIXLIST_DW[j_pixListNinc];
      }

      if (autosarproject_DW.BlobAnalysis1_M_PIXLIST_DW[j_pixListNinc] < bufIdx)
      {
        bufIdx = autosarproject_DW.BlobAnalysis1_M_PIXLIST_DW[j_pixListNinc];
      }

      if (autosarproject_DW.BlobAnalysis1_M_PIXLIST_DW[j_pixListNinc] > maxr) {
        maxr = autosarproject_DW.BlobAnalysis1_M_PIXLIST_DW[j_pixListNinc];
      }
    }

    rtb_BlobAnalysis1_o1[i] = outIdx + 1;
    rtb_BlobAnalysis1_o1[stackIdx + (uint32_T)i] = bufIdx + 1;
    rtb_BlobAnalysis1_o1[((int32_T)stackIdx << 1) + i] = (startC - outIdx) + 1;
    rtb_BlobAnalysis1_o1[3 * (int32_T)stackIdx + i] = (maxr - bufIdx) + 1;
    inIdx += (int32_T)BlobAnalysis1_NUM_PIX_DW[i];
    ku = inIdx;
  }

  autosarproject_DW.BlobAnalysis1_DIMS1[0] = (int32_T)stackIdx;
  autosarproject_DW.BlobAnalysis1_DIMS1[1] = 4;

  /* End of S-Function (svipblob): '<S1>/Blob Analysis1' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Constant6'
   *  Constant: '<S1>/Threshold'
   *  S-Function (svipblob): '<S1>/Blob Analysis1'
   *  S-Function (svipcolorconv): '<S3>/Color Space  Conversion1'
   */
  /* MATLAB Function 'Detection/MATLAB Function': '<S8>:1' */
  /* '<S8>:1:32' */
  /* '<S8>:1:34' */
  autosarproject_DW.SFunction_DIMS2[0] = autosarproject_DW.BlobAnalysis1_DIMS1[0];
  autosarproject_DW.SFunction_DIMS2[1] = 4;
  centerM = autosarproject_DW.BlobAnalysis1_DIMS1[0] << 2;
  for (maxr = 0; maxr < centerM; maxr++) {
    rtb_BBox_e[maxr] = 0.0F;
  }

  i = autosarproject_DW.BlobAnalysis1_DIMS1[0];

  /* '<S8>:1:37' */
  for (inIdx = 0; inIdx < i; inIdx++) {
    /* '<S8>:1:38' */
    bestSimilarity = 0.0F;
    if ((rtb_BlobAnalysis1_o1[autosarproject_DW.BlobAnalysis1_DIMS1[0] * 3 +
         inIdx] >= 12) && (rtb_BlobAnalysis1_o1
                           [(autosarproject_DW.BlobAnalysis1_DIMS1[0] << 1) +
                           inIdx] >= 12)) {
      /* '<S8>:1:40' */
      /* '<S8>:1:42' */
      bestConfidence = (real32_T)
        rtb_BlobAnalysis1_o1[autosarproject_DW.BlobAnalysis1_DIMS1[0] * 3 +
        inIdx];
      stepRows = (real32_T)floor(bestConfidence / 12.0F);

      /* '<S8>:1:43' */
      stepCols_tmp_tmp = rtb_BlobAnalysis1_o1
        [(autosarproject_DW.BlobAnalysis1_DIMS1[0] << 1) + inIdx];
      stepCols = (real32_T)floor((real32_T)stepCols_tmp_tmp / 12.0F);

      /* '<S8>:1:48' */
      startColList_tmp_tmp = rtb_BlobAnalysis1_o1[inIdx];
      startColList[1] = (real32_T)startColList_tmp_tmp;

      /* '<S8>:1:49' */
      startRow = (real32_T)startColList_tmp_tmp - stepCols;
      if (startRow <= 1.0F) {
        startColList[0] = 1.0F;
      } else {
        startColList[0] = startRow;
      }

      /* '<S8>:1:50' */
      startRow = (real32_T)startColList_tmp_tmp + stepCols;
      if (startRow >= 180.0F) {
        startColList[2] = 180.0F;
      } else {
        startColList[2] = startRow;
      }

      /* '<S8>:1:53' */
      if ((startColList_tmp_tmp < 0) && (stepCols_tmp_tmp < MIN_int32_T
           - startColList_tmp_tmp)) {
        centerM = MIN_int32_T;
      } else if ((startColList_tmp_tmp > 0) && (stepCols_tmp_tmp > MAX_int32_T -
                  startColList_tmp_tmp)) {
        centerM = MAX_int32_T;
      } else {
        centerM = startColList_tmp_tmp + stepCols_tmp_tmp;
      }

      if (centerM < -2147483647) {
        centerM = MIN_int32_T;
      } else {
        centerM--;
      }

      endColList[1] = (real32_T)centerM;

      /* '<S8>:1:54' */
      startRow = (real32_T)centerM - stepCols;
      if (startRow <= 1.0F) {
        endColList[0] = 1.0F;
      } else {
        endColList[0] = startRow;
      }

      /* '<S8>:1:55' */
      startRow = (real32_T)centerM + stepCols;
      if (startRow >= 180.0F) {
        endColList[2] = 180.0F;
      } else {
        endColList[2] = startRow;
      }

      /* '<S8>:1:58' */
      startRowList_tmp_tmp = rtb_BlobAnalysis1_o1[inIdx +
        autosarproject_DW.BlobAnalysis1_DIMS1[0]];
      startRowList[1] = (real32_T)startRowList_tmp_tmp;

      /* '<S8>:1:59' */
      startRow = (real32_T)startRowList_tmp_tmp - stepRows;
      if ((startRow <= 1.0F) || rtIsNaNF(startRow)) {
        startRowList[0] = 1.0F;
      } else {
        startRowList[0] = startRow;
      }

      /* '<S8>:1:60' */
      startRow = (real32_T)startRowList_tmp_tmp + stepRows;
      if ((startRow >= 360.0F) || rtIsNaNF(startRow)) {
        startRowList[2] = 360.0F;
      } else {
        startRowList[2] = startRow;
      }

      /* '<S8>:1:63' */
      ku = rtb_BlobAnalysis1_o1[autosarproject_DW.BlobAnalysis1_DIMS1[0] * 3 +
        inIdx];
      if ((startRowList_tmp_tmp < 0) && (ku < MIN_int32_T - startRowList_tmp_tmp))
      {
        centerM = MIN_int32_T;
      } else if ((startRowList_tmp_tmp > 0) && (ku > MAX_int32_T
                  - startRowList_tmp_tmp)) {
        centerM = MAX_int32_T;
      } else {
        centerM = startRowList_tmp_tmp + ku;
      }

      if (centerM < -2147483647) {
        centerM = MIN_int32_T;
      } else {
        centerM--;
      }

      endRowList[1] = (real32_T)centerM;

      /* '<S8>:1:64' */
      startRow = (real32_T)centerM - stepRows;
      if ((startRow <= 1.0F) || rtIsNaNF(startRow)) {
        endRowList[0] = 1.0F;
      } else {
        endRowList[0] = startRow;
      }

      /* '<S8>:1:65' */
      startRow = (real32_T)centerM + stepRows;
      if ((startRow >= 360.0F) || rtIsNaNF(startRow)) {
        endRowList[2] = 360.0F;
      } else {
        endRowList[2] = startRow;
      }

      /* '<S8>:1:33' */
      /* '<S8>:1:68' */
      for (centerM = 0; centerM < 3; centerM++) {
        stepRows = startColList[centerM];

        /* '<S8>:1:33' */
        /* '<S8>:1:69' */
        for (outIdx = 0; outIdx < 3; outIdx++) {
          /* '<S8>:1:70' */
          stepCols = (endColList[outIdx] - stepRows) / 12.0F;

          /* '<S8>:1:33' */
          /* '<S8>:1:71' */
          for (bufIdx = 0; bufIdx < 3; bufIdx++) {
            startRow = startRowList[bufIdx];

            /* '<S8>:1:33' */
            /* '<S8>:1:72' */
            for (startC = 0; startC < 3; startC++) {
              /* '<S8>:1:73' */
              ratioRows = (endRowList[startC] - startRow) / 12.0F;

              /* '<S8>:1:76' */
              colSrcFlt = stepRows;

              /* '<S8>:1:77' */
              for (ku = 0; ku < 12; ku++) {
                /* '<S8>:1:78' */
                colSrc = (real32_T)floor(colSrcFlt);

                /* '<S8>:1:79' */
                /* '<S8>:1:80' */
                for (maxr = 0; maxr < 12; maxr++) {
                  /* '<S8>:1:81' */
                  /* '<S8>:1:82' */
                  feature[maxr + 12 * ku] =
                    autosarproject_B.ColorSpaceConversion1_o3[((int32_T)
                    (real32_T)floor((real32_T)maxr * ratioRows + startRow) +
                    ((int32_T)colSrc - 1) * 180) - 1];

                  /* '<S8>:1:83' */
                }

                /* '<S8>:1:85' */
                colSrcFlt += stepCols;
              }

              /* '<S8>:1:89' */
              ratioRows = feature[0];
              for (ku = 0; ku < 143; ku++) {
                ratioRows += feature[ku + 1];
              }

              ratioRows /= 144.0F;
              for (maxr = 0; maxr <= 140; maxr += 4) {
                tmp_0 = _mm_loadu_ps(&feature[maxr]);
                _mm_storeu_ps(&feature[maxr], _mm_sub_ps(tmp_0, _mm_set1_ps
                  (ratioRows)));
              }

              /* '<S8>:1:92' */
              for (ku = 0; ku < 3; ku++) {
                /* '<S8>:1:93' */
                similarity = 0.0F;

                /* '<S8>:1:95' */
                for (maxr = 0; maxr < 12; maxr++) {
                  /* '<S8>:1:96' */
                  for (j_pixListNinc = 0; j_pixListNinc < 12; j_pixListNinc++) {
                    /* '<S8>:1:97' */
                    similarity_tmp = 12 * maxr + j_pixListNinc;
                    similarity += autosarproject_P.template_detection[144 * ku +
                      similarity_tmp] * feature[similarity_tmp];
                  }
                }

                if (similarity > bestSimilarity) {
                  /* '<S8>:1:101' */
                  /* '<S8>:1:102' */
                  bestSimilarity = similarity;
                }
              }
            }
          }
        }
      }

      if (bestSimilarity >= autosarproject_P.Threshold_Value) {
        /* '<S8>:1:111' */
        /* '<S8>:1:112' */
        rtb_BBox_e[inIdx] = (real32_T)startColList_tmp_tmp;

        /* '<S8>:1:113' */
        rtb_BBox_e[inIdx + autosarproject_DW.SFunction_DIMS2[0]] = (real32_T)
          startRowList_tmp_tmp;

        /* '<S8>:1:114' */
        rtb_BBox_e[inIdx + (autosarproject_DW.SFunction_DIMS2[0] << 1)] =
          (real32_T)stepCols_tmp_tmp;

        /* '<S8>:1:115' */
        rtb_BBox_e[inIdx + autosarproject_DW.SFunction_DIMS2[0] * 3] =
          bestConfidence;
      }
    }
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* Switch: '<S6>/Switch2' */
  if (autosarproject_B.Constant) {
    /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
     *  Constant: '<S6>/Constant4'
     */
    bestSimilarity = autosarproject_P.Constant4_Value;
  } else {
    /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
     *  UnitDelay: '<S6>/Unit Delay2'
     */
    bestSimilarity = autosarproject_DW.UnitDelay2_DSTATE;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
   *  Switch: '<S6>/Switch'
   */
  startC = autosarproject_DW.SFunction_DIMS2[0];
  j_pixListNinc = autosarproject_DW.SFunction_DIMS2[1];
  centerM = autosarproject_DW.SFunction_DIMS2[0] *
    autosarproject_DW.SFunction_DIMS2[1];
  if (centerM - 1 >= 0) {
    memcpy(&bbox_data[0], &rtb_BBox_e[0], (uint32_T)centerM * sizeof(real32_T));
  }

  /* MATLAB Function 'Tracking/MATLAB Function': '<S16>:1' */
  /* '<S16>:1:73' */
  /* '<S16>:1:74' */
  /* '<S16>:1:30' */
  ku = autosarproject_DW.SFunction_DIMS2[0] - 1;

  /* '<S16>:1:31' */
  for (i = 0; i < 36; i++) {
    rtb_BBox[i] = 0.0F;
  }

  /* '<S16>:1:32' */
  for (i = 0; i < 9; i++) {
    rtb_Count[i] = 0.0F;
  }

  /* '<S16>:1:35' */
  similarity_tmp = autosarproject_DW.SFunction_DIMS2[0];
  centerM = 9 * autosarproject_DW.SFunction_DIMS2[0];
  for (maxr = 0; maxr < centerM; maxr++) {
    disMatrix_data[maxr] = 10000.0F;
  }

  /* '<S16>:1:38' */
  for (inIdx = 0; inIdx < 9; inIdx++) {
    stepRows = rtb_Switch[inIdx + 18];
    if (stepRows > 0.0F) {
      /* '<S16>:1:39' */
      similarity = rtb_Switch[inIdx + 27];
      if (similarity > 0.0F) {
        /* '<S16>:1:39' */
        /* '<S16>:1:40' */
        for (centerM = 0; centerM <= ku; centerM++) {
          if (((int32_T)rtb_BBox_e[(autosarproject_DW.SFunction_DIMS2[0] << 1) +
               centerM] > 0) && ((int32_T)
                                 rtb_BBox_e[autosarproject_DW.SFunction_DIMS2[0]
               * 3 + centerM] > 0)) {
            /* '<S16>:1:41' */
            /* '<S16>:1:42' */
            bestConfidence = rtb_BBox_e[(autosarproject_DW.SFunction_DIMS2[0] <<
              1) + centerM];
            stepCols = rtb_BBox_e[autosarproject_DW.SFunction_DIMS2[0] * 3 +
              centerM];
            disMatrix_data[inIdx + 9 * centerM] = (real32_T)fabs
              (((rtb_Switch[inIdx + 9] - rtb_BBox_e[centerM +
                 autosarproject_DW.SFunction_DIMS2[0]]) * 2.0F + similarity) -
               stepCols) / (stepCols + similarity) + (real32_T)fabs
              (((rtb_Switch[inIdx] - rtb_BBox_e[centerM]) * 2.0F + stepRows) -
               bestConfidence) / (bestConfidence + stepRows);
          }
        }
      }
    }
  }

  /* '<S16>:1:55' */
  centerM = 0;
  exitg1 = false;
  while ((!exitg1) && (centerM <= ku)) {
    /* '<S16>:1:55' */
    /* '<S16>:1:56' */
    stepRows = 10000.0F;

    /* '<S16>:1:57' */
    outIdx = -1;

    /* '<S16>:1:58' */
    bufIdx = -1;

    /* '<S16>:1:59' */
    for (i = 0; i < 9; i++) {
      /* '<S16>:1:60' */
      for (inIdx = 0; inIdx <= ku; inIdx++) {
        similarity = disMatrix_data[9 * inIdx + i];
        if (similarity < stepRows) {
          /* '<S16>:1:61' */
          /* '<S16>:1:62' */
          stepRows = similarity;

          /* '<S16>:1:63' */
          outIdx = i;

          /* '<S16>:1:64' */
          bufIdx = inIdx;
        }
      }
    }

    if (stepRows < 2.0F) {
      /* '<S16>:1:71' */
      /* '<S16>:1:72' */
      for (maxr = 0; maxr < similarity_tmp; maxr++) {
        disMatrix_data[outIdx + 9 * maxr] = 10000.0F;
      }

      /* '<S16>:1:73' */
      for (maxr = 0; maxr < 9; maxr++) {
        disMatrix_data[maxr + 9 * bufIdx] = 10000.0F;
      }

      /* '<S16>:1:74' */
      rtb_BBox[outIdx] = bbox_data[bufIdx];
      rtb_BBox[outIdx + 9] = bbox_data[bufIdx + startC];
      rtb_BBox[outIdx + 18] = bbox_data[(startC << 1) + bufIdx];
      rtb_BBox[outIdx + 27] = bbox_data[startC * 3 + bufIdx];

      /* '<S16>:1:75' */
      rtb_Count[outIdx] = rtb_Switch1[outIdx] + 1.0F;

      /* '<S16>:1:76' */
      for (maxr = 0; maxr < j_pixListNinc; maxr++) {
        bbox_data[bufIdx + startC * maxr] = 0.0F;
      }

      centerM++;
    } else {
      exitg1 = true;
    }
  }

  /* '<S16>:1:83' */
  centerM = autosarproject_DW.SFunction_DIMS2[0];

  /* '<S16>:1:84' */
  for (i = 0; i < centerM; i++) {
    stepRows = bbox_data[(startC << 1) + i];
    if (stepRows > 0.0F) {
      /* '<S16>:1:85' */
      while (rtb_BBox[(int32_T)bestSimilarity + 17] != 0.0F) {
        if (bestSimilarity < 9.0F) {
          /* '<S16>:1:87' */
          /* '<S16>:1:88' */
          bestSimilarity++;
        } else {
          /* '<S16>:1:90' */
          bestSimilarity = 1.0F;
        }
      }

      /* '<S16>:1:93' */
      rtb_BBox[(int32_T)bestSimilarity - 1] = bbox_data[i];
      rtb_BBox[(int32_T)bestSimilarity + 8] = bbox_data[i + startC];
      rtb_BBox[(int32_T)bestSimilarity + 17] = stepRows;
      rtb_BBox[(int32_T)bestSimilarity + 26] = bbox_data[startC * 3 + i];

      /* '<S16>:1:94' */
      rtb_Count[(int32_T)bestSimilarity - 1] = 1.0F;
      if (bestSimilarity < 9.0F) {
        /* '<S16>:1:95' */
        /* '<S16>:1:96' */
        bestSimilarity++;
      } else {
        /* '<S16>:1:98' */
        bestSimilarity = 1.0F;
      }
    }
  }

  /* S-Function (svipdrawshapes): '<S2>/Draw Shapes' incorporates:
   *  S-Function (svipdrawshapes): '<S2>/Draw Shapes1'
   */
  /* Copy the image from input to output. */
  /* Update view port. */
  /* Draw all rectangles. */
  centerM = 0;
  for (inIdx = 0; inIdx < 9; inIdx++) {
    /* Selector: '<S2>/Selector1' */
    similarity = rtb_BBox[inIdx + 9];
    if ((real32_T)fabs(similarity) >= 0.5F) {
      stepCols = (real32_T)floor(similarity + 0.5F);
    } else {
      stepCols = similarity * 0.0F;
    }

    ku = (int32_T)stepCols - 1;
    stepRows = rtb_BBox[inIdx];
    if ((real32_T)fabs(stepRows) >= 0.5F) {
      startRow = (real32_T)floor(stepRows + 0.5F);
    } else {
      startRow = stepRows * 0.0F;
    }

    bufIdx = (int32_T)startRow - 1;

    /* Selector: '<S2>/Selector2' */
    bestConfidence = rtb_BBox[inIdx + 27];
    if ((real32_T)fabs(bestConfidence) >= 0.5F) {
      stepCols_tmp = (real32_T)floor(bestConfidence + 0.5F);
    } else {
      stepCols_tmp = bestConfidence * 0.0F;
    }

    startC = ((int32_T)stepCols + (int32_T)stepCols_tmp) - 2;
    stepRows = rtb_BBox[inIdx + 18];
    if ((real32_T)fabs(stepRows) >= 0.5F) {
      stepCols_tmp = (real32_T)floor(stepRows + 0.5F);
    } else {
      stepCols_tmp = stepRows * 0.0F;
    }

    maxr = ((int32_T)startRow + (int32_T)stepCols_tmp) - 2;
    if (autosarproject_P.DrawShapes_lineWidth > 1) {
      i = autosarproject_P.DrawShapes_lineWidth >> 1;
      ku = ((int32_T)stepCols - i) - 1;
      startC += i;
      bufIdx = ((int32_T)startRow - i) - 1;
      maxr += i;
    }

    if ((ku <= startC) && (bufIdx <= maxr)) {
      for (j_pixListNinc = 0; j_pixListNinc <
           autosarproject_P.DrawShapes_lineWidth; j_pixListNinc++) {
        stepCols_tmp_tmp = ku + j_pixListNinc;
        maxNumBlobsReached = false;

        /* Find the visible portion of a line. */
        visited1 = false;
        visited2 = false;
        done = false;
        similarity_tmp = stepCols_tmp_tmp;
        startColList_tmp_tmp = bufIdx;
        startRowList_tmp_tmp = stepCols_tmp_tmp;
        line_idx_3 = maxr;
        while (!done) {
          stackIdx = 0U;
          pixIdx = 0U;

          /* Determine viewport violations. */
          if (similarity_tmp < 0) {
            stackIdx = 4U;
          } else if (similarity_tmp > 179) {
            stackIdx = 8U;
          }

          if (startRowList_tmp_tmp < 0) {
            pixIdx = 4U;
          } else if (startRowList_tmp_tmp > 179) {
            pixIdx = 8U;
          }

          if (startColList_tmp_tmp < 0) {
            stackIdx |= 1U;
          } else if (startColList_tmp_tmp > 359) {
            stackIdx |= 2U;
          }

          if (line_idx_3 < 0) {
            pixIdx |= 1U;
          } else if (line_idx_3 > 359) {
            pixIdx |= 2U;
          }

          if ((stackIdx | pixIdx) == 0U) {
            /* Line falls completely within bounds. */
            done = true;
            maxNumBlobsReached = true;
          } else if ((stackIdx & pixIdx) != 0U) {
            /* Line falls completely out of bounds. */
            done = true;
            maxNumBlobsReached = false;
          } else if (stackIdx != 0U) {
            /* Clip 1st point; if it's in-bounds, clip 2nd point. */
            if (visited1) {
              similarity_tmp = stepCols_tmp_tmp;
              startColList_tmp_tmp = bufIdx;
            }

            i = startRowList_tmp_tmp - similarity_tmp;
            outIdx = line_idx_3 - startColList_tmp_tmp;
            if ((i > 1073741824) || (i < -1073741824) || ((outIdx > 1073741824) ||
                 (outIdx < -1073741824))) {
              /* Possible Inf or Nan. */
              done = true;
              maxNumBlobsReached = false;
              visited1 = true;
            } else if ((stackIdx & 4U) != 0U) {
              /* Violated RMin. */
              outRedIndx = -similarity_tmp * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                startColList_tmp_tmp += (div_s32_floor(outRedIndx << 1, i) + 1) >>
                  1;
              } else {
                startColList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, i) + 1)
                  >> 1;
              }

              similarity_tmp = 0;
              visited1 = true;
            } else if ((stackIdx & 8U) != 0U) {
              /* Violated RMax. */
              outRedIndx = (179 - similarity_tmp) * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                startColList_tmp_tmp += (div_s32_floor(outRedIndx << 1, i) + 1) >>
                  1;
              } else {
                startColList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, i) + 1)
                  >> 1;
              }

              similarity_tmp = 179;
              visited1 = true;
            } else if ((stackIdx & 1U) != 0U) {
              /* Violated CMin. */
              outRedIndx = -startColList_tmp_tmp * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                similarity_tmp += (div_s32_floor(outRedIndx << 1, outIdx) + 1) >>
                  1;
              } else {
                similarity_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx) + 1) >>
                  1;
              }

              startColList_tmp_tmp = 0;
              visited1 = true;
            } else {
              /* Violated CMax. */
              outRedIndx = (359 - startColList_tmp_tmp) * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                similarity_tmp += (div_s32_floor(outRedIndx << 1, outIdx) + 1) >>
                  1;
              } else {
                similarity_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx) + 1) >>
                  1;
              }

              startColList_tmp_tmp = 359;
              visited1 = true;
            }
          } else {
            /* Clip the 2nd point. */
            if (visited2) {
              startRowList_tmp_tmp = stepCols_tmp_tmp;
              line_idx_3 = maxr;
            }

            i = startRowList_tmp_tmp - similarity_tmp;
            outIdx = line_idx_3 - startColList_tmp_tmp;
            if ((i > 1073741824) || (i < -1073741824) || ((outIdx > 1073741824) ||
                 (outIdx < -1073741824))) {
              /* Possible Inf or Nan. */
              done = true;
              maxNumBlobsReached = false;
              visited2 = true;
            } else if ((pixIdx & 4U) != 0U) {
              /* Violated RMin. */
              outRedIndx = -startRowList_tmp_tmp * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                line_idx_3 += (div_s32_floor(outRedIndx << 1, i) + 1) >> 1;
              } else {
                line_idx_3 -= (div_s32_floor(-outRedIndx << 1, i) + 1) >> 1;
              }

              startRowList_tmp_tmp = 0;
              visited2 = true;
            } else if ((pixIdx & 8U) != 0U) {
              /* Violated RMax. */
              outRedIndx = (179 - startRowList_tmp_tmp) * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                line_idx_3 += (div_s32_floor(outRedIndx << 1, i) + 1) >> 1;
              } else {
                line_idx_3 -= (div_s32_floor(-outRedIndx << 1, i) + 1) >> 1;
              }

              startRowList_tmp_tmp = 179;
              visited2 = true;
            } else if ((pixIdx & 1U) != 0U) {
              /* Violated CMin. */
              outRedIndx = -line_idx_3 * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                startRowList_tmp_tmp += (div_s32_floor(outRedIndx << 1, outIdx)
                  + 1) >> 1;
              } else {
                startRowList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx)
                  + 1) >> 1;
              }

              line_idx_3 = 0;
              visited2 = true;
            } else {
              /* Violated CMax. */
              outRedIndx = (359 - line_idx_3) * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                startRowList_tmp_tmp += (div_s32_floor(outRedIndx << 1, outIdx)
                  + 1) >> 1;
              } else {
                startRowList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx)
                  + 1) >> 1;
              }

              line_idx_3 = 359;
              visited2 = true;
            }
          }
        }

        if (maxNumBlobsReached) {
          outIdx = startColList_tmp_tmp * 180 + similarity_tmp;
          for (i = startColList_tmp_tmp; i <= line_idx_3; i++) {
            autosarproject_B.DrawShapes1[outIdx] =
              autosarproject_P.DrawShapes_color[0];
            autosarproject_B.DrawShapes1[outIdx + 64800] =
              autosarproject_P.DrawShapes_color[1];
            autosarproject_B.DrawShapes1[outIdx + 129600] =
              autosarproject_P.DrawShapes_color[2];
            outIdx += 180;
          }
        }

        stepCols_tmp_tmp = bufIdx + j_pixListNinc;
        maxNumBlobsReached = false;

        /* Find the visible portion of a line. */
        visited1 = false;
        visited2 = false;
        done = false;
        similarity_tmp = ku;
        startColList_tmp_tmp = stepCols_tmp_tmp;
        startRowList_tmp_tmp = startC;
        line_idx_3 = stepCols_tmp_tmp;
        while (!done) {
          stackIdx = 0U;
          pixIdx = 0U;

          /* Determine viewport violations. */
          if (similarity_tmp < 0) {
            stackIdx = 4U;
          } else if (similarity_tmp > 179) {
            stackIdx = 8U;
          }

          if (startRowList_tmp_tmp < 0) {
            pixIdx = 4U;
          } else if (startRowList_tmp_tmp > 179) {
            pixIdx = 8U;
          }

          if (startColList_tmp_tmp < 0) {
            stackIdx |= 1U;
          } else if (startColList_tmp_tmp > 359) {
            stackIdx |= 2U;
          }

          if (line_idx_3 < 0) {
            pixIdx |= 1U;
          } else if (line_idx_3 > 359) {
            pixIdx |= 2U;
          }

          if ((stackIdx | pixIdx) == 0U) {
            /* Line falls completely within bounds. */
            done = true;
            maxNumBlobsReached = true;
          } else if ((stackIdx & pixIdx) != 0U) {
            /* Line falls completely out of bounds. */
            done = true;
            maxNumBlobsReached = false;
          } else if (stackIdx != 0U) {
            /* Clip 1st point; if it's in-bounds, clip 2nd point. */
            if (visited1) {
              similarity_tmp = ku;
              startColList_tmp_tmp = stepCols_tmp_tmp;
            }

            i = startRowList_tmp_tmp - similarity_tmp;
            outIdx = line_idx_3 - startColList_tmp_tmp;
            if ((i > 1073741824) || (i < -1073741824) || ((outIdx > 1073741824) ||
                 (outIdx < -1073741824))) {
              /* Possible Inf or Nan. */
              done = true;
              maxNumBlobsReached = false;
              visited1 = true;
            } else if ((stackIdx & 4U) != 0U) {
              /* Violated RMin. */
              outRedIndx = -similarity_tmp * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                startColList_tmp_tmp += (div_s32_floor(outRedIndx << 1, i) + 1) >>
                  1;
              } else {
                startColList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, i) + 1)
                  >> 1;
              }

              similarity_tmp = 0;
              visited1 = true;
            } else if ((stackIdx & 8U) != 0U) {
              /* Violated RMax. */
              outRedIndx = (179 - similarity_tmp) * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                startColList_tmp_tmp += (div_s32_floor(outRedIndx << 1, i) + 1) >>
                  1;
              } else {
                startColList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, i) + 1)
                  >> 1;
              }

              similarity_tmp = 179;
              visited1 = true;
            } else if ((stackIdx & 1U) != 0U) {
              /* Violated CMin. */
              outRedIndx = -startColList_tmp_tmp * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                similarity_tmp += (div_s32_floor(outRedIndx << 1, outIdx) + 1) >>
                  1;
              } else {
                similarity_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx) + 1) >>
                  1;
              }

              startColList_tmp_tmp = 0;
              visited1 = true;
            } else {
              /* Violated CMax. */
              outRedIndx = (359 - startColList_tmp_tmp) * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                similarity_tmp += (div_s32_floor(outRedIndx << 1, outIdx) + 1) >>
                  1;
              } else {
                similarity_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx) + 1) >>
                  1;
              }

              startColList_tmp_tmp = 359;
              visited1 = true;
            }
          } else {
            /* Clip the 2nd point. */
            if (visited2) {
              startRowList_tmp_tmp = startC;
              line_idx_3 = stepCols_tmp_tmp;
            }

            i = startRowList_tmp_tmp - similarity_tmp;
            outIdx = line_idx_3 - startColList_tmp_tmp;
            if ((i > 1073741824) || (i < -1073741824) || ((outIdx > 1073741824) ||
                 (outIdx < -1073741824))) {
              /* Possible Inf or Nan. */
              done = true;
              maxNumBlobsReached = false;
              visited2 = true;
            } else if ((pixIdx & 4U) != 0U) {
              /* Violated RMin. */
              outRedIndx = -startRowList_tmp_tmp * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                line_idx_3 += (div_s32_floor(outRedIndx << 1, i) + 1) >> 1;
              } else {
                line_idx_3 -= (div_s32_floor(-outRedIndx << 1, i) + 1) >> 1;
              }

              startRowList_tmp_tmp = 0;
              visited2 = true;
            } else if ((pixIdx & 8U) != 0U) {
              /* Violated RMax. */
              outRedIndx = (179 - startRowList_tmp_tmp) * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                line_idx_3 += (div_s32_floor(outRedIndx << 1, i) + 1) >> 1;
              } else {
                line_idx_3 -= (div_s32_floor(-outRedIndx << 1, i) + 1) >> 1;
              }

              startRowList_tmp_tmp = 179;
              visited2 = true;
            } else if ((pixIdx & 1U) != 0U) {
              /* Violated CMin. */
              outRedIndx = -line_idx_3 * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                startRowList_tmp_tmp += (div_s32_floor(outRedIndx << 1, outIdx)
                  + 1) >> 1;
              } else {
                startRowList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx)
                  + 1) >> 1;
              }

              line_idx_3 = 0;
              visited2 = true;
            } else {
              /* Violated CMax. */
              outRedIndx = (359 - line_idx_3) * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                startRowList_tmp_tmp += (div_s32_floor(outRedIndx << 1, outIdx)
                  + 1) >> 1;
              } else {
                startRowList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx)
                  + 1) >> 1;
              }

              line_idx_3 = 359;
              visited2 = true;
            }
          }
        }

        if (maxNumBlobsReached) {
          outIdx = startColList_tmp_tmp * 180 + similarity_tmp;
          for (i = similarity_tmp; i <= startRowList_tmp_tmp; i++) {
            autosarproject_B.DrawShapes1[outIdx] =
              autosarproject_P.DrawShapes_color[0];
            autosarproject_B.DrawShapes1[outIdx + 64800] =
              autosarproject_P.DrawShapes_color[1];
            autosarproject_B.DrawShapes1[outIdx + 129600] =
              autosarproject_P.DrawShapes_color[2];
            outIdx++;
          }
        }

        stepCols_tmp_tmp = startC - j_pixListNinc;
        maxNumBlobsReached = false;

        /* Find the visible portion of a line. */
        visited1 = false;
        visited2 = false;
        done = false;
        similarity_tmp = stepCols_tmp_tmp;
        startColList_tmp_tmp = bufIdx;
        startRowList_tmp_tmp = stepCols_tmp_tmp;
        line_idx_3 = maxr;
        while (!done) {
          stackIdx = 0U;
          pixIdx = 0U;

          /* Determine viewport violations. */
          if (similarity_tmp < 0) {
            stackIdx = 4U;
          } else if (similarity_tmp > 179) {
            stackIdx = 8U;
          }

          if (startRowList_tmp_tmp < 0) {
            pixIdx = 4U;
          } else if (startRowList_tmp_tmp > 179) {
            pixIdx = 8U;
          }

          if (startColList_tmp_tmp < 0) {
            stackIdx |= 1U;
          } else if (startColList_tmp_tmp > 359) {
            stackIdx |= 2U;
          }

          if (line_idx_3 < 0) {
            pixIdx |= 1U;
          } else if (line_idx_3 > 359) {
            pixIdx |= 2U;
          }

          if ((stackIdx | pixIdx) == 0U) {
            /* Line falls completely within bounds. */
            done = true;
            maxNumBlobsReached = true;
          } else if ((stackIdx & pixIdx) != 0U) {
            /* Line falls completely out of bounds. */
            done = true;
            maxNumBlobsReached = false;
          } else if (stackIdx != 0U) {
            /* Clip 1st point; if it's in-bounds, clip 2nd point. */
            if (visited1) {
              similarity_tmp = stepCols_tmp_tmp;
              startColList_tmp_tmp = bufIdx;
            }

            i = startRowList_tmp_tmp - similarity_tmp;
            outIdx = line_idx_3 - startColList_tmp_tmp;
            if ((i > 1073741824) || (i < -1073741824) || ((outIdx > 1073741824) ||
                 (outIdx < -1073741824))) {
              /* Possible Inf or Nan. */
              done = true;
              maxNumBlobsReached = false;
              visited1 = true;
            } else if ((stackIdx & 4U) != 0U) {
              /* Violated RMin. */
              outRedIndx = -similarity_tmp * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                startColList_tmp_tmp += (div_s32_floor(outRedIndx << 1, i) + 1) >>
                  1;
              } else {
                startColList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, i) + 1)
                  >> 1;
              }

              similarity_tmp = 0;
              visited1 = true;
            } else if ((stackIdx & 8U) != 0U) {
              /* Violated RMax. */
              outRedIndx = (179 - similarity_tmp) * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                startColList_tmp_tmp += (div_s32_floor(outRedIndx << 1, i) + 1) >>
                  1;
              } else {
                startColList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, i) + 1)
                  >> 1;
              }

              similarity_tmp = 179;
              visited1 = true;
            } else if ((stackIdx & 1U) != 0U) {
              /* Violated CMin. */
              outRedIndx = -startColList_tmp_tmp * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                similarity_tmp += (div_s32_floor(outRedIndx << 1, outIdx) + 1) >>
                  1;
              } else {
                similarity_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx) + 1) >>
                  1;
              }

              startColList_tmp_tmp = 0;
              visited1 = true;
            } else {
              /* Violated CMax. */
              outRedIndx = (359 - startColList_tmp_tmp) * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                similarity_tmp += (div_s32_floor(outRedIndx << 1, outIdx) + 1) >>
                  1;
              } else {
                similarity_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx) + 1) >>
                  1;
              }

              startColList_tmp_tmp = 359;
              visited1 = true;
            }
          } else {
            /* Clip the 2nd point. */
            if (visited2) {
              startRowList_tmp_tmp = stepCols_tmp_tmp;
              line_idx_3 = maxr;
            }

            i = startRowList_tmp_tmp - similarity_tmp;
            outIdx = line_idx_3 - startColList_tmp_tmp;
            if ((i > 1073741824) || (i < -1073741824) || ((outIdx > 1073741824) ||
                 (outIdx < -1073741824))) {
              /* Possible Inf or Nan. */
              done = true;
              maxNumBlobsReached = false;
              visited2 = true;
            } else if ((pixIdx & 4U) != 0U) {
              /* Violated RMin. */
              outRedIndx = -startRowList_tmp_tmp * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                line_idx_3 += (div_s32_floor(outRedIndx << 1, i) + 1) >> 1;
              } else {
                line_idx_3 -= (div_s32_floor(-outRedIndx << 1, i) + 1) >> 1;
              }

              startRowList_tmp_tmp = 0;
              visited2 = true;
            } else if ((pixIdx & 8U) != 0U) {
              /* Violated RMax. */
              outRedIndx = (179 - startRowList_tmp_tmp) * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                line_idx_3 += (div_s32_floor(outRedIndx << 1, i) + 1) >> 1;
              } else {
                line_idx_3 -= (div_s32_floor(-outRedIndx << 1, i) + 1) >> 1;
              }

              startRowList_tmp_tmp = 179;
              visited2 = true;
            } else if ((pixIdx & 1U) != 0U) {
              /* Violated CMin. */
              outRedIndx = -line_idx_3 * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                startRowList_tmp_tmp += (div_s32_floor(outRedIndx << 1, outIdx)
                  + 1) >> 1;
              } else {
                startRowList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx)
                  + 1) >> 1;
              }

              line_idx_3 = 0;
              visited2 = true;
            } else {
              /* Violated CMax. */
              outRedIndx = (359 - line_idx_3) * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                startRowList_tmp_tmp += (div_s32_floor(outRedIndx << 1, outIdx)
                  + 1) >> 1;
              } else {
                startRowList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx)
                  + 1) >> 1;
              }

              line_idx_3 = 359;
              visited2 = true;
            }
          }
        }

        if (maxNumBlobsReached) {
          outIdx = startColList_tmp_tmp * 180 + similarity_tmp;
          for (i = startColList_tmp_tmp; i <= line_idx_3; i++) {
            autosarproject_B.DrawShapes1[outIdx] =
              autosarproject_P.DrawShapes_color[0];
            autosarproject_B.DrawShapes1[outIdx + 64800] =
              autosarproject_P.DrawShapes_color[1];
            autosarproject_B.DrawShapes1[outIdx + 129600] =
              autosarproject_P.DrawShapes_color[2];
            outIdx += 180;
          }
        }

        stepCols_tmp_tmp = maxr - j_pixListNinc;
        maxNumBlobsReached = false;

        /* Find the visible portion of a line. */
        visited1 = false;
        visited2 = false;
        done = false;
        similarity_tmp = ku;
        startColList_tmp_tmp = stepCols_tmp_tmp;
        startRowList_tmp_tmp = startC;
        line_idx_3 = stepCols_tmp_tmp;
        while (!done) {
          stackIdx = 0U;
          pixIdx = 0U;

          /* Determine viewport violations. */
          if (similarity_tmp < 0) {
            stackIdx = 4U;
          } else if (similarity_tmp > 179) {
            stackIdx = 8U;
          }

          if (startRowList_tmp_tmp < 0) {
            pixIdx = 4U;
          } else if (startRowList_tmp_tmp > 179) {
            pixIdx = 8U;
          }

          if (startColList_tmp_tmp < 0) {
            stackIdx |= 1U;
          } else if (startColList_tmp_tmp > 359) {
            stackIdx |= 2U;
          }

          if (line_idx_3 < 0) {
            pixIdx |= 1U;
          } else if (line_idx_3 > 359) {
            pixIdx |= 2U;
          }

          if ((stackIdx | pixIdx) == 0U) {
            /* Line falls completely within bounds. */
            done = true;
            maxNumBlobsReached = true;
          } else if ((stackIdx & pixIdx) != 0U) {
            /* Line falls completely out of bounds. */
            done = true;
            maxNumBlobsReached = false;
          } else if (stackIdx != 0U) {
            /* Clip 1st point; if it's in-bounds, clip 2nd point. */
            if (visited1) {
              similarity_tmp = ku;
              startColList_tmp_tmp = stepCols_tmp_tmp;
            }

            i = startRowList_tmp_tmp - similarity_tmp;
            outIdx = line_idx_3 - startColList_tmp_tmp;
            if ((i > 1073741824) || (i < -1073741824) || ((outIdx > 1073741824) ||
                 (outIdx < -1073741824))) {
              /* Possible Inf or Nan. */
              done = true;
              maxNumBlobsReached = false;
              visited1 = true;
            } else if ((stackIdx & 4U) != 0U) {
              /* Violated RMin. */
              outRedIndx = -similarity_tmp * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                startColList_tmp_tmp += (div_s32_floor(outRedIndx << 1, i) + 1) >>
                  1;
              } else {
                startColList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, i) + 1)
                  >> 1;
              }

              similarity_tmp = 0;
              visited1 = true;
            } else if ((stackIdx & 8U) != 0U) {
              /* Violated RMax. */
              outRedIndx = (179 - similarity_tmp) * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                startColList_tmp_tmp += (div_s32_floor(outRedIndx << 1, i) + 1) >>
                  1;
              } else {
                startColList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, i) + 1)
                  >> 1;
              }

              similarity_tmp = 179;
              visited1 = true;
            } else if ((stackIdx & 1U) != 0U) {
              /* Violated CMin. */
              outRedIndx = -startColList_tmp_tmp * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                similarity_tmp += (div_s32_floor(outRedIndx << 1, outIdx) + 1) >>
                  1;
              } else {
                similarity_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx) + 1) >>
                  1;
              }

              startColList_tmp_tmp = 0;
              visited1 = true;
            } else {
              /* Violated CMax. */
              outRedIndx = (359 - startColList_tmp_tmp) * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                similarity_tmp += (div_s32_floor(outRedIndx << 1, outIdx) + 1) >>
                  1;
              } else {
                similarity_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx) + 1) >>
                  1;
              }

              startColList_tmp_tmp = 359;
              visited1 = true;
            }
          } else {
            /* Clip the 2nd point. */
            if (visited2) {
              startRowList_tmp_tmp = startC;
              line_idx_3 = stepCols_tmp_tmp;
            }

            i = startRowList_tmp_tmp - similarity_tmp;
            outIdx = line_idx_3 - startColList_tmp_tmp;
            if ((i > 1073741824) || (i < -1073741824) || ((outIdx > 1073741824) ||
                 (outIdx < -1073741824))) {
              /* Possible Inf or Nan. */
              done = true;
              maxNumBlobsReached = false;
              visited2 = true;
            } else if ((pixIdx & 4U) != 0U) {
              /* Violated RMin. */
              outRedIndx = -startRowList_tmp_tmp * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                line_idx_3 += (div_s32_floor(outRedIndx << 1, i) + 1) >> 1;
              } else {
                line_idx_3 -= (div_s32_floor(-outRedIndx << 1, i) + 1) >> 1;
              }

              startRowList_tmp_tmp = 0;
              visited2 = true;
            } else if ((pixIdx & 8U) != 0U) {
              /* Violated RMax. */
              outRedIndx = (179 - startRowList_tmp_tmp) * outIdx;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (i >= 0)) || ((outRedIndx < 0) &&
                          (i < 0))) {
                line_idx_3 += (div_s32_floor(outRedIndx << 1, i) + 1) >> 1;
              } else {
                line_idx_3 -= (div_s32_floor(-outRedIndx << 1, i) + 1) >> 1;
              }

              startRowList_tmp_tmp = 179;
              visited2 = true;
            } else if ((pixIdx & 1U) != 0U) {
              /* Violated CMin. */
              outRedIndx = -line_idx_3 * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                startRowList_tmp_tmp += (div_s32_floor(outRedIndx << 1, outIdx)
                  + 1) >> 1;
              } else {
                startRowList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx)
                  + 1) >> 1;
              }

              line_idx_3 = 0;
              visited2 = true;
            } else {
              /* Violated CMax. */
              outRedIndx = (359 - line_idx_3) * i;
              if ((outRedIndx > 1073741824) || (outRedIndx < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
              } else if (((outRedIndx >= 0) && (outIdx >= 0)) || ((outRedIndx <
                           0) && (outIdx < 0))) {
                startRowList_tmp_tmp += (div_s32_floor(outRedIndx << 1, outIdx)
                  + 1) >> 1;
              } else {
                startRowList_tmp_tmp -= (div_s32_floor(-outRedIndx << 1, outIdx)
                  + 1) >> 1;
              }

              line_idx_3 = 359;
              visited2 = true;
            }
          }
        }

        if (maxNumBlobsReached) {
          outIdx = startColList_tmp_tmp * 180 + similarity_tmp;
          for (i = similarity_tmp; i <= startRowList_tmp_tmp; i++) {
            autosarproject_B.DrawShapes1[outIdx] =
              autosarproject_P.DrawShapes_color[0];
            autosarproject_B.DrawShapes1[outIdx + 64800] =
              autosarproject_P.DrawShapes_color[1];
            autosarproject_B.DrawShapes1[outIdx + 129600] =
              autosarproject_P.DrawShapes_color[2];
            outIdx++;
          }
        }
      }
    }

    /* Selector: '<S2>/Selector' incorporates:
     *  S-Function (svipdrawshapes): '<S2>/Draw Shapes'
     *  S-Function (svipdrawshapes): '<S2>/Draw Shapes1'
     */
    rtb_MatrixConcatenate1[inIdx] = rtb_BBox[inIdx];

    /* Sum: '<S2>/Add1' */
    rtb_MatrixConcatenate1[inIdx + 9] = similarity + bestConfidence;
  }

  /* SignalConversion generated from: '<S2>/Matrix Concatenate' incorporates:
   *  Concatenate: '<S2>/Matrix Concatenate1'
   */
  memcpy(&rtb_Switch[0], &rtb_MatrixConcatenate1[0], 18U * sizeof(real32_T));

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Compare'
   *  Selector: '<S2>/Selector5'
   */
  for (maxr = 0; maxr < 2; maxr++) {
    for (i = 0; i < 9; i++) {
      inIdx = 9 * maxr + i;
      tmp[inIdx] = (real32_T)(rtb_BBox[(maxr + 2) * 9 + i] >
        autosarproject_P.Constant_Value) *
        autosarproject_P.Constant2_Value_g[inIdx];
    }
  }

  memcpy(&rtb_Switch[18], &tmp[0], 18U * sizeof(real32_T));

  /* End of Product: '<S2>/Product' */

  /* S-Function (svipdrawshapes): '<S2>/Draw Shapes1' */
  /* Copy the image from input to output. */
  /* Calculate FillColor times Opacity. */
  autosarproject_DW.DrawShapes1_DW_FillColorAdd[0] =
    autosarproject_P.DrawShapes1_color[0] * autosarproject_P.DrawShapes1_opacity;
  autosarproject_DW.DrawShapes1_DW_FillColorAdd[1] =
    autosarproject_P.DrawShapes1_color[1] * autosarproject_P.DrawShapes1_opacity;
  autosarproject_DW.DrawShapes1_DW_FillColorAdd[2] =
    autosarproject_P.DrawShapes1_color[2] * autosarproject_P.DrawShapes1_opacity;

  /* Calculate One minus Opacity. */
  autosarproject_DW.DrawShapes1_DW_OneMOpacity = 1.0F -
    autosarproject_P.DrawShapes1_opacity;

  /* Update view port. */
  /* Draw all filled rectangles. */
  for (inIdx = 0; inIdx < 9; inIdx++) {
    /* Concatenate: '<S2>/Matrix Concatenate' */
    stepRows = rtb_Switch[inIdx + 9];
    similarity = (real32_T)fabs(stepRows);
    if (similarity < 8.388608E+6F) {
      if (similarity >= 0.5F) {
        stepRows = (real32_T)floor(stepRows + 0.5F);
      } else {
        stepRows *= 0.0F;
      }
    }

    /* Concatenate: '<S2>/Matrix Concatenate' */
    stepCols = rtb_Switch[inIdx];
    similarity = (real32_T)fabs(stepCols);
    if (similarity < 8.388608E+6F) {
      if (similarity >= 0.5F) {
        stepCols = (real32_T)floor(stepCols + 0.5F);
      } else {
        stepCols *= 0.0F;
      }
    }

    /* Find the overlapping area of the rectangle and the view port. */
    if ((int32_T)stepRows - 1 <= 0) {
      startC = 0;
    } else {
      startC = (int32_T)stepRows - 1;
    }

    if ((int32_T)stepCols - 1 <= 0) {
      ku = 0;
    } else {
      ku = (int32_T)stepCols - 1;
    }

    /* Concatenate: '<S2>/Matrix Concatenate' */
    startRow = rtb_Switch[inIdx + 27];
    similarity = (real32_T)fabs(startRow);
    if (similarity < 8.388608E+6F) {
      if (similarity >= 0.5F) {
        startRow = (real32_T)floor(startRow + 0.5F);
      } else {
        startRow *= 0.0F;
      }
    }

    maxr = ((int32_T)stepRows + (int32_T)startRow) - 2;
    if (maxr >= 179) {
      maxr = 179;
    }

    /* Concatenate: '<S2>/Matrix Concatenate' */
    stepRows = rtb_Switch[inIdx + 18];
    similarity = (real32_T)fabs(stepRows);
    if (similarity < 8.388608E+6F) {
      if (similarity >= 0.5F) {
        stepRows = (real32_T)floor(stepRows + 0.5F);
      } else {
        stepRows *= 0.0F;
      }
    }

    j_pixListNinc = ((int32_T)stepCols + (int32_T)stepRows) - 2;
    if (j_pixListNinc >= 359) {
      j_pixListNinc = 359;
    }

    /* Draw a filled rectangle. */
    if ((startC <= maxr) && (ku <= j_pixListNinc)) {
      while (ku <= j_pixListNinc) {
        bufIdx = ku * 180 + startC;
        outIdx = bufIdx;
        for (i = startC; i <= maxr; i++) {
          autosarproject_B.DrawShapes1[outIdx] *=
            autosarproject_DW.DrawShapes1_DW_OneMOpacity;
          autosarproject_B.DrawShapes1[outIdx] +=
            autosarproject_DW.DrawShapes1_DW_FillColorAdd[0];
          outIdx++;
        }

        bufIdx += 64800;
        outIdx = bufIdx;
        for (i = startC; i <= maxr; i++) {
          autosarproject_B.DrawShapes1[outIdx] *=
            autosarproject_DW.DrawShapes1_DW_OneMOpacity;
          autosarproject_B.DrawShapes1[outIdx] +=
            autosarproject_DW.DrawShapes1_DW_FillColorAdd[1];
          outIdx++;
        }

        outIdx = bufIdx + 64800;
        for (i = startC; i <= maxr; i++) {
          autosarproject_B.DrawShapes1[outIdx] *=
            autosarproject_DW.DrawShapes1_DW_OneMOpacity;
          autosarproject_B.DrawShapes1[outIdx] +=
            autosarproject_DW.DrawShapes1_DW_FillColorAdd[2];
          outIdx++;
        }

        ku++;
      }
    }
  }

  /* End of S-Function (svipdrawshapes): '<S2>/Draw Shapes1' */
  for (i = 0; i < 36; i++) {
    /* Constant: '<S5>/Constant12' */
    rtb_Switch[i] = autosarproject_P.template_names[i];
  }

  for (i = 0; i < 9; i++) {
    /* RelationalOperator: '<S15>/Compare' incorporates:
     *  Constant: '<S15>/Constant'
     */
    rtb_Compare_f[i] = (rtb_Count[i] >
                        autosarproject_P.ComparewithThreshold_const);

    /* Switch: '<S5>/Switch4' incorporates:
     *  Constant: '<S5>/Constant7'
     *  Constant: '<S5>/Constant9'
     *  Switch: '<S5>/Switch3'
     *  UnitDelay: '<S5>/Unit Delay3'
     *  UnitDelay: '<S5>/Unit Delay4'
     */
    if (autosarproject_B.Constant) {
      rtb_Switch1[i] = autosarproject_P.Constant9_Value[i];
      rtb_Switch3[i] = autosarproject_P.Constant7_Value[i];
    } else {
      rtb_Switch1[i] = autosarproject_DW.UnitDelay4_DSTATE[i];
      rtb_Switch3[i] = autosarproject_DW.UnitDelay3_DSTATE[i];
    }

    /* End of Switch: '<S5>/Switch4' */
  }

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  Constant: '<S5>/Constant12'
   *  Constant: '<S5>/Constant5'
   *  Constant: '<S5>/Constant8'
   *  Constant: '<S5>/Minimum Count Number'
   *  Constant: '<S5>/Minimum Similarity'
   *  S-Function (svipcolorconv): '<S3>/Color Space  Conversion1'
   */
  /* MATLAB Function 'Recognition/MATLAB Function': '<S14>:1' */
  /* '<S14>:1:54' */
  lenNames[0] = 0;
  lenNames[1] = 0;
  lenNames[2] = 0;

  /* '<S14>:1:56' */
  memset(&autosarproject_B.Message[0], 0, 162U * sizeof(uint8_T));

  /* '<S14>:1:57' */
  /* '<S14>:1:58' */
  for (i = 0; i < 9; i++) {
    rtb_Status[i] = 0.0F;
    rtb_Count_n[i] = 0.0F;
  }

  /* '<S14>:1:61' */
  /* '<S14>:1:62' */
  exitg1 = false;
  while ((!exitg1) && (centerM < 12)) {
    /* '<S14>:1:62' */
    if (rtb_Switch[(11 - centerM) * 3] != 0.0F) {
      /* '<S14>:1:64' */
      lenNames[0] = (int8_T)(12 - centerM);
      exitg1 = true;
    } else {
      centerM++;
    }
  }

  /* '<S14>:1:62' */
  centerM = 0;
  exitg1 = false;
  while ((!exitg1) && (centerM < 12)) {
    /* '<S14>:1:62' */
    if (rtb_Switch[(11 - centerM) * 3 + 1] != 0.0F) {
      /* '<S14>:1:64' */
      lenNames[1] = (int8_T)(12 - centerM);
      exitg1 = true;
    } else {
      centerM++;
    }
  }

  /* '<S14>:1:62' */
  centerM = 0;
  exitg1 = false;
  while ((!exitg1) && (centerM < 12)) {
    /* '<S14>:1:62' */
    if (rtb_Switch[(11 - centerM) * 3 + 2] != 0.0F) {
      /* '<S14>:1:64' */
      lenNames[2] = (int8_T)(12 - centerM);
      exitg1 = true;
    } else {
      centerM++;
    }
  }

  /* '<S14>:1:70' */
  for (i = 0; i < 9; i++) {
    /* '<S14>:1:71' */
    similarity = 0.0F;

    /* '<S14>:1:72' */
    bestConfidence = 0.0F;
    if (rtb_Compare_f[i]) {
      /* '<S14>:1:74' */
      stepCols_tmp = rtb_Switch3[i];
      if (stepCols_tmp > autosarproject_P.MinimumCountNumber_Value) {
        /* '<S14>:1:75' */
        /* '<S14>:1:76' */
        rtb_Status[i] = rtb_Switch1[i];

        /* '<S14>:1:77' */
        rtb_Count_n[i] = stepCols_tmp + 1.0F;
      } else {
        /* '<S14>:1:80' */
        ratioRows = rtb_BBox[i + 27];
        stepRows = (real32_T)floor(ratioRows / 18.0F);

        /* '<S14>:1:81' */
        colSrcFlt = rtb_BBox[i + 18];
        stepCols = (real32_T)floor(colSrcFlt / 18.0F);

        /* '<S14>:1:84' */
        colSrc = rtb_BBox[i];
        startColList_0[1] = colSrc;

        /* '<S14>:1:85' */
        startRow = colSrc - stepCols;
        if (startRow <= 1.0F) {
          startColList_0[0] = 1.0F;
        } else {
          startColList_0[0] = startRow;
        }

        /* '<S14>:1:86' */
        startRow = colSrc + stepCols;
        if (startRow >= 360.0F) {
          startColList_0[2] = 360.0F;
        } else {
          startColList_0[2] = startRow;
        }

        /* '<S14>:1:89' */
        colSrcFlt = (colSrc + colSrcFlt) - 1.0F;
        endColList_0[1] = colSrcFlt;

        /* '<S14>:1:90' */
        startRow = colSrcFlt - stepCols;
        if (startRow <= 1.0F) {
          endColList_0[0] = 1.0F;
        } else {
          endColList_0[0] = startRow;
        }

        /* '<S14>:1:91' */
        startRow = colSrcFlt + stepCols;
        if (startRow >= 360.0F) {
          endColList_0[2] = 360.0F;
        } else {
          endColList_0[2] = startRow;
        }

        /* '<S14>:1:94' */
        colSrcFlt = rtb_BBox[i + 9];
        startRowList_0[1] = colSrcFlt;

        /* '<S14>:1:95' */
        startRow = colSrcFlt - stepRows;
        if ((startRow <= 1.0F) || rtIsNaNF(startRow)) {
          startRowList_0[0] = 1.0F;
        } else {
          startRowList_0[0] = startRow;
        }

        /* '<S14>:1:96' */
        startRow = colSrcFlt + stepRows;
        if ((startRow >= 180.0F) || rtIsNaNF(startRow)) {
          startRowList_0[2] = 180.0F;
        } else {
          startRowList_0[2] = startRow;
        }

        /* '<S14>:1:99' */
        stepCols = (colSrcFlt + ratioRows) - 1.0F;
        endRowList_0[1] = stepCols;

        /* '<S14>:1:100' */
        startRow = stepCols - stepRows;
        if ((startRow <= 1.0F) || rtIsNaNF(startRow)) {
          endRowList_0[0] = 1.0F;
        } else {
          endRowList_0[0] = startRow;
        }

        /* '<S14>:1:101' */
        startRow = stepCols + stepRows;
        if ((startRow >= 180.0F) || rtIsNaNF(startRow)) {
          endRowList_0[2] = 180.0F;
        } else {
          endRowList_0[2] = startRow;
        }

        /* '<S14>:1:55' */
        /* '<S14>:1:103' */
        for (centerM = 0; centerM < 3; centerM++) {
          stepRows = startColList_0[centerM];

          /* '<S14>:1:55' */
          /* '<S14>:1:104' */
          for (outIdx = 0; outIdx < 3; outIdx++) {
            /* '<S14>:1:105' */
            stepCols = (endColList_0[outIdx] - stepRows) / 18.0F;

            /* '<S14>:1:55' */
            /* '<S14>:1:106' */
            for (bufIdx = 0; bufIdx < 3; bufIdx++) {
              startRow = startRowList_0[bufIdx];

              /* '<S14>:1:55' */
              /* '<S14>:1:107' */
              for (startC = 0; startC < 3; startC++) {
                /* '<S14>:1:108' */
                ratioRows = (endRowList_0[startC] - startRow) / 18.0F;

                /* '<S14>:1:111' */
                colSrcFlt = stepRows;

                /* '<S14>:1:112' */
                for (ku = 0; ku < 18; ku++) {
                  /* '<S14>:1:113' */
                  colSrc = (real32_T)floor(colSrcFlt);

                  /* '<S14>:1:114' */
                  /* '<S14>:1:115' */
                  for (maxr = 0; maxr < 18; maxr++) {
                    /* '<S14>:1:116' */
                    /* '<S14>:1:117' */
                    feature_0[maxr + 18 * ku] =
                      autosarproject_B.ColorSpaceConversion1_o1[((int32_T)
                      (real32_T)floor((real32_T)maxr * ratioRows + startRow) +
                      ((int32_T)colSrc - 1) * 180) - 1];

                    /* '<S14>:1:118' */
                  }

                  /* '<S14>:1:120' */
                  colSrcFlt += stepCols;
                }

                /* '<S14>:1:124' */
                ratioRows = feature_0[0];
                for (ku = 0; ku < 323; ku++) {
                  ratioRows += feature_0[ku + 1];
                }

                ratioRows /= 324.0F;
                for (maxr = 0; maxr <= 320; maxr += 4) {
                  tmp_0 = _mm_loadu_ps(&feature_0[maxr]);
                  _mm_storeu_ps(&feature_0[maxr], _mm_sub_ps(tmp_0, _mm_set1_ps
                    (ratioRows)));
                }

                /* '<S14>:1:127' */
                for (ku = 0; ku < 9; ku++) {
                  /* '<S14>:1:128' */
                  ratioRows = 0.0F;

                  /* '<S14>:1:129' */
                  for (maxr = 0; maxr < 18; maxr++) {
                    /* '<S14>:1:130' */
                    for (j_pixListNinc = 0; j_pixListNinc < 18; j_pixListNinc++)
                    {
                      /* '<S14>:1:131' */
                      inIdx = 18 * maxr + j_pixListNinc;
                      ratioRows += autosarproject_P.template_recognition[324 *
                        ku + inIdx] * feature_0[inIdx];
                    }
                  }

                  if (ratioRows > bestConfidence) {
                    /* '<S14>:1:135' */
                    /* '<S14>:1:136' */
                    bestConfidence = ratioRows;

                    /* '<S14>:1:137' */
                    similarity = autosarproject_P.template_ids[ku];
                  }
                }
              }
            }
          }
        }

        if (bestConfidence >= autosarproject_P.MinimumSimilarity_Value) {
          /* '<S14>:1:145' */
          if (rtb_Switch1[i] == similarity) {
            /* '<S14>:1:146' */
            /* '<S14>:1:147' */
            rtb_Count_n[i] = stepCols_tmp + 1.0F;
          } else {
            /* '<S14>:1:149' */
            rtb_Count_n[i] = 1.0F;
          }

          /* '<S14>:1:151' */
          rtb_Status[i] = similarity;
        }
      }
    }
  }

  /* '<S14>:1:158' */
  stepRows = 1.0F;

  /* '<S14>:1:159' */
  for (centerM = 0; centerM < 9; centerM++) {
    similarity = rtb_Count_n[centerM];
    if ((similarity >= autosarproject_P.MinimumCountNumber_Value) ||
        rtb_Compare_f[centerM]) {
      /* '<S14>:1:160' */
      /* '<S14>:1:161' */
      if (similarity >= autosarproject_P.MinimumCountNumber_Value) {
        /* '<S14>:1:162' */
        ku = (int32_T)rtb_Status[centerM];
        inCol_tmp = lenNames[ku - 1];
        i = inCol_tmp;

        /* '<S14>:1:164' */
        for (inIdx = 0; inIdx < i; inIdx++) {
          /* '<S14>:1:165' */
          stepCols_tmp = rt_roundf_snf(rtb_Switch[(3 * inIdx + ku) - 1]);
          if (stepCols_tmp < 256.0F) {
            if (stepCols_tmp >= 0.0F) {
              autosarproject_B.Message[(int32_T)((stepRows + ((real32_T)inIdx +
                1.0F)) - 1.0F) - 1] = (uint8_T)stepCols_tmp;
            } else {
              autosarproject_B.Message[(int32_T)((stepRows + ((real32_T)inIdx +
                1.0F)) - 1.0F) - 1] = 0U;
            }
          } else if (stepCols_tmp >= 256.0F) {
            autosarproject_B.Message[(int32_T)((stepRows + ((real32_T)inIdx +
              1.0F)) - 1.0F) - 1] = MAX_uint8_T;
          } else {
            autosarproject_B.Message[(int32_T)((stepRows + ((real32_T)inIdx +
              1.0F)) - 1.0F) - 1] = 0U;
          }
        }

        /* '<S14>:1:167' */
        stepRows += (real32_T)inCol_tmp;
      } else {
        /* '<S14>:1:169' */
        autosarproject_B.Message[(int32_T)stepRows - 1] = 82U;

        /* '<S14>:1:170' */
        autosarproject_B.Message[(int32_T)(stepRows + 1.0F) - 1] = 101U;

        /* '<S14>:1:171' */
        autosarproject_B.Message[(int32_T)(stepRows + 2.0F) - 1] = 99U;

        /* '<S14>:1:172' */
        autosarproject_B.Message[(int32_T)(stepRows + 3.0F) - 1] = 111U;

        /* '<S14>:1:173' */
        autosarproject_B.Message[(int32_T)(stepRows + 4.0F) - 1] = 103U;

        /* '<S14>:1:174' */
        autosarproject_B.Message[(int32_T)(stepRows + 5.0F) - 1] = 110U;

        /* '<S14>:1:175' */
        autosarproject_B.Message[(int32_T)(stepRows + 6.0F) - 1] = 105U;

        /* '<S14>:1:176' */
        autosarproject_B.Message[(int32_T)(stepRows + 7.0F) - 1] = 122U;

        /* '<S14>:1:177' */
        autosarproject_B.Message[(int32_T)(stepRows + 8.0F) - 1] = 101U;

        /* '<S14>:1:178' */
        autosarproject_B.Message[(int32_T)(stepRows + 9.0F) - 1] = 46U;

        /* '<S14>:1:179' */
        autosarproject_B.Message[(int32_T)(stepRows + 10.0F) - 1] = 46U;

        /* '<S14>:1:180' */
        autosarproject_B.Message[(int32_T)(stepRows + 11.0F) - 1] = 46U;

        /* '<S14>:1:181' */
        stepRows += 12.0F;
      }

      /* '<S14>:1:185' */
      autosarproject_B.Message[(int32_T)stepRows - 1] = 10U;

      /* '<S14>:1:186' */
      autosarproject_B.Message[(int32_T)(stepRows + 1.0F) - 1] = 84U;

      /* '<S14>:1:187' */
      autosarproject_B.Message[(int32_T)(stepRows + 2.0F) - 1] = 97U;

      /* '<S14>:1:188' */
      autosarproject_B.Message[(int32_T)(stepRows + 3.0F) - 1] = 103U;

      /* '<S14>:1:189' */
      autosarproject_B.Message[(int32_T)(stepRows + 4.0F) - 1] = 58U;

      /* '<S14>:1:190' */
      autosarproject_B.Message[(int32_T)(stepRows + 5.0F) - 1] = (uint8_T)
        (centerM + 49);

      /* '<S14>:1:191' */
      stepRows += 6.0F;
    }

    /* '<S14>:1:193' */
    stepRows++;
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */
  for (i = 0; i <= 12; i += 4) {
    /* Bias: '<S2>/Bias' incorporates:
     *  Concatenate: '<S2>/Matrix Concatenate1'
     */
    tmp_0 = _mm_loadu_ps(&rtb_MatrixConcatenate1[i]);

    /* Bias: '<S2>/Bias' */
    _mm_storeu_ps(&autosarproject_B.Bias[i], _mm_add_ps(tmp_0, _mm_set1_ps
      (autosarproject_P.Bias_Bias)));
  }

  for (i = 16; i < 18; i++) {
    /* Bias: '<S2>/Bias' incorporates:
     *  Concatenate: '<S2>/Matrix Concatenate1'
     */
    autosarproject_B.Bias[i] = rtb_MatrixConcatenate1[i] +
      autosarproject_P.Bias_Bias;
  }

  /* S-Function (sviptextrender): '<S2>/Insert Text1' */
  /* put the pen at the beginning of the string */
  inIdx = 0;
  outIdx = 162;
  bufIdx = 0;

  /* S-Function (sviptextrender): '<S2>/Insert Text1' incorporates:
   *  S-Function (svipdrawshapes): '<S2>/Draw Shapes1'
   */
  /* copy input to output since Simulink isn't giving us in-place operation */
  memcpy(&autosarproject_B.InsertText1[0], &autosarproject_B.DrawShapes1[0],
         194400U * sizeof(real32_T));

  /* S-Function (sviptextrender): '<S2>/Insert Text1' incorporates:
   *  Bias: '<S2>/Bias'
   */
  while (outIdx > 0) {
    centerM = bufIdx;
    startC = outIdx;
    if (inIdx < 9) {
      /* copy location to int32 container */
      similarity_tmp = (int32_T)(real32_T)floor(autosarproject_B.Bias[inIdx]) -
        1;

      /* update the color/intensity */
      autosarproject_DW.InsertText1_colorVectorDW[0] =
        autosarproject_P.InsertText1_textColor[0];

      /* Saturate color values */
      if (autosarproject_DW.InsertText1_colorVectorDW[0] < 0.0F) {
        autosarproject_DW.InsertText1_colorVectorDW[0] = 0.0F;
      } else if (autosarproject_DW.InsertText1_colorVectorDW[0] > 1.0F) {
        autosarproject_DW.InsertText1_colorVectorDW[0] = 1.0F;
      }

      autosarproject_DW.InsertText1_colorVectorDW[1] =
        autosarproject_P.InsertText1_textColor[1];

      /* Saturate color values */
      if (autosarproject_DW.InsertText1_colorVectorDW[1] < 0.0F) {
        autosarproject_DW.InsertText1_colorVectorDW[1] = 0.0F;
      } else if (autosarproject_DW.InsertText1_colorVectorDW[1] > 1.0F) {
        autosarproject_DW.InsertText1_colorVectorDW[1] = 1.0F;
      }

      autosarproject_DW.InsertText1_colorVectorDW[2] =
        autosarproject_P.InsertText1_textColor[2];

      /* Saturate color values */
      if (autosarproject_DW.InsertText1_colorVectorDW[2] < 0.0F) {
        autosarproject_DW.InsertText1_colorVectorDW[2] = 0.0F;
      } else if (autosarproject_DW.InsertText1_colorVectorDW[2] > 1.0F) {
        autosarproject_DW.InsertText1_colorVectorDW[2] = 1.0F;
      }

      memcpy(&autosarproject_DW.InsertText1_VarHolder[0],
             &autosarproject_B.Message[bufIdx], 162U * sizeof(uint8_T));
      MWVIP_snprintf_wrapper(&autosarproject_DW.InsertText1_RepBuf[0U],
        &autosarproject_DW.InsertText1_StringDataDW[0],
        &autosarproject_DW.InsertText1_VarHolder[0U], outIdx + 1, 3, true, 167);
      i = MWVIP_strlen(&autosarproject_B.Message[bufIdx]) + 1;
      bufIdx += i;
      outIdx -= i;
      i = MWVIP_strlen(&autosarproject_DW.InsertText1_RepBuf[0]);
      if ((inIdx < 8) && (outIdx <= 0)) {
        bufIdx = centerM;
        outIdx = startC;
      }

      if (!(autosarproject_P.InsertText1_textOpacity == 0.0F)) {
        /* put the pen at the beginning of the string */
        ku = similarity_tmp;
        startC = (int32_T)(real32_T)floor(autosarproject_B.Bias[inIdx + 9]);
        for (centerM = 0; centerM < i; centerM++) {
          if (autosarproject_DW.InsertText1_RepBuf[centerM] == 10) {
            startC += 15;
            ku = similarity_tmp;
          } else {
            maxr = autosarproject_DW.InsertText1_RepBuf[centerM];
            j_pixListNinc = (int32_T)
              autosarproject_ConstP.InsertText1_GlyIndexes[maxr];
            if ((autosarproject_ConstP.InsertText1_GlyWidths[maxr] == 0) ||
                (autosarproject_ConstP.InsertText1_GlyHeights[maxr] == 0) ||
                (autosarproject_ConstP.InsertText1_GlyXAdvances[maxr] == 0)) {
              maxr = 32;
              j_pixListNinc = 0;
            }

            stepRows = autosarproject_P.InsertText1_textOpacity;
            MWVIP_DrawText_I_single_AA
              (&autosarproject_ConstP.InsertText1_GlyData[j_pixListNinc], ku,
               startC + 11, autosarproject_ConstP.InsertText1_GlyLBearings[maxr],
               autosarproject_ConstP.InsertText1_GlyTBearings[maxr],
               autosarproject_ConstP.InsertText1_GlyWidths[maxr],
               autosarproject_ConstP.InsertText1_GlyHeights[maxr], 360U, 180U,
               &autosarproject_B.InsertText1[0],
               &autosarproject_DW.InsertText1_colorVectorDW[0], &stepRows, false);
            MWVIP_DrawText_I_single_AA
              (&autosarproject_ConstP.InsertText1_GlyData[j_pixListNinc], ku,
               startC + 11, autosarproject_ConstP.InsertText1_GlyLBearings[maxr],
               autosarproject_ConstP.InsertText1_GlyTBearings[maxr],
               autosarproject_ConstP.InsertText1_GlyWidths[maxr],
               autosarproject_ConstP.InsertText1_GlyHeights[maxr], 360U, 180U,
               &autosarproject_B.InsertText1[64800],
               &autosarproject_DW.InsertText1_colorVectorDW[1], &stepRows, false);
            MWVIP_DrawText_I_single_AA
              (&autosarproject_ConstP.InsertText1_GlyData[j_pixListNinc], ku,
               startC + 11, autosarproject_ConstP.InsertText1_GlyLBearings[maxr],
               autosarproject_ConstP.InsertText1_GlyTBearings[maxr],
               autosarproject_ConstP.InsertText1_GlyWidths[maxr],
               autosarproject_ConstP.InsertText1_GlyHeights[maxr], 360U, 180U,
               &autosarproject_B.InsertText1[129600],
               &autosarproject_DW.InsertText1_colorVectorDW[2], &stepRows, false);
            ku += autosarproject_ConstP.InsertText1_GlyXAdvances[maxr];
          }
        }
      }

      inIdx++;
    } else {
      outIdx = -1;
    }
  }

  /* Sum: '<S12>/FixPt Sum1' incorporates:
   *  Constant: '<S12>/FixPt Constant'
   */
  rtb_Output += autosarproject_P.FixPtConstant_Value;

  /* Switch: '<S13>/FixPt Switch' */
  if (rtb_Output > autosarproject_P.NSampleEnable_sample) {
    /* Update for UnitDelay: '<S10>/Output' incorporates:
     *  Constant: '<S13>/Constant'
     */
    autosarproject_DW.Output_DSTATE = autosarproject_P.Constant_Value_b;
  } else {
    /* Update for UnitDelay: '<S10>/Output' */
    autosarproject_DW.Output_DSTATE = rtb_Output;
  }

  /* End of Switch: '<S13>/FixPt Switch' */

  /* Update for UnitDelay: '<S6>/Unit Delay1' */
  memcpy(&autosarproject_DW.UnitDelay1_DSTATE[0], &rtb_BBox[0], 36U * sizeof
         (real32_T));

  /* Update for UnitDelay: '<S6>/Unit Delay2' incorporates:
   *  MATLAB Function: '<S6>/MATLAB Function'
   */
  autosarproject_DW.UnitDelay2_DSTATE = bestSimilarity;
  for (i = 0; i < 9; i++) {
    /* Update for UnitDelay: '<S6>/Unit Delay' */
    autosarproject_DW.UnitDelay_DSTATE[i] = rtb_Count[i];

    /* Update for UnitDelay: '<S5>/Unit Delay4' */
    autosarproject_DW.UnitDelay4_DSTATE[i] = rtb_Status[i];

    /* Update for UnitDelay: '<S5>/Unit Delay3' */
    autosarproject_DW.UnitDelay3_DSTATE[i] = rtb_Count_n[i];
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(autosarproject_M->rtwLogInfo,
                      (&autosarproject_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                             /* Sample time: [0.033333299999999996s, 0.0s] */
    if ((rtmGetTFinal(autosarproject_M)!=-1) &&
        !((rtmGetTFinal(autosarproject_M)-autosarproject_M->Timing.taskTime0) >
          autosarproject_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(autosarproject_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++autosarproject_M->Timing.clockTick0)) {
    ++autosarproject_M->Timing.clockTickH0;
  }

  autosarproject_M->Timing.taskTime0 = autosarproject_M->Timing.clockTick0 *
    autosarproject_M->Timing.stepSize0 + autosarproject_M->Timing.clockTickH0 *
    autosarproject_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void autosarproject_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)autosarproject_M, 0,
                sizeof(RT_MODEL_autosarproject_T));
  rtmSetTFinal(autosarproject_M, -1);
  autosarproject_M->Timing.stepSize0 = 0.033333299999999996;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    autosarproject_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(autosarproject_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(autosarproject_M->rtwLogInfo, (NULL));
    rtliSetLogT(autosarproject_M->rtwLogInfo, "");
    rtliSetLogX(autosarproject_M->rtwLogInfo, "");
    rtliSetLogXFinal(autosarproject_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(autosarproject_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(autosarproject_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(autosarproject_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(autosarproject_M->rtwLogInfo, 1);
    rtliSetLogY(autosarproject_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(autosarproject_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(autosarproject_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &autosarproject_B), 0,
                sizeof(B_autosarproject_T));

  {
    int32_T i;
    for (i = 0; i < 64800; i++) {
      autosarproject_B.ColorSpaceConversion1_o1[i] = 0.0F;
    }

    for (i = 0; i < 64800; i++) {
      autosarproject_B.ColorSpaceConversion1_o2[i] = 0.0F;
    }

    for (i = 0; i < 64800; i++) {
      autosarproject_B.ColorSpaceConversion1_o3[i] = 0.0F;
    }

    for (i = 0; i < 64800; i++) {
      autosarproject_B.FromMultimediaFile_o1[i] = 0.0F;
    }

    for (i = 0; i < 64800; i++) {
      autosarproject_B.FromMultimediaFile_o2[i] = 0.0F;
    }

    for (i = 0; i < 64800; i++) {
      autosarproject_B.FromMultimediaFile_o3[i] = 0.0F;
    }

    for (i = 0; i < 194400; i++) {
      autosarproject_B.DrawShapes1[i] = 0.0F;
    }

    for (i = 0; i < 18; i++) {
      autosarproject_B.Bias[i] = 0.0F;
    }

    for (i = 0; i < 194400; i++) {
      autosarproject_B.InsertText1[i] = 0.0F;
    }
  }

  /* states (dwork) */
  (void) memset((void *)&autosarproject_DW, 0,
                sizeof(DW_autosarproject_T));

  {
    int32_T i;
    for (i = 0; i < 137; i++) {
      autosarproject_DW.FromMultimediaFile_HostLib[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      autosarproject_DW.FromMultimediaFile_AudioInfo[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 11; i++) {
      autosarproject_DW.FromMultimediaFile_VideoInfo[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 36; i++) {
      autosarproject_DW.UnitDelay1_DSTATE[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      autosarproject_DW.UnitDelay_DSTATE[i] = 0.0F;
    }
  }

  autosarproject_DW.UnitDelay2_DSTATE = 0.0F;

  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      autosarproject_DW.UnitDelay4_DSTATE[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      autosarproject_DW.UnitDelay3_DSTATE[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 64800; i++) {
      autosarproject_DW.ColorSpaceConversion1_DWORK1[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 27; i++) {
      autosarproject_DW.DrawShapes1_DW_FillColorAdd[i] = 0.0F;
    }
  }

  autosarproject_DW.DrawShapes1_DW_OneMOpacity = 0.0F;
  autosarproject_DW.InsertText1_colorVectorDW[0] = 0.0F;
  autosarproject_DW.InsertText1_colorVectorDW[1] = 0.0F;
  autosarproject_DW.InsertText1_colorVectorDW[2] = 0.0F;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(autosarproject_M->rtwLogInfo, 0.0,
    rtmGetTFinal(autosarproject_M), autosarproject_M->Timing.stepSize0,
    (&rtmGetErrorStatus(autosarproject_M)));

  {
    int32_T curNumNonZ;
    int32_T idxOffsets;
    int32_T m;
    char_T *sErr;

    /* Start for S-Function (sdspwmmfi2): '<S3>/From Multimedia File' */
    sErr = GetErrorBuffer(&autosarproject_DW.FromMultimediaFile_HostLib[0U]);
    CreateHostLibrary("frommmfile.dll",
                      &autosarproject_DW.FromMultimediaFile_HostLib[0U]);
    createAudioInfo(&autosarproject_DW.FromMultimediaFile_AudioInfo[0U], 0U, 0U,
                    0.0, 0, 0, 0, 0, GetNullPointer());
    createVideoInfo(&autosarproject_DW.FromMultimediaFile_VideoInfo[0U], 1U,
                    30.00003000003, 30.00003000003, "RGB ", 3, 3, 360, 180, 0U,
                    1, 1, GetNullPointer());
    if (*sErr == 0) {
      LibCreate_FromMMFile(&autosarproject_DW.FromMultimediaFile_HostLib[0U],
                           NULL,
                           "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\vision\\visiondata\\vipwarnsigns.avi",
                           1, "", "",
                           &autosarproject_DW.FromMultimediaFile_AudioInfo[0U],
                           &autosarproject_DW.FromMultimediaFile_VideoInfo[0U],
                           0U, 1U, 1U, 0U, 0U, 1U, 1.0, 9.2233720368547758E+18,
                           0U);
    }

    if (*sErr == 0) {
      LibStart(&autosarproject_DW.FromMultimediaFile_HostLib[0U]);
    }

    if (*sErr != 0) {
      DestroyHostLibrary(&autosarproject_DW.FromMultimediaFile_HostLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(autosarproject_M, sErr);
        rtmSetStopRequested(autosarproject_M, 1);
      }
    }

    /* End of Start for S-Function (sdspwmmfi2): '<S3>/From Multimedia File' */

    /* Start for S-Function (svipmorphop): '<S1>/Closing' */
    idxOffsets = 0;
    curNumNonZ = 0;
    for (m = 0; m < 15; m++) {
      autosarproject_DW.Closing_ERODE_OFF_DW[idxOffsets] = m;
      idxOffsets = curNumNonZ + 1;
      curNumNonZ++;
    }

    for (m = 0; m < 15; m++) {
      autosarproject_DW.Closing_ERODE_OFF_DW[idxOffsets] = m * 209;
      idxOffsets++;
    }

    idxOffsets = 0;
    curNumNonZ = 0;
    for (m = 0; m < 15; m++) {
      autosarproject_DW.Closing_DILATE_OFF_DW[idxOffsets] = m;
      idxOffsets = curNumNonZ + 1;
      curNumNonZ++;
    }

    autosarproject_DW.Closing_NUMNONZ_DW[0] = curNumNonZ;
    curNumNonZ = 0;
    for (m = 0; m < 15; m++) {
      autosarproject_DW.Closing_DILATE_OFF_DW[idxOffsets] = m * 209;
      curNumNonZ++;
      idxOffsets++;
    }

    autosarproject_DW.Closing_NUMNONZ_DW[1] = curNumNonZ;

    /* End of Start for S-Function (svipmorphop): '<S1>/Closing' */

    /* Start for S-Function (svipdrawshapes): '<S2>/Draw Shapes1' */
    /* Calculate FillColor times Opacity. */
    autosarproject_DW.DrawShapes1_DW_FillColorAdd[0] =
      autosarproject_P.DrawShapes1_color[0] *
      autosarproject_P.DrawShapes1_opacity;
    autosarproject_DW.DrawShapes1_DW_FillColorAdd[1] =
      autosarproject_P.DrawShapes1_color[1] *
      autosarproject_P.DrawShapes1_opacity;
    autosarproject_DW.DrawShapes1_DW_FillColorAdd[2] =
      autosarproject_P.DrawShapes1_color[2] *
      autosarproject_P.DrawShapes1_opacity;

    /* Calculate One minus Opacity. */
    autosarproject_DW.DrawShapes1_DW_OneMOpacity = 1.0F -
      autosarproject_P.DrawShapes1_opacity;

    /* Start for S-Function (sviptextrender): '<S2>/Insert Text1' */
    autosarproject_DW.InsertText1_StringDataDW[0] = 37U;
    autosarproject_DW.InsertText1_StringDataDW[1] = 115U;
    autosarproject_DW.InsertText1_StringDataDW[2] = 0U;
  }

  {
    int32_T i;

    /* InitializeConditions for S-Function (sdspwmmfi2): '<S3>/From Multimedia File' */
    LibReset(&autosarproject_DW.FromMultimediaFile_HostLib[0U]);

    /* InitializeConditions for UnitDelay: '<S10>/Output' */
    autosarproject_DW.Output_DSTATE = autosarproject_P.Output_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay1' */
    for (i = 0; i < 36; i++) {
      autosarproject_DW.UnitDelay1_DSTATE[i] =
        autosarproject_P.UnitDelay1_InitialCondition;
    }

    /* End of InitializeConditions for UnitDelay: '<S6>/Unit Delay1' */

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay2' */
    autosarproject_DW.UnitDelay2_DSTATE =
      autosarproject_P.UnitDelay2_InitialCondition;
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
      autosarproject_DW.UnitDelay_DSTATE[i] =
        autosarproject_P.UnitDelay_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S5>/Unit Delay4' */
      autosarproject_DW.UnitDelay4_DSTATE[i] =
        autosarproject_P.UnitDelay4_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S5>/Unit Delay3' */
      autosarproject_DW.UnitDelay3_DSTATE[i] =
        autosarproject_P.UnitDelay3_InitialCondition;
    }

    /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
    /* SystemInitialize for Outport: '<S11>/Out1' incorporates:
     *  Constant: '<S11>/Constant'
     */
    autosarproject_B.Constant = autosarproject_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */
  }
}

/* Model terminate function */
void autosarproject_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspwmmfi2): '<S3>/From Multimedia File' */
  sErr = GetErrorBuffer(&autosarproject_DW.FromMultimediaFile_HostLib[0U]);
  LibTerminate(&autosarproject_DW.FromMultimediaFile_HostLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(autosarproject_M, sErr);
    rtmSetStopRequested(autosarproject_M, 1);
  }

  LibDestroy(&autosarproject_DW.FromMultimediaFile_HostLib[0U], 0);
  DestroyHostLibrary(&autosarproject_DW.FromMultimediaFile_HostLib[0U]);

  /* End of Terminate for S-Function (sdspwmmfi2): '<S3>/From Multimedia File' */
}
