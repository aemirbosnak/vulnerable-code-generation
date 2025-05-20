//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

// Define the maximum number of bits in an IPv4 address
#define MAX_BITS 32

// Define the maximum number of subnets
#define MAX_SUBNETS 100

// Define the maximum number of hosts per subnet
#define MAX_HOSTS_PER_SUBNET 65534

// Define the structure of a subnet
typedef struct subnet {
    unsigned int address;    // The address of the subnet
    unsigned int mask;     // The subnet mask
    unsigned int num_hosts;  // The number of hosts in the subnet
} subnet_t;

// Define the structure of a subnet calculator
typedef struct subnet_calculator {
    unsigned int address;    // The address of the network
    unsigned int mask;     // The subnet mask
    unsigned int num_subnets;  // The number of subnets
    subnet_t subnets[MAX_SUBNETS];  // The subnets
} subnet_calculator_t;

// Create a new subnet calculator
subnet_calculator_t *subnet_calculator_new(unsigned int address, unsigned int mask, unsigned int num_subnets) {
    subnet_calculator_t *calc = malloc(sizeof(subnet_calculator_t));
    calc->address = address;
    calc->mask = mask;
    calc->num_subnets = num_subnets;
    return calc;
}

// Free a subnet calculator
void subnet_calculator_free(subnet_calculator_t *calc) {
    free(calc);
}

// Calculate the subnets
void subnet_calculator_calculate(subnet_calculator_t *calc) {
    // Calculate the number of bits in the subnet mask
    unsigned int mask_bits = 0;
    for (unsigned int i = 0; i < MAX_BITS; i++) {
        if ((calc->mask >> i) & 1) {
            mask_bits++;
        }
    }

    // Calculate the number of hosts per subnet
    unsigned int num_hosts_per_subnet = pow(2, MAX_BITS - mask_bits) - 2;

    // Calculate the subnets
    for (unsigned int i = 0; i < calc->num_subnets; i++) {
        calc->subnets[i].address = calc->address + (i * num_hosts_per_subnet);
        calc->subnets[i].mask = calc->mask;
        calc->subnets[i].num_hosts = num_hosts_per_subnet;
    }
}

// Print the subnets
void subnet_calculator_print(subnet_calculator_t *calc) {
    for (unsigned int i = 0; i < calc->num_subnets; i++) {
        printf("Subnet %u:\n", i + 1);
        printf("  Address: %u.%u.%u.%u\n",
            (calc->subnets[i].address >> 24) & 0xFF,
            (calc->subnets[i].address >> 16) & 0xFF,
            (calc->subnets[i].address >> 8) & 0xFF,
            calc->subnets[i].address & 0xFF);
        printf("  Mask: %u.%u.%u.%u\n",
            (calc->subnets[i].mask >> 24) & 0xFF,
            (calc->subnets[i].mask >> 16) & 0xFF,
            (calc->subnets[i].mask >> 8) & 0xFF,
            calc->subnets[i].mask & 0xFF);
        printf("  Num hosts: %u\n", calc->subnets[i].num_hosts);
    }
}

int main(int argc, char *argv[]) {
    // Check the arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <address> <mask> <num_subnets>\n", argv[0]);
        return 1;
    }

    // Parse the arguments
    unsigned int address = inet_addr(argv[1]);
    unsigned int mask = inet_addr(argv[2]);
    unsigned int num_subnets = atoi(argv[3]);

    // Create a subnet calculator
    subnet_calculator_t *calc = subnet_calculator_new(address, mask, num_subnets);

    // Calculate the subnets
    subnet_calculator_calculate(calc);

    // Print the subnets
    subnet_calculator_print(calc);

    // Free the subnet calculator
    subnet_calculator_free(calc);

    return 0;
}