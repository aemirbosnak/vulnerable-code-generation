//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent* server;

  // Check for command-line arguments
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get server hostname and port from command-line arguments
  server = gethostbyname(argv[1]);
  portno = atoi(argv[2]);

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    exit(EXIT_FAILURE);
  }

  // Zero-out server address struct
  memset(&serv_addr, 0, sizeof(serv_addr));

  // Set server address family, hostname, and port
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  // Connect to server
  if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    exit(EXIT_FAILURE);
  }

  // Send HTTP GET message
  char buffer[BUFFER_SIZE];
  sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Error writing to socket");
    exit(EXIT_FAILURE);
  }

  // Read HTTP response
  char response[BUFFER_SIZE];
  memset(response, 0, BUFFER_SIZE);
  n = read(sockfd, response, BUFFER_SIZE - 1);
  if (n < 0) {
    perror("Error reading from socket");
    exit(EXIT_FAILURE);
  }

  // Print HTTP response
  printf("%s\n", response);

  // Close socket
  close(sockfd);

  return EXIT_SUCCESS;
}