//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LEN     16
#define MAX_PREFIX_LEN 32

void print_usage(char *prog_name)
{
    printf("Usage: %s <IP address>/<prefix length>\n", prog_name);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_prefix = strtok(argv[1], "/");
    char *prefix_length_str = strtok(NULL, "/");
    if (ip_prefix == NULL || prefix_length_str == NULL) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    uint32_t ip_addr = ntohl(inet_addr(ip_prefix));
    if (ip_addr == INADDR_NONE) {
        printf("Invalid IP address: %s\n", ip_prefix);
        return EXIT_FAILURE;
    }

    long prefix_length = strtol(prefix_length_str, NULL, 10);
    if (prefix_length < 0 || prefix_length > MAX_PREFIX_LEN) {
        printf("Invalid prefix length: %ld\n", prefix_length);
        return EXIT_FAILURE;
    }

    uint32_t subnet_mask = htonl(((1 << prefix_length) - 1) << (MAX_PREFIX_LEN - prefix_length));
    uint32_t network_addr = ip_addr & subnet_mask;
    uint32_t broadcast_addr = network_addr | ~subnet_mask;

    char ip_str[MAX_IP_LEN];
    inet_ntop(AF_INET, &ip_addr, ip_str, MAX_IP_LEN);

    char subnet_mask_str[MAX_IP_LEN];
    inet_ntop(AF_INET, &subnet_mask, subnet_mask_str, MAX_IP_LEN);

    char network_addr_str[MAX_IP_LEN];
    inet_ntop(AF_INET, &network_addr, network_addr_str, MAX_IP_LEN);

    char broadcast_addr_str[MAX_IP_LEN];
    inet_ntop(AF_INET, &broadcast_addr, broadcast_addr_str, MAX_IP_LEN);

    printf("IP address: %s\n", ip_str);
    printf("Subnet mask: %s\n", subnet_mask_str);
    printf("Network address: %s\n", network_addr_str);
    printf("Broadcast address: %s\n", broadcast_addr_str);

    return EXIT_SUCCESS;
}