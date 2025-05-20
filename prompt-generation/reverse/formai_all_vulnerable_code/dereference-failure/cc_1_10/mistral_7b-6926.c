//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//--------------------------------------------------------------------------------------------------
typedef struct {
    int base;
    int bits;
} SubnetMask;

//--------------------------------------------------------------------------------------------------
void ToBinary(int decNumber, char* binaryNumber) {
    int i, divisor = 1 << 31;

    memset(binaryNumber, '0', 33);

    for (i = 0; i < 32; i++) {
        if (decNumber & divisor)
            binaryNumber[31 - i] = '1';
        divisor >>= 1;
    }
}

//--------------------------------------------------------------------------------------------------
void PrintSubnet(int ipAddress, SubnetMask mask) {
    char binaryMask[33], binaryIP[33], binarySubnet[33], binaryBroadcast[33], binaryEnd[33];

    ToBinary(ipAddress, binaryIP);
    ToBinary(mask.base, binaryMask);

    int i, j, subnetSize = 1 << mask.bits;

    for (i = 0; i < mask.bits; i++) {
        if (binaryMask[32 - i] == '1') {
            for (j = 0; j < 32 - i; j++)
                binarySubnet[31 - j] = binaryIP[31 - j];
            binarySubnet[31 - i] = '1';
            break;
        }
    }

    memset(binaryBroadcast, binaryIP[0], 32);
    for (i = 0; i < subnetSize; i++)
        binaryBroadcast[31 - i] = '1';

    memset(binaryEnd, '0', 32);
    binaryEnd[31 - mask.bits] = '1';

    printf("IP Address: %s\n", binaryIP);
    printf("Subnet Mask: %s\n", binaryMask);
    printf("Subnet: %s\n", binarySubnet);
    printf("Broadcast: %s\n", binaryBroadcast);
    printf("Usable Hosts: %s\n", binaryEnd);
}

//--------------------------------------------------------------------------------------------------
int main(int argc, char** argv) {
    int ipAddress;
    int maskSize;

    if (argc != 3) {
        printf("Usage: %s <IP Address> <Subnet Mask Size>\n", argv[0]);
        return 1;
    }

    ipAddress = atoi(argv[1]);
    maskSize = atoi(argv[2]);

    if (ipAddress < 0 || maskSize < 0 || maskSize > 32) {
        printf("Invalid IP Address or Subnet Mask Size\n");
        return 1;
    }

    SubnetMask mask = {.base = (1 << maskSize) - 1, .bits = maskSize};

    PrintSubnet(ipAddress, mask);

    return 0;
}
//--------------------------------------------------------------------------------------------------