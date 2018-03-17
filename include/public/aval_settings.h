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

#ifndef AVAL_CONTROLS_API_H
#define AVAL_CONTROLS_API_H

#include  <string>

#define SHARPNESS_Control "sharpness"
#define PQ_Control "pq"
#define Volume_Control "volume"
#define BLACK_LEVEL_Control "black_level"


typedef enum
{
	AVAL_VPQ_INPUT_ATV = 0,                 ///< analog rf
	AVAL_VPQ_INPUT_AV,                      ///< cvbs,svideo
	AVAL_VPQ_INPUT_SCARTRGB,                ///< scart-rgb
	AVAL_VPQ_INPUT_COMP,                    ///< component
	AVAL_VPQ_INPUT_RGB_PC,                  ///< rgb-pc
	AVAL_VPQ_INPUT_HDMI_TV,                 ///< hdmi non-pc(hdmi-av,dvi-dtv,mcam)
	AVAL_VPQ_INPUT_HDMI_PC,                 ///< hdmi pc(dvi-pc)
	AVAL_VPQ_INPUT_DTV,                     ///< digital rf
	AVAL_VPQ_INPUT_PICWIZ,                  ///< dtv pic wiz
	AVAL_VPQ_INPUT_PICTEST,                 ///< dtv pic test
	AVAL_VPQ_INPUT_MEDIA_MOVIE,             ///< divx, cp-divx
	AVAL_VPQ_INPUT_MEDIA_PHOTO,             ///< photo, cp-photo
	AVAL_VPQ_INPUT_CAMERA,                  ///< vcs
	AVAL_VPQ_INPUT_PVR_DTV,                 ///< pvr dtv
	AVAL_VPQ_INPUT_PVR_ATV,                 ///< pvr atv
	AVAL_VPQ_INPUT_PVR_AV,                  ///< pvr av,scart-rgb
	AVAL_VPQ_INPUT_MAX                      ///< max num
} AVAL_VPQ_INPUT_T;

class AVAL_ControlSettings
{

public:
	virtual ~AVAL_ControlSettings() = default;
	virtual bool configureVideoSettings(const std::string ctrl, const AVAL_VIDEO_WID_T winID, const int32_t []) = 0;
	virtual bool configureSoundSettings(const std::string ctrl, const std::string ) = 0;
	virtual bool configureSoundSettings(const std::string ctrl, const int32_t [] ) = 0;
};

#endif //AVAL_CONTROLS_API_H
