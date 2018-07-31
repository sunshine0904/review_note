/*************************************************************************
	> File Name: malarm.c
	> Author: 
	> Mail: 
	> Created Time: Tue 31 Jul 2018 08:10:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void handle()
{
    printf("I have get alarm signal.........\n");

    alarm(5);
}


int main(int argc, char **argv)
{
    signal(SIGALRM, handle);
    
    handle();

    while(1)
    {
        pause();
    }
}


