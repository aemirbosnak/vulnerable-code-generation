//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal_number, char* binary_number) {
    int current_number = decimal_number;
    int index = 0;

    // Convert decimal to binary
    while(current_number > 0) {
        int remainder = current_number % 2;
        char remainder_char = remainder + '0';
        binary_number[index] = remainder_char;
        current_number /= 2;
        index++;
    }

    // Reverse the binary string
    int i;
    for(i = 0; i < index / 2; i++) {
        char temp = binary_number[i];
        binary_number[i] = binary_number[index - i - 1];
        binary_number[index - i - 1] = temp;
    }
}

int main() {
    char ip_address[16];
    printf("Enter IP Address: ");
    scanf("%s", ip_address);

    // Get the subnet mask
    int subnet_mask;
    printf("Enter Subnet Mask (in CIDR notation): ");
    scanf("%d", &subnet_mask);

    // Split IP address into octets
    char* octet;
    octet = strtok(ip_address, ".");
    int octets[4];
    int i = 0;
    while(octet != NULL) {
        octets[i] = atoi(octet);
        i++;
        octet = strtok(NULL, ".");
    }

    // Get the IP address in binary
    char binary_ip[33];
    char* binary_octet;
    int j;
    for(j = 0; j < 4; j++) {
        binary_octet = (char*)malloc(sizeof(char) * 8);
        decimalToBinary(octets[j], binary_octet);
        strcat(binary_ip, binary_octet);
        free(binary_octet);
    }

    // Calculate the number of subnets and hosts
    int num_subnets = pow(2, (32 - subnet_mask));
    int num_hosts = pow(2, (32 - subnet_mask)) - 2;

    // Get the network ID and broadcast address
    char network_id[33];
    char broadcast_address[33];
    char* subnet_binary;
    int k;
    for(k = 0; k < 4; k++) {
        subnet_binary = (char*)malloc(sizeof(char) * 8);
        memset(subnet_binary, '0', 8);
        int l;
        for(l = 0; l < 8; l++) {
            int binary_index = k * 8 + l;
            if(binary_index < subnet_mask) {
                subnet_binary[l] = binary_ip[binary_index];
            } else {
                break;
            }
        }
        strcat(network_id, subnet_binary);
        free(subnet_binary);
    }
    strcpy(broadcast_address, network_id);
    for(k = subnet_mask; k < 32; k++) {
        broadcast_address[k] = '1';
    }

    // Print subnet information
    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %d\n", subnet_mask);
    printf("Number of Subnets: %d\n", num_subnets);
    printf("Number of Hosts per Subnet: %d\n", num_hosts);
    printf("Network ID: %s\n", network_id);
    printf("Broadcast Address: %s\n", broadcast_address);

    return 0;
}