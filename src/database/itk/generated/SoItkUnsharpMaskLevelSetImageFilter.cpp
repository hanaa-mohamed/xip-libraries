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
#include <itkUnsharpMaskLevelSetImageFilter.h>
#include <xip/inventor/itk/SoItkUtils.h>
#include "SoItkUnsharpMaskLevelSetImageFilter.h"

SO_ENGINE_SOURCE( SoItkUnsharpMaskLevelSetImageFilter );

SoItkUnsharpMaskLevelSetImageFilter::SoItkUnsharpMaskLevelSetImageFilter()
{
	SO_ENGINE_CONSTRUCTOR( SoItkUnsharpMaskLevelSetImageFilter );
	
	// Inputs
	SO_ENGINE_ADD_INPUT( MaxFilterIteration, (99) );
}

SoItkUnsharpMaskLevelSetImageFilter::~SoItkUnsharpMaskLevelSetImageFilter()
{

}

void
SoItkUnsharpMaskLevelSetImageFilter::initClass()
{
	SO_ENGINE_INIT_CLASS( SoItkUnsharpMaskLevelSetImageFilter, SoItkSparseFieldFourthOrderLevelSetImageFilter, "SoItkSparseFieldFourthOrderLevelSetImageFilter" );
}

bool
SoItkUnsharpMaskLevelSetImageFilter::checkInput()
{
	switch( Input0.getValue()->getType() )
	{
		case SoItkDataImage::FLOAT:
		{
			switch( Input0.getValue()->getNumDimension() )
			{
				case 2:
				{
					return true;
				}
				break ;
				case 3:
				{
					return true;
				}
				break ;
			}
		}
		break ;
	}
	
	return false;
}

