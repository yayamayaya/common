#ifndef LOG_FUNC
#define LOG_FUNC

#include <stdio.h>

#ifdef DEBUG

#define _INIT_LOG() FILE *log_file = NULL;

#define _OPEN_LOG(arg)                                      \
    log_file = fopen(arg, "wb");                            \
    if (!log_file)                                          \
        printf("[error]> couldn't open logfile %s.\n", arg);\
                                                            \
    setbuf(log_file, NULL)

#define LOG(...)\
    if (log_file)\
        fprintf(log_file, __VA_ARGS__)

#define _CLOSE_LOG()\
    if (log_file)\
    {\
        LOG("> closing logfile\n");\
        fclose(log_file);\
        log_file = NULL;\
    }
#else
#define _INIT_LOG() do{}while(0)
#define _OPEN_LOG(arg) do{}while(0)
#define LOG(...) do{}while(0)
#define _CLOSE_LOG() do{}while(0)
#endif

enum LOG_ERRS
{
    ERR     = 1,
    NO_ERR  = 0,
};
    
    

#endif