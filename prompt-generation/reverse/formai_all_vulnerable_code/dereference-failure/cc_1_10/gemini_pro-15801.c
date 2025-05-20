//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of connections
#define MAX_CONNECTIONS 5

// Define the maximum size of the request buffer
#define MAX_REQUEST_SIZE 1024

// Define the maximum size of the response buffer
#define MAX_RESPONSE_SIZE 1024

// Define the default port number
#define DEFAULT_PORT 8080

// Define the error message
#define ERROR_MESSAGE "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\nNot Found\n"

// Define the success message
#define SUCCESS_MESSAGE "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, world!\n"

// Function to handle client requests
void handle_request(int client_socket) {
  // Read the request from the client
  char request[MAX_REQUEST_SIZE];
  int bytes_received = recv(client_socket, request, MAX_REQUEST_SIZE, 0);

  // Check if the request was received successfully
  if (bytes_received < 0) {
    perror("recv");
    return;
  }

  // Parse the request
  char *method = strtok(request, " ");
  char *path = strtok(NULL, " ");
  char *version = strtok(NULL, "\r\n");

  // Check if the request is valid
  if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
    // Send an error message to the client
    send(client_socket, ERROR_MESSAGE, strlen(ERROR_MESSAGE), 0);
    return;
  }

  // Send a success message to the client
  send(client_socket, SUCCESS_MESSAGE, strlen(SUCCESS_MESSAGE), 0);
}

// Function to start the server
void start_server(int port) {
  // Create a socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Check if the socket was created successfully
  if (server_socket < 0) {
    perror("socket");
    return;
  }

  // Set the socket options
  int optval = 1;
  setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

  // Bind the socket to the port
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port);
  bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

  // Listen for connections
  listen(server_socket, MAX_CONNECTIONS);

  // Accept connections
  while (1) {
    // Accept a connection
    int client_socket = accept(server_socket, NULL, NULL);

    // Check if the connection was accepted successfully
    if (client_socket < 0) {
      perror("accept");
      continue;
    }

    // Handle the client request
    handle_request(client_socket);

    // Close the client socket
    close(client_socket);
  }

  // Close the server socket
  close(server_socket);
}

// Main function
int main(int argc, char *argv[]) {
  // Parse the command line arguments
  int port = DEFAULT_PORT;
  if (argc > 1) {
    port = atoi(argv[1]);
  }

  // Start the server
  start_server(port);

  return 0;
}