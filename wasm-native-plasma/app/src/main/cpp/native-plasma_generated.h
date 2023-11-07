/* Automatically generated by wasm2c */
#ifndef _NATIVE_PLASMA_GENERATED_H_GENERATED_
#define _NATIVE_PLASMA_GENERATED_H_GENERATED_

#define NO_SANDBOX 1

#include "wasm-rt-no-sandbox.h"

#if defined(WASM_RT_ENABLE_SIMD)
#include "simde/wasm/simd128.h"
#endif

/* TODO(binji): only use stdint.h types in header */
#ifndef WASM_RT_CORE_TYPES_DEFINED
#define WASM_RT_CORE_TYPES_DEFINED
typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
typedef int64_t s64;
typedef float f32;
typedef double f64;

#if defined(WASM_RT_ENABLE_SIMD)
typedef simde_v128_t v128;
#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NO_SANDBOX
struct w2c_env;

typedef struct w2c_native0x2Dplasma {
  struct w2c_env* w2c_env_instance;
  wasm_rt_memory_t w2c_memory;
  wasm_rt_funcref_table_t w2c_0x5F_indirect_function_table;
} w2c_native0x2Dplasma;

#endif

/* import: 'env' 'AConfiguration_delete' */
void AConfiguration_delete(u64);
/* import: 'env' 'AConfiguration_fromAssetManager' */
void AConfiguration_fromAssetManager(u64, u64);
/* import: 'env' 'AConfiguration_getCountry' */
void AConfiguration_getCountry(u64, u64);
/* import: 'env' 'AConfiguration_getLanguage' */
void AConfiguration_getLanguage(u64, u64);
/* import: 'env' 'AConfiguration_new' */
u64 AConfiguration_new();
/* import: 'env' 'AInputEvent_getType' */
u32 AInputEvent_getType(u64);
/* import: 'env' 'AInputQueue_attachLooper' */
void AInputQueue_attachLooper(u64, u64, u32, u64, u64);
/* import: 'env' 'AInputQueue_detachLooper' */
void AInputQueue_detachLooper(u64);
/* import: 'env' 'AInputQueue_finishEvent' */
void AInputQueue_finishEvent(u64, u64, u32);
/* import: 'env' 'AInputQueue_getEvent' */
u32 AInputQueue_getEvent(u64, u64);
/* import: 'env' 'AInputQueue_preDispatchEvent' */
u32 AInputQueue_preDispatchEvent(u64, u64);
/* import: 'env' 'ALooper_addFd' */
u32 ALooper_addFd(u64, u32, u32, u32, u64, u64);
/* import: 'env' 'ALooper_pollAll' */
u32 ALooper_pollAll(u32, u64, u64, u64);
/* import: 'env' 'ALooper_prepare' */
u64 ALooper_prepare(u32);
/* import: 'env' 'ANativeWindow_getFormat' */
u32 ANativeWindow_getFormat(u64);
/* import: 'env' 'ANativeWindow_getHeight' */
u32 ANativeWindow_getHeight(u64);
/* import: 'env' 'ANativeWindow_getWidth' */
u32 ANativeWindow_getWidth(u64);
/* import: 'env' 'ANativeWindow_lock' */
u32 ANativeWindow_lock(u64, u64, u64);
/* import: 'env' 'ANativeWindow_setBuffersGeometry' */
u32 ANativeWindow_setBuffersGeometry(u64, u32, u32, u32);
/* import: 'env' 'ANativeWindow_unlockAndPost' */
u32 ANativeWindow_unlockAndPost(u64);
/* import: 'env' 'calloc' */
u64 calloc(u64, u64);
/* import: 'env' 'clock_gettime' */
u32 clock_gettime(u32, u64);
/* import: 'env' 'close' */
u32 close(u32);
/* import: 'env' 'free' */
void free(u64);
/* import: 'env' 'gettimeofday' */
u32 gettimeofday(u64, u64);
/* import: 'env' 'malloc' */
u64 malloc(u64);
/* import: 'env' 'memcpy' */
u64 memcpy(u64, u64, u64);
/* import: 'env' 'memset' */
u64 memset(u64, u32, u64);
/* import: 'env' 'pipe' */
u32 pipe(u64);
/* import: 'env' 'pthread_attr_init' */
u32 pthread_attr_init(u64);
/* import: 'env' 'pthread_attr_setdetachstate' */
u32 pthread_attr_setdetachstate(u64, u32);
/* import: 'env' 'pthread_cond_broadcast' */
u32 pthread_cond_broadcast(u64);
/* import: 'env' 'pthread_cond_destroy' */
u32 pthread_cond_destroy(u64);
/* import: 'env' 'pthread_cond_init' */
u32 pthread_cond_init(u64, u64);
/* import: 'env' 'pthread_cond_wait' */
u32 pthread_cond_wait(u64, u64);
/* import: 'env' 'pthread_create' */
u32 pthread_create(u64, u64, u64, u64);
/* import: 'env' 'pthread_mutex_destroy' */
u32 pthread_mutex_destroy(u64);
/* import: 'env' 'pthread_mutex_init' */
u32 pthread_mutex_init(u64, u64);
/* import: 'env' 'pthread_mutex_lock' */
u32 pthread_mutex_lock(u64);
/* import: 'env' 'pthread_mutex_unlock' */
u32 pthread_mutex_unlock(u64);
/* import: 'env' 'read' */
u64 read(u32, u64, u64);
/* import: 'env' 'sin' */
f64 sin(f64);
/* import: 'env' 'strlen' */
u64 strlen(u64);
/* import: 'env' 'write' */
;

/* export: 'ANativeActivity_onCreate' */
#define w2c_native0x2Dplasma_ANativeActivity_onCreate ANativeActivity_onCreate
void w2c_native0x2Dplasma_ANativeActivity_onCreate(u64, u64, u64);

#ifdef __cplusplus
}
#endif

#endif  /* _NATIVE_PLASMA_GENERATED_H_GENERATED_ */