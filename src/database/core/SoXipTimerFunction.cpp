/*
  ------------------------------------------------------------------------

    SoXipTimerFunction.cpp

    A triggered timer function with linear, smoothstep and C2 smoothstep.

    Copyright (C) 2007 - 2008, Siemens Corporate Research, Inc.

    Authors:
      Patric Ljung, patric.ljung@siemens.com
      Stefan Wiesner, stefan.wiesner@siemens.com

    This file is part of Open XIP - an eXtensive Imaging Platform.

  ------------------------------------------------------------------------
*/

#include "SoXipTimerFunction.h"

#include <Inventor/fields/SoSFTime.h>
#include <Inventor/sensors/SoFieldSensor.h>
#include <Inventor/errors/SoDebugError.h>
#include <xip/utils/XipBasicOperators.h>

#include <xip/system/standard.h>

#ifdef XIP_BASIC_OPS_NAMESPACE
using namespace XipBasicOps;
#endif

SO_NODE_SOURCE(SoXipTimerFunction);

const float SoXipTimerFunction::cmTimeScale = 1000.0;

void SoXipTimerFunction::initClass()
{
    SO_NODE_INIT_CLASS(SoXipTimerFunction, SoNode, "Node");
}

SoXipTimerFunction::SoXipTimerFunction()
{
    SO_NODE_CONSTRUCTOR(SoXipTimerFunction);

    SO_NODE_DEFINE_ENUM_VALUE(FUNCTION_TYPES, C0);
    SO_NODE_DEFINE_ENUM_VALUE(FUNCTION_TYPES, C1);
    SO_NODE_DEFINE_ENUM_VALUE(FUNCTION_TYPES, C2);
    SO_NODE_SET_SF_ENUM_TYPE(function, FUNCTION_TYPES);
	SO_NODE_ADD_FIELD(function, (C1));

	SO_NODE_DEFINE_ENUM_VALUE(MODE_TYPES, ONCE);
	SO_NODE_DEFINE_ENUM_VALUE(MODE_TYPES, LOOP);
	SO_NODE_SET_SF_ENUM_TYPE(playMode, MODE_TYPES);
	SO_NODE_ADD_FIELD(playMode, (ONCE));
    

    SO_NODE_ADD_FIELD(duration, (1.0));
    
    SO_NODE_ADD_FIELD(syncIn, ());

    SO_NODE_ADD_FIELD(value, (1.0));
    SO_NODE_ADD_FIELD(counter, (0));
	
	SO_NODE_ADD_FIELD(start, ());
	SO_NODE_ADD_FIELD(pause, ());
	SO_NODE_ADD_FIELD(pauseOn, (FALSE));
	SO_NODE_ADD_FIELD(stop, ());



    //SoDB::setRealTimeInterval(SbTime(1.0/30.0));
    mRealTime = reinterpret_cast<SoSFTime *>(SoDB::getGlobalField("realTime"));
    syncIn.connectFrom(mRealTime);

    mStarted = false;
		
	SoField * fields[] = {
	&start,&pause,&stop  
    };

    mInputSensorCount = sizeof(fields) / sizeof(SoField *);
    mInputSensors = new SoFieldSensor *[mInputSensorCount];

    for (int i = 0; i < mInputSensorCount; i++)
    {
        mInputSensors[i] = new SoFieldSensor(&fieldSensorCBFunc, this);
        mInputSensors[i]->attach(fields[i]);
        mInputSensors[i]->setPriority(0);
    }

    int64_t freq;
#ifdef WIN32
    QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER *>(&freq));
    mPerfFreq = double(freq);
#endif /* WIN32 */

	
	mElapsedTime = .0f;
}

SoXipTimerFunction::~SoXipTimerFunction()
{
    for (int i = 0; i < mInputSensorCount; i++)
    {
		delete mInputSensors[i];
        mInputSensors[i] = 0;
    }

    delete mInputSensors;
    mInputSensors = 0;
    mInputSensorCount = 0;
	
}

void SoXipTimerFunction::fieldSensorCBFunc(void * user,
                                           SoSensor * sensor)
{
    SoXipTimerFunction * object =
        reinterpret_cast<SoXipTimerFunction *>(user);
    SoFieldSensor * fieldSensor = reinterpret_cast<SoFieldSensor *>(sensor);

    object->inputChanged(fieldSensor->getAttachedField());
}

void SoXipTimerFunction::inputChanged(SoField *which)
{
    if ( (which == &start) && mRealTime) 
    {
       	syncIn.enableConnection(true);
#ifdef WIN32
		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&mStartTime));
#endif /* WIN32 */
		
		if (!pauseOn.getValue())
        {
			mValue = 0.0;
			value.setValue(0.0);
			mElapsedTime = 0.0;
		} 
		
		pauseOn.setValue(false);
	
		mStarted = true;
	}
	else if (which == &pause)
	{
		pauseOn.setValue(true);
	
		int64_t currentTime;
#ifdef WIN32
		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&currentTime));
#endif /* WIN32 */
		syncIn.enableConnection(false);		
		mElapsedTime += (currentTime - mStartTime);
		syncIn.enableConnection(false);
	}
	else if (which == &stop)
    {
		syncIn.enableConnection(false);
		mValue = 0.0;
	    value.setValue(0.0);
		pauseOn.setValue(false);
		mStarted = false;
		counter.setValue(0);
    }
}

void SoXipTimerFunction::GLRender(SoGLRenderAction * /* action */)
{
    if (!mRealTime || mValue >= 1.0 || pauseOn.getValue() || !mStarted )
        return;

    
	int64_t currentTime;

#ifdef WIN32
    QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&currentTime));
#endif /* WIN32 */

	
    // unsigned long currentTime = mRealTime->getValue().getMsecValue();
    float dT = float(double(currentTime - mStartTime + mElapsedTime) / mPerfFreq);

    switch (function.getValue())
    {
    default:
    case C0:
        mValue = linearstep(dT, 0.0f, duration.getValue());
        break;

    case C1:
        mValue = smoothstep(dT, 0.0f, duration.getValue());
        break;

    case C2:
        mValue = smoothstep2(dT, 0.0f, duration.getValue());
        break;
    }

    value.setValue(mValue);

	// disconnect timer after time passed
    if (dT > duration.getValue()) {
        syncIn.enableConnection(FALSE);
        counter.setValue(counter.getValue() + 1);
		
		if (playMode.getValue() == LOOP)
			start.touch();


	}

    
}


// local Variables:
//   mode: c++
//   indent-tabs-mode: nil
//   c-indentation-style: k&r
//   c-basic-offset: 4
// End: