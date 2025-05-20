//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the maximum size of the request and response buffers
#define MAX_BUFFER_SIZE 1024

// Define the default port number for the proxy server
#define DEFAULT_PORT 8080

// Define the default hostname for the proxy server
#define DEFAULT_HOSTNAME "localhost"

// Function to handle incoming client connections
void handle_client(int client_socket) {
  // Declare the request and response buffers
  char request[MAX_BUFFER_SIZE];
  char response[MAX_BUFFER_SIZE];

  // Receive the request from the client
  int request_length = recv(client_socket, request, MAX_BUFFER_SIZE, 0);
  if (request_length <= 0) {
    perror("Error receiving request from client");
    close(client_socket);
    return;
  }

  // Parse the request to get the target hostname and port number
  char *hostname = strtok(request, " ");
  char *port = strtok(NULL, " ");

  // Convert the port number to an integer
  int port_number = atoi(port);

  // Create a socket to connect to the target server
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    perror("Error creating socket");
    close(client_socket);
    return;
  }

  // Set the target server's address and port number
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr(hostname);
  server_address.sin_port = htons(port_number);

  // Connect to the target server
  if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Error connecting to server");
    close(client_socket);
    close(server_socket);
    return;
  }

  // Send the request to the target server
  if (send(server_socket, request, request_length, 0) < 0) {
    perror("Error sending request to server");
    close(client_socket);
    close(server_socket);
    return;
  }

  // Receive the response from the target server
  int response_length = recv(server_socket, response, MAX_BUFFER_SIZE, 0);
  if (response_length <= 0) {
    perror("Error receiving response from server");
    close(client_socket);
    close(server_socket);
    return;
  }

  // Send the response to the client
  if (send(client_socket, response, response_length, 0) < 0) {
    perror("Error sending response to client");
    close(client_socket);
    close(server_socket);
    return;
  }

  // Close the client and server sockets
  close(client_socket);
  close(server_socket);
}

int main(int argc, char *argv[]) {
  // Parse the command-line arguments
  int port = DEFAULT_PORT;
  char *hostname = DEFAULT_HOSTNAME;

  if (argc > 1) {
    port = atoi(argv[1]);
  }

  if (argc > 2) {
    hostname = argv[2];
  }

  // Create a socket to listen for incoming client connections
  int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (listening_socket < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Set the listening socket's address and port number
  struct sockaddr_in listening_address;
  memset(&listening_address, 0, sizeof(listening_address));
  listening_address.sin_family = AF_INET;
  listening_address.sin_addr.s_addr = INADDR_ANY;
  listening_address.sin_port = htons(port);

  // Bind the listening socket to the address and port
  if (bind(listening_socket, (struct sockaddr *)&listening_address, sizeof(listening_address)) < 0) {
    perror("Error binding socket");
    close(listening_socket);
    exit(1);
  }

  // Listen for incoming client connections
  if (listen(listening_socket, 5) < 0) {
    perror("Error listening for connections");
    close(listening_socket);
    exit(1);
  }

  printf("Proxy server listening on port %d\n", port);

  // Accept incoming client connections and handle them
  while (1) {
    int client_socket = accept(listening_socket, NULL, NULL);
    if (client_socket < 0) {
      perror("Error accepting connection");
      continue;
    }

    handle_client(client_socket);
  }

  // Close the listening socket
  close(listening_socket);

  return 0;
}