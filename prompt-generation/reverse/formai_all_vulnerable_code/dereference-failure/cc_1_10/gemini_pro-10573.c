//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Bind the socket to the address and port
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    close(sock);
    return 1;
  }

  // Listen for incoming connections
  if (listen(sock, 5) < 0) {
    perror("listen");
    close(sock);
    return 1;
  }

  // Accept incoming connections
  while (1) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock < 0) {
      perror("accept");
      continue;
    }

    // Handle the client request
    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);
    recv(client_sock, buf, BUF_SIZE, 0);

    // Parse the request
    char *method = strtok(buf, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Send the response
    char response[BUF_SIZE];
    memset(response, 0, BUF_SIZE);
    if (strcmp(method, "GET") == 0) {
      if (strcmp(path, "/") == 0) {
        // Return the home page
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Welcome to my website!</h1>");
      } else {
        // Return a 404 error
        sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<h1>404 Not Found</h1>");
      }
    } else {
      // Return a 501 error
      sprintf(response, "HTTP/1.1 501 Not Implemented\r\nContent-Type: text/html\r\n\r\n<h1>501 Not Implemented</h1>");
    }

    send(client_sock, response, strlen(response), 0);

    // Close the client socket
    close(client_sock);
  }

  // Close the server socket
  close(sock);

  return 0;
}