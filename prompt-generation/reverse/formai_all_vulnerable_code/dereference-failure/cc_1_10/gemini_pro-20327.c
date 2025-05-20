//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Colors for text
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"

// Function to set up a server socket
int setup_server_socket(int port) {
  int server_socket;
  struct sockaddr_in server_address;

  // Create a socket
  if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  // Set up the server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port);

  // Bind the socket to the server address
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Error binding socket to address");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_socket, 5) < 0) {
    perror("Error listening for connections");
    exit(EXIT_FAILURE);
  }

  return server_socket;
}

// Function to handle a client connection
void handle_client_connection(int client_socket) {
  char buffer[1024];
  int num_bytes;

  // Receive data from the client
  while ((num_bytes = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
    // Print the data received from the client
    printf("%s", buffer);

    // Send data back to the client
    send(client_socket, buffer, num_bytes, 0);
  }

  // Close the client socket
  close(client_socket);
}

// Main function
int main(int argc, char **argv) {
  int server_socket, client_socket;
  struct sockaddr_in client_address;
  socklen_t client_address_len;

  // Check if the user has provided a port number
  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Set up the server socket
  server_socket = setup_server_socket(atoi(argv[1]));

  // Loop to accept incoming connections
  while (1) {
    // Accept an incoming connection
    client_address_len = sizeof(client_address);
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len)) < 0) {
      perror("Error accepting connection");
      continue;
    }

    // Handle the client connection
    handle_client_connection(client_socket);
  }

  // Close the server socket
  close(server_socket);

  return 0;
}