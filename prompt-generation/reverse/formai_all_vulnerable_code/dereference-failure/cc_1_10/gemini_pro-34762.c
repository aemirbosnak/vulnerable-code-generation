//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

static void handle_client(int client_socket, int server_socket) {
  char buffer[BUFFER_SIZE];
  int bytes_read, bytes_sent;

  // Read the request from the client
  memset(buffer, 0, BUFFER_SIZE);
  bytes_read = read(client_socket, buffer, BUFFER_SIZE - 1);
  if (bytes_read <= 0) {
    return;
  }

  // Send the request to the server
  bytes_sent = write(server_socket, buffer, bytes_read);
  if (bytes_sent <= 0) {
    return;
  }

  // Read the response from the server
  memset(buffer, 0, BUFFER_SIZE);
  bytes_read = read(server_socket, buffer, BUFFER_SIZE - 1);
  if (bytes_read <= 0) {
    return;
  }

  // Send the response to the client
  bytes_sent = write(client_socket, buffer, bytes_read);
  if (bytes_sent <= 0) {
    return;
  }
}

int main(int argc, char *argv[]) {
  int client_socket, server_socket;
  struct sockaddr_in client_address, server_address;

  // Create the client socket
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Create the server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Bind the client socket to the client address
  memset(&client_address, 0, sizeof(client_address));
  client_address.sin_family = AF_INET;
  client_address.sin_port = htons(atoi(argv[1]));
  client_address.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(client_socket, (struct sockaddr *)&client_address, sizeof(client_address)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Bind the server socket to the server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(atoi(argv[2]));
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen on the client socket
  if (listen(client_socket, 5) == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept connections on the client socket
  while (1) {
    int new_client_socket = accept(client_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address);
    if (new_client_socket == -1) {
      perror("accept");
      continue;
    }

    // Handle the client
    handle_client(new_client_socket, server_socket);

    // Close the new client socket
    close(new_client_socket);
  }

  // Close the client socket
  close(client_socket);

  // Close the server socket
  close(server_socket);

  return EXIT_SUCCESS;
}