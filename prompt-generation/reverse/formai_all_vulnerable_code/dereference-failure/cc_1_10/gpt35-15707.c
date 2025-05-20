//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define SUBNET_SIZE 32

int main(int argc, char *argv[]) {
  
  // Check if the user has provided an IP address and subnet mask
  if (argc < 3) {
    printf("Please provide IP address and subnet mask in the format: x.x.x.x y.y.y.y\n");
    return -1;
  }

  // Parse the IP address and subnet mask
  struct in_addr ip_addr;
  if (inet_pton(AF_INET, argv[1], &ip_addr) != 1) {
    printf("Invalid IP address\n");
    return -1;
  }
  
  uint32_t subnet_mask;
  if (inet_pton(AF_INET, argv[2], &subnet_mask) != 1) {
    printf("Invalid subnet mask\n");
    return -1;
  }

  // Calculate the network address and broadcast address
  uint32_t subnet_addr = ntohl(ip_addr.s_addr & subnet_mask);
  uint32_t broadcast_addr = subnet_addr | ~(subnet_mask);

  // Calculate the number of hosts
  uint32_t num_hosts = ~(subnet_mask) - 1;

  // Calculate the range of IP addresses
  uint32_t range_begin = subnet_addr + 1;
  uint32_t range_end = broadcast_addr - 1;

  // Output the results
  printf("IP address: %s\n", inet_ntoa(ip_addr));
  printf("Subnet mask: %s\n", inet_ntoa(*(struct in_addr*)&subnet_mask));
  printf("Network address: %s\n", inet_ntoa(*(struct in_addr*)&subnet_addr));
  printf("Broadcast address: %s\n", inet_ntoa(*(struct in_addr*)&broadcast_addr));
  printf("Number of hosts: %d\n", num_hosts);
  printf("Range of IP addresses: %s - %s\n", inet_ntoa(*(struct in_addr*)&range_begin), inet_ntoa(*(struct in_addr*)&range_end));

  return 0;
}