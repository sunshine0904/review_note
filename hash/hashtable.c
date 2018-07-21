/*************************************************************************
	> File Name: hashtable.c
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Jul 2018 09:14:46 AM CST
 ************************************************************************/

#include<stdio.h>
#include "hashtable.h"


uint32_t hash_compute(void *key)
{
    struct stu_hashkey *pkey = key;
    uint32_t val = 0;

    val = pkey->serial_num + pkey->age;

    return val;
}

uint32_t hash_compare(void *item, void *hash_key)
{
    struct stu_hashkey *pkey = NULL;
    struct stu_hashkey *pkey_cmp = hash_key;

    pkey = &(((struct students *)item)->key);

    if ((pkey->serial_num == pkey_cmp->serial_num) &&
        (pkey->age == pkey_cmp->age))
    {
        return ERRNO_SUCCESS;
    }
    return ERRNO_FAIL;
}


void hash_table_init(struct hash_table *table, uint32_t size, uint32_t (*compute)(void *hash_key), uint32_t (*compare(void *item, void *hash_key)))
{
    uint32_t i = 0;

    table->hash_size = size;
    table->entry_size = 0;
    table->hash_compute = compute;
    table->hash_compare = compare;

    for (i = 0; i < BUCKET_SIZE; i++)
    {
        table->buckets[i] = NULL;
    }
}

void hash_add(struct hash_table *table,struct hash_bucket *item)
{
    uint32_t val = 0;

    if (table->entry_size == table->hash_size)
    {
        return ERRNO_FAIL;
    }
    
    val = table->hash_compute(&(item->hash_key));
    val %= BUCKET_SIZE;

    item->prev = NULL;
    item->next = table->buckets[val];
    item->hashval = val;
    if (item->next)
    {
        item->next->prev = item;
    }
    table->buckets[val] = item;
    table->entry_size ++;
    
    return 0;
}

void hash_delete(struct hash_table *table, struct hash_bucket *item)
{
    uint32_t val = table->hash_compute(item->hash_key);
    
    if(item->prev)
    {
        item->prev->next = item->next;
    }
    else
    {
        table->buckets[val] = item->next;
    }

    if (item->next)
    {
        item->next->prev = item->prev;
    }

    table->entry_size --;
}

void hash_find(struct hash_table *table, void *key)
{
    struct hash_bucket *item = NULL;
    uint32_t val = table->hash_compute(key);

    for(item = table->buckets[val]; item; item = item->next)
    {
        if (table->hash_compare(item,key) == ERRNO_SUCCESS)
        {
            return item;
        }
    }

    return NULL;
}


void hash_bucket_loop(struct hash_table *table)
{
    struct hash_bucket *pbucket = NULL;
    struct students *stu = NULL;
    uint32_t val = 0;

    printf("entry_size:%d hash_size:%d\n",table->entry_size, table->hash_size);

    for(val = 0; val < BUCKET_SIZE; val ++)
    {
        for(pbucket = table->buckets[val]; pbucket; pbucket = pbucket->next)
        {
            if (pbucket->data == NULL)
                break;

            stu = (struct students *)pbucket->data;
            printf("val:%d stu:%p key.serial:%d key.age:%d\n",
                    val, stu, stu->key.serial_num, stu->key.age);
        }
    }

}





void main()
{
    struct hash_table stu_table;
    struct hash_bucket *pbucket = NULL;
    struct students stu;
    struct students *pstu = NULL;
    uint32_t i = 0;

    memset(&stu, 0, sizeof(struct students));
    hash_table_init(&stu_table, 4096, hash_compute, hash_compare);

    for(i = 0;i < 10; i ++)
    {
        stu.key.serial_num = 20180900 + i;
        stu.key.age = 25;
        stu.sex = (i % 2);
        stu.high = 175;
        stu.weight = 60;
        stu.score = 100;
        
        pbucket = malloc(sizeof(struct hash_bucket));
        pstu = malloc(sizeof(struct students));
        memcpy(pstu, &stu, sizeof(struct students));

        pbucket->hash_key = &(pstu->key);
        pbucket->data = pstu;
        hash_add(&stu_table, pbucket);
    }

    hash_bucket_loop(&stu_table);

}
