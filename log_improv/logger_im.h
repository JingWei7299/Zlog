
#ifndef _LOGGER_H_
#define _LOGGER_H_

#include<stdarg.h>

#ifdef __cplusplus
extern "C"
{
#endif


typedef enum
{
    ZJW_LOG_LEVEL_INFO,
    ZJW_LOG_LEVEL_WARNING,
    ZJW_LOG_LEVEL_DEBUG,
    ZJW_LOG_LEVEL_ERROR,
}ZJW_LOG_LEVEL;

bool log_init();//初始化日志系统
void log_uninit();//反初始化日志系统
void logwrite(ZJW_LOG_LEVEL level, const char* file_name,int line, const char* format, ...);

#define ZJW_LOG_INFO(format,...)    logwrite(ZJW_LOG_LEVEL_INFO,__FILE__,__LINE__,format,##__VA_ARGS__)
#define ZJW_LOG_WARNING(format,...) logwrite(ZJW_LOG_LEVEL_WARNING,__FILE__,__LINE__,format,##__VA_ARGS__)
#define ZJW_LOG_DEBUG(format,...)   logwrite(ZJW_LOG_LEVEL_DEBUG,__FILE__,__LINE__,format,##__VA_ARGS__)
#define ZJW_LOG_ERROR(format,...)   logwrite(ZJW_LOG_LEVEL_ERROR,__FILE__,__LINE__,format,##__VA_ARGS__)

#define LOG_INIT   log_init
#define LOG_UNINIT log_uninit



#ifdef __cplusplus
}
#endif


#endif

