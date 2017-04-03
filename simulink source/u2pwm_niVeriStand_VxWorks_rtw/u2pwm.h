/*
 * u2pwm.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "u2pwm".
 *
 * Model version              : 1.26
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Apr 03 10:08:10 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_u2pwm_h_
#define RTW_HEADER_u2pwm_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef u2pwm_COMMON_INCLUDES_
# define u2pwm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* u2pwm_COMMON_INCLUDES_ */

#include "u2pwm_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

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
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
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
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
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
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
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
#define u2pwm_rtModel                  RT_MODEL_u2pwm_T

/* Block signals (auto storage) */
typedef struct {
  real_T BT_min_pwm;                   /* '<Root>/BT_min_pwm' */
  real_T BT_max_pwm;                   /* '<Root>/BT_max_pwm' */
  real_T pwm_BT;                       /* '<S1>/pwm_BT' */
  real_T pwm_VSP1;                     /* '<S1>/pwm_VSP1' */
  real_T pwm_VSP2;                     /* '<S1>/pwm_VSP2' */
  real_T pwm_servo1;                   /* '<S1>/pwm_servo1' */
  real_T pwm_servo2;                   /* '<S1>/pwm_servo2' */
  real_T pwm_servo3;                   /* '<S1>/pwm_servo3' */
  real_T pwm_servo4;                   /* '<S1>/pwm_servo4' */
  real_T manualoverride;               /* '<Root>/manual override' */
  real_T alpha_VSP1;                   /* '<S3>/alpha_VSP1' */
  real_T u_VSP1;                       /* '<S3>/u_VSP1' */
  real_T alpha_VSP2;                   /* '<S3>/alpha_VSP2' */
  real_T u_VSP2;                       /* '<S3>/u_VSP2' */
  real_T u_BT;                         /* '<S3>/u_BT' */
  real_T omega_VSP1;                   /* '<S3>/omega_VSP1' */
  real_T omega_VSP2;                   /* '<S3>/omega_VSP2' */
  real_T Switch[7];                    /* '<Root>/Switch' */
} B_u2pwm_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T BT_min_pwm_DWORK1;            /* '<Root>/BT_min_pwm' */
  real_T BT_max_pwm_DWORK1;            /* '<Root>/BT_max_pwm' */
  real_T pwm_BT_DWORK1;                /* '<S1>/pwm_BT' */
  real_T pwm_VSP1_DWORK1;              /* '<S1>/pwm_VSP1' */
  real_T pwm_VSP2_DWORK1;              /* '<S1>/pwm_VSP2' */
  real_T pwm_servo1_DWORK1;            /* '<S1>/pwm_servo1' */
  real_T pwm_servo2_DWORK1;            /* '<S1>/pwm_servo2' */
  real_T pwm_servo3_DWORK1;            /* '<S1>/pwm_servo3' */
  real_T pwm_servo4_DWORK1;            /* '<S1>/pwm_servo4' */
  real_T manualoverride_DWORK1;        /* '<Root>/manual override' */
  real_T alpha_VSP1_DWORK1;            /* '<S3>/alpha_VSP1' */
  real_T u_VSP1_DWORK1;                /* '<S3>/u_VSP1' */
  real_T alpha_VSP2_DWORK1;            /* '<S3>/alpha_VSP2' */
  real_T u_VSP2_DWORK1;                /* '<S3>/u_VSP2' */
  real_T u_BT_DWORK1;                  /* '<S3>/u_BT' */
  real_T omega_VSP1_DWORK1;            /* '<S3>/omega_VSP1' */
  real_T omega_VSP2_DWORK1;            /* '<S3>/omega_VSP2' */
  real_T pwm_VSP1_DWORK1_g;            /* '<S2>/pwm_VSP1' */
  real_T pwm_VSP2_DWORK1_f;            /* '<S2>/pwm_VSP2' */
  real_T pwm_BT_DWORK1_i;              /* '<S2>/pwm_BT' */
  real_T pwm_servo4_DWORK1_p;          /* '<S2>/pwm_servo4' */
  real_T pwm_servo3_DWORK1_a;          /* '<S2>/pwm_servo3' */
  real_T pwm_servo1_DWORK1_f;          /* '<S2>/pwm_servo1' */
  real_T pwm_servo2_DWORK1_h;          /* '<S2>/pwm_servo2' */
  int32_T NIVeriStandSignalProbe_DWORK2;/* '<Root>/NIVeriStandSignalProbe' */
  uint8_T BT_min_pwm_DWORK2[6];        /* '<Root>/BT_min_pwm' */
  uint8_T BT_max_pwm_DWORK2[6];        /* '<Root>/BT_max_pwm' */
  uint8_T pwm_BT_DWORK2[6];            /* '<S1>/pwm_BT' */
  uint8_T pwm_VSP1_DWORK2[6];          /* '<S1>/pwm_VSP1' */
  uint8_T pwm_VSP2_DWORK2[6];          /* '<S1>/pwm_VSP2' */
  uint8_T pwm_servo1_DWORK2[6];        /* '<S1>/pwm_servo1' */
  uint8_T pwm_servo2_DWORK2[6];        /* '<S1>/pwm_servo2' */
  uint8_T pwm_servo3_DWORK2[6];        /* '<S1>/pwm_servo3' */
  uint8_T pwm_servo4_DWORK2[6];        /* '<S1>/pwm_servo4' */
  uint8_T manualoverride_DWORK2[6];    /* '<Root>/manual override' */
  uint8_T alpha_VSP1_DWORK2[6];        /* '<S3>/alpha_VSP1' */
  uint8_T u_VSP1_DWORK2[6];            /* '<S3>/u_VSP1' */
  uint8_T alpha_VSP2_DWORK2[6];        /* '<S3>/alpha_VSP2' */
  uint8_T u_VSP2_DWORK2[6];            /* '<S3>/u_VSP2' */
  uint8_T u_BT_DWORK2[6];              /* '<S3>/u_BT' */
  uint8_T omega_VSP1_DWORK2[6];        /* '<S3>/omega_VSP1' */
  uint8_T omega_VSP2_DWORK2[6];        /* '<S3>/omega_VSP2' */
  uint8_T pwm_VSP1_DWORK2_k[6];        /* '<S2>/pwm_VSP1' */
  uint8_T pwm_VSP2_DWORK2_c[6];        /* '<S2>/pwm_VSP2' */
  uint8_T pwm_BT_DWORK2_n[6];          /* '<S2>/pwm_BT' */
  uint8_T pwm_servo4_DWORK2_c[6];      /* '<S2>/pwm_servo4' */
  uint8_T pwm_servo3_DWORK2_n[6];      /* '<S2>/pwm_servo3' */
  uint8_T pwm_servo1_DWORK2_h[6];      /* '<S2>/pwm_servo1' */
  uint8_T pwm_servo2_DWORK2_e[6];      /* '<S2>/pwm_servo2' */
  uint8_T NIVeriStandSignalProbe_DWORK1[6];/* '<Root>/NIVeriStandSignalProbe' */
  uint8_T NIVeriStandSignalProbe_DWORK3[49];/* '<Root>/NIVeriStandSignalProbe' */
} DW_u2pwm_T;

