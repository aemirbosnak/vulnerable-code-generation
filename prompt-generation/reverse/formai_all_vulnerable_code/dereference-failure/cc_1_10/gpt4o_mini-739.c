//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 100

typedef struct {
    char subnet_ip[16]; // holds the subnet IP
    int prefix_length; // holds the CIDR prefix length
    char subnet_mask[16]; // holds the subnet mask
    char broadcast_ip[16]; // holds the broadcast IP
    int num_hosts; // holds the number of hosts in the subnet
} SubnetInfo;

void calculate_subnet_mask(int prefix_length, char *subnet_mask) {
    unsigned int mask = 0xFFFFFFFF << (32 - prefix_length);
    struct in_addr addr;
    addr.s_addr = htonl(mask);
    strcpy(subnet_mask, inet_ntoa(addr));
}

void calculate_broadcast_ip(const char *subnet_ip, const char *subnet_mask, char *broadcast_ip) {
    struct in_addr ip_addr, mask_addr, broadcast_addr;
    inet_aton(subnet_ip, &ip_addr);
    inet_aton(subnet_mask, &mask_addr);
    broadcast_addr.s_addr = ip_addr.s_addr | ~mask_addr.s_addr;
    strcpy(broadcast_ip, inet_ntoa(broadcast_addr));
}

int calculate_num_hosts(int prefix_length) {
    return (1 << (32 - prefix_length)) - 2; // total hosts = 2^(32 - prefix_length) - 2
}

void display_subnet_info(SubnetInfo *subnet) {
    printf("Subnet IP: %s\n", subnet->subnet_ip);
    printf("Subnet Mask: %s\n", subnet->subnet_mask);
    printf("Broadcast IP: %s\n", subnet->broadcast_ip);
    printf("Number of Hosts: %d\n", subnet->num_hosts);
    printf("----------------------------\n");
}

void get_subnet_info(int count) {
    SubnetInfo subnets[MAX_SUBNETS];
    for (int i = 0; i < count; i++) {
        printf("Enter Subnet IP (Format: xxx.xxx.xxx.xxx): ");
        scanf("%s", subnets[i].subnet_ip);
        printf("Enter Prefix Length (0-32): ");
        scanf("%d", &subnets[i].prefix_length);

        calculate_subnet_mask(subnets[i].prefix_length, subnets[i].subnet_mask);
        calculate_broadcast_ip(subnets[i].subnet_ip, subnets[i].subnet_mask, subnets[i].broadcast_ip);
        subnets[i].num_hosts = calculate_num_hosts(subnets[i].prefix_length);
    }

    printf("\nSubnet Information:\n");
    printf("============================\n");
    for (int i = 0; i < count; i++) {
        display_subnet_info(&subnets[i]);
    }
}

int main() {
    int subnet_count;

    printf("Welcome to the Genius Subnet Calculator!\n");
    printf("How many subnets do you want to calculate? (Max: %d): ", MAX_SUBNETS);
    scanf("%d", &subnet_count);

    if (subnet_count <= 0 || subnet_count > MAX_SUBNETS) {
        printf("Please enter a valid number of subnets between 1 and %d.\n", MAX_SUBNETS);
        return EXIT_FAILURE;
    }

    get_subnet_info(subnet_count);

    printf("Thank you for using the Genius Subnet Calculator! Goodbye!\n");
    return EXIT_SUCCESS;
}