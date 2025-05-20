//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char ip_address[16];
  char subnet_mask[16];
  char *ptr;
  int octet[4];
  int subnet[4];
  int cidr;
  int i;

  // User input
  printf("Enter the IP address: ");
  fgets(ip_address, 16, stdin);
  printf("Enter the subnet mask: ");
  fgets(subnet_mask, 16, stdin);

  // Parse IP address
  ptr = strtok(ip_address, ".");
  for (i = 0; i < 4; i++) {
    octet[i] = atoi(ptr);
    ptr = strtok(NULL, ".");
  }

  // Parse subnet mask
  ptr = strtok(subnet_mask, ".");
  for (i = 0; i < 4; i++) {
    subnet[i] = atoi(ptr);
    ptr = strtok(NULL, ".");
  }

  // Calculate CIDR notation
  cidr = 0;
  for (i = 0; i < 4; i++) {
    int mask_bit = 128;
    while (mask_bit > 0) {
      if ((subnet[i] & mask_bit) == mask_bit) {
        cidr++;
      } else {
        break;
      }
      mask_bit >>= 1;
    }
  }

  // Calculate network ID
  int network_id[4];
  for (i = 0; i < 4; i++) {
    network_id[i] = octet[i] & subnet[i];
  }

  // Calculate broadcast address
  int broadcast_addr[4];
  for (i = 0; i < 4; i++) {
    broadcast_addr[i] = network_id[i] | (255 - subnet[i]);
  }

  // Print results
  printf("\nCIDR notation: /%d\n", cidr);
  printf("Network ID: %d.%d.%d.%d\n", network_id[0], network_id[1], network_id[2], network_id[3]);
  printf("Broadcast address: %d.%d.%d.%d\n", broadcast_addr[0], broadcast_addr[1], broadcast_addr[2], broadcast_addr[3]);

  return 0;
}