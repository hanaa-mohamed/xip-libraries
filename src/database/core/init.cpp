/*
*  COPYRIGHT NOTICE.  Copyright (C) 2005 Siemens Corporate Research, 
*  Inc. ("caBIG(tm) Participant"). eXtensible Imaging Platform (XIP)
*  was created with NCI funding and is part of the caBIG(tm) 
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

#include <xip/system/GL/gl.h>
#include <xip/inventor/core/SoXipData.h>
#include <xip/inventor/core/SoXipDataImage.h>
#include <xip/inventor/core/SoXipDataImageElement.h>
#include <xip/inventor/core/SoXipSFDataImage.h>
#include <xip/inventor/core/SoXipMFDataImage.h>
#include <xip/inventor/core/SoXipActiveViewportElement.h>
#include <xip/inventor/core/SoXipCursor.h>
#include <xip/inventor/core/SoXipExaminer.h>
#include <xip/inventor/core/SoXipKit.h>
#include <xip/inventor/core/SoXipRenderModeElement.h>
#include <xip/inventor/core/SoXipLutElement.h>
#include <xip/inventor/core/SoXipMultiTextureElement.h>
#include <xip/inventor/core/SbVariant.h>
#include <xip/inventor/core/SoMFVariant.h>
#include <xip/inventor/core/SoSFVariant.h>
#include <xip/inventor/core/SoXipMprPlaneElement.h>
#include <xip/inventor/core/SoXipMprActiveElement.h>
#include <xip/inventor/core/SoXipTransparentGeometryGroupElement.h>
#include <xip/inventor/core/SoXipMprLockElement.h>
#include <xip/inventor/core/SoXipVolGroupElement.h>
#include <xip/inventor/core/SoXipVolDataElement.h>
#include <xip/inventor/core/SoXipClipPlaneElement.h>
#include <xip/inventor/core/SbXipDirtyFieldList.h>
#include <xip/inventor/core/SoXipPickRadiusElement.h>
#include <xip/inventor/core/SoXipImageTextElement.h>

#include "SoXipAutoScale.h"
#include "SoXipBackground.h"
#include "SoXipTexture.h"
#include "SoXipSFDataImageToSFImage.h"
#include "SoXipImage.h"
#include "SoXipGetImage.h"
#include "SoXipLoadRaw.h"
#include "SoXipViewportBorder.h"
#include "SoXipIncrement.h"
#include "SoXipIntersectionPlane.h"
#include "SoXipViewportGroup.h"
#include "SoXipImageAttributes.h"
#include "SoXipRenderMode.h"
#include "SoXipWindowLevelManip.h"
#include "SoXipPlaneManipBase.h"
#include "SoXipMprPlane.h"
#include "SoXipMprIntersectionManip.h"
#include "SoXipMprIntersectionLine.h"
#include "SoXipMprExaminer.h"
#include "SoXipMprIntersectionPlanes.h"
#include "SoXipMprAlign.h"
#include "SoXipTransparentGeometryGroup.h"
#include "SoXipMprActive.h"
#include "SoXipMprLock.h"
#include "SoXipVolGroup.h"
#include "SoXipPickAction.h"
#include "SoXipBoundingBox.h"
#include "SoXipTrackballToMouse.h"
#include "SoXipTimerFunction.h"
#include "SoXipWindowSize.h"
#include "SoXipMouseToggle.h"
#include "SoXipDogEar.h"
#include "SoXipOrientationCube.h"
#include "SoXipClipPlane.h"
#include "SoXipLut.h"
#include "SoXipPerformance.h"
#include "SoXipPerformanceCounter.h"
#include "SoXipConvertMatrixToPlane.h"
#include "SoXipConvertToEnum.h"
#include "SoXipAnchor.h"
#include "SoXipImageExaminer.h"
#include "SoXipComposeMFImage.h"
#include "SoXipDecomposeMFImage.h"
#include "SoXipExtractSlice.h"
#include "SoXipLazyGroup.h"
#include "SoXipImageText.h"
#include "SoXipComposeVec6.h"
#include "SoXipDecomposeVec6.h"
#include "SoXipStringConcatenate.h"
#include "SoXipConvertMFImageToSFImage.h"
#include "SoXipConvertSFImageToMFImage.h"
#include "SoXipImageOperation.h"
#include "SoXipSwitchMFDataImage.h"

int XIPIVCORE_API xipivcore_init()
{
	//initialize elements first
	SoXipLutElement::initClass();
	SoXipActiveViewportElement::initClass();
	SoXipDataImageElement::initClass();
	SoXipMultiTextureElement::initClass();
	SoXipRenderModeElement::initClass();
	SoXipMprPlaneElement::initClass();
	SoXipMprActiveElement::initClass();		
    SoXipTransparentGeometryGroupElement::initClass();
	SoXipMprLockElement::initClass();
    SoXipVolDataElement::initClass();		
    SoXipVolGroupElement::initClass();		
	SoXipClipPlaneElement::initClass();
	SoXipPickRadiusElement::initClass();
	SoXipImageTextElement::initClass();

	//initialize rest then
	SbXipDirtyFieldList::initClass();
	SoXipData::initClass();
	SoXipDataImage::initClass();
	SoXipSFDataImage::initClass();
	SoXipMFDataImage::initClass();
	SoXipSFDataImageToSFImage::initClass();
	SoXipComposeVec6::initClass();
	SoXipCursor::initClass();
	SoXipDecomposeVec6::initClass();
	SoXipKit::initClass();
    SoXipImage::initClass();
    SoXipImageAttributes::initClass();
    SoXipLoadRaw::initClass();
    SoXipDogEar::initClass();
    SoXipViewportBorder::initClass();
    SoXipOrientationCube::initClass();	
    SoXipViewportGroup::initClass();
    SoXipLut::initClass();
    SoXipTexture::initClass();
    SoXipTimerFunction::initClass();
    SoXipRenderMode::initClass();
    SoXipExaminer::initClass();
    SoSFVariant::initClass();
    SoMFVariant::initClass();
    SoXipPlaneManipBase::initClass();
    SoXipIntersectionPlane::initClass();
    SoXipWindowLevelManip::initClass();
	SoXipMprPlane::initClass();
	SoXipMprIntersectionLine::initClass();
	SoXipMprIntersectionManip::initClass();
	SoXipMprExaminer::initClass();
	SoXipMprAlign::initClass();
    SoXipTransparentGeometryGroup::initClass();
	SoXipMprLock::initClass();
	SoXipMprActive::initClass();
    SoXipVolGroup::initClass();
    SoXipPickAction::initClass();

    SoXipLazyGroup::initClass();

	SoXipBoundingBox::initClass();
	SoXipTrackballToMouse::initClass();
	SoXipWindowSize::initClass();
	SoXipMouseToggle::initClass();
	SoXipClipPlane::initClass();
	SoXipPerformance::initClass();
	SoXipPerformanceCounter::initClass();
	SoXipConvertMatrixToPlane::initClass();
	SoXipConvertToEnum::initClass();
    SoXipAutoScale::initClass();
    SoXipBackground::initClass();
	SoXipAnchor::initClass();

	SoXipGetImage::initClass();
	SoXipImageExaminerBase::initClass();
	SoXipImageExaminer::initClass();    
	SoXipComposeMFImage::initClass();
	SoXipDecomposeMFImage::initClass();
	SoXipExtractSlice::initClass();
	SoXipImageText::initClass();
	SoXipIncrement::initClass();
    SoXipStringConcatenate::initClass();
	SoXipConvertMFImageToSFImage::initClass();
	SoXipConvertSFImageToMFImage::initClass();
	SoXipImageOperation::initClass();
	SoXipSwitchMFDataImage::initClass();

	return 1;
}


//#ifdef linux
#ifndef WIN32

static int initted = FALSE;    // a little protection--probably unnecessary
void __attribute__ ((constructor)) _init(void)// don't write this if DllMain is to be used
{

    int err;

  	
	if (SoDB::isInitialized())
        {
            // automatic initialization for dynamic loading
            xipivcore_init();
        }
    

    initted = TRUE;
    //return 0;
}

void __attribute__ ((destructor)) _fini(void)
{
   //printf ("fini print.\n");
}

#endif
#ifdef WIN32
BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD reason, LPVOID)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        if (SoDB::isInitialized())
        {
            // automatic initialization for dynamic loading
            xipivcore_init();
        }
    }

    return TRUE;
}
#endif