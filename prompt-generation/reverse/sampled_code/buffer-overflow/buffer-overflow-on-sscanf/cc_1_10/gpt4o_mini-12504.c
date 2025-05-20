//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ip_address[16];
    char subnet_mask[16];
    char network_address[16];
    char broadcast_address[16];
    int no_of_hosts;
} SubnetInfo;

void calculateSubnetInfo(SubnetInfo *subnet) {
    unsigned int ip[4], mask[4], network[4], broadcast[4];
    sscanf(subnet->ip_address, "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(subnet->subnet_mask, "%u.%u.%u.%u", &mask[0], &mask[1], &mask[2], &mask[3]);

    // Calculate network address
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
    }
    sprintf(subnet->network_address, "%u.%u.%u.%u", network[0], network[1], network[2], network[3]);

    // Calculate broadcast address
    for (int i = 0; i < 4; i++) {
        broadcast[i] = network[i] | (~mask[i] & 0xFF);
    }
    sprintf(subnet->broadcast_address, "%u.%u.%u.%u", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);

    // Calculate number of hosts
    int host_bits = 0;
    for (int i = 0; i < 4; i++) {
        host_bits += 8 - __builtin_popcount(mask[i]);
    }
    subnet->no_of_hosts = (1 << host_bits) - 2; // -2 for network and broadcast addresses
}

void printSubnetInfo(SubnetInfo *subnet) {
    printf("\n🎉 Subnet Information 🎉\n");
    printf("=========================================\n");
    printf("IP Address:          %s\n", subnet->ip_address);
    printf("Subnet Mask:        %s\n", subnet->subnet_mask);
    printf("Network Address:    %s\n", subnet->network_address);
    printf("Broadcast Address:  %s\n", subnet->broadcast_address);
    printf("Number of Hosts:    %d\n", subnet->no_of_hosts);
    printf("=========================================\n");
}

int main() {
    printf("🎊 Welcome to the C Subnet Calculator! 🎊\n");
    SubnetInfo subnet;

    printf("Please enter an IP Address (e.g., 192.168.1.1): ");
    fgets(subnet.ip_address, sizeof(subnet.ip_address), stdin);
    subnet.ip_address[strcspn(subnet.ip_address, "\n")] = 0; // remove newline

    printf("Please enter a Subnet Mask (e.g., 255.255.255.0): ");
    fgets(subnet.subnet_mask, sizeof(subnet.subnet_mask), stdin);
    subnet.subnet_mask[strcspn(subnet.subnet_mask, "\n")] = 0; // remove newline

    calculateSubnetInfo(&subnet);
    printSubnetInfo(&subnet);

    printf("🌟 Thank you for using the C Subnet Calculator! 🌟\n");
    return 0;
}