//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Global variables
const char *ip_address;
int prefix_length;
struct sockaddr_in *sock_addr;
char subnet_mask[16];
char network_address[16];
char broadcast_address[16];
char first_host_address[16];
char last_host_address[16];
int num_hosts;

// Functions
void parse_arguments(int argc, char *argv[]);
void calculate_subnet();
void print_results();

int main(int argc, char *argv[]) {
  // Parse command line arguments
  parse_arguments(argc, argv);

  // Calculate subnet information
  calculate_subnet();

  // Print results
  print_results();

  return 0;
}

void parse_arguments(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <IP address> <prefix length>\n", argv[0]);
    exit(1);
  }

  ip_address = argv[1];
  prefix_length = atoi(argv[2]);

  if (prefix_length < 0 || prefix_length > 32) {
    fprintf(stderr, "Invalid prefix length: %d\n", prefix_length);
    exit(1);
  }
}

void calculate_subnet() {
  // Convert IP address to binary
  uint32_t ip_binary = inet_addr(ip_address);

  // Create subnet mask
  uint32_t subnet_mask_binary = 0xFFFFFFFF << (32 - prefix_length);
  inet_ntop(AF_INET, &subnet_mask_binary, subnet_mask, sizeof(subnet_mask));

  // Create network address
  uint32_t network_address_binary = ip_binary & subnet_mask_binary;
  inet_ntop(AF_INET, &network_address_binary, network_address, sizeof(network_address));

  // Create broadcast address
  uint32_t broadcast_address_binary = network_address_binary | ~subnet_mask_binary;
  inet_ntop(AF_INET, &broadcast_address_binary, broadcast_address, sizeof(broadcast_address));

  // Create first host address
  uint32_t first_host_address_binary = network_address_binary + 1;
  inet_ntop(AF_INET, &first_host_address_binary, first_host_address, sizeof(first_host_address));

  // Create last host address
  uint32_t last_host_address_binary = broadcast_address_binary - 1;
  inet_ntop(AF_INET, &last_host_address_binary, last_host_address, sizeof(last_host_address));

  // Calculate number of hosts
  num_hosts = pow(2, 32 - prefix_length) - 2;
}

void print_results() {
  printf("IP address: %s\n", ip_address);
  printf("Subnet mask: %s\n", subnet_mask);
  printf("Network address: %s\n", network_address);
  printf("Broadcast address: %s\n", broadcast_address);
  printf("First host address: %s\n", first_host_address);
  printf("Last host address: %s\n", last_host_address);
  printf("Number of hosts: %d\n", num_hosts);
}