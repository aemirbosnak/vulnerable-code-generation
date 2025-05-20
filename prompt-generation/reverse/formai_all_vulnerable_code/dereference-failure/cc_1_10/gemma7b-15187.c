//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void subnetCalculator(char *mask, int currentBit, int totalBits)
{
    char subnetMask[32] = "";
    int i = 0;

    // Calculate subnet mask
    for (i = 0; i < totalBits; i++)
    {
        if (mask[i] == '1')
        {
            subnetMask[i] = '1';
        }
    }

    // Print subnet mask
    printf("Subnet Mask: ");
    for (i = 0; i < totalBits; i++)
    {
        printf("%c", subnetMask[i]);
    }

    // Calculate broadcast address
    int broadcastAddress = (1 << (totalBits - 1)) - 1;
    printf("\nBroadcast Address: ");
    for (i = 0; i < totalBits; i++)
    {
        printf("%d", broadcastAddress & (1 << i));
    }

    // Calculate usable hosts
    int usableHosts = (1 << (totalBits - 1)) - 2;
    printf("\nUsable Hosts: ");
    printf("%d", usableHosts);

    // Recursively calculate subnet masks for remaining bits
    if (currentBit < totalBits - 1)
    {
        subnetCalculator(mask, currentBit + 1, totalBits);
    }
}

int main()
{
    char mask[] = "255.255.255.0";
    subnetCalculator(mask, 0, 32);

    return 0;
}