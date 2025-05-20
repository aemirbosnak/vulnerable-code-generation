//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNET_CALCULATOR_SIZE 1024

typedef struct subnet_calculator_node {
    struct subnet_calculator_node* next;
    int subnet_mask;
    int host_mask;
    int network_address;
    int broadcast_address;
    int usable_hosts;
} subnet_calculator_node;

subnet_calculator_node* subnet_calculator_insert(subnet_calculator_node* head, int subnet_mask, int host_mask, int network_address, int broadcast_address, int usable_hosts) {
    subnet_calculator_node* new_node = malloc(sizeof(subnet_calculator_node));
    new_node->subnet_mask = subnet_mask;
    new_node->host_mask = host_mask;
    new_node->network_address = network_address;
    new_node->broadcast_address = broadcast_address;
    new_node->usable_hosts = usable_hosts;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        subnet_calculator_insert(head, subnet_mask, host_mask, network_address, broadcast_address, usable_hosts);
    }

    return head;
}

void subnet_calculator_print(subnet_calculator_node* head) {
    while (head) {
        printf("Subnet Mask: %x\n", head->subnet_mask);
        printf("Host Mask: %x\n", head->host_mask);
        printf("Network Address: %x\n", head->network_address);
        printf("Broadcast Address: %x\n", head->broadcast_address);
        printf("Usable Hosts: %d\n", head->usable_hosts);
        printf("\n");
        head = head->next;
    }
}

int main() {
    subnet_calculator_node* head = NULL;

    subnet_calculator_insert(head, 255, 255, 192, 192, 2);
    subnet_calculator_insert(head, 255, 255, 192, 193, 4);
    subnet_calculator_insert(head, 255, 255, 192, 194, 6);

    subnet_calculator_print(head);

    return 0;
}