//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: relaxed
// A C program to do a basic TCP client-server chat.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// Define the port number for the server.
#define PORT 8080

// Define the maximum size of a message.
#define MAX_MESSAGE_SIZE 1024

// Create a socket for the server.
int create_server_socket() {
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Error creating server socket");
    exit(1);
  }
  return server_socket;
}

// Bind the server socket to the port.
void bind_server_socket(int server_socket) {
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);

  if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
    perror("Error binding server socket to port");
    exit(1);
  }
}

// Listen for incoming connections on the server socket.
void listen_for_connections(int server_socket) {
  if (listen(server_socket, 5) == -1) {
    perror("Error listening for connections on server socket");
    exit(1);
  }
}

// Accept an incoming connection on the server socket.
int accept_connection(int server_socket) {
  int client_socket = accept(server_socket, NULL, NULL);
  if (client_socket == -1) {
    perror("Error accepting connection on server socket");
    exit(1);
  }
  return client_socket;
}

// Send a message to the client.
void send_message(int client_socket, char* message) {
  if (send(client_socket, message, strlen(message), 0) == -1) {
    perror("Error sending message to client");
    exit(1);
  }
}

// Receive a message from the client.
void receive_message(int client_socket, char* message) {
  int message_length = recv(client_socket, message, MAX_MESSAGE_SIZE, 0);
  if (message_length == -1) {
    perror("Error receiving message from client");
    exit(1);
  }
  message[message_length] = '\0';
}

// Close a socket.
void close_socket(int socket) {
  if (close(socket) == -1) {
    perror("Error closing socket");
    exit(1);
  }
}

int main() {
  // Create the server socket.
  int server_socket = create_server_socket();

  // Bind the server socket to the port.
  bind_server_socket(server_socket);

  // Listen for incoming connections on the server socket.
  listen_for_connections(server_socket);

  // Accept an incoming connection on the server socket.
  int client_socket = accept_connection(server_socket);

  // Send a message to the client.
  char* message = "Hello, client!";
  send_message(client_socket, message);

  // Receive a message from the client.
  char client_message[MAX_MESSAGE_SIZE];
  receive_message(client_socket, client_message);
  printf("Message from client: %s\n", client_message);

  // Close the client socket.
  close_socket(client_socket);

  // Close the server socket.
  close_socket(server_socket);

  return 0;
}