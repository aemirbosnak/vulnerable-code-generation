//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OCTETS 4
#define MIN_MASK_SIZE 8
#define MAX_MASK_SIZE 24
#define MAX_SUBNETS 16
#define MAX_HOSTS 254

typedef struct {
    int octets[MAX_OCTETS];
    int mask_size;
} Subnet;

void print_subnet(Subnet subnet) {
    for (int i = 0; i < MAX_OCTETS; i++) {
        if (i != MAX_OCTETS - 1)
            printf("%d.", subnet.octets[i]);
        else
            printf("%d", subnet.octets[i]);
    }

    printf(" /%d\n", subnet.mask_size);
}

Subnet parse_subnet(char *str) {
    char *token;
    Subnet subnet = {0};
    int i = 0;

    token = strtok(str, ".");
    while (token != NULL) {
        subnet.octets[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    token = strtok(str, "/");
    subnet.mask_size = atoi(token);

    return subnet;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <subnet_address_and_mask>\n", argv[0]);
        return 1;
    }

    Subnet subnet = parse_subnet(argv[1]);

    if (subnet.mask_size < MIN_MASK_SIZE || subnet.mask_size > MAX_MASK_SIZE) {
        printf("Invalid mask size.\n");
        return 1;
    }

    int num_subnets = 1 << (32 - subnet.mask_size);
    int num_hosts_per_subnet = MAX_HOSTS - 2;
    int total_hosts = num_subnets * num_hosts_per_subnet;

    printf("Subnet Address: ");
    print_subnet(subnet);

    printf("Number of Subnets: %d\n", num_subnets);
    printf("Number of Hosts per Subnet: %d\n", num_hosts_per_subnet);
    printf("Total Number of Hosts: %d\n", total_hosts);

    return 0;
}