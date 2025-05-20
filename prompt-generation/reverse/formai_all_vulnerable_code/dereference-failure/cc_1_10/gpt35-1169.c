//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

// Function to convert an IPv4 address to binary format
void convertToBinary(char ipAddr[], int binaryIpAddr[]) {
    int a, b, c, d;
    sscanf(ipAddr, "%d.%d.%d.%d", &a, &b, &c, &d);

    binaryIpAddr[0] = a;
    binaryIpAddr[1] = b;
    binaryIpAddr[2] = c;
    binaryIpAddr[3] = d;
}

// Function to print an IPv4 address in binary format
void printBinaryIpAddr(int binaryIpAddr[]) {
    printf("%d.%d.%d.%d", binaryIpAddr[0], binaryIpAddr[1], binaryIpAddr[2], binaryIpAddr[3]);
}

// Function to calculate the subnet mask from the prefix length 
void calculateSubnetMask(int prefixLength, int subnetMask[]) {
    int i, j, bits, mask = 0;

    for (i = 0; i < prefixLength; i++) {
        bits = 7 - i % 8;
        mask += pow(2, bits);
        if (bits == 0) {
            subnetMask[i/8] = mask;
            mask = 0;
        }
    }

    if (prefixLength % 8 != 0) {
        subnetMask[prefixLength/8] = mask;
    }

    for (i = prefixLength/8 + 1; i < 4; i++) {
        subnetMask[i] = 0;
    }
}

// Function to print a subnet mask in binary format
void printBinarySubnetMask(int subnetMask[]) {
    printf("%d.%d.%d.%d", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
}

int main() {
    char ipAddr[MAX_INPUT_SIZE];
    int prefixLength, binaryIpAddr[4], subnetMask[4], networkAddr[4], broadcastAddr[4];
    char choice, subnetChoice;

    printf("Enter an IPv4 address: ");
    fgets(ipAddr, MAX_INPUT_SIZE, stdin);
    ipAddr[strcspn(ipAddr, "\n")] = 0;

    printf("Enter the prefix length: ");
    scanf("%d", &prefixLength);

    // Calculate and print the binary form of the given IPv4 address
    convertToBinary(ipAddr, binaryIpAddr);
    printf("\nBinary form of %s is: ", ipAddr);
    printBinaryIpAddr(binaryIpAddr);
    printf("\n");

    // Calculate and print the subnet mask in binary form
    calculateSubnetMask(prefixLength, subnetMask);
    printf("\nThe subnet mask is: ");
    printBinarySubnetMask(subnetMask);
    printf("\n");

    // Calculate and print the network address
    for (int i = 0; i < 4; i++) {
        networkAddr[i] = binaryIpAddr[i] & subnetMask[i];
    }
    printf("\nThe network address is: ");
    printBinaryIpAddr(networkAddr);
    printf("\n");

    // Calculate and print the broadcast address
    for (int i = 0; i < 4; i++) {
        broadcastAddr[i] = networkAddr[i] | ~subnetMask[i] & 0xFF;
    }
    printf("\nThe broadcast address is: ");
    printBinaryIpAddr(broadcastAddr);
    printf("\n");
    
    printf("\nDo you want to calculate another subnet? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        printf("\nEnter the subnet prefix length: ");
        scanf("%d", &prefixLength);

        printf("\nDo you want to calculate the network and broadcast addresses for this subnet? (y/n): ");
        scanf(" %c", &subnetChoice);

        if (subnetChoice == 'y' || subnetChoice == 'Y') {
            calculateSubnetMask(prefixLength, subnetMask);
            printf("\nThe subnet mask is: ");
            printBinarySubnetMask(subnetMask);
            printf("\n");

            for (int i = 0; i < 4; i++) {
                networkAddr[i] = binaryIpAddr[i] & subnetMask[i];
            }
            printf("\nThe network address for this subnet is: ");
            printBinaryIpAddr(networkAddr);
            printf("\n");

            for (int i = 0; i < 4; i++) {
                broadcastAddr[i] = networkAddr[i] | ~subnetMask[i] & 0xFF;
            }
            printf("\nThe broadcast address for this subnet is: ");
            printBinaryIpAddr(broadcastAddr);
            printf("\n");
        }

        printf("\nDo you want to calculate another subnet? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("\nThank you for using the subnet calculator!\n");

    return 0;
}