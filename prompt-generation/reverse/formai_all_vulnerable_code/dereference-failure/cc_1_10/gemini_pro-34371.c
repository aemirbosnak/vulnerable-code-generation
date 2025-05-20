//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum number of clients that can connect to the server
#define MAX_CLIENTS 10

// Define the maximum size of the request buffer
#define MAX_REQUEST_SIZE 1024

// Define the maximum size of the response buffer
#define MAX_RESPONSE_SIZE 1024

// Create a socket descriptor
int server_socket;

// Create an array of client sockets
int client_sockets[MAX_CLIENTS];

// Create a buffer to store the request
char request[MAX_REQUEST_SIZE];

// Create a buffer to store the response
char response[MAX_RESPONSE_SIZE];

// Create a function to handle client requests
void handle_client(int client_socket) {
  // Read the request from the client
  int num_bytes_received = recv(client_socket, request, MAX_REQUEST_SIZE, 0);

  // Check if the client has disconnected
  if (num_bytes_received == 0) {
    close(client_socket);
    return;
  }

  // Parse the request
  char *method = strtok(request, " ");
  char *path = strtok(NULL, " ");
  char *protocol = strtok(NULL, "\r\n");

  // Check if the method is GET
  if (strcmp(method, "GET") != 0) {
    // Send a 405 Method Not Allowed response
    sprintf(response, "HTTP/1.1 405 Method Not Allowed\r\n\r\n");
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
    return;
  }

  // Check if the path is valid
  if (strcmp(path, "/") != 0) {
    // Send a 404 Not Found response
    sprintf(response, "HTTP/1.1 404 Not Found\r\n\r\n");
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
    return;
  }

  // Send a 200 OK response
  sprintf(response, "HTTP/1.1 200 OK\r\n\r\nHello, world!");
  send(client_socket, response, strlen(response), 0);

  // Close the client socket
  close(client_socket);
}

// Create a function to main
int main() {
  // Create a socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Check if the socket was created successfully
  if (server_socket == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the socket options
  int opt = 1;
  setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  // Bind the socket to the port
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;
  int bind_status = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

  // Check if the socket was bound successfully
  if (bind_status == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  int listen_status = listen(server_socket, MAX_CLIENTS);

  // Check if the socket is listening successfully
  if (listen_status == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept incoming connections
  while (1) {
    int client_socket = accept(server_socket, NULL, NULL);

    // Check if the client socket was accepted successfully
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Handle the client request
    handle_client(client_socket);
  }

  // Close the server socket
  close(server_socket);

  return EXIT_SUCCESS;
}