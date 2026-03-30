#include "../include/hash_table.h"

int main()
{
    hash_table_t ht;
    hash_table_init(&ht, 4, &simple_hash);

    hash_table_insert(&ht, 1);
    hash_table_print(&ht);

    hash_table_insert(&ht, 2);
    hash_table_print(&ht);

    hash_table_insert(&ht, 3);
    hash_table_print(&ht);

    hash_table_delete(&ht, 2);
    hash_table_print(&ht);


    hash_table_insert(&ht, 4);
    hash_table_insert(&ht, 5);
    hash_table_insert(&ht, 6);
    hash_table_insert(&ht, 6);
    hash_table_insert(&ht, 8);

    hash_table_print(&ht);
    hash_table_destroy(&ht);

    return 0;
}
