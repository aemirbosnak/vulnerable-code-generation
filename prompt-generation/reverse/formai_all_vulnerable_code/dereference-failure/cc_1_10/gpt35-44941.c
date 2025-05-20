//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper function to convert subnet mask into CIDR notation
int subnet_to_cidr(char* subnet_mask) {
    int cidr = 0;
    // Count the number of bits set to 1
    for (int i = 0; i < 4; i++) {
        int octet = atoi(strtok(i == 0 ? subnet_mask : NULL, "."));
        for (int j = 0; j < 8; j++) {
            if ((octet >> (7 - j)) & 1) {
                cidr++;
            }
        }
    }
    return cidr;
}

// Helper function to convert IP address into integer
unsigned int ip_to_int(char* ip_address) {
    unsigned int result = 0;
    // Parse the four octets of the IP address
    char* octet_str = strtok(ip_address, ".");
    for (int i = 0; i < 4; i++) {
        int octet = atoi(octet_str);
        result += (octet << (8 * (3 - i)));
        octet_str = strtok(NULL, ".");
    }
    return result;
}

int main() {
    // Read the IP address and subnet mask from user input
    char ip_address[16];
    char subnet_mask[16];
    printf("Enter IP address and subnet mask (e.g. 192.168.0.1/24): ");
    scanf("%15[^/]/%15s", ip_address, subnet_mask);

    // Calculate the network address, broadcast address, and IP range
    unsigned int ip = ip_to_int(ip_address);
    int cidr = atoi(subnet_mask + strlen(subnet_mask) - 2);
    unsigned int subnet_mask_int = 0xFFFFFFFFu << (32 - cidr);
    unsigned int network_address = ip & subnet_mask_int;
    unsigned int broadcast_address = network_address | ~subnet_mask_int;
    unsigned int min_address = network_address + 1;
    unsigned int max_address = broadcast_address - 1;

    // Print the results
    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Network Address: %d.%d.%d.%d\n", (network_address >> 24) & 0xFF, (network_address >> 16) & 0xFF, (network_address >> 8) & 0xFF, network_address & 0xFF);
    printf("Broadcast Address: %d.%d.%d.%d\n", (broadcast_address >> 24) & 0xFF, (broadcast_address >> 16) & 0xFF, (broadcast_address >> 8) & 0xFF, broadcast_address & 0xFF);
    printf("IP Range: %d.%d.%d.%d - %d.%d.%d.%d\n", (min_address >> 24) & 0xFF, (min_address >> 16) & 0xFF, (min_address >> 8) & 0xFF, min_address & 0xFF, (max_address >> 24) & 0xFF, (max_address >> 16) & 0xFF, (max_address >> 8) & 0xFF, max_address & 0xFF);
    printf("CIDR Notation: /%d\n", cidr);

    return 0;
}