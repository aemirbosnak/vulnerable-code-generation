//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: portable
// This program implements a simple TCP/IP echo server. It listens for incoming
// connections on a specified port and echoes back any data received from the
// client.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {
  // Check if the correct number of arguments have been provided.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return 1;
  }

  // Get the port number from the command line arguments.
  int port = atoi(argv[1]);

  // Create a socket.
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return 1;
  }

  // Set the socket to be reusable. This allows us to restart the server without
  // having to wait for the TIME_WAIT state to expire.
  int reuseaddr = 1;
  if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr)) == -1) {
    perror("setsockopt");
    return 1;
  }

  // Bind the socket to the specified port.
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port);
  if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
    perror("bind");
    return 1;
  }

  // Listen for incoming connections.
  if (listen(server_socket, 5) == -1) {
    perror("listen");
    return 1;
  }

  // Accept incoming connections.
  while (1) {
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_length);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Read data from the client.
    char buffer[1024];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
      perror("recv");
      continue;
    }

    // Echo the data back to the client.
    if (send(client_socket, buffer, bytes_received, 0) == -1) {
      perror("send");
      continue;
    }

    // Close the client socket.
    close(client_socket);
  }

  // Close the server socket.
  close(server_socket);

  return 0;
}