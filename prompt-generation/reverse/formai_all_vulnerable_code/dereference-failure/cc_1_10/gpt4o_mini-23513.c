//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_MASK_LENGTH 3

void calculateSubnet(char *ip, char *mask);
void printBinary(unsigned int num);
unsigned int ipToDecimal(char *ip);
void decimalToIp(unsigned int decimal, char *ip);
unsigned int calculateHosts(unsigned int subnetMask);
unsigned int calculateNetworkAddress(unsigned int ipDecimal, unsigned int maskDecimal);
unsigned int calculateBroadcastAddress(unsigned int networkDecimal, unsigned int invertedMaskDecimal);

int main() {
    char ip[MAX_IP_LENGTH], mask[MAX_MASK_LENGTH];
    char choice;

    printf("Welcome to the Subnet Calculator!\n");

    do {
        printf("Please enter an IPv4 address (e.g., 192.168.1.1): ");
        scanf("%s", ip);

        printf("Please enter a subnet mask (e.g., 255.255.255.0 or CIDR notation 24): ");
        scanf("%s", mask);
        
        calculateSubnet(ip, mask);

        printf("\nDo you want to perform another calculation? (y/n): ");
        getchar();  // To consume the newline character left in buffer
        choice = getchar();
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Subnet Calculator. Goodbye!\n");
    return 0;
}

void calculateSubnet(char *ip, char *mask) {
    struct in_addr ipAddr, maskAddr;
    if (inet_pton(AF_INET, ip, &ipAddr) != 1) {
        printf("Invalid IP address format.\n");
        return;
    }

    unsigned int ipDecimal = ntohl(ipAddr.s_addr);
    unsigned int maskDecimal;

    // Check if the mask is in CIDR notation or dot-decimal notation
    if (strchr(mask, '.') != NULL) {
        if (inet_pton(AF_INET, mask, &maskAddr) != 1) {
            printf("Invalid subnet mask format.\n");
            return;
        }
        maskDecimal = ntohl(maskAddr.s_addr);
    } else {
        int cidr = atoi(mask);
        if (cidr < 0 || cidr > 32) {
            printf("Invalid CIDR value.\n");
            return;
        }
        maskDecimal = ~((1 << (32 - cidr)) - 1);
    }

    unsigned int invertedMaskDecimal = ~maskDecimal;
    unsigned int networkAddress = calculateNetworkAddress(ipDecimal, maskDecimal);
    unsigned int broadcastAddress = calculateBroadcastAddress(networkAddress, invertedMaskDecimal);
    unsigned int totalHosts = calculateHosts(maskDecimal);
    unsigned int validHosts = totalHosts - 2; // Subtract network and broadcast addresses

    char networkIp[MAX_IP_LENGTH], broadcastIp[MAX_IP_LENGTH];
    decimalToIp(networkAddress, networkIp);
    decimalToIp(broadcastAddress, broadcastIp);

    printf("\n--- Subnet Calculation Results ---\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", mask);
    printf("Network Address: %s\n", networkIp);
    printf("Broadcast Address: %s\n", broadcastIp);
    printf("Total Hosts: %u\n", totalHosts);
    printf("Valid Hosts: %u\n", validHosts);
    printf("Subnet Mask in Binary: ");
    printBinary(maskDecimal);
    printf("Inverted Subnet Mask in Binary: ");
    printBinary(invertedMaskDecimal);
    printf("----------------------------------\n");
}

void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) {
            printf(" "); // Grouping bits for readability
        }
    }
    printf("\n");
}

unsigned int ipToDecimal(char *ip) {
    struct in_addr addr;
    inet_pton(AF_INET, ip, &addr);
    return ntohl(addr.s_addr);
}

void decimalToIp(unsigned int decimal, char *ip) {
    struct in_addr addr;
    addr.s_addr = htonl(decimal);
    strcpy(ip, inet_ntoa(addr));
}

unsigned int calculateHosts(unsigned int subnetMask) {
    unsigned int hostBits = 32 - __builtin_popcount(subnetMask);
    return (1 << hostBits); // 2^hostBits
}

unsigned int calculateNetworkAddress(unsigned int ipDecimal, unsigned int maskDecimal) {
    return ipDecimal & maskDecimal;
}

unsigned int calculateBroadcastAddress(unsigned int networkDecimal, unsigned int invertedMaskDecimal) {
    return networkDecimal | invertedMaskDecimal;
}