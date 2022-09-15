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
AC_INIT([xraudio], [1.0], [David_Wolaver@cable.comcast.com])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_PROG_AR
LT_INIT

AC_PROG_CC

AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
])

AC_ARG_ENABLE([rdkxlogger],
[  --enable-rdkxlogger    Turn on RDKX logger support],
[case "${enableval}" in
  yes) rdkxlogger=true ;;
  no)  rdkxlogger=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-rdkxlogger]) ;;
esac],[rdkxlogger=false])
AM_CONDITIONAL([RDKX_LOGGER_ENABLED], [test x$rdkxlogger = xtrue])

AC_ARG_ENABLE([resourcemgmt],
[  --enable-resourcemgmt    Turn on resource manangement support],
[case "${enableval}" in
  yes) resourcemgmt=true ;;
  no)  resourcemgmt=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-resourcemgmt]) ;;
esac],[resourcemgmt=false])
AM_CONDITIONAL([XRAUDIO_RESOURCE_MGMT], [test x$resourcemgmt = xtrue])

AC_ARG_ENABLE([mic_tap],
[  --enable-mic_tap    Turn on Microphone Tap support],
[case "${enableval}" in
  yes) mic_tap=true ;;
  no)  mic_tap=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-mic_tap]) ;;
esac],[mic_tap=false])
AM_CONDITIONAL([MICROPHONE_TAP_ENABLED], [test x$mic_tap = xtrue])

AC_ARG_VAR(VSDK_UTILS_JSON_TO_HEADER, script to create header from json object)
AC_ARG_VAR(VSDK_UTILS_JSON_COMBINE,   script to combine multiple json files)

AC_ARG_VAR(XRAUDIO_CONFIG_JSON_HAL, hal json configuration file)
AC_ARG_VAR(XRAUDIO_CONFIG_JSON_KWD, keyword detector json configuration file)
AC_ARG_VAR(XRAUDIO_CONFIG_JSON_EOS, end of speech json configuration file)
AC_ARG_VAR(XRAUDIO_CONFIG_JSON_DGA, dynamic gain adjustment json configuration file)
AC_ARG_VAR(XRAUDIO_CONFIG_JSON_SDF, sound focus json configuration file)
AC_ARG_VAR(XRAUDIO_CONFIG_JSON_OVC, output volume control json configuration file)
AC_ARG_VAR(XRAUDIO_CONFIG_JSON_PPR, pre-processor json configuration file)
AC_ARG_VAR(XRAUDIO_CONFIG_JSON_SUB, oem sub json configuration file)
AC_ARG_VAR(XRAUDIO_CONFIG_JSON_ADD, oem add json configuration file)
AC_ARG_VAR(GIT_BRANCH, git branch name)

AC_OUTPUT
