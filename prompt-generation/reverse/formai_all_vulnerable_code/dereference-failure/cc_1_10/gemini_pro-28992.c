//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 3
#define MAX_CIDR_LEN 3

typedef struct {
    uint8_t addr[4];
    uint8_t mask[4];
} ip_t;

typedef struct {
    uint32_t cidr;
    ip_t ip;
    ip_t mask;
} subnet_t;

static int parse_ip(const char *ip_str, ip_t *ip) {
    int i,j,k,l;
    char *buf = strdup(ip_str);
    char *p = strtok(buf, ".");
    if (!p) return -1;
    for (i=0; i<4; i++) {
        ip->addr[i] = atoi(p);
        if (ip->addr[i] > 255) return -1;
        p = strtok(NULL, ".");
        if (!p) return -1;
    }
    free(buf);
    return 0;
}

static int parse_mask(const char *mask_str, ip_t *mask) {
    int i,j,k,l;
    char *buf = strdup(mask_str);
    char *p = strtok(buf, ".");
    if (!p) return -1;
    for (i=0; i<4; i++) {
        mask->mask[i] = atoi(p);
        if (mask->mask[i] > 255) return -1;
        p = strtok(NULL, ".");
        if (!p) return -1;
    }
    free(buf);
    return 0;
}

static int parse_cidr(const char *cidr_str, uint32_t *cidr) {
    *cidr = atoi(cidr_str);
    if (*cidr > 32) return -1;
    return 0;
}

static void print_ip(const ip_t *ip) {
    printf("%d.%d.%d.%d", ip->addr[0], ip->addr[1], ip->addr[2], ip->addr[3]);
}

static void print_subnet(const subnet_t *subnet) {
    printf("CIDR: %d\n", subnet->cidr);
    printf("IP: ");
    print_ip(&subnet->ip);
    printf("\n");
    printf("Mask: ");
    print_ip(&subnet->mask);
    printf("\n");
}

static int calculate_subnet(const ip_t *ip, const ip_t *mask, subnet_t *subnet) {
    int i,j,k,l;
    uint32_t cidr = 0;
    for (i=0; i<4; i++) {
        if (mask->mask[i] > ip->addr[i]) return -1;
        subnet->mask.mask[i] = mask->mask[i];
        if (mask->mask[i] == 255) cidr += 8;
        else {
            for (j=0; j<8; j++) {
                if (mask->mask[i] & (1<<j)) cidr++;
            }
        }
    }
    subnet->cidr = cidr;
    for (i=0; i<4; i++) {
        subnet->ip.addr[i] = ip->addr[i] & mask->mask[i];
    }
    return 0;
}

int main(int argc, char **argv) {
    int i,j,k,l;
    ip_t ip;
    ip_t mask;
    subnet_t subnet;
    if (argc != 4) {
        printf("Usage: %s <ip> <mask> <cidr>\n", argv[0]);
        return -1;
    }
    if (parse_ip(argv[1], &ip) < 0) {
        printf("Invalid IP address: %s\n", argv[1]);
        return -1;
    }
    if (parse_mask(argv[2], &mask) < 0) {
        printf("Invalid subnet mask: %s\n", argv[2]);
        return -1;
    }
    if (parse_cidr(argv[3], &subnet.cidr) < 0) {
        printf("Invalid CIDR: %s\n", argv[3]);
        return -1;
    }
    if (calculate_subnet(&ip, &mask, &subnet) < 0) {
        printf("Invalid subnet parameters\n");
        return -1;
    }
    print_subnet(&subnet);
    return 0;
}