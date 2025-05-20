//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LEN 16

typedef struct {
    unsigned char octets[4];
} ip_addr_t;

typedef struct {
    ip_addr_t addr;
    unsigned int prefix_len;
} subnet_t;

int get_ip_addr(ip_addr_t *addr, char *buf) {
    int i;
    char *p;

    for (i = 0; i < 4; i++) {
        p = strchr(buf, '.');
        if (p == NULL) {
            return -1;
        }
        *p = '\0';
        addr->octets[i] = atoi(buf);
        buf = p + 1;
    }

    return 0;
}

int get_subnet(subnet_t *subnet, char *buf) {
    int i;
    char *p;

    for (i = 0; i < 4; i++) {
        p = strchr(buf, '.');
        if (p == NULL) {
            return -1;
        }
        *p = '\0';
        subnet->addr.octets[i] = atoi(buf);
        buf = p + 1;
    }

    p = strchr(buf, '/');
    if (p == NULL) {
        return -1;
    }
    *p = '\0';
    subnet->prefix_len = atoi(buf);

    return 0;
}

int check_subnet(subnet_t *subnet) {
    int i;

    for (i = 0; i < 4; i++) {
        if (subnet->addr.octets[i] > 255) {
            return -1;
        }
    }

    if (subnet->prefix_len > 32) {
        return -1;
    }

    return 0;
}

void print_ip_addr(ip_addr_t *addr) {
    int i;

    for (i = 0; i < 4; i++) {
        printf("%d", addr->octets[i]);
        if (i < 3) {
            printf(".");
        }
    }
}

void print_subnet(subnet_t *subnet) {
    print_ip_addr(&subnet->addr);
    printf("/");
    printf("%d", subnet->prefix_len);
}

unsigned int get_subnet_mask(subnet_t *subnet) {
    unsigned int mask = 0;

    for (int i = 0; i < subnet->prefix_len; i++) {
        mask |= (1 << (31 - i));
    }

    return mask;
}

unsigned int get_subnet_broadcast(subnet_t *subnet) {
    unsigned int broadcast = 0;

    broadcast = ~get_subnet_mask(subnet) & 0xFFFFFFFF;
    broadcast |= subnet->addr.octets[0] << 24;
    broadcast |= subnet->addr.octets[1] << 16;
    broadcast |= subnet->addr.octets[2] << 8;
    broadcast |= subnet->addr.octets[3];

    return broadcast;
}

unsigned int get_subnet_size(subnet_t *subnet) {
    unsigned int size = 0;

    size = pow(2, (32 - subnet->prefix_len));

    return size;
}

int main(int argc, char *argv[]) {
    subnet_t subnet;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <subnet>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (get_subnet(&subnet, argv[1]) != 0) {
        fprintf(stderr, "Invalid subnet: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (check_subnet(&subnet) != 0) {
        fprintf(stderr, "Invalid subnet: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("Subnet: ");
    print_subnet(&subnet);
    printf("\n");

    printf("Subnet Mask: 0x%08x\n", get_subnet_mask(&subnet));
    printf("Subnet Broadcast: ");
    print_ip_addr(&subnet.addr);
    printf("/%d\n", get_subnet_broadcast(&subnet));
    printf("Subnet Size: %d\n", get_subnet_size(&subnet));

    return EXIT_SUCCESS;
}