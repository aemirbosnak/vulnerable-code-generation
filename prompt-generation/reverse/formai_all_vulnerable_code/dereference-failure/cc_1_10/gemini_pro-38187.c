//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_SUBNET_LEN 16

typedef struct ip_subnet {
    char ip[MAX_IP_LEN];
    char subnet[MAX_SUBNET_LEN];
    int prefix_len;
} ip_subnet;

void print_help(char *argv[]) {
    printf("Usage: %s <ip address> <subnet mask>\n", argv[0]);
    printf("Example: %s 192.168.1.1 255.255.255.0\n", argv[0]);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_help(argv);
    }

    ip_subnet subnet;
    strcpy(subnet.ip, argv[1]);
    strcpy(subnet.subnet, argv[2]);

    // Parse the IP address
    char *ip_parts[4];
    int i;
    for (i = 0; i < 4; i++) {
        ip_parts[i] = strtok(subnet.ip, ".");
        if (ip_parts[i] == NULL) {
            fprintf(stderr, "Invalid IP address: %s\n", subnet.ip);
            exit(1);
        }
    }

    // Parse the subnet mask
    char *subnet_parts[4];
    for (i = 0; i < 4; i++) {
        subnet_parts[i] = strtok(subnet.subnet, ".");
        if (subnet_parts[i] == NULL) {
            fprintf(stderr, "Invalid subnet mask: %s\n", subnet.subnet);
            exit(1);
        }
    }

    // Calculate the prefix length
    int prefix_len = 0;
    for (i = 0; i < 4; i++) {
        int octet = atoi(subnet_parts[i]);
        prefix_len += (octet == 255) ? 8 : (octet == 128) ? 7 : (octet == 192) ? 6 : (octet == 224) ? 5 : 0;
    }

    // Set the prefix length
    subnet.prefix_len = prefix_len;

    // Print the results
    printf("IP address: %s\n", subnet.ip);
    printf("Subnet mask: %s\n", subnet.subnet);
    printf("Prefix length: %d\n", subnet.prefix_len);

    return 0;
}