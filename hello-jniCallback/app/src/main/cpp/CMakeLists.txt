cmake_minimum_required(VERSION 3.4.1)

if (ANDROID_WASM)

add_compile_options(-O3)
add_compile_options(-fno-unroll-loops)
add_link_options(-Wl,--strip-debug)
add_link_options(-Wl,--export-dynamic)

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
