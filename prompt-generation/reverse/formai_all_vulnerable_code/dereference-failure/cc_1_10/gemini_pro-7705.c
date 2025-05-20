//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 4

typedef struct {
    unsigned char octets[4];
} IPAddress;

typedef struct {
    unsigned char octets[4];
    unsigned char mask;
} SubnetMask;

static int parse_ip_address(const char *str, IPAddress *ip) {
    int i, octet;
    char *pch;

    for (i = 0; i < 4; i++) {
        pch = strtok(str, ".");
        if (pch == NULL) {
            return -1;
        }
        octet = atoi(pch);
        if (octet < 0 || octet > 255) {
            return -1;
        }
        ip->octets[i] = octet;
        str = NULL;
    }

    return 0;
}

static int parse_subnet_mask(const char *str, SubnetMask *mask) {
    int i, octet;
    char *pch;

    for (i = 0; i < 4; i++) {
        pch = strtok(str, ".");
        if (pch == NULL) {
            return -1;
        }
        octet = atoi(pch);
        if (octet < 0 || octet > 255) {
            return -1;
        }
        mask->octets[i] = octet;
        str = NULL;
    }

    mask->mask = 0;
    for (i = 0; i < 4; i++) {
        mask->mask |= (mask->octets[i] << (8 * i));
    }

    return 0;
}

static void print_ip_address(const IPAddress *ip) {
    int i;

    for (i = 0; i < 4; i++) {
        printf("%d", ip->octets[i]);
        if (i < 3) {
            printf(".");
        }
    }
}

static void print_subnet_mask(const SubnetMask *mask) {
    int i;

    for (i = 0; i < 4; i++) {
        printf("%d", mask->octets[i]);
        if (i < 3) {
            printf(".");
        }
    }
}

static int calculate_network_address(const IPAddress *ip, const SubnetMask *mask, IPAddress *network) {
    int i;

    for (i = 0; i < 4; i++) {
        network->octets[i] = ip->octets[i] & mask->octets[i];
    }

    return 0;
}

static int calculate_broadcast_address(const IPAddress *ip, const SubnetMask *mask, IPAddress *broadcast) {
    int i;

    for (i = 0; i < 4; i++) {
        broadcast->octets[i] = ip->octets[i] | ~mask->octets[i];
    }

    return 0;
}

static int calculate_number_of_hosts(const SubnetMask *mask) {
    int i, num_hosts;

    num_hosts = 0;
    for (i = 0; i < 4; i++) {
        num_hosts += (255 - mask->octets[i]);
    }

    return num_hosts;
}

static int print_subnet_calculator(const char *ip_str, const char *mask_str) {
    IPAddress ip;
    SubnetMask mask;
    IPAddress network;
    IPAddress broadcast;
    int num_hosts;

    if (parse_ip_address(ip_str, &ip) != 0) {
        printf("Invalid IP address: %s\n", ip_str);
        return -1;
    }

    if (parse_subnet_mask(mask_str, &mask) != 0) {
        printf("Invalid subnet mask: %s\n", mask_str);
        return -1;
    }

    printf("IP address: ");
    print_ip_address(&ip);
    printf("\n");

    printf("Subnet mask: ");
    print_subnet_mask(&mask);
    printf("\n");

    calculate_network_address(&ip, &mask, &network);

    printf("Network address: ");
    print_ip_address(&network);
    printf("\n");

    calculate_broadcast_address(&ip, &mask, &broadcast);

    printf("Broadcast address: ");
    print_ip_address(&broadcast);
    printf("\n");

    num_hosts = calculate_number_of_hosts(&mask);

    printf("Number of hosts: %d\n", num_hosts);

    return 0;
}

int main(int argc, char *argv[]) {
    int i;

    if (argc != 3) {
        printf("Usage: %s <ip_address> <subnet_mask>\n", argv[0]);
        return -1;
    }

    print_subnet_calculator(argv[1], argv[2]);

    return 0;
}