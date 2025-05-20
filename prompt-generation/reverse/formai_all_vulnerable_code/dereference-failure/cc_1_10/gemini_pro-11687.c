//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HOPS 10
#define MAX_BUF_SIZE 1024

// A struct to represent a node in the network topology
typedef struct node {
  char *ip_address;
  int num_hops;
} node_t;

// A function to get the IP address of the host
char *get_ip_address(char *hostname) {
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    return NULL;
  }
  return inet_ntoa(*((struct in_addr *)host->h_addr));
}

// A function to create a socket
int create_socket() {
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }
  return sockfd;
}

// A function to send a packet to a host
void send_packet(int sockfd, char *ip_address, int port, char *payload) {
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(ip_address);
  if (sendto(sockfd, payload, strlen(payload), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("sendto");
    exit(1);
  }
}

// A function to receive a packet from a host
char *receive_packet(int sockfd) {
  char buf[MAX_BUF_SIZE];
  struct sockaddr_in addr;
  socklen_t addr_len = sizeof(addr);
  if (recvfrom(sockfd, buf, MAX_BUF_SIZE, 0, (struct sockaddr *)&addr, &addr_len) < 0) {
    perror("recvfrom");
    exit(1);
  }
  return strdup(buf);
}

// A function to map the network topology
void map_topology(char *source_ip_address, int source_port) {
  int sockfd = create_socket();
  node_t *nodes = malloc(sizeof(node_t) * MAX_HOPS);
  nodes[0].ip_address = strdup(source_ip_address);
  nodes[0].num_hops = 0;
  int num_nodes = 1;
  while (num_nodes < MAX_HOPS) {
    for (int i = 0; i < num_nodes; i++) {
      // Send a packet to each neighbor
      send_packet(sockfd, nodes[i].ip_address, source_port, "ping");
      // Receive a response from each neighbor
      char *response = receive_packet(sockfd);
      // If the response is "pong", then the neighbor is alive
      if (strcmp(response, "pong") == 0) {
        // Add the neighbor to the list of nodes
        nodes[num_nodes].ip_address = strdup(response);
        nodes[num_nodes].num_hops = nodes[i].num_hops + 1;
        num_nodes++;
      }
    }
  }
  // Print the list of nodes
  for (int i = 0; i < num_nodes; i++) {
    printf("%s: %d\n", nodes[i].ip_address, nodes[i].num_hops);
  }
  // Free the memory
  for (int i = 0; i < num_nodes; i++) {
    free(nodes[i].ip_address);
  }
  free(nodes);
  close(sockfd);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <source_ip_address> <source_port>\n", argv[0]);
    exit(1);
  }
  map_topology(argv[1], atoi(argv[2]));
  return 0;
}