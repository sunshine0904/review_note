/*************************************************************************
	> File Name: linklist.c
	> Author: 
	> Mail: 
	> Created Time: Thu 26 Jul 2018 01:59:52 PM CST
 ************************************************************************/

#include<stdio.h>

#include "linklist.h"

void listnode_add_tail(struct list *l, void *val)
{
    struct listnode *node = NULL;

    node = malloc(sizeof(struct listnode));

    node->data = val;
    node->prev = l->tail;

    if (l->head == NULL)
    {
        l->head = node;
    }
    else
    {
        l->tail->next = node;
    }

    l->tail = node;

    l->count ++;
}


void listnode_add_head(struct list *l, void *val)
{
    struct listnode *node = NULL;

    node = malloc(sizeof(struct listnode));

    node->data = val;
    node->next = l->head;

    if (l->tail == NULL)
    {
        l->tail = node;
    }
    else
    {
        l->tail->prev = node;
    }

    l->head = node;

    l->count ++;
}


void listnode_add_sort(struct list *l, void *val)
{
    struct listnode *n = NULL;
    struct listnode *node = NULL;

    node = malloc(sizeof(struct listnode));
    node->data = val;


    if (l->cmp == NULL)
    {
        return;
    }

    for (n = l->head; n; n = n->next)
    {
        if ((l->cmp)(val, n->data) == ERRNO_SUCCESS)
        {
            node->next = n;

            if (n->prev)
            {
                n->prev->next = node;
            }
            else
            {
                l->head = node;
            }
            
            node->prev = n->prev;
            n->prev = node;
            
            l->count ++;

            return;
        }
    }

    /*if add by sort fail,insert to list tail*/
    node->prev = l->tail;

    if (l->head == NULL)
    {
        l->head = node;
    }
    else
    {
        l->tail->next = node;
    }

    l->tail = node;
    l->count ++;
}

uint8_t listnode_delete(struct list *l, void *val)
{
    struct listnode *n = NULL;

    for (n = l->head; n; n = n->next)
    {
        if (n->data == val)
        {
            if (n->prev)
            {
                n->prev->next = n->next;
            }
            else
            {
                l->head = n->next;
            }

            if (n->next)
            {
                n->next->prev = n->prev;
            }
            else
            {
                l->tail = n->prev;
            }
           
            free(n);
            l->count --;
            return ERRNO_SUCCESS;
        }
    }

    return ERRNO_FAIL;
}



struct listnode *listnode_find(struct list *l, void *val)
{
    struct listnode *n = NULL;

    for (n = l->head; n; n = n->next)
    {
        if ((l->cmp)(val, n->data) == ERRNO_SUCCESS)
        {
            return n;
        }
    }
    
    return NULL;
}






void list_init(struct list *l, uint8_t (*cmp)(void *val1, void *val2), uint8_t (*del)(struct list *l, void *val))
{
    l->head = NULL;
    l->tail = NULL;
    l->count = 0;
    l->cmp = cmp;
    l->del = del;
}

uint8_t stu_cmp(void *val1, void *val2)
{
    struct stu *pval1 = val1;
    struct stu *pval2 = val2;

    if (pval1->serial_num > pval2->serial_num)
    {
        return ERRNO_SUCCESS;
    }
}


void main()
{
    uint8_t i = 0;
    struct stu *st = NULL; 
    struct list stu_l;
    struct listnode *n = NULL;

    list_init(&stu_l, stu_cmp, listnode_delete);
    
    //printf("func:%s line:%d stu_l.head:%p\n",__func__,__LINE__,stu_l.head);
    for (i = 0; i < 20; i++)
    {
        st = malloc(sizeof(struct stu));
        st->serial_num = 20180800 + i;
        st->score = 95;
        st->sex = i % 2;
        st->high = 160 + st->sex;
        st->weight = 60 + st->sex;
        
        //listnode_add_tail(&stu_l, st);
        listnode_add_sort(&stu_l, st);
    }

    for (n = stu_l.head; n; n = n->next)
    {
        st = n->data;
        printf ("serial:%d score:%d \n",st->serial_num, st->score);
    }
}











