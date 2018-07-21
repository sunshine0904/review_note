/*************************************************************************
	> File Name: hashtable.h
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Jul 2018 04:46:56 PM CST
 ************************************************************************/

#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#define BUCKET_SIZE 1024

#define ERRNO_SUCCESS 1
#define ERRNO_FAIL    0

typedef unsigned int         uint32_t;
typedef unsigned short int   uint16_t;
typedef unsigned char        uint8_t;


struct hash_bucket
{
    struct hash_bucket *next;
    struct hash_bucket *prev;
    uint32_t hashval;
    void *hash_key;
    void *data;
};

struct hash_table
{
    struct hash_bucket *buckets[BUCKET_SIZE];
    uint32_t entry_size;//real entry size
    uint32_t hash_size;//max entry size
    uint32_t (*hash_compute)(void *hash_key);//hash key compute
    uint32_t (*hash_compare)(void *item, void *hash_key);//hash key compare
};



struct stu_hashkey
{
    uint32_t serial_num;
    uint32_t age;
};

struct students
{
    struct stu_hashkey key;
    uint8_t sex;
    uint8_t high;
    uint8_t weight;
    uint8_t score;
};

#endif
