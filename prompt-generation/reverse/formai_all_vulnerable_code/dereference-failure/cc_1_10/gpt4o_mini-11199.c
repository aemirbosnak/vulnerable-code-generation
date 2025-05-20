//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_IP_SEGMENTS 4
#define MAX_SUBNET_BITS 32

void printBinary(uint32_t num) {
    for (int i = MAX_SUBNET_BITS - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) {
            printf(" "); // Grouping by bytes for readability
        }
    }
}

uint32_t ipToDecimal(const char *ipStr) {
    uint32_t ip = 0;
    int segment;
    char temp[4];
    int count = 0;

    for (int i = 0; i < MAX_IP_SEGMENTS; i++) {
        segment = strtol(ipStr, &temp, 10);
        ip = (ip << 8) | (segment & 0xFF);
        ipStr = temp + 1; // Move to the next segment
    }
    return ip;
}

void decimalToIP(uint32_t ip) {
    printf("IP Address: %d.%d.%d.%d\n", 
        (ip >> 24) & 0xFF, 
        (ip >> 16) & 0xFF,
        (ip >> 8) & 0xFF, 
        ip & 0xFF);
}

uint32_t calculateSubnetMask(int subnetBits) {
    return ~((1 << (MAX_SUBNET_BITS - subnetBits)) - 1);
}

void printSubnetInfo(uint32_t ip, uint32_t mask) {
    uint32_t networkAddress = ip & mask;
    uint32_t broadcastAddress = networkAddress | ~mask;
    
    printf("Network Address: ");
    decimalToIP(networkAddress);
    
    printf("Broadcast Address: ");
    decimalToIP(broadcastAddress);
    
    printf("Subnet Mask: ");
    decimalToIP(mask);

    printf("Binary Representation:\n");
    printf("IP: ");
    printBinary(ip);
    printf("\nSubnet Mask: ");
    printBinary(mask);
    printf("\nNetwork Address: ");
    printBinary(networkAddress);
    printf("\nBroadcast Address: ");
    printBinary(broadcastAddress);
}

int main() {
    char ipStr[16];
    int subnetBits;

    printf("Welcome to the Magical C Subnet Calculator!\n");
    printf("Please enter your lovely IP address (e.g., 192.168.1.1): ");
    scanf("%15s", ipStr);

    printf("Now, tell me the number of subnet bits (example: 24): ");
    scanf("%d", &subnetBits);
    
    if (subnetBits < 0 || subnetBits > MAX_SUBNET_BITS) {
        printf("Oh no! That's an invalid number of subnet bits.\n");
        return 1;
    }

    uint32_t ipDecimal = ipToDecimal(ipStr);
    uint32_t subnetMask = calculateSubnetMask(subnetBits);
    
    printf("\nLet's unravel the mysteries of your IP!\n");
    printSubnetInfo(ipDecimal, subnetMask);

    printf("\nThank you for using the Magical C Subnet Calculator!\n");
    printf("May your networks always be subnetted smartly!\n");

    return 0;
}