//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *  A sub-net calculator that masks with magic
 */

#define MAGIC_NUMBER 42

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Usage: %s <ip_address> <mask>\n", argv[0]);
        return 1;
    }

    char* ip_address = argv[1];
    char* mask_str = argv[2];
    long mask = strtol(mask_str, NULL, 10);

    if (mask < 0 || mask > 32) {
        printf("Invalid mask value: %ld\n", mask);
        return 1;
    }

    char* octet = strtok(ip_address, ".");
    int octet_count = 0;
    long ip = 0;

    while (octet != NULL) {
        if (octet_count > 3) {
            printf("Invalid ip address format: %s\n", ip_address);
            return 1;
        }

        ip += strtol(octet, NULL, 10);
        ip <<= 8;
        octet = strtok(NULL, ".");
        octet_count++;
    }

    ip >>= 8;
    long magic_mask = (1 << MAGIC_NUMBER) - 1;
    magic_mask <<= 32 - mask;
    ip &= magic_mask;

    printf("Subnet Address: %ld.%ld.%ld.%ld\n",
            (ip >> 24) & 0xff,
            (ip >> 16) & 0xff,
            (ip >> 8) & 0xff,
            (ip >> 0) & 0xff);
    return 0;
}