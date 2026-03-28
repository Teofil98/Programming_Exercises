#include <stdbool.h>
#include <stdint.h>
#include "dcp_1.h"

bool is_sum(uint64_t n, int64_t* arr, int64_t k)
{
    if(n == 0) {
        return false;
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == k) {
                return true;
            }
        }
    }

    return false;
}
