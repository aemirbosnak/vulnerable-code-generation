//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX_HOPS 30
#define TIMEOUT_SECS 1
#define MAX_ADDR_LEN 100

typedef struct {
  char *addr;
  int hops;
} node_t;

node_t *nodes[MAX_HOPS];
int num_nodes = 0;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <target> <port>\n", argv[0]);
    return 1;
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  // Set a timeout on the socket
  struct timeval timeout;
  timeout.tv_sec = TIMEOUT_SECS;
  timeout.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,
                 sizeof(timeout)) < 0) {
    perror("setsockopt");
    return 1;
  }

  // Get the target's IP address
  struct hostent *he = gethostbyname(argv[1]);
  if (he == NULL) {
    perror("gethostbyname");
    return 1;
  }

  // Create the target address
  struct sockaddr_in target_addr;
  memset(&target_addr, 0, sizeof(target_addr));
  target_addr.sin_family = AF_INET;
  target_addr.sin_port = htons(atoi(argv[2]));
  memcpy(&target_addr.sin_addr, he->h_addr, he->h_length);

  // Create a buffer to receive data
  char buf[1024];
  memset(buf, 0, sizeof(buf));

  // Send a ping message to the target
  int bytes_sent = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&target_addr,
                         sizeof(target_addr));
  if (bytes_sent < 0) {
    perror("sendto");
    return 1;
  }

  // Receive a response from the target
  struct sockaddr_in from_addr;
  socklen_t from_addr_len = sizeof(from_addr);
  int bytes_recv = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&from_addr,
                           &from_addr_len);
  if (bytes_recv < 0) {
    perror("recvfrom");
    return 1;
  }

  // Add the target to the list of nodes
  nodes[num_nodes] = malloc(sizeof(node_t));
  nodes[num_nodes]->addr = strdup(inet_ntoa(from_addr.sin_addr));
  nodes[num_nodes]->hops = 1;
  num_nodes++;

  // Process the response
  char *ptr = buf;
  while (ptr < buf + bytes_recv) {
    // Get the next hop
    char *next_hop = strchr(ptr, ' ');
    if (next_hop == NULL) {
      break;
    }

    *next_hop++ = '\0';

    // Get the hops to the next hop
    int hops = atoi(next_hop);

    // Add the next hop to the list of nodes
    nodes[num_nodes] = malloc(sizeof(node_t));
    nodes[num_nodes]->addr = strdup(ptr);
    nodes[num_nodes]->hops = hops + 1;
    num_nodes++;

    // Advance the pointer
    ptr = next_hop;
  }

  // Print the list of nodes
  for (int i = 0; i < num_nodes; i++) {
    printf("%s (%d hops)\n", nodes[i]->addr, nodes[i]->hops);
    free(nodes[i]->addr);
    free(nodes[i]);
  }

  // Close the socket
  close(sockfd);

  return 0;
}