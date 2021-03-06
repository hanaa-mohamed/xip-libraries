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
#include <itkCurvatureAnisotropicDiffusionImageFilter.h>
#include <xip/inventor/itk/SoItkUtils.h>
#include "SoItkCurvatureAnisotropicDiffusionImageFilter.h"

SO_ENGINE_SOURCE( SoItkCurvatureAnisotropicDiffusionImageFilter );

SoItkCurvatureAnisotropicDiffusionImageFilter::SoItkCurvatureAnisotropicDiffusionImageFilter()
{
	SO_ENGINE_CONSTRUCTOR( SoItkCurvatureAnisotropicDiffusionImageFilter );
}

SoItkCurvatureAnisotropicDiffusionImageFilter::~SoItkCurvatureAnisotropicDiffusionImageFilter()
{

}

void
SoItkCurvatureAnisotropicDiffusionImageFilter::initClass()
{
	SO_ENGINE_INIT_CLASS( SoItkCurvatureAnisotropicDiffusionImageFilter, SoItkAnisotropicDiffusionImageFilter, "SoItkAnisotropicDiffusionImageFilter" );
}

bool
SoItkCurvatureAnisotropicDiffusionImageFilter::checkInput()
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
SoItkCurvatureAnisotropicDiffusionImageFilter::evaluate()
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
						typedef itk::CurvatureAnisotropicDiffusionImageFilter< InputImageType, OutputImageType > FilterType;
						
						FilterType::Pointer filter = FilterType::New();
						
						// Set the filter's inputs
						
						// Inherited from SoItkAnisotropicDiffusionImageFilter
						SO_ITK_SET_FIELD_VALUE( filter, ConductanceScalingParameter );
						SO_ITK_SET_FIELD_VALUE( filter, TimeStep );
						SO_ITK_SET_FIELD_VALUE( filter, ConductanceScalingUpdateInterval );
						SO_ITK_SET_FIELD_VALUE( filter, FixedAverageGradientMagnitude );
						SO_ITK_SET_FIELD_VALUE( filter, ConductanceParameter );
						
						
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
						typedef itk::CurvatureAnisotropicDiffusionImageFilter< InputImageType, OutputImageType > FilterType;
						
						FilterType::Pointer filter = FilterType::New();
						
						// Set the filter's inputs
						
						// Inherited from SoItkAnisotropicDiffusionImageFilter
						SO_ITK_SET_FIELD_VALUE( filter, ConductanceScalingParameter );
						SO_ITK_SET_FIELD_VALUE( filter, TimeStep );
						SO_ITK_SET_FIELD_VALUE( filter, ConductanceScalingUpdateInterval );
						SO_ITK_SET_FIELD_VALUE( filter, FixedAverageGradientMagnitude );
						SO_ITK_SET_FIELD_VALUE( filter, ConductanceParameter );
						
						
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
