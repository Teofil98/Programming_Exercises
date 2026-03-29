#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ll_node_t
{
    int64_t value;
    struct ll_node_t* next;
} ll_node_t;

typedef struct linked_list_t
{
    ll_node_t* head;
} linked_list_t;

void linked_list_init(linked_list_t* ll);
void linked_list_destroy(linked_list_t* ll);
void linked_list_insert(linked_list_t* ll, int64_t val);
void linked_list_delete(linked_list_t* ll, int64_t val);
void linked_list_print(const linked_list_t* ll);
bool linked_list_search(const linked_list_t* ll, int64_t val);

#endif // LINKED_LIST_H
