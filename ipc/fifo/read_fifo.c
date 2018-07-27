/*************************************************************************
	> File Name: read_fifo.c
	> Author: 
	> Mail: 
	> Created Time: Fri 27 Jul 2018 05:51:27 PM CST
 ************************************************************************/

#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define ERRNO_SUCCESS 1
#define ERRNO_FAIL    0

int main(int argc, char **argv)
{
    int r_fd = 0;
    char buf[1024];
    int ret = 0;
    int len = 0;
    
    if (mkfifo("fifo", 0666) < 0)
    {
        printf("mkfifo error!errno:%s\n",strerror(errno));
    }

    if ((r_fd = open("fifo", O_RDONLY)) < 0)
    {
        printf("open fifo error!errno:%s\n",strerror(errno));
        return ERRNO_FAIL;
    }

    memset(buf, 0, 1024);
    while((len = read(r_fd, buf, 1024)) > 0)
    {
        printf("len:%d content:%s\n", len, buf);
    }

    close(r_fd);

    return ERRNO_SUCCESS;
}
