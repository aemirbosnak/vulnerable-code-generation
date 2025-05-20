//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Function to convert IPv4 address to binary string
char* ip_to_binary(unsigned int ip) {
    static char bin[32];
    int i, j;
    for (i = 0; i < 4; i++) {
        unsigned int octet = ip & 0xFF;
        ip >>= 8;

        memset(bin + i * 8, '0', 8);
        for (j = 0; j < 8; j++) {
            if (octet & 1 << (7 - j))
                bin[i * 8 + j] = '1';
        }
    }
    bin[32] = '\0';
    return bin;
}

// Function to perform subnet calculation
void subnet_calculation(unsigned int ip, unsigned int subnet_mask) {
    unsigned int network_address, broadcast_address, subnet_size;

    // Calculate network address and broadcast address
    network_address = ip & subnet_mask;
    broadcast_address = network_address | ~(subnet_mask & 0xFFFFFF00);

    // Calculate subnet size
    subnet_size = 4 * 8 - (32 - (int)log2(subnet_mask & 0xFFFFFF00) + 2);

    // Print results
    printf("Input IP address : %s\n", inet_ntoa(*(struct in_addr*)&ip));
    printf("Subnet mask : %s\n", inet_ntoa(*(struct in_addr*)&subnet_mask));
    printf("Network address : %s\n", inet_ntoa(*(struct in_addr*)&network_address));
    printf("Broadcast address : %s\n", inet_ntoa(*(struct in_addr*)&broadcast_address));
    printf("Subnet size : %d bits = %d addresses\n", subnet_size, 1 << subnet_size);

    // Convert network address and broadcast address to binary strings
    char* network_binary = ip_to_binary(network_address);
    char* broadcast_binary = ip_to_binary(broadcast_address);

    // Print binary representations
    printf("Network address in binary : %s\n", network_binary);
    printf("Broadcast address in binary : %s\n", broadcast_binary);

    free(network_binary);
    free(broadcast_binary);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage : %s <IP address> <Subnet mask>\n", argv[0]);
        exit(1);
    }

    unsigned int ip, subnet_mask;

    // Convert IP address and subnet mask to unsigned integers
    ip = inet_addr(argv[1]);
    subnet_mask = inet_addr(argv[2]);

    // Perform subnet calculation
    subnet_calculation(ip, subnet_mask);

    return 0;
}

// End of file