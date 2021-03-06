/*
Copyright (c) 2011, Siemens Corporate Research a Division of Siemens Corporation 
All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include <Inventor/fields/SoSFTrigger.h>
#include <xip/inventor/core/SoXipSFDataImage.h>
#include <xip/inventor/core/SoXipDataImage.h>
#include <xip/inventor/core/SbXipImage.h>
#include "SoXipIncrement.h"

SO_ENGINE_SOURCE( SoXipIncrement );

SoXipIncrement::SoXipIncrement()
{
	SO_ENGINE_CONSTRUCTOR( SoXipIncrement );

	SO_ENGINE_ADD_INPUT( next, ());
	SO_ENGINE_ADD_INPUT( previous, ());

	SO_ENGINE_ADD_INPUT( sliceIndex, (-1) );
	SO_ENGINE_ADD_OUTPUT( outSliceIndex, SoSFShort );
}

SoXipIncrement::~SoXipIncrement()
{

}

void
SoXipIncrement::initClass()
{
	SO_ENGINE_INIT_CLASS( SoXipIncrement, SoEngine, "Engine" );
}

void
SoXipIncrement::evaluate()
{
	// Reset outputs
    SO_ENGINE_OUTPUT( outSliceIndex, SoSFShort, setValue(0) );
}

void SoXipIncrement::inputChanged(SoField *which)
{
	if (which == &next)
	{
		sliceIndex.setValue( sliceIndex.getValue()+1 );
	    //SO_ENGINE_OUTPUT( outSliceIndex, SoSFShort, outSliceIndex.getValue()+1 );
	}
	else if (which == &previous)
	{
		if( sliceIndex.getValue() > 0 )
		sliceIndex.setValue( sliceIndex.getValue()-1 );
		else
		sliceIndex.setValue( 0 );
	    //SO_ENGINE_OUTPUT( outSliceIndex, SoSFShort, outSliceIndex.getValue()-1 );
	}
}
