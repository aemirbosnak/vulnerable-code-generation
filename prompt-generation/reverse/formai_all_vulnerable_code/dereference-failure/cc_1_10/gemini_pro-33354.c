//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// Structure for storing information about a node.
struct node {
  char *ip_address;
  char *hostname;
  int port;
  struct node *next;
};

// Structure for storing information about a link.
struct link {
  struct node *node1;
  struct node *node2;
  int weight;
  struct link *next;
};

// Structure for storing the topology map.
struct topology_map {
  struct node *nodes;
  struct link *links;
};

// Function to create a new node.
struct node *create_node(char *ip_address, char *hostname, int port) {
  struct node *node = malloc(sizeof(struct node));
  node->ip_address = strdup(ip_address);
  node->hostname = strdup(hostname);
  node->port = port;
  node->next = NULL;
  return node;
}

// Function to create a new link.
struct link *create_link(struct node *node1, struct node *node2, int weight) {
  struct link *link = malloc(sizeof(struct link));
  link->node1 = node1;
  link->node2 = node2;
  link->weight = weight;
  link->next = NULL;
  return link;
}

// Function to add a node to the topology map.
void add_node(struct topology_map *map, struct node *node) {
  node->next = map->nodes;
  map->nodes = node;
}

// Function to add a link to the topology map.
void add_link(struct topology_map *map, struct link *link) {
  link->next = map->links;
  map->links = link;
}

// Function to print the topology map.
void print_topology_map(struct topology_map *map) {
  struct node *node = map->nodes;
  while (node != NULL) {
    printf("Node: %s (%s, %d)\n", node->hostname, node->ip_address, node->port);
    node = node->next;
  }

  struct link *link = map->links;
  while (link != NULL) {
    printf("Link: %s (%s, %d) - %s (%s, %d) (weight: %d)\n",
           link->node1->hostname, link->node1->ip_address, link->node1->port,
           link->node2->hostname, link->node2->ip_address, link->node2->port, link->weight);
    link = link->next;
  }
}

// Function to free the memory allocated for the topology map.
void free_topology_map(struct topology_map *map) {
  struct node *node = map->nodes;
  while (node != NULL) {
    struct node *next = node->next;
    free(node->ip_address);
    free(node->hostname);
    free(node);
    node = next;
  }

  struct link *link = map->links;
  while (link != NULL) {
    struct link *next = link->next;
    free(link);
    link = next;
  }
}

// Function to create a new topology map.
struct topology_map *create_topology_map() {
  struct topology_map *map = malloc(sizeof(struct topology_map));
  map->nodes = NULL;
  map->links = NULL;
  return map;
}

// Function to discover the network topology.
void discover_topology(struct topology_map *map) {
  // Get the list of local IP addresses.

  struct hostent *host = gethostbyname("localhost");
  if (host == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  for (int i = 0; host->h_addr_list[i] != NULL; i++) {
    char *ip_address = inet_ntoa(*((struct in_addr *) host->h_addr_list[i]));

    // Create a new node for the local IP address.

    struct node *node = create_node(ip_address, host->h_name, 0);
    add_node(map, node);

    // Discover the links to other nodes on the network.

    for (int j = 0; j < 65535; j++) {
      struct sockaddr_in addr;
      addr.sin_family = AF_INET;
      addr.sin_addr.s_addr = inet_addr(ip_address);
      addr.sin_port = htons(j);

      int sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if (sockfd == -1) {
        perror("socket");
        exit(1);
      }

      int result = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
      if (result == 0) {
        char hostname[256];
        gethostname(hostname, 256);

        // Create a new link to the remote node.

        struct node *remote_node = create_node(ip_address, hostname, j);
        add_node(map, remote_node);

        struct link *link = create_link(node, remote_node, 1);
        add_link(map, link);

        close(sockfd);
      }
    }
  }
}

int main() {
  struct topology_map *map = create_topology_map();
  discover_topology(map);
  print_topology_map(map);
  free_topology_map(map);
  return 0;
}