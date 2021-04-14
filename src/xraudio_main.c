/*
##########################################################################
# If not stated otherwise in this file or this component's LICENSE
# file the following copyright and licenses apply:
#
# Copyright 2019 RDK Management
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
##########################################################################
*/
#include <stdio.h>
#include <stdlib.h>
#include "xraudio.h"

int main(int argc, char* argv[]) {
   printf("%s: Create\n", __FUNCTION__);  xraudio_object_t obj = xraudio_object_create(NULL);
   printf("%s: Open\n", __FUNCTION__);    xraudio_open(obj, XRAUDIO_POWER_MODE_FULL, false, XRAUDIO_DEVICE_INPUT_QUAD, XRAUDIO_DEVICE_OUTPUT_NORMAL, NULL);
   printf("%s: Play\n", __FUNCTION__);    xraudio_play_from_file(obj, "/usr/share/xraudio_test_sound_lib/MorseCode-SoundBible.com-810471357_22050_mono.wav", NULL, NULL);
   printf("%s: Stop\n", __FUNCTION__);    xraudio_play_stop(obj);
   printf("%s: Close\n", __FUNCTION__);   xraudio_close(obj);
   printf("%s: Destroy\n", __FUNCTION__); xraudio_object_destroy(obj);
}
