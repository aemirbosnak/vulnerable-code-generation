//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 256

typedef struct subnet_calculator {
  char subnet_address[MAX_BUFFER_SIZE];
  int subnet_mask_bits;
  int broadcast_address[MAX_BUFFER_SIZE];
  int host_address_range[MAX_BUFFER_SIZE];
} subnet_calculator;

subnet_calculator *calculate_subnet(char *subnet_address, int subnet_mask_bits) {
  subnet_calculator *sc = malloc(sizeof(subnet_calculator));

  // Copy subnet address
  strncpy(sc->subnet_address, subnet_address, MAX_BUFFER_SIZE);

  // Subnet mask bits
  sc->subnet_mask_bits = subnet_mask_bits;

  // Calculate broadcast address
  int num_hosts = pow(2, 32 - subnet_mask_bits) - 1;
  sc->broadcast_address[0] = sc->subnet_address[0] | (num_hosts & 0xFF);
  sc->broadcast_address[1] = sc->subnet_address[1] | (num_hosts & 0xFF00) >> 8;
  sc->broadcast_address[2] = sc->subnet_address[2] | (num_hosts & 0xFF0000) >> 16;
  sc->broadcast_address[3] = sc->subnet_address[3] | (num_hosts & 0xFF000000) >> 24;

  // Calculate host address range
  sc->host_address_range[0] = sc->subnet_address[0] & ~((sc->subnet_mask_bits - 1) & 0xFF);
  sc->host_address_range[1] = sc->subnet_address[1] & ~((sc->subnet_mask_bits - 1) & 0xFF00) >> 8;
  sc->host_address_range[2] = sc->subnet_address[2] & ~((sc->subnet_mask_bits - 1) & 0xFF0000) >> 16;
  sc->host_address_range[3] = sc->subnet_address[3] & ~((sc->subnet_mask_bits - 1) & 0xFF000000) >> 24;

  return sc;
}

int main() {
  char subnet_address[] = "192.168.1.0";
  int subnet_mask_bits = 24;

  subnet_calculator *sc = calculate_subnet(subnet_address, subnet_mask_bits);

  // Print results
  printf("Subnet Address: %s\n", sc->subnet_address);
  printf("Subnet Mask Bits: %d\n", sc->subnet_mask_bits);
  printf("Broadcast Address: %s\n", sc->broadcast_address);
  printf("Host Address Range: %s - %s\n", sc->host_address_range);

  free(sc);

  return 0;
}