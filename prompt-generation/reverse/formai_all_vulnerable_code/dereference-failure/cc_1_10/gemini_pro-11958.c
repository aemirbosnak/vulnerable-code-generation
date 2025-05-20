//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: unmistakable
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Define the maximum request size
#define MAX_REQUEST_SIZE 4096

// Define the proxy server's port
#define PROXY_PORT 8080

// Define the newline character
#define CRLF "\r\n"

// Function to handle client requests
void handle_client(int client_socket) {
  // Buffer to store the client's request
  char request[MAX_REQUEST_SIZE];

  // Read the client's request
  int bytes_read = read(client_socket, request, MAX_REQUEST_SIZE);
  if (bytes_read == -1) {
    perror("Error reading client request");
    return;
  }

  // Parse the client's request
  char *method = strtok(request, " ");
  char *path = strtok(NULL, " ");
  char *version = strtok(NULL, CRLF);

  // Check if the request is a valid HTTP request
  if (strcmp(method, "GET") != 0) {
    // Send an error response to the client
    char *error_response =
        "HTTP/1.1 400 Bad Request" CRLF
        "Content-Type: text/plain" CRLF
        "Content-Length: 13" CRLF
        CRLF
        "Bad Request";

    write(client_socket, error_response, strlen(error_response));
    return;
  }

  // Parse the host header
  char *host = NULL;
  char *header = strstr(request, "Host:");
  if (header != NULL) {
    host = strtok(header + 6, CRLF);
  }

  // Check if the host header is present
  if (host == NULL) {
    // Send an error response to the client
    char *error_response =
        "HTTP/1.1 400 Bad Request" CRLF
        "Content-Type: text/plain" CRLF
        "Content-Length: 20" CRLF
        CRLF
        "Host header missing";

    write(client_socket, error_response, strlen(error_response));
    return;
  }

  // Connect to the remote server
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(80);
  inet_pton(AF_INET, host, &server_address.sin_addr);

  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Error creating server socket");
    return;
  }

  if (connect(server_socket, (struct sockaddr *)&server_address,
              sizeof(server_address)) == -1) {
    perror("Error connecting to server");
    return;
  }

  // Send the client's request to the remote server
  write(server_socket, request, strlen(request));

  // Receive the server's response
  char response[MAX_REQUEST_SIZE];
  bytes_read = read(server_socket, response, MAX_REQUEST_SIZE);
  if (bytes_read == -1) {
    perror("Error reading server response");
    return;
  }

  // Send the server's response to the client
  write(client_socket, response, strlen(response));

  // Close the client socket
  close(client_socket);

  // Close the server socket
  close(server_socket);
}

int main() {
  // Create a listening socket
  int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (listening_socket == -1) {
    perror("Error creating listening socket");
    return 1;
  }

  // Bind the listening socket to the proxy server's port
  struct sockaddr_in listening_address;
  memset(&listening_address, 0, sizeof(listening_address));
  listening_address.sin_family = AF_INET;
  listening_address.sin_port = htons(PROXY_PORT);
  listening_address.sin_addr.s_addr = INADDR_ANY;

  if (bind(listening_socket, (struct sockaddr *)&listening_address,
             sizeof(listening_address)) == -1) {
    perror("Error binding listening socket");
    return 1;
  }

  // Listen for incoming client connections
  if (listen(listening_socket, 5) == -1) {
    perror("Error listening for client connections");
    return 1;
  }

  // Accept incoming client connections
  while (1) {
    int client_socket = accept(listening_socket, NULL, NULL);
    if (client_socket == -1) {
      perror("Error accepting client connection");
      continue;
    }

    // Handle the client request in a separate thread
    int *client_socket_ptr = malloc(sizeof(int));
    *client_socket_ptr = client_socket;
    pthread_t client_thread;
    pthread_create(&client_thread, NULL, (void *)handle_client,
                    (void *)client_socket_ptr);
  }

  // Close the listening socket
  close(listening_socket);

  return 0;
}