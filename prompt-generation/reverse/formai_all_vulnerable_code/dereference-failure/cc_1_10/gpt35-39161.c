//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function to check if the given IP address is valid */
bool is_valid_ip(char *ip_address){
    int num, dots = 0, i = 0;
    char *ptr;

    if (ip_address == NULL) {
        return false;
    }

    ptr = strtok(ip_address, ".");
  
    if (ptr == NULL) {
        return false;
    }

    while (ptr) {

        if (!isdigit(*ptr)) {
            return false;
        }

        num = atoi(ptr);

        if (num < 0 || num > 255) {
            return false;
        }

        ptr = strtok(NULL, ".");
        i++;

        if (i < 4 && ptr == NULL) {
            return false;
        }

        if (ptr != NULL) {
            dots++;
        }
    }
  
    if (dots != 3) {
        return false;
    }

    return true;
}

/* Function to calculate the Subnet Mask */
void calculate_subnet_mask(int subnet_bits) {
    int i, byte = 0;
    unsigned int mask = 0xffffffff;
  
    for (i = 0; i < subnet_bits; i++) {
        mask <<= 1;
    }

    for(i = 0; i < 4; i++) {
        byte = (mask >> (24 - 8 * i)) & 0xff;
        printf("%d", byte);

        if (i != 3) {
            printf(".");
        }
    }
}

/* Main Function */
int main(int argc, char *argv[]) {
    char *ip_address;
    int subnet_bits;

    if (argc != 3) {
        printf("ERROR: Please provide an IP address and subnet bits.\n");
        return 0;
    }

    ip_address = argv[1];
    subnet_bits = atoi(argv[2]);

    if (!is_valid_ip(ip_address)) {
        printf("ERROR: The provided IP address is not valid.\n");
        return 0;
    }

    if (subnet_bits > 32 || subnet_bits < 0) {
        printf("ERROR: The provided subnet bits are not valid.\n");
        return 0;
    }

    printf("The subnet mask for %s/%d is: ", ip_address, subnet_bits);
    calculate_subnet_mask(subnet_bits);
    printf("\n");

    return 0;
}