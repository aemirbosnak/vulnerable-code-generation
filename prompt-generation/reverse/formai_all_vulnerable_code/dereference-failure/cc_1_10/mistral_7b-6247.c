//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct {
    uint8_t ip[4];
    uint8_t mask[4];
} ip_subnet;

void binary_to_decimal(uint8_t binary[], uint8_t size, uint8_t output[]) {
    int i, j, number = 0;

    for (i = 0; i < size; i++) {
        for (j = 7; j >= 0; j--) {
            if (binary[i] & (1 << j))
                number += 1 << j;
        }
        output[i] = number & 0xFF;
        number >>= 8;
    }
}

ip_subnet subnet_calculator(uint8_t ip[], uint8_t subnet_size) {
    ip_subnet result;
    uint8_t subnet_mask[4];
    uint8_t broadcast[4];

    memset(result.mask, 255, sizeof(result.mask));
    memset(broadcast, 0, sizeof(broadcast));

    binary_to_decimal(ip, 4, result.ip);

    for (int i = 0; i < 4; i++) {
        int subnet_bits = subnet_size >> (8 * (3 - i));

        result.mask[i] &= ~((1 << subnet_bits) - 1);
        broadcast[i] = result.ip[i] + (255 & ~result.mask[i]);
    }

    binary_to_decimal(broadcast, 4, result.mask + 4);

    return result;
}

void print_ip_subnet(ip_subnet subnet) {
    printf("IP Address: ");
    for (int i = 0; i < 4; i++) {
        printf("%d.", subnet.ip[i]);
    }
    printf("\nSubnet Mask: ");
    for (int i = 0; i < 4; i++) {
        printf("%d.", subnet.mask[i]);
    }
    printf("\nBroadcast Address: ");
    for (int i = 0; i < 4; i++) {
        printf("%d.", subnet.mask[i] + 3);
    }
    printf("\n");
}

int main() {
    uint8_t ip[] = {192, 168, 1, 10};
    uint8_t subnet_size = 24;

    ip_subnet subnet = subnet_calculator(ip, subnet_size);

    print_ip_subnet(subnet);

    return 0;
}