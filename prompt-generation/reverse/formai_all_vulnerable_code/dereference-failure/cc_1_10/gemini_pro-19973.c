//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the two lovers
typedef struct {
  char *name;
  int age;
  int height;
} lover;

// Define the function to calculate the subnet mask
int calculate_subnet_mask(int prefix_length) {
  int subnet_mask = 0;
  for (int i = 0; i < prefix_length; i++) {
    subnet_mask |= (1 << (31 - i));
  }
  return subnet_mask;
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user has provided the correct number of arguments
  if (argc != 3) {
    printf("Usage: %s <prefix length> <number of hosts>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse the arguments
  int prefix_length = atoi(argv[1]);
  int num_hosts = atoi(argv[2]);

  // Calculate the subnet mask
  int subnet_mask = calculate_subnet_mask(prefix_length);

  // Calculate the network address
  int network_address = 0;
  for (int i = 0; i < 32; i++) {
    if (subnet_mask & (1 << (31 - i))) {
      network_address |= (1 << (31 - i));
    }
  }

  // Calculate the broadcast address
  int broadcast_address = network_address | ~subnet_mask;

  // Calculate the first and last host addresses
  int first_host_address = network_address + 1;
  int last_host_address = broadcast_address - 1;

  // Print the results
  printf("Subnet mask: %d.%d.%d.%d\n", (subnet_mask >> 24) & 0xFF, (subnet_mask >> 16) & 0xFF, (subnet_mask >> 8) & 0xFF, subnet_mask & 0xFF);
  printf("Network address: %d.%d.%d.%d\n", (network_address >> 24) & 0xFF, (network_address >> 16) & 0xFF, (network_address >> 8) & 0xFF, network_address & 0xFF);
  printf("Broadcast address: %d.%d.%d.%d\n", (broadcast_address >> 24) & 0xFF, (broadcast_address >> 16) & 0xFF, (broadcast_address >> 8) & 0xFF, broadcast_address & 0xFF);
  printf("First host address: %d.%d.%d.%d\n", (first_host_address >> 24) & 0xFF, (first_host_address >> 16) & 0xFF, (first_host_address >> 8) & 0xFF, first_host_address & 0xFF);
  printf("Last host address: %d.%d.%d.%d\n", (last_host_address >> 24) & 0xFF, (last_host_address >> 16) & 0xFF, (last_host_address >> 8) & 0xFF, last_host_address & 0xFF);

  // Return success
  return EXIT_SUCCESS;
}