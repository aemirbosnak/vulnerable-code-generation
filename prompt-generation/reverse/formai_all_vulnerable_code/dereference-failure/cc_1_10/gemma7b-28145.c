//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ProxyClient {
  int sockfd;
  char hostname[256];
  char port;
  struct ProxyClient* next;
} ProxyClient;

ProxyClient* proxy_client_insert(ProxyClient* head, char* hostname, int port) {
  ProxyClient* new_client = (ProxyClient*)malloc(sizeof(ProxyClient));
  new_client->sockfd = -1;
  strcpy(new_client->hostname, hostname);
  new_client->port = port;
  new_client->next = NULL;

  if (head == NULL) {
    return new_client;
  }

  head->next = new_client;
  return head;
}

void proxy_client_remove(ProxyClient* head, char* hostname) {
  ProxyClient* previous = NULL;
  ProxyClient* current = head;

  while (current) {
    if (strcmp(current->hostname, hostname) == 0) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }

  return;
}

int main() {
  ProxyClient* head = NULL;

  // Simulate adding clients
  proxy_client_insert(head, "localhost", 8080);
  proxy_client_insert(head, "192.168.1.1", 8080);

  // Simulate removing clients
  proxy_client_remove(head, "localhost");

  // Print remaining clients
  ProxyClient* current = head;
  while (current) {
    printf("Hostname: %s, Port: %d\n", current->hostname, current->port);
    current = current->next;
  }

  return 0;
}