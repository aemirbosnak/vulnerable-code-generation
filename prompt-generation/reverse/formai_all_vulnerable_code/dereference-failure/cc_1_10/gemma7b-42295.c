//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_HOSTS 100

typedef struct Host {
  char name[256];
  struct Host* next;
  int num_connections;
  struct Connection** connections;
} Host;

typedef struct Connection {
  Host* host1;
  Host* host2;
  int port;
  struct Connection* next;
} Connection;

Host* create_host(char* name) {
  Host* host = malloc(sizeof(Host));
  strcpy(host->name, name);
  host->next = NULL;
  host->num_connections = 0;
  host->connections = NULL;
  return host;
}

Connection* create_connection(Host* host1, Host* host2, int port) {
  Connection* connection = malloc(sizeof(Connection));
  connection->host1 = host1;
  connection->host2 = host2;
  connection->port = port;
  connection->next = NULL;
  return connection;
}

void map_topology(Host* host) {
  printf("Host: %s\n", host->name);
  printf("  Connections:\n");
  for (Connection* connection = host->connections; connection; connection++) {
    printf("    %s (%d)\n", connection->host2->name, connection->port);
  }
  printf("\n");
}

int main() {
  Host* head = create_host("A");
  Host* second = create_host("B");
  Host* third = create_host("C");

  Connection* connection1 = create_connection(head, second, 50);
  Connection* connection2 = create_connection(second, third, 60);

  head->connections = connection1;
  second->connections = connection1;
  second->connections = connection2;

  map_topology(head);

  return 0;
}