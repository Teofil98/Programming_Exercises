#include <stdio.h>
#include "../include/linked_list.h"

void linked_list_init(linked_list_t* ll)
{
    ll->head = NULL;
}

void linked_list_destroy(linked_list_t* ll)
{
    ll_node_t* curr = ll->head;
    ll_node_t* prev;
    while(curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
}

void linked_list_insert(linked_list_t* ll, int64_t val)
{
    ll_node_t* new_node = (ll_node_t*)malloc(sizeof(ll_node_t));
    new_node->value = val;
    new_node->next = ll->head;
    ll->head = new_node;
}

void linked_list_print(const linked_list_t* ll)
{
    ll_node_t* curr = ll->head;
    while(curr != NULL) {
        printf("%ld ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

void linked_list_delete(linked_list_t* ll, int64_t val)
{
    ll_node_t* curr = ll->head;
    ll_node_t* prev;
    while(curr != NULL && curr->value != val) {
        prev = curr;
        curr = curr->next;
    }

    if(curr != NULL) {
        if(curr == ll->head) {
            ll->head = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    }
}

bool linked_list_search(const linked_list_t *ll, int64_t val) {
    ll_node_t* curr = ll->head;
    ll_node_t* prev;
    while(curr != NULL && curr->value != val) {
        prev = curr;
        curr = curr->next;
    }

    if(curr != NULL) {
        return true;
    }

    return false;
}
