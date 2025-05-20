//Gemma-7B DATASET v1.0 Category: Chat server ; Style: Sherlock Holmes
// The Sign of Four Chat Server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

// Define the maximum number of clients
#define MAX_CLIENTS 10

// Define the port number
#define PORT 8080

// Create a list of clients
struct client_list {
  char name[20];
  int socket_fd;
  struct client_list* next;
};

// Function to add a client to the list
void add_client(struct client_list* head, char* name, int socket_fd) {
  struct client_list* new_client = malloc(sizeof(struct client_list));
  strcpy(new_client->name, name);
  new_client->socket_fd = socket_fd;
  new_client->next = NULL;

  if (head == NULL) {
    head = new_client;
  } else {
    head->next = new_client;
  }
}

// Function to remove a client from the list
void remove_client(struct client_list* head, char* name) {
  struct client_list* current = head;
  struct client_list* previous = NULL;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }

  // Client not found
  return;
}

// Function to handle client messages
void handle_client(struct client_list* head, int socket_fd) {
  char message[256];

  // Receive the client message
  recv(socket_fd, message, 256, 0);

  // Broadcast the message to other clients
  struct client_list* current = head;
  while (current) {
    if (current->socket_fd != socket_fd) {
      send(current->socket_fd, message, strlen(message), 0);
    }
    current = current->next;
  }
}

int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));

  // Bind the socket to a port
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

  // Create a list of clients
  struct client_list* head = NULL;

  // Listen for clients
  while (1) {
    // Accept a client connection
    int client_fd = accept(sockfd, NULL, NULL);

    // Add the client to the list
    add_client(head, "Unknown", client_fd);

    // Handle client messages
    handle_client(head, client_fd);

    // Remove the client from the list
    remove_client(head, "Unknown");

    // Close the client connection
    close(client_fd);
  }

  return 0;
}