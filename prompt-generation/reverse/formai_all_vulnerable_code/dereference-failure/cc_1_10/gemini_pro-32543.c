//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 3

typedef struct {
    unsigned int ip;
    unsigned int mask;
    unsigned int network;
    unsigned int broadcast;
    unsigned int hostmin;
    unsigned int hostmax;
    unsigned int num_hosts;
} subnet_info;

void print_usage() {
    printf("Usage: subnetcalc <ip> <mask>\n");
    printf("Example: subnetcalc 192.168.1.0 24\n");
}

int is_valid_ip(char *ip) {
    int octets, i;
    char *ptr;

    octets = 0;
    ptr = strtok(ip, ".");
    while (ptr != NULL) {
        octets++;
        if (atoi(ptr) > 255) {
            return 0;
        }
        ptr = strtok(NULL, ".");
    }
    if (octets != 4) {
        return 0;
    }
    return 1;
}

int is_valid_mask(char *mask) {
    int bits, i;

    bits = atoi(mask);
    if (bits < 0 || bits > 32) {
        return 0;
    }
    for (i = 0; i < bits; i++) {
        if (mask[i] != '1') {
            return 0;
        }
    }
    for (i = bits; i < 32; i++) {
        if (mask[i] != '0') {
            return 0;
        }
    }
    return 1;
}

unsigned int ip_to_int(char *ip) {
    unsigned int i, octet, ip_int;

    ip_int = 0;
    for (i = 0; i < 4; i++) {
        octet = atoi(strtok(ip, "."));
        ip_int |= octet << (8 * (3 - i));
    }
    return ip_int;
}

char *int_to_ip(unsigned int ip) {
    static char ip_str[MAX_IP_LEN];
    unsigned int octet;
    int i;

    for (i = 0; i < 4; i++) {
        octet = (ip >> (8 * (3 - i))) & 0xFF;
        sprintf(ip_str + strlen(ip_str), "%d", octet);
        if (i < 3) {
            strcat(ip_str, ".");
        }
    }
    return ip_str;
}

void calculate_subnet(subnet_info *subnet, unsigned int ip, unsigned int mask) {
    subnet->ip = ip;
    subnet->mask = mask;
    subnet->network = subnet->ip & subnet->mask;
    subnet->broadcast = subnet->network | ~subnet->mask;
    subnet->hostmin = subnet->network + 1;
    subnet->hostmax = subnet->broadcast - 1;
    subnet->num_hosts = pow(2, 32 - mask) - 2;
}

void print_subnet_info(subnet_info *subnet) {
    printf("IP Address: %s\n", int_to_ip(subnet->ip));
    printf("Subnet Mask: %d\n", subnet->mask);
    printf("Network Address: %s\n", int_to_ip(subnet->network));
    printf("Broadcast Address: %s\n", int_to_ip(subnet->broadcast));
    printf("Host Min: %s\n", int_to_ip(subnet->hostmin));
    printf("Host Max: %s\n", int_to_ip(subnet->hostmax));
    printf("Number of Hosts: %u\n", subnet->num_hosts);
}

int main(int argc, char **argv) {
    subnet_info subnet;
    char ip[MAX_IP_LEN], mask[MAX_MASK_LEN];

    if (argc < 3) {
        print_usage();
        return 1;
    }

    strcpy(ip, argv[1]);
    strcpy(mask, argv[2]);

    if (!is_valid_ip(ip)) {
        printf("Invalid IP address: %s\n", ip);
        return 1;
    }

    if (!is_valid_mask(mask)) {
        printf("Invalid subnet mask: %s\n", mask);
        return 1;
    }

    calculate_subnet(&subnet, ip_to_int(ip), atoi(mask));
    print_subnet_info(&subnet);

    return 0;
}