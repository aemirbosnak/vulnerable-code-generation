//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_MASK_LENGTH 3

void print_help() {
    printf("C Subnet Calculator\n");
    printf("Usage: ./subnet_calculator <IP address> <subnet mask>\n");
    printf("Example: ./subnet_calculator 192.168.1.1 24\n");
    printf("This will calculate and display the subnet information based on the provided IP address and subnet mask.\n");
}

int is_valid_ip(const char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0;
}

int is_valid_subnet_mask(const char *mask) {
    int mask_val = atoi(mask);
    return (mask_val >= 0 && mask_val <= 32);
}

uint32_t ip_to_uint32(const char *ip) {
    uint32_t result = 0;
    inet_pton(AF_INET, ip, &result);
    return ntohl(result);
}

void uint32_to_ip(uint32_t ip, char *output) {
    struct in_addr addr;
    addr.s_addr = htonl(ip);
    strcpy(output, inet_ntoa(addr));
}

void calculate_subnet(const char *ip, const char *mask) {
    uint32_t ip_uint = ip_to_uint32(ip);
    int mask_int = atoi(mask);
    
    uint32_t subnet_mask = (mask_int == 0) ? 0 : (~0U >> (32 - mask_int));
    uint32_t network_address = ip_uint & subnet_mask;
    uint32_t broadcast_address = network_address | ~subnet_mask;
    
    char network_ip[MAX_IP_LENGTH];
    char broadcast_ip[MAX_IP_LENGTH];

    uint32_to_ip(network_address, network_ip);
    uint32_to_ip(broadcast_address, broadcast_ip);
    
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: /%s\n", mask);
    printf("Network Address: %s\n", network_ip);
    printf("Broadcast Address: %s\n", broadcast_ip);
    printf("Number of Hosts: %d\n", (1 << (32 - mask_int)) - 2); // Subtracting 2 for network and broadcast
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_help();
        return 1;
    }
    
    const char *ip = argv[1];
    const char *mask = argv[2];

    if (!is_valid_ip(ip)) {
        fprintf(stderr, "Error: Invalid IP Address\n");
        return 1;
    }
    
    if (!is_valid_subnet_mask(mask)) {
        fprintf(stderr, "Error: Invalid Subnet Mask\n");
        return 1;
    }
    
    calculate_subnet(ip, mask);
    
    return 0;
}