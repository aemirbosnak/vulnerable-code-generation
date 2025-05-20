//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the server's port number
#define PORT 8080

// Define the maximum number of clients that can connect to the server
#define MAX_CLIENTS 10

// Define the maximum size of a request buffer
#define MAX_REQUEST_SIZE 1024

// Define the maximum size of a response buffer
#define MAX_RESPONSE_SIZE 1024

// Create a socket for the server to listen on
int create_server_socket() {
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Could not create server socket");
    exit(1);
  }
  return server_socket;
}

// Bind the server socket to the specified port
void bind_server_socket(int server_socket, int port) {
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port);
  if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
    perror("Could not bind server socket to port");
    exit(1);
  }
}

// Listen for incoming connections on the server socket
void listen_for_connections(int server_socket) {
  if (listen(server_socket, MAX_CLIENTS) == -1) {
    perror("Could not listen for connections on server socket");
    exit(1);
  }
}

// Accept an incoming connection on the server socket
int accept_connection(int server_socket) {
  int client_socket = accept(server_socket, NULL, NULL);
  if (client_socket == -1) {
    perror("Could not accept incoming connection on server socket");
    exit(1);
  }
  return client_socket;
}

// Read a request from a client socket
void read_request(int client_socket, char *request) {
  int bytes_received = recv(client_socket, request, MAX_REQUEST_SIZE, 0);
  if (bytes_received == -1) {
    perror("Could not read request from client socket");
    exit(1);
  }
  request[bytes_received] = '\0';
}

// Write a response to a client socket
void write_response(int client_socket, char *response) {
  int bytes_sent = send(client_socket, response, strlen(response), 0);
  if (bytes_sent == -1) {
    perror("Could not write response to client socket");
    exit(1);
  }
}

// Close a client socket
void close_client_socket(int client_socket) {
  close(client_socket);
}

// Main function
int main() {
  // Create a server socket
  int server_socket = create_server_socket();

  // Bind the server socket to the specified port
  bind_server_socket(server_socket, PORT);

  // Listen for incoming connections on the server socket
  listen_for_connections(server_socket);

  // Accept an incoming connection on the server socket
  int client_socket = accept_connection(server_socket);

  // Read a request from the client socket
  char request[MAX_REQUEST_SIZE];
  read_request(client_socket, request);

  // Write a response to the client socket
  char response[MAX_RESPONSE_SIZE];
  sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>Hello, world!</h1>");
  write_response(client_socket, response);

  // Close the client socket
  close_client_socket(client_socket);

  // Close the server socket
  close(server_socket);

  return 0;
}