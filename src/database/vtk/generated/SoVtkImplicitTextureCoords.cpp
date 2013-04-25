/*
 *  COPYRIGHT NOTICE.  Copyright (C) 2007 Siemens Corporate Research, 
 *  Inc. ("caBIG(tm) Participant"). The eXtensible Imaging Platform
 *  (XIP) was created with NCI funding and is part of the caBIG(tm) 
 *  initiative. The software subject to this notice and license 
 *  includes both human readable source code form and machine 
 *  readable, binary, object code form (the "caBIG(tm) Software").
 *  
 *  This caBIG(tm) Software License (the "License") is between 
 *  caBIG(tm) Participant and You.  "You (or "Your") shall mean a 
 *  person or an entity, and all other entities that control, are 
 *  controlled by, or are under common control with the entity.  
 *  "Control" for purposes of this definition means (i) the direct or 
 *  indirect power to cause the direction or management of such 
 *  entity, whether by contract or otherwise, or (ii) ownership of 
 *  fifty percent (50%) or more of the outstanding shares, or (iii) 
 *  beneficial ownership of such entity.
 *  
 *  LICENSE.  Provided that You agree to the conditions described 
 *  below, caBIG(tm) Participant grants You a non-exclusive, 
 *  worldwide, perpetual, fully-paid-up, no-charge, irrevocable, 
 *  transferable and royalty-free right and license in its rights in 
 *  the caBIG(tm) Software, including any copyright or patent rights 
 *  therein that may be infringed by the making, using, selling, 
 *  offering for sale, or importing of caBIG(tm) Software, to (i) 
 *  use, install, access, operate, execute, reproduce, copy, modify, 
 *  translate, market, publicly display, publicly perform, and 
 *  prepare derivative works of the caBIG(tm) Software; (ii) make, 
 *  have made, use, practice, sell, and offer for sale, and/or 
 *  otherwise dispose of caBIG(tm) Software (or portions thereof); 
 *  (iii) distribute and have distributed to and by third parties the 
 *  caBIG(tm) Software and any modifications and derivative works 
 *  thereof; and (iv) sublicense the foregoing rights set out in (i), 
 *  (ii) and (iii) to third parties, including the right to license 
 *  such rights to further third parties.  For sake of clarity, and 
 *  not by way of limitation, caBIG(tm) Participant shall have no 
 *  right of accounting or right of payment from You or Your 
 *  sublicensees for the rights granted under this License.  This 
 *  License is granted at no charge to You.  Your downloading, 
 *  copying, modifying, displaying, distributing or use of caBIG(tm) 
 *  Software constitutes acceptance of all of the terms and 
 *  conditions of this Agreement.  If you do not agree to such terms 
 *  and conditions, you have no right to download, copy, modify, 
 *  display, distribute or use the caBIG(tm) Software.
 *  
 *  1.	Your redistributions of the source code for the caBIG(tm) 
 *      Software must retain the above copyright notice, this list 
 *      of conditions and the disclaimer and limitation of 
 *      liability of Article 6 below.  Your redistributions in 
 *      object code form must reproduce the above copyright notice, 
 *      this list of conditions and the disclaimer of Article 6 in 
 *      the documentation and/or other materials provided with the 
 *      distribution, if any.
 *  2.	Your end-user documentation included with the 
 *      redistribution, if any, must include the following 
 *      acknowledgment: "This product includes software developed 
 *      by Siemens Corporate Research Inc."  If You do not include 
 *      such end-user documentation, You shall include this 
 *      acknowledgment in the caBIG(tm) Software itself, wherever 
 *      such third-party acknowledgments normally appear.
 *  3.	You may not use the names "Siemens Corporate Research, 
 *      Inc.", "The National Cancer Institute", "NCI", "Cancer 
 *      Bioinformatics Grid" or "caBIG(tm)" to endorse or promote 
 *      products derived from this caBIG(tm) Software.  This 
 *      License does not authorize You to use any trademarks, 
 *  	service marks, trade names, logos or product names of 
 *      either caBIG(tm) Participant, NCI or caBIG(tm), except as 
 *      required to comply with the terms of this License.
 *  4.	For sake of clarity, and not by way of limitation, You may 
 *      incorporate this caBIG(tm) Software into Your proprietary 
 *      programs and into any third party proprietary programs.  
 *      However, if You incorporate the caBIG(tm) Software into 
 *      third party proprietary programs, You agree that You are 
 *      solely responsible for obtaining any permission from such 
 *      third parties required to incorporate the caBIG(tm) 
 *      Software into such third party proprietary programs and for 
 *      informing Your sublicensees, including without limitation 
 *      Your end-users, of their obligation to secure any required 
 *      permissions from such third parties before incorporating 
 *      the caBIG(tm) Software into such third party proprietary 
 *      software programs.  In the event that You fail to obtain 
 *      such permissions, You agree to indemnify caBIG(tm) 
 *      Participant for any claims against caBIG(tm) Participant by 
 *      such third parties, except to the extent prohibited by law, 
 *      resulting from Your failure to obtain such permissions.
 *  5.	For sake of clarity, and not by way of limitation, You may 
 *      add Your own copyright statement to Your modifications and 
 *      to the derivative works, and You may provide additional or 
 *      different license terms and conditions in Your sublicenses 
 *      of modifications of the caBIG(tm) Software, or any 
 *      derivative works of the caBIG(tm) Software as a whole, 
 *      provided Your use, reproduction, and distribution of the 
 *      Work otherwise complies with the conditions stated in this 
 *      License.
 *  6.	THIS caBIG(tm) SOFTWARE IS PROVIDED "AS IS" AND ANY 
 *      EXPRESSED OR IMPLIED WARRANTIES (INCLUDING, BUT NOT LIMITED 
 *      TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, NON-
 *      INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE) ARE 
 *      DISCLAIMED.  IN NO EVENT SHALL SIEMENS CORPORATE RESEARCH 
 *      INC. OR ITS AFFILIATES BE LIABLE FOR ANY DIRECT, INDIRECT, 
 *      INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
 *      (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
 *      GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR 
 *      BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 *      LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *      (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
 *      OF THE USE OF THIS caBIG(tm) SOFTWARE, EVEN IF ADVISED OF 
 *      THE POSSIBILITY OF SUCH DAMAGE.
 *  
 */
 
 
 
