#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "linked_list.h"
#include "hashing.h"

typedef struct hash_table_t
{
    linked_list_t* buckets;
    size_t size;
    hashing_func hfunc;
} hash_table_t;

void hash_table_init(hash_table_t* ht, size_t size, hashing_func hfunc);
void hash_table_destroy(hash_table_t* ht);
void hash_table_insert(hash_table_t* ht, int64_t val);
void hash_table_delete(hash_table_t* ht, int64_t val);
void hash_table_print(const hash_table_t* ht);
bool hash_table_search(const hash_table_t* ht, int64_t val);
uint64_t simple_hash(int64_t val);

#endif // HASH_TABLE_H
