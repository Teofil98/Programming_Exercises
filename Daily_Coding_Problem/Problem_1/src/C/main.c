#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "dcp_1.h"

int main()
{
    uint64_t n; 
    int64_t k;
    int64_t* arr;

    FILE* ifile = fopen("input.txt", "r");
    FILE* ofile = fopen("output.txt", "w");

    int ret = fscanf(ifile, "%ld\n", &n);
    (void) ret;
    arr = (int64_t*)malloc(n * sizeof(int64_t));

    for(int i = 0; i < n; i++) {
        ret = fscanf(ifile, "\n%ld", &arr[i]);
        (void) ret;
    }

    ret = fscanf(ifile, "%ld", &k);
    (void) ret;
        
    bool res = is_sum(n, arr, k);

    if(res) {
        fprintf(ofile, "True");
    } else {
        fprintf(ofile, "False");
    }

    free(arr);
    return 0;

}
