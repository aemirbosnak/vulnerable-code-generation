//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the size of the octet (8 bits) and the maximum number of bits for the CIDR notation
#define OCTET_SIZE 8
#define MAX_CIDR_BITS 32

// Define a function to convert a dotted decimal IP address to binary
long long convertToBinary(char *ipAddr) {
    long long binary = 0;
    char *octet;
    int i;

    octet = strtok(ipAddr, ".");
    while (octet != NULL) {
        binary <<= OCTET_SIZE;
        binary |= atoi(octet);
        octet = strtok(NULL, ".");
    }

    return binary;
}

// Define a function to convert a binary IP address to dotted decimal notation
char *convertToDottedDecimal(long long binary) {
    char *dottedDecimal = malloc(sizeof(char) * 16);

    sprintf(dottedDecimal, "%lld.%lld.%lld.%lld", 
            (binary >> 24) & 255, (binary >> 16) & 255, (binary >> 8) & 255, binary & 255);

    return dottedDecimal;
}

// Define a function to calculate the subnet mask based on the CIDR notation
long long calculateSubnetMask(int cidrBits) {
    long long subnetMask = 0;

    if (cidrBits > MAX_CIDR_BITS) {
        printf("Invalid CIDR notation!\n");
        return 0;
    }

    for (int i = 0; i < cidrBits; i++) {
        subnetMask |= 1 << (MAX_CIDR_BITS - i - 1);
    }

    return subnetMask;
}

// Define the main function
int main() {
    char ipAddr[16];
    int cidrBits;
    long long binaryIp, subnetMask, networkId, broadcastId;
    char *dottedDecimalNetworkId, *dottedDecimalBroadcastId;

    // Prompt the user for the IP address and CIDR notation
    printf("Enter an IP address in dotted decimal notation: ");
    scanf("%s", ipAddr);
    printf("Enter the CIDR notation (between 0 and 32): ");
    scanf("%d", &cidrBits);

    // Convert the IP address to binary
    binaryIp = convertToBinary(ipAddr);

    // Calculate the subnet mask based on the CIDR notation
    subnetMask = calculateSubnetMask(cidrBits);

    // Calculate the network ID and broadcast ID based on the IP address and subnet mask
    networkId = binaryIp & subnetMask;
    broadcastId = binaryIp | (~subnetMask & ((1 << MAX_CIDR_BITS) - 1));

    // Convert the network ID and broadcast ID to dotted decimal notation
    dottedDecimalNetworkId = convertToDottedDecimal(networkId);
    dottedDecimalBroadcastId = convertToDottedDecimal(broadcastId);

    // Display the results
    printf("IP address: %s\n", ipAddr);
    printf("CIDR notation: %d\n", cidrBits);
    printf("Subnet mask: %s\n", convertToDottedDecimal(subnetMask));
    printf("Network ID: %s\n", dottedDecimalNetworkId);
    printf("Broadcast ID: %s\n", dottedDecimalBroadcastId);

    // Free the memory allocated for the dotted decimal strings
    free(dottedDecimalNetworkId);
    free(dottedDecimalBroadcastId);

    return 0;
}