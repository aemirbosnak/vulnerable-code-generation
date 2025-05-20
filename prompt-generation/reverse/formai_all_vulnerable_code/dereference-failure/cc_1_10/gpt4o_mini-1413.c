//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printUsage() {
    printf("Welcome to the C Subnet Calculator!\n");
    printf("Usage: ./subnet_calculator <IP_ADDRESS> <SUBNET_MASK>\n");
    printf("Example: ./subnet_calculator 192.168.1.10 255.255.255.0\n");
}

unsigned int ipToDecimal(const char *ip) {
    unsigned int decimal = 0;
    unsigned int octet = 0;
    
    char* token;
    char* copy = strdup(ip); // Duplicate the string to avoid modifying it
    char* rest = copy;

    while ((token = strtok_r(rest, ".", &rest))) {
        octet = atoi(token);
        decimal = (decimal << 8) | (octet & 0xFF); // Shift previous and add new octet
    }

    free(copy); // Free the duplicated string
    return decimal;
}

void calculateSubnet(unsigned int ipDecimal, unsigned int maskDecimal) {
    unsigned int network = ipDecimal & maskDecimal;
    unsigned int broadcast = network | ~maskDecimal;
    
    printf("\nIP Address: %u\n", ipDecimal);
    printf("Subnet Mask: %u\n", maskDecimal);
    printf("Network Address: %u\n", network);
    printf("Broadcast Address: %u\n", broadcast);
    
    unsigned int numberOfAddresses = (ntohl(maskDecimal) ^ 0xFFFFFFFF) + 1;
    printf("Total Addresses in Subnet: %u\n", numberOfAddresses);
}

unsigned int ipToMaskDecimal(const char *subnetMask) {
    unsigned int maskDecimal = 0;
    char *maskCopy = strdup(subnetMask);
    
    char *token;
    char *rest = maskCopy;
    
    while ((token = strtok_r(rest, ".", &rest))) {
        maskDecimal = (maskDecimal << 8) | (atoi(token) & 0xFF);
    }

    free(maskCopy);
    return maskDecimal;
}

int validateInputs(const char *ip, const char *mask) {
    int dotCountIp = 0, dotCountMask = 0;
    
    for (int i = 0; ip[i] != '\0'; i++) {
        if (ip[i] == '.') dotCountIp++;
    }
    
    for (int i = 0; mask[i] != '\0'; i++) {
        if (mask[i] == '.') dotCountMask++;
    }

    if (dotCountIp != 3 || dotCountMask != 3) {
        printf("Invalid IP Address or Subnet Mask format.\n");
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage();
        return EXIT_FAILURE;
    }

    const char *ipAddress = argv[1];
    const char *subnetMask = argv[2];

    if (!validateInputs(ipAddress, subnetMask)) {
        return EXIT_FAILURE;
    }

    unsigned int ipDecimal = ipToDecimal(ipAddress);
    unsigned int maskDecimal = ipToMaskDecimal(subnetMask);

    calculateSubnet(ipDecimal, maskDecimal);

    // Let’s add a little gratitude here
    printf("\nThank you for using the C Subnet Calculator! Have a wonderful day!\n");

    return EXIT_SUCCESS;
}