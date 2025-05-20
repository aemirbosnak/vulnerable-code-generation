//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8080

int main() {
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char *response, *file;

  // Create a socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Set socket options
  int opt = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Set socket to non-blocking
  if (fcntl(server_fd, F_SETFL, O_NONBLOCK) < 0) {
    perror("fcntl");
    exit(EXIT_FAILURE);
  }

  // Set server address
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Bind socket to address
  if (bind(server_fd, (struct sockaddr *)&address, addrlen) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for connections
  if (listen(server_fd, 10) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  while (1) {
    // Accept connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
      if (errno == EAGAIN || errno == EWOULDBLOCK) {
        continue;
      } else {
        perror("accept failed");
        exit(EXIT_FAILURE);
      }
    }

    // Read HTTP request
    valread = read(new_socket, buffer, 1024);

    // Parse HTTP request
    response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, world!</h1></body></html>";

    // Write HTTP response
    write(new_socket, response, strlen(response));

    // Close connection
    close(new_socket);
  }

  return 0;
}