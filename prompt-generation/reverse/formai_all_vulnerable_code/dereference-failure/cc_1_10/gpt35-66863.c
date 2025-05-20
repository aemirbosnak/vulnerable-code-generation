//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP 32

int get_octet(int mask, int octet) {
    return (mask >> (8 * (3 - octet))) & 0xff;
}

void dec_to_bin(int dec, char *bin) {
    int i;
    for (i = 0; i < 8; i++) {
        bin[7 - i] = (dec & (1 << i)) ? '1' : '0';
    }
}

long bin_to_dec(char *bin) {
    long dec = 0;
    int i;
    for (i = 0; i < 8; i++) {
        dec |= (bin[i] - '0') << (7 - i);
    }
    return dec;
}

void print_mask(int mask) {
    int octet, bits;
    char bin[9] = {0};
    printf("Mask:\t%d.%d.%d.%d\n", get_octet(mask, 0), get_octet(mask, 1), get_octet(mask, 2), get_octet(mask, 3));
    for (octet = 0; octet < 4; octet++) {
        dec_to_bin(get_octet(mask, octet), bin);
        bits = 0;
        while (bin[bits] == '1') bits++;
        printf("\t%d.%d.%d.%d/%d\n", get_octet(mask, 0), get_octet(mask, 1), get_octet(mask, 2), get_octet(mask, 3), octet * 8 + bits);
    }
}

void print_address(int address) {
    printf("Address:\t%d.%d.%d.%d\n", get_octet(address, 0), get_octet(address, 1), get_octet(address, 2), get_octet(address, 3));
}

int main(int argc, char **argv) {
    char ip[MAX_IP], mask[MAX_IP];
    int address, mask_int, network, broadcast, num_hosts;
    if (argc > 1) {
        strncpy(ip, argv[1], MAX_IP);
        if (argc > 2) {
            strncpy(mask, argv[2], MAX_IP);
        } else {
            printf("Please enter subnet mask: ");
            fgets(mask, MAX_IP, stdin);
            mask[strlen(mask) - 1] = '\0';
        }
    } else {
        printf("Please enter IP address: ");
        fgets(ip, MAX_IP, stdin);
        ip[strlen(ip) - 1] = '\0';
        printf("Please enter subnet mask: ");
        fgets(mask, MAX_IP, stdin);
        mask[strlen(mask) - 1] = '\0';
    }
    address = ntohl(inet_addr(ip));
    mask_int = ntohl(inet_addr(mask));
    print_address(address);
    print_mask(mask_int);
    network = (address & mask_int);
    printf("Network:\t%d.%d.%d.%d\n", get_octet(network, 0), get_octet(network, 1), get_octet(network, 2), get_octet(network, 3));
    broadcast = (address & mask_int) | ~mask_int;
    printf("Broadcast:\t%d.%d.%d.%d\n", get_octet(broadcast, 0), get_octet(broadcast, 1), get_octet(broadcast, 2), get_octet(broadcast, 3));
    num_hosts = (~mask_int & 0xffffffff) - 1;
    printf("# of Hosts:\t%d\n", num_hosts);
    return 0;
}