//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNETS 256

typedef struct subnet_t {
    int address;
    int mask;
    struct subnet_t* next;
} subnet_t;

subnet_t* subnet_add(subnet_t* head, int address, int mask)
{
    subnet_t* new_subnet = malloc(sizeof(subnet_t));
    new_subnet->address = address;
    new_subnet->mask = mask;
    new_subnet->next = NULL;

    if (head == NULL) {
        head = new_subnet;
    } else {
        subnet_t* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_subnet;
    }

    return head;
}

int subnet_count(subnet_t* head)
{
    int count = 0;
    subnet_t* current = head;
    while (current) {
        count++;
        current = current->next;
    }

    return count;
}

int subnet_search(subnet_t* head, int address)
{
    subnet_t* current = head;
    while (current) {
        if (current->address == address) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main()
{
    subnet_t* head = NULL;

    subnet_add(head, 192, 255);
    subnet_add(head, 192, 254);
    subnet_add(head, 192, 253);

    int count = subnet_count(head);
    printf("Number of subnets: %d\n", count);

    if (subnet_search(head, 192) == 1) {
        printf("Address 192 is in the subnet.\n");
    } else {
        printf("Address 192 is not in the subnet.\n");
    }

    return 0;
}