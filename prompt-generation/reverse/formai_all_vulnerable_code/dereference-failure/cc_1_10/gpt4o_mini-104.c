//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void splitIP(char *ip, int *ipParts);
void splitMask(char *mask, int *maskParts);
void calculateSubnet(int *ipParts, int *maskParts, int *subnetParts, int *broadcastParts);
void displayResults(int *ipParts, int *maskParts, int *subnetParts, int *broadcastParts);

int main() {
    char ip[16], mask[16];
    int ipParts[4];
    int maskParts[4];
    int subnetParts[4];
    int broadcastParts[4];

    printf("Welcome to the C Subnet Calculator!\n");
    printf("You can calculate subnets based on your IP address and subnet mask.\n");
    
    // Get user input
    printf("Enter your IP address (xxx.xxx.xxx.xxx): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = '\0'; // Remove newline character

    printf("Enter your Subnet Mask (xxx.xxx.xxx.xxx): ");
    fgets(mask, sizeof(mask), stdin);
    mask[strcspn(mask, "\n")] = '\0'; // Remove newline character

    // Split the IP and mask into their components
    splitIP(ip, ipParts);
    splitMask(mask, maskParts);

    // Calculate subnet and broadcast addresses
    calculateSubnet(ipParts, maskParts, subnetParts, broadcastParts);

    // Display results
    displayResults(ipParts, maskParts, subnetParts, broadcastParts);

    return 0;
}

void splitIP(char *ip, int *ipParts) {
    char *token = strtok(ip, ".");
    for (int i = 0; i < 4; i++) {
        ipParts[i] = atoi(token);
        token = strtok(NULL, ".");
    }
}

void splitMask(char *mask, int *maskParts) {
    char *token = strtok(mask, ".");
    for (int i = 0; i < 4; i++) {
        maskParts[i] = atoi(token);
        token = strtok(NULL, ".");
    }
}

void calculateSubnet(int *ipParts, int *maskParts, int *subnetParts, int *broadcastParts) {
    for (int i = 0; i < 4; i++) {
        subnetParts[i] = ipParts[i] & maskParts[i];
        broadcastParts[i] = subnetParts[i] | (~maskParts[i] & 255);
    }
}

void displayResults(int *ipParts, int *maskParts, int *subnetParts, int *broadcastParts) {
    printf("\n--- Subnet Calculation Results ---\n");
    printf("IP Address: %d.%d.%d.%d\n", ipParts[0], ipParts[1], ipParts[2], ipParts[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", maskParts[0], maskParts[1], maskParts[2], maskParts[3]);
    printf("Calculated Subnet Address: %d.%d.%d.%d\n",
           subnetParts[0], subnetParts[1], subnetParts[2], subnetParts[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n",
           broadcastParts[0], broadcastParts[1], broadcastParts[2], broadcastParts[3]);
    
    printf("\nThank you for using the C Subnet Calculator!\n");
}