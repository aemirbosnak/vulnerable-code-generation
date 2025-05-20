//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int determineClass(char ip[]);

void getNetworkAddress(char ip[], int subnetMask, char networkAddress[]);
void getBroadcastAddress(char networkAddress[], int hostBits, char broadcastAddress[]);
void getFirstIpAddress(char networkAddress[], char firstIpAddress[]);
void getLastIpAddress(char broadcastAddress[], char lastIpAddress[]);

int main()
{
    //Declaration of variables
    char ipAddress[15];
    int subnetMask, class, hostBits;
    char networkAddress[15], broadcastAddress[15], firstIpAddress[15], lastIpAddress[15];
    
    //Input
    printf("Enter IP address: ");
    scanf("%s", ipAddress);
    
    printf("Enter Subnet Mask: ");
    scanf("%d", &subnetMask);
    
    //Process
    class = determineClass(ipAddress);
    
    switch(class)
    {
        case 1: hostBits = 24 - subnetMask; break;
        case 2: hostBits = 16 - subnetMask; break;
        case 3: hostBits = 8 - subnetMask; break;
        default: printf("\nInvalid IP Address!"); exit(0);
    }
    
    getNetworkAddress(ipAddress, subnetMask, networkAddress);
    getBroadcastAddress(networkAddress, hostBits, broadcastAddress);
    getFirstIpAddress(networkAddress, firstIpAddress);
    getLastIpAddress(broadcastAddress, lastIpAddress);
    
    //Output
    printf("\n");
    printf(" IP address: %s\n", ipAddress);
    printf(" Subnet mask: %d\n", subnetMask);
    printf(" Network address: %s\n", networkAddress);
    printf(" Broadcast address: %s\n", broadcastAddress);
    printf(" First IP address: %s\n", firstIpAddress);
    printf(" Last IP address: %s\n", lastIpAddress);
    
    return 0;
}

//Function to determine class of IP Address
int determineClass(char ip[])
{
    char ipAddress[15];
    strcpy(ipAddress, ip);
    
    char *token = strtok(ipAddress, ".");
    int firstOctet = atoi(token);
    
    if(firstOctet >= 1 && firstOctet <= 126)
        return 1;
    else if(firstOctet >= 128 && firstOctet <= 191)
        return 2;
    else if(firstOctet >= 192 && firstOctet <= 223)
        return 3;
    else
        return 0;
}

//Function to get Network Address
void getNetworkAddress(char ip[], int subnetMask, char networkAddress[])
{
    char *token;
    int num;
    int subnetOctet;
    int i, j;
    
    strcpy(networkAddress, "");
    
    for (i = 0; i < 4; i++)
    {
        if (subnetMask > 0)
        {
            subnetOctet = 0;
            for (j = 0; j < 8; j++)
            {
                if(subnetMask <= 0)
                    break;
                    
                subnetOctet += pow(2, j);
                
                subnetMask--;
            }
        }
        else
            subnetOctet = 0;
        
        token = strtok(ip, ".");
        num = atoi(token);
        sprintf(token, "%d", (num & subnetOctet));
        
        strcat(networkAddress, token);
        strcat(networkAddress, ".");
        
        ip = NULL;
    }
    
    networkAddress[strlen(networkAddress) - 1] = '\0';
}

//Function to get Broadcast Address
void getBroadcastAddress(char networkAddress[], int hostBits, char broadcastAddress[])
{
    int i;
    char *token;
    int num;
    strcpy(broadcastAddress, "");
    
    for (i = 0; i < hostBits; i++)
    {
        strcat(networkAddress, "1");
    }
    
    for (i = 0; i < 4; i++)
    {
        token = strtok(networkAddress, ".");
        num = strtol(token, NULL, 2);
        sprintf(token, "%d", num);
        strcat(broadcastAddress, token);
        strcat(broadcastAddress, ".");
        networkAddress = NULL;
    }
    
    broadcastAddress[strlen(broadcastAddress) - 1] = '\0';
}

//Function to get First IP Address
void getFirstIpAddress(char networkAddress[], char firstIpAddress[])
{
    int i;
    char *token;
    int num;
    strcpy(firstIpAddress, "");
    
    for (i = 0; i < 3; i++)
    {
        token = strtok(networkAddress, ".");
        sprintf(token, "%d", atoi(token));
        strcat(firstIpAddress, token);
        strcat(firstIpAddress, ".");
        networkAddress = NULL;
    }
    
    strcat(firstIpAddress, "1");
}

//Function to get Last IP Address
void getLastIpAddress(char broadcastAddress[], char lastIpAddress[])
{
    int i;
    char *token;
    int num;
    strcpy(lastIpAddress, "");
    
    for (i = 0; i < 3; i++)
    {
        token = strtok(broadcastAddress, ".");
        sprintf(token, "%d", atoi(token));
        strcat(lastIpAddress, token);
        strcat(lastIpAddress, ".");
        broadcastAddress = NULL;
    }
    
    strcat(lastIpAddress, "254");
}