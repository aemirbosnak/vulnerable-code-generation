//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define IPV4_LEN 16
#define MAX_SUBNETS 256

void calculateSubnet(uint32_t ip, uint32_t subnetMask) {
    uint32_t networkAddr = ip & subnetMask;
    uint32_t broadcastAddr = networkAddr | ~subnetMask;
    uint32_t totalAddresses = ~subnetMask + 1;

    printf("Network Address: %u.%u.%u.%u\n", 
           (networkAddr >> 24) & 0xFF, 
           (networkAddr >> 16) & 0xFF, 
           (networkAddr >> 8) & 0xFF, 
           networkAddr & 0xFF);
           
    printf("Broadcast Address: %u.%u.%u.%u\n", 
           (broadcastAddr >> 24) & 0xFF, 
           (broadcastAddr >> 16) & 0xFF, 
           (broadcastAddr >> 8) & 0xFF, 
           broadcastAddr & 0xFF);
    
    printf("Total Addresses: %u\n", totalAddresses);
    printf("Usable IP Addresses: %u\n", totalAddresses - 2);
}

uint32_t ipToInt(const char* ip) {
    uint32_t result = 0;
    int octet;
    char* ptr = strdup(ip);
    char* token = strtok(ptr, ".");

    while (token != NULL) {
        octet = atoi(token);
        result = (result << 8) | (octet & 0xFF);
        token = strtok(NULL, ".");
    }

    free(ptr);
    return result;
}

uint32_t maskToInt(const char* mask) {
    int maskBits = atoi(mask);
    return (maskBits == 0) ? 0 : (0xFFFFFFFF << (32 - maskBits));
}

void printHelp() {
    printf("Subnet Calculator\n");
    printf("Usage: ./subnet_calculator <IP_Address> <Subnet_Mask>\n");
    printf("Example: ./subnet_calculator 192.168.1.10 24\n");
    printf("The subnet mask can be provided in CIDR notation (e.g., 24) or in dotted-decimal format (e.g., 255.255.255.0).\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printHelp();
        return 1;
    }

    // Converting IP Address to Integer
    uint32_t ip = ipToInt(argv[1]);
    
    // Handling CIDR Method
    uint32_t subnetMask = 0;
    if (strchr(argv[2], '.') != NULL) {
        subnetMask = ipToInt(argv[2]);
    } else {
        subnetMask = maskToInt(argv[2]);
    }

    // Validating IP and Subnet
    if (subnetMask == 0) {
        printf("Invalid subnet mask.\n");
        return 1;
    }

    // Calculating Subnet Details
    calculateSubnet(ip, subnetMask);

    return 0;
}