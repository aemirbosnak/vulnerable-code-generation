//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct ip_address {
    unsigned char octet1, octet2, octet3, octet4;
};

struct subnet {
    struct ip_address network;
    struct ip_address broadcast;
    struct ip_address first_usable;
};

struct subnet *create_subnet(struct ip_address network, struct ip_address broadcast) {
    struct subnet *subnet = malloc(sizeof(struct subnet));
    subnet->network = network;
    subnet->broadcast = broadcast;
    subnet->first_usable = network;
    return subnet;
}

struct ip_address get_next_usable_address(struct subnet *subnet, struct ip_address address) {
    struct ip_address next = address;
    next.octet4 = 0;
    while (next.octet4 == 0) {
        if (address.octet3 == 0 && address.octet2 == 0 && address.octet1 == 0) {
            return subnet->first_usable;
        }
        next.octet1++;
        if (next.octet1 == 256) {
            next.octet1 = 0;
            next.octet2++;
            if (next.octet2 == 256) {
                next.octet2 = 0;
                next.octet3++;
                if (next.octet3 == 256) {
                    next.octet3 = 0;
                    next.octet4 = 1;
                }
            }
        }
    }
    return next;
}

void print_subnet(struct subnet *subnet) {
    printf("Subnet: ");
    printf("Network: %u.%u.%u.%u\n", subnet->network.octet1, subnet->network.octet2, subnet->network.octet3, subnet->network.octet4);
    printf("Broadcast: %u.%u.%u.%u\n", subnet->broadcast.octet1, subnet->broadcast.octet2, subnet->broadcast.octet3, subnet->broadcast.octet4);
    printf("First usable: %u.%u.%u.%u\n", subnet->first_usable.octet1, subnet->first_usable.octet2, subnet->first_usable.octet3, subnet->first_usable.octet4);
}

int main(int argc, char *argv[]) {
    struct ip_address network = { 192, 168, 1, 0 };
    struct ip_address broadcast = { 192, 168, 1, 255 };
    struct subnet *subnet = create_subnet(network, broadcast);
    print_subnet(subnet);
    struct ip_address next_address = get_next_usable_address(subnet, network);
    print_subnet(subnet);
    return 0;
}