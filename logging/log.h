#ifndef LOG_FUNC
#define LOG_FUNC

#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

#ifdef DEBUG

#define _INIT_LOG() static FILE *log_file = NULL;

#define _OPEN_LOG(arg)                                      \
    log_file = fopen(arg, "wb");                            \
    if (!log_file)                                          \
        {printf("[error]> couldn't open logfile %s.\n", arg);}\
                                                            \
    setbuf(log_file, NULL)

#define _OPEN_N_LOG(format)                                             \
    static int log_num = 0;                                             \
    char log_name[200] = {};                                            \
    snprintf(log_name, sizeof(log_name), format, log_num);              \
    log_num++;                                                          \
    _OPEN_LOG(log_name)

#define _OPEN_A_LOG(arg)                                      \
    log_file = fopen(arg, "ab");                            \
    if (!log_file)                                          \
        {printf("[error]> couldn't open logfile %s.\n", arg);}\
                                                            \
    setbuf(log_file, NULL)

#define LOG(...)\
    if (log_file)\
        fprintf(log_file, __VA_ARGS__)

#define W_LOG(...)\
    if (log_file)\
        fwprintf(log_file, __VA_ARGS__)

#define _CLOSE_LOG()\
    if (log_file)\
    {\
        LOG("> closing logfile\n");\
        fclose(log_file);\
        log_file = NULL;\
    }


#else
#define _INIT_LOG() 
#define _OPEN_LOG(arg) do{}while(0)
#define _OPEN_A_LOG(arg)
#define _OPEN_N_LOG(format)
#define LOG(...) do{}while(0)
#define W_LOG(...) do{}while(0)
#define _CLOSE_LOG() do{}while(0)
#endif

#define _CLEAR_LOGS()\
    system("rm logs/*")

enum LOG_ERRS
{
    ERR     = 1,
    NO_ERR  = 0,
};

#endif
