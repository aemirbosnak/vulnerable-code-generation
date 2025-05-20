//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum number of clients that can connect to the server
#define MAX_CLIENTS 10

// Define the size of the buffer for receiving data from clients
#define BUFFER_SIZE 1024

// Create a socket for the server
int create_server_socket() {
  int server_socket;

  // Create a socket for the server
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Check if the socket was created successfully
  if (server_socket < 0) {
    perror("Error creating socket");
    exit(1);
  }

  return server_socket;
}

// Bind the server socket to the specified port
void bind_server_socket(int server_socket) {
  struct sockaddr_in server_address;

  // Initialize the server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);

  // Bind the server socket to the specified address and port
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Error binding socket");
    exit(1);
  }
}

// Listen for incoming connections on the server socket
void listen_for_connections(int server_socket) {
  // Listen for incoming connections on the server socket
  if (listen(server_socket, MAX_CLIENTS) < 0) {
    perror("Error listening for connections");
    exit(1);
  }
}

// Accept an incoming connection on the server socket
int accept_connection(int server_socket) {
  int client_socket;
  struct sockaddr_in client_address;
  socklen_t client_address_length;

  // Accept an incoming connection on the server socket
  client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);

  // Check if the client socket was created successfully
  if (client_socket < 0) {
    perror("Error accepting connection");
    exit(1);
  }

  return client_socket;
}

// Receive data from a client
char *receive_data(int client_socket) {
  char *buffer = malloc(BUFFER_SIZE);
  int bytes_received;

  // Receive data from the client
  bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

  // Check if the data was received successfully
  if (bytes_received < 0) {
    perror("Error receiving data");
    exit(1);
  }

  // Return the received data
  return buffer;
}

// Send data to a client
void send_data(int client_socket, char *data) {
  // Send data to the client
  if (send(client_socket, data, strlen(data), 0) < 0) {
    perror("Error sending data");
    exit(1);
  }
}

// Close a client socket
void close_client_socket(int client_socket) {
  // Close the client socket
  close(client_socket);
}

// Main function
int main() {
  int server_socket, client_socket;
  char *data;

  // Create a server socket
  server_socket = create_server_socket();

  // Bind the server socket to the specified port
  bind_server_socket(server_socket);

  // Listen for incoming connections on the server socket
  listen_for_connections(server_socket);

  // Accept an incoming connection on the server socket
  client_socket = accept_connection(server_socket);

  // Receive data from the client
  data = receive_data(client_socket);

  // Print the received data
  printf("Received data: %s\n", data);

  // Send data to the client
  send_data(client_socket, "Hello world!");

  // Close the client socket
  close_client_socket(client_socket);

  // Close the server socket
  close(server_socket);

  return 0;
}