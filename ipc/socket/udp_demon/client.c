/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Aug 2018 10:27:45 AM CST
 ************************************************************************/

#include<stdio.h>

#include "head.h"

int main(int argc, char **argv)
{
    int sockfd = 0;
    char buff[1024];
    struct sockaddr seraddr;

    memset(&seraddr, 0, sizeof(struct sockaddr_in));

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket error!\n");
        return ERRNO_FAIL;
    }

    strcpy(buff, "hello socket!\n");
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(SER_PORT);
    seraddr.sin_addr.s_addr = htonl(SER_ADDR);

    if (sendto(sockfd, buff, strlen(buff) + 1, 0, (struct sockaddr *)&seraddr, sizeof(struct sockaddr)) < 0)
    {
        perror("sendto error!\n");
        return ERRNO_FAIL;
    }
    

    if (recvfrom(sockfd, buff, 1024, 0, NULL, NULL) < 0)
    {
        perror("recvfrom error!\n");
        return ERRNO_FAIL;
    }

    printf("buff:%s\n", buff);

    close(sockfd);
    return ERRNO_SUCCESS;


}
