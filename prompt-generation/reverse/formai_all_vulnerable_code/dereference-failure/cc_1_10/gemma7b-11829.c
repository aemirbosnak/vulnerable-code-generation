//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct subnet_calculator {
  char subnet_mask[MAX_BUFFER_SIZE];
  int subnet_mask_len;
  char ip_address[MAX_BUFFER_SIZE];
  int ip_address_len;
  int broadcast_address[MAX_BUFFER_SIZE];
  int num_hosts;
} subnet_calculator;

subnet_calculator* calculate_subnet(char* subnet_mask, int subnet_mask_len, char* ip_address, int ip_address_len) {
  subnet_calculator* sc = malloc(sizeof(subnet_calculator));

  sc->subnet_mask_len = subnet_mask_len;
  strncpy(sc->subnet_mask, subnet_mask, subnet_mask_len);

  sc->ip_address_len = ip_address_len;
  strncpy(sc->ip_address, ip_address, ip_address_len);

  sc->broadcast_address[0] = (sc->ip_address[0] & ~sc->subnet_mask[0]) | sc->subnet_mask[0];
  sc->broadcast_address[1] = (sc->ip_address[1] & ~sc->subnet_mask[1]) | sc->subnet_mask[1];
  sc->broadcast_address[2] = (sc->ip_address[2] & ~sc->subnet_mask[2]) | sc->subnet_mask[2];
  sc->broadcast_address[3] = (sc->ip_address[3] & ~sc->subnet_mask[3]) | sc->subnet_mask[3];

  sc->num_hosts = (int)((~sc->subnet_mask[0]) & 0x3F) * (int)((~sc->subnet_mask[1]) & 0x3F) * (int)((~sc->subnet_mask[2]) & 0x3F) - 2;

  return sc;
}

int main() {
  char subnet_mask[] = "255.255.255.0";
  int subnet_mask_len = strlen(subnet_mask);

  char ip_address[] = "192.168.1.1";
  int ip_address_len = strlen(ip_address);

  subnet_calculator* sc = calculate_subnet(subnet_mask, subnet_mask_len, ip_address, ip_address_len);

  printf("Subnet Mask: %s\n", sc->subnet_mask);
  printf("Subnet Mask Length: %d\n", sc->subnet_mask_len);
  printf("IP Address: %s\n", sc->ip_address);
  printf("IP Address Length: %d\n", sc->ip_address_len);
  printf("Broadcast Address: %d.%d.%d.%d\n", sc->broadcast_address[0], sc->broadcast_address[1], sc->broadcast_address[2], sc->broadcast_address[3]);
  printf("Number of Hosts: %d\n", sc->num_hosts);

  free(sc);

  return 0;
}