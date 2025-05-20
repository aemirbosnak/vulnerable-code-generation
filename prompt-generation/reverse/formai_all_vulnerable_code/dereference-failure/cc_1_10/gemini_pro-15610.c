//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define HTTP_PORT 8080
#define MAX_CONTENT_LENGTH 1024

void handle_request(int client_socket) {
  // Read the HTTP request from the client
  char request[MAX_CONTENT_LENGTH];
  int bytes_received = recv(client_socket, request, MAX_CONTENT_LENGTH, 0);
  if (bytes_received == -1) {
    perror("Error receiving request");
    close(client_socket);
    return;
  }

  // Parse the HTTP request
  char *method = strtok(request, " ");
  char *uri = strtok(NULL, " ");
  char *version = strtok(NULL, "\r\n");

  // Print the request info
  printf("Received request:\n");
  printf("Method: %s\n", method);
  printf("URI: %s\n", uri);
  printf("Version: %s\n", version);

  // Handle the request
  if (strcmp(method, "GET") == 0) {
    // Send a 200 OK response
    char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, world!</h1>";
    send(client_socket, response, sizeof(response), 0);
  } else {
    // Send a 405 Method Not Allowed response
    char response[] = "HTTP/1.1 405 Method Not Allowed\r\nContent-Type: text/html\r\n\r\n<h1>405 Method Not Allowed</h1>";
    send(client_socket, response, sizeof(response), 0);
  }

  // Close the client socket
  close(client_socket);
}

int main() {
  // Create a listening socket
  int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_socket == -1) {
    perror("Error creating listening socket");
    return 1;
  }

  // Bind the listening socket to the HTTP port
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(HTTP_PORT);
  addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(listen_socket, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
    perror("Error binding listening socket");
    close(listen_socket);
    return 1;
  }

  // Listen for incoming connections
  if (listen(listen_socket, 5) == -1) {
    perror("Error listening for incoming connections");
    close(listen_socket);
    return 1;
  }

  // Accept incoming connections
  while (1) {
    int client_socket = accept(listen_socket, NULL, NULL);
    if (client_socket == -1) {
      perror("Error accepting incoming connection");
      continue;
    }

    // Handle the request in a separate thread
    handle_request(client_socket);
  }

  // Close the listening socket
  close(listen_socket);

  return 0;
}