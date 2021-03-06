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
#ifndef SORADIMAGEATTRIBUTES_H
#define SORADIMAGEATTRIBUTES_H

#include <Inventor/engines/SoSubEngine.h>
#include <Inventor/fields/SoSFMatrix.h>
#include <xip/inventor/core/SoXipSFDataImage.h>


class SoXipImageAttributes : public SoEngine
{
	SO_ENGINE_HEADER(SoXipImageAttributes);

public:
	SoXipImageAttributes();
	static void initClass();

	SoXipSFDataImage image;
	SoEngineOutput	 modelMatrix;
	SoEngineOutput	 width;
	SoEngineOutput	 height;
	SoEngineOutput	 depth;
	SoEngineOutput	 bitsStored;

	SoEngineOutput	 defaultOrientation;

	SoEngineOutput	 orthoScanOrientation;
	SoEngineOutput	 orthoOrientation1;
	SoEngineOutput	 orthoOrientation2;
	SoEngineOutput	 orthoOrientation3;

	SoEngineOutput	 defaultCenter;

protected:
	virtual ~SoXipImageAttributes();
	virtual void evaluate();
};


#endif // SORADIMAGEATTRIBUTES_H
