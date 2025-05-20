//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

// Function to handle client requests
void handle_client(int client_socket) {
  // Receive the request from the client
  char buffer[MAX_BUFFER_SIZE];
  int bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);

  // If the client closed the connection, exit
  if (bytes_received == 0) {
    printf("Client closed the connection\n");
    close(client_socket);
    return;
  }

  // Parse the request
  char *method = strtok(buffer, " ");
  char *path = strtok(NULL, " ");
  char *version = strtok(NULL, "\r\n");

  // If the method is not GET, return an error
  if (strcmp(method, "GET") != 0) {
    char *error_response = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
    send(client_socket, error_response, strlen(error_response), 0);
    close(client_socket);
    return;
  }

  // Connect to the remote server
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(80);
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    printf("Error connecting to the remote server\n");
    close(client_socket);
    close(server_socket);
    return;
  }

  // Send the request to the remote server
  send(server_socket, buffer, bytes_received, 0);

  // Receive the response from the remote server
  char server_buffer[MAX_BUFFER_SIZE];
  int server_bytes_received = recv(server_socket, server_buffer, MAX_BUFFER_SIZE, 0);

  // If the remote server closed the connection, exit
  if (server_bytes_received == 0) {
    printf("Remote server closed the connection\n");
    close(client_socket);
    close(server_socket);
    return;
  }

  // Send the response to the client
  send(client_socket, server_buffer, server_bytes_received, 0);

  // Close the connections
  close(client_socket);
  close(server_socket);
}

int main() {
  // Create a listening socket
  int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in listening_address;
  listening_address.sin_family = AF_INET;
  listening_address.sin_port = htons(8080);
  listening_address.sin_addr.s_addr = INADDR_ANY;

  if (bind(listening_socket, (struct sockaddr *)&listening_address, sizeof(listening_address)) < 0) {
    printf("Error binding to the listening socket\n");
    return 1;
  }

  // Start listening for connections
  if (listen(listening_socket, 5) < 0) {
    printf("Error listening for connections\n");
    return 1;
  }

  // Accept connections and handle them
  while (1) {
    int client_socket = accept(listening_socket, NULL, NULL);
    if (client_socket < 0) {
      printf("Error accepting connection\n");
      continue;
    }

    handle_client(client_socket);
  }

  // Close the listening socket
  close(listening_socket);

  return 0;
}