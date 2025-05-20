//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int address[4];
    int subnet_mask;
} IPInfo;

IPInfo parse_input(char* input) {
    IPInfo info;
    char* token;
    int i = 0;

    // Parse IP address
    token = strtok(input, ".");
    while (token != NULL && i < 4) {
        info.address[i] = atoi(token);
        token = strtok(NULL, ".");
        i++;
    }

    // Parse subnet mask
    if (token != NULL) {
        info.subnet_mask = atoi(token);
    }

    return info;
}

void print_address(int* address) {
    printf("%d.%d.%d.%d", address[0], address[1], address[2], address[3]);
}

void print_subnet(IPInfo info) {
    int subnet_mask = info.subnet_mask;
    int i, j, k;
    int mask[32];
    int address_binary[32];
    int subnet_binary[32];
    int octets[4];

    // Convert subnet mask to binary
    for (i = 0; i < 32; i++) {
        mask[i] = i < subnet_mask ? 1 : 0;
    }

    // Convert IP address to binary
    for (i = 0, j = 0; i < 4; i++) {
        for (k = 7; k >= 0; k--) {
            address_binary[j] = (info.address[i] >> k) & 1;
            j++;
        }
    }

    // Apply subnet mask to IP address
    for (i = 0; i < 32; i++) {
        subnet_binary[i] = address_binary[i] & mask[i];
    }

    // Convert binary to octets
    for (i = 0, j = 0; i < 32; i += 8, j++) {
        octets[j] = subnet_binary[i] * 128 + subnet_binary[i+1] * 64 + subnet_binary[i+2] * 32 + subnet_binary[i+3] * 16 + subnet_binary[i+4] * 8 + subnet_binary[i+5] * 4 + subnet_binary[i+6] * 2 + subnet_binary[i+7];
    }

    // Print subnet in dotted decimal notation
    print_address(octets);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./subnet_calculator <ip_address>/<subnet_mask>\n");
        return 1;
    }

    char* input = argv[1];
    IPInfo info = parse_input(input);

    printf("IP Address: ");
    print_address(info.address);

    printf("\nSubnet Mask: %d\n", info.subnet_mask);
    
    printf("Subnet Address: ");
    print_subnet(info);

    printf("\n");

    return 0;
}