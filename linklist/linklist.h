/*************************************************************************
	> File Name: linklist.h
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Jul 2018 05:58:48 PM CST
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

struct listnode
{
    struct listnode *next;
    struct listnode *prev;
    void *data;
};

strut list
{
    struct listnode *head;
    struct listnode *tail;
    uint32_t count;

    void (*cmp)(void *val1, void *val2);
    void (*del)(void *val);
};



#endif
