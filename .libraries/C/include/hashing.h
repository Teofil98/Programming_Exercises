#ifndef HASHING_H
#define HASHING_H

#include <stdint.h>

typedef uint64_t (*hashing_func)(int64_t);
uint64_t simple_hash(int64_t val);

#endif // HASHING_H
