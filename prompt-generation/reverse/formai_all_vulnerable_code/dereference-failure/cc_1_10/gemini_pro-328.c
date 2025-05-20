//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IP_ADDR_LEN 16
#define MAX_SUBNET_MASK_LEN 32

typedef struct {
    char ip_addr[IP_ADDR_LEN];
    char subnet_mask[MAX_SUBNET_MASK_LEN];
    char network_addr[IP_ADDR_LEN];
    char broadcast_addr[IP_ADDR_LEN];
    char num_hosts[16];
} subnet_info;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_addr> <subnet_mask>\n", argv[0]);
        return EXIT_FAILURE;
    }

    subnet_info subnet;
    strcpy(subnet.ip_addr, argv[1]);
    strcpy(subnet.subnet_mask, argv[2]);

    // Calculate the network address
    char *network_addr = strtok(subnet.ip_addr, ".");
    char *subnet_mask_part = strtok(subnet.subnet_mask, ".");
    while (network_addr != NULL && subnet_mask_part != NULL) {
        int network_addr_part = atoi(network_addr);
        int subnet_mask_part_int = atoi(subnet_mask_part);
        int network_addr_part_masked = network_addr_part & subnet_mask_part_int;
        char network_addr_part_masked_str[16];
        sprintf(network_addr_part_masked_str, "%d", network_addr_part_masked);
        strcat(subnet.network_addr, network_addr_part_masked_str);
        strcat(subnet.network_addr, ".");
        network_addr = strtok(NULL, ".");
        subnet_mask_part = strtok(NULL, ".");
    }

    // Calculate the broadcast address
    char *broadcast_addr = strtok(subnet.ip_addr, ".");
    subnet_mask_part = strtok(subnet.subnet_mask, ".");
    while (broadcast_addr != NULL && subnet_mask_part != NULL) {
        int broadcast_addr_part = atoi(broadcast_addr);
        int subnet_mask_part_int = atoi(subnet_mask_part);
        int broadcast_addr_part_masked = broadcast_addr_part | ~subnet_mask_part_int;
        char broadcast_addr_part_masked_str[16];
        sprintf(broadcast_addr_part_masked_str, "%d", broadcast_addr_part_masked);
        strcat(subnet.broadcast_addr, broadcast_addr_part_masked_str);
        strcat(subnet.broadcast_addr, ".");
        broadcast_addr = strtok(NULL, ".");
        subnet_mask_part = strtok(NULL, ".");
    }

    // Calculate the number of hosts
    int num_hosts_int = 0;
    subnet_mask_part = strtok(subnet.subnet_mask, ".");
    while (subnet_mask_part != NULL) {
        int subnet_mask_part_int = atoi(subnet_mask_part);
        num_hosts_int += subnet_mask_part_int ^ 255;
        subnet_mask_part = strtok(NULL, ".");
    }
    sprintf(subnet.num_hosts, "%d", num_hosts_int);

    // Print the subnet information
    printf("Network Address: %s\n", subnet.network_addr);
    printf("Broadcast Address: %s\n", subnet.broadcast_addr);
    printf("Number of Hosts: %s\n", subnet.num_hosts);

    return EXIT_SUCCESS;
}