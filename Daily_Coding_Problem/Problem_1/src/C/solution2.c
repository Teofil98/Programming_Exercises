#include <stdbool.h>
#include "dcp_1.h"
#include "../../../../.libraries/C/include/mylib.h"

bool is_sum(uint64_t n, int64_t* arr, int64_t k)
{
    hash_table_t ht;
    hash_table_init(&ht, 1000, &simple_hash);
    for(uint64_t i = 0; i < n; i++) {
        if(hash_table_search(&ht, k - arr[i])) {
            return true;
        }
        hash_table_insert(&ht, arr[i]);
    }
    return false;
}
