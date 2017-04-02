/*
 * ctrl_student_HIL.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.296
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sun Apr 02 17:23:21 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_student_HIL_h_
#define RTW_HEADER_ctrl_student_HIL_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ctrl_student_HIL_COMMON_INCLUDES_
# define ctrl_student_HIL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_student_HIL_COMMON_INCLUDES_ */

#include "ctrl_student_HIL_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define ctrl_student_HIL_rtModel       RT_MODEL_ctrl_student_HIL_T

/* Block signals (auto storage) */
typedef struct {
  real_T niose_power;                  /* '<Root>/niose_power' */
  real_T WhiteNoise;                   /* '<S28>/White Noise' */
  real_T WhiteNoise_e;                 /* '<S29>/White Noise' */
  real_T WhiteNoise_m;                 /* '<S27>/White Noise' */
  real_T y_in;                         /* '<Root>/y_in' */
  real_T x_in;                         /* '<Root>/x_in' */
  real_T psi_in;                       /* '<Root>/psi_in' */
  real_T Hold[3];                      /* '<S23>/Hold' */
  real_T Dropout;                      /* '<S7>/Drop-out' */
  real_T Memory[3];                    /* '<S7>/Memory' */
  real_T Memory_a[3];                  /* '<S36>/Memory' */
  real_T SystemReset;                  /* '<Root>/System Reset' */
  real_T Integrator2[3];               /* '<S5>/Integrator2' */
  real_T Sum[3];                       /* '<Root>/Sum' */
  real_T r_in;                         /* '<Root>/r_in' */
  real_T u_in;                         /* '<Root>/u_in' */
  real_T v_in;                         /* '<Root>/v_in' */
  real_T Integrator[3];                /* '<S3>/Integrator' */
  real_T L2_continuous;                /* '<S9>/L2_continuous' */
  real_T PosXRight;                    /* '<S9>/PosXRight' */
  real_T PosYRight;                    /* '<S9>/PosYRight' */
  real_T R2_continuous;                /* '<S9>/R2_continuous' */
  real_T PosXLeft;                     /* '<S9>/PosXLeft' */
  real_T PosYLeft;                     /* '<S9>/PosYLeft' */
  real_T L1;                           /* '<S9>/L1' */
  real_T R1;                           /* '<S9>/R1' */
  real_T ArrowDown;                    /* '<S9>/ArrowDown' */
  real_T ArrowUp;                      /* '<S9>/ArrowUp' */
  real_T ArrowLeft;                    /* '<S9>/ArrowLeft' */
  real_T ArrowRight;                   /* '<S9>/ArrowRight' */
  real_T Integrator1;                  /* '<S3>/Integrator1' */
  real_T pathNumber;                   /* '<S14>/ pathNumber' */
  real_T U_ref;                        /* '<S14>/ U_ref' */
  real_T IC[3];                        /* '<S15>/IC' */
  real_T IC1[3];                       /* '<S15>/IC1' */
  real_T my;                           /* '<S18>/my' */
  real_T Memory_p;                     /* '<S18>/Memory' */
  real_T IC3;                          /* '<S15>/IC3' */
  real_T IC2[3];                       /* '<S15>/IC2' */
  real_T K_p2_1;                       /* '<S2>/K_p2_1' */
  real_T K_p2_2;                       /* '<S2>/K_p2_2' */
  real_T K_p2_3;                       /* '<S2>/K_p2_3' */
  real_T Integrator1_k[3];             /* '<S5>/Integrator1' */
  real_T MatrixMultiply2[3];           /* '<S30>/Matrix Multiply2' */
  real_T Sum1[3];                      /* '<S1>/Sum1' */
  real_T Saturation[3];                /* '<S1>/Saturation' */
  real_T MatrixMultiply[3];            /* '<S3>/Matrix Multiply' */
  real_T L1_11;                        /* '<S2>/L1_11' */
  real_T L1_22;                        /* '<S2>/L1_22' */
  real_T L1_33;                        /* '<S2>/L1_33' */
  real_T L2_11;                        /* '<S2>/L2_11' */
  real_T L2_22;                        /* '<S2>/L2_22' */
  real_T L2_33;                        /* '<S2>/L2_33' */
  real_T L3_11;                        /* '<S2>/L3_11' */
  real_T L3_22;                        /* '<S2>/L3_22' */
  real_T L3_33;                        /* '<S2>/L3_33' */
  real_T MatrixMultiply9[3];           /* '<S30>/Matrix Multiply9' */
  real_T MatrixMultiply4[3];           /* '<S5>/Matrix Multiply4' */
  real_T Sum1_n[3];                    /* '<S5>/Sum1' */
  real_T eta_m_out[3];                 /* '<S7>/Signal drop-out simulation' */
  real_T eta_m_c1[3];                  /* '<S36>/MATLAB Function' */
  real_T output[3];                    /* '<S23>/MATLAB Function1' */
  real_T count;                        /* '<S22>/MATLAB Function' */
  real_T s_dot;                        /* '<S18>/s calculation' */
  real_T z1_inertial[3];               /* '<S1>/MATLAB Function' */
} B_ctrl_student_HIL_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T counter_PreviousInput;        /* '<S22>/counter' */
  real_T niose_power_DWORK1;           /* '<Root>/niose_power' */
  real_T NextOutput;                   /* '<S28>/White Noise' */
  real_T NextOutput_c;                 /* '<S29>/White Noise' */
  real_T NextOutput_p;                 /* '<S27>/White Noise' */
  real_T y_in_DWORK1;                  /* '<Root>/y_in' */
  real_T x_in_DWORK1;                  /* '<Root>/x_in' */
  real_T psi_in_DWORK1;                /* '<Root>/psi_in' */
  real_T Hold_PreviousInput[3];        /* '<S23>/Hold' */
  real_T Dropout_DWORK1;               /* '<S7>/Drop-out' */
  real_T Memory_PreviousInput[3];      /* '<S7>/Memory' */
  real_T Memory_PreviousInput_n[3];    /* '<S36>/Memory' */
  real_T SystemReset_DWORK1;           /* '<Root>/System Reset' */
  real_T eta_tilde_psi_DWORK1;         /* '<Root>/ eta_tilde_psi' */
  real_T eta_tilde_x_DWORK1;           /* '<Root>/ eta_tilde_x' */
  real_T eta_tilde_y_DWORK1;           /* '<Root>/ eta_tilde_y' */
  real_T eta_hat_psi_DWORK1;           /* '<Root>/eta_hat_psi' */
  real_T r_in_DWORK1;                  /* '<Root>/r_in' */
  real_T eta_hat_x_DWORK1;             /* '<Root>/eta_hat_x' */
  real_T u_in_DWORK1;                  /* '<Root>/u_in' */
  real_T eta_hat_y_DWORK1;             /* '<Root>/eta_hat_y' */
  real_T v_in_DWORK1;                  /* '<Root>/v_in' */
  real_T eta_d_PSI_DWORK1;             /* '<S8>/eta_d_PSI' */
  real_T eta_d_X_DWORK1;               /* '<S8>/eta_d_X' */
  real_T eta_d_Y_DWORK1;               /* '<S8>/eta_d_Y' */
  real_T L2_continuous_DWORK1;         /* '<S9>/L2_continuous' */
  real_T PosXRight_DWORK1;             /* '<S9>/PosXRight' */
  real_T PosYRight_DWORK1;             /* '<S9>/PosYRight' */
  real_T R2_continuous_DWORK1;         /* '<S9>/R2_continuous' */
  real_T PosXLeft_DWORK1;              /* '<S9>/PosXLeft' */
  real_T PosYLeft_DWORK1;              /* '<S9>/PosYLeft' */
  real_T L1_DWORK1;                    /* '<S9>/L1' */
  real_T R1_DWORK1;                    /* '<S9>/R1' */
  real_T ArrowDown_DWORK1;             /* '<S9>/ArrowDown' */
  real_T ArrowUp_DWORK1;               /* '<S9>/ArrowUp' */
  real_T ArrowLeft_DWORK1;             /* '<S9>/ArrowLeft' */
  real_T ArrowRight_DWORK1;            /* '<S9>/ArrowRight' */
  real_T pathNumber_DWORK1;            /* '<S14>/ pathNumber' */
  real_T U_ref_DWORK1;                 /* '<S14>/ U_ref' */
  real_T IC_FirstOutputTime;           /* '<S15>/IC' */
  real_T IC1_FirstOutputTime;          /* '<S15>/IC1' */
  real_T my_DWORK1;                    /* '<S18>/my' */
  real_T Memory_PreviousInput_g;       /* '<S18>/Memory' */
  real_T IC3_FirstOutputTime;          /* '<S15>/IC3' */
  real_T IC2_FirstOutputTime;          /* '<S15>/IC2' */
  real_T K_p2_1_DWORK1;                /* '<S2>/K_p2_1' */
  real_T K_p2_2_DWORK1;                /* '<S2>/K_p2_2' */
  real_T K_p2_3_DWORK1;                /* '<S2>/K_p2_3' */
  real_T N_d_DWORK1;                   /* '<S10>/N_d' */
  real_T X_d_DWORK1;                   /* '<S10>/X_d' */
  real_T Y_d_DWORK1;                   /* '<S10>/Y_d' */
  real_T integratorresetmodel_DWORK1;  /* '<S10>/integrator reset model' */
  real_T psi_0_DWORK1;                 /* '<S10>/psi_0 ' */
  real_T x_0_DWORK1;                   /* '<S10>/x_0' */
  real_T y_0_DWORK1;                   /* '<S10>/y_0' */
  real_T tau_d_x_DWORK1;               /* '<S1>/tau_d_x' */
  real_T tau_d_psi_DWORK1;             /* '<S1>/tau_d_psi' */
  real_T tau_d_y_DWORK1;               /* '<S1>/tau_d_y' */
  real_T z1_psi_DWORK1;                /* '<S1>/z1_psi' */
  real_T z1_x_DWORK1;                  /* '<S1>/z1_x' */
  real_T z1_y_DWORK1;                  /* '<S1>/z1_y' */
  real_T s_DWORK1;                     /* '<S3>/s' */
  real_T s_dot_DWORK1;                 /* '<S3>/s_dot' */
  real_T bias_x_DWORK1;                /* '<S5>/bias_x' */
  real_T bias_y_DWORK1;                /* '<S5>/bias_y' */
  real_T bias_psi_DWORK1;              /* '<S5>/bias_psi' */
  real_T nu_x_hat_DWORK1;              /* '<S33>/ nu_x_hat' */
  real_T nu_y_hat_DWORK1;              /* '<S33>/ nu_y_hat' */
  real_T nu_psi_hat_DWORK1;            /* '<S33>/nu_psi_hat' */
  real_T L1_11_DWORK1;                 /* '<S2>/L1_11' */
  real_T L1_22_DWORK1;                 /* '<S2>/L1_22' */
  real_T L1_33_DWORK1;                 /* '<S2>/L1_33' */
  real_T L2_11_DWORK1;                 /* '<S2>/L2_11' */
  real_T L2_22_DWORK1;                 /* '<S2>/L2_22' */
  real_T L2_33_DWORK1;                 /* '<S2>/L2_33' */
  real_T L3_11_DWORK1;                 /* '<S2>/L3_11' */
  real_T L3_22_DWORK1;                 /* '<S2>/L3_22' */
  real_T L3_33_DWORK1;                 /* '<S2>/L3_33' */
  real_T eta_mpsi_DWORK1;              /* '<S7>/eta_mpsi' */
  real_T eta_mx_DWORK1;                /* '<S7>/eta_mx' */
  real_T eta_my_DWORK1;                /* '<S7>/eta_my' */
  uint32_T RandSeed;                   /* '<S28>/White Noise' */
  uint32_T RandSeed_j;                 /* '<S29>/White Noise' */
  uint32_T RandSeed_c;                 /* '<S27>/White Noise' */
  struct {
    int_T IcNeedsLoading;
  } Integrator2_IWORK;                 /* '<S5>/Integrator2' */

  uint8_T niose_power_DWORK2[17];      /* '<Root>/niose_power' */
  uint8_T y_in_DWORK2[17];             /* '<Root>/y_in' */
  uint8_T x_in_DWORK2[17];             /* '<Root>/x_in' */
  uint8_T psi_in_DWORK2[17];           /* '<Root>/psi_in' */
  uint8_T Dropout_DWORK2[17];          /* '<S7>/Drop-out' */
  uint8_T SystemReset_DWORK2[17];      /* '<Root>/System Reset' */
  uint8_T eta_tilde_psi_DWORK2[17];    /* '<Root>/ eta_tilde_psi' */
  uint8_T eta_tilde_x_DWORK2[17];      /* '<Root>/ eta_tilde_x' */
  uint8_T eta_tilde_y_DWORK2[17];      /* '<Root>/ eta_tilde_y' */
  uint8_T eta_hat_psi_DWORK2[17];      /* '<Root>/eta_hat_psi' */
  uint8_T r_in_DWORK2[17];             /* '<Root>/r_in' */
  uint8_T eta_hat_x_DWORK2[17];        /* '<Root>/eta_hat_x' */
  uint8_T u_in_DWORK2[17];             /* '<Root>/u_in' */
  uint8_T eta_hat_y_DWORK2[17];        /* '<Root>/eta_hat_y' */
  uint8_T v_in_DWORK2[17];             /* '<Root>/v_in' */
  uint8_T eta_d_PSI_DWORK2[17];        /* '<S8>/eta_d_PSI' */
  uint8_T eta_d_X_DWORK2[17];          /* '<S8>/eta_d_X' */
  uint8_T eta_d_Y_DWORK2[17];          /* '<S8>/eta_d_Y' */
  uint8_T L2_continuous_DWORK2[17];    /* '<S9>/L2_continuous' */
  uint8_T PosXRight_DWORK2[17];        /* '<S9>/PosXRight' */
  uint8_T PosYRight_DWORK2[17];        /* '<S9>/PosYRight' */
  uint8_T R2_continuous_DWORK2[17];    /* '<S9>/R2_continuous' */
  uint8_T PosXLeft_DWORK2[17];         /* '<S9>/PosXLeft' */
  uint8_T PosYLeft_DWORK2[17];         /* '<S9>/PosYLeft' */
  uint8_T L1_DWORK2[17];               /* '<S9>/L1' */
  uint8_T R1_DWORK2[17];               /* '<S9>/R1' */
  uint8_T ArrowDown_DWORK2[17];        /* '<S9>/ArrowDown' */
  uint8_T ArrowUp_DWORK2[17];          /* '<S9>/ArrowUp' */
  uint8_T ArrowLeft_DWORK2[17];        /* '<S9>/ArrowLeft' */
  uint8_T ArrowRight_DWORK2[17];       /* '<S9>/ArrowRight' */
  uint8_T pathNumber_DWORK2[17];       /* '<S14>/ pathNumber' */
  uint8_T U_ref_DWORK2[17];            /* '<S14>/ U_ref' */
  uint8_T my_DWORK2[17];               /* '<S18>/my' */
  uint8_T K_p2_1_DWORK2[17];           /* '<S2>/K_p2_1' */
  uint8_T K_p2_2_DWORK2[17];           /* '<S2>/K_p2_2' */
  uint8_T K_p2_3_DWORK2[17];           /* '<S2>/K_p2_3' */
  uint8_T N_d_DWORK2[17];              /* '<S10>/N_d' */
  uint8_T X_d_DWORK2[17];              /* '<S10>/X_d' */
  uint8_T Y_d_DWORK2[17];              /* '<S10>/Y_d' */
  uint8_T integratorresetmodel_DWORK2[17];/* '<S10>/integrator reset model' */
  uint8_T psi_0_DWORK2[17];            /* '<S10>/psi_0 ' */
  uint8_T x_0_DWORK2[17];              /* '<S10>/x_0' */
  uint8_T y_0_DWORK2[17];              /* '<S10>/y_0' */
  uint8_T tau_d_x_DWORK2[17];          /* '<S1>/tau_d_x' */
  uint8_T tau_d_psi_DWORK2[17];        /* '<S1>/tau_d_psi' */
  uint8_T tau_d_y_DWORK2[17];          /* '<S1>/tau_d_y' */
  uint8_T z1_psi_DWORK2[17];           /* '<S1>/z1_psi' */
  uint8_T z1_x_DWORK2[17];             /* '<S1>/z1_x' */
  uint8_T z1_y_DWORK2[17];             /* '<S1>/z1_y' */
  uint8_T s_DWORK2[17];                /* '<S3>/s' */
  uint8_T s_dot_DWORK2[17];            /* '<S3>/s_dot' */
  uint8_T bias_x_DWORK2[17];           /* '<S5>/bias_x' */
  uint8_T bias_y_DWORK2[17];           /* '<S5>/bias_y' */
  uint8_T bias_psi_DWORK2[17];         /* '<S5>/bias_psi' */
  uint8_T nu_x_hat_DWORK2[17];         /* '<S33>/ nu_x_hat' */
  uint8_T nu_y_hat_DWORK2[17];         /* '<S33>/ nu_y_hat' */
  uint8_T nu_psi_hat_DWORK2[17];       /* '<S33>/nu_psi_hat' */
  uint8_T L1_11_DWORK2[17];            /* '<S2>/L1_11' */
  uint8_T L1_22_DWORK2[17];            /* '<S2>/L1_22' */
  uint8_T L1_33_DWORK2[17];            /* '<S2>/L1_33' */
  uint8_T L2_11_DWORK2[17];            /* '<S2>/L2_11' */
  uint8_T L2_22_DWORK2[17];            /* '<S2>/L2_22' */
  uint8_T L2_33_DWORK2[17];            /* '<S2>/L2_33' */
  uint8_T L3_11_DWORK2[17];            /* '<S2>/L3_11' */
  uint8_T L3_22_DWORK2[17];            /* '<S2>/L3_22' */
  uint8_T L3_33_DWORK2[17];            /* '<S2>/L3_33' */
  uint8_T eta_mpsi_DWORK2[17];         /* '<S7>/eta_mpsi' */
  uint8_T eta_mx_DWORK2[17];           /* '<S7>/eta_mx' */
  uint8_T eta_my_DWORK2[17];           /* '<S7>/eta_my' */
} DW_ctrl_student_HIL_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator2_CSTATE[3];        /* '<S5>/Integrator2' */
  real_T Integrator_CSTATE[3];         /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S3>/Integrator1' */
  real_T Integrator1_CSTATE_b[3];      /* '<S5>/Integrator1' */
  real_T Integrator_CSTATE_n[3];       /* '<S30>/Integrator' */
} X_ctrl_student_HIL_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator2_CSTATE[3];        /* '<S5>/Integrator2' */
  real_T Integrator_CSTATE[3];         /* '<S3>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S3>/Integrator1' */
  real_T Integrator1_CSTATE_b[3];      /* '<S5>/Integrator1' */
  real_T Integrator_CSTATE_n[3];       /* '<S30>/Integrator' */
} XDot_ctrl_student_HIL_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE[3];     /* '<S5>/Integrator2' */
  boolean_T Integrator_CSTATE[3];      /* '<S3>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S3>/Integrator1' */
  boolean_T Integrator1_CSTATE_b[3];   /* '<S5>/Integrator1' */
  boolean_T Integrator_CSTATE_n[3];    /* '<S30>/Integrator' */
} XDis_ctrl_student_HIL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator2_Reset_ZCE;    /* '<S5>/Integrator2' */
  ZCSigState Integrator1_Reset_ZCE;    /* '<S5>/Integrator1' */
} PrevZCX_ctrl_student_HIL_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_student_HIL_B
#define BlockIO                        B_ctrl_student_HIL_T
#define rtX                            ctrl_student_HIL_X
#define ContinuousStates               X_ctrl_student_HIL_T
#define rtXdot                         ctrl_student_HIL_XDot
#define StateDerivatives               XDot_ctrl_student_HIL_T
#define tXdis                          ctrl_student_HIL_XDis
#define StateDisabled                  XDis_ctrl_student_HIL_T
#define rtP                            ctrl_student_HIL_P
#define Parameters                     P_ctrl_student_HIL_T
#define rtDWork                        ctrl_student_HIL_DW
#define D_Work                         DW_ctrl_student_HIL_T
#define rtPrevZCSigState               ctrl_student_HIL_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_student_HIL_T

