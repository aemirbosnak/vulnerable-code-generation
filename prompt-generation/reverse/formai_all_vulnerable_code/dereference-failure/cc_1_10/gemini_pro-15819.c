//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the port number for the server
#define PORT 8080

// Function to handle client requests
void handle_client(int client_socket) {
  // Buffer to receive client request
  char request[1024];

  // Receive the request from the client
  recv(client_socket, request, sizeof(request), 0);

  // Extract the HTTP method and path from the request
  char *method = strtok(request, " ");
  char *path = strtok(NULL, " ");

  // Handle different HTTP methods
  if (strcmp(method, "GET") == 0) {
    // Send a 200 OK response with the default page
    char response[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>";
    send(client_socket, response, strlen(response), 0);
  } else {
    // Send a 405 Method Not Allowed response
    char response[] = "HTTP/1.1 405 Method Not Allowed\nContent-Type: text/html\n\n<html><body><h1>405 Method Not Allowed</h1></body></html>";
    send(client_socket, response, strlen(response), 0);
  }

  // Close the client socket
  close(client_socket);
}

int main() {
  // Create a server socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Bind the socket to the port
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);
  bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

  // Listen for incoming client connections
  listen(server_socket, 5);

  while (1) {
    // Accept incoming client connections
    int client_socket = accept(server_socket, NULL, NULL);

    // Handle the client request in a separate thread
    pthread_t thread;
    pthread_create(&thread, NULL, (void *)handle_client, (void *)client_socket);
  }

  // Close the server socket
  close(server_socket);

  return 0;
}