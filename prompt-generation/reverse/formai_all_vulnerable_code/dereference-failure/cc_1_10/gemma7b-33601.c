//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNETS 256

typedef struct Subnet
{
    int network_address;
    int subnet_mask;
    int broadcast_address;
    int usable_hosts;
    struct Subnet* next;
} Subnet;

void calculate_subnet(Subnet* subnet)
{
    subnet->broadcast_address = subnet->network_address | ~subnet->subnet_mask;
    subnet->usable_hosts = (subnet->broadcast_address - subnet->network_address - 1) & ~subnet->subnet_mask;
}

void print_subnet(Subnet* subnet)
{
    printf("Network Address: %d\n", subnet->network_address);
    printf("Subnet Mask: %d\n", subnet->subnet_mask);
    printf("Broadcast Address: %d\n", subnet->broadcast_address);
    printf("Usable Hosts: %d\n", subnet->usable_hosts);
    printf("\n");
}

int main()
{
    Subnet* head = NULL;
    Subnet* current = NULL;

    // Allocate memory for the first subnet
    head = (Subnet*)malloc(sizeof(Subnet));
    current = head;

    // Set the network address and subnet mask
    current->network_address = 192;
    current->subnet_mask = 255;

    // Calculate the subnet information
    calculate_subnet(current);

    // Print the subnet information
    print_subnet(current);

    // Allocate memory for the second subnet
    current = (Subnet*)malloc(sizeof(Subnet));
    current->next = head;

    // Set the network address and subnet mask
    current->network_address = 192;
    current->subnet_mask = 254;

    // Calculate the subnet information
    calculate_subnet(current);

    // Print the subnet information
    print_subnet(current);

    return 0;
}