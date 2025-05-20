//Gemma-7B DATASET v1.0 Category: Chat server ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <netdb.h>

#define MAX_CLIENTS 10

typedef struct client_t {
  char name[256];
  int sockfd;
  struct client_t *next;
} client_t;

client_t *head = NULL;

void add_client(int sockfd, char *name) {
  client_t *new_client = malloc(sizeof(client_t));
  strcpy(new_client->name, name);
  new_client->sockfd = sockfd;
  new_client->next = head;
  head = new_client;
}

void handle_client(client_t *client) {
  char message[256];
  printf("Client: %s, Message: ", client->name);
  scanf("%s", message);
  send(client->sockfd, message, sizeof(message), 0);
  free(client);
}

int main() {
  int sockfd, new_sockfd;
  struct sockaddr_in server_addr, client_addr;
  int client_len;
  char message[256];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

  // Bind the socket to a port
  server_addr.sin_port = htons(8080);
  bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // Listen for clients
  while (1) {
    // Accept a client connection
    client_len = sizeof(client_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);

    // Add the client to the list
    add_client(new_sockfd, "Unknown");

    // Handle the client
    handle_client(head);
  }

  return 0;
}