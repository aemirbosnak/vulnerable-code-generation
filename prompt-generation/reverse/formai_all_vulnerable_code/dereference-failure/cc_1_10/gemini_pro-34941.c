//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the maximum number of clients that can connect to the server
#define MAX_CLIENTS 10

// Define the maximum size of a request that the server can handle
#define MAX_REQUEST_SIZE 1024

// Define the port that the server will listen on
#define PORT 8080

// Define the root directory of the server
#define ROOT_DIR "/var/www/html"

// Function to handle client requests
void handle_client(int client_socket) {
  // Read the client's request
  char request[MAX_REQUEST_SIZE];
  int bytes_received = recv(client_socket, request, MAX_REQUEST_SIZE, 0);
  if (bytes_received < 0) {
    perror("recv");
    return;
  }

  // Parse the client's request
  char *method = strtok(request, " ");
  char *path = strtok(NULL, " ");
  char *version = strtok(NULL, "\r\n");

  // Check if the client's request is valid
  if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
    // Send a 400 Bad Request response
    char *response = "HTTP/1.1 400 Bad Request\r\n\r\n";
    send(client_socket, response, strlen(response), 0);
    return;
  }

  // Get the file that the client is requesting
  char file_path[strlen(ROOT_DIR) + strlen(path) + 1];
  strcpy(file_path, ROOT_DIR);
  strcat(file_path, path);

  // Open the file
  FILE *file = fopen(file_path, "r");
  if (file == NULL) {
    // Send a 404 Not Found response
    char *response = "HTTP/1.1 404 Not Found\r\n\r\n";
    send(client_socket, response, strlen(response), 0);
    return;
  }

  // Send the file to the client
  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    send(client_socket, buffer, strlen(buffer), 0);
  }

  // Close the file
  fclose(file);

  // Send a 200 OK response
  char *response = "HTTP/1.1 200 OK\r\n\r\n";
  send(client_socket, response, strlen(response), 0);
}

int main() {
  // Create a socket for listening for client connections
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    perror("socket");
    return 1;
  }

  // Set the socket options
  int optval = 1;
  setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

  // Bind the socket to the port
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);
  if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
    perror("bind");
    return 1;
  }

  // Listen for client connections
  if (listen(server_socket, MAX_CLIENTS) < 0) {
    perror("listen");
    return 1;
  }

  // Accept client connections
  while (1) {
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);
    if (client_socket < 0) {
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

  return 0;
}