//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toBinary(int num)
{
    char* result = (char*) malloc(9 * sizeof(char));
    int index = 0;
    for (int i = 7; i >= 0; i--)
    {
        int bit = num >> i & 1;
        result[index++] = bit + '0';
        if (i == 4)
            result[index++] = '.';
    }
    result[index] = '\0';
    return result;
}

int toDecimal(char* binary)
{
    int result = 0;
    for (int i = 0; i < 8; i++)
    {
        int bit = binary[i] - '0';
        result = (result << 1) | bit;
    }
    return result;
}

int main()
{
    printf("Welcome to the C Subnet Calculator!\n\n");

    // Get the IP address
    printf("Please enter an IP address: ");
    char ip[16];
    scanf("%s", &ip);

    // Convert the IP address to binary
    char* binaryIp = (char*) malloc(33 * sizeof(char));
    char* token = strtok(ip, ".");
    while (token != NULL)
    {
        int num = atoi(token);
        strcat(binaryIp, toBinary(num));
        token = strtok(NULL, ".");
    }

    // Get the subnet mask
    printf("Please enter the subnet mask in CIDR notation: /");
    int cidr;
    scanf("%d", &cidr);

    // Calculate the subnet mask
    int numOnes = cidr;
    int numZeros = 32 - cidr;
    char* binarySubnetMask = (char*) malloc(33 * sizeof(char));
    for (int i = 0; i < numOnes; i++)
    {
        strcat(binarySubnetMask, "1");
    }
    for (int i = 0; i < numZeros; i++)
    {
        strcat(binarySubnetMask, "0");
    }

    // Separate the subnet mask into octets
    char subnetMask[16];
    strncpy(subnetMask, binarySubnetMask, 8);
    subnetMask[8] = '\0';
    int decimal = toDecimal(subnetMask);
    sprintf(subnetMask, "%d.", decimal);

    strncpy(subnetMask + 4, binarySubnetMask + 8, 8);
    subnetMask[12] = '\0';
    decimal = toDecimal(subnetMask + 4);
    sprintf(subnetMask + 12, "%d.", decimal);

    strncpy(subnetMask + 8, binarySubnetMask + 16, 8);
    subnetMask[16] = '\0';
    decimal = toDecimal(subnetMask + 8);
    sprintf(subnetMask + 20, "%d.", decimal);

    strncpy(subnetMask + 12, binarySubnetMask + 24, 8);
    subnetMask[24] = '\0';
    decimal = toDecimal(subnetMask + 12);
    sprintf(subnetMask + 28, "%d", decimal);

    // Calculate the network address
    char* binaryNetworkAddress = (char*) malloc(33 * sizeof(char));
    for (int i = 0; i < 32; i++)
    {
        int bitIp = binaryIp[i] - '0';
        int bitSubnetMask = binarySubnetMask[i] - '0';
        int bitNetwork = (bitIp & bitSubnetMask);
        binaryNetworkAddress[i] = bitNetwork + '0';
    }

    // Separate the network address into octets
    char networkAddress[16];
    strncpy(networkAddress, binaryNetworkAddress, 8);
    networkAddress[8] = '\0';
    int decimal1 = toDecimal(networkAddress);
    sprintf(networkAddress, "%d.", decimal1);

    strncpy(networkAddress + 4, binaryNetworkAddress + 8, 8);
    networkAddress[12] = '\0';
    int decimal2 = toDecimal(networkAddress + 4);
    sprintf(networkAddress + 12, "%d.", decimal2);

    strncpy(networkAddress + 8, binaryNetworkAddress + 16, 8);
    networkAddress[16] = '\0';
    int decimal3 = toDecimal(networkAddress + 8);
    sprintf(networkAddress + 20, "%d.", decimal3);

    strncpy(networkAddress + 12, binaryNetworkAddress + 24, 8);
    networkAddress[24] = '\0';
    int decimal4 = toDecimal(networkAddress + 12);
    sprintf(networkAddress + 28, "%d", decimal4);

    // Calculate the broadcast address
    char* binaryBroadcastAddress = (char*) malloc(33 * sizeof(char));
    for (int i = 0; i < 32; i++)
    {
        int bitIp = binaryIp[i] - '0';
        int bitSubnetMask = binarySubnetMask[i] - '0';
        int bitBroadcast = (bitIp | (~bitSubnetMask & 1));
        binaryBroadcastAddress[i] = bitBroadcast + '0';
    }

    // Separate the broadcast address into octets
    char broadcastAddress[16];
    strncpy(broadcastAddress, binaryBroadcastAddress, 8);
    broadcastAddress[8] = '\0';
    decimal1 = toDecimal(broadcastAddress);
    sprintf(broadcastAddress, "%d.", decimal1);

    strncpy(broadcastAddress + 4, binaryBroadcastAddress + 8, 8);
    broadcastAddress[12] = '\0';
    decimal2 = toDecimal(broadcastAddress + 4);
    sprintf(broadcastAddress + 12, "%d.", decimal2);

    strncpy(broadcastAddress + 8, binaryBroadcastAddress + 16, 8);
    broadcastAddress[16] = '\0';
    decimal3 = toDecimal(broadcastAddress + 8);
    sprintf(broadcastAddress + 20, "%d.", decimal3);

    strncpy(broadcastAddress + 12, binaryBroadcastAddress + 24, 8);
    broadcastAddress[24] = '\0';
    decimal4 = toDecimal(broadcastAddress + 12);
    sprintf(broadcastAddress + 28, "%d", decimal4);

    // Calculate the number of hosts
    int numHosts = 1;
    for (int i = 0; i < numZeros; i++)
    {
        numHosts *= 2;
    }
    numHosts -= 2;

    // Print the result
    printf("\nNetwork address: %s\n", networkAddress);
    printf("Broadcast address: %s\n", broadcastAddress);
    printf("Subnet mask: %s\n", subnetMask);
    printf("Number of hosts: %d\n\n", numHosts);

    free(binaryIp);
    free(binarySubnetMask);
    free(binaryNetworkAddress);
    free(binaryBroadcastAddress);

    return 0;
}