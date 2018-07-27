/*************************************************************************
	> File Name: read_fifo.c
	> Author: 
	> Mail: 
	> Created Time: Fri 27 Jul 2018 05:51:27 PM CST
 ************************************************************************/

#include<stdio.h>
#include<errno.h>


int main(int argc, char **argv)
{
    
    if (mkfifo("./fifo", 0666) < 0)
    {
        printf("mkfifo error!errno:%s\n",strerror(errno));
    }




}
