//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Cyberpunk
// The rain-soaked neon city awaits your digital footprint.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

// Every journey starts with a destination.
struct node {
  char *host;
  int port;
  struct node *next;
};

// Your trusted guide through the cyberweb.
struct graph {
  struct node *head;
  struct node *tail;
};

// Scanning the horizon for potential connections.
int scan_host(char *host) {
  struct hostent *he;
  if ((he = gethostbyname(host)) == NULL) {
    perror("gethostbyname");
    return -1;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  memcpy(&addr.sin_addr, he->h_addr, he->h_length);

  int sockfd;
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return -1;
  }

  // Knocking on the door of opportunity.
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    close(sockfd);
    return -1;
  }

  // A new connection forged in the digital realm.
  printf("Connected to %s on port %d\n", host, ntohs(addr.sin_port));

  close(sockfd);
  return 0;
}

// Mapping out the cyberweb, one node at a time.
struct node *add_node(struct graph *graph, char *host, int port) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->host = strdup(host);
  new_node->port = port;
  new_node->next = NULL;

  if (graph->head == NULL) {
    graph->head = new_node;
    graph->tail = new_node;
  } else {
    graph->tail->next = new_node;
    graph->tail = new_node;
  }

  return new_node;
}

// Exploring the uncharted territories of cyberspace.
void traverse_graph(struct graph *graph) {
  struct node *current = graph->head;
  while (current != NULL) {
    scan_host(current->host);
    current = current->next;
  }
}

// The entry point into the digital wilderness.
int main(int argc, char **argv) {
  // Initializing your cybernetic guide.
  struct graph graph;
  memset(&graph, 0, sizeof(graph));

  // Establish connections to the initial nodes.
  add_node(&graph, "thematrix.com", 80);
  add_node(&graph, "cyberspace.net", 23);

  // Venture forth into the labyrinth of cyberspace.
  traverse_graph(&graph);

  // Leave no digital footprint behind.
  struct node *current = graph.head;
  while (current != NULL) {
    free(current->host);
    struct node *next = current->next;
    free(current);
    current = next;
  }

  return 0;
}