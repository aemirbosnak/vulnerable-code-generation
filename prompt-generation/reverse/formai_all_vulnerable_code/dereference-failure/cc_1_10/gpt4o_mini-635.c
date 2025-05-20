//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void printSubnetInfo(const char *ipAddress, const char *subnetMask) {
    struct sockaddr_in sa;
    char subnet[INET_ADDRSTRLEN];
    char network[INET_ADDRSTRLEN];

    // Convert IP address and subnet mask
    inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    inet_pton(AF_INET, subnetMask, &(sa.sin_addr));

    // Calculate network address
    uint32_t ip, mask;
    ip = ntohl(*(uint32_t *)&sa.sin_addr);
    mask = ntohl(*(uint32_t *)&sa.sin_addr);

    uint32_t networkAddress = ip & mask;

    // Store the network address in the subnet array
    sa.sin_addr.s_addr = htonl(networkAddress);
    inet_ntop(AF_INET, &(sa.sin_addr), network, INET_ADDRSTRLEN);
    
    // Print Information
    printf("Given IP Address:  %s\n", ipAddress);
    printf("Given Subnet Mask: %s\n", subnetMask);
    printf("Calculated Network Address: %s\n\n", network);
}

void displayUsage() {
    printf("Usage: subnet_calc <IP_ADDRESS> <SUBNET_MASK>\n");
    printf("Example: subnet_calc 192.168.1.10 255.255.255.0\n");
}

int isValidIP(const char *ipAddress) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ipAddress, &(sa.sin_addr)) != 0;
}

int isValidMask(const char *subnetMask) {
    if (strcmp(subnetMask, "255.255.255.255") == 0) return 1;
    if (strcmp(subnetMask, "255.255.255.0") == 0) return 1;
    if (strcmp(subnetMask, "255.255.0.0") == 0) return 1;
    if (strcmp(subnetMask, "255.0.0.0") == 0) return 1;

    // further checks for valid mask if needed
    return 0;
}

void calculateSubnet(const char *ipAddress, const char *subnetMask) {
    if(!isValidIP(ipAddress)) {
        printf("Error: Invalid IP Address!\n");
        return;
    }
    if(!isValidMask(subnetMask)) {
        printf("Error: Invalid Subnet Mask!\n");
        return;
    }
    
    printSubnetInfo(ipAddress, subnetMask);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        displayUsage();
        return EXIT_FAILURE;
    }

    const char *ipAddress = argv[1];
    const char *subnetMask = argv[2];
    
    calculateSubnet(ipAddress, subnetMask);

    return EXIT_SUCCESS;
}