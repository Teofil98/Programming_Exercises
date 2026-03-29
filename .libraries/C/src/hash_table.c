#include "../include/hash_table.h"

uint64_t simple_hash(int64_t val)
{
    unsigned long hash = 5381;
    int c;

    while (val != 0) {
        c = val % 10;
        val /= 10;
        hash = hash * 33 + c;
    }

    return hash;
}

void hash_table_init(hash_table_t *ht, size_t size)
{
    ht->size = size;
    ht->buckets = (linked_list_t*)malloc(size * sizeof(linked_list_t));
    for(size_t i = 0; i < size; i++) {
        linked_list_init(&(ht->buckets[i]));
    }
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
    uint64_t hash = simple_hash(val); 
    size_t idx = hash % ht->size;
    linked_list_insert(&(ht->buckets[idx]), val);
}

void hash_table_delete(hash_table_t* ll, int64_t val)
{

}

void hash_table_print(const hash_table_t* ll);
bool hash_table_search(const hash_table_t* ll, int64_t val);
