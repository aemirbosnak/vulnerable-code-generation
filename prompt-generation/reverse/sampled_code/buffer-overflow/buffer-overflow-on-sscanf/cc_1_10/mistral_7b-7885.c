//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define IP_STR_LEN 16
#define MASK_STR_LEN 10

typedef struct {
    unsigned char ip[4];
    unsigned char mask[4];
} ip_mask;

void binary_string(unsigned char *bin, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%c", (bin[i] & 0x80) ? '1' : '0');
        bin[i] <<= 1;
        if ((i + 1) % 8 == 0 && i < len - 1)
            putchar(' ');
    }
    putchar('\n');
}

void ip_to_binary(unsigned char *ip) {
    int i;
    for (i = 0; i < 4; i++) {
        binary_string(&ip[i], 1);
        putchar('.');
    }
    putchar('\n');
}

void mask_to_binary(unsigned char *mask) {
    int i;
    for (i = 0; i < 4; i++) {
        binary_string(&mask[i], 1);
        putchar('.');
    }
    putchar('\n');
}

void ip_binary(ip_mask ipmsk) {
    ip_to_binary(ipmsk.ip);
    mask_to_binary(ipmsk.mask);
}

ip_mask ip_subnet(unsigned char *ip, unsigned char *mask) {
    ip_mask ipmsk;
    int i;
    for (i = 0; i < 4; i++) {
        ipmsk.ip[i] = ip[i] & mask[i];
        ipmsk.mask[i] = mask[i];
    }
    return ipmsk;
}

void broadcast_address(ip_mask ipmsk) {
    int i;
    for (i = 0; i < 4; i++)
        ipmsk.ip[i] += ~ipmsk.mask[i] & 0xFF;
    ip_binary(ipmsk);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s IP_ADDRESS SUBNET_MASK\n", argv[0]);
        return 1;
    }

    unsigned char ip[4], mask[4];
    sscanf(argv[1], "%hhd.%hhd.%hhd.%hhd", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(argv[2], "%hhd.%hhd.%hhd.%hhd", &mask[0], &mask[1], &mask[2], &mask[3]);

    ip_mask ipmsk = ip_subnet(ip, mask);
    broadcast_address(ipmsk);

    char ipstr[IP_STR_LEN], maskstr[MASK_STR_LEN];
    sprintf(ipstr, "%hhd.%hhd.%hhd.%hhd", ip[0], ip[1], ip[2], ip[3]);
    sprintf(maskstr, "%hhd.%hhd.%hhd.%hhd", mask[0], mask[1], mask[2], mask[3]);
    printf("Subnet IP: %s\n", ipstr);
    printf("Subnet Mask: %s\n", maskstr);

    return 0;
}