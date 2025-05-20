//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scientific
/*
 * Scientific Style C Subnet Calculator Example Program
 * by YourNameHere
 * 
 * This program takes an IP address and subnet mask from the user,
 * calculates the network and broadcast addresses, and displays
 * the results along with the total number of hosts in the subnet.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_IP_STR_LEN 15

int main(void) {
    /* Variables to hold user input */
    char ip_str[MAX_IP_STR_LEN+1], mask_str[MAX_IP_STR_LEN+1];
    int mask_bits;
    
    /* Variables for IP and subnet mask manipulation */
    unsigned long ip, mask, net, bcast;
    unsigned int host_bits, num_hosts;
    
    /* Prompt user for IP address and subnet mask */
    printf("Enter IP address in dotted decimal notation (e.g. 192.168.1.1):\n");
    fgets(ip_str, MAX_IP_STR_LEN+1, stdin);
    printf("Enter subnet mask in dotted decimal notation (e.g. 255.255.255.0):\n");
    fgets(mask_str, MAX_IP_STR_LEN+1, stdin);
    
    /* Convert IP address from string to binary */
    ip = 0;
    for (int i=0, j=24; i<4; i++, j-=8) {
        ip += atoi(strtok((i==0) ? ip_str : NULL, ".")) << j;
    }
    
    /* Convert subnet mask from string to binary and count number of host bits */
    mask = 0;
    host_bits = 0;
    for (int i=0, j=24; i<4; i++, j-=8) {
        int octet = atoi(strtok((i==0) ? mask_str : NULL, "."));
        mask += octet << j;
        for (int k=7; k>=0; k--) {
            if ((octet >> k) & 1) {
                host_bits++;
            } else {
                break;
            }
        }
    }
    
    /* Calculate network and broadcast addresses */
    net = ip & mask;
    bcast = net | ~(mask);
    
    /* Calculate number of hosts in subnet */
    num_hosts = pow(2, host_bits) - 2;
    
    /* Display results */
    printf("IP address: %s", ip_str);
    printf("Subnet mask: %s", mask_str);
    printf("Network address: %lu.%lu.%lu.%lu\n", (net >> 24) & 0xFF, (net >> 16) & 0xFF, (net >> 8) & 0xFF, net & 0xFF);
    printf("Broadcast address: %lu.%lu.%lu.%lu\n", (bcast >> 24) & 0xFF, (bcast >> 16) & 0xFF, (bcast >> 8) & 0xFF, bcast & 0xFF);
    printf("Number of hosts in subnet: %u\n", num_hosts);
    
    return 0;
}