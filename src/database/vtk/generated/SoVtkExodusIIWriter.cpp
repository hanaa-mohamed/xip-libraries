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
 */

/*
 * \brief
 * \author Sylvain Jaume, Francois Huguet
 */
 
#include "SoVtkExodusIIWriter.h"
#include "SoVtkUtils.h"

#include "vtkModelMetadata.h"
#include "vtkAlgorithmOutput.h"

#ifdef WIN64
#include "vtkMultiBlockDataSet.h"
#endif

SO_ENGINE_SOURCE( SoVtkExodusIIWriter )

SoVtkExodusIIWriter::SoVtkExodusIIWriter()
{
	SO_ENGINE_CONSTRUCTOR(SoVtkExodusIIWriter);

	mObject = vtkExodusIIWriter::New();
	mObject->Register(0);
	mObject->SetGlobalWarningDisplay(0);

	vtkExodusIIWriter *aExodusIIWriter = vtkExodusIIWriter::New();
	double *x = 0;
	int *y = 0;
	float *z = 0;

	SO_ENGINE_ADD_INPUT(GhostLevel, (0));
	GhostLevel.setValue(aExodusIIWriter->GetGhostLevel());

	SO_ENGINE_ADD_INPUT(StoreDoubles, (0));
	StoreDoubles.setValue(aExodusIIWriter->GetStoreDoubles());

	SO_ENGINE_ADD_INPUT(WriteOutBlockIdArray, (0));
	WriteOutBlockIdArray.setValue(aExodusIIWriter->
	  GetWriteOutBlockIdArray());

	SO_ENGINE_ADD_INPUT(WriteOutGlobalElementIdArray, (0));
	WriteOutGlobalElementIdArray.setValue(aExodusIIWriter->
	  GetWriteOutGlobalElementIdArray());

	SO_ENGINE_ADD_INPUT(WriteOutGlobalNodeIdArray, (0));
	WriteOutGlobalNodeIdArray.setValue(aExodusIIWriter->
	  GetWriteOutGlobalNodeIdArray());

	//SO_ENGINE_ADD_INPUT(CurrentTimeStep, (0));
	//CurrentTimeStep.setValue(aExodusIIWriter->GetCurrentTimeStep());

	SO_ENGINE_ADD_INPUT(ModelMetadata, (0));

	//SO_ENGINE_ADD_INPUT(GlobalNodeIdArrayName, (""));

	//SO_ENGINE_ADD_INPUT(GlobalElementIdArrayName, (""));

	SO_ENGINE_ADD_INPUT(ErrorStatus, (0));

#ifdef WIN32 //WARNING - this is probably more of a VTK version specific thing...
	ErrorStatus.setValue(aExodusIIWriter->GetErrorStatus());
#endif //WIN32

	SO_ENGINE_ADD_INPUT(FileName, (""));

	SO_ENGINE_ADD_INPUT(BlockIdArrayName, (""));

	SO_ENGINE_ADD_INPUT(InputConnection, (0));

	aExodusIIWriter->Delete();


	SO_ENGINE_ADD_OUTPUT( OutputPort, SoSFVtkAlgorithmOutput );
	mOutputPort = 0;
	SO_ENGINE_ADD_OUTPUT( oOrCreateModelMetadata, SoSFVtkObject );
	mOrCreateModelMetadata = 0;
	SO_ENGINE_ADD_OUTPUT( Output, SoSFVtkObject );
	mOutput = 0;


	addCalled = 0;
}

SoVtkExodusIIWriter::~SoVtkExodusIIWriter()
{
	// Deletion of the objects if they exist
	if ( mOutputPort )
	{
	
		mOutputPort->unref();
		mOutputPort = 0;
	}
	
	if ( mOrCreateModelMetadata )
	{
	
		mOrCreateModelMetadata->unref();
		mOrCreateModelMetadata = 0;
	}
	
	if ( mObject )
	{
		mObject->UnRegister(0);
		mObject->Delete();
		mObject = 0;
	}
	

}

void SoVtkExodusIIWriter::initClass()
{
	SO_ENGINE_INIT_CLASS( SoVtkExodusIIWriter, SoEngine, "Engine" );
}

void SoVtkExodusIIWriter::evaluate()
{
	try
	{
        
#ifdef WIN32 //WARNING - this is probably more of a VTK version specific thing...
		// Get the input type(s)
		SoVtkAlgorithmOutput *inputPortPtr = InputConnection.getValue();
		
		if (inputPortPtr)
			mObject->SetInputConnection(inputPortPtr->getPointer());

		// Deletion of the objects if they exist
		if ( mOutputPort )
		{
		
			mOutputPort->unref();
			mOutputPort = 0;
		}
		
		if ( mOrCreateModelMetadata )
		{
		
			mOrCreateModelMetadata->unref();
			mOrCreateModelMetadata = 0;
		}
		
		if ( addCalled )
		{
			reset();
			addCalled = 0;
		}

		if ( mObject->GetNumberOfOutputPorts() > 0 )
		{
			mObject->GetOutputPort()->Register(0);
			mOutputPort = new SoVtkAlgorithmOutput();
			mOutputPort->ref();
			mOutputPort->setPointer( mObject->GetOutputPort() );
		}
		mObject->GetOrCreateModelMetadata();
		mOrCreateModelMetadata = new SoVtkObject();
		mOrCreateModelMetadata->ref();
		mOrCreateModelMetadata->setPointer( mObject->GetOrCreateModelMetadata() );

		mOutput = new SoVtkObject();
		mOutput->ref();
		mOutput->setPointer( mObject );
#endif //WIN32 
        
	}
	catch(...)
	{
		SoDebugError::post( __FILE__, "Unknown Exception" );
		return;
	}
	SO_ENGINE_OUTPUT( OutputPort, SoSFVtkAlgorithmOutput, setValue( mOutputPort ) );
	SO_ENGINE_OUTPUT( oOrCreateModelMetadata, SoSFVtkObject, setValue( mOrCreateModelMetadata ) );
	SO_ENGINE_OUTPUT( Output, SoSFVtkObject, setValue( mOutput ) );
}


