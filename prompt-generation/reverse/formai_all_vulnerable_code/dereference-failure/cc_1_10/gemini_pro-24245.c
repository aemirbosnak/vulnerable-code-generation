//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 3
#define MAX_CIDR_LEN 3

typedef struct {
    uint32_t ip;
    uint32_t mask;
    uint8_t cidr;
} ip_subnet;

int get_ip_address(char *ip_str, ip_subnet *subnet) {
    char *ip_parts[4];
    int i;

    if (ip_str == NULL || subnet == NULL) {
        return -1;
    }

    if (strlen(ip_str) > MAX_IP_LEN) {
        return -1;
    }

    for (i = 0; i < 4; i++) {
        ip_parts[i] = strtok(ip_str, ".");
        if (ip_parts[i] == NULL) {
            return -1;
        }
    }

    subnet->ip = (uint32_t)atoi(ip_parts[0]) << 24 | (uint32_t)atoi(ip_parts[1]) << 16 | (uint32_t)atoi(ip_parts[2]) << 8 | (uint32_t)atoi(ip_parts[3]);

    return 0;
}

int get_subnet_mask(char *mask_str, ip_subnet *subnet) {
    char *mask_parts[4];
    int i;

    if (mask_str == NULL || subnet == NULL) {
        return -1;
    }

    if (strlen(mask_str) > MAX_MASK_LEN) {
        return -1;
    }

    for (i = 0; i < 4; i++) {
        mask_parts[i] = strtok(mask_str, ".");
        if (mask_parts[i] == NULL) {
            return -1;
        }
    }

    subnet->mask = (uint32_t)atoi(mask_parts[0]) << 24 | (uint32_t)atoi(mask_parts[1]) << 16 | (uint32_t)atoi(mask_parts[2]) << 8 | (uint32_t)atoi(mask_parts[3]);

    return 0;
}

int get_cidr_prefix(char *cidr_str, ip_subnet *subnet) {
    int cidr;

    if (cidr_str == NULL || subnet == NULL) {
        return -1;
    }

    if (strlen(cidr_str) > MAX_CIDR_LEN) {
        return -1;
    }

    cidr = atoi(cidr_str);
    if (cidr < 0 || cidr > 32) {
        return -1;
    }

    subnet->cidr = (uint8_t)cidr;

    return 0;
}

int calculate_subnet(ip_subnet *subnet) {
    uint32_t mask_bits;

    if (subnet == NULL) {
        return -1;
    }

    if (subnet->cidr == 0) {
        subnet->mask = 0xFFFFFFFF;
        return 0;
    }

    mask_bits = 0xFFFFFFFF << (32 - subnet->cidr);
    subnet->mask = mask_bits;

    return 0;
}

int print_subnet(ip_subnet *subnet) {
    char ip_str[MAX_IP_LEN];
    char mask_str[MAX_MASK_LEN];
    char cidr_str[MAX_CIDR_LEN];

    if (subnet == NULL) {
        return -1;
    }

    sprintf(ip_str, "%d.%d.%d.%d", (subnet->ip >> 24) & 0xFF, (subnet->ip >> 16) & 0xFF, (subnet->ip >> 8) & 0xFF, subnet->ip & 0xFF);
    sprintf(mask_str, "%d.%d.%d.%d", (subnet->mask >> 24) & 0xFF, (subnet->mask >> 16) & 0xFF, (subnet->mask >> 8) & 0xFF, subnet->mask & 0xFF);
    sprintf(cidr_str, "%d", subnet->cidr);

    printf("IP Address: %s\n", ip_str);
    printf("Subnet Mask: %s\n", mask_str);
    printf("CIDR Prefix: %s\n", cidr_str);

    return 0;
}

int main(int argc, char **argv) {
    ip_subnet subnet;
    char *ip_str;
    char *mask_str;
    char *cidr_str;
    int ret;

    if (argc != 4) {
        printf("Usage: %s <ip_address> <subnet_mask> <cidr_prefix>\n", argv[0]);
        return -1;
    }

    ip_str = argv[1];
    mask_str = argv[2];
    cidr_str = argv[3];

    ret = get_ip_address(ip_str, &subnet);
    if (ret != 0) {
        printf("Invalid IP address: %s\n", ip_str);
        return -1;
    }

    ret = get_subnet_mask(mask_str, &subnet);
    if (ret != 0) {
        printf("Invalid subnet mask: %s\n", mask_str);
        return -1;
    }

    ret = get_cidr_prefix(cidr_str, &subnet);
    if (ret != 0) {
        printf("Invalid CIDR prefix: %s\n", cidr_str);
        return -1;
    }

    ret = calculate_subnet(&subnet);
    if (ret != 0) {
        printf("Error calculating subnet\n");
        return -1;
    }

    print_subnet(&subnet);

    return 0;
}