#include "../include/hashing.h"


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
