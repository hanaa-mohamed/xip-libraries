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
 
 
 
# ifndef SO_VTK_DECIMATEPRO_H_
# define SO_VTK_DECIMATEPRO_H_

# include <Inventor/engines/SoSubEngine.h>

# include "xip/inventor/vtk/SoSFVtkAlgorithmOutput.h"
# include "xip/inventor/vtk/SoSFVtkObject.h"

# include "vtkDecimatePro.h"

# include "Inventor/fields/SoSFFloat.h"
# include "Inventor/fields/SoSFInt32.h"

class SoVtkDecimatePro : public SoEngine
{
	SO_ENGINE_HEADER( SoVtkDecimatePro );

public:

	/// Constructor
	SoVtkDecimatePro();

	/// Class Initialization
	static void initClass();
	
	// Inputs
	/// AbsoluteError
	SoSFFloat AbsoluteError;
	/// Splitting
	SoSFInt32 Splitting;
	/// AccumulateError
	SoSFInt32 AccumulateError;
	/// InflectionPointRatio
	SoSFFloat InflectionPointRatio;
	/// MaximumError
	SoSFFloat MaximumError;
	/// ErrorIsAbsolute
	SoSFInt32 ErrorIsAbsolute;
	/// TargetReduction
	SoSFFloat TargetReduction;
	/// BoundaryVertexDeletion
	SoSFInt32 BoundaryVertexDeletion;
	/// PreserveTopology
	SoSFInt32 PreserveTopology;
	/// PreSplitMesh
	SoSFInt32 PreSplitMesh;
	/// Degree
	SoSFInt32 Degree;
	/// FeatureAngle
	SoSFFloat FeatureAngle;
	/// SplitAngle
	SoSFFloat SplitAngle;
	/// Input connection 
	SoSFVtkAlgorithmOutput InputConnection;

	
	// Outputs
	/// SoSFVtkObject of type vtkPolyData
	SoEngineOutput Output;
	/// SoSFVtkAlgorithmOutput
	SoEngineOutput OutputPort;

protected:

	/// Destructor
	~SoVtkDecimatePro();

	/// Evaluate Function
	virtual void evaluate();

	/// inputChanged Function
	virtual void inputChanged(SoField *);

	/// reset Function
	virtual void reset();

	/// vtkPolyData
	SoVtkObject *mOutput;

	/// vtkAlgorithm
	SoVtkAlgorithmOutput *mOutputPort;


private:

	vtkDecimatePro* mObject;
	/// addCalled checks if the Add*() method has been called 
	bool addCalled;
};

#endif // SO_VTK_DECIMATEPRO_H_

