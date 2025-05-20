//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNETS 10

typedef struct subnet {
    int address;
    int mask;
    int broadcast;
    struct subnet* next;
} subnet_t;

subnet_t* subnet_add(subnet_t* head, int address, int mask) {
    subnet_t* new_subnet = malloc(sizeof(subnet_t));
    new_subnet->address = address;
    new_subnet->mask = mask;
    new_subnet->broadcast = address | ~mask;
    new_subnet->next = NULL;

    if (head == NULL) {
        head = new_subnet;
    } else {
        head->next = new_subnet;
    }

    return head;
}

void subnet_print(subnet_t* head) {
    while (head) {
        printf("  Address: %x\n", head->address);
        printf("  Mask: %x\n", head->mask);
        printf("  Broadcast: %x\n", head->broadcast);
        printf("\n");
        head = head->next;
    }
}

int main() {
    subnet_t* head = NULL;

    // Add some subnets
    subnet_add(head, 192, 255);
    subnet_add(head, 192, 224);
    subnet_add(head, 192, 192);
    subnet_add(head, 192, 160);

    // Print the subnets
    subnet_print(head);

    return 0;
}