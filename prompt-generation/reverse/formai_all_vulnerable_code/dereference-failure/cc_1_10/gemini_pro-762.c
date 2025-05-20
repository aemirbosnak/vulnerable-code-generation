//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

// Colors for terminal output
#define RED   "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN  "\x1B[36m"
#define RESET "\x1B[0m"

// Network topology structure
typedef struct {
  char *hostname;
  char *ip_address;
  int port;
  struct sockaddr_in sockaddr;
} NetworkNode;

// Function to create a new network node
NetworkNode *create_node(char *hostname, char *ip_address, int port) {
  NetworkNode *node = malloc(sizeof(NetworkNode));
  node->hostname = strdup(hostname);
  node->ip_address = strdup(ip_address);
  node->port = port;
  node->sockaddr.sin_family = AF_INET;
  node->sockaddr.sin_addr.s_addr = inet_addr(ip_address);
  node->sockaddr.sin_port = htons(port);
  return node;
}

// Function to free a network node
void free_node(NetworkNode *node) {
  free(node->hostname);
  free(node->ip_address);
  free(node);
}

// Function to print a network node
void print_node(NetworkNode *node) {
  printf("%s%s (%s:%d)%s\n", CYAN, node->hostname, node->ip_address, node->port, RESET);
}

// Function to map the network topology
int map_network(NetworkNode **nodes, int num_nodes) {
  int sockfd;
  int i, j;

  // Create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    return -1;
  }

  // Iterate over all nodes
  for (i = 0; i < num_nodes; i++) {
    // Connect to the node
    if (connect(sockfd, (struct sockaddr *)&nodes[i]->sockaddr, sizeof(nodes[i]->sockaddr)) == -1) {
      perror("connect");
      return -1;
    }

    // Print the node
    print_node(nodes[i]);

    // Iterate over all other nodes
    for (j = i + 1; j < num_nodes; j++) {
      // Send a message to the other node
      if (send(sockfd, nodes[j]->hostname, strlen(nodes[j]->hostname) + 1, 0) == -1) {
        perror("send");
        return -1;
      }

      // Receive a message from the other node
      char buffer[1024];
      if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return -1;
      }

      // Print the message from the other node
      printf("%s  ->  %s: %s\n", GREEN, nodes[i]->hostname, buffer);
    }

    // Close the connection to the node
    close(sockfd);
  }

  return 0;
}

// Main function
int main() {
  // Create the network nodes
  NetworkNode *nodes[] = {
    create_node("node1", "192.168.1.1", 1234),
    create_node("node2", "192.168.1.2", 2345),
    create_node("node3", "192.168.1.3", 3456),
  };

  // Map the network topology
  if (map_network(nodes, sizeof(nodes) / sizeof(NetworkNode *)) == -1) {
    return -1;
  }

  // Free the network nodes
  for (int i = 0; i < sizeof(nodes) / sizeof(NetworkNode *); i++) {
    free_node(nodes[i]);
  }

  return 0;
}