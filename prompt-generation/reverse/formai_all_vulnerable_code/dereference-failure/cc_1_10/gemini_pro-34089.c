//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an IP address from dotted decimal notation to binary
void ip_to_binary(char *ip, char *binary) {
    int i, j, k;
    char octet[4];

    // Split the IP address into octets
    for (i = 0, j = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            octet[j] = '\0';
            binary[k++] = strtol(octet, NULL, 10);
            j = 0;
        } else {
            octet[j++] = ip[i];
        }
    }

    // Convert the last octet to binary
    octet[j] = '\0';
    binary[k] = strtol(octet, NULL, 10);
}

// Function to convert a binary IP address to dotted decimal notation
void binary_to_ip(char *binary, char *ip) {
    int i, j, k;
    char octet[4];

    // Convert each octet to decimal
    for (i = 0, j = 0, k = 0; i < 32; i += 8) {
        octet[j++] = binary[i] + binary[i + 1] * 2 + binary[i + 2] * 4 + binary[i + 3] * 8 + binary[i + 4] * 16 + binary[i + 5] * 32 + binary[i + 6] * 64 + binary[i + 7] * 128;
        if (j == 4) {
            sprintf(ip + k, "%d.", octet[0]);
            k += strlen(ip + k);
            j = 0;
        }
    }

    // Remove the trailing period
    ip[strlen(ip) - 1] = '\0';
}

// Function to calculate the subnet mask
void calculate_subnet_mask(char *ip, char *mask, int prefix_length) {
    int i, j;

    // Convert the IP address to binary
    char binary[32];
    ip_to_binary(ip, binary);

    // Set the first prefix_length bits of the subnet mask to 1
    for (i = 0; i < prefix_length; i++) {
        mask[i] = 1;
    }

    // Set the remaining bits of the subnet mask to 0
    for (j = prefix_length; j < 32; j++) {
        mask[j] = 0;
    }

    // Convert the subnet mask to dotted decimal notation
    binary_to_ip(mask, mask);
}

// Function to calculate the network address
void calculate_network_address(char *ip, char *mask, char *network) {
    int i;

    // Convert the IP address and subnet mask to binary
    char binary_ip[32];
    char binary_mask[32];
    ip_to_binary(ip, binary_ip);
    ip_to_binary(mask, binary_mask);

    // Perform bitwise AND operation between the IP address and subnet mask
    for (i = 0; i < 32; i++) {
        network[i] = binary_ip[i] & binary_mask[i];
    }

    // Convert the network address to dotted decimal notation
    binary_to_ip(network, network);
}

// Function to calculate the broadcast address
void calculate_broadcast_address(char *ip, char *mask, char *broadcast) {
    int i;

    // Convert the IP address and subnet mask to binary
    char binary_ip[32];
    char binary_mask[32];
    ip_to_binary(ip, binary_ip);
    ip_to_binary(mask, binary_mask);

    // Perform bitwise OR operation between the IP address and the inverse of the subnet mask
    for (i = 0; i < 32; i++) {
        broadcast[i] = binary_ip[i] | (~binary_mask[i]);
    }

    // Convert the broadcast address to dotted decimal notation
    binary_to_ip(broadcast, broadcast);
}

// Function to print the subnet information
void print_subnet_information(char *ip, char *mask, char *network, char *broadcast) {
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", mask);
    printf("Network Address: %s\n", network);
    printf("Broadcast Address: %s\n", broadcast);
}

int main() {
    // Get the IP address, prefix length, and subnet mask from the user
    char ip[16];
    int prefix_length;
    char mask[16];

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the prefix length: ");
    scanf("%d", &prefix_length);

    // Calculate the subnet mask
    calculate_subnet_mask(ip, mask, prefix_length);

    // Calculate the network address
    char network[16];
    calculate_network_address(ip, mask, network);

    // Calculate the broadcast address
    char broadcast[16];
    calculate_broadcast_address(ip, mask, broadcast);

    // Print the subnet information
    print_subnet_information(ip, mask, network, broadcast);

    return 0;
}