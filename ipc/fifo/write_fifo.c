/*************************************************************************
	> File Name: write_fifo.c
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Jul 2018 07:17:18 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char **argv)
{
    int fd = 0;
    int len = 0;

    if ((mkfifo("fifo", 0666)) < 0)
    {
        if (errno == EEXIST)
        {
            printf("FIFO exist!\n");
        }
        else
        {
            printf("mkdir fifo error!\n");
            return 0;
        }
    }

    if ((fd = open("fifo", O_WRONLY)) < 0)
    {
        printf("open fifo error!\n");
        return 0;
    }

    while(1)
    {
        if ((len = write(fd, "hello, this is fifo!", 20)) < 0)
        {
           printf("write fifo error!\n"); 
        }
        else
        {
            printf("write %d bytes to fifo!\n",len);
        }

        sleep(1);
    }

    close(fd);

    return 1;
}


