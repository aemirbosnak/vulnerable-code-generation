//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the C Subnet Calculator!\n");
    printf("Enter IP address: ");

    char ip[16];
    fgets(ip, 16, stdin);
    ip[strcspn(ip, "\n")] = 0;

    printf("\nEnter subnet mask: ");
    char subnet[16];
    fgets(subnet, 16, stdin);
    subnet[strcspn(subnet, "\n")] = 0;

    char *ipToken = strtok(ip, ".");   
    int ipArray[4];
    int subnetArray[4];

    for(int i=0; i<4; i++) {
        ipArray[i] = atoi(ipToken);
        subnetArray[i] = atoi(strtok(NULL, "."));
        ipToken = strtok(NULL, ".");
    }

    printf("\nIP address: %s\n", ip);
    printf("Subnet mask: %s\n", subnet);

    int hostBits = 32 - atoi(subnet);
    int subnets = 1;

    for(int i=0; i<hostBits; i++) {
        subnets *= 2;
    }
    
    int hosts = subnets - 2;
    int subnetMask = 256 - subnets;
    int networkAddress[4];

    for(int j=0; j<4; j++) {
        if(subnets==256)
            networkAddress[j] = ipArray[j];
        else if(subnetArray[j] == 0)
            networkAddress[j] = 0;
        else
            networkAddress[j] = ipArray[j] & ((subnetArray[j]-1) | subnetMask);
    }

    printf("\nNumber of subnets: %d\n", subnets);
    printf("Number of hosts per subnet: %d\n", hosts);
    printf("Subnet mask in decimal: %d.%d.%d.%d\n", subnetMask, subnetMask, subnetMask, subnetMask);
    printf("Network address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);

    return 0;
}