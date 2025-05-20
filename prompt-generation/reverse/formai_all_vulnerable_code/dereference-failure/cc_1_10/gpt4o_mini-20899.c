//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_OCTET 255
#define MIN_OCTET 0
#define MAX_SUBNET_MASK 32
#define MIN_SUBNET_MASK 0

// Function prototypes
void printUsage();
int isValidIPAddress(char *ip);
int isValidSubnetMask(int mask);
void calculateSubnetDetails(char *ip, int mask);
void convertToBinary(unsigned char octet, char *binary);
void displaySubnetDetails(unsigned char *network, unsigned char *broadcast, int hostCount);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage();
        return 1; // Incorrect usage
    }

    char *ipAddress = argv[1];
    int subnetMask = atoi(argv[2]);

    if (!isValidIPAddress(ipAddress)) {
        printf("Invalid IP Address format.\n");
        return 1;
    }

    if (!isValidSubnetMask(subnetMask)) {
        printf("Invalid Subnet Mask. Must be between 0 and 32.\n");
        return 1;
    }

    calculateSubnetDetails(ipAddress, subnetMask);
    return 0;
}

void printUsage() {
    printf("Usage: ./subnet_calculator <IP Address> <Subnet Mask>\n");
    printf("Example: ./subnet_calculator 192.168.1.10 24\n");
}

int isValidIPAddress(char *ip) {
    int octets[4];
    return sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) == 4 &&
           octets[0] >= MIN_OCTET && octets[0] <= MAX_OCTET &&
           octets[1] >= MIN_OCTET && octets[1] <= MAX_OCTET &&
           octets[2] >= MIN_OCTET && octets[2] <= MAX_OCTET &&
           octets[3] >= MIN_OCTET && octets[3] <= MAX_OCTET;
}

int isValidSubnetMask(int mask) {
    return mask >= MIN_SUBNET_MASK && mask <= MAX_SUBNET_MASK;
}

void calculateSubnetDetails(char *ip, int mask) {
    unsigned char ipParts[4];
    unsigned char subnetMask[4] = {0, 0, 0, 0};
    unsigned char network[4], broadcast[4];
    int hostCount;

    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);

    // Calculate subnet mask in binary
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            if (mask > 0) {
                subnetMask[i] |= (1 << (7 - j));
                mask--;
            }
        }
    }

    // Calculate network address
    for (int i = 0; i < 4; i++) {
        network[i] = ipParts[i] & subnetMask[i];
        broadcast[i] = network[i] | ~subnetMask[i] & MAX_OCTET;
    }

    // Calculate the number of hosts
    hostCount = (1 << (32 - __builtin_ctz(*((int *)subnetMask)))) - 2;

    // Display results
    displaySubnetDetails(network, broadcast, hostCount);
}

void displaySubnetDetails(unsigned char *network, unsigned char *broadcast, int hostCount) {
    printf("Network Address: %u.%u.%u.%u\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %u.%u.%u.%u\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Total Hosts in Subnet: %d\n", hostCount);
}