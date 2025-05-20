//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subnets
#define MAX_SUBNETS 100

// Define the structure of a subnet
typedef struct {
  char *name;
  unsigned int address;
  unsigned int netmask;
  unsigned int gateway;
  unsigned int broadcast;
  unsigned int num_hosts;
} subnet_t;

// Define the function to create a new subnet
subnet_t *create_subnet(char *name, unsigned int address, unsigned int netmask, unsigned int gateway, unsigned int broadcast, unsigned int num_hosts) {
  // Allocate memory for the new subnet
  subnet_t *subnet = malloc(sizeof(subnet_t));

  // Copy the subnet's information into the new subnet
  subnet->name = strdup(name);
  subnet->address = address;
  subnet->netmask = netmask;
  subnet->gateway = gateway;
  subnet->broadcast = broadcast;
  subnet->num_hosts = num_hosts;

  // Return the new subnet
  return subnet;
}

// Define the function to destroy a subnet
void destroy_subnet(subnet_t *subnet) {
  // Free the memory allocated for the subnet's name
  free(subnet->name);

  // Free the memory allocated for the subnet
  free(subnet);
}

// Define the function to print the information about a subnet
void print_subnet(subnet_t *subnet) {
  // Print the subnet's information
  printf("Subnet name: %s\n", subnet->name);
  printf("Subnet address: %u\n", subnet->address);
  printf("Subnet netmask: %u\n", subnet->netmask);
  printf("Subnet gateway: %u\n", subnet->gateway);
  printf("Subnet broadcast: %u\n", subnet->broadcast);
  printf("Subnet number of hosts: %u\n", subnet->num_hosts);
}

// Define the function to calculate the subnets for a given network
int calculate_subnets(unsigned int network_address, unsigned int network_netmask, unsigned int num_subnets) {
  // Check if the number of subnets is valid
  if (num_subnets > MAX_SUBNETS) {
    return -1;
  }

  // Calculate the subnet bitmask
  unsigned int subnet_bitmask = ~network_netmask;

  // Calculate the number of hosts per subnet
  unsigned int num_hosts_per_subnet = (1 << (32 - __builtin_clz(subnet_bitmask))) - 2;

  // Calculate the subnet addresses
  unsigned int subnet_addresses[MAX_SUBNETS];
  for (int i = 0; i < num_subnets; i++) {
    subnet_addresses[i] = network_address + (i * num_hosts_per_subnet);
  }

  // Calculate the subnet netmasks
  unsigned int subnet_netmasks[MAX_SUBNETS];
  for (int i = 0; i < num_subnets; i++) {
    subnet_netmasks[i] = network_netmask | subnet_bitmask;
  }

  // Calculate the subnet gateways
  unsigned int subnet_gateways[MAX_SUBNETS];
  for (int i = 0; i < num_subnets; i++) {
    subnet_gateways[i] = subnet_addresses[i] + 1;
  }

  // Calculate the subnet broadcasts
  unsigned int subnet_broadcasts[MAX_SUBNETS];
  for (int i = 0; i < num_subnets; i++) {
    subnet_broadcasts[i] = subnet_addresses[i] + num_hosts_per_subnet;
  }

  // Create the subnets
  subnet_t *subnets[MAX_SUBNETS];
  for (int i = 0; i < num_subnets; i++) {
    char subnet_name[32];
    snprintf(subnet_name, sizeof(subnet_name), "Subnet %d", i + 1);
    subnets[i] = create_subnet(subnet_name, subnet_addresses[i], subnet_netmasks[i], subnet_gateways[i], subnet_broadcasts[i], num_hosts_per_subnet);
  }

  // Print the subnets
  for (int i = 0; i < num_subnets; i++) {
    print_subnet(subnets[i]);
  }

  // Destroy the subnets
  for (int i = 0; i < num_subnets; i++) {
    destroy_subnet(subnets[i]);
  }

  return 0;
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the number of arguments is valid
  if (argc != 4) {
    printf("Usage: %s <network address> <network netmask> <number of subnets>\n", argv[0]);
    return -1;
  }

  // Parse the arguments
  unsigned int network_address = inet_addr(argv[1]);
  unsigned int network_netmask = inet_addr(argv[2]);
  unsigned int num_subnets = atoi(argv[3]);

  // Calculate the subnets
  int result = calculate_subnets(network_address, network_netmask, num_subnets);

  // Check if the subnets were calculated successfully
  if (result != 0) {
    printf("Error calculating subnets\n");
    return -1;
  }

  return 0;
}