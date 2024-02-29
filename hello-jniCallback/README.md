# Hello JNI Callback

This sample is an add-on to Hello JNI sample to demonstrate calling back to Java
from C code

- create a java class instance from C code
- call java class static and non-static member functions

This sample uses the new
[Android Studio CMake plugin](http://tools.android.com/tech-docs/external-c-builds)
with C++ support.

## Pre-requisites

- Android Studio 2.2+ with [NDK](https://developer.android.com/ndk/) bundle.

## Getting Started

1. [Download Android Studio](http://developer.android.com/sdk/index.html)
2. Set up the [WASM-NDK toolchain](https://github.com/AndroidWasm/wasm_ndk)
3. Manually compile the C++ code to WASM:

   ```
   cd app/src/main/cpp
   mkdir build_wasm
   cd build_wasm
   cmake --toolchain $WASM_NDK/cmake/toolchain/android_wasm.toolchain.cmake ..
   cmake --build .
   ```

4. Run `wasm2c` (still from within `build_wasm`):

   ```
   $WABT_HOME/bin/wasm2c --experimental --enable-memory64 --disable-sandbox \
   hello-jnicallback -o hello-jnicallback_generated.c
   ```

5. Set `WABT_HOME` and then launch Android Studio.
6. Open the sample directory.
7. Open *File/Project Structure...*

- Click *Download* or *Select NDK location*.

8. Click *Tools/Android/Sync Project with Gradle Files*.
9. Click *Run/Run 'app'*.

## Screenshots

![screenshot](screenshot.png)

## Support

If you've found an error in these samples, please
[file an issue](https://github.com/googlesamples/android-ndk/issues/new).

Patches are encouraged, and may be submitted by
[forking this project](https://github.com/googlesamples/android-ndk/fork) and
submitting a pull request through GitHub. Please see
[CONTRIBUTING.md](../CONTRIBUTING.md) for more details.

- [Stack Overflow](http://stackoverflow.com/questions/tagged/android-ndk)
- [Android Tools Feedbacks](http://tools.android.com/feedback)

## License

Copyright 2015 Google, Inc.

Licensed to the Apache Software Foundation (ASF) under one or more contributor
license agreements. See the NOTICE file distributed with this work for
additional information regarding copyright ownership. The ASF licenses this file
to you under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of the
License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.
