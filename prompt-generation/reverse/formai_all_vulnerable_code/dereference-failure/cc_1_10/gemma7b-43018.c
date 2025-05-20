//Gemma-7B DATASET v1.0 Category: Chat server ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10

typedef struct client_t {
  int sockfd;
  char name[256];
  struct client_t *next;
} client_t;

client_t *clients = NULL;

void handle_client(int sockfd) {
  client_t *client = malloc(sizeof(client_t));
  client->sockfd = sockfd;
  client->next = clients;
  clients = client;

  char buffer[1024];
  int len = recv(sockfd, buffer, 1024, 0);
  if (len > 0) {
    printf("Client: %s says: %s\n", client->name, buffer);
  }

  close(sockfd);
  free(client);
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in server_addr, client_addr;
  int client_len = sizeof(client_addr);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(65535);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    handle_client(newsockfd);
  }

  return 0;
}