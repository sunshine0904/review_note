/*************************************************************************
	> File Name: snd_signal.c
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Jul 2018 08:34:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void handler(int sig)
{
    if (sig == SIGINT)
    {
        printf("I have get SIGINT signal..........\n");
    }
}



int main(int argc, char **argv)
{
   signal(SIGINT, handler); 

    while(1)
    {
        pause();
    }

    return 1;
}

