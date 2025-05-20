//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CIDR 32
#define BITS_PER_BYTE 8
#define BYTES_PER_IP 4
#define IP_SIZE 15
#define MAX_IP_LENGTH 15

void print_usage() {
    printf("Space Subnet Calculator\n");
    printf("Usage: ssc [CIDR]\n");
    printf("Example: ssc 192.168.1.1/24\n");
}

bool is_valid_cidr(int cidr) {
    if (cidr <= 0 || cidr > MAX_CIDR) {
        return false;
    }
    int total_bits = 32 - cidr;
    int num_bytes = total_bits / BITS_PER_BYTE;
    int remaining_bits = total_bits % BITS_PER_BYTE;

    return num_bytes > 0 && remaining_bits != 0;
}

void print_error(const char *message) {
    fprintf(stderr, "%s\n", message);
    print_usage();
    exit(1);
}

void print_ip(const unsigned char *ip) {
    for (int i = 0; i < BYTES_PER_IP; i++) {
        printf("%d.", ip[i]);
        if (i < BYTES_PER_IP - 1) {
            printf(" ");
        }
    }
    printf("\b");
}

void print_mask(int cidr) {
    int total_bits = 32 - cidr;
    int num_bytes = total_bits / BITS_PER_BYTE;
    int remaining_bits = total_bits % BITS_PER_BYTE;

    printf("/%d ", cidr);
    for (int i = num_bytes - 1; i >= 0; i--) {
        int mask_byte = 0xFF >> (BITS_PER_BYTE - remaining_bits);
        printf("%d.", mask_byte & ((1 << (7 - (i * 8))) >> (7 - (i * 8))));
        remaining_bits -= 8;
        num_bytes--;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_usage();
    }

    int cidr = atoi(argv[1]);
    if (!is_valid_cidr(cidr)) {
        print_error("Invalid CIDR value");
    }

    unsigned char ip[BYTES_PER_IP];
    for (int i = 0; i < IP_SIZE; i++) {
        char c = argv[1][i];
        if (isspace(c) || isdigit(c)) {
            if (i > 0 && isdigit(argv[1][i - 1])) {
                print_error("Invalid IP address format");
            }
            if (i == 0 && c != '0') {
                print_error("IP address must start with '0'");
            }
            ip[i - (i % BYTES_PER_IP)] = (unsigned char)strtoul(&c, NULL, 10);
        }
    }

    if (ip[0] != 0) {
        printf("IP: ");
        print_ip(ip);
        printf("\n");
    }

    printf("Subnet mask: ");
    print_mask(cidr);
    printf("\n");

    return 0;
}