//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_ADDRESSES 100
#define MAX_QUERIES 50
#define MAX_PORTS 50

struct address_port {
  uint32_t address;
  uint16_t port;
};

struct query {
  char *hostname;
  char *port;
  struct address_port *addresses;
  int num_addresses;
  bool resolved;
};

struct topology {
  struct query *queries;
  int num_queries;
};

void error(const char *msg) {
  perror(msg);
  exit(1);
}

void resolve_hostname(struct query *query) {
  struct addrinfo hints, *res;
  int err;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_CANONNAME;

  err = getaddrinfo(query->hostname, query->port, &hints, &res);
  if (err != 0) {
    error(gai_strerror(err));
  }

  query->addresses = malloc(MAX_ADDRESSES * sizeof(struct address_port));
  query->num_addresses = 0;

  struct addrinfo *addr;
  for (addr = res; addr != NULL; addr = addr->ai_next) {
    struct sockaddr_in *sin = (struct sockaddr_in *)addr->ai_addr;
    query->addresses[query->num_addresses].address = sin->sin_addr.s_addr;
    query->addresses[query->num_addresses].port = sin->sin_port;
    query->num_addresses++;
  }

  freeaddrinfo(res);
}

void resolve_queries(struct topology *topology) {
  for (int i = 0; i < topology->num_queries; i++) {
    resolve_hostname(&topology->queries[i]);
  }
}

void print_topology(struct topology *topology) {
  for (int i = 0; i < topology->num_queries; i++) {
    printf("%s:", topology->queries[i].hostname);
    for (int j = 0; j < topology->queries[i].num_addresses; j++) {
      printf(" %s:%d",
             inet_ntoa(topology->queries[i].addresses[j].address),
             ntohs(topology->queries[i].addresses[j].port));
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    error("Usage: ./network_topology_mapper <file>");
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    error("Could not open file");
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  struct topology topology;
  topology.queries = malloc(MAX_QUERIES * sizeof(struct query));
  topology.num_queries = 0;

  while ((nread = getline(&line, &len, file)) != -1) {
    char *hostname = strtok(line, ":");
    char *port = strtok(NULL, ":");
    if (port == NULL || hostname == NULL) {
      fprintf(stderr, "Invalid line: %s", line);
      continue;
    }

    topology.queries[topology.num_queries].hostname = strdup(hostname);
    topology.queries[topology.num_queries].port = strdup(port);
    topology.queries[topology.num_queries].addresses = NULL;
    topology.queries[topology.num_queries].num_addresses = 0;
    topology.queries[topology.num_queries].resolved = false;
    topology.num_queries++;
  }

  fclose(file);

  resolve_queries(&topology);

  print_topology(&topology);

  return 0;
}