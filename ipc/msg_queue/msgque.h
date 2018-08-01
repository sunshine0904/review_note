/*************************************************************************
	> File Name: msgque.h
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Aug 2018 05:46:06 PM CST
 ************************************************************************/

#ifndef _MSGQUE_H
#define _MSGQUE_H

#define MPATH "/home/sun/temp/"

#define BUFF_SIZE 128

#define ERRNO_FAIL    0
#define ERRNO_SUCCESS 1

typedef unsigned int       uint32_t;
typedef unsigned short int uint16_t;
typedef unsigned char      uint8_t;

struct msg_buf
{
    uint8_t mtype;
    uint8_t buf[BUFF_SIZE];
};





#endif
