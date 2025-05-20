//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum size of the message that can be sent or received
#define MAX_MESSAGE_SIZE 1024

// Create a socket for the server
int create_server_socket() {
  int server_socket;

  // Create a socket for the server
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Error creating server socket");
    exit(1);
  }

  // Set the socket options for the server
  int optval = 1;
  if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
    perror("Error setting socket options");
    exit(1);
  }

  // Bind the socket to the port
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("Error binding socket to port");
    exit(1);
  }

  // Listen for connections on the socket
  if (listen(server_socket, 5) == -1) {
    perror("Error listening for connections");
    exit(1);
  }

  return server_socket;
}

// Accept a connection from a client
int accept_client_connection(int server_socket) {
  int client_socket;

  // Accept a connection from a client
  struct sockaddr_in client_address;
  socklen_t client_address_length = sizeof(client_address);
  client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
  if (client_socket == -1) {
    perror("Error accepting client connection");
    exit(1);
  }

  return client_socket;
}

// Receive a message from a client
char *receive_message(int client_socket) {
  char *message = malloc(MAX_MESSAGE_SIZE);

  // Receive a message from the client
  int bytes_received = recv(client_socket, message, MAX_MESSAGE_SIZE, 0);
  if (bytes_received == -1) {
    perror("Error receiving message from client");
    exit(1);
  }

  // Null-terminate the message
  message[bytes_received] = '\0';

  return message;
}

// Send a message to a client
void send_message(int client_socket, char *message) {
  // Send a message to the client
  if (send(client_socket, message, strlen(message), 0) == -1) {
    perror("Error sending message to client");
    exit(1);
  }
}

// Close a socket
void close_socket(int socket) {
  // Close the socket
  if (close(socket) == -1) {
    perror("Error closing socket");
    exit(1);
  }
}

// Main function
int main() {
  // Create a server socket
  int server_socket = create_server_socket();

  // Main loop
  while (1) {
    // Accept a connection from a client
    int client_socket = accept_client_connection(server_socket);

    // Receive a message from the client
    char *message = receive_message(client_socket);

    // Print the message
    printf("Received message from client: %s\n", message);

    // Send a message to the client
    send_message(client_socket, "Hello from the server!");

    // Close the client socket
    close_socket(client_socket);
  }

  // Close the server socket
  close_socket(server_socket);

  return 0;
}