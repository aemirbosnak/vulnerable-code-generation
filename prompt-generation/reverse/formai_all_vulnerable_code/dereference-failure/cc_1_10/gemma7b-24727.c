//Gemma-7B DATASET v1.0 Category: Chat server ; Style: calm
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CLIENTS 10

struct client_data {
  char name[256];
  int sockfd;
  struct client_data *next;
};

void handle_client(int sockfd, struct client_data **head) {
  struct client_data *new_client = malloc(sizeof(struct client_data));
  new_client->sockfd = sockfd;
  new_client->next = NULL;

  // Get client name
  char name[256];
  recv(sockfd, name, 256, 0);
  strcpy(new_client->name, name);

  // Add client to head
  if (*head == NULL) {
    *head = new_client;
  } else {
    (*head)->next = new_client;
  }

  // Echo client name back
  send(sockfd, name, strlen(name) + 1, 0);

  // Listen for client messages
  char message[256];
  while (1) {
    // Receive client message
    recv(sockfd, message, 256, 0);

    // Check if client has sent end-of-message signal
    if (strcmp(message, "/end") == 0) {
      break;
    }

    // Echo client message back
    send(sockfd, message, strlen(message) + 1, 0);
  }

  // Close client connection
  close(sockfd);

  // Free client data
  free(new_client);
}

int main() {
  // Create a listening socket
  int sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

  // Bind the socket to a port
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // Listen for clients
  struct client_data *head = NULL;
  while (1) {
    // Accept a client connection
    int new_sockfd = accept(sockfd, NULL, NULL);

    // Handle client connection
    handle_client(new_sockfd, &head);
  }

  // Close the listening socket
  close(sockfd);

  return 0;
}