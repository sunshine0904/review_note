/*************************************************************************
	> File Name: single_linklist.c
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Aug 2018 02:45:40 PM CST
 ************************************************************************/

#include<stdio.h>


#define ERRNO_SUCCESS 1
#define ERRNO_FAIL    0




struct stu
{
    int age;
    int sex;
    int score;
};


struct listnode
{
    struct listnode *next;
    void *data;
};

struct list
{
    struct listnode *head;
    struct listnode *tail;
    int count;
    char (*cmp)(struct listnode *n, void *data);
    void (*del)(struct list *l, void *data);
};


void list_revert(struct list *l)
{
    struct listnode *head = l->head;
    struct listnode *p = NULL,*q = NULL,*pr = NULL;

    p = head->next;
    q = NULL;
    head->next = NULL;
    while(p)
    {
        pr = p->next;
        p->next = q;
        q = p;
        p = pr;
    }

    head->next = q;
    //l->head = head;
}

/*尾插法*/
void listnode_add_tail(struct list *l, void *data)
{
    struct listnode *pnode = NULL;

    pnode = malloc(sizeof(struct listnode));
    pnode->data = data;

    if (l->tail)
    {
        l->tail->next = pnode;
    }
    else
    {
        l->head = pnode;
    }

    l->tail = pnode;

    l->count ++;
}


void listnode_add_head(struct list *l, void *data)
{
    struct listnode *pnode = NULL;

    pnode = malloc(sizeof(struct listnode));
    pnode ->data = data;

    pnode->next = l->head;
    if (l->head == NULL)
    {
        l->tail = pnode;
    }
    
    l->head = pnode;

    l->count ++;
}


char listnode_del(struct list *l, void *data)
{
    struct listnode *pnode = NULL;
    struct listnode *pnext = NULL;

    if (l->head)
    {
        if ((l->cmp)(l->head, data) == ERRNO_SUCCESS)
        {
            l->head = l->head->next;
            l->count --;
            return ERRNO_SUCCESS;
        }
    }

    for (pnode = l->head,pnext = pnode->next; pnext; pnode = pnext,pnext = pnode->next)
    {
        if ((l->cmp)(pnext, data) == ERRNO_SUCCESS)
        {
            pnode->next = pnext->next;
            if (pnext->next == NULL)
            {
                l->tail = pnode;
            }

            l->count --;

            free(pnext);
            return ERRNO_SUCCESS;
        }
    }

    return ERRNO_FAIL;
}

char stu_cmp(struct listnode *pnode, void *data)
{
    struct stu *pdata = data;
    struct stu *ndata = pnode->data;
    
    if ((pdata->age == ndata->age) &&
        (pdata->sex == ndata->sex) &&
        (pdata->score == ndata->score))
    {
        return ERRNO_SUCCESS;
    }

    return ERRNO_FAIL;
}






int main(int argc, char **argv)
{
    struct list l;    
    struct stu *st = NULL;
    struct listnode *pnode = NULL;
    int  i = 0;
    
    memset(&l, 0 , sizeof(struct list));
    l.cmp = stu_cmp;
    l.del = listnode_del;

    for (i = 0; i < 10; i++)
    {
        st = malloc(sizeof(struct stu));
        st->age = i + 20;
        st->sex = i % 2;
        st->score = 100;

        //listnode_add_head(&l, st);
        listnode_add_tail(&l, st);
    }

    #if 0
    struct stu tstu;
    memset(&tstu, 0, sizeof(struct stu));
    tstu.age = 21;
    tstu.sex = 1;
    tstu.score = 100;
    listnode_del(&l, &tstu);
    #endif
    
    for (pnode = l.head; pnode; pnode = pnode->next)
    {
        st = pnode->data;
        if (!st) continue;

        printf("st.age:%d ",st->age);
    }
    printf("\n");
    
    
    list_revert(&l);

    for (pnode = l.head; pnode; pnode = pnode->next)
    {
        st = pnode->data;
        if (!st) break;

        printf("st.age:%d ",st->age);
    }
    printf("\n");

}

