//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024
#define MAX_SOCKET_BUFFER_SIZE 1024 * 1024

// Create a socket and connect to the specified host and port
int create_socket(char *host, int port) {
  struct sockaddr_in server_addr;
  int sockfd;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  // Set the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(host);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  return sockfd;
}

// Send an HTTP request to the specified socket
void send_request(int sockfd, char *request) {
  int n;

  // Send the request
  n = write(sockfd, request, strlen(request));
  if (n < 0) {
    perror("write");
    exit(1);
  }
}

// Receive an HTTP response from the specified socket
char *receive_response(int sockfd) {
  int n;
  char *response = malloc(MAX_SOCKET_BUFFER_SIZE);

  // Receive the response
  n = read(sockfd, response, MAX_SOCKET_BUFFER_SIZE);
  if (n < 0) {
    perror("read");
    exit(1);
  }

  // Null-terminate the response
  response[n] = '\0';

  return response;
}

// Print the HTTP response
void print_response(char *response) {
  printf("%s\n", response);
}

// Close the specified socket
void close_socket(int sockfd) {
  close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
  int sockfd;
  char *request;
  char *response;

  // Check if the user specified a host and port
  if (argc < 3) {
    printf("Usage: %s <host> <port>\n", argv[0]);
    exit(1);
  }

  // Create a request
  request = malloc(MAX_LINE);
  sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);

  // Create a socket and connect to the server
  sockfd = create_socket(argv[1], atoi(argv[2]));

  // Send the request
  send_request(sockfd, request);

  // Receive the response
  response = receive_response(sockfd);

  // Print the response
  print_response(response);

  // Close the socket
  close_socket(sockfd);

  return 0;
}