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
include_HEADERS = xraudio_config.json
lib_LTLIBRARIES = libxraudio.la
libxraudio_la_SOURCES = xraudio_ver.h               \
                        xraudio.c                   \
                        xraudio_input.c             \
                        xraudio_output.c            \
                        xraudio_thread.c            \
                        xraudio_utils.c             \
                        xraudio_atomic.c

if XRAUDIO_RESOURCE_MGMT
libxraudio_la_SOURCES += xraudio_resource.c
endif

if MICROPHONE_TAP_ENABLED
libxraudio_la_CFLAGS  = -DMICROPHONE_TAP_ENABLED
endif

libxraudio_la_LDFLAGS = -Wl,-whole-archive -lxraudio-hal -Wl,-no-whole-archive

noinst_PROGRAMS      = xraudio_main
xraudio_main_SOURCES = xraudio_main.c
xraudio_main_LDFLAGS = -lc -lxraudio

# Dependency to build shared lib before exe
xraudio_main.c: libxraudio.la

BUILT_SOURCES = xraudio_ver.h xraudio_config.h xraudio_config.json
CLEANFILES    = xraudio_ver.h xraudio_config.h xraudio_config.json

xraudio_ver.h:
	echo "#define XRAUDIO_VER_MAJOR \"1\"" >$@
	echo "#define XRAUDIO_VER_MINOR \"`git -C ${srcdir} rev-list --count ce72b5fca802807d5a577192f132aad34754b94d..HEAD``git -C ${srcdir} diff --quiet || echo \"++\"`\"" >>$@
	echo "#define XRAUDIO_BRANCH    \"${GIT_BRANCH}\"" >>$@
	echo "#define XRAUDIO_COMMIT_ID \"`git -C ${srcdir} log --format="%H" -n 1`\"" >>$@
	echo "#define XRAUDIO_VERSION (XRAUDIO_VER_MAJOR \".\" XRAUDIO_VER_MINOR)" >>$@

xraudio_config.json: xraudio_config_default.json
	python3 "${VSDK_UTILS_JSON_COMBINE}" -i $< -a "${XRAUDIO_CONFIG_JSON_HAL}:hal" -a "${XRAUDIO_CONFIG_JSON_KWD}:input,kwd" -a "${XRAUDIO_CONFIG_JSON_EOS}:input,eos" -a "${XRAUDIO_CONFIG_JSON_DGA}:input,dga" -a "${XRAUDIO_CONFIG_JSON_SDF}:input,sdf" -a "${XRAUDIO_CONFIG_JSON_OVC}:output,ovc" -a "${XRAUDIO_CONFIG_JSON_PPR}:input,ppr" -s "${XRAUDIO_CONFIG_JSON_SUB}" -a "${XRAUDIO_CONFIG_JSON_ADD}" -o $@

xraudio_config.h: xraudio_config.json
	python3 "${VSDK_UTILS_JSON_TO_HEADER}" -i $< -o $@ -m 2
