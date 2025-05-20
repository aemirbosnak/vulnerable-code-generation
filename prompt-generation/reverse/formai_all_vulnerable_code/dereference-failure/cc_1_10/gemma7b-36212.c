//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000

typedef struct subnet {
    char subnet_mask[16];
    int network_address;
    int broadcast_address;
    struct subnet* next;
} subnet_t;

subnet_t* subnet_create() {
    subnet_t* subnet = malloc(sizeof(subnet_t));
    subnet->subnet_mask[0] = 0;
    subnet->network_address = 0;
    subnet->broadcast_address = 0;
    subnet->next = NULL;
    return subnet;
}

void subnet_add(subnet_t* head, char* subnet_mask, int network_address, int broadcast_address) {
    subnet_t* new_subnet = subnet_create();
    memcpy(new_subnet->subnet_mask, subnet_mask, 16);
    new_subnet->network_address = network_address;
    new_subnet->broadcast_address = broadcast_address;

    if (head == NULL) {
        head = new_subnet;
    } else {
        head->next = new_subnet;
        head = new_subnet;
    }
}

void subnet_print(subnet_t* head) {
    while (head) {
        printf("Subnet Mask: %s\n", head->subnet_mask);
        printf("Network Address: %d\n", head->network_address);
        printf("Broadcast Address: %d\n", head->broadcast_address);
        printf("\n");
        head = head->next;
    }
}

int main() {
    subnet_t* head = NULL;

    subnet_add(head, "255.255.255.0", 192, 255);
    subnet_add(head, "255.255.255.128", 192, 255);
    subnet_add(head, "255.255.255.192", 192, 255);

    subnet_print(head);

    return 0;
}