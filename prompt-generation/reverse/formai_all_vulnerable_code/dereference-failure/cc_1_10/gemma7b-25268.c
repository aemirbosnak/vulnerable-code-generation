//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNETS 256

typedef struct subnet {
    int address;
    int mask;
    int network;
    int broadcast;
    struct subnet* next;
} subnet_t;

subnet_t* subnet_create(int address, int mask) {
    subnet_t* subnet = (subnet_t*)malloc(sizeof(subnet_t));
    subnet->address = address;
    subnet->mask = mask;
    subnet->network = (address & mask) >> 24;
    subnet->broadcast = address | ~mask;
    subnet->next = NULL;
    return subnet;
}

void subnet_print(subnet_t* subnet) {
    printf("Address: %x\n", subnet->address);
    printf("Mask: %x\n", subnet->mask);
    printf("Network: %x\n", subnet->network);
    printf("Broadcast: %x\n", subnet->broadcast);
}

int subnet_count(subnet_t* subnet) {
    int count = 0;
    subnet_t* current = subnet;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    subnet_t* subnet_head = subnet_create(192, 255);
    subnet_print(subnet_head);

    int num_subnets = subnet_count(subnet_head);
    printf("Number of subnets: %d\n", num_subnets);

    return 0;
}