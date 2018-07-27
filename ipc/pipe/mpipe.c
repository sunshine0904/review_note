/*************************************************************************
	> File Name: mpipe.c
	> Author: 
	> Mail: 
	> Created Time: Fri 27 Jul 2018 04:07:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<errno.h>

#define ERRNO_SUCCESS 1
#define ERRNO_FAIL    0


void main(int argc, char **argv)
{
    int fd[2];
    pid_t pid;
    int ret = 0;
    char buff[20] = {0};

    if (pipe(fd) < 0)
    {
        printf("pipe Created error!Errno:%s\n",strerror(errno));
        return ERRNO_FAIL;
    }

    if ((pid = fork()) < 0)
    {
        printf("child process create error!Error:%s\n",strerror(errno));
        return ERRNO_FAIL;
    }
    else if (pid > 0)
    {
        printf("pid:%d This is father process!\n",pid);
        close(fd[0]);//close read fd
        write(fd[1],"hello pipe!\n", 15);
    }
    else if (pid == 0)
    {
        printf("pid:%d This is child process!\n",pid);
        close(fd[1]);//close write fd
        ret = read(fd[0],buff, 20);
        if (ret < 0)
        {
            printf("Read error!errno:%s\n",strerror(errno));
            return ERRNO_FAIL;
        }
        else
        {
            printf("read:%s\n",buff);
        }
    }

    return ERRNO_SUCCESS;
}
