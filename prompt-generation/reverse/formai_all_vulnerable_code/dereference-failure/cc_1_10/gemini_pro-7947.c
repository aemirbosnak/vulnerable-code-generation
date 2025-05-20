//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_ADDR_LEN 16

typedef struct {
    char ip_addr[MAX_IP_ADDR_LEN];
    int prefix_len;
} ip_subnet;

void print_ip_subnet(ip_subnet *subnet) {
    printf("IP Address: %s\n", subnet->ip_addr);
    printf("Prefix Length: %d\n", subnet->prefix_len);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip_address/prefix_length>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_addr_str = argv[1];
    char *prefix_len_str = strchr(ip_addr_str, '/');
    if (prefix_len_str == NULL) {
        fprintf(stderr, "Invalid IP address/prefix length format\n");
        return EXIT_FAILURE;
    }

    *prefix_len_str = '\0';
    prefix_len_str++;

    ip_subnet subnet;
    strcpy(subnet.ip_addr, ip_addr_str);
    subnet.prefix_len = atoi(prefix_len_str);

    print_ip_subnet(&subnet);

    // Calculate the network address
    char network_addr[MAX_IP_ADDR_LEN];
    for (int i = 0; i < 4; i++) {
        int octet = atoi(strtok(subnet.ip_addr, "."));
        int mask = 0xFF << (8 - subnet.prefix_len);
        network_addr[i] = octet & mask;
    }

    // Print the network address
    printf("Network Address: %s\n", network_addr);

    // Calculate the broadcast address
    char broadcast_addr[MAX_IP_ADDR_LEN];
    for (int i = 0; i < 4; i++) {
        int octet = atoi(strtok(subnet.ip_addr, "."));
        int mask = 0xFF << (8 - subnet.prefix_len);
        broadcast_addr[i] = octet | ~mask;
    }

    // Print the broadcast address
    printf("Broadcast Address: %s\n", broadcast_addr);

    // Calculate the number of hosts
    int num_hosts = (1 << (32 - subnet.prefix_len)) - 2;

    // Print the number of hosts
    printf("Number of Hosts: %d\n", num_hosts);

    return EXIT_SUCCESS;
}