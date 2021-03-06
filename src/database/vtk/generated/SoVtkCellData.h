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
/*
 * \brief
 * \author Sylvain Jaume, Francois Huguet
 */
 
 
 
# ifndef SO_VTK_CELLDATA_H_
# define SO_VTK_CELLDATA_H_

# include <Inventor/engines/SoSubEngine.h>

# include "xip/inventor/vtk/SoSFVtkAlgorithmOutput.h"
# include "xip/inventor/vtk/SoSFVtkObject.h"

# include "vtkCellData.h"

# include "Inventor/fields/SoSFInt32.h"
# include "xip/inventor/core/SbVariant.h"
# include "xip/inventor/core/SoMFVariant.h"

class SoVtkCellData : public SoEngine
{
	SO_ENGINE_HEADER( SoVtkCellData );

public:

	/// Constructor
	SoVtkCellData();

	/// Class Initialization
	static void initClass();
	
	// Inputs
	/// CopyVectors
	SoSFInt32 CopyVectors;
	/// CopyScalars
	SoSFInt32 CopyScalars;
	/// CopyAttribute
	SoMFVariant CopyAttribute;
	/// CopyNormals
	SoSFInt32 CopyNormals;
	/// Component
	SoMFVariant Component;
	/// NumberOfTuples of type constvtkIdType
	SoSFVtkObject NumberOfTuples;
	/// CopyTensors
	SoSFInt32 CopyTensors;
	/// CopyTCoords
	SoSFInt32 CopyTCoords;

	
	// Outputs
	/// SoSFVtkObject of type vtkDataArray
	SoEngineOutput oTensors;
	/// SoSFVtkObject of type vtkDataArray
	SoEngineOutput oScalars;
	/// SoSFVtkObject of type vtkDataArray
	SoEngineOutput oTCoords;
	/// SoSFVtkObject of type vtkDataArray
	SoEngineOutput oNormals;
	/// SoSFVtkObject of type vtkDataArray
	SoEngineOutput oVectors;
	/// SoSFVtkObject of type CellData
	SoEngineOutput Output;

protected:

	/// Destructor
	~SoVtkCellData();

	/// Evaluate Function
	virtual void evaluate();

	/// inputChanged Function
	virtual void inputChanged(SoField *);

	/// reset Function
	virtual void reset();

	/// vtkDataArray
	SoVtkObject *mTensors;

	/// vtkDataArray
	SoVtkObject *mScalars;

	/// vtkDataArray
	SoVtkObject *mTCoords;

	/// vtkDataArray
	SoVtkObject *mNormals;

	/// vtkDataArray
	SoVtkObject *mVectors;

	/// vtkCellData
	SoVtkObject *mOutput;


private:

	vtkCellData* mObject;
	/// addCalled checks if the Add*() method has been called 
	bool addCalled;
};

#endif // SO_VTK_CELLDATA_H_