void
SoItkUnsharpMaskLevelSetImageFilter::evaluate()
{
	if( mOutput )
	{
		mOutput->unref();
		mOutput = 0;
		SO_ENGINE_OUTPUT( Output, SoItkSFDataImage, setValue( 0 ) );
	}

	if( !Input0.getValue() )
		return ;
	
	if( !checkInput() )
	{
		SoDebugError::post( __FILE__, "Invalid Input Types" );
		return ;
	}

	try
	{
		switch( Input0.getValue()->getType() )
		{
			case SoItkDataImage::FLOAT:
			{
				switch( Input0.getValue()->getNumDimension() )
				{
					case 2:
					{
						typedef itk::Image< float, 2 > InputImageType;
						typedef itk::Image< float, 2 > OutputImageType;
						typedef itk::UnsharpMaskLevelSetImageFilter< InputImageType, OutputImageType > FilterType;
						
						FilterType::Pointer filter = FilterType::New();
						
						// Set the filter's inputs
						SO_ITK_SET_FIELD_VALUE( filter, MaxFilterIteration );
						
						// Inherited from SoItkSparseFieldFourthOrderLevelSetImageFilter
						SO_ITK_SET_FIELD_VALUE( filter, CurvatureBandWidth );
						SO_ITK_SET_FIELD_VALUE( filter, NumberOfLayers );
						SO_ITK_SET_FIELD_VALUE( filter, NormalProcessUnsharpWeight );
						SO_ITK_SET_FIELD_VALUE( filter, NormalProcessConductance );
						SO_ITK_SET_FIELD_VALUE( filter, NormalProcessUnsharpFlag );
						SO_ITK_SET_FIELD_VALUE( filter, RMSChangeNormalProcessTrigger );
						SO_ITK_SET_FIELD_VALUE( filter, MaxNormalIteration );
						SO_ITK_SET_FIELD_VALUE( filter, MaxRefitIteration );
						SO_ITK_SET_FIELD_VALUE( filter, NormalProcessType );
						
						// Inherited from SoItkSparseFieldLevelSetImageFilter
						SO_ITK_SET_FIELD_VALUE( filter, NumberOfLayers );
						SO_ITK_SET_FIELD_VALUE( filter, IsoSurfaceValue );
						SO_ITK_SET_FIELD_VALUE( filter, InterpolateSurfaceLocation );
						
						// Inherited from SoItkFiniteDifferenceImageFilter
						SO_ITK_SET_FIELD_VALUE( filter, UseImageSpacing );
						SO_ITK_SET_FIELD_VALUE( filter, NumberOfIterations );
						SO_ITK_SET_FIELD_VALUE( filter, RMSChange );
						SO_ITK_SET_FIELD_VALUE( filter, ManualReinitialization );
						SO_ITK_SET_FIELD_VALUE( filter, MaximumRMSError );
						
						// Inherited from SoItkInPlaceImageFilter
						SO_ITK_SET_FIELD_VALUE( filter, InPlace );
						
						// Inherited from SoItkImageToImageFilter
						typedef itk::Image< float, 2 > InputImageType;
						SO_ITK_SET_FIELD_MDATA( filter, Input, 0, InputImageType );
						
						
						
						// Start processing the ouputs
						filter->Update();
						
						// Retrieve the filter's outputs
						filter->GetOutput()->Register();
						mOutput = new SoItkDataImage( SoItkDataImage::FLOAT, 2,
							Input0.getValue()->getModelMatrix() );
						mOutput->ref();
						mOutput->setPointer( filter->GetOutput() );
					}
					break ;
					case 3:
					{
						typedef itk::Image< float, 3 > InputImageType;
						typedef itk::Image< float, 3 > OutputImageType;
						typedef itk::UnsharpMaskLevelSetImageFilter< InputImageType, OutputImageType > FilterType;
						
						FilterType::Pointer filter = FilterType::New();
						
						// Set the filter's inputs
						SO_ITK_SET_FIELD_VALUE( filter, MaxFilterIteration );
						
						// Inherited from SoItkSparseFieldFourthOrderLevelSetImageFilter
						SO_ITK_SET_FIELD_VALUE( filter, CurvatureBandWidth );
						SO_ITK_SET_FIELD_VALUE( filter, NumberOfLayers );
						SO_ITK_SET_FIELD_VALUE( filter, NormalProcessUnsharpWeight );
						SO_ITK_SET_FIELD_VALUE( filter, NormalProcessConductance );
						SO_ITK_SET_FIELD_VALUE( filter, NormalProcessUnsharpFlag );
						SO_ITK_SET_FIELD_VALUE( filter, RMSChangeNormalProcessTrigger );
						SO_ITK_SET_FIELD_VALUE( filter, MaxNormalIteration );
						SO_ITK_SET_FIELD_VALUE( filter, MaxRefitIteration );
						SO_ITK_SET_FIELD_VALUE( filter, NormalProcessType );
						
						// Inherited from SoItkSparseFieldLevelSetImageFilter
						SO_ITK_SET_FIELD_VALUE( filter, NumberOfLayers );
						SO_ITK_SET_FIELD_VALUE( filter, IsoSurfaceValue );
						SO_ITK_SET_FIELD_VALUE( filter, InterpolateSurfaceLocation );
						
						// Inherited from SoItkFiniteDifferenceImageFilter
						SO_ITK_SET_FIELD_VALUE( filter, UseImageSpacing );
						SO_ITK_SET_FIELD_VALUE( filter, NumberOfIterations );
						SO_ITK_SET_FIELD_VALUE( filter, RMSChange );
						SO_ITK_SET_FIELD_VALUE( filter, ManualReinitialization );
						SO_ITK_SET_FIELD_VALUE( filter, MaximumRMSError );
						
						// Inherited from SoItkInPlaceImageFilter
						SO_ITK_SET_FIELD_VALUE( filter, InPlace );
						
						// Inherited from SoItkImageToImageFilter
						typedef itk::Image< float, 3 > InputImageType;
						SO_ITK_SET_FIELD_MDATA( filter, Input, 0, InputImageType );
						
						
						
						// Start processing the ouputs
						filter->Update();
						
						// Retrieve the filter's outputs
						filter->GetOutput()->Register();
						mOutput = new SoItkDataImage( SoItkDataImage::FLOAT, 3,
							Input0.getValue()->getModelMatrix() );
						mOutput->ref();
						mOutput->setPointer( filter->GetOutput() );
					}
					break ;
				}
			}
			break ;
		}
	}
	catch( itk::ExceptionObject& e )
	{
		SoDebugError::post( e.GetFile(), "line %d: %s", e.GetLine(), e.GetDescription() );
		return ;
	}
	catch(...)
	{
		SoDebugError::post( __FILE__, "Unknown Exception" );
		return ;
	}

	SO_ENGINE_OUTPUT( Output, SoItkSFDataImage, setValue( mOutput ) );
}
