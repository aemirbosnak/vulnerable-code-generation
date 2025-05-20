//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_MASK_LENGTH 3

void calculateSubnet(char *ip, char *mask);
void printBinary(unsigned int num);
unsigned int calculateUsableHosts(unsigned int subnetMask);
char findClass(char *ip);

int main() {
    char ip[MAX_IP_LENGTH];
    char mask[MAX_MASK_LENGTH];

    printf("Welcome to the Subnet Calculator!\n");
    printf("---------------------------------------\n");

    printf("Enter IP address (e.g., 192.168.1.1): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0;  // Remove trailing newline

    printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
    fgets(mask, sizeof(mask), stdin);
    mask[strcspn(mask, "\n")] = 0;  // Remove trailing newline

    calculateSubnet(ip, mask);

    return 0;
}

void calculateSubnet(char *ip, char *mask) {
    struct in_addr ipAddr, maskAddr, networkAddr, broadcastAddr;
    unsigned int usableHosts;

    // Convert the IP address and subnet mask to binary
    if (inet_pton(AF_INET, ip, &ipAddr) != 1) {
        printf("Invalid IP address format!\n");
        return;
    }
    if (inet_pton(AF_INET, mask, &maskAddr) != 1) {
        printf("Invalid subnet mask format!\n");
        return;
    }

    // Calculate Network Address
    networkAddr.s_addr = ipAddr.s_addr & maskAddr.s_addr;

    // Calculate Broadcast address
    broadcastAddr.s_addr = networkAddr.s_addr | ~maskAddr.s_addr;

    // Calculate Usable Hosts
    usableHosts = calculateUsableHosts(ntohl(maskAddr.s_addr));

    // Print results
    printf("\nSubnet Calculation Results:\n");
    printf("Network Address: %s\n", inet_ntoa(networkAddr));
    printf("Broadcast Address: %s\n", inet_ntoa(broadcastAddr));
    printf("Usable Hosts: %u\n", usableHosts);
    printf("Class: %c\n", findClass(ip));
}

unsigned int calculateUsableHosts(unsigned int subnetMask) {
    unsigned int hosts = (1 << (32 - __builtin_popcount(subnetMask))) - 2;
    return (hosts < 0) ? 0 : hosts;  // Ensure it doesn't go negative
}

char findClass(char *ip) {
    int firstOctet = atoi(strtok(ip, "."));
    if (firstOctet >= 1 && firstOctet <= 126) {
        return 'A';
    } else if (firstOctet >= 128 && firstOctet <= 191) {
        return 'B';
    } else if (firstOctet >= 192 && firstOctet <= 223) {
        return 'C';
    } else if (firstOctet >= 224 && firstOctet <= 239) {
        return 'D';
    } else {
        return 'E';  // Class E is reserved
    }
}

void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" ");  // Separate bytes for readability
    }
    printf("\n");
}