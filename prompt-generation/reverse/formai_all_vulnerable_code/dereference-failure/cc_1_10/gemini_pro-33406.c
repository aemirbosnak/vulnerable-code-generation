//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Defines the maximum size of the HTTP request and response buffers.
#define MAX_BUFFER_SIZE 1024

// Defines the HTTP request and response headers.
const char *HTTP_GET_REQUEST_HEADER = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
const char *HTTP_OK_RESPONSE_HEADER = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";

// Main function.
int main(int argc, char *argv[]) {
  // Parse the command-line arguments.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Convert the port number to an integer.
  int port = atoi(argv[1]);

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Bind the socket to the port.
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(port);
  if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections.
  if (listen(sockfd, 5) == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept an incoming connection.
  int connfd = accept(sockfd, (struct sockaddr *) NULL, NULL);
  if (connfd == -1) {
    perror("accept");
    return EXIT_FAILURE;
  }

  // Send the HTTP request to the server.
  if (send(connfd, HTTP_GET_REQUEST_HEADER, strlen(HTTP_GET_REQUEST_HEADER), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the HTTP response from the server.
  char buffer[MAX_BUFFER_SIZE];
  ssize_t nbytes = recv(connfd, buffer, MAX_BUFFER_SIZE, 0);
  if (nbytes == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the HTTP response to the console.
  printf("%s", buffer);

  // Close the connection.
  close(connfd);
  close(sockfd);

  return EXIT_SUCCESS;
}