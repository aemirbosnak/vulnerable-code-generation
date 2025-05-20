//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

// Function to send a message to the server
void send_message(int socket, char *message) {
  // Send the length of the message
  int length = strlen(message);
  send(socket, &length, sizeof(int), 0);

  // Send the message
  send(socket, message, length, 0);
}

// Function to receive a message from the server
char *receive_message(int socket) {
  // Receive the length of the message
  int length;
  recv(socket, &length, sizeof(int), 0);

  // Allocate memory for the message
  char *message = malloc(length + 1);

  // Receive the message
  recv(socket, message, length, 0);

  // Add a null-terminator to the message
  message[length] = '\0';

  return message;
}

// Function to start the server
void start_server() {
  // Create a server socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Bind the server socket to an address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8080);
  server_address.sin_addr.s_addr = INADDR_ANY;
  bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

  // Listen for client connections
  listen(server_socket, 5);

  // Accept a client connection
  int client_socket = accept(server_socket, NULL, NULL);

  // Receive a message from the client
  char *message = receive_message(client_socket);

  // Print the message to the console
  printf("Client: %s\n", message);

  // Send a message to the client
  send_message(client_socket, "Hello from the server!");

  // Close the client socket
  close(client_socket);

  // Close the server socket
  close(server_socket);
}

// Function to start the client
void start_client() {
  // Create a client socket
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Connect to the server
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8080);
  server_address.sin_addr.s_addr = INADDR_LOOPBACK;
  connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));

  // Send a message to the server
  send_message(client_socket, "Hello from the client!");

  // Receive a message from the server
  char *message = receive_message(client_socket);

  // Print the message to the console
  printf("Server: %s\n", message);

  // Close the client socket
  close(client_socket);
}

int main() {
  // Start the server
  start_server();

  // Start the client
  start_client();

  return 0;
}