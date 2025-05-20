//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum length of the message that can be sent or received
#define MAX_MESSAGE_LENGTH 1024

// Create a socket for the server to listen on
int create_server_socket() {
  int server_socket;

  // Create a socket for the server to listen on
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    exit(1);
  }

  // Set up the server address
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);

  // Bind the socket to the server address
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("bind");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(server_socket, 10) == -1) {
    perror("listen");
    exit(1);
  }

  return server_socket;
}

// Accept a connection from a client
int accept_client_connection(int server_socket) {
  int client_socket;

  // Accept a connection from a client
  client_socket = accept(server_socket, NULL, NULL);
  if (client_socket == -1) {
    perror("accept");
    exit(1);
  }

  return client_socket;
}

// Receive a message from a client
char *receive_message(int client_socket) {
  char *message;

  // Allocate memory for the message
  message = malloc(MAX_MESSAGE_LENGTH);
  if (message == NULL) {
    perror("malloc");
    exit(1);
  }

  // Receive the message from the client
  int bytes_received = recv(client_socket, message, MAX_MESSAGE_LENGTH, 0);
  if (bytes_received == -1) {
    perror("recv");
    exit(1);
  }

  // Null-terminate the message
  message[bytes_received] = '\0';

  return message;
}

// Send a message to a client
void send_message(int client_socket, char *message) {
  // Send the message to the client
  int bytes_sent = send(client_socket, message, strlen(message), 0);
  if (bytes_sent == -1) {
    perror("send");
    exit(1);
  }
}

// Close a socket
void close_socket(int socket) {
  // Close the socket
  if (close(socket) == -1) {
    perror("close");
    exit(1);
  }
}

// Main function
int main() {
  // Create a server socket
  int server_socket = create_server_socket();

  // Accept a connection from a client
  int client_socket = accept_client_connection(server_socket);

  // Receive a message from the client
  char *message = receive_message(client_socket);

  // Print the message to the console
  printf("Message from client: %s\n", message);

  // Send a message back to the client
  send_message(client_socket, "Hello from server!");

  // Close the client socket
  close_socket(client_socket);

  // Close the server socket
  close_socket(server_socket);

  return 0;
}