/* Parameters (auto storage) */
struct P_ctrl_student_HIL_T_ {
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Constant4_Value;              /* Expression: 100
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Stepsize_Value;               /* Expression: 0.01
                                        * Referenced by: '<S4>/Step size'
                                        */
  real_T counter_X0;                   /* Expression: 0
                                        * Referenced by: '<S22>/counter'
                                        */
  real_T niose_power_P1;               /* Expression: width
                                        * Referenced by: '<Root>/niose_power'
                                        */
  real_T niose_power_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/niose_power'
                                        */
  real_T niose_power_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/niose_power'
                                        */
  real_T niose_power_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/niose_power'
                                        */
  real_T niose_power_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/niose_power'
                                        */
  real_T niose_power_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/niose_power'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 0.0001
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S28>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S28>/White Noise'
                                        */
  real_T WhiteNoise_Seed;              /* Expression: 9024
                                        * Referenced by: '<S28>/White Noise'
                                        */
  real_T WhiteNoise_Mean_h;            /* Expression: 0
                                        * Referenced by: '<S29>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_d;          /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S29>/White Noise'
                                        */
  real_T WhiteNoise_Seed_b;            /* Expression: 123
                                        * Referenced by: '<S29>/White Noise'
                                        */
  real_T WhiteNoise_Mean_f;            /* Expression: 0
                                        * Referenced by: '<S27>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_g;          /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S27>/White Noise'
                                        */
  real_T WhiteNoise_Seed_l;            /* Expression: 9025
                                        * Referenced by: '<S27>/White Noise'
                                        */
  real_T y_in_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/y_in'
                                        */
  real_T y_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/y_in'
                                        */
  real_T y_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/y_in'
                                        */
  real_T y_in_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/y_in'
                                        */
  real_T y_in_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/y_in'
                                        */
  real_T y_in_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/y_in'
                                        */
  real_T x_in_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/x_in'
                                        */
  real_T x_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/x_in'
                                        */
  real_T x_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/x_in'
                                        */
  real_T x_in_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/x_in'
                                        */
  real_T x_in_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/x_in'
                                        */
  real_T x_in_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/x_in'
                                        */
  real_T psi_in_P1;                    /* Expression: width
                                        * Referenced by: '<Root>/psi_in'
                                        */
  real_T psi_in_P2;                    /* Expression: dtype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  real_T psi_in_P3;                    /* Expression: portnum
                                        * Referenced by: '<Root>/psi_in'
                                        */
  real_T psi_in_P4;                    /* Expression: stime
                                        * Referenced by: '<Root>/psi_in'
                                        */
  real_T psi_in_P5;                    /* Expression: stype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  real_T psi_in_P6;                    /* Expression: btype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  real_T Hold_X0;                      /* Expression: 0
                                        * Referenced by: '<S23>/Hold'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Dropout_P1;                   /* Expression: width
                                        * Referenced by: '<S7>/Drop-out'
                                        */
  real_T Dropout_P2;                   /* Expression: dtype
                                        * Referenced by: '<S7>/Drop-out'
                                        */
  real_T Dropout_P3;                   /* Expression: portnum
                                        * Referenced by: '<S7>/Drop-out'
                                        */
  real_T Dropout_P4;                   /* Expression: stime
                                        * Referenced by: '<S7>/Drop-out'
                                        */
  real_T Dropout_P5;                   /* Expression: stype
                                        * Referenced by: '<S7>/Drop-out'
                                        */
  real_T Dropout_P6;                   /* Expression: btype
                                        * Referenced by: '<S7>/Drop-out'
                                        */
  real_T Memory_X0[3];                 /* Expression: [0 0 0]
                                        * Referenced by: '<S7>/Memory'
                                        */
  real_T Memory_X0_e[3];               /* Expression: [0 0 0]
                                        * Referenced by: '<S36>/Memory'
                                        */
  real_T SystemReset_P1;               /* Expression: width
                                        * Referenced by: '<Root>/System Reset'
                                        */
  real_T SystemReset_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/System Reset'
                                        */
  real_T SystemReset_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/System Reset'
                                        */
  real_T SystemReset_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/System Reset'
                                        */
  real_T SystemReset_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/System Reset'
                                        */
  real_T SystemReset_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/System Reset'
                                        */
  real_T eta_tilde_psi_P1;             /* Expression: width
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  real_T eta_tilde_psi_P2;             /* Expression: dtype
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  real_T eta_tilde_psi_P3;             /* Expression: portnum
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  real_T eta_tilde_psi_P4;             /* Expression: stime
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  real_T eta_tilde_psi_P5;             /* Expression: stype
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  real_T eta_tilde_psi_P6;             /* Expression: btype
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  real_T eta_tilde_x_P1;               /* Expression: width
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  real_T eta_tilde_x_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  real_T eta_tilde_x_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  real_T eta_tilde_x_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  real_T eta_tilde_x_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  real_T eta_tilde_x_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  real_T eta_tilde_y_P1;               /* Expression: width
                                        * Referenced by: '<Root>/ eta_tilde_y'
                                        */
  real_T eta_tilde_y_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/ eta_tilde_y'
                                        */
  real_T eta_tilde_y_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/ eta_tilde_y'
                                        */
  real_T eta_tilde_y_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/ eta_tilde_y'
                                        */
  real_T eta_tilde_y_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/ eta_tilde_y'
                                        */
  real_T eta_tilde_y_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/ eta_tilde_y'
                                        */
  real_T eta_hat_psi_P1;               /* Expression: width
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  real_T eta_hat_psi_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  real_T eta_hat_psi_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  real_T eta_hat_psi_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  real_T eta_hat_psi_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  real_T eta_hat_psi_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  real_T r_in_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/r_in'
                                        */
  real_T r_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/r_in'
                                        */
  real_T r_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/r_in'
                                        */
  real_T r_in_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/r_in'
                                        */
  real_T r_in_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/r_in'
                                        */
  real_T r_in_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/r_in'
                                        */
  real_T eta_hat_x_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  real_T eta_hat_x_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  real_T eta_hat_x_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  real_T eta_hat_x_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  real_T eta_hat_x_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  real_T eta_hat_x_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  real_T u_in_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/u_in'
                                        */
  real_T u_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/u_in'
                                        */
  real_T u_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/u_in'
                                        */
  real_T u_in_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/u_in'
                                        */
  real_T u_in_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/u_in'
                                        */
  real_T u_in_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/u_in'
                                        */
  real_T eta_hat_y_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  real_T eta_hat_y_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  real_T eta_hat_y_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  real_T eta_hat_y_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  real_T eta_hat_y_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  real_T eta_hat_y_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  real_T v_in_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/v_in'
                                        */
  real_T v_in_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/v_in'
                                        */
  real_T v_in_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/v_in'
                                        */
  real_T v_in_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/v_in'
                                        */
  real_T v_in_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/v_in'
                                        */
  real_T v_in_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/v_in'
                                        */
  real_T Integrator_IC[3];             /* Expression: [7;0;0]
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T eta_d_PSI_P1;                 /* Expression: width
                                        * Referenced by: '<S8>/eta_d_PSI'
                                        */
  real_T eta_d_PSI_P2;                 /* Expression: dtype
                                        * Referenced by: '<S8>/eta_d_PSI'
                                        */
  real_T eta_d_PSI_P3;                 /* Expression: portnum
                                        * Referenced by: '<S8>/eta_d_PSI'
                                        */
  real_T eta_d_PSI_P4;                 /* Expression: stime
                                        * Referenced by: '<S8>/eta_d_PSI'
                                        */
  real_T eta_d_PSI_P5;                 /* Expression: stype
                                        * Referenced by: '<S8>/eta_d_PSI'
                                        */
  real_T eta_d_PSI_P6;                 /* Expression: btype
                                        * Referenced by: '<S8>/eta_d_PSI'
                                        */
  real_T eta_d_X_P1;                   /* Expression: width
                                        * Referenced by: '<S8>/eta_d_X'
                                        */
  real_T eta_d_X_P2;                   /* Expression: dtype
                                        * Referenced by: '<S8>/eta_d_X'
                                        */
  real_T eta_d_X_P3;                   /* Expression: portnum
                                        * Referenced by: '<S8>/eta_d_X'
                                        */
  real_T eta_d_X_P4;                   /* Expression: stime
                                        * Referenced by: '<S8>/eta_d_X'
                                        */
  real_T eta_d_X_P5;                   /* Expression: stype
                                        * Referenced by: '<S8>/eta_d_X'
                                        */
  real_T eta_d_X_P6;                   /* Expression: btype
                                        * Referenced by: '<S8>/eta_d_X'
                                        */
  real_T eta_d_Y_P1;                   /* Expression: width
                                        * Referenced by: '<S8>/eta_d_Y'
                                        */
  real_T eta_d_Y_P2;                   /* Expression: dtype
                                        * Referenced by: '<S8>/eta_d_Y'
                                        */
  real_T eta_d_Y_P3;                   /* Expression: portnum
                                        * Referenced by: '<S8>/eta_d_Y'
                                        */
  real_T eta_d_Y_P4;                   /* Expression: stime
                                        * Referenced by: '<S8>/eta_d_Y'
                                        */
  real_T eta_d_Y_P5;                   /* Expression: stype
                                        * Referenced by: '<S8>/eta_d_Y'
                                        */
  real_T eta_d_Y_P6;                   /* Expression: btype
                                        * Referenced by: '<S8>/eta_d_Y'
                                        */
  real_T L2_continuous_P1;             /* Expression: width
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  real_T L2_continuous_P2;             /* Expression: dtype
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  real_T L2_continuous_P3;             /* Expression: portnum
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  real_T L2_continuous_P4;             /* Expression: stime
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  real_T L2_continuous_P5;             /* Expression: stype
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  real_T L2_continuous_P6;             /* Expression: btype
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  real_T PosXRight_P1;                 /* Expression: width
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  real_T PosXRight_P2;                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  real_T PosXRight_P3;                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  real_T PosXRight_P4;                 /* Expression: stime
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  real_T PosXRight_P5;                 /* Expression: stype
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  real_T PosXRight_P6;                 /* Expression: btype
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  real_T PosYRight_P1;                 /* Expression: width
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  real_T PosYRight_P2;                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  real_T PosYRight_P3;                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  real_T PosYRight_P4;                 /* Expression: stime
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  real_T PosYRight_P5;                 /* Expression: stype
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  real_T PosYRight_P6;                 /* Expression: btype
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  real_T R2_continuous_P1;             /* Expression: width
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  real_T R2_continuous_P2;             /* Expression: dtype
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  real_T R2_continuous_P3;             /* Expression: portnum
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  real_T R2_continuous_P4;             /* Expression: stime
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  real_T R2_continuous_P5;             /* Expression: stype
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  real_T R2_continuous_P6;             /* Expression: btype
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  real_T PosXLeft_P1;                  /* Expression: width
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  real_T PosXLeft_P2;                  /* Expression: dtype
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  real_T PosXLeft_P3;                  /* Expression: portnum
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  real_T PosXLeft_P4;                  /* Expression: stime
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  real_T PosXLeft_P5;                  /* Expression: stype
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  real_T PosXLeft_P6;                  /* Expression: btype
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  real_T PosYLeft_P1;                  /* Expression: width
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  real_T PosYLeft_P2;                  /* Expression: dtype
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  real_T PosYLeft_P3;                  /* Expression: portnum
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  real_T PosYLeft_P4;                  /* Expression: stime
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  real_T PosYLeft_P5;                  /* Expression: stype
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  real_T PosYLeft_P6;                  /* Expression: btype
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  real_T L1_P1;                        /* Expression: width
                                        * Referenced by: '<S9>/L1'
                                        */
  real_T L1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S9>/L1'
                                        */
  real_T L1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S9>/L1'
                                        */
  real_T L1_P4;                        /* Expression: stime
                                        * Referenced by: '<S9>/L1'
                                        */
  real_T L1_P5;                        /* Expression: stype
                                        * Referenced by: '<S9>/L1'
                                        */
  real_T L1_P6;                        /* Expression: btype
                                        * Referenced by: '<S9>/L1'
                                        */
  real_T R1_P1;                        /* Expression: width
                                        * Referenced by: '<S9>/R1'
                                        */
  real_T R1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S9>/R1'
                                        */
  real_T R1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S9>/R1'
                                        */
  real_T R1_P4;                        /* Expression: stime
                                        * Referenced by: '<S9>/R1'
                                        */
  real_T R1_P5;                        /* Expression: stype
                                        * Referenced by: '<S9>/R1'
                                        */
  real_T R1_P6;                        /* Expression: btype
                                        * Referenced by: '<S9>/R1'
                                        */
  real_T ArrowDown_P1;                 /* Expression: width
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  real_T ArrowDown_P2;                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  real_T ArrowDown_P3;                 /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  real_T ArrowDown_P4;                 /* Expression: stime
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  real_T ArrowDown_P5;                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  real_T ArrowDown_P6;                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  real_T ArrowUp_P1;                   /* Expression: width
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  real_T ArrowUp_P2;                   /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  real_T ArrowUp_P3;                   /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  real_T ArrowUp_P4;                   /* Expression: stime
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  real_T ArrowUp_P5;                   /* Expression: stype
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  real_T ArrowUp_P6;                   /* Expression: btype
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  real_T ArrowLeft_P1;                 /* Expression: width
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  real_T ArrowLeft_P2;                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  real_T ArrowLeft_P3;                 /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  real_T ArrowLeft_P4;                 /* Expression: stime
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  real_T ArrowLeft_P5;                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  real_T ArrowLeft_P6;                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  real_T ArrowRight_P1;                /* Expression: width
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  real_T ArrowRight_P2;                /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  real_T ArrowRight_P3;                /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  real_T ArrowRight_P4;                /* Expression: stime
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  real_T ArrowRight_P5;                /* Expression: stype
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  real_T ArrowRight_P6;                /* Expression: btype
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  real_T pathNumber_P1;                /* Expression: width
                                        * Referenced by: '<S14>/ pathNumber'
                                        */
  real_T pathNumber_P2;                /* Expression: dtype
                                        * Referenced by: '<S14>/ pathNumber'
                                        */
  real_T pathNumber_P3;                /* Expression: portnum
                                        * Referenced by: '<S14>/ pathNumber'
                                        */
  real_T pathNumber_P4;                /* Expression: stime
                                        * Referenced by: '<S14>/ pathNumber'
                                        */
  real_T pathNumber_P5;                /* Expression: stype
                                        * Referenced by: '<S14>/ pathNumber'
                                        */
  real_T pathNumber_P6;                /* Expression: btype
                                        * Referenced by: '<S14>/ pathNumber'
                                        */
  real_T U_ref_P1;                     /* Expression: width
                                        * Referenced by: '<S14>/ U_ref'
                                        */
  real_T U_ref_P2;                     /* Expression: dtype
                                        * Referenced by: '<S14>/ U_ref'
                                        */
  real_T U_ref_P3;                     /* Expression: portnum
                                        * Referenced by: '<S14>/ U_ref'
                                        */
  real_T U_ref_P4;                     /* Expression: stime
                                        * Referenced by: '<S14>/ U_ref'
                                        */
  real_T U_ref_P5;                     /* Expression: stype
                                        * Referenced by: '<S14>/ U_ref'
                                        */
  real_T U_ref_P6;                     /* Expression: btype
                                        * Referenced by: '<S14>/ U_ref'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 0.05
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T IC_Value[3];                  /* Expression: [0;0;0]
                                        * Referenced by: '<S15>/IC'
                                        */
  real_T IC1_Value[3];                 /* Expression: [0.00001;0.00001;0.00001]
                                        * Referenced by: '<S15>/IC1'
                                        */
  real_T my_P1;                        /* Expression: width
                                        * Referenced by: '<S18>/my'
                                        */
  real_T my_P2;                        /* Expression: dtype
                                        * Referenced by: '<S18>/my'
                                        */
  real_T my_P3;                        /* Expression: portnum
                                        * Referenced by: '<S18>/my'
                                        */
  real_T my_P4;                        /* Expression: stime
                                        * Referenced by: '<S18>/my'
                                        */
  real_T my_P5;                        /* Expression: stype
                                        * Referenced by: '<S18>/my'
                                        */
  real_T my_P6;                        /* Expression: btype
                                        * Referenced by: '<S18>/my'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 0.001
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Memory_X0_b;                  /* Expression: 0.0000001
                                        * Referenced by: '<S18>/Memory'
                                        */
  real_T IC3_Value;                    /* Expression: 0.0000001
                                        * Referenced by: '<S15>/IC3'
                                        */
  real_T IC2_Value[3];                 /* Expression: [0.0000001;0.0000001;0.0000001]
                                        * Referenced by: '<S15>/IC2'
                                        */
  real_T Constant_Value[9];            /* Expression: [0.2 0 0;0 0.2 0;0 0 0.1]
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T K_p2_1_P1;                    /* Expression: width
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  real_T K_p2_1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  real_T K_p2_1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  real_T K_p2_1_P4;                    /* Expression: stime
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  real_T K_p2_1_P5;                    /* Expression: stype
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  real_T K_p2_1_P6;                    /* Expression: btype
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  real_T K_p2_2_P1;                    /* Expression: width
                                        * Referenced by: '<S2>/K_p2_2'
                                        */
  real_T K_p2_2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S2>/K_p2_2'
                                        */
  real_T K_p2_2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S2>/K_p2_2'
                                        */
  real_T K_p2_2_P4;                    /* Expression: stime
                                        * Referenced by: '<S2>/K_p2_2'
                                        */
  real_T K_p2_2_P5;                    /* Expression: stype
                                        * Referenced by: '<S2>/K_p2_2'
                                        */
  real_T K_p2_2_P6;                    /* Expression: btype
                                        * Referenced by: '<S2>/K_p2_2'
                                        */
  real_T K_p2_3_P1;                    /* Expression: width
                                        * Referenced by: '<S2>/K_p2_3'
                                        */
  real_T K_p2_3_P2;                    /* Expression: dtype
                                        * Referenced by: '<S2>/K_p2_3'
                                        */
  real_T K_p2_3_P3;                    /* Expression: portnum
                                        * Referenced by: '<S2>/K_p2_3'
                                        */
  real_T K_p2_3_P4;                    /* Expression: stime
                                        * Referenced by: '<S2>/K_p2_3'
                                        */
  real_T K_p2_3_P5;                    /* Expression: stype
                                        * Referenced by: '<S2>/K_p2_3'
                                        */
  real_T K_p2_3_P6;                    /* Expression: btype
                                        * Referenced by: '<S2>/K_p2_3'
                                        */
  real_T Integrator1_IC_m[3];          /* Expression: [0;0;0]
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  real_T Integrator_IC_a;              /* Expression: 0
                                        * Referenced by: '<S30>/Integrator'
                                        */
  real_T Constant_Value_m[3];          /* Expression: [0; 0; 0]
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Saturation_UpperSat[3];       /* Expression: [2 2 2]'
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat[3];       /* Expression: [-2 -2 -2]'
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T N_d_P1;                       /* Expression: width
                                        * Referenced by: '<S10>/N_d'
                                        */
  real_T N_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S10>/N_d'
                                        */
  real_T N_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S10>/N_d'
                                        */
  real_T N_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S10>/N_d'
                                        */
  real_T N_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S10>/N_d'
                                        */
  real_T N_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S10>/N_d'
                                        */
  real_T X_d_P1;                       /* Expression: width
                                        * Referenced by: '<S10>/X_d'
                                        */
  real_T X_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S10>/X_d'
                                        */
  real_T X_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S10>/X_d'
                                        */
  real_T X_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S10>/X_d'
                                        */
  real_T X_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S10>/X_d'
                                        */
  real_T X_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S10>/X_d'
                                        */
  real_T Y_d_P1;                       /* Expression: width
                                        * Referenced by: '<S10>/Y_d'
                                        */
  real_T Y_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  real_T Y_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S10>/Y_d'
                                        */
  real_T Y_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S10>/Y_d'
                                        */
  real_T Y_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  real_T Y_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  real_T integratorresetmodel_P1;      /* Expression: width
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  real_T integratorresetmodel_P2;      /* Expression: dtype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  real_T integratorresetmodel_P3;      /* Expression: portnum
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  real_T integratorresetmodel_P4;      /* Expression: stime
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  real_T integratorresetmodel_P5;      /* Expression: stype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  real_T integratorresetmodel_P6;      /* Expression: btype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  real_T Constant2_Value_e;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T psi_0_P1;                     /* Expression: width
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  real_T psi_0_P2;                     /* Expression: dtype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  real_T psi_0_P3;                     /* Expression: portnum
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  real_T psi_0_P4;                     /* Expression: stime
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  real_T psi_0_P5;                     /* Expression: stype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  real_T psi_0_P6;                     /* Expression: btype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T x_0_P1;                       /* Expression: width
                                        * Referenced by: '<S10>/x_0'
                                        */
  real_T x_0_P2;                       /* Expression: dtype
                                        * Referenced by: '<S10>/x_0'
                                        */
  real_T x_0_P3;                       /* Expression: portnum
                                        * Referenced by: '<S10>/x_0'
                                        */
  real_T x_0_P4;                       /* Expression: stime
                                        * Referenced by: '<S10>/x_0'
                                        */
  real_T x_0_P5;                       /* Expression: stype
                                        * Referenced by: '<S10>/x_0'
                                        */
  real_T x_0_P6;                       /* Expression: btype
                                        * Referenced by: '<S10>/x_0'
                                        */
  real_T Constant1_Value_h;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T y_0_P1;                       /* Expression: width
                                        * Referenced by: '<S10>/y_0'
                                        */
  real_T y_0_P2;                       /* Expression: dtype
                                        * Referenced by: '<S10>/y_0'
                                        */
  real_T y_0_P3;                       /* Expression: portnum
                                        * Referenced by: '<S10>/y_0'
                                        */
  real_T y_0_P4;                       /* Expression: stime
                                        * Referenced by: '<S10>/y_0'
                                        */
  real_T y_0_P5;                       /* Expression: stype
                                        * Referenced by: '<S10>/y_0'
                                        */
  real_T y_0_P6;                       /* Expression: btype
                                        * Referenced by: '<S10>/y_0'
                                        */
  real_T tau_d_x_P1;                   /* Expression: width
                                        * Referenced by: '<S1>/tau_d_x'
                                        */
  real_T tau_d_x_P2;                   /* Expression: dtype
                                        * Referenced by: '<S1>/tau_d_x'
                                        */
  real_T tau_d_x_P3;                   /* Expression: portnum
                                        * Referenced by: '<S1>/tau_d_x'
                                        */
  real_T tau_d_x_P4;                   /* Expression: stime
                                        * Referenced by: '<S1>/tau_d_x'
                                        */
  real_T tau_d_x_P5;                   /* Expression: stype
                                        * Referenced by: '<S1>/tau_d_x'
                                        */
  real_T tau_d_x_P6;                   /* Expression: btype
                                        * Referenced by: '<S1>/tau_d_x'
                                        */
  real_T tau_d_psi_P1;                 /* Expression: width
                                        * Referenced by: '<S1>/tau_d_psi'
                                        */
  real_T tau_d_psi_P2;                 /* Expression: dtype
                                        * Referenced by: '<S1>/tau_d_psi'
                                        */
  real_T tau_d_psi_P3;                 /* Expression: portnum
                                        * Referenced by: '<S1>/tau_d_psi'
                                        */
  real_T tau_d_psi_P4;                 /* Expression: stime
                                        * Referenced by: '<S1>/tau_d_psi'
                                        */
  real_T tau_d_psi_P5;                 /* Expression: stype
                                        * Referenced by: '<S1>/tau_d_psi'
                                        */
  real_T tau_d_psi_P6;                 /* Expression: btype
                                        * Referenced by: '<S1>/tau_d_psi'
                                        */
  real_T tau_d_y_P1;                   /* Expression: width
                                        * Referenced by: '<S1>/tau_d_y'
                                        */
  real_T tau_d_y_P2;                   /* Expression: dtype
                                        * Referenced by: '<S1>/tau_d_y'
                                        */
  real_T tau_d_y_P3;                   /* Expression: portnum
                                        * Referenced by: '<S1>/tau_d_y'
                                        */
  real_T tau_d_y_P4;                   /* Expression: stime
                                        * Referenced by: '<S1>/tau_d_y'
                                        */
  real_T tau_d_y_P5;                   /* Expression: stype
                                        * Referenced by: '<S1>/tau_d_y'
                                        */
  real_T tau_d_y_P6;                   /* Expression: btype
                                        * Referenced by: '<S1>/tau_d_y'
                                        */
  real_T z1_psi_P1;                    /* Expression: width
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  real_T z1_psi_P2;                    /* Expression: dtype
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  real_T z1_psi_P3;                    /* Expression: portnum
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  real_T z1_psi_P4;                    /* Expression: stime
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  real_T z1_psi_P5;                    /* Expression: stype
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  real_T z1_psi_P6;                    /* Expression: btype
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  real_T z1_x_P1;                      /* Expression: width
                                        * Referenced by: '<S1>/z1_x'
                                        */
  real_T z1_x_P2;                      /* Expression: dtype
                                        * Referenced by: '<S1>/z1_x'
                                        */
  real_T z1_x_P3;                      /* Expression: portnum
                                        * Referenced by: '<S1>/z1_x'
                                        */
  real_T z1_x_P4;                      /* Expression: stime
                                        * Referenced by: '<S1>/z1_x'
                                        */
  real_T z1_x_P5;                      /* Expression: stype
                                        * Referenced by: '<S1>/z1_x'
                                        */
  real_T z1_x_P6;                      /* Expression: btype
                                        * Referenced by: '<S1>/z1_x'
                                        */
  real_T z1_y_P1;                      /* Expression: width
                                        * Referenced by: '<S1>/z1_y'
                                        */
  real_T z1_y_P2;                      /* Expression: dtype
                                        * Referenced by: '<S1>/z1_y'
                                        */
  real_T z1_y_P3;                      /* Expression: portnum
                                        * Referenced by: '<S1>/z1_y'
                                        */
  real_T z1_y_P4;                      /* Expression: stime
                                        * Referenced by: '<S1>/z1_y'
                                        */
  real_T z1_y_P5;                      /* Expression: stype
                                        * Referenced by: '<S1>/z1_y'
                                        */
  real_T z1_y_P6;                      /* Expression: btype
                                        * Referenced by: '<S1>/z1_y'
                                        */
  real_T s_P1;                         /* Expression: width
                                        * Referenced by: '<S3>/s'
                                        */
  real_T s_P2;                         /* Expression: dtype
                                        * Referenced by: '<S3>/s'
                                        */
  real_T s_P3;                         /* Expression: portnum
                                        * Referenced by: '<S3>/s'
                                        */
  real_T s_P4;                         /* Expression: stime
                                        * Referenced by: '<S3>/s'
                                        */
  real_T s_P5;                         /* Expression: stype
                                        * Referenced by: '<S3>/s'
                                        */
  real_T s_P6;                         /* Expression: btype
                                        * Referenced by: '<S3>/s'
                                        */
  real_T s_dot_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/s_dot'
                                        */
  real_T s_dot_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/s_dot'
                                        */
  real_T s_dot_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/s_dot'
                                        */
  real_T s_dot_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/s_dot'
                                        */
  real_T s_dot_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/s_dot'
                                        */
  real_T s_dot_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/s_dot'
                                        */
  real_T bias_x_P1;                    /* Expression: width
                                        * Referenced by: '<S5>/bias_x'
                                        */
  real_T bias_x_P2;                    /* Expression: dtype
                                        * Referenced by: '<S5>/bias_x'
                                        */
  real_T bias_x_P3;                    /* Expression: portnum
                                        * Referenced by: '<S5>/bias_x'
                                        */
  real_T bias_x_P4;                    /* Expression: stime
                                        * Referenced by: '<S5>/bias_x'
                                        */
  real_T bias_x_P5;                    /* Expression: stype
                                        * Referenced by: '<S5>/bias_x'
                                        */
  real_T bias_x_P6;                    /* Expression: btype
                                        * Referenced by: '<S5>/bias_x'
                                        */
  real_T bias_y_P1;                    /* Expression: width
                                        * Referenced by: '<S5>/bias_y'
                                        */
  real_T bias_y_P2;                    /* Expression: dtype
                                        * Referenced by: '<S5>/bias_y'
                                        */
  real_T bias_y_P3;                    /* Expression: portnum
                                        * Referenced by: '<S5>/bias_y'
                                        */
  real_T bias_y_P4;                    /* Expression: stime
                                        * Referenced by: '<S5>/bias_y'
                                        */
  real_T bias_y_P5;                    /* Expression: stype
                                        * Referenced by: '<S5>/bias_y'
                                        */
  real_T bias_y_P6;                    /* Expression: btype
                                        * Referenced by: '<S5>/bias_y'
                                        */
  real_T bias_psi_P1;                  /* Expression: width
                                        * Referenced by: '<S5>/bias_psi'
                                        */
  real_T bias_psi_P2;                  /* Expression: dtype
                                        * Referenced by: '<S5>/bias_psi'
                                        */
  real_T bias_psi_P3;                  /* Expression: portnum
                                        * Referenced by: '<S5>/bias_psi'
                                        */
  real_T bias_psi_P4;                  /* Expression: stime
                                        * Referenced by: '<S5>/bias_psi'
                                        */
  real_T bias_psi_P5;                  /* Expression: stype
                                        * Referenced by: '<S5>/bias_psi'
                                        */
  real_T bias_psi_P6;                  /* Expression: btype
                                        * Referenced by: '<S5>/bias_psi'
                                        */
  real_T nu_x_hat_P1;                  /* Expression: width
                                        * Referenced by: '<S33>/ nu_x_hat'
                                        */
  real_T nu_x_hat_P2;                  /* Expression: dtype
                                        * Referenced by: '<S33>/ nu_x_hat'
                                        */
  real_T nu_x_hat_P3;                  /* Expression: portnum
                                        * Referenced by: '<S33>/ nu_x_hat'
                                        */
  real_T nu_x_hat_P4;                  /* Expression: stime
                                        * Referenced by: '<S33>/ nu_x_hat'
                                        */
  real_T nu_x_hat_P5;                  /* Expression: stype
                                        * Referenced by: '<S33>/ nu_x_hat'
                                        */
  real_T nu_x_hat_P6;                  /* Expression: btype
                                        * Referenced by: '<S33>/ nu_x_hat'
                                        */
  real_T nu_y_hat_P1;                  /* Expression: width
                                        * Referenced by: '<S33>/ nu_y_hat'
                                        */
  real_T nu_y_hat_P2;                  /* Expression: dtype
                                        * Referenced by: '<S33>/ nu_y_hat'
                                        */
  real_T nu_y_hat_P3;                  /* Expression: portnum
                                        * Referenced by: '<S33>/ nu_y_hat'
                                        */
  real_T nu_y_hat_P4;                  /* Expression: stime
                                        * Referenced by: '<S33>/ nu_y_hat'
                                        */
  real_T nu_y_hat_P5;                  /* Expression: stype
                                        * Referenced by: '<S33>/ nu_y_hat'
                                        */
  real_T nu_y_hat_P6;                  /* Expression: btype
                                        * Referenced by: '<S33>/ nu_y_hat'
                                        */
  real_T nu_psi_hat_P1;                /* Expression: width
                                        * Referenced by: '<S33>/nu_psi_hat'
                                        */
  real_T nu_psi_hat_P2;                /* Expression: dtype
                                        * Referenced by: '<S33>/nu_psi_hat'
                                        */
  real_T nu_psi_hat_P3;                /* Expression: portnum
                                        * Referenced by: '<S33>/nu_psi_hat'
                                        */
  real_T nu_psi_hat_P4;                /* Expression: stime
                                        * Referenced by: '<S33>/nu_psi_hat'
                                        */
  real_T nu_psi_hat_P5;                /* Expression: stype
                                        * Referenced by: '<S33>/nu_psi_hat'
                                        */
  real_T nu_psi_hat_P6;                /* Expression: btype
                                        * Referenced by: '<S33>/nu_psi_hat'
                                        */
  real_T L1_11_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/L1_11'
                                        */
  real_T L1_11_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/L1_11'
                                        */
  real_T L1_11_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/L1_11'
                                        */
  real_T L1_11_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/L1_11'
                                        */
  real_T L1_11_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/L1_11'
                                        */
  real_T L1_11_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/L1_11'
                                        */
  real_T L1_22_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/L1_22'
                                        */
  real_T L1_22_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/L1_22'
                                        */
  real_T L1_22_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/L1_22'
                                        */
  real_T L1_22_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/L1_22'
                                        */
  real_T L1_22_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/L1_22'
                                        */
  real_T L1_22_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/L1_22'
                                        */
  real_T L1_33_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/L1_33'
                                        */
  real_T L1_33_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/L1_33'
                                        */
  real_T L1_33_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/L1_33'
                                        */
  real_T L1_33_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/L1_33'
                                        */
  real_T L1_33_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/L1_33'
                                        */
  real_T L1_33_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/L1_33'
                                        */
  real_T L2_11_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/L2_11'
                                        */
  real_T L2_11_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/L2_11'
                                        */
  real_T L2_11_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/L2_11'
                                        */
  real_T L2_11_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/L2_11'
                                        */
  real_T L2_11_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/L2_11'
                                        */
  real_T L2_11_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/L2_11'
                                        */
  real_T L2_22_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/L2_22'
                                        */
  real_T L2_22_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/L2_22'
                                        */
  real_T L2_22_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/L2_22'
                                        */
  real_T L2_22_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/L2_22'
                                        */
  real_T L2_22_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/L2_22'
                                        */
  real_T L2_22_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/L2_22'
                                        */
  real_T L2_33_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/L2_33'
                                        */
  real_T L2_33_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/L2_33'
                                        */
  real_T L2_33_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/L2_33'
                                        */
  real_T L2_33_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/L2_33'
                                        */
  real_T L2_33_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/L2_33'
                                        */
  real_T L2_33_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/L2_33'
                                        */
  real_T L3_11_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/L3_11'
                                        */
  real_T L3_11_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/L3_11'
                                        */
  real_T L3_11_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/L3_11'
                                        */
  real_T L3_11_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/L3_11'
                                        */
  real_T L3_11_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/L3_11'
                                        */
  real_T L3_11_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/L3_11'
                                        */
  real_T L3_22_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/L3_22'
                                        */
  real_T L3_22_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/L3_22'
                                        */
  real_T L3_22_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/L3_22'
                                        */
  real_T L3_22_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/L3_22'
                                        */
  real_T L3_22_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/L3_22'
                                        */
  real_T L3_22_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/L3_22'
                                        */
  real_T L3_33_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/L3_33'
                                        */
  real_T L3_33_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/L3_33'
                                        */
  real_T L3_33_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/L3_33'
                                        */
  real_T L3_33_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/L3_33'
                                        */
  real_T L3_33_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/L3_33'
                                        */
  real_T L3_33_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/L3_33'
                                        */
  real_T eta_mpsi_P1;                  /* Expression: width
                                        * Referenced by: '<S7>/eta_mpsi'
                                        */
  real_T eta_mpsi_P2;                  /* Expression: dtype
                                        * Referenced by: '<S7>/eta_mpsi'
                                        */
  real_T eta_mpsi_P3;                  /* Expression: portnum
                                        * Referenced by: '<S7>/eta_mpsi'
                                        */
  real_T eta_mpsi_P4;                  /* Expression: stime
                                        * Referenced by: '<S7>/eta_mpsi'
                                        */
  real_T eta_mpsi_P5;                  /* Expression: stype
                                        * Referenced by: '<S7>/eta_mpsi'
                                        */
  real_T eta_mpsi_P6;                  /* Expression: btype
                                        * Referenced by: '<S7>/eta_mpsi'
                                        */
  real_T eta_mx_P1;                    /* Expression: width
                                        * Referenced by: '<S7>/eta_mx'
                                        */
  real_T eta_mx_P2;                    /* Expression: dtype
                                        * Referenced by: '<S7>/eta_mx'
                                        */
  real_T eta_mx_P3;                    /* Expression: portnum
                                        * Referenced by: '<S7>/eta_mx'
                                        */
  real_T eta_mx_P4;                    /* Expression: stime
                                        * Referenced by: '<S7>/eta_mx'
                                        */
  real_T eta_mx_P5;                    /* Expression: stype
                                        * Referenced by: '<S7>/eta_mx'
                                        */
  real_T eta_mx_P6;                    /* Expression: btype
                                        * Referenced by: '<S7>/eta_mx'
                                        */
  real_T eta_my_P1;                    /* Expression: width
                                        * Referenced by: '<S7>/eta_my'
                                        */
  real_T eta_my_P2;                    /* Expression: dtype
                                        * Referenced by: '<S7>/eta_my'
                                        */
  real_T eta_my_P3;                    /* Expression: portnum
                                        * Referenced by: '<S7>/eta_my'
                                        */
  real_T eta_my_P4;                    /* Expression: stime
                                        * Referenced by: '<S7>/eta_my'
                                        */
  real_T eta_my_P5;                    /* Expression: stype
                                        * Referenced by: '<S7>/eta_my'
                                        */
  real_T eta_my_P6;                    /* Expression: btype
                                        * Referenced by: '<S7>/eta_my'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  uint8_T ManualSwitch_CurrentSetting_f;/* Computed Parameter: ManualSwitch_CurrentSetting_f
                                         * Referenced by: '<S1>/Manual Switch'
                                         */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_student_HIL_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[13];
    real_T odeF[3][13];
    ODE3_IntgData intgData;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_ctrl_student_HIL_T ctrl_student_HIL_P;

/* Block signals (auto storage) */
extern B_ctrl_student_HIL_T ctrl_student_HIL_B;

/* Continuous states (auto storage) */
extern X_ctrl_student_HIL_T ctrl_student_HIL_X;

/* Block states (auto storage) */
extern DW_ctrl_student_HIL_T ctrl_student_HIL_DW;

/* Model entry point functions */
extern void ctrl_student_HIL_initialize(void);
extern void ctrl_student_HIL_output(void);
extern void ctrl_student_HIL_update(void);
extern void ctrl_student_HIL_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ctrl_student_HIL_rtModel *ctrl_student_HIL(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_student_HIL_T *const ctrl_student_HIL_M;

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
 * '<Root>' : 'ctrl_student_HIL'
 * '<S1>'   : 'ctrl_student_HIL/Controller'
 * '<S2>'   : 'ctrl_student_HIL/Gain Matrices'
 * '<S3>'   : 'ctrl_student_HIL/Guidance'
 * '<S4>'   : 'ctrl_student_HIL/Noise generator'
 * '<S5>'   : 'ctrl_student_HIL/Observer'
 * '<S6>'   : 'ctrl_student_HIL/Op_space control'
 * '<S7>'   : 'ctrl_student_HIL/Signal Drop-out'
 * '<S8>'   : 'ctrl_student_HIL/eta_d to veristand'
 * '<S9>'   : 'ctrl_student_HIL/joystick'
 * '<S10>'  : 'ctrl_student_HIL/tau to CSE mocell (only use for HIL testing)'
 * '<S11>'  : 'ctrl_student_HIL/Controller/MATLAB Function'
 * '<S12>'  : 'ctrl_student_HIL/Gain Matrices/Controller gain matrix k_p2'
 * '<S13>'  : 'ctrl_student_HIL/Gain Matrices/MATLAB Function'
 * '<S14>'  : 'ctrl_student_HIL/Guidance/Control inputs'
 * '<S15>'  : 'ctrl_student_HIL/Guidance/Path generation'
 * '<S16>'  : 'ctrl_student_HIL/Guidance/Rotation matrix'
 * '<S17>'  : 'ctrl_student_HIL/Guidance/XY pos'
 * '<S18>'  : 'ctrl_student_HIL/Guidance/s_dot generation'
 * '<S19>'  : 'ctrl_student_HIL/Guidance/Path generation/Ellipsoid'
 * '<S20>'  : 'ctrl_student_HIL/Guidance/Path generation/straight line'
 * '<S21>'  : 'ctrl_student_HIL/Guidance/s_dot generation/s calculation'
 * '<S22>'  : 'ctrl_student_HIL/Noise generator/Downsample	signal'
 * '<S23>'  : 'ctrl_student_HIL/Noise generator/Sample & hold'
 * '<S24>'  : 'ctrl_student_HIL/Noise generator/noise generator'
 * '<S25>'  : 'ctrl_student_HIL/Noise generator/Downsample	signal/MATLAB Function'
 * '<S26>'  : 'ctrl_student_HIL/Noise generator/Sample & hold/MATLAB Function1'
 * '<S27>'  : 'ctrl_student_HIL/Noise generator/noise generator/Band-limited white noise psi'
 * '<S28>'  : 'ctrl_student_HIL/Noise generator/noise generator/Band-limited white noise x'
 * '<S29>'  : 'ctrl_student_HIL/Noise generator/noise generator/Band-limited white noise y'
 * '<S30>'  : 'ctrl_student_HIL/Observer/Bias estimator'
 * '<S31>'  : 'ctrl_student_HIL/Observer/MATLAB Function'
 * '<S32>'  : 'ctrl_student_HIL/Observer/kinematics'
 * '<S33>'  : 'ctrl_student_HIL/Observer/nu_hat_out'
 * '<S34>'  : 'ctrl_student_HIL/Observer/kinematics/MATLAB Function1'
 * '<S35>'  : 'ctrl_student_HIL/Op_space control/op_space'
 * '<S36>'  : 'ctrl_student_HIL/Signal Drop-out/Detection'
 * '<S37>'  : 'ctrl_student_HIL/Signal Drop-out/Signal drop-out simulation'
 * '<S38>'  : 'ctrl_student_HIL/Signal Drop-out/Detection/MATLAB Function'
 * '<S39>'  : 'ctrl_student_HIL/joystick/Contoller_Map'
 * '<S40>'  : 'ctrl_student_HIL/joystick/Force Allocation'
 * '<S41>'  : 'ctrl_student_HIL/joystick/Force2Control'
 * '<S42>'  : 'ctrl_student_HIL/joystick/Ramp'
 * '<S43>'  : 'ctrl_student_HIL/joystick/Sat_Chk_BT'
 * '<S44>'  : 'ctrl_student_HIL/joystick/Sat_Chk_VSP'
 * '<S45>'  : 'ctrl_student_HIL/joystick/Subsystem'
 * '<S46>'  : 'ctrl_student_HIL/joystick/Subsystem/Sel_Control_Mode'
 */
#endif                                 /* RTW_HEADER_ctrl_student_HIL_h_ */

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#define NI_SIT_PARAMS
#ifdef NI_ROOTMODEL_ctrl_student_HIL
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

P_ctrl_student_HIL_T rtParameter[NUMST+!TID01EQ];
P_ctrl_student_HIL_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

P_ctrl_student_HIL_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

extern int tid;
extern P_ctrl_student_HIL_T* param_lookup[NUMST][2];

#else

extern P_ctrl_student_HIL_T rtParameter[];

#endif
#endif

#ifdef MULTITASKING
#define ctrl_student_HIL_P             (*param_lookup[tid][READSIDE])
#else
#define ctrl_student_HIL_P             rtParameter[READSIDE]
#endif
#endif
#endif
