//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ProxyClient {
  char *hostname;
  int port;
  int socketfd;
  struct ProxyClient *next;
} ProxyClient;

ProxyClient *head = NULL;

void addClient(char *hostname, int port) {
  ProxyClient *newClient = malloc(sizeof(ProxyClient));
  newClient->hostname = strdup(hostname);
  newClient->port = port;
  newClient->socketfd = -1;
  newClient->next = NULL;

  if (head == NULL) {
    head = newClient;
  } else {
    ProxyClient *tempClient = head;
    while (tempClient->next) {
      tempClient = tempClient->next;
    }
    tempClient->next = newClient;
  }
}

int main() {
  addClient("localhost", 8080);
  addClient("localhost", 8081);

  // Simulate client requests
  for (int i = 0; i < 10; i++) {
    char *hostname = "localhost";
    int port = rand() % 2 + 8080;
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    connect(sockfd, (struct sockaddr *)NULL, 0);
    write(sockfd, "GET /", 5);
    read(sockfd, "Response", MAX_BUFFER_SIZE);
    close(sockfd);
  }

  return 0;
}