//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 15
#define MAX_MASK_LEN 2

typedef struct {
    unsigned char octets[4];
} IPAddress;

void printUsage() {
    printf("Usage: subnet_calculator <IP Address (x.x.x.x)> <Subnet Mask (x)>\n");
    printf("Example: ./subnet_calculator 192.168.1.1 24\n");
}

int isValidIp(const char* ipStr) {
    int dots = 0, value;
    char* endPtr;
    const char* p = ipStr;

    while (*p) {
        if (*p == '.') {
            dots++;
        } else if (*p < '0' || *p > '9') {
            return 0; // Invalid character
        }
        p++;
    }

    // Split by dots
    char* token = strtok(strdup(ipStr), ".");
    while (token) {
        value = atoi(token);
        if (value < 0 || value > 255) return 0; // Invalid octet
        token = strtok(NULL, ".");
    }

    return dots == 3; // Should have exactly 3 dots
}

int isValidMask(int mask) {
    return mask >= 0 && mask <= 32;
}

void convertIpToBinary(IPAddress ip, char* binaryStr) {
    for (int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            binaryStr[i * 8 + (7 - j)] = (ip.octets[i] & (1 << j)) ? '1' : '0';
        }
    }
    binaryStr[32] = '\0'; // null-terminate the string
}

void calculateSubnet(IPAddress ip, int mask, IPAddress* subnet, IPAddress* broadcast) {
    int bitmask = 0xFFFFFFFF << (32 - mask);
    for (int i = 0; i < 4; i++) {
        subnet->octets[i] = ip.octets[i] & (bitmask >> (i * 8));
        broadcast->octets[i] = subnet->octets[i] | (~(bitmask >> (i * 8)));
    }
}

void printIp(const IPAddress* ip) {
    printf("%d.%d.%d.%d", ip->octets[0], ip->octets[1], ip->octets[2], ip->octets[3]);
}

void printSubnetInfo(IPAddress ip, int mask) {
    IPAddress subnet, broadcast;
    char binaryStr[33];

    calculateSubnet(ip, mask, &subnet, &broadcast);
    convertIpToBinary(ip, binaryStr);

    printf("IP Address: ");
    printIp(&ip);
    printf("\nSubnet Mask: /%d\n", mask);
    printf("Binary IP: %s\n", binaryStr);
    printf("Subnet Address: ");
    printIp(&subnet);
    printf("\nBroadcast Address: ");
    printIp(&broadcast);
    printf("\n");
}

void parseIpAddress(const char* ipStr, IPAddress* ip) {
    sscanf(ipStr, "%hhu.%hhu.%hhu.%hhu", &ip->octets[0], &ip->octets[1], &ip->octets[2], &ip->octets[3]);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printUsage();
        return 1;
    }

    const char* ipStr = argv[1];
    int mask = atoi(argv[2]);
    IPAddress ip;

    if (!isValidIp(ipStr)) {
        printf("Error: Invalid IP address format.\n");
        return 1;
    }

    if (!isValidMask(mask)) {
        printf("Error: Invalid subnet mask. Please enter a value between 0 and 32.\n");
        return 1;
    }

    parseIpAddress(ipStr, &ip);
    printSubnetInfo(ip, mask);

    return 0;
}