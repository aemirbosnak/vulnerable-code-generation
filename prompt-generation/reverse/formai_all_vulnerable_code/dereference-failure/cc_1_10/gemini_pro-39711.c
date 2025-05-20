//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of clients
#define MAX_CLIENTS 10

// Define the port number
#define PORT 5555

// Define the buffer size
#define BUFFER_SIZE 1024

// Define the command structure
typedef struct {
  char command;
  float speed;
  float angle;
} Command;

// Define the client structure
typedef struct {
  int socket;
  struct sockaddr_in address;
} Client;

// Define the server structure
typedef struct {
  int socket;
  struct sockaddr_in address;
  Client clients[MAX_CLIENTS];
  int num_clients;
} Server;

// Create a new server
Server *create_server() {
  Server *server = malloc(sizeof(Server));
  server->socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server->socket == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  server->address.sin_family = AF_INET;
  server->address.sin_port = htons(PORT);
  server->address.sin_addr.s_addr = INADDR_ANY;

  if (bind(server->socket, (struct sockaddr *)&server->address, sizeof(server->address)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  if (listen(server->socket, MAX_CLIENTS) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  server->num_clients = 0;

  return server;
}

// Destroy a server
void destroy_server(Server *server) {
  close(server->socket);
  free(server);
}

// Accept a new client
int accept_client(Server *server) {
  int client_socket = accept(server->socket, (struct sockaddr *)&server->clients[server->num_clients].address, (socklen_t *)&server->clients[server->num_clients].address);
  if (client_socket == -1) {
    perror("accept");
    return -1;
  }

  server->clients[server->num_clients].socket = client_socket;
  server->num_clients++;

  return client_socket;
}

// Send a message to a client
int send_message(int client_socket, char *message) {
  int length = strlen(message);
  int sent = send(client_socket, message, length, 0);
  if (sent == -1) {
    perror("send");
    return -1;
  }

  return sent;
}

// Receive a message from a client
int receive_message(int client_socket, char *buffer) {
  int length = recv(client_socket, buffer, BUFFER_SIZE, 0);
  if (length == -1) {
    perror("recv");
    return -1;
  }

  return length;
}

// Handle a client
void handle_client(Server *server, int client_socket) {
  char buffer[BUFFER_SIZE];

  // Receive the command from the client
  int length = receive_message(client_socket, buffer);
  if (length == -1) {
    perror("recv");
    return;
  }

  // Parse the command
  Command command;
  memcpy(&command, buffer, sizeof(command));

  // Execute the command
  switch (command.command) {
    case 'f':
      printf("Forward: speed = %f, angle = %f\n", command.speed, command.angle);
      break;
    case 'b':
      printf("Backward: speed = %f, angle = %f\n", command.speed, command.angle);
      break;
    case 'l':
      printf("Left: speed = %f, angle = %f\n", command.speed, command.angle);
      break;
    case 'r':
      printf("Right: speed = %f, angle = %f\n", command.speed, command.angle);
      break;
    case 's':
      printf("Stop\n");
      break;
  }

  // Send a response to the client
  char response[] = "OK";
  send_message(client_socket, response);
}

// Main function
int main() {
  // Create a server
  Server *server = create_server();

  // Main loop
  while (1) {
    // Accept new clients
    int client_socket = accept_client(server);
    if (client_socket != -1) {
      printf("New client connected\n");
    }

    // Handle clients
    for (int i = 0; i < server->num_clients; i++) {
      handle_client(server, server->clients[i].socket);
    }
  }

  // Destroy the server
  destroy_server(server);

  return 0;
}