//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 4096

typedef struct Client {
  int sockfd;
  char buf[MAX_BUFFER_SIZE];
  struct Client *next;
} Client;

Client *clients = NULL;

void handle_client(int sockfd) {
  Client *client = malloc(sizeof(Client));
  client->sockfd = sockfd;
  client->next = clients;
  clients = client;

  printf("Client connected: %d\n", sockfd);

  char request[MAX_BUFFER_SIZE];
  read(sockfd, request, MAX_BUFFER_SIZE);
  printf("Client request: %s\n", request);

  char response[MAX_BUFFER_SIZE];
  sprintf(response, "HTTP/1.1 200 OK\r\n\r\nHello, world!");
  write(sockfd, response, strlen(response));

  free(client);
}

int main() {
  int sockfd;
  struct sockaddr_in sock_addr;

  // Bind socket to port 8080
  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  if (sockfd < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  while (1) {
    struct sockaddr_in client_addr;
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (client_sockfd < 0) {
      perror("Error accepting client");
      continue;
    }

    handle_client(client_sockfd);
  }

  return 0;
}