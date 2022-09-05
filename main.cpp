#include"logger.h"
#include<iostream>
#include<string>
#include<pthread.h>

const std::string info_log_filename="infolog.txt";
const std::string warn_log_filename="warnlog.txt";
const std::string error_log_filename="errorlog.txt";

int count;
void *pthread_entry(void*)
{
    for(int i=0;i<50;i++)
    {
        count++;
        LOG(INFO)<<"count is "<<count;
    }
    LOG(INFO)<<"thread is over"<<std::endl;
}

int main()
{
    initLogger(info_log_filename,warn_log_filename,error_log_filename);
    pthread_t p1,p2;
    pthread_create(&p1,NULL,pthread_entry,NULL);
    pthread_create(&p2,NULL,pthread_entry,NULL);

    LOG(INFO)<<"threads  over"<<std::endl;

    pthread_detach(p1);
    pthread_detach(p2);
    return 0;


}