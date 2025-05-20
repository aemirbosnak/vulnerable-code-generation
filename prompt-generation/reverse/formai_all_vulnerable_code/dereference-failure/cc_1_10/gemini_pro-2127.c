//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
  // Create a socket
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("socket");
    return 1;
  }

  // Set up the socket address structure
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // Bind the socket to the address
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    return 1;
  }

  // Listen for incoming connections
  if (listen(server_fd, 5) < 0) {
    perror("listen");
    return 1;
  }

  // Accept incoming connections
  while (1) {
    int client_fd = accept(server_fd, NULL, NULL);
    if (client_fd < 0) {
      perror("accept");
      continue;
    }

    // Handle the client request
    char request[1024];
    memset(request, 0, 1024);
    if (recv(client_fd, request, 1023, 0) < 0) {
      perror("recv");
      close(client_fd);
      continue;
    }

    // Parse the request
    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Send a response
    char response[1024];
    memset(response, 0, 1024);
    if (strcmp(path, "/") == 0) {
      sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Welcome to my website!</h1>");
    } else {
      sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<h1>404 Not Found</h1>");
    }

    if (send(client_fd, response, strlen(response), 0) < 0) {
      perror("send");
      close(client_fd);
      continue;
    }

    // Close the client connection
    close(client_fd);
  }

  // Close the server socket
  close(server_fd);

  return 0;
}