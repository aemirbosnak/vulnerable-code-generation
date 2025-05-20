//FormAI DATASET v1.0 Category: Firewall ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IPS 100 // Maximum number of authorized IPs

int main()
{
    char* authorized_ips[MAX_IPS]; // Array to hold authorized IPs
    int num_authorized_ips = 0; // Number of authorized IPs
    char input_ip[16]; // Input buffer for IP addresses
    int i; // Loop index
    
    printf("Welcome to the Castle Firewall!\n");
    
    while(1)
    {
        printf("Enter IP address to authorize (q to quit): ");
        scanf("%15s", input_ip); // Read input IP address
        
        if(strcmp(input_ip, "q") == 0) // Exit loop if user enters q
        {
            break;
        }
        
        authorized_ips[num_authorized_ips] = (char*)malloc(16); // Allocate memory for IP address
        strcpy(authorized_ips[num_authorized_ips], input_ip); // Copy input IP address to authorized_ips array
        num_authorized_ips++; // Increment number of authorized IPs
    }
    
    printf("Firewall is now active. Authorized IPs:\n");
    
    for(i = 0; i < num_authorized_ips; i++)
    {
        printf("%s\n", authorized_ips[i]); // Print out list of authorized IPs
    }
    
    printf("Waiting for incoming traffic...\n");
    
    while(1)
    {
        printf("Enter incoming IP address (q to quit): ");
        scanf("%15s", input_ip); // Read incoming IP address
        
        if(strcmp(input_ip, "q") == 0) // Exit loop if user enters q
        {
            break;
        }
        
        for(i = 0; i < num_authorized_ips; i++)
        {
            if(strcmp(input_ip, authorized_ips[i]) == 0) // Check if incoming IP is authorized
            {
                printf("Access granted for IP %s\n", input_ip);
                break;
            }
        }
        
        if(i == num_authorized_ips) // If loop finished without finding authorized IP
        {
            printf("Access denied for IP %s\n", input_ip);
        }
    }
    
    printf("Firewall is now offline. Cleaning up...\n");
    
    for(i = 0; i < num_authorized_ips; i++)
    {
        free(authorized_ips[i]); // Free memory allocated for authorized IP addresses
    }
    
    return 0;
}