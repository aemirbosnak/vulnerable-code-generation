//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of subnets
#define MAX_SUBNETS 10

// Define the maximum number of hosts per subnet
#define MAX_HOSTS 255

// Define the structure of a subnet
typedef struct subnet {
    char name[32];              // The name of the subnet
    unsigned int address;       // The address of the subnet
    unsigned int netmask;       // The netmask of the subnet
    unsigned int broadcast;     // The broadcast address of the subnet
    unsigned int first_host;    // The first host address of the subnet
    unsigned int last_host;     // The last host address of the subnet
    unsigned int num_hosts;     // The number of hosts on the subnet
} subnet_t;

// Define the structure of a subnet calculator
typedef struct subnet_calculator {
    char ip_address[32];            // The IP address to be subnetted
    unsigned int netmask;           // The netmask to be applied
    unsigned int num_subnets;       // The number of subnets to be created
    subnet_t subnets[MAX_SUBNETS];  // The array of subnets
} subnet_calculator_t;

// Create a new subnet calculator
subnet_calculator_t* new_subnet_calculator(char* ip_address, unsigned int netmask, unsigned int num_subnets) {
    subnet_calculator_t* subnet_calculator = malloc(sizeof(subnet_calculator_t));
    strcpy(subnet_calculator->ip_address, ip_address);
    subnet_calculator->netmask = netmask;
    subnet_calculator->num_subnets = num_subnets;
    return subnet_calculator;
}

// Free a subnet calculator
void free_subnet_calculator(subnet_calculator_t* subnet_calculator) {
    free(subnet_calculator);
}

// Calculate the subnets
void calculate_subnets(subnet_calculator_t* subnet_calculator) {
    // Get the IP address
    unsigned int ip_address = inet_addr(subnet_calculator->ip_address);

    // Get the netmask
    unsigned int netmask = subnet_calculator->netmask;

    // Get the number of subnets
    unsigned int num_subnets = subnet_calculator->num_subnets;

    // Calculate the subnet mask
    unsigned int subnet_mask = htonl(0xFFFFFFFF << (32 - netmask));

    // Calculate the number of hosts per subnet
    unsigned int num_hosts = pow(2, (32 - netmask)) - 2;

    // Calculate the subnets
    for (unsigned int i = 0; i < num_subnets; i++) {
        // Get the subnet address
        unsigned int subnet_address = ip_address & subnet_mask;

        // Get the broadcast address
        unsigned int broadcast_address = subnet_address | ~subnet_mask;

        // Get the first host address
        unsigned int first_host = subnet_address + 1;

        // Get the last host address
        unsigned int last_host = broadcast_address - 1;

        // Create the subnet
        subnet_t subnet;
        sprintf(subnet.name, "Subnet %d", i + 1);
        subnet.address = subnet_address;
        subnet.netmask = netmask;
        subnet.broadcast = broadcast_address;
        subnet.first_host = first_host;
        subnet.last_host = last_host;
        subnet.num_hosts = num_hosts;

        // Add the subnet to the array of subnets
        subnet_calculator->subnets[i] = subnet;

        // Increment the IP address
        ip_address += subnet_mask;
    }
}

// Print the subnets
void print_subnets(subnet_calculator_t* subnet_calculator) {
    // Get the number of subnets
    unsigned int num_subnets = subnet_calculator->num_subnets;

    // Print the subnets
    for (unsigned int i = 0; i < num_subnets; i++) {
        // Get the subnet
        subnet_t subnet = subnet_calculator->subnets[i];

        // Print the subnet information
        printf("Subnet %d:\n", i + 1);
        printf("Name: %s\n", subnet.name);
        printf("Address: %s\n", inet_ntoa(htonl(subnet.address)));
        printf("Netmask: %s\n", inet_ntoa(htonl(subnet.netmask)));
        printf("Broadcast: %s\n", inet_ntoa(htonl(subnet.broadcast)));
        printf("First host: %s\n", inet_ntoa(htonl(subnet.first_host)));
        printf("Last host: %s\n", inet_ntoa(htonl(subnet.last_host)));
        printf("Number of hosts: %u\n\n", subnet.num_hosts);
    }
}

// Main function
int main(int argc, char** argv) {
    // Get the IP address
    char* ip_address = argv[1];

    // Get the netmask
    unsigned int netmask = atoi(argv[2]);

    // Get the number of subnets
    unsigned int num_subnets = atoi(argv[3]);

    // Create a subnet calculator
    subnet_calculator_t* subnet_calculator = new_subnet_calculator(ip_address, netmask, num_subnets);

    // Calculate the subnets
    calculate_subnets(subnet_calculator);

    // Print the subnets
    print_subnets(subnet_calculator);

    // Free the subnet calculator
    free_subnet_calculator(subnet_calculator);

    return 0;
}