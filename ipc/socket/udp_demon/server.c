/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Aug 2018 11:04:58 AM CST
 ************************************************************************/

#include<stdio.h>

#include "head.h"

int main()
{
    struct sockaddr seraddr;
    struct sockaddr cltaddr;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_DGRAM,0);

    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(SER_PORT);
    seraddr.sin_addr.s_addr = htonl(SER_ADDR);

    bind(sockfd, &seraddr, sizeof(struct sockaddr_in));

    while(1)
    {
        if (recvfrom())


        sendto();
    }


    close(sockfd);
}



