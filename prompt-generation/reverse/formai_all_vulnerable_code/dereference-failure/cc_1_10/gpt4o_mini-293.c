//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define IP_SIZE 16
#define MASK_SIZE 16

void print_menu() {
    printf("=== Subnet Calculator ===\n");
    printf("Enter the IP address and subnet mask to calculate the subnet details.\n");
    printf("Press 'q' to quit.\n");
}

void calculate_subnet(char *ip_address, char *subnet_mask) {
    struct in_addr ip, mask, network, broadcast;
    unsigned int ip_arr[4], mask_arr[4], network_arr[4], broadcast_arr[4];
    
    // Convert IP and mask from string to struct
    if (inet_pton(AF_INET, ip_address, &ip) == 0) {
        printf("Invalid IP address format.\n");
        return;
    }
    if (inet_pton(AF_INET, subnet_mask, &mask) == 0) {
        printf("Invalid subnet mask format.\n");
        return;
    }
    
    // Calculate the network address
    network.s_addr = ip.s_addr & mask.s_addr;
    // Calculate the broadcast address
    broadcast.s_addr = network.s_addr | ~mask.s_addr;

    // Convert IPs to arrays
    memcpy(ip_arr, &ip.s_addr, sizeof(ip_arr));
    memcpy(mask_arr, &mask.s_addr, sizeof(mask_arr));
    memcpy(network_arr, &network.s_addr, sizeof(network_arr));
    memcpy(broadcast_arr, &broadcast.s_addr, sizeof(broadcast_arr));

    // Output results
    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Network Address: %d.%d.%d.%d\n",
           network_arr[0], network_arr[1], network_arr[2], network_arr[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n",
           broadcast_arr[0], broadcast_arr[1], broadcast_arr[2], broadcast_arr[3]);

    // Calculate usable range
    printf("Usable IP Range: %d.%d.%d.%d - %d.%d.%d.%d\n",
           network_arr[0], network_arr[1], network_arr[2], network_arr[3] + 1,
           broadcast_arr[0], broadcast_arr[1], broadcast_arr[2], broadcast_arr[3] - 1);
}

int main() {
    char ip_address[IP_SIZE], subnet_mask[MASK_SIZE];
  
    print_menu();
    while (1) {
        printf("\nEnter IP Address (or q to quit): ");
        fgets(ip_address, sizeof(ip_address), stdin);
        ip_address[strcspn(ip_address, "\n")] = 0; // Remove newline character

        if (strcmp(ip_address, "q") == 0) {
            break; // Exit the loop if user wants to quit
        }

        printf("Enter Subnet Mask: ");
        fgets(subnet_mask, sizeof(subnet_mask), stdin);
        subnet_mask[strcspn(subnet_mask, "\n")] = 0; // Remove newline character

        calculate_subnet(ip_address, subnet_mask);
    }

    printf("Goodbye!\n");
    return 0;
}