void SoVtkExodusIIWriter::inputChanged(SoField * f)
{
	// Get the GhostLevel value
	if ( f == &GhostLevel )
		SO_VTK_SET_FIELD_VALUE( mObject, GhostLevel);

	// Get the StoreDoubles value
	if ( f == &StoreDoubles )
		SO_VTK_SET_FIELD_VALUE( mObject, StoreDoubles);

	// Get the WriteOutBlockIdArray value
	if ( f == &WriteOutBlockIdArray )
		SO_VTK_SET_FIELD_VALUE( mObject, WriteOutBlockIdArray);

	// Get the WriteOutGlobalElementIdArray value
	if ( f == &WriteOutGlobalElementIdArray )
		SO_VTK_SET_FIELD_VALUE( mObject, WriteOutGlobalElementIdArray);

	// Get the WriteOutGlobalNodeIdArray value
	if ( f == &WriteOutGlobalNodeIdArray )
		SO_VTK_SET_FIELD_VALUE( mObject, WriteOutGlobalNodeIdArray);

	// Get the CurrentTimeStep value
	//if ( f == &CurrentTimeStep )
  //SO_VTK_SET_FIELD_VALUE( mObject, CurrentTimeStep);

	// Get the ModelMetadata value
	if ( f == &ModelMetadata )
		SO_VTK_SET_FIELD_DATA( mObject, ModelMetadata, vtkModelMetadata);

	// Get the GlobalNodeIdArrayName value
	//if ( f == &GlobalNodeIdArrayName )
	//SO_VTK_SET_FIELD_MFSTRING( mObject, GlobalNodeIdArrayName);

	// Get the GlobalElementIdArrayName value
	//if ( f == &GlobalElementIdArrayName )
	//SO_VTK_SET_FIELD_MFSTRING( mObject, GlobalElementIdArrayName);

#ifdef WIN32 //WARNING - this is probably more of a VTK version specific thing...
	// Get the ErrorStatus value
	if ( f == &ErrorStatus )
		SO_VTK_SET_FIELD_VALUE( mObject, ErrorStatus);
#endif //WIN32
    
	// Get the FileName value
	if ( f == &FileName )
		SO_VTK_SET_FIELD_MFSTRING( mObject, FileName);

	// Get the BlockIdArrayName value
	if ( f == &BlockIdArrayName )
		SO_VTK_SET_FIELD_MFSTRING( mObject, BlockIdArrayName);

	mObject->Update();
}

void SoVtkExodusIIWriter::reset()
{
	mObject->UnRegister(0);
	mObject->Delete();
	mObject = 0;
	mObject = vtkExodusIIWriter::New();
	mObject->Register(0);
	mObject->SetGlobalWarningDisplay(0);
	// Get the input type(s)
	SoVtkAlgorithmOutput *inputPortPtr = InputConnection.getValue();
	
	if (inputPortPtr)
		mObject->SetInputConnection(inputPortPtr->getPointer());

	// Get the GhostLevel value
	
		SO_VTK_SET_FIELD_VALUE( mObject, GhostLevel);

	// Get the StoreDoubles value
	
		SO_VTK_SET_FIELD_VALUE( mObject, StoreDoubles);

	// Get the WriteOutBlockIdArray value
	
		SO_VTK_SET_FIELD_VALUE( mObject, WriteOutBlockIdArray);

	// Get the WriteOutGlobalElementIdArray value
	
		SO_VTK_SET_FIELD_VALUE( mObject, WriteOutGlobalElementIdArray);

	// Get the WriteOutGlobalNodeIdArray value
	
		SO_VTK_SET_FIELD_VALUE( mObject, WriteOutGlobalNodeIdArray);

	// Get the CurrentTimeStep value
	//SO_VTK_SET_FIELD_VALUE( mObject, CurrentTimeStep);

	// Get the ModelMetadata value
	SO_VTK_SET_FIELD_DATA( mObject, ModelMetadata, vtkModelMetadata);

	// Get the GlobalNodeIdArrayName value
	//SO_VTK_SET_FIELD_MFSTRING( mObject, GlobalNodeIdArrayName);

	// Get the GlobalElementIdArrayName value
	//SO_VTK_SET_FIELD_MFSTRING( mObject, GlobalElementIdArrayName);

	// Get the ErrorStatus value
#ifdef WIN32 //WARNING - this is probably more of a VTK version specific thing...
		SO_VTK_SET_FIELD_VALUE( mObject, ErrorStatus);
#endif //WIN32

	// Get the FileName value
	
		SO_VTK_SET_FIELD_MFSTRING( mObject, FileName);

	// Get the BlockIdArrayName value
	
		SO_VTK_SET_FIELD_MFSTRING( mObject, BlockIdArrayName);

	mObject->Update();
}

