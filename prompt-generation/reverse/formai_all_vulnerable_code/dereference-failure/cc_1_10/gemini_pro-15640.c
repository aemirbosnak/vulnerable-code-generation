//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_SUBNET_LEN 18

typedef struct {
    unsigned char ip[4];
    unsigned char subnet[4];
    unsigned int cidr;
    unsigned int subnet_mask;
    unsigned int host_bits;
    unsigned int num_hosts;
    unsigned int first_host;
    unsigned int last_host;
    unsigned int broadcast;
} subnet_info;

void print_usage() {
    printf("Usage: sherlock_subnet <IP address> <Subnet mask or CIDR>\n");
    printf("Example: sherlock_subnet 192.168.1.0 24\n");
    printf("Example: sherlock_subnet 192.168.1.0 255.255.255.0\n");
}

int parse_ip(const char *ip, unsigned char *ip_out) {
    int i;
    char *s, *t;

    for (i = 0; i < 4; i++) {
        s = strtok(i == 0 ? (char *)ip : NULL, ".");
        if (s == NULL) {
            return -1;
        }
        ip_out[i] = (unsigned char)strtoul(s, &t, 10);
        if (*t != '\0') {
            return -1;
        }
    }

    return 0;
}

int parse_subnet(const char *subnet, subnet_info *info) {
    int i;
    char *s, *t;

    if (strchr(subnet, '/') != NULL) {
        info->cidr = (unsigned int)strtoul(subnet, &t, 10);
        if (*t != '/' || info->cidr > 32) {
            return -1;
        }
        info->subnet_mask = 0xFFFFFFFF << (32 - info->cidr);
    } else {
        if (parse_ip(subnet, info->subnet) != 0) {
            return -1;
        }
        info->subnet_mask = 0;
        for (i = 0; i < 4; i++) {
            info->subnet_mask |= info->subnet[i] << (8 * (3 - i));
        }
        info->cidr = 0;
        for (i = 0; i < 32; i++) {
            if ((info->subnet_mask & (1 << i)) == 0) {
                info->cidr = i;
                break;
            }
        }
    }

    return 0;
}

void calculate_subnet_info(subnet_info *info) {
    info->host_bits = 32 - info->cidr;
    info->num_hosts = (1 << info->host_bits) - 2;
    info->first_host = ntohl(info->ip[0] << 24 | info->ip[1] << 16 | info->ip[2] << 8 | info->ip[3]) & info->subnet_mask;
    info->last_host = ntohl(info->ip[0] << 24 | info->ip[1] << 16 | info->ip[2] << 8 | info->ip[3]) | ~info->subnet_mask;
    info->broadcast = ntohl(info->ip[0] << 24 | info->ip[1] << 16 | info->ip[2] << 8 | info->ip[3]) | ~info->subnet_mask | 1;
}

void print_subnet_info(const subnet_info *info) {
    printf("IP address: %u.%u.%u.%u\n", info->ip[0], info->ip[1], info->ip[2], info->ip[3]);
    printf("Subnet mask: %u.%u.%u.%u\n", info->subnet[0], info->subnet[1], info->subnet[2], info->subnet[3]);
    printf("CIDR: %u\n", info->cidr);
    printf("Host bits: %u\n", info->host_bits);
    printf("Number of hosts: %u\n", info->num_hosts);
    printf("First host: %u.%u.%u.%u\n", (info->first_host >> 24) & 0xFF, (info->first_host >> 16) & 0xFF, (info->first_host >> 8) & 0xFF, info->first_host & 0xFF);
    printf("Last host: %u.%u.%u.%u\n", (info->last_host >> 24) & 0xFF, (info->last_host >> 16) & 0xFF, (info->last_host >> 8) & 0xFF, info->last_host & 0xFF);
    printf("Broadcast: %u.%u.%u.%u\n", (info->broadcast >> 24) & 0xFF, (info->broadcast >> 16) & 0xFF, (info->broadcast >> 8) & 0xFF, info->broadcast & 0xFF);
}

int main(int argc, char **argv) {
    subnet_info info;

    if (argc != 3) {
        print_usage();
        return -1;
    }

    if (parse_ip(argv[1], info.ip) != 0) {
        printf("Invalid IP address: %s\n", argv[1]);
        return -1;
    }

    if (parse_subnet(argv[2], &info) != 0) {
        printf("Invalid subnet mask or CIDR: %s\n", argv[2]);
        return -1;
    }

    calculate_subnet_info(&info);
    print_subnet_info(&info);

    return 0;
}