#
# Copyright (C) The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 3.5)
project(TeapotNativeActivity LANGUAGES C CXX)

# set up common compile options
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Werror -fno-exceptions -fno-rtti")

get_filename_component(commonDir ${CMAKE_CURRENT_SOURCE_DIR}/../../../../common ABSOLUTE)
get_filename_component(ndkHelperSrc ${commonDir}/ndk_helper ABSOLUTE)

if (ANDROID_WASM)

add_compile_options(-O3)
add_compile_options(-fno-unroll-loops)

# Workaround
add_compile_options(-Wno-unused-command-line-argument)
add_link_options(-Wno-unused-command-line-argument)

# For wasm-ld only
# Export ANativeActivity_onCreate()
add_link_options(-Wl,--export=ANativeActivity_onCreate)
add_link_options(-Wl,--strip-debug)

# For wasm we add everything to one project
add_executable(${PROJECT_NAME}
        TeapotNativeActivity.cpp
        TeapotRenderer.cpp
        ${ndkHelperSrc}/gestureDetector.cpp
        ${ndkHelperSrc}/gl3stub.cpp
        ${ndkHelperSrc}/GLContext.cpp
        ${ndkHelperSrc}/interpolator.cpp
        ${ndkHelperSrc}/JNIHelper.cpp
        ${ndkHelperSrc}/perfMonitor.cpp
        ${ndkHelperSrc}/sensorManager.cpp
        ${ndkHelperSrc}/shader.cpp
        ${ndkHelperSrc}/tapCamera.cpp
        ${ndkHelperSrc}/vecmath.cpp
        ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${ANDROID_NDK}/sources/android/native_app_glue
        ${ndkHelperSrc}
)

target_link_libraries(${PROJECT_NAME}
    android
    GLESv2
    EGL
    log
    c++
    m
    dl
)

else()

// Set this to 0 to get the original native build.
set(GENERATED_BUILD 1)

if (GENERATED_BUILD)

add_library(${PROJECT_NAME}
  SHARED
    build_wasm/${PROJECT_NAME}_generated.c)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    $ENV{WABT_HOME}/wasm2c)

target_link_libraries(${PROJECT_NAME}
    android
    GLESv2
    EGL
    log
    c++
    m
    dl)

set_target_properties(${PROJECT_NAME}
  PROPERTIES  LINK_FLAGS "-u ANativeActivity_onCreate")

else()

# build the ndk-helper library
add_subdirectory(${ndkHelperSrc}
        ${commonDir}/ndkHelperBin/${CMAKE_BUILD_TYPE}/${ANDROID_ABI})

# now build app's shared lib
add_library(${PROJECT_NAME}
  SHARED
    TeapotNativeActivity.cpp
    TeapotRenderer.cpp
)
set_target_properties(${PROJECT_NAME}
  PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# Export ANativeActivity_onCreate(),
# Refer to: https://github.com/android-ndk/ndk/issues/381.
set_target_properties(${PROJECT_NAME}
  PROPERTIES  LINK_FLAGS "-u ANativeActivity_onCreate")

# add lib dependencies
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    NdkHelper
)

endif()

endif()
