#include"logger.h"
#include<iostream>
#include<string>
const std::string info_log_filename="infolog.txt";
const std::string warn_log_filename="warnlog.txt";
const std::string error_log_filename="errorlog.txt";


int main()
{
    initLogger(info_log_filename,warn_log_filename,error_log_filename);

    for(int i=0;i<10000;i++)
    {
        LOG(INFO)<<"This is a tests "<<i;
    }   

    return 0;
}