/* Backward compatible GRT Identifiers */
#define rtB                            u2pwm_B
#define BlockIO                        B_u2pwm_T
#define rtP                            u2pwm_P
#define Parameters                     P_u2pwm_T
#define rtDWork                        u2pwm_DW
#define D_Work                         DW_u2pwm_T

/* Parameters (auto storage) */
struct P_u2pwm_T_ {
  real_T VSP_u2pwm_gain;               /* Variable: VSP_u2pwm_gain
                                        * Referenced by:
                                        *   '<Root>/VPS_Speed_Gain'
                                        *   '<Root>/VPS_Speed_Gain2'
                                        */
  real_T VSP_zero_pwm;                 /* Variable: VSP_zero_pwm
                                        * Referenced by: '<Root>/VPS_Power_Offset'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain5_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -1
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T Constant_Value;               /* Expression: pi/2
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 1
                                        * Referenced by: '<Root>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -1
                                        * Referenced by: '<Root>/Saturation4'
                                        */
  real_T Gain4_Gain;                   /* Expression: .88
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T DLookupTable_tableData[25];   /* Expression: servo_mapping(:,:,1)
                                        * Referenced by: '<Root>/2-D Lookup Table'
                                        */
  real_T DLookupTable_bp01Data[5];     /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<Root>/2-D Lookup Table'
                                        */
  real_T DLookupTable_bp02Data[5];     /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<Root>/2-D Lookup Table'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T DLookupTable1_tableData[25];  /* Expression: servo_mapping(:,:,2)
                                        * Referenced by: '<Root>/2-D Lookup Table1'
                                        */
  real_T DLookupTable1_bp01Data[5];    /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<Root>/2-D Lookup Table1'
                                        */
  real_T DLookupTable1_bp02Data[5];    /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<Root>/2-D Lookup Table1'
                                        */
  real_T Constant1_Value;              /* Expression: pi/2
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<Root>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -1
                                        * Referenced by: '<Root>/Saturation3'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T DLookupTable2_tableData[25];  /* Expression: servo_mapping(:,:,3)
                                        * Referenced by: '<Root>/2-D Lookup Table2'
                                        */
  real_T DLookupTable2_bp01Data[5];    /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<Root>/2-D Lookup Table2'
                                        */
  real_T DLookupTable2_bp02Data[5];    /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<Root>/2-D Lookup Table2'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T DLookupTable3_tableData[25];  /* Expression: servo_mapping(:,:,4)
                                        * Referenced by: '<Root>/2-D Lookup Table3'
                                        */
  real_T DLookupTable3_bp01Data[5];    /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<Root>/2-D Lookup Table3'
                                        */
  real_T DLookupTable3_bp02Data[5];    /* Expression: [-1,-0.7071067811865476,0,0.7071067811865476,1]
                                        * Referenced by: '<Root>/2-D Lookup Table3'
                                        */
  real_T BT_min_pwm_P1;                /* Expression: width
                                        * Referenced by: '<Root>/BT_min_pwm'
                                        */
  real_T BT_min_pwm_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/BT_min_pwm'
                                        */
  real_T BT_min_pwm_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/BT_min_pwm'
                                        */
  real_T BT_min_pwm_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/BT_min_pwm'
                                        */
  real_T BT_min_pwm_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/BT_min_pwm'
                                        */
  real_T BT_min_pwm_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/BT_min_pwm'
                                        */
  real_T BT_max_pwm_P1;                /* Expression: width
                                        * Referenced by: '<Root>/BT_max_pwm'
                                        */
  real_T BT_max_pwm_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/BT_max_pwm'
                                        */
  real_T BT_max_pwm_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/BT_max_pwm'
                                        */
  real_T BT_max_pwm_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/BT_max_pwm'
                                        */
  real_T BT_max_pwm_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/BT_max_pwm'
                                        */
  real_T BT_max_pwm_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/BT_max_pwm'
                                        */
  real_T pwm_BT_P1;                    /* Expression: width
                                        * Referenced by: '<S1>/pwm_BT'
                                        */
  real_T pwm_BT_P2;                    /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_BT'
                                        */
  real_T pwm_BT_P3;                    /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_BT'
                                        */
  real_T pwm_BT_P4;                    /* Expression: stime
                                        * Referenced by: '<S1>/pwm_BT'
                                        */
  real_T pwm_BT_P5;                    /* Expression: stype
                                        * Referenced by: '<S1>/pwm_BT'
                                        */
  real_T pwm_BT_P6;                    /* Expression: btype
                                        * Referenced by: '<S1>/pwm_BT'
                                        */
  real_T pwm_VSP1_P1;                  /* Expression: width
                                        * Referenced by: '<S1>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P2;                  /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P3;                  /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P4;                  /* Expression: stime
                                        * Referenced by: '<S1>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P5;                  /* Expression: stype
                                        * Referenced by: '<S1>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P6;                  /* Expression: btype
                                        * Referenced by: '<S1>/pwm_VSP1'
                                        */
  real_T pwm_VSP2_P1;                  /* Expression: width
                                        * Referenced by: '<S1>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P2;                  /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P3;                  /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P4;                  /* Expression: stime
                                        * Referenced by: '<S1>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P5;                  /* Expression: stype
                                        * Referenced by: '<S1>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P6;                  /* Expression: btype
                                        * Referenced by: '<S1>/pwm_VSP2'
                                        */
  real_T pwm_servo1_P1;                /* Expression: width
                                        * Referenced by: '<S1>/pwm_servo1'
                                        */
  real_T pwm_servo1_P2;                /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_servo1'
                                        */
  real_T pwm_servo1_P3;                /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_servo1'
                                        */
  real_T pwm_servo1_P4;                /* Expression: stime
                                        * Referenced by: '<S1>/pwm_servo1'
                                        */
  real_T pwm_servo1_P5;                /* Expression: stype
                                        * Referenced by: '<S1>/pwm_servo1'
                                        */
  real_T pwm_servo1_P6;                /* Expression: btype
                                        * Referenced by: '<S1>/pwm_servo1'
                                        */
  real_T pwm_servo2_P1;                /* Expression: width
                                        * Referenced by: '<S1>/pwm_servo2'
                                        */
  real_T pwm_servo2_P2;                /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_servo2'
                                        */
  real_T pwm_servo2_P3;                /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_servo2'
                                        */
  real_T pwm_servo2_P4;                /* Expression: stime
                                        * Referenced by: '<S1>/pwm_servo2'
                                        */
  real_T pwm_servo2_P5;                /* Expression: stype
                                        * Referenced by: '<S1>/pwm_servo2'
                                        */
  real_T pwm_servo2_P6;                /* Expression: btype
                                        * Referenced by: '<S1>/pwm_servo2'
                                        */
  real_T pwm_servo3_P1;                /* Expression: width
                                        * Referenced by: '<S1>/pwm_servo3'
                                        */
  real_T pwm_servo3_P2;                /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_servo3'
                                        */
  real_T pwm_servo3_P3;                /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_servo3'
                                        */
  real_T pwm_servo3_P4;                /* Expression: stime
                                        * Referenced by: '<S1>/pwm_servo3'
                                        */
  real_T pwm_servo3_P5;                /* Expression: stype
                                        * Referenced by: '<S1>/pwm_servo3'
                                        */
  real_T pwm_servo3_P6;                /* Expression: btype
                                        * Referenced by: '<S1>/pwm_servo3'
                                        */
  real_T pwm_servo4_P1;                /* Expression: width
                                        * Referenced by: '<S1>/pwm_servo4'
                                        */
  real_T pwm_servo4_P2;                /* Expression: dtype
                                        * Referenced by: '<S1>/pwm_servo4'
                                        */
  real_T pwm_servo4_P3;                /* Expression: portnum
                                        * Referenced by: '<S1>/pwm_servo4'
                                        */
  real_T pwm_servo4_P4;                /* Expression: stime
                                        * Referenced by: '<S1>/pwm_servo4'
                                        */
  real_T pwm_servo4_P5;                /* Expression: stype
                                        * Referenced by: '<S1>/pwm_servo4'
                                        */
  real_T pwm_servo4_P6;                /* Expression: btype
                                        * Referenced by: '<S1>/pwm_servo4'
                                        */
  real_T manualoverride_P1;            /* Expression: width
                                        * Referenced by: '<Root>/manual override'
                                        */
  real_T manualoverride_P2;            /* Expression: dtype
                                        * Referenced by: '<Root>/manual override'
                                        */
  real_T manualoverride_P3;            /* Expression: portnum
                                        * Referenced by: '<Root>/manual override'
                                        */
  real_T manualoverride_P4;            /* Expression: stime
                                        * Referenced by: '<Root>/manual override'
                                        */
  real_T manualoverride_P5;            /* Expression: stype
                                        * Referenced by: '<Root>/manual override'
                                        */
  real_T manualoverride_P6;            /* Expression: btype
                                        * Referenced by: '<Root>/manual override'
                                        */
  real_T alpha_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  real_T alpha_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S3>/alpha_VSP1'
                                        */
  real_T u_VSP1_P1;                    /* Expression: width
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  real_T u_VSP1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  real_T u_VSP1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  real_T u_VSP1_P4;                    /* Expression: stime
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  real_T u_VSP1_P5;                    /* Expression: stype
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  real_T u_VSP1_P6;                    /* Expression: btype
                                        * Referenced by: '<S3>/u_VSP1'
                                        */
  real_T alpha_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  real_T alpha_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S3>/alpha_VSP2'
                                        */
  real_T u_VSP2_P1;                    /* Expression: width
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  real_T u_VSP2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  real_T u_VSP2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  real_T u_VSP2_P4;                    /* Expression: stime
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  real_T u_VSP2_P5;                    /* Expression: stype
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  real_T u_VSP2_P6;                    /* Expression: btype
                                        * Referenced by: '<S3>/u_VSP2'
                                        */
  real_T u_BT_P1;                      /* Expression: width
                                        * Referenced by: '<S3>/u_BT'
                                        */
  real_T u_BT_P2;                      /* Expression: dtype
                                        * Referenced by: '<S3>/u_BT'
                                        */
  real_T u_BT_P3;                      /* Expression: portnum
                                        * Referenced by: '<S3>/u_BT'
                                        */
  real_T u_BT_P4;                      /* Expression: stime
                                        * Referenced by: '<S3>/u_BT'
                                        */
  real_T u_BT_P5;                      /* Expression: stype
                                        * Referenced by: '<S3>/u_BT'
                                        */
  real_T u_BT_P6;                      /* Expression: btype
                                        * Referenced by: '<S3>/u_BT'
                                        */
  real_T omega_VSP1_P1;                /* Expression: width
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  real_T omega_VSP1_P2;                /* Expression: dtype
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  real_T omega_VSP1_P3;                /* Expression: portnum
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  real_T omega_VSP1_P4;                /* Expression: stime
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  real_T omega_VSP1_P5;                /* Expression: stype
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  real_T omega_VSP1_P6;                /* Expression: btype
                                        * Referenced by: '<S3>/omega_VSP1'
                                        */
  real_T omega_VSP2_P1;                /* Expression: width
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  real_T omega_VSP2_P2;                /* Expression: dtype
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  real_T omega_VSP2_P3;                /* Expression: portnum
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  real_T omega_VSP2_P4;                /* Expression: stime
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  real_T omega_VSP2_P5;                /* Expression: stype
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  real_T omega_VSP2_P6;                /* Expression: btype
                                        * Referenced by: '<S3>/omega_VSP2'
                                        */
  real_T pwm_VSP1_P1_j;                /* Expression: width
                                        * Referenced by: '<S2>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P2_e;                /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P3_a;                /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P4_p;                /* Expression: stime
                                        * Referenced by: '<S2>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P5_b;                /* Expression: stype
                                        * Referenced by: '<S2>/pwm_VSP1'
                                        */
  real_T pwm_VSP1_P6_o;                /* Expression: btype
                                        * Referenced by: '<S2>/pwm_VSP1'
                                        */
  real_T pwm_VSP2_P1_l;                /* Expression: width
                                        * Referenced by: '<S2>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P2_o;                /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P3_e;                /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P4_b;                /* Expression: stime
                                        * Referenced by: '<S2>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P5_n;                /* Expression: stype
                                        * Referenced by: '<S2>/pwm_VSP2'
                                        */
  real_T pwm_VSP2_P6_i;                /* Expression: btype
                                        * Referenced by: '<S2>/pwm_VSP2'
                                        */
  real_T pwm_BT_P1_a;                  /* Expression: width
                                        * Referenced by: '<S2>/pwm_BT'
                                        */
  real_T pwm_BT_P2_b;                  /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_BT'
                                        */
  real_T pwm_BT_P3_l;                  /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_BT'
                                        */
  real_T pwm_BT_P4_m;                  /* Expression: stime
                                        * Referenced by: '<S2>/pwm_BT'
                                        */
  real_T pwm_BT_P5_j;                  /* Expression: stype
                                        * Referenced by: '<S2>/pwm_BT'
                                        */
  real_T pwm_BT_P6_g;                  /* Expression: btype
                                        * Referenced by: '<S2>/pwm_BT'
                                        */
  real_T pwm_servo4_P1_p;              /* Expression: width
                                        * Referenced by: '<S2>/pwm_servo4'
                                        */
  real_T pwm_servo4_P2_b;              /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_servo4'
                                        */
  real_T pwm_servo4_P3_h;              /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_servo4'
                                        */
  real_T pwm_servo4_P4_n;              /* Expression: stime
                                        * Referenced by: '<S2>/pwm_servo4'
                                        */
  real_T pwm_servo4_P5_f;              /* Expression: stype
                                        * Referenced by: '<S2>/pwm_servo4'
                                        */
  real_T pwm_servo4_P6_a;              /* Expression: btype
                                        * Referenced by: '<S2>/pwm_servo4'
                                        */
  real_T pwm_servo3_P1_k;              /* Expression: width
                                        * Referenced by: '<S2>/pwm_servo3'
                                        */
  real_T pwm_servo3_P2_o;              /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_servo3'
                                        */
  real_T pwm_servo3_P3_o;              /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_servo3'
                                        */
  real_T pwm_servo3_P4_o;              /* Expression: stime
                                        * Referenced by: '<S2>/pwm_servo3'
                                        */
  real_T pwm_servo3_P5_a;              /* Expression: stype
                                        * Referenced by: '<S2>/pwm_servo3'
                                        */
  real_T pwm_servo3_P6_i;              /* Expression: btype
                                        * Referenced by: '<S2>/pwm_servo3'
                                        */
  real_T pwm_servo1_P1_l;              /* Expression: width
                                        * Referenced by: '<S2>/pwm_servo1'
                                        */
  real_T pwm_servo1_P2_n;              /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_servo1'
                                        */
  real_T pwm_servo1_P3_i;              /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_servo1'
                                        */
  real_T pwm_servo1_P4_j;              /* Expression: stime
                                        * Referenced by: '<S2>/pwm_servo1'
                                        */
  real_T pwm_servo1_P5_l;              /* Expression: stype
                                        * Referenced by: '<S2>/pwm_servo1'
                                        */
  real_T pwm_servo1_P6_f;              /* Expression: btype
                                        * Referenced by: '<S2>/pwm_servo1'
                                        */
  real_T pwm_servo2_P1_h;              /* Expression: width
                                        * Referenced by: '<S2>/pwm_servo2'
                                        */
  real_T pwm_servo2_P2_a;              /* Expression: dtype
                                        * Referenced by: '<S2>/pwm_servo2'
                                        */
  real_T pwm_servo2_P3_k;              /* Expression: portnum
                                        * Referenced by: '<S2>/pwm_servo2'
                                        */
  real_T pwm_servo2_P4_g;              /* Expression: stime
                                        * Referenced by: '<S2>/pwm_servo2'
                                        */
  real_T pwm_servo2_P5_g;              /* Expression: stype
                                        * Referenced by: '<S2>/pwm_servo2'
                                        */
  real_T pwm_servo2_P6_e;              /* Expression: btype
                                        * Referenced by: '<S2>/pwm_servo2'
                                        */
  real_T NIVeriStandSignalProbe_P1;    /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
  uint32_T DLookupTable_maxIndex[2];   /* Computed Parameter: DLookupTable_maxIndex
                                        * Referenced by: '<Root>/2-D Lookup Table'
                                        */
  uint32_T DLookupTable1_maxIndex[2];  /* Computed Parameter: DLookupTable1_maxIndex
                                        * Referenced by: '<Root>/2-D Lookup Table1'
                                        */
  uint32_T DLookupTable2_maxIndex[2];  /* Computed Parameter: DLookupTable2_maxIndex
                                        * Referenced by: '<Root>/2-D Lookup Table2'
                                        */
  uint32_T DLookupTable3_maxIndex[2];  /* Computed Parameter: DLookupTable3_maxIndex
                                        * Referenced by: '<Root>/2-D Lookup Table3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_u2pwm_T {
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
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_u2pwm_T u2pwm_P;

/* Block signals (auto storage) */
extern B_u2pwm_T u2pwm_B;

/* Block states (auto storage) */
extern DW_u2pwm_T u2pwm_DW;

/*====================*
 * External functions *
 *====================*/
extern u2pwm_rtModel *u2pwm(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_u2pwm_T *const u2pwm_M;

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
 * '<Root>' : 'u2pwm'
 * '<S1>'   : 'u2pwm/manual'
 * '<S2>'   : 'u2pwm/pwm'
 * '<S3>'   : 'u2pwm/u'
 */
#endif                                 /* RTW_HEADER_u2pwm_h_ */

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#define NI_SIT_PARAMS
#ifdef NI_ROOTMODEL_u2pwm
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

P_u2pwm_T rtParameter[NUMST+!TID01EQ];
P_u2pwm_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },
};

#else

P_u2pwm_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

extern int tid;
extern P_u2pwm_T* param_lookup[NUMST][2];

#else

extern P_u2pwm_T rtParameter[];

#endif
#endif

#ifdef MULTITASKING
#define u2pwm_P                        (*param_lookup[tid][READSIDE])
#else
#define u2pwm_P                        rtParameter[READSIDE]
#endif
#endif
#endif
