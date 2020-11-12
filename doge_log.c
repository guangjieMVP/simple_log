#include "doge_log.h"
#include "stdarg.h"


#if USE_DOGE_LOG

extern void doge_log_lock(void);
extern void doge_log_unlock(void);
extern void doge_log_output(doge_log_level_t level, const char * file, int line, char *str);


void doge_log_add(doge_log_level_t level, const char * file, int line,  const char *fmt, ...)
{
    va_list args;
    
    if(level >= DOGE_LOG_LEVEL_NUM) return; 

#if USE_LOCK_LOG
    doge_log_lock();
#endif
    
    va_start(args, fmt); 
    
#if USE_PRINT_LOG
    static const char *level_prefix[] = {"[Trace]>>", "[Info]>>", "[Warn]>>", "[Error]>>"};
    printf("%s ", level_prefix[level]);
    vfprintf(stdout, fmt, args);
    printf("\t(%s #%d)\n", file, line);
#else
    char buf[2048];  
    vsprintf(buf, fmt, args);
    doge_log_output(level, file, line, buf);
#endif
    va_end(args);
    
#if USE_LOCK_LOG    
    doge_log_unlock();
#endif
}


#endif /* USE_DOGE_LOG */
