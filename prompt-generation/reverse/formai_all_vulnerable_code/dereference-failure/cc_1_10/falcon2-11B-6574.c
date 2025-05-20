//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate subnet, broadcast, and usable IP addresses
void calculateSubnet(char *ip, char *mask) {
    char *subnet = (char*)malloc(sizeof(char) * 8);
    char *broadcast = (char*)malloc(sizeof(char) * 8);
    int usableIPs = 0;

    // Convert IP and mask to binary
    int i;
    int ipBinary[32] = {0};
    int maskBinary[32] = {0};
    int maskLength = strlen(mask);
    for (i = 0; i < maskLength; i++) {
        maskBinary[i] = mask[i] - '0';
    }
    for (i = 0; i < strlen(ip); i++) {
        ipBinary[i] = ip[i] - '0';
    }

    // Calculate subnet and broadcast
    for (i = 0; i < 32; i++) {
        if (maskBinary[i] == 0) {
            subnet[i] = '1';
            broadcast[i] = '1';
            continue;
        }
        if (ipBinary[i] == 1 && maskBinary[i] == 1) {
            subnet[i] = '0';
            broadcast[i] = '1';
        } else if (ipBinary[i] == 0 && maskBinary[i] == 0) {
            subnet[i] = '0';
            broadcast[i] = '0';
        } else {
            subnet[i] = '1';
            broadcast[i] = '0';
        }
        if (subnet[i] == '1' || broadcast[i] == '1') {
            usableIPs++;
        }
    }

    // Print results
    printf("Subnet: %s\n", subnet);
    printf("Broadcast: %s\n", broadcast);
    printf("Number of usable IP addresses: %d\n", usableIPs);
}

int main() {
    char ip[16] = "192.168.1.0";
    char mask[16] = "255.255.255.0";
    calculateSubnet(ip, mask);
    return 0;
}