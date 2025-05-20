//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to convert a string IP to a 32-bit integer
unsigned long ipToLong(const char *ip) {
    struct in_addr addr;
    inet_pton(AF_INET, ip, &addr);
    return ntohl(addr.s_addr);
}

// Function to convert a 32-bit integer to dotted-decimal string
void longToIp(unsigned long ip, char *out) {
    struct in_addr addr;
    addr.s_addr = htonl(ip);
    strcpy(out, inet_ntoa(addr));
}

// Function to calculate subnet details
void calculateSubnet(const char *ipStr, const char *maskStr) {
    unsigned long ip = ipToLong(ipStr);
    unsigned long mask = ipToLong(maskStr);
    
    unsigned long network = ip & mask; // Network Address
    unsigned long broadcast = network | ~mask; // Broadcast Address
    unsigned long firstUsable = network + 1; // First usable IP
    unsigned long lastUsable = broadcast - 1; // Last usable IP
    
    char networkStr[16], broadcastStr[16], firstUsableStr[16], lastUsableStr[16];

    longToIp(network, networkStr);
    longToIp(broadcast, broadcastStr);
    longToIp(firstUsable, firstUsableStr);
    longToIp(lastUsable, lastUsableStr);

    printf("Subnet Calculation for IP: %s and Mask: %s\n", ipStr, maskStr);
    printf("Network Address: %s\n", networkStr);
    printf("Broadcast Address: %s\n", broadcastStr);
    printf("First Usable IP: %s\n", firstUsableStr);
    printf("Last Usable IP: %s\n", lastUsableStr);
    printf("Total Usable Hosts: %lu\n", (broadcast - network - 1));
}

int main() {
    char ip[16], mask[16];

    printf("Enter an IP address (e.g., 192.168.1.1): ");
    scanf("%15s", ip);
    
    printf("Enter a subnet mask (e.g., 255.255.255.0): ");
    scanf("%15s", mask);

    // Validate IP and mask format
    if (inet_pton(AF_INET, ip, NULL) != 1) {
        fprintf(stderr, "Invalid IP address format.\n");
        return EXIT_FAILURE;
    }

    if (inet_pton(AF_INET, mask, NULL) != 1) {
        fprintf(stderr, "Invalid subnet mask format.\n");
        return EXIT_FAILURE;
    }

    // Calculate the subnet details
    calculateSubnet(ip, mask);

    return EXIT_SUCCESS;
}