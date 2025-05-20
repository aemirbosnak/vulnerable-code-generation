//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate IP address
int isValidIP(char* ip) {
    int i, j;
    char* token;

    // Split the IP address into four parts
    token = strtok(ip, ".");
    i = atoi(token);
    if (i < 0 || i > 255) {
        return 0;
    }
    token = strtok(NULL, ".");
    j = atoi(token);
    if (j < 0 || j > 255) {
        return 0;
    }
    token = strtok(NULL, ".");
    i = atoi(token);
    if (i < 0 || i > 255) {
        return 0;
    }
    token = strtok(NULL, ".");
    j = atoi(token);
    if (j < 0 || j > 255) {
        return 0;
    }

    // If all parts are valid, return 1
    return 1;
}

// Function to calculate subnet mask
void calculateSubnetMask(int subnetBits, char* ip, char* mask) {
    int i, j;
    char* token;

    // Split the IP address into four parts
    token = strtok(ip, ".");
    i = atoi(token);
    j = 8 - subnetBits;
    sprintf(mask, "%d.%d.%d.%d", i, i, i, (255 << j) & 255);
}

// Function to calculate broadcast address
void calculateBroadcastAddress(char* ip, char* mask) {
    int i, j;
    char* token;

    // Split the IP address into four parts
    token = strtok(ip, ".");
    i = atoi(token);
    j = 8 - strlen(mask);
    sprintf(mask, "%d.%d.%d.%d", i | (~atoi(mask) & 255), i | (~atoi(mask) & 255), i | (~atoi(mask) & 255), 255);
}

// Function to calculate number of hosts in a subnet
int calculateNumberOfHosts(char* mask) {
    int i, j;
    char* token;

    // Split the subnet mask into four parts
    token = strtok(mask, ".");
    i = atoi(token);
    j = 8 - strlen(mask);
    return (256 - (255 << j)) & 0xFF;
}

// Main function
int main(int argc, char* argv[]) {
    char ip[16];
    char mask[16];

    // Check if the correct number of arguments are provided
    if (argc!= 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    // Validate the IP address
    if (!isValidIP(argv[1])) {
        printf("Invalid IP address.\n");
        return 1;
    }

    // Copy the IP address to a local variable
    strcpy(ip, argv[1]);

    // Calculate the subnet mask
    calculateSubnetMask(24, ip, mask);

    // Print the results
    printf("IP address: %s\n", ip);
    printf("Subnet mask: %s\n", mask);
    printf("Number of hosts: %d\n", calculateNumberOfHosts(mask));

    return 0;
}