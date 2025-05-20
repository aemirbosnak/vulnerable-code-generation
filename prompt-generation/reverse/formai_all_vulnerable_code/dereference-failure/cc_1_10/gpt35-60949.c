//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

int32_t ipToInt(char* ipAddr)
{
    int32_t res = 0;
    int i = 0;
    int val = 0;
    int len = strlen(ipAddr);
    int dotCount = 0;
    
    for (i = 0; i < len; i++)
    {
        if (ipAddr[i] == '.')
        {
            res = (res << 8) | val;
            val = 0;
            dotCount++;
        }
        else
        {
            val = val * 10 + (ipAddr[i] - '0');
        }
    }
    
    if (dotCount == 3)
    {
        res = (res << 8) | val;
    }    
    else
    {
        res = -1;
    }
    
    return res;
}

void calculateSubnet(char* ipAddr, int32_t mask)
{
    int32_t ip = ipToInt(ipAddr);
    
    if (ip == -1)
    {
        printf("Invalid IP address\n");
        return;
    }
    
    printf("IP address: %s\n", ipAddr);
    printf("Mask: %d\n", mask);
    
    int32_t subnetMask = (1 << 31) >> (mask - 1);
    int32_t networkAddr = ip & subnetMask;
    int32_t broadcastAddr = networkAddr | ~subnetMask;
    
    printf("Subnet mask: %d.%d.%d.%d\n", 
            (subnetMask & 0xff000000) >> 24,
            (subnetMask & 0x00ff0000) >> 16,
            (subnetMask & 0x0000ff00) >> 8,
            (subnetMask & 0x000000ff));
    printf("Network address: %d.%d.%d.%d\n", 
            (networkAddr & 0xff000000) >> 24,
            (networkAddr & 0x00ff0000) >> 16,
            (networkAddr & 0x0000ff00) >> 8,
            (networkAddr & 0x000000ff));
    printf("Broadcast address: %d.%d.%d.%d\n", 
            (broadcastAddr & 0xff000000) >> 24,
            (broadcastAddr & 0x00ff0000) >> 16,
            (broadcastAddr & 0x0000ff00) >> 8,
            (broadcastAddr & 0x000000ff));
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Invalid arguments. Usage: subnetCalc <ipAddress> <mask>\n");
        return -1;
    }
    
    char* ipAddr = argv[1];
    int32_t mask = atoi(argv[2]);
    
    if (mask < 0 || mask > 32)
    {
        printf("Invalid mask. Mask must be between 0 and 32.\n");
        return -1;
    }
    
    calculateSubnet(ipAddr, mask);
    
    return 0;
}