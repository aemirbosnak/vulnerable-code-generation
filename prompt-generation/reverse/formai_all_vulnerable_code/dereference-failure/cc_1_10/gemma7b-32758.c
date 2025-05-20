//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Client {
  char name[256];
  int socket_fd;
  struct Client* next;
} Client;

Client* head = NULL;

void handle_client(int sockfd) {
  Client* new_client = malloc(sizeof(Client));
  new_client->socket_fd = sockfd;
  snprintf(new_client->name, 256, "Client %d", sockfd);
  new_client->next = head;
  head = new_client;
  printf("Client %s connected.\n", new_client->name);

  char buffer[MAX_BUFFER_SIZE];
  while (1) {
    int bytes_read = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_read == 0) {
      printf("Client %s disconnected.\n", new_client->name);
      break;
    }
    printf("Client %s: %s\n", new_client->name, buffer);
    send(sockfd, buffer, bytes_read, 0);
  }

  free(new_client);
}

int main() {
  int sockfd;
  struct sockaddr_in sock_addr;
  sock_addr.sin_family = AF_INET;
  sock_addr.sin_port = htons(8080);
  sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  bind(sockfd, (struct sockaddr*)&sock_addr, sizeof(sock_addr));

  listen(sockfd, 10);

  while (1) {
    int new_sockfd = accept(sockfd, NULL, NULL);
    handle_client(new_sockfd);
  }

  return 0;
}