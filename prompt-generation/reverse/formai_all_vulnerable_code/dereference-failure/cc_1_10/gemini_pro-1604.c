//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum number of connections that the server can handle
#define MAX_CONNECTIONS 10

// Define the maximum size of the request that the server can handle
#define MAX_REQUEST_SIZE 1024

// Define the maximum size of the response that the server can send
#define MAX_RESPONSE_SIZE 1024

/*
 * This function handles the request from the client.
 */
void handle_request(int client_socket) {
  // Read the request from the client
  char request[MAX_REQUEST_SIZE];
  int bytes_received = recv(client_socket, request, MAX_REQUEST_SIZE, 0);

  // Check if the request was valid
  if (bytes_received < 0) {
    perror("recv");
    close(client_socket);
    return;
  }

  // Parse the request
  char *method = strtok(request, " ");
  char *path = strtok(NULL, " ");
  char *http_version = strtok(NULL, "\r\n");

  // Check if the request is a GET request
  if (strcmp(method, "GET") != 0) {
    // Send a 405 Method Not Allowed response
    char response[MAX_RESPONSE_SIZE];
    sprintf(response, "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n");
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
    return;
  }

  // Check if the path is valid
  if (strcmp(path, "/") != 0) {
    // Send a 404 Not Found response
    char response[MAX_RESPONSE_SIZE];
    sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n");
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
    return;
  }

  // Send a 200 OK response
  char response[MAX_RESPONSE_SIZE];
  sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n<html><body><h1>Hello World!</h1></body></html>", strlen(response));
  send(client_socket, response, strlen(response), 0);

  // Close the client socket
  close(client_socket);
}

/*
 * This function is the main entry point for the server.
 */
int main() {
  // Create a socket for the server
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Check if the socket was created successfully
  if (server_socket < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the socket options
  int optval = 1;
  setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

  // Bind the socket to the port
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address.sin_port = htons(PORT);

  if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
    perror("bind");
    close(server_socket);
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(server_socket, MAX_CONNECTIONS) < 0) {
    perror("listen");
    close(server_socket);
    return EXIT_FAILURE;
  }

  // Main loop
  while (1) {
    // Accept incoming connections
    int client_socket = accept(server_socket, NULL, NULL);

    // Check if the connection was accepted successfully
    if (client_socket < 0) {
      perror("accept");
      continue;
    }

    // Handle the request from the client
    handle_request(client_socket);
  }

  // Close the server socket
  close(server_socket);

  return EXIT_SUCCESS;
}