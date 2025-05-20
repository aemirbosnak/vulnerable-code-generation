//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <stdbool.h>
#include <time.h>

#define PORT 5000
#define MAX_NODES 100

typedef struct {
  char ip_address[16];
  int port;
  char hostname[256];
  time_t last_seen;
} node_t;

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in serv_addr, cli_addr;
  int addrlen = sizeof(cli_addr);
  char buffer[256];
  int n;

  // Create a UDP socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Initialize the list of nodes
  node_t nodes[MAX_NODES];
  int num_nodes = 0;

  // Main loop
  while (1) {
    // Receive a message from a client
    n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cli_addr, &addrlen);
    if (n < 0) {
      perror("recvfrom");
      continue;
    }

    // Parse the message
    char *ip_address = strtok(buffer, ":");
    char *port = strtok(NULL, ":");
    char *hostname = strtok(NULL, "\n");

    // Check if the node is already in the list
    int node_index = -1;
    for (int i = 0; i < num_nodes; i++) {
      if (strcmp(nodes[i].ip_address, ip_address) == 0 && nodes[i].port == atoi(port)) {
        node_index = i;
        break;
      }
    }

    // If the node is not in the list, add it
    if (node_index == -1) {
      strcpy(nodes[num_nodes].ip_address, ip_address);
      nodes[num_nodes].port = atoi(port);
      strcpy(nodes[num_nodes].hostname, hostname);
      nodes[num_nodes].last_seen = time(NULL);
      num_nodes++;
    } else {
      // If the node is in the list, update its last seen time
      nodes[node_index].last_seen = time(NULL);
    }

    // Print the list of nodes to the console
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
      printf("%s:%d (%s)\n", nodes[i].ip_address, nodes[i].port, nodes[i].hostname);
    }
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}