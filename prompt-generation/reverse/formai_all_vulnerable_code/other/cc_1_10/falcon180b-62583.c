//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main() {
    int subnet_bits, host_bits;
    int num_subnets, num_hosts;
    int i, j;
    int subnet_mask, host_mask;
    int subnet_address, host_address;
    char subnet_ip[16], host_ip[16];

    // Prompt the user for the IP address and subnet mask
    printf("Enter the IP address: ");
    scanf("%s", subnet_ip);
    printf("Enter the subnet mask: ");
    scanf("%s", host_ip);

    // Convert the IP address and subnet mask to integers
    inet_pton(AF_INET, subnet_ip, &subnet_address);
    inet_pton(AF_INET, host_ip, &host_address);

    // Calculate the number of subnets and hosts
    num_subnets = 32 - (ntohl(host_address) & 0xFF000000);
    num_hosts = 32 - (ntohl(host_address) & 0xFF000000) - 1;

    // Prompt the user for the number of subnets and hosts
    printf("Enter the number of subnets: ");
    scanf("%d", &subnet_bits);
    printf("Enter the number of hosts: ");
    scanf("%d", &host_bits);

    // Calculate the subnet mask and host mask
    subnet_mask = htonl((0xFF000000 << (32 - subnet_bits)) & 0xFF000000);
    host_mask = htonl((0x00FFFFFF >> host_bits) & 0x00FFFFFF);

    // Print the subnet and host masks
    printf("Subnet mask: %s\n", inet_ntoa(*((struct in_addr *)&subnet_mask)));
    printf("Host mask: %s\n", inet_ntoa(*((struct in_addr *)&host_mask)));

    // Print the subnet and host addresses
    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < num_hosts; j++) {
            subnet_address = htonl((ntohl(subnet_address) & 0xFF000000) + (i << (32 - subnet_bits)));
            host_address = htonl((ntohl(subnet_address) & 0x00FFFFFF) + (j << host_bits));
            inet_ntop(AF_INET, &subnet_address, subnet_ip, sizeof(subnet_ip));
            inet_ntop(AF_INET, &host_address, host_ip, sizeof(host_ip));
            printf("Subnet %d, Host %d: %s / %s\n", i+1, j+1, subnet_ip, host_ip);
        }
    }

    return 0;
}