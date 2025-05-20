//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: visionary
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 10

typedef struct client_t {
  int fd;
  char name[256];
  struct client_t* next;
} client_t;

client_t* head = NULL;

void add_client(int fd, char* name) {
  client_t* new_client = malloc(sizeof(client_t));
  new_client->fd = fd;
  strcpy(new_client->name, name);
  new_client->next = head;
  head = new_client;
}

void handle_client(client_t* client) {
  char message[1024];
  printf("Client: %s, Message: ", client->name);
  scanf("%s", message);
  printf("Client: %s, Response: ", client->name);
  printf("%s\n", message);
  close(client->fd);
  free(client);
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in serv_addr, cli_addr;
  int client_fd, i, num_clients = 0;

  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8080);
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, NULL);
    add_client(newsockfd, "Client " + num_clients);
    num_clients++;
    handle_client(head);
  }

  return 0;
}