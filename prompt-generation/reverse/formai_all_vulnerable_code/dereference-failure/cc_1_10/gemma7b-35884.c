//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNETS 1024

typedef struct subnet {
    int address;
    int mask;
    struct subnet* next;
} subnet_t;

subnet_t* subnet_insert(subnet_t* head, int address, int mask) {
    subnet_t* new_subnet = malloc(sizeof(subnet_t));
    new_subnet->address = address;
    new_subnet->mask = mask;
    new_subnet->next = NULL;

    if (head == NULL) {
        head = new_subnet;
    } else {
        subnet_t* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_subnet;
    }

    return head;
}

int subnet_count(subnet_t* head) {
    int count = 0;
    subnet_t* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    subnet_t* head = NULL;

    subnet_insert(head, 192, 255);
    subnet_insert(head, 192, 254);
    subnet_insert(head, 192, 252);

    printf("Number of subnets: %d\n", subnet_count(head));

    return 0;
}