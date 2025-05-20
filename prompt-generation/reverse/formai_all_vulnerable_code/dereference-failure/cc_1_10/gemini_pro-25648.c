//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 16
#define MAX_CIDR_LEN 32
#define MAX_HOSTS_LEN 12

struct subnetting_parameters {
    char ip_address[MAX_IP_LEN];
    char subnet_mask[MAX_MASK_LEN];
    unsigned int cidr_notation;
    unsigned int num_hosts;
    bool valid;
};

void print_invalid_parameters(struct subnetting_parameters *params) {
    printf("Invalid parameters:\n");
    if (!params->valid) {
        printf("  - IP address: %s\n", params->ip_address);
    }
    if (!params->valid) {
        printf("  - Subnet mask: %s\n", params->subnet_mask);
    }
    if (!params->valid) {
        printf("  - CIDR notation: %u\n", params->cidr_notation);
    }
    if (!params->valid) {
        printf("  - Number of hosts: %u\n", params->num_hosts);
    }
}

bool validate_ip_address(char *ip_address) {
    // Check for valid format
    int octet_count = 0;
    char *octet = strtok(ip_address, ".");
    while (octet != NULL) {
        octet_count++;
        if (octet_count > 4) {
            return false;
        }
        // Check for valid octet value
        int octet_value = atoi(octet);
        if (octet_value < 0 || octet_value > 255) {
            return false;
        }
        octet = strtok(NULL, ".");
    }
    if (octet_count != 4) {
        return false;
    }
    return true;
}

bool validate_subnet_mask(char *subnet_mask) {
    // Check for valid format
    int octet_count = 0;
    char *octet = strtok(subnet_mask, ".");
    while (octet != NULL) {
        octet_count++;
        if (octet_count > 4) {
            return false;
        }
        // Check for valid octet value
        int octet_value = atoi(octet);
        if (octet_value < 0 || octet_value > 255) {
            return false;
        }
        octet = strtok(NULL, ".");
    }
    if (octet_count != 4) {
        return false;
    }
    // Check for valid subnet mask pattern
    unsigned int mask_bits = 0;
    for (int i = 0; i < 4; i++) {
        int octet_value = atoi(strtok(subnet_mask, "."));
        mask_bits += __builtin_popcount(octet_value);
    }
    if (mask_bits <= 0 || mask_bits > 32) {
        return false;
    }
    return true;
}

bool validate_cidr_notation(unsigned int cidr_notation) {
    if (cidr_notation < 0 || cidr_notation > 32) {
        return false;
    }
    return true;
}

bool convert_cidr_to_subnet_mask(unsigned int cidr_notation, char *subnet_mask) {
    if (!validate_cidr_notation(cidr_notation)) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        int octet_value = 0;
        if (cidr_notation >= 8) {
            octet_value = 255;
            cidr_notation -= 8;
        } else {
            octet_value = (1 << cidr_notation) - 1;
            cidr_notation = 0;
        }
        sprintf(subnet_mask + strlen(subnet_mask), "%d.", octet_value);
    }
    subnet_mask[strlen(subnet_mask) - 1] = '\0';
    return true;
}

bool validate_num_hosts(unsigned int num_hosts) {
    if (num_hosts < 2 || num_hosts > pow(2, 31) - 1) {
        return false;
    }
    return true;
}

void calculate_cidr_notation(char *subnet_mask, unsigned int *cidr_notation) {
    *cidr_notation = 0;
    for (int i = 0; i < 4; i++) {
        int octet_value = atoi(strtok(subnet_mask, "."));
        *cidr_notation += __builtin_popcount(octet_value);
    }
}

void calculate_num_hosts(char *subnet_mask, unsigned int *num_hosts) {
    unsigned int cidr_notation;
    calculate_cidr_notation(subnet_mask, &cidr_notation);
    *num_hosts = pow(2, 32 - cidr_notation) - 2;
}

void print_subnetting_results(struct subnetting_parameters *params) {
    printf("Subnetting Results:\n");
    printf("  - IP Address: %s\n", params->ip_address);
    printf("  - Subnet Mask: %s\n", params->subnet_mask);
    printf("  - CIDR Notation: %u\n", params->cidr_notation);
    printf("  - Number of Hosts: %u\n", params->num_hosts);
}

int main(int argc, char *argv[]) {
    // Initialize parameters
    struct subnetting_parameters params = {
        .valid = true
    };

    // Parse command line arguments
    if (argc < 3) {
        printf("Usage: %s <ip_address> <subnet_mask>\n", argv[0]);
        exit(1);
    }
    strcpy(params.ip_address, argv[1]);
    strcpy(params.subnet_mask, argv[2]);

    // Validate parameters
    if (!validate_ip_address(params.ip_address)) {
        params.valid = false;
    }
    if (!validate_subnet_mask(params.subnet_mask)) {
        params.valid = false;
    }
    if (!params.valid) {
        print_invalid_parameters(&params);
        exit(1);
    }

    // Calculate CIDR notation
    calculate_cidr_notation(params.subnet_mask, &params.cidr_notation);

    // Calculate number of hosts
    calculate_num_hosts(params.subnet_mask, &params.num_hosts);

    // Print results
    print_subnetting_results(&params);

    return 0;
}