// Copyright (c) 2017-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef AVAL_VIDEO_API_H
#define AVAL_VIDEO_API_H

#include "aval_common.h"
#include <string>
#include <vector>

typedef enum
{
	AVAL_VSC_INPUTSRC_AVD = 0,
	AVAL_VSC_INPUTSRC_ADC,
	AVAL_VSC_INPUTSRC_HDMI,
	AVAL_VSC_INPUTSRC_VDEC,
	AVAL_VSC_INPUTSRC_JPEG,
	AVAL_VSC_INPUTSRC_MAX = AVAL_VSC_INPUTSRC_JPEG,
	AVAL_VSC_INPUTSRC_MAXN,
} AVAL_VSC_INPUT_TYPE_T;

typedef enum
{
	AVAL_VIDEO_WID_MIN  = 0,            /**< WID min */
	AVAL_VIDEO_WID_0    = AVAL_VIDEO_WID_MIN,   /**< WID main window */
	AVAL_VIDEO_WID_1,                  /**< WID sub window */
	AVAL_VIDEO_WID_2,
	AVAL_VIDEO_WID_3,
	AVAL_VIDEO_WID_MAX  = AVAL_VIDEO_WID_3,    /**< WID max */
	AVAL_VIDEO_WID_MAXN,                /**< WID max number */
} AVAL_VIDEO_WID_T;

typedef enum
{
	AVAL_VSC_OUTPUT_DISPLAY_MODE = 0,
	AVAL_VSC_OUTPUT_VENC_MODE,
	AVAL_VSC_OUTPUT_MEMORY_MODE,
	AVAL_VSC_OUTPUT_AVE_MODE,
	AVAL_VSC_OUTPUT_MAX = AVAL_VSC_OUTPUT_AVE_MODE,
	AVAL_VSC_OUTPUT_MAXN,
} AVAL_VSC_OUTPUT_MODE_T;

typedef struct AVAL_VSC_INPUT_SRC_INFO
{
	AVAL_VSC_INPUT_TYPE_T type;
	UINT8 attr;
	UINT8 resourceIndex;
} AVAL_VSC_INPUT_SRC_INFO_T;

typedef struct
{
	UINT16		x;	/**< horizontal Start Position in pixel [0,].*/
	UINT16		y;	/**< vertical	Start Position in pixel [0,].*/
	UINT16		w;	/**< horizontal Size(Width)    in pixel [0,].*/
	UINT16		h;	/**< vertical	Size(Height)   in pixel [0,].*/
} AVAL_VIDEO_RECT_T;

typedef struct
{
	AVAL_VIDEO_WID_T wId; // 0: bottom, 1: bottom+1,..
	UINT8 uAlpha; // 0 ~ 255
	AVAL_VIDEO_RECT_T inputRegion;
	AVAL_VIDEO_RECT_T outputRegion;
} AVAL_WINDOW_INFO_T;

/**
 * HDMI Timing Information.
 *
 * @see DDI Implementation Guide
*/
/*typedef struct
{
	UINT32 format;
	UINT16 hFreq;
	UINT16 vFreq;
	UINT16 hTotal;
	UINT16 vTotal;
	UINT16 hPorch;
	UINT16 vPorch;
	AVAL_VFE_HDMI_RECT_T	active;
	UINT16 scanType;
	UINT8  mode;
	UINT8  isDolbyHDR;

	AVAL_VFE_HDMI_3D_FORMAT_TYPE_T full_3d_timing;	// 3D format information base on timing info
	AVAL_VFE_HDMI_3D_LR_TYPE_T	video_LR_order;

} AVAL_VFE_HDMI_TIMING_INFO_T;*/

typedef struct
{
public:
	UINT16 w=0;
	UINT16 h=0;

} AVAL_VIDEO_SIZE_T;

typedef struct
{
public:
	AVAL_VIDEO_WID_T wId;
	std::string planeName;
	AVAL_VIDEO_SIZE_T minSizeT;
	AVAL_VIDEO_SIZE_T maxSizeT;
} AVAL_PLANE_T;

class AVAL_Video {

public:

	virtual ~AVAL_Video() = default;
	virtual bool connect(AVAL_VIDEO_WID_T wId, AVAL_VSC_INPUT_SRC_INFO_T vscInput, AVAL_VSC_OUTPUT_MODE_T outputmode, unsigned int *planeId) = 0;
	virtual bool disconnect(AVAL_VIDEO_WID_T wId, AVAL_VSC_INPUT_SRC_INFO_T vscInput, AVAL_VSC_OUTPUT_MODE_T outputmode) = 0;
	virtual bool applyScaling(AVAL_VIDEO_WID_T wId, AVAL_VIDEO_RECT_T srcInfo, bool adaptive, AVAL_VIDEO_RECT_T inputRegion, AVAL_VIDEO_RECT_T outputRegion) = 0;
	virtual bool setDualVideo(bool enable) = 0;
	virtual bool setCompositionParams(std::vector<AVAL_WINDOW_INFO_T> zOrder) = 0;
	virtual bool setWindowBlanking(AVAL_VIDEO_WID_T wId, bool blank, AVAL_VIDEO_RECT_T inputRegion, AVAL_VIDEO_RECT_T outputRegion) = 0;

	//Device Capabilities
	virtual AVAL_VIDEO_RECT_T getDisplayResolution() = 0;
	virtual bool getVideoCapabilities(AVAL_VIDEO_SIZE_T &minDownscaleSize, AVAL_VIDEO_SIZE_T& maxUpscaleSize) = 0;
	virtual std::vector<AVAL_PLANE_T> getVideoPlanes() {return std::vector<AVAL_PLANE_T>();};
	virtual std::vector<AVAL_VIDEO_SIZE_T> getSupportedResolutions() = 0;
	virtual bool setDisplayResolution(AVAL_VIDEO_SIZE_T) = 0;
	//AVAL_VFE_HDMI_TIMING_INFO_T* readHdmiTimingInfo(uint8_t sourcePort);

};

#endif //AVAL_VIDEO_API_H
