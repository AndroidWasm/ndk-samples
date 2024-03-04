cmake_minimum_required(VERSION 3.4.1)

if (ANDROID_WASM)

add_compile_options(-O3)
add_compile_options(-fno-unroll-loops)


# For wasm-ld only
add_link_options(-Wl,--strip-debug)

# Explicitly list exported symbols for now (until clang, and wasm-ld, and wasm2c get
# their collective act together so that JNIEXPORT works).
add_link_options(-Wl,--export=Java_com_example_hellojnicallback_MainActivity_stringFromJNI)
add_link_options(-Wl,--export=JNI_OnLoad)
add_link_options(-Wl,--export=Java_com_example_hellojnicallback_MainActivity_startTicks)
add_link_options(-Wl,--export=Java_com_example_hellojnicallback_MainActivity_StopTicks)

add_executable(hello-jnicallback
               hello-jnicallback.c)

else()

add_library(hello-jnicallback SHARED
            build_wasm/hello-jnicallback_generated.c)

target_include_directories(hello-jnicallback PRIVATE
                           $ENV{WABT_HOME}/wasm2c)

endif()

# Include libraries needed for hello-jnicallback lib
target_link_libraries(hello-jnicallback
                      android
                      log)
