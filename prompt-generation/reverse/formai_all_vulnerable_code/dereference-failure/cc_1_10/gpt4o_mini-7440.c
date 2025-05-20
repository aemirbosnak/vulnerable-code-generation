//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_LENGTH 3

void calculateSubnet(char *ipAddress, char *subnetMask) {
    struct in_addr ip, netmask, network, broadcast;
    int prefixLength;

    // Convert IP address and subnet mask to binary
    if (inet_pton(AF_INET, ipAddress, &ip) != 1) {
        fprintf(stderr, "Invalid IP address format: %s\n", ipAddress);
        exit(EXIT_FAILURE);
    }
    if (inet_pton(AF_INET, subnetMask, &netmask) != 1) {
        fprintf(stderr, "Invalid subnet mask format: %s\n", subnetMask);
        exit(EXIT_FAILURE);
    }

    // Calculate network and broadcast addresses
    network.s_addr = ip.s_addr & netmask.s_addr;
    broadcast.s_addr = network.s_addr | ~netmask.s_addr;

    // Calculate prefix length
    prefixLength = __builtin_popcount(ntohl(netmask.s_addr));

    printf("\nIP Address: %s\n", ipAddress);
    printf("Subnet Mask: %s\n", subnetMask);
    printf("Network Address: %s\n", inet_ntoa(network));
    printf("Broadcast Address: %s\n", inet_ntoa(broadcast));
    printf("CIDR Notation: /%d\n", prefixLength);
}

void getInput(char *ipAddress, char *subnetMask) {
    printf("Enter IP Address (e.g. 192.168.1.1): ");
    fgets(ipAddress, MAX_IP_LENGTH, stdin);
    ipAddress[strcspn(ipAddress, "\n")] = '\0';  // Remove newline character

    printf("Enter Subnet Mask (e.g. 255.255.255.0): ");
    fgets(subnetMask, MAX_SUBNET_LENGTH, stdin);
    subnetMask[strcspn(subnetMask, "\n")] = '\0';  // Remove newline character
}

int main(int argc, char *argv[]) {
    char ipAddress[MAX_IP_LENGTH];
    char subnetMask[MAX_SUBNET_LENGTH];

    if (argc == 3) {
        strncpy(ipAddress, argv[1], MAX_IP_LENGTH);
        strncpy(subnetMask, argv[2], MAX_SUBNET_LENGTH);
    } else {
        getInput(ipAddress, subnetMask);
    }

    calculateSubnet(ipAddress, subnetMask);
    return 0;
}