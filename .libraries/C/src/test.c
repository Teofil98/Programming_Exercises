#include "../include/linked_list.h"

int main()
{
    linked_list_t ll;
    linked_list_init(&ll);

    linked_list_insert(&ll, 1);
    linked_list_print(&ll);

    linked_list_insert(&ll, 2);
    linked_list_print(&ll);

    linked_list_insert(&ll, 3);
    linked_list_print(&ll);

    linked_list_delete(&ll, 2);
    linked_list_print(&ll);

    linked_list_delete(&ll, 1);
    linked_list_print(&ll);

    linked_list_delete(&ll, 3);
    linked_list_print(&ll);

    linked_list_destroy(&ll);

    return 0;
}
