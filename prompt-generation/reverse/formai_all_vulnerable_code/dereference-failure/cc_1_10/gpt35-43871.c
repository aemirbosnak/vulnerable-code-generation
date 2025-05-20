//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to binary
void decimalToBinary(int decimalNum, int binaryArr[]) {
    int i = 0;
    while (decimalNum > 0) {
        binaryArr[i] = decimalNum % 2;
        decimalNum /= 2;
        i++;
    }
}

// Function to calculate the network address
void calculateNetworkAddress(int ipAddr[], int subnetMask[], int networkAddr[]) {
    for (int i = 0; i < 4; i++) {
        networkAddr[i] = ipAddr[i] & subnetMask[i];
    }
}

// Function to calculate the broadcast address
void calculateBroadcastAddress(int ipAddr[], int subnetMask[], int broadcastAddr[]) {
    int invertedSubnetMask[4] = { ~subnetMask[0], ~subnetMask[1], ~subnetMask[2], ~subnetMask[3] };
    int invertedNetworkAddr[4] = { ~ipAddr[0], ~ipAddr[1], ~ipAddr[2], ~ipAddr[3] };
    int temp[4];
    for (int i = 0; i < 4; i++) {
        temp[i] = invertedSubnetMask[i] | invertedNetworkAddr[i];
    }
    for (int i = 0; i < 4; i++) {
        broadcastAddr[i] = ~temp[i];
    }
}

int main() {
    char ipAddress[16], subnetMask[16];
    int ipAddr[4], subnetMaskOctets[4], subnetMaskBits = 0, networkAddr[4], broadcastAddr[4];
    printf("Enter an IP address (e.g. 192.168.1.1): ");
    fgets(ipAddress, 16, stdin);
    printf("Enter the subnet mask (e.g. 255.255.255.0): ");
    fgets(subnetMask, 16, stdin);
    // Splitting IP address into octets
    char* token = strtok(ipAddress, ".");
    for (int i = 0; i < 4; i++) {
        ipAddr[i] = atoi(token);
        token = strtok(NULL, ".");
    }
    // Splitting subnet mask into octets
    token = strtok(subnetMask, ".");
    for (int i = 0; i < 4; i++) {
        subnetMaskOctets[i] = atoi(token);
        // Calculating number of bits in subnet mask
        int binarySubnetMask[8] = { 0 };
        decimalToBinary(subnetMaskOctets[i], binarySubnetMask);
        for (int j = 0; j < 8; j++) {
            if (binarySubnetMask[j] == 1) {
                subnetMaskBits++;
            }
        }
        token = strtok(NULL, ".");
    }
    calculateNetworkAddress(ipAddr, subnetMaskOctets, networkAddr);
    calculateBroadcastAddress(ipAddr, subnetMaskOctets, broadcastAddr);
    printf("IP address: %d.%d.%d.%d\n", ipAddr[0], ipAddr[1], ipAddr[2], ipAddr[3]);
    printf("Subnet mask: %d.%d.%d.%d (%d bits)\n", subnetMaskOctets[0], subnetMaskOctets[1], subnetMaskOctets[2], subnetMaskOctets[3], subnetMaskBits);
    printf("Network address: %d.%d.%d.%d\n", networkAddr[0], networkAddr[1], networkAddr[2], networkAddr[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcastAddr[0], broadcastAddr[1], broadcastAddr[2], broadcastAddr[3]);
    return 0;
}