# include "SoVtkImplicitTextureCoords.h"
# include "SoVtkUtils.h"

# include "vtkImplicitFunction.h"
# include "vtkAlgorithmOutput.h"
# include "vtkStructuredPoints.h"
# include "vtkStructuredGrid.h"
# include "vtkPolyData.h"
# include "vtkImageData.h"
# include "vtkDataSet.h"
# include "vtkUnstructuredGrid.h"
# include "vtkRectilinearGrid.h"


SO_ENGINE_SOURCE( SoVtkImplicitTextureCoords )

SoVtkImplicitTextureCoords::SoVtkImplicitTextureCoords()
{
	SO_ENGINE_CONSTRUCTOR(SoVtkImplicitTextureCoords);

	mObject = vtkImplicitTextureCoords::New();
	mObject->Register(0);
	mObject->SetGlobalWarningDisplay(0);

	vtkImplicitTextureCoords *aImplicitTextureCoords = vtkImplicitTextureCoords::New();
	double *x = 0;
	int *y = 0;
	float *z = 0;

	SO_ENGINE_ADD_INPUT(TFunction, (0));

	SO_ENGINE_ADD_INPUT(SFunction, (0));

	SO_ENGINE_ADD_INPUT(RFunction, (0));

	SO_ENGINE_ADD_INPUT(FlipTexture, (0));
	FlipTexture.setValue(aImplicitTextureCoords->GetFlipTexture());

	SO_ENGINE_ADD_INPUT(InputConnection, (0));

	aImplicitTextureCoords->Delete();


	SO_ENGINE_ADD_OUTPUT( oStructuredPointsOutput, SoSFVtkObject );
	mStructuredPointsOutput = 0;
	SO_ENGINE_ADD_OUTPUT( oRFunction, SoSFVtkObject );
	mRFunction = 0;
	SO_ENGINE_ADD_OUTPUT( oStructuredGridOutput, SoSFVtkObject );
	mStructuredGridOutput = 0;
	SO_ENGINE_ADD_OUTPUT( oPolyDataOutput, SoSFVtkObject );
	mPolyDataOutput = 0;
	SO_ENGINE_ADD_OUTPUT( oImageDataOutput, SoSFVtkObject );
	mImageDataOutput = 0;
	SO_ENGINE_ADD_OUTPUT( oTFunction, SoSFVtkObject );
	mTFunction = 0;
	SO_ENGINE_ADD_OUTPUT( oSFunction, SoSFVtkObject );
	mSFunction = 0;
	SO_ENGINE_ADD_OUTPUT( Output, SoSFVtkObject );
	mOutput = 0;
	SO_ENGINE_ADD_OUTPUT( OutputPort, SoSFVtkAlgorithmOutput );
	mOutputPort = 0;
	SO_ENGINE_ADD_OUTPUT( oUnstructuredGridOutput, SoSFVtkObject );
	mUnstructuredGridOutput = 0;
	SO_ENGINE_ADD_OUTPUT( oRectilinearGridOutput, SoSFVtkObject );
	mRectilinearGridOutput = 0;


	addCalled = 0;
}

SoVtkImplicitTextureCoords::~SoVtkImplicitTextureCoords()
{
	// Deletion of the objects if they exist
	if ( mStructuredPointsOutput )
	{
	
		mStructuredPointsOutput->unref();
		mStructuredPointsOutput = 0;
	}
	
	if ( mRFunction )
	{
	
		mRFunction->unref();
		mRFunction = 0;
	}
	
	if ( mStructuredGridOutput )
	{
	
		mStructuredGridOutput->unref();
		mStructuredGridOutput = 0;
	}
	
	if ( mPolyDataOutput )
	{
	
		mPolyDataOutput->unref();
		mPolyDataOutput = 0;
	}
	
	if ( mImageDataOutput )
	{
	
		mImageDataOutput->unref();
		mImageDataOutput = 0;
	}
	
	if ( mTFunction )
	{
	
		mTFunction->unref();
		mTFunction = 0;
	}
	
	if ( mSFunction )
	{
	
		mSFunction->unref();
		mSFunction = 0;
	}
	
	if ( mOutput )
	{
	
		mOutput->unref();
		mOutput = 0;
	}
	
	if ( mOutputPort )
	{
	
		mOutputPort->unref();
		mOutputPort = 0;
	}
	
	if ( mUnstructuredGridOutput )
	{
	
		mUnstructuredGridOutput->unref();
		mUnstructuredGridOutput = 0;
	}
	
	if ( mRectilinearGridOutput )
	{
	
		mRectilinearGridOutput->unref();
		mRectilinearGridOutput = 0;
	}
	
	if ( mObject )
	{
		mObject->UnRegister(0);
		mObject->Delete();
		mObject = 0;
	}
	

}

void SoVtkImplicitTextureCoords::initClass()
{
	SO_ENGINE_INIT_CLASS( SoVtkImplicitTextureCoords, SoEngine, "Engine" );
}

void SoVtkImplicitTextureCoords::evaluate()
{
	try
	{
		// Get the input type(s)
		SoVtkAlgorithmOutput *inputPortPtr = InputConnection.getValue();
		
		if (inputPortPtr)
			mObject->SetInputConnection(inputPortPtr->getPointer());

		// Deletion of the objects if they exist
		if ( mStructuredPointsOutput )
		{
		
			mStructuredPointsOutput->unref();
			mStructuredPointsOutput = 0;
		}
		
		if ( mRFunction )
		{
		
			mRFunction->unref();
			mRFunction = 0;
		}
		
		if ( mStructuredGridOutput )
		{
		
			mStructuredGridOutput->unref();
			mStructuredGridOutput = 0;
		}
		
		if ( mPolyDataOutput )
		{
		
			mPolyDataOutput->unref();
			mPolyDataOutput = 0;
		}
		
		if ( mImageDataOutput )
		{
		
			mImageDataOutput->unref();
			mImageDataOutput = 0;
		}
		
		if ( mTFunction )
		{
		
			mTFunction->unref();
			mTFunction = 0;
		}
		
		if ( mSFunction )
		{
		
			mSFunction->unref();
			mSFunction = 0;
		}
		
		if ( mOutput )
		{
		
			mOutput->unref();
			mOutput = 0;
		}
		
		if ( mOutputPort )
		{
		
			mOutputPort->unref();
			mOutputPort = 0;
		}
		
		if ( mUnstructuredGridOutput )
		{
		
			mUnstructuredGridOutput->unref();
			mUnstructuredGridOutput = 0;
		}
		
		if ( mRectilinearGridOutput )
		{
		
			mRectilinearGridOutput->unref();
			mRectilinearGridOutput = 0;
		}
		
		if ( addCalled )
		{
			reset();
			addCalled = 0;
		}

		mObject->GetStructuredPointsOutput();
		mStructuredPointsOutput = new SoVtkObject();
		mStructuredPointsOutput->ref();
		mStructuredPointsOutput->setPointer( mObject->GetStructuredPointsOutput() );

		mObject->GetRFunction();
		mRFunction = new SoVtkObject();
		mRFunction->ref();
		mRFunction->setPointer( mObject->GetRFunction() );

		mObject->GetStructuredGridOutput();
		mStructuredGridOutput = new SoVtkObject();
		mStructuredGridOutput->ref();
		mStructuredGridOutput->setPointer( mObject->GetStructuredGridOutput() );

		mObject->GetPolyDataOutput();
		mPolyDataOutput = new SoVtkObject();
		mPolyDataOutput->ref();
		mPolyDataOutput->setPointer( mObject->GetPolyDataOutput() );

		mObject->GetImageDataOutput();
		mImageDataOutput = new SoVtkObject();
		mImageDataOutput->ref();
		mImageDataOutput->setPointer( mObject->GetImageDataOutput() );

		mObject->GetTFunction();
		mTFunction = new SoVtkObject();
		mTFunction->ref();
		mTFunction->setPointer( mObject->GetTFunction() );

		mObject->GetSFunction();
		mSFunction = new SoVtkObject();
		mSFunction->ref();
		mSFunction->setPointer( mObject->GetSFunction() );

		mObject->GetOutput()->Register(0);
		mOutput = new SoVtkObject();
		mOutput->ref();
		mOutput->setPointer( mObject->GetOutput() );

		if ( mObject->GetNumberOfOutputPorts() > 0 )
		{
			mObject->GetOutputPort()->Register(0);
			mOutputPort = new SoVtkAlgorithmOutput();
			mOutputPort->ref();
			mOutputPort->setPointer( mObject->GetOutputPort() );
		}

		mObject->GetUnstructuredGridOutput();
		mUnstructuredGridOutput = new SoVtkObject();
		mUnstructuredGridOutput->ref();
		mUnstructuredGridOutput->setPointer( mObject->GetUnstructuredGridOutput() );

		mObject->GetRectilinearGridOutput();
		mRectilinearGridOutput = new SoVtkObject();
		mRectilinearGridOutput->ref();
		mRectilinearGridOutput->setPointer( mObject->GetRectilinearGridOutput() );

	}
	catch(...)
	{
		SoDebugError::post( __FILE__, "Unknown Exception" );
		return;
	}
	SO_ENGINE_OUTPUT( oStructuredPointsOutput, SoSFVtkObject, setValue( mStructuredPointsOutput ) );
	SO_ENGINE_OUTPUT( oRFunction, SoSFVtkObject, setValue( mRFunction ) );
	SO_ENGINE_OUTPUT( oStructuredGridOutput, SoSFVtkObject, setValue( mStructuredGridOutput ) );
	SO_ENGINE_OUTPUT( oPolyDataOutput, SoSFVtkObject, setValue( mPolyDataOutput ) );
	SO_ENGINE_OUTPUT( oImageDataOutput, SoSFVtkObject, setValue( mImageDataOutput ) );
	SO_ENGINE_OUTPUT( oTFunction, SoSFVtkObject, setValue( mTFunction ) );
	SO_ENGINE_OUTPUT( oSFunction, SoSFVtkObject, setValue( mSFunction ) );
	SO_ENGINE_OUTPUT( Output, SoSFVtkObject, setValue( mOutput ) );
	SO_ENGINE_OUTPUT( OutputPort, SoSFVtkAlgorithmOutput, setValue( mOutputPort ) );
	SO_ENGINE_OUTPUT( oUnstructuredGridOutput, SoSFVtkObject, setValue( mUnstructuredGridOutput ) );
	SO_ENGINE_OUTPUT( oRectilinearGridOutput, SoSFVtkObject, setValue( mRectilinearGridOutput ) );
}


void SoVtkImplicitTextureCoords::inputChanged(SoField * f)
{
	// Get the TFunction value
	if ( f == &TFunction )
		SO_VTK_SET_FIELD_DATA( mObject, TFunction, vtkImplicitFunction);

	// Get the SFunction value
	if ( f == &SFunction )
		SO_VTK_SET_FIELD_DATA( mObject, SFunction, vtkImplicitFunction);

	// Get the RFunction value
	if ( f == &RFunction )
		SO_VTK_SET_FIELD_DATA( mObject, RFunction, vtkImplicitFunction);

	// Get the FlipTexture value
	if ( f == &FlipTexture )
		SO_VTK_SET_FIELD_VALUE( mObject, FlipTexture);

	mObject->Update();
}

void SoVtkImplicitTextureCoords::reset()
{
	mObject->UnRegister(0);
	mObject->Delete();
	mObject = 0;
	mObject = vtkImplicitTextureCoords::New();
	mObject->Register(0);
	mObject->SetGlobalWarningDisplay(0);
	// Get the input type(s)
	SoVtkAlgorithmOutput *inputPortPtr = InputConnection.getValue();
	
	if (inputPortPtr)
		mObject->SetInputConnection(inputPortPtr->getPointer());

	// Get the TFunction value
	
		SO_VTK_SET_FIELD_DATA( mObject, TFunction, vtkImplicitFunction);

	// Get the SFunction value
	
		SO_VTK_SET_FIELD_DATA( mObject, SFunction, vtkImplicitFunction);

	// Get the RFunction value
	
		SO_VTK_SET_FIELD_DATA( mObject, RFunction, vtkImplicitFunction);

	// Get the FlipTexture value
	
		SO_VTK_SET_FIELD_VALUE( mObject, FlipTexture);

	mObject->Update();
}