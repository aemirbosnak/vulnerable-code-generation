//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_LENGTH 4
#define MAX_BUFFER_LENGTH 1024

void print_usage() {
    printf("Usage: ./subnet_calculator <IP address> <Subnet mask>\n");
    printf("Example: ./subnet_calculator 192.168.1.10 255.255.255.0\n");
}

unsigned int ip_to_int(const char *ip) {
    unsigned int result = 0;
    unsigned int octet;
    char *token;
    char ip_copy[MAX_IP_LENGTH];
    
    strncpy(ip_copy, ip, MAX_IP_LENGTH);
    
    token = strtok(ip_copy, ".");
    while (token != NULL) {
        if (sscanf(token, "%u", &octet) != 1 || octet > 255) {
            fprintf(stderr, "Invalid IP address format.\n");
            exit(EXIT_FAILURE);
        }
        result = (result << 8) | octet;
        token = strtok(NULL, ".");
    }
    
    return result;
}

void int_to_ip(unsigned int ip, char *buffer) {
    sprintf(buffer, "%u.%u.%u.%u", 
            (ip >> 24) & 0xFF,
            (ip >> 16) & 0xFF,
            (ip >> 8) & 0xFF,
            ip & 0xFF);
}

unsigned int mask_to_int(const char *mask) {
    unsigned int result = 0;
    unsigned int octet;
    char *token;
    char mask_copy[MAX_SUBNET_LENGTH];
    
    strncpy(mask_copy, mask, MAX_SUBNET_LENGTH);
    
    token = strtok(mask_copy, ".");
    while (token != NULL) {
        if (sscanf(token, "%u", &octet) != 1 || octet > 255) {
            fprintf(stderr, "Invalid subnet mask format.\n");
            exit(EXIT_FAILURE);
        }
        result = (result << 8) | octet;
        token = strtok(NULL, ".");
    }
    
    return result;
}

void calculate_subnet(const char *ip_str, const char *subnet_str) {
    unsigned int ip = ip_to_int(ip_str);
    unsigned int subnet_mask = mask_to_int(subnet_str);
    unsigned int network_address = ip & subnet_mask;
    unsigned int broadcast_address = network_address | ~subnet_mask;

    char network_str[MAX_IP_LENGTH];
    char broadcast_str[MAX_IP_LENGTH];

    int_to_ip(network_address, network_str);
    int_to_ip(broadcast_address, broadcast_str);

    printf("IP Address:      %s\n", ip_str);
    printf("Subnet Mask:     %s\n", subnet_str);
    printf("Network Address: %s\n", network_str);
    printf("Broadcast Address:%s\n", broadcast_str);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *ip_address = argv[1];
    const char *subnet_mask = argv[2];

    calculate_subnet(ip_address, subnet_mask);

    return EXIT_SUCCESS;
}