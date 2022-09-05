#include<iostream>
#include"logger_im.h"
using namespace std;
#include<pthread.h>


int count;
void *pthread_entry(void*)
{
    for(int i=0;i<50;i++)
    {
         count++;
         ZJW_LOG_INFO("the count is %d",count);
    }
    ZJW_LOG_INFO("thread is over");
}

int main()
{
    if(!LOG_INIT())
    {
       	std::cout<<"log init failed"<<std::endl;
		return 0;
    }

    

    pthread_t p1,p2;
    pthread_create(&p1,NULL,pthread_entry,NULL);
    pthread_create(&p2,NULL,pthread_entry,NULL);


    pthread_join(p1,NULL);
    pthread_join(p2,NULL);

    return 0;
}