//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_LENGTH 3

void print_usage() {
    printf("Usage: subnet_calculator <IP Address> <Subnet Mask Prefix Length>\n");
    printf("Example: subnet_calculator 192.168.1.1 24\n");
}

int validate_ip(const char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0;
}

void calculate_subnet(char *ip_str, int subnet_prefix) {
    unsigned char ip[4];
    unsigned char subnet_mask[4] = {0};
    unsigned char network[4] = {0};
    unsigned char broadcast[4] = {0};
    unsigned char first_usable[4] = {0};
    unsigned char last_usable[4] = {0};

    inet_pton(AF_INET, ip_str, ip);

    // Calculate subnet mask
    for (int i = 0; i < 4; i++) {
        if (subnet_prefix >= 8) {
            subnet_mask[i] = 255;
            subnet_prefix -= 8;
        } else {
            subnet_mask[i] = (unsigned char)(255 << (8 - subnet_prefix));
            break;
        }
    }

    // Calculate network address
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & subnet_mask[i];
    }

    // Calculate broadcast address
    for (int i = 0; i < 4; i++) {
        broadcast[i] = network[i] | ~subnet_mask[i];
    }

    // Calculate usable IP addresses
    for (int i = 0; i < 4; i++) {
        first_usable[i] = network[i];
        last_usable[i] = broadcast[i];
    }

    first_usable[3] += 1; // First usable IP
    last_usable[3] -= 1;   // Last usable IP

    // Printing results
    printf("IP Address: %s\n", ip_str);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
    printf("Network Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Usable IP Range: %d.%d.%d.%d - %d.%d.%d.%d\n", 
           first_usable[0], first_usable[1], first_usable[2], first_usable[3], 
           last_usable[0], last_usable[1], last_usable[2], last_usable[3]);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *ip_input = argv[1];
    int subnet_length = atoi(argv[2]);

    // Validate IP address
    if (!validate_ip(ip_input)) {
        printf("Error: Invalid IP address format: %s\n", ip_input);
        return EXIT_FAILURE;
    }
    
    // Validate subnet prefix
    if (subnet_length < 0 || subnet_length > 32) {
        printf("Error: Subnet prefix must be between 0 and 32\n");
        return EXIT_FAILURE;
    }

    // Calculate and display the subnet information
    calculate_subnet(ip_input, subnet_length);
    
    return EXIT_SUCCESS;
}