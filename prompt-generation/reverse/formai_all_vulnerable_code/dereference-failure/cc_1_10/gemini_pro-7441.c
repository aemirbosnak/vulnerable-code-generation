//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OCTETS 4
#define MAX_BITS 32

// Declare the main function
int main(int argc, char *argv[]) {
  // Declare variables
  unsigned int ip_address[MAX_OCTETS];
  unsigned int subnet_mask[MAX_OCTETS];
  unsigned int network_address[MAX_OCTETS];
  unsigned int broadcast_address[MAX_OCTETS];
  unsigned int num_hosts;
  unsigned int num_subnets;
  unsigned int cidr_prefix;

  if (argc != 2) {
    printf("Usage: %s <CIDR prefix>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Extract the CIDR prefix from the command line argument
  cidr_prefix = atoi(argv[1]);

  // Check if the CIDR prefix is valid
  if (cidr_prefix < 0 || cidr_prefix > MAX_BITS) {
    printf("Error: Invalid CIDR prefix\n");
    return EXIT_FAILURE;
  }

  // Convert the CIDR prefix to a subnet mask
  for (int i = 0; i < MAX_OCTETS; i++) {
    if (cidr_prefix >= 8) {
      subnet_mask[i] = 255;
      cidr_prefix -= 8;
    } else {
      subnet_mask[i] = 255 << (8 - cidr_prefix);
      cidr_prefix = 0;
    }
  }

  // Prompt the user for the IP address
  printf("Enter the IP address: ");
  for (int i = 0; i < MAX_OCTETS; i++) {
    scanf("%u", &ip_address[i]);
  }

  // Calculate the network address
  for (int i = 0; i < MAX_OCTETS; i++) {
    network_address[i] = ip_address[i] & subnet_mask[i];
  }

  // Calculate the broadcast address
  for (int i = 0; i < MAX_OCTETS; i++) {
    broadcast_address[i] = network_address[i] | ~subnet_mask[i];
  }

  // Calculate the number of hosts
  num_hosts = (1 << (MAX_BITS - cidr_prefix)) - 2;

  // Calculate the number of subnets
  num_subnets = 1 << cidr_prefix;

  // Print the results
  printf("\nSubnet Calculator Results:\n");
  printf("IP Address: %u.%u.%u.%u\n", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);
  printf("Subnet Mask: %u.%u.%u.%u\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
  printf("Network Address: %u.%u.%u.%u\n", network_address[0], network_address[1], network_address[2], network_address[3]);
  printf("Broadcast Address: %u.%u.%u.%u\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
  printf("Number of Hosts: %u\n", num_hosts);
  printf("Number of Subnets: %u\n", num_subnets);

  return EXIT_SUCCESS;
}