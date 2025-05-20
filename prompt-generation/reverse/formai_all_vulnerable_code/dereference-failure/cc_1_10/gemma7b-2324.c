//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ subnet_bits 32

typedef struct subnet_mask {
    int bits;
    struct subnet_mask* next;
} subnet_mask_t;

subnet_mask_t* subnet_mask_insert(subnet_mask_t* head, int bits)
{
    subnet_mask_t* new_node = malloc(sizeof(subnet_mask_t));
    new_node->bits = bits;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        subnet_mask_t* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = new_node;
    }

    return head;
}

int subnet_mask_match(subnet_mask_t* head, int subnet_mask)
{
    subnet_mask_t* current = head;
    while (current) {
        if (current->bits == subnet_mask) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main()
{
    subnet_mask_t* subnet_mask_head = NULL;
    subnet_mask_head = subnet_mask_insert(subnet_mask_head, 24);
    subnet_mask_head = subnet_mask_insert(subnet_mask_head, 16);
    subnet_mask_head = subnet_mask_insert(subnet_mask_head, 8);

    int subnet_mask_value = 22;
    if (subnet_mask_match(subnet_mask_head, subnet_mask_value)) {
        printf("Subnet mask %d is matched\n", subnet_mask_value);
    } else {
        printf("Subnet mask %d is not matched\n", subnet_mask_value);
    }

    return 0;
}