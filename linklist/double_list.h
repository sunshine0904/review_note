/*************************************************************************
	> File Name: linklist.h
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Jul 2018 05:58:48 PM CST
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H


#define ERRNO_SUCCESS 1
#define ERRNO_FAIL    0

typedef unsigned int       uint32_t;
typedef unsigned short int uint16_t;
typedef unsigned char      uint8_t;

struct listnode
{
    struct listnode *next;
    struct listnode *prev;
    void *data;
};

struct list
{
    struct listnode *head;
    struct listnode *tail;
    uint32_t count;

    uint8_t (*cmp)(void *val1, void *val2);
    uint8_t (*del)(void *val);
};


struct stu
{
    uint32_t serial_num;
    uint8_t score;
    uint8_t sex;
    uint8_t high;
    uint8_t weight;
};

#endif
