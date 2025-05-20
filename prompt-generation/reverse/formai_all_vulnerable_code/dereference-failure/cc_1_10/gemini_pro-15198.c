//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

typedef struct {
  int sockfd;
  struct sockaddr_in addr;
} client_t;

void* handle_client(void* arg) {
  client_t* client = (client_t*)arg;
  char buffer[256];

  while (1) {
    memset(buffer, 0, sizeof(buffer));
    recv(client->sockfd, buffer, sizeof(buffer), 0);

    printf("Client: %s\n", buffer);

    memset(buffer, 0, sizeof(buffer));
    scanf("%s", buffer);
    send(client->sockfd, buffer, sizeof(buffer), 0);
  }

  close(client->sockfd);
  free(client);
  return NULL;
}

int main() {
  int server_sockfd, client_sockfd, addrlen;
  struct sockaddr_in server_addr, client_addr;

  server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sockfd < 0) {
    perror("socket");
    return -1;
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  if (bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    return -1;
  }

  if (listen(server_sockfd, 5) < 0) {
    perror("listen");
    return -1;
  }

  while (1) {
    addrlen = sizeof(client_addr);
    client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &addrlen);
    if (client_sockfd < 0) {
      perror("accept");
      continue;
    }

    client_t* client = (client_t*)malloc(sizeof(client_t));
    client->sockfd = client_sockfd;
    client->addr = client_addr;

    pthread_t thread;
    if (pthread_create(&thread, NULL, handle_client, (void*)client) < 0) {
      perror("pthread_create");
      continue;
    }
  }

  close(server_sockfd);
  return 0;
}