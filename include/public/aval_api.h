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

#ifndef AVAL_API_H
#define AVAL_API_H

#include "aval_audio.h"
#include "aval_video.h"
#include "aval_settings.h"

class AVAL {

private:
	static AVAL* _instance;

public:

	AVAL_Audio* audio;
	AVAL_Video* video;
	AVAL_ControlSettings* controls;

	static AVAL* getInstance();

	virtual ~AVAL() = default;

	virtual bool initialize() = 0;
	virtual bool deinitialize() = 0;
};

#endif //AVAL_API_H
