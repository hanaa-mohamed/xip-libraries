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
#ifndef SOXIPOVERLAYACTIONS_H
#define SOXIPOVERLAYACTIONS_H

#include <Inventor/engines/SoSubEngine.h>
#include <Inventor/fields/SoMFNode.h>
#include <Inventor/fields/SoSFTrigger.h>

class SoXipOverlayActions : public SoEngine
{
	SO_ENGINE_HEADER( SoXipOverlayActions );

public:
	SoXipOverlayActions();

	SoMFNode		overlays;
	SoSFTrigger		show;
	SoSFTrigger		hide;
	SoSFTrigger		select;
	SoSFTrigger		unselect;

	SoEngineOutput	status; // SoSFString

	static void initClass();

protected:
	~SoXipOverlayActions();

	virtual void doAction( class SoXipShape* shape );

	virtual void inputChanged( SoField* whichField );
	virtual void evaluate();

	SoSFTrigger*	mActionTrigger;
};

#endif // SOXIPOVERLAYACTIONS_H
