//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 3

// The Great Subnet Calculator
int main(int argc, char *argv[]) {
    // Welcome the great detective
    printf("Greetings, Detective! Let us embark on a journey of subnet calculation.\n");

    // Acquire the IP address
    char ip_address[MAX_IP_LEN];
    printf("Pray, tell me the IP address you desire to unravel:\n");
    scanf("%s", ip_address);

    // Acquire the subnet mask
    char subnet_mask[MAX_MASK_LEN];
    printf("And what is the subnet mask, my astute companion:\n");
    scanf("%s", subnet_mask);

    // Convert IP address to binary
    unsigned int ip_binary[4] = {0};
    for (int i = 0; i < 4; i++) {
        ip_binary[i] = atoi(strtok(ip_address, "."));
    }

    // Convert subnet mask to binary
    unsigned int mask_binary = 0;
    for (int i = 0; i < 4; i++) {
        mask_binary |= (1 << (32 - atoi(strtok(subnet_mask, ".")))) - 1;
    }

    // Calculate network address
    unsigned int network_address[4] = {0};
    for (int i = 0; i < 4; i++) {
        network_address[i] = ip_binary[i] & mask_binary;
    }

    // Calculate broadcast address
    unsigned int broadcast_address[4] = {0};
    for (int i = 0; i < 4; i++) {
        broadcast_address[i] = ip_binary[i] | ~mask_binary;
    }

    // Calculate the number of usable hosts
    unsigned int num_hosts = 0;
    for (int i = 0; i < 32; i++) {
        if ((mask_binary >> i) & 1) {
            num_hosts |= 1 << i;
        }
    }
    num_hosts--;

    // Present the findings
    printf("Behold, the subnet details you sought:\n");
    printf("IP Address:          %d.%d.%d.%d\n", ip_binary[0], ip_binary[1], ip_binary[2], ip_binary[3]);
    printf("Subnet Mask:         %d.%d.%d.%d\n", mask_binary >> 24, (mask_binary >> 16) & 0xFF, (mask_binary >> 8) & 0xFF, mask_binary & 0xFF);
    printf("Network Address:     %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("Broadcast Address:  %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
    printf("Usable Hosts:        %d\n", num_hosts);

    // Farewell to the great detective
    printf("My services are at your disposal, Detective. May your investigations always lead to the truth.\n");

    return 0;
}