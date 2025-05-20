//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Subnet {
    int subnetMask;
    int numberOfAddresses;
    int bitsForNetwork;
    int bitsForSubnet;
    int bitsForHost;
};

void decimalToBinary(int *binary, int decimal, int size) {
    int i;
    for(i = size - 1; i >= 0; i--) {
        binary[i] = decimal%2;
        decimal /= 2;
    }
}

int binaryToDecimal(int *binary, int size) {
    int decimal = 0;
    int multiplier = 1;
    int i;
    for(i = size - 1; i >= 0; i--) {
        decimal += multiplier*binary[i];
        multiplier *= 2;
    }
    return decimal;
}

int getSubnetMask(int bitsForNetwork, int bitsForSubnet) {
    int i;
    int subnetMask = 0;
    for(i = 0; i < 32; i++) {
        if(i < bitsForNetwork) {
            subnetMask |= 1 << (31 - i);
        }
        else if(i < bitsForNetwork + bitsForSubnet) {
            subnetMask |= 0 << (31 - i);
        }
        else {
            subnetMask |= 0 << (31 - i);
        }
    }
    return subnetMask;
}

int getNumberOfAddresses(int bitsForHost) {
    return (1 << bitsForHost) - 2;
}

struct Subnet *calculateSubnet(int ipAddress[], int subnetBits) {
    struct Subnet *subnet = (struct Subnet *)malloc(sizeof(struct Subnet));
    int bitsForNetwork = 0;
    int bitsForSubnet = subnetBits;
    int bitsForHost = 32 - bitsForNetwork - bitsForSubnet;

    subnet->subnetMask = getSubnetMask(bitsForNetwork, bitsForSubnet);
    subnet->bitsForNetwork = bitsForNetwork;
    subnet->bitsForSubnet = bitsForSubnet;
    subnet->bitsForHost = bitsForHost;
    subnet->numberOfAddresses = getNumberOfAddresses(bitsForHost);

    return subnet;
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: ./subnetCalculator <IP Address>/<Subnet>\n");
        return 0;
    }

    char *ipAddressString = strtok(argv[1], "/");
    char *subnetString = strtok(NULL, "/");

    int ipAddress[4];
    sscanf(ipAddressString, "%d.%d.%d.%d", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);

    int subnetBits = atoi(subnetString);

    struct Subnet *subnet = calculateSubnet(ipAddress, subnetBits);

    printf("IP Address: %s\n", ipAddressString);
    printf("Subnet Mask: %d.%d.%d.%d\n", (subnet->subnetMask >> 24) & 0xff, (subnet->subnetMask >> 16) & 0xff, (subnet->subnetMask >> 8) & 0xff, subnet->subnetMask & 0xff);
    printf("Number of Addresses: %d\n", subnet->numberOfAddresses);
    printf("Bits for Network: %d\n", subnet->bitsForNetwork);
    printf("Bits for Subnet: %d\n", subnet->bitsForSubnet);
    printf("Bits for Host: %d\n", subnet->bitsForHost);

    free(subnet);

    return 0;
}