#ifndef _DOGE_LOG_H_
#define _DOGE_LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdio.h>


enum log_level {
    DOGE_LOG_LEVEL_TRACE = 0,
    DOGE_LOG_LEVEL_INFO  = 1,
    DOGE_LOG_LEVEL_WARN  = 2,
    DOGE_LOG_LEVEL_ERROR = 3, 
    DOGE_LOG_LEVEL_NONE  = 4, 
    DOGE_LOG_LEVEL_NUM   = 5,
};
typedef  int8_t   doge_log_level_t;

#ifndef USE_DOGE_LOG
    #define USE_DOGE_LOG     1
#endif

#if USE_DOGE_LOG

#ifndef USE_PRINT_LOG
    #define USE_PRINT_LOG    1
#endif

#ifndef USE_LOCK_LOG    
    #define USE_LOCK_LOG     0
#endif


void doge_log_add(doge_log_level_t level, const char * file, int line,  const char *fmt, ...);

#define DOGE_LOG_TRACE(...) doge_log_add(DOGE_LOG_LEVEL_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define DOGE_LOG_INFO(...)  doge_log_add(DOGE_LOG_LEVEL_INFO, __FILE__, __LINE__,  __VA_ARGS__)
#define DOGE_LOG_WARN(...)  doge_log_add(DOGE_LOG_LEVEL_WARN, __FILE__, __LINE__,  __VA_ARGS__)
#define DOGE_LOG_ERROR(...) doge_log_add(DOGE_LOG_LEVEL_ERROR, __FILE__, __LINE__, __VA_ARGS__)

#else

#define DOGE_LOG_TRACE(...)   
#define DOGE_LOG_INFO(...)  
#define DOGE_LOG_WARN(...)  
#define DOGE_LOG_ERROR(...) 

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif 
