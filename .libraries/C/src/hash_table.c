#include <stdio.h>
#include "../include/hash_table.h"

static inline size_t get_hash_idx(const hash_table_t* ht, int64_t val)
{
    uint64_t hash = ht->hfunc(val);
    size_t idx = hash % ht->size;
    
    return idx;
}

void hash_table_init(hash_table_t *ht, size_t size, hashing_func hfunc)
{
    ht->size = size;
    ht->buckets = (linked_list_t*)malloc(size * sizeof(linked_list_t));
    for(size_t i = 0; i < size; i++) {
        linked_list_init(&(ht->buckets[i]));
    }
    ht->hfunc = hfunc;
}

void hash_table_destroy(hash_table_t* ht)
{
    for(size_t i = 0; i < ht->size; i++) {
        linked_list_destroy(&(ht->buckets[i]));
    }
    free(ht->buckets);
}

void hash_table_insert(hash_table_t* ht, int64_t val)
{
    size_t idx = get_hash_idx(ht, val);
    linked_list_insert(&(ht->buckets[idx]), val);
}

void hash_table_delete(hash_table_t* ht, int64_t val)
{
    size_t idx = get_hash_idx(ht, val);
    linked_list_delete(&(ht->buckets[idx]), val);
}

void hash_table_print(const hash_table_t* ht)
{
    for(size_t i = 0; i < ht->size; i++) {
        printf("[%ld]:", i);
        linked_list_print(&ht->buckets[i]);
    }
}

bool hash_table_search(const hash_table_t* ht, int64_t val)
{
   size_t idx = get_hash_idx(ht, val); 
   return linked_list_search(&(ht->buckets[idx]), val);
}
