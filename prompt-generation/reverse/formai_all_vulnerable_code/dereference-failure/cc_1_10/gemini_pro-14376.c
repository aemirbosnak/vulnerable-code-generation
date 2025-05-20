//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OCTETS 4

typedef struct {
    unsigned int octets[MAX_OCTETS];
    unsigned int prefix_length;
} ip_address;

void print_ip_address(ip_address *ip) {
    for (int i = 0; i < MAX_OCTETS; i++) {
        printf("%u", ip->octets[i]);
        if (i < MAX_OCTETS - 1) {
            printf(".");
        }
    }
    printf("/%u\n", ip->prefix_length);
}

int main() {
    // Variables
    ip_address ip;
    unsigned int subnet_mask, usable_hosts;
    char input[100];

    // User input
    printf("Enter IP address and prefix length (e.g. 192.168.1.0/24): ");
    fgets(input, sizeof(input), stdin);

    // Parse IP address
    char *ptr = strtok(input, "/");
    for (int i = 0; i < MAX_OCTETS; i++) {
        ip.octets[i] = atoi(ptr);
        ptr = strtok(NULL, "/");
    }

    // Parse prefix length
    ip.prefix_length = atoi(ptr);

    // Calculate subnet mask
    subnet_mask = 0xFFFFFFFF << (32 - ip.prefix_length);

    // Calculate usable hosts
    usable_hosts = (1 << (32 - ip.prefix_length)) - 2;

    // Display results
    printf("\nCyberpunk Subnet Calculator Results:\n\n");
    printf("IP Address: ");
    print_ip_address(&ip);

    printf("Subnet Mask: ");
    for (int i = 0; i < MAX_OCTETS; i++) {
        printf("%u", (subnet_mask >> (8 * (MAX_OCTETS - 1 - i))) & 0xFF);
        if (i < MAX_OCTETS - 1) {
            printf(".");
        }
    }
    printf("\n");

    printf("Usable Hosts: %u\n", usable_hosts);

    return 0;
}