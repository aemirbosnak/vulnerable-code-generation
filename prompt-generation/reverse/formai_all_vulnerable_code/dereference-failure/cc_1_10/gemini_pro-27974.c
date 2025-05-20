//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <ip-address>\n", argv[0]);
    return 1;
  }

  char *ip_addr = argv[1];

  // Parse IP address
  char *tokens[4];
  int octets[4];
  char *token = strtok(ip_addr, ".");
  int i = 0;
  while (token != NULL) {
    tokens[i++] = token;
    token = strtok(NULL, ".");
  }
  for (i = 0; i < 4; i++) {
    octets[i] = atoi(tokens[i]);
  }

  // Calculate subnet mask
  int subnet_mask = 0;
  for (i = 0; i < 4; i++) {
    if (octets[i] == 255) {
      subnet_mask |= (0xFF << (32 - (i * 8)));
    }
  }

  // Calculate network address
  unsigned int network_addr = octets[0] << 24 | octets[1] << 16 | octets[2] << 8 | octets[3];
  network_addr &= subnet_mask;

  // Calculate broadcast address
  unsigned int broadcast_addr = network_addr | ~subnet_mask;

  // Calculate number of hosts
  int num_hosts = (broadcast_addr - network_addr) / 2;

  // Print results
  printf("IP Address: %s\n", ip_addr);
  printf("Subnet Mask: %u.%u.%u.%u\n",
         (subnet_mask >> 24) & 0xFF, (subnet_mask >> 16) & 0xFF, (subnet_mask >> 8) & 0xFF, subnet_mask & 0xFF);
  printf("Network Address: %u.%u.%u.%u\n",
         (network_addr >> 24) & 0xFF, (network_addr >> 16) & 0xFF, (network_addr >> 8) & 0xFF, network_addr & 0xFF);
  printf("Broadcast Address: %u.%u.%u.%u\n",
         (broadcast_addr >> 24) & 0xFF, (broadcast_addr >> 16) & 0xFF, (broadcast_addr >> 8) & 0xFF, broadcast_addr & 0xFF);
  printf("Number of Hosts: %d\n", num_hosts);

  return 0;
}