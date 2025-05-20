//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define IP_STR_LEN 16
#define MAX_BITS 32

void printUsage() {
    printf("Usage: ./subnet_calculator <IP Address> <Subnet Mask>\n");
    printf("Example: ./subnet_calculator 192.168.1.1 255.255.255.0\n");
}

int validateIP(const char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) == 1;
}

int validateSubnetMask(const char *mask) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, mask, &(sa.sin_addr)) == 1 || strcmp(mask, "0") == 0;
}

void calculateSubnet(const char *ip, const char *mask) {
    struct in_addr ipAddr, maskAddr;
    struct in_addr networkAddr, broadcastAddr;
    unsigned int subnetMask, numUsableHosts;

    // Convert strings to in_addr structs
    inet_pton(AF_INET, ip, &ipAddr);
    inet_pton(AF_INET, mask, &maskAddr);
     
    // Bitwise AND to find Network Address
    networkAddr.s_addr = ipAddr.s_addr & maskAddr.s_addr;

    // Bitwise OR with NOT to find Broadcast Address
    broadcastAddr.s_addr = networkAddr.s_addr | ~maskAddr.s_addr;
    
    // Calculate number of usable hosts
    subnetMask = ntohl(maskAddr.s_addr);
    numUsableHosts = (1 << (MAX_BITS - __builtin_popcount(subnetMask))) - 2;

    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", mask);
    printf("Network Address: %s\n", inet_ntoa(networkAddr));
    printf("Broadcast Address: %s\n", inet_ntoa(broadcastAddr));
    printf("Number of Usable Hosts: %u\n", numUsableHosts);
}

int main(int argc, char *argv[]) {
    // Ensure correct number of arguments
    if (argc != 3) {
        printUsage();
        return EXIT_FAILURE;
    }

    const char *ipAddress = argv[1];
    const char *subnetMask = argv[2];

    // Validate IP Address and Subnet Mask
    if (!validateIP(ipAddress)) {
        fprintf(stderr, "Invalid IP Address: %s\n", ipAddress);
        return EXIT_FAILURE;
    }

    if (!validateSubnetMask(subnetMask)) {
        fprintf(stderr, "Invalid Subnet Mask: %s\n", subnetMask);
        return EXIT_FAILURE;
    }

    // Calculate and display subnet information
    calculateSubnet(ipAddress, subnetMask);

    return EXIT_SUCCESS;
}