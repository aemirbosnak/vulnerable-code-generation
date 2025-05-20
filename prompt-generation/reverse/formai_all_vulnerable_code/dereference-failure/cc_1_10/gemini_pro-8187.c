//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_HOSTS 256
#define MAX_PORTS 65536
#define MAX_CONNECTIONS 1024

typedef struct {
  char *hostname;
  int port;
  int socket;
  bool connected;
} host_t;

typedef struct {
  host_t *hosts;
  int num_hosts;
  int num_ports;
  int num_connections;
} network_t;

network_t *network_new() {
  network_t *network = malloc(sizeof(network_t));
  network->hosts = malloc(MAX_HOSTS * sizeof(host_t));
  network->num_hosts = 0;
  network->num_ports = 0;
  network->num_connections = 0;
  return network;
}

void network_free(network_t *network) {
  for (int i = 0; i < network->num_hosts; i++) {
    free(network->hosts[i].hostname);
    close(network->hosts[i].socket);
  }
  free(network->hosts);
  free(network);
}

int network_add_host(network_t *network, char *hostname, int port) {
  if (network->num_hosts >= MAX_HOSTS) {
    return -1;
  }

  host_t *host = &network->hosts[network->num_hosts++];
  host->hostname = strdup(hostname);
  host->port = port;
  host->socket = -1;
  host->connected = false;

  return 0;
}

int network_add_port(network_t *network, int port) {
  if (network->num_ports >= MAX_PORTS) {
    return -1;
  }

  network->num_ports++;

  return 0;
}

int network_connect(network_t *network) {
  for (int i = 0; i < network->num_hosts; i++) {
    host_t *host = &network->hosts[i];

    host->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (host->socket < 0) {
      perror("socket");
      return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(host->port);

    if (inet_pton(AF_INET, host->hostname, &addr.sin_addr) <= 0) {
      perror("inet_pton");
      return -1;
    }

    if (connect(host->socket, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
      perror("connect");
      return -1;
    }

    host->connected = true;
    network->num_connections++;
  }

  return 0;
}

int network_disconnect(network_t *network) {
  for (int i = 0; i < network->num_hosts; i++) {
    host_t *host = &network->hosts[i];

    if (host->connected) {
      close(host->socket);
      host->connected = false;
      network->num_connections--;
    }
  }

  return 0;
}

int network_map(network_t *network) {
  for (int i = 0; i < network->num_hosts; i++) {
    host_t *host = &network->hosts[i];

    for (int j = 0; j < network->num_ports; j++) {
      int port = network->num_ports - j;

      struct sockaddr_in addr;
      memset(&addr, 0, sizeof(addr));
      addr.sin_family = AF_INET;
      addr.sin_port = htons(port);

      if (inet_pton(AF_INET, host->hostname, &addr.sin_addr) <= 0) {
        perror("inet_pton");
        return -1;
      }

      int sock = socket(AF_INET, SOCK_STREAM, 0);
      if (sock < 0) {
        perror("socket");
        return -1;
      }

      if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) >= 0) {
        printf("%s:%d is open\n", host->hostname, port);
        close(sock);
      }
    }
  }

  return 0;
}

int main() {
  network_t *network = network_new();

  network_add_host(network, "localhost", 80);
  network_add_host(network, "google.com", 443);
  network_add_port(network, 22);
  network_add_port(network, 25);

  network_connect(network);
  network_map(network);
  network_disconnect(network);

  network_free(network);

  return 0;
}