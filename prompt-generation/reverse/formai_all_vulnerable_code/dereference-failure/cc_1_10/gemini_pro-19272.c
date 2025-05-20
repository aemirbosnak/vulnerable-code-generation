//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
  int server_fd, client_fd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[1024];
  int len;

  // Create a TCP socket
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("socket");
    exit(1);
  }

  // Set the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // Bind the socket to the server address
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(server_fd, 5) < 0) {
    perror("listen");
    exit(1);
  }

  // Main loop: accept connections and handle requests
  while (1) {
    // Accept a connection from a client
    len = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &len);
    if (client_fd < 0) {
      perror("accept");
      continue;
    }

    // Read the HTTP request from the client
    len = recv(client_fd, buffer, sizeof(buffer), 0);
    if (len < 0) {
      perror("recv");
      close(client_fd);
      continue;
    }

    // Parse the HTTP request
    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *protocol = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (strcmp(method, "GET") != 0 || strcmp(protocol, "HTTP/1.1") != 0) {
      // Send a 400 Bad Request response
      char *response = "HTTP/1.1 400 Bad Request\r\nContent-Length: 0\r\n\r\n";
      send(client_fd, response, strlen(response), 0);
      close(client_fd);
      continue;
    }

    // Send a 200 OK response
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 11\r\n\r\nHello World!";
    send(client_fd, response, strlen(response), 0);

    // Close the connection with the client
    close(client_fd);
  }

  // Close the server socket
  close(server_fd);

  return 0;
}