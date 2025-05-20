//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_HOSTS 100

struct host {
  char *name;
  char *ip;
  int port;
  struct host *next;
};

struct host *head = NULL;

void add_host(char *name, char *ip, int port) {
  struct host *new_host = malloc(sizeof(struct host));
  new_host->name = strdup(name);
  new_host->ip = strdup(ip);
  new_host->port = port;
  new_host->next = NULL;

  if (head == NULL) {
    head = new_host;
  } else {
    struct host *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_host;
  }
}

void print_hosts() {
  struct host *current = head;
  while (current != NULL) {
    printf("%s (%s):%d\n", current->name, current->ip, current->port);
    current = current->next;
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <hostname or IP>\n", argv[0]);
    return 1;
  }

  // Resolve the hostname or IP address
  struct hostent *host_info = gethostbyname(argv[1]);
  if (host_info == NULL) {
    printf("Error: Could not resolve hostname or IP address: %s\n", argv[1]);
    return 1;
  }

  // Get the IP address of the host
  char *ip = inet_ntoa(*(struct in_addr *)host_info->h_addr_list[0]);

  // Get the port number of the service
  int port = 80;  // Default port for HTTP

  // Add the host to the list of hosts
  add_host(host_info->h_name, ip, port);

  // Print the list of hosts
  print_hosts();

  return 0;
}