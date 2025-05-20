//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

#define MAX_SUBNET_MASK 30
#define MIN_SUBNET_MASK 1

void print_usage() {
    printf("Subnet Calculator\n");
    printf("Usage:\n");
    printf("  ./subnet_calculator <ip_address> <subnet_mask>\n");
    printf("Example:\n");
    printf("  ./subnet_calculator 192.168.1.0 24\n");
}

int validate_ip(const char *ip) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return result != 0;
}

void convert_to_binary(uint32_t num, char *binary) {
    for (int i = 31; i >= 0; --i) {
        binary[i] = (num % 2) ? '1' : '0';
        num /= 2;
    }
    binary[32] = '\0';
}

void calculate_subnet(const char *ip_str, int subnet_mask) {
    uint32_t ip_num = 0;
    sscanf(ip_str, "%hhu.%hhu.%hhu.%hhu", (unsigned char*)&ip_num, 
                                         (unsigned char*)&ip_num+1, 
                                         (unsigned char*)&ip_num+2, 
                                         (unsigned char*)&ip_num+3);
    
    uint32_t subnet_mask_val = (subnet_mask < 32) ? (uint32_t)(~0U >> (32 - subnet_mask)) : ~0U;
    uint32_t network_address = ip_num & subnet_mask_val;
    uint32_t broadcast_address = network_address | ~subnet_mask_val;

    char ip_bin[33], net_bin[33], broad_bin[33];
    convert_to_binary(ip_num, ip_bin);
    convert_to_binary(network_address, net_bin);
    convert_to_binary(broadcast_address, broad_bin);

    char network_ip[INET_ADDRSTRLEN];
    char broadcast_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &network_address, network_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &broadcast_address, broadcast_ip, INET_ADDRSTRLEN);
    
    printf("IP Address       (Decimal): %u\n", ip_num);
    printf("IP Address (Binary):        %s\n", ip_bin);
    printf("Subnet Mask      (Decimal): %u\n", subnet_mask_val);
    printf("Subnet Mask (Binary):       ");
    for (int i = 0; i < 32; ++i) {
        putchar((subnet_mask <= i) ? '1' : '0');
    }
    printf("\n");

    printf("Network Address  (Decimal): %s\n", network_ip);
    printf("Network Address (Binary):    %s\n", net_bin);
    printf("Broadcast Address (Decimal): %s\n", broadcast_ip);
    printf("Broadcast Address (Binary):  %s\n", broad_bin);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }
    
    const char *ip_address = argv[1];
    int subnet_mask = atoi(argv[2]);

    if (!validate_ip(ip_address)) {
        fprintf(stderr, "Error: Invalid IP address format.\n");
        return EXIT_FAILURE;
    }

    if (subnet_mask < MIN_SUBNET_MASK || subnet_mask > MAX_SUBNET_MASK) {
        fprintf(stderr, "Error: Subnet mask must be between 1 and 30.\n");
        return EXIT_FAILURE;
    }

    calculate_subnet(ip_address, subnet_mask);

    return EXIT_SUCCESS;
}