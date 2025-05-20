//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

typedef struct {
    uint32_t ip;
    uint8_t cidr;
} subnet;

int is_valid_cidr(uint8_t cidr) {
    if (cidr < 0 || cidr > 32) {
        return 0;
    }

    return 1;
}

uint32_t get_network_address(const subnet *subnet) {
    if (!is_valid_cidr(subnet->cidr)) {
        return 0;
    }

    uint32_t mask = 0xFFFFFFFF << (32 - subnet->cidr);

    return subnet->ip & mask;
}

uint32_t get_broadcast_address(const subnet *subnet) {
    if (!is_valid_cidr(subnet->cidr)) {
        return 0;
    }

    uint32_t mask = 0xFFFFFFFF >> subnet->cidr;

    return subnet->ip | mask;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <cidr>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    uint8_t cidr = atoi(argv[2]);

    if (!is_valid_cidr(cidr)) {
        fprintf(stderr, "Invalid CIDR\n");
        return 1;
    }

    subnet subnet;
    subnet.ip = inet_addr(ip);
    subnet.cidr = cidr;

    uint32_t network_address = get_network_address(&subnet);
    uint32_t broadcast_address = get_broadcast_address(&subnet);

    printf("Network address: %s\n", inet_ntoa(network_address));
    printf("Broadcast address: %s\n", inet_ntoa(broadcast_address));

    return 0;
}