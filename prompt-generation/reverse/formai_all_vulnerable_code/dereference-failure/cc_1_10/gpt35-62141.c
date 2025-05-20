//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
/* C Subnet Calculator Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) { // check if command line arguments are valid
        printf("Usage: %s <IP Address> <Subnet Mask>\n", argv[0]);
        return 0;
    }

    char *ipAddr = argv[1];
    char *subnetMask = argv[2];

    // convert IP address to binary
    char *token = strtok(ipAddr, ".");
    int ipBinary[4];
    int i = 0;
    while (token != NULL) {
        int octet = atoi(token);
        ipBinary[i++] = octet;
        token = strtok(NULL, ".");
    }

    // convert subnet mask to binary
    token = strtok(subnetMask, ".");
    int maskBinary[4];
    i = 0;
    while (token != NULL) {
        int octet = atoi(token);
        maskBinary[i++] = octet;
        token = strtok(NULL, ".");
    }

    // calculate network address
    int netBinary[4];
    for (i = 0; i < 4; i++) {
        netBinary[i] = ipBinary[i] & maskBinary[i];
    }

    // calculate broadcast address
    int bcastBinary[4];
    for (i = 0; i < 4; i++) {
        bcastBinary[i] = netBinary[i] | (255 - maskBinary[i]);
    }

    // print results
    printf("IP Address: %s\n", ipAddr);
    printf("Subnet Mask: %s\n", subnetMask);
    printf("Network Address: %d.%d.%d.%d\n", netBinary[0], netBinary[1], netBinary[2], netBinary[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", bcastBinary[0], bcastBinary[1], bcastBinary[2], bcastBinary[3]);

    return 0;
}