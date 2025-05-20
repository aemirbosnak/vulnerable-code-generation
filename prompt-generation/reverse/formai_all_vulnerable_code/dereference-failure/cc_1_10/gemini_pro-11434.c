//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 16

struct ip_addr {
    unsigned char octets[4];
};

struct ip_mask {
    unsigned char octets[4];
};

int get_ip_addr(struct ip_addr *addr, char *str) {
    int i;
    char *ptr;

    ptr = strtok(str, ".");
    if (ptr == NULL) {
        return -1;
    }

    for (i = 0; i < 4; i++) {
        addr->octets[i] = atoi(ptr);
        if (addr->octets[i] > 255) {
            return -1;
        }
        ptr = strtok(NULL, ".");
        if (ptr == NULL) {
            return -1;
        }
    }

    return 0;
}

int get_ip_mask(struct ip_mask *mask, char *str) {
    int i;
    char *ptr;

    ptr = strtok(str, ".");
    if (ptr == NULL) {
        return -1;
    }

    for (i = 0; i < 4; i++) {
        mask->octets[i] = atoi(ptr);
        if (mask->octets[i] > 255) {
            return -1;
        }
        ptr = strtok(NULL, ".");
        if (ptr == NULL) {
            return -1;
        }
    }

    return 0;
}

int get_network_addr(struct ip_addr *network, struct ip_addr *addr, struct ip_mask *mask) {
    int i;

    for (i = 0; i < 4; i++) {
        network->octets[i] = addr->octets[i] & mask->octets[i];
    }

    return 0;
}

int get_broadcast_addr(struct ip_addr *broadcast, struct ip_addr *addr, struct ip_mask *mask) {
    int i;

    for (i = 0; i < 4; i++) {
        broadcast->octets[i] = addr->octets[i] | ~mask->octets[i];
    }

    return 0;
}

int get_num_hosts(struct ip_mask *mask) {
    int i;
    int num_hosts = 1;

    for (i = 0; i < 4; i++) {
        num_hosts *= (256 - mask->octets[i]);
    }

    return num_hosts;
}

void print_ip_addr(struct ip_addr *addr) {
    int i;

    for (i = 0; i < 4; i++) {
        printf("%d", addr->octets[i]);
        if (i < 3) {
            printf(".");
        }
    }
}

void print_ip_mask(struct ip_mask *mask) {
    int i;

    for (i = 0; i < 4; i++) {
        printf("%d", mask->octets[i]);
        if (i < 3) {
            printf(".");
        }
    }
}

int main(int argc, char *argv[]) {
    struct ip_addr addr, network, broadcast;
    struct ip_mask mask;
    int num_hosts;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_addr> <ip_mask>\n", argv[0]);
        return 1;
    }

    if (get_ip_addr(&addr, argv[1]) != 0) {
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        return 2;
    }

    if (get_ip_mask(&mask, argv[2]) != 0) {
        fprintf(stderr, "Invalid IP mask: %s\n", argv[2]);
        return 3;
    }

    if (get_network_addr(&network, &addr, &mask) != 0) {
        fprintf(stderr, "Invalid network address\n");
        return 4;
    }

    if (get_broadcast_addr(&broadcast, &addr, &mask) != 0) {
        fprintf(stderr, "Invalid broadcast address\n");
        return 5;
    }

    num_hosts = get_num_hosts(&mask);

    printf("IP address: ");
    print_ip_addr(&addr);
    printf("\n");

    printf("IP mask: ");
    print_ip_mask(&mask);
    printf("\n");

    printf("Network address: ");
    print_ip_addr(&network);
    printf("\n");

    printf("Broadcast address: ");
    print_ip_addr(&broadcast);
    printf("\n");

    printf("Number of hosts: %d\n", num_hosts);

    return 0;
}