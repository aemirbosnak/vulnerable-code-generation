//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 4096

// Function to handle client connections
void handle_client(int client_socket) {
  // Read the HTTP request from the client
  char request[BUFFER_SIZE];
  int bytes_received = recv(client_socket, request, BUFFER_SIZE, 0);
  if (bytes_received < 0) {
    perror("Error receiving request from client");
    close(client_socket);
    return;
  }

  // Parse the HTTP request
  char *method = strtok(request, " ");
  char *path = strtok(NULL, " ");
  char *version = strtok(NULL, "\r\n");

  // Check if the request is valid
  if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
    // Send a 400 Bad Request response to the client
    char response[] = "HTTP/1.1 400 Bad Request\r\nContent-Length: 0\r\n\r\n";
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
    return;
  }

  // Send a 200 OK response to the client
  char response[] = "HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n";
  send(client_socket, response, strlen(response), 0);

  // Parse the Host header from the request
  char *host = strtok(request, "\r\n");
  while (host != NULL) {
    if (strncmp(host, "Host: ", 6) == 0) {
      host += 6;
      break;
    }
    host = strtok(NULL, "\r\n");
  }

  // Connect to the remote server
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(SERVER_PORT);
  inet_pton(AF_INET, host, &server_address.sin_addr);
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    perror("Error creating server socket");
    close(client_socket);
    return;
  }
  if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
    perror("Error connecting to server");
    close(client_socket);
    close(server_socket);
    return;
  }

  // Forward the request to the remote server
  send(server_socket, request, bytes_received, 0);

  // Receive the response from the remote server
  char response_buffer[BUFFER_SIZE];
  int bytes_read = 0;
  while ((bytes_read = recv(server_socket, response_buffer, BUFFER_SIZE, 0)) > 0) {
    // Send the response to the client
    send(client_socket, response_buffer, bytes_read, 0);
  }

  // Close the connections
  close(client_socket);
  close(server_socket);
}

int main() {
  // Create a listening socket
  int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (listening_socket < 0) {
    perror("Error creating listening socket");
    return EXIT_FAILURE;
  }

  // Bind the listening socket to the specified port
  struct sockaddr_in listening_address;
  memset(&listening_address, 0, sizeof(listening_address));
  listening_address.sin_family = AF_INET;
  listening_address.sin_port = htons(8080);
  listening_address.sin_addr.s_addr = INADDR_ANY;
  if (bind(listening_socket, (struct sockaddr *) &listening_address, sizeof(listening_address)) < 0) {
    perror("Error binding listening socket");
    close(listening_socket);
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(listening_socket, 5) < 0) {
    perror("Error listening for incoming connections");
    close(listening_socket);
    return EXIT_FAILURE;
  }

  // Accept incoming connections and handle them
  while (1) {
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    int client_socket = accept(listening_socket, (struct sockaddr *) &client_address, &client_address_length);
    if (client_socket < 0) {
      perror("Error accepting incoming connection");
      continue;
    }

    // Create a new thread to handle the client connection
    handle_client(client_socket);
  }

  // Close the listening socket
  close(listening_socket);

  return EXIT_SUCCESS;
}