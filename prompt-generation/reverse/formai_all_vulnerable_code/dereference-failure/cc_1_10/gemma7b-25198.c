//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

#define PORT 8080

typedef struct Client {
  char name[20];
  int connection_fd;
  struct Client *next;
} Client;

Client *head = NULL;

void handle_client(int connection_fd) {
  Client *new_client = malloc(sizeof(Client));
  new_client->connection_fd = connection_fd;

  // Get client name
  char name[20];
  printf("Enter your name: ");
  scanf(name);
  strcpy(new_client->name, name);

  // Add client to head
  if (head == NULL) {
    head = new_client;
  } else {
    new_client->next = head;
    head = new_client;
  }

  // Send welcome message
  char message[20] = "Welcome, ";
  strcat(message, new_client->name);
  send(connection_fd, message, sizeof(message), 0);

  // Close connection
  close(connection_fd);
}

int main() {
  // Bind to port
  int listen_fd = listen(PORT, NULL);

  // Accept connections
  while (1) {
    int connection_fd = accept(listen_fd, NULL, NULL);
    handle_client(connection_fd);
  }

  return 0;
}