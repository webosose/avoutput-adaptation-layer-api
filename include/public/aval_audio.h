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

#ifndef AVAL_AUDIO_API_H
#define AVAL_AUDIO_API_H

#include <cstdint>
#include "aval_common.h"

typedef uint8_t AVAL_AUDIO_VOLUME_T;
typedef uint8_t SpeakerVolume;
static const SpeakerVolume MIN_VOLUME = 0;
static const SpeakerVolume MAX_VOLUME = 100;

/**
 * AVAL AUDIO Resources.
 */
typedef  enum
{
	AVAL_AUDIO_RESOURCE_SDEC0                        =  0,
	AVAL_AUDIO_RESOURCE_SDEC1                        =  1,
	AVAL_AUDIO_RESOURCE_ATP0                         =  2,
	AVAL_AUDIO_RESOURCE_ATP1                         =  3,
	AVAL_AUDIO_RESOURCE_ADC                          =  4,
	AVAL_AUDIO_RESOURCE_HDMI                         =  5,
	AVAL_AUDIO_RESOURCE_AAD                          =  6,
	AVAL_AUDIO_RESOURCE_SYSTEM                       =  7,   /* Clip or LMF Play */
	AVAL_AUDIO_RESOURCE_ADEC0                        =  8,
	AVAL_AUDIO_RESOURCE_ADEC1                        =  9,
	AVAL_AUDIO_RESOURCE_AENC0                        = 10,
	AVAL_AUDIO_RESOURCE_AENC1                        = 11,
	AVAL_AUDIO_RESOURCE_SE                           = 12,
	AVAL_AUDIO_RESOURCE_OUT_SPK                      = 13,   /* Speaker */
	AVAL_AUDIO_RESOURCE_OUT_SPDIF                    = 14,   /* SPDIF Ouput */
	AVAL_AUDIO_RESOURCE_OUT_SB_SPDIF                 = 15,   /* Sound Bar(SPDIF) : Mixer Output */
	AVAL_AUDIO_RESOURCE_OUT_SB_PCM                   = 16,   /* Sound Bar(PCM)   : Mixer Output(Wireless) */
	AVAL_AUDIO_RESOURCE_OUT_SB_CANVAS                = 17,   /* Sound Bar(CANVAS): Sound Engine Output */
	AVAL_AUDIO_RESOURCE_OUT_HP                       = 18,   /* Must be controlled by audio decoder.*/
	AVAL_AUDIO_RESOURCE_OUT_SCART                    = 19,   /* Must be controlled by audio decoder.*/
	AVAL_AUDIO_RESOURCE_MIXER0                       = 20,   /* Audio Mixer Input 0. */
	AVAL_AUDIO_RESOURCE_MIXER1                       = 21,   /* Audio Mixer Input 1. */
	AVAL_AUDIO_RESOURCE_MIXER2                       = 22,   /* Audio Mixer Input 2. */
	AVAL_AUDIO_RESOURCE_MIXER3                       = 23,   /* Audio Mixer Input 3. */
	AVAL_AUDIO_RESOURCE_MIXER4                       = 24,   /* Audio Mixer Input 4. */
	AVAL_AUDIO_RESOURCE_MIXER5                       = 25,   /* Audio Mixer Input 5. */
	AVAL_AUDIO_RESOURCE_MIXER6                       = 26,   /* Audio Mixer Input 6. */
	AVAL_AUDIO_RESOURCE_MIXER7                       = 27,   /* Audio Mixer Input 7. */
	AVAL_AUDIO_RESOURCE_OUT_SPDIF_ES                 = 28,   /* SPDIF ES Ouput Only */
	AVAL_AUDIO_RESOURCE_HDMI0                        = 29,   /* Audio HDMI Input 0. */
	AVAL_AUDIO_RESOURCE_HDMI1                        = 30,   /* Audio HDMI Input 1. */
	AVAL_AUDIO_RESOURCE_HDMI2                        = 31,   /* Audio HDMI Input 2. */
	AVAL_AUDIO_RESOURCE_HDMI3                        = 32,   /* Audio HDMI Input 3. */
	AVAL_AUDIO_RESOURCE_SWITCH                       = 33,   /* Audio HDMI Input with switch. */
	AVAL_AUDIO_RESOURCE_NO_CONNECTION                = 0XFF,
} AVAL_AUDIO_RESOURCE_T;

/**
 * AVAL AUDIO Sound Output Mode.
 */
typedef  enum
{
        AVAL_AUDIO_NO_OUTPUT             = 0x00,
        AVAL_AUDIO_SPK                   = 0x01,
        AVAL_AUDIO_SPDIF                 = 0x02,
        AVAL_AUDIO_SB_SPDIF              = 0x04,
        AVAL_AUDIO_SB_PCM                = 0x08,
        AVAL_AUDIO_SB_CANVAS             = 0x10,
        AVAL_AUDIO_HP                    = 0x20,
        AVAL_AUDIO_SCART                 = 0x40,
        AVAL_AUDIO_SPDIF_ES              = 0x80,
} AVAL_AUDIO_SNDOUT_T;

typedef enum
{
	AVAL_AUDIO_SPDIF_NONE           = 0,
	AVAL_AUDIO_SPDIF_PCM            = 1,
	AVAL_AUDIO_SPDIF_AUTO           = 2,
	AVAL_AUDIO_SPDIF_AUTO_AAC       = 3,
	AVAL_AUDIO_SPDIF_MIXED_DD       = 4,    /* Google Mixed DD(AC3 Encoding) */
} AVAL_AUDIO_SPDIF_MODE_T ;

typedef enum
{
	AVAL_ERROR_NONE,
	AVAL_OUTPUT_NOT_SUPPORTED,
	AVAL_ERROR_FAIL
} AVAL_ERROR;

class AVAL_Audio {

public:

	virtual ~AVAL_Audio() = default;

	virtual bool connectInput(AVAL_AUDIO_RESOURCE_T audioResourceId, int16_t *port) = 0;
	virtual bool disconnectInput(AVAL_AUDIO_RESOURCE_T audioResourceId) = 0;
	virtual bool connectOutput(AVAL_AUDIO_SNDOUT_T outputType, AVAL_AUDIO_RESOURCE_T currentConnect, AVAL_AUDIO_RESOURCE_T outputConnect) = 0;
	virtual bool disconnectOutput(AVAL_AUDIO_SNDOUT_T outputType, AVAL_AUDIO_RESOURCE_T currentConnect, AVAL_AUDIO_RESOURCE_T outputConnect) = 0;
	virtual bool setMute(AVAL_AUDIO_RESOURCE_T audioResourceId, bool mute) = 0;
	virtual AVAL_ERROR setOutputMode(AVAL_AUDIO_SNDOUT_T outputType, AVAL_AUDIO_SPDIF_MODE_T spdifMode) = 0;
	virtual AVAL_ERROR setOutputVolume(AVAL_AUDIO_SNDOUT_T outputType, AVAL_AUDIO_VOLUME_T volume) = 0;
	virtual AVAL_ERROR setOutputMute(AVAL_AUDIO_SNDOUT_T outputType, bool mute) = 0;
};

#endif //AVAL_AUDIO_API_H
