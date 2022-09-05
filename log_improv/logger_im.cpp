
#include"logger_im.h"
#include<iostream>
#include<stdarg.h>
#include<sys/time.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>


static const char* NULL_MAX="The Log is running\n";



static FILE* fp=NULL;
static const char * log_file_name="./mylog.log";



#define LOG(time,info,file,line,msg) fprintf(fp,"%s%s[%s:%d] %s\n",time,info,file,line,msg)



    
static const char* nm_loginfo[] = 
{
    [ZJW_LOG_LEVEL_INFO] = "[INFO] ",
    [ZJW_LOG_LEVEL_WARNING] = "[WARNING] ",
    [ZJW_LOG_LEVEL_DEBUG] = "[DEBUG] ",
    [ZJW_LOG_LEVEL_ERROR] = "[ERROR] ",
};


static void get_timestamp(char* buffer)
{
    time_t t;
    struct tm* p;
    struct timeval tv;
    int len;
    int millsec;

    t = time(NULL);
    p = localtime(&t);

    gettimeofday(&tv, NULL);
    millsec = (int)(tv.tv_usec / 1000);

    // 时间格式：[2011-11-15 12:47:34:888] 
    len = snprintf(buffer, 32, "[%04d-%02d-%02d %02d:%02d:%02d:%03d] ",
        p->tm_year + 1900, p->tm_mon + 1,
        p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec, millsec);

    buffer[len] = '\0';
}



void logwrite(ZJW_LOG_LEVEL level, const char* file_name, int line, const char* format, ...)
{
    if (level< ZJW_LOG_LEVEL_INFO || level>ZJW_LOG_LEVEL_ERROR)
    {
        return;
    }

    va_list arg_list;
    char buf[2048];
    char time[32] = { 0 };
    va_start(arg_list, format);
    vsnprintf(buf, sizeof(buf), format, arg_list);
  
    get_timestamp(time);
    LOG(time, nm_loginfo[level],file_name,line, buf);
    va_end(arg_list);

}


//初始化日志系统
bool log_init()
{
    fp=fopen(log_file_name,"a+");
    if(!fp)
    {
        std::cout<<"open log file "<<log_file_name<<" failed"<<std::endl;
        return false;
    }
    ZJW_LOG_INFO(NULL_MAX);
    return true;
}


//反初始化日志系统
void log_uninit()
{
    if(fp)
    {
        fclose(fp);
        fp=NULL;
    }
}
