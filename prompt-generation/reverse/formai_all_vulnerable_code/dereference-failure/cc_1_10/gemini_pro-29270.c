//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

// Handle a client request
void handle_client(int client_socket) {
  char request[1024];
  char response[1024];

  // Read the request from the client
  int bytes_received = recv(client_socket, request, 1024, 0);

  // Check if the client closed the connection
  if (bytes_received == 0) {
    return;
  }

  // Parse the request
  char *method = strtok(request, " ");
  char *path = strtok(NULL, " ");
  char *version = strtok(NULL, "\r\n");

  // Check if the request is valid
  if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
    send(client_socket, "HTTP/1.1 400 Bad Request\n\n", 27, 0);
    return;
  }

  // Send the response
  sprintf(response, "HTTP/1.1 200 OK\n\nHello, world!\n");
  send(client_socket, response, strlen(response), 0);
}

// Main function
int main() {
  // Create a socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Check if the socket was created successfully
  if (server_socket == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Bind the socket to an address
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8080);
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);

  // Check if the socket was bound successfully
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(server_socket, 5) == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  printf("Server is listening on port 8080.\n");

  // Main loop
  while (1) {
    // Accept a new connection
    int client_socket = accept(server_socket, NULL, NULL);

    // Check if the connection was accepted successfully
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Handle the client request
    handle_client(client_socket);

    // Close the client socket
    close(client_socket);
  }

  // Close the server socket
  close(server_socket);

  return EXIT_SUCCESS;
}