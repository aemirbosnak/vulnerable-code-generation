//Gemma-7B DATASET v1.0 Category: Chat server ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <netdb.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

typedef struct client_t {
  char name[256];
  int sockfd;
  struct client_t *next;
} client_t;

client_t *head = NULL;

void add_client(char *name, int sockfd) {
  client_t *new_client = malloc(sizeof(client_t));
  strcpy(new_client->name, name);
  new_client->sockfd = sockfd;
  new_client->next = head;
  head = new_client;
}

void handle_client(client_t *client) {
  char message[BUFFER_SIZE];

  // Receive message from client
  recv(client->sockfd, message, BUFFER_SIZE, 0);

  // Print message to server
  printf("%s: %s\n", client->name, message);

  // Send message back to client
  send(client->sockfd, message, BUFFER_SIZE, 0);
}

int main() {
  int sockfd, new_sockfd;
  struct sockaddr_in server_addr, client_addr;
  int client_len;

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

  // Bind socket to port
  server_addr.sin_port = htons(8080);
  bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // Listen for clients
  while (1) {
    // Accept client connection
    client_len = sizeof(client_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);

    // Add client to list
    add_client("Client", new_sockfd);

    // Handle client
    handle_client(head);
  }

  return 0;
}