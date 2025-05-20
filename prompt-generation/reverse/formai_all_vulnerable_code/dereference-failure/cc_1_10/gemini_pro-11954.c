//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an IP address from string to binary
unsigned int ip_to_binary(char *ip) {
  unsigned int result = 0;
  char *p = strtok(ip, ".");
  while (p) {
    result <<= 8;
    result += atoi(p);
    p = strtok(NULL, ".");
  }
  return result;
}

// Function to convert a binary IP address to string
char *binary_to_ip(unsigned int ip) {
  char *result = malloc(16);
  sprintf(result, "%u.%u.%u.%u", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
  return result;
}

// Function to calculate the subnet mask
unsigned int subnet_mask(unsigned int cidr) {
  unsigned int mask = 0xFFFFFFFF;
  mask <<= 32 - cidr;
  return mask;
}

// Function to calculate the network address
unsigned int network_address(unsigned int ip, unsigned int mask) {
  return ip & mask;
}

// Function to calculate the broadcast address
unsigned int broadcast_address(unsigned int ip, unsigned int mask) {
  return ip | ~mask;
}

// Function to print the subnet information
void print_subnet_info(char *ip, unsigned int cidr, unsigned int mask, unsigned int network, unsigned int broadcast) {
  printf("IP Address: %s\n", ip);
  printf("CIDR Notation: %u\n", cidr);
  printf("Subnet Mask: %s\n", binary_to_ip(mask));
  printf("Network Address: %s\n", binary_to_ip(network));
  printf("Broadcast Address: %s\n", binary_to_ip(broadcast));
}

int main() {
  char ip[] = "192.168.1.0";
  unsigned int cidr = 24;

  // Convert the IP address to binary
  unsigned int ip_binary = ip_to_binary(ip);

  // Calculate the subnet mask
  unsigned int mask = subnet_mask(cidr);

  // Calculate the network address
  unsigned int network = network_address(ip_binary, mask);

  // Calculate the broadcast address
  unsigned int broadcast = broadcast_address(ip_binary, mask);

  // Print the subnet information
  print_subnet_info(ip, cidr, mask, network, broadcast);

  return 0;
}