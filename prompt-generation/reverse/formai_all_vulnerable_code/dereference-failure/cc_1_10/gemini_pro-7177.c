//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 1024

// Structure to represent a client
typedef struct Client {
  int socket_fd;
  char name[MAX_MESSAGE_LENGTH];
  int is_active;
} Client;

// Function to handle client connections
void handle_client(Client *client) {
  char buffer[MAX_MESSAGE_LENGTH];

  // Receive the client's message
  int bytes_received = recv(client->socket_fd, buffer, MAX_MESSAGE_LENGTH, 0);
  if (bytes_received <= 0) {
    printf("Error receiving message from client %s\n", client->name);
    return;
  }

  // Process the client's message
  printf("Received message from client %s: %s\n", client->name, buffer);

  // Send a response to the client
  char response[MAX_MESSAGE_LENGTH];
  snprintf(response, MAX_MESSAGE_LENGTH, "Hello, %s!", client->name);
  send(client->socket_fd, response, strlen(response), 0);

  // Close the client's socket
  close(client->socket_fd);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return 1;
  }

  // Get the port number from the command line
  int port_number = atoi(argv[1]);

  // Create the server socket
  int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket_fd == -1) {
    perror("Error creating server socket");
    return 1;
  }

  // Set the server socket to be reusable
  int reuse_addr = 1;
  if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr)) == -1) {
    perror("Error setting socket options");
    return 1;
  }

  // Bind the server socket to the port number
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port_number);
  if (bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("Error binding socket to port");
    return 1;
  }

  // Listen for client connections
  if (listen(server_socket_fd, MAX_CLIENTS) == -1) {
    perror("Error listening for client connections");
    return 1;
  }

  // Array to store the client sockets
  int client_sockets[MAX_CLIENTS];
  memset(client_sockets, 0, sizeof(client_sockets));

  // Main server loop
  while (1) {
    // Wait for a client to connect
    int client_socket_fd = accept(server_socket_fd, NULL, NULL);
    if (client_socket_fd == -1) {
      perror("Error accepting client connection");
      continue;
    }

    // Find an empty slot in the client sockets array
    int client_index = -1;
    for (int i = 0; i < MAX_CLIENTS; i++) {
      if (client_sockets[i] == 0) {
        client_index = i;
        break;
      }
    }

    // If no empty slot is found, close the client socket
    if (client_index == -1) {
      printf("Error: No empty slot found for client\n");
      close(client_socket_fd);
      continue;
    }

    // Add the client socket to the array
    client_sockets[client_index] = client_socket_fd;

    // Create a new client struct
    Client *client = malloc(sizeof(Client));
    client->socket_fd = client_socket_fd;
    client->is_active = 1;

    // Receive the client's name
    int bytes_received = recv(client_socket_fd, client->name, MAX_MESSAGE_LENGTH, 0);
    if (bytes_received <= 0) {
      printf("Error receiving client name\n");
      free(client);
      client_sockets[client_index] = 0;
      continue;
    }

    // Print a welcome message to the client
    printf("Welcome, %s!\n", client->name);

    // Handle the client in a separate thread
    pthread_t client_thread;
    pthread_create(&client_thread, NULL, (void *(*)(void *))handle_client, client);
  }

  // Close the server socket
  close(server_socket_fd);

  return 0;
}