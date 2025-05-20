//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ClientState {
  int sockfd;
  char *hostname;
  struct ClientState *next;
} ClientState;

ClientState *client_list = NULL;

void handle_client(int sockfd, char *hostname) {
  ClientState *new_client = malloc(sizeof(ClientState));
  new_client->sockfd = sockfd;
  new_client->hostname = strdup(hostname);
  new_client->next = client_list;
  client_list = new_client;

  char buffer[MAX_BUFFER_SIZE];
  int bytes_read = read(sockfd, buffer, MAX_BUFFER_SIZE);
  if (bytes_read > 0) {
    write(sockfd, buffer, bytes_read);
  }

  close(sockfd);
}

int main() {
  int sockfd_listen, new_sockfd;
  struct sockaddr_in server_addr, client_addr;
  int client_len, bytes_read, i;

  sockfd_listen = socket(AF_INET, SOCK_STREAM, htons(8080));
  if (sockfd_listen < 0) {
    perror("Error creating socket");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  bind(sockfd_listen, (struct sockaddr *)&server_addr, sizeof(server_addr));

  listen(sockfd_listen, 10);

  while (1) {
    client_len = sizeof(client_addr);
    new_sockfd = accept(sockfd_listen, (struct sockaddr *)&client_addr, &client_len);
    if (new_sockfd < 0) {
      perror("Error accepting client connection");
      continue;
    }

    handle_client(new_sockfd, inet_ntoa((struct sockaddr *)&client_addr));
  }

  return 0;
}