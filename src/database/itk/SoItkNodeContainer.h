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

/* author Sylvain Jaume, Julien Gein */

#ifndef SO_ITK_NODE_CONTAINER_H
# define SO_ITK_NODE_CONTAINER_H

# include <xip/inventor/itk/xipivitk.h>
# include <Inventor/engines/SoSubEngine.h>
# include <Inventor/fields/SoMFVec3f.h>
# include <Inventor/fields/SoMFFloat.h>
# include <Inventor/fields/SoSFFloat.h>
# include <Inventor/fields/SoSFShort.h>
# include <Inventor/fields/SoSFEnum.h>

class SoItkNodeContainer : public SoEngine
{
	SO_ENGINE_HEADER( SoItkNodeContainer );

public:
	SoItkNodeContainer();

	static void initClass();	

	SoSFFloat DefaultLabel;
	SoMFVec3f Seeds;
	SoMFFloat Labels;

	SoEngineOutput NodeContainer;		// SoItkSFNodeContainer

protected:
	~SoItkNodeContainer();

	virtual void inputChanged( SoField* field );
	virtual void evaluate();

};

#endif // SO_ITK_NODE_CONTAINER_H