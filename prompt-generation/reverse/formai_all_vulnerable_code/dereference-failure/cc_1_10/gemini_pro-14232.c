//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  // Get the host and port from the command line arguments.
  char *host = argv[1];
  int port = atoi(argv[2]);

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  // Get the host IP address.
  struct hostent *hostent = gethostbyname(host);
  if (hostent == NULL) {
    perror("gethostbyname");
    return 1;
  }

  // Set up the server address.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr = *(struct in_addr *)hostent->h_addr;

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send a HTTP GET request to the server.
  char request[] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the HTTP response from the server.
  char buffer[MAX_BUFFER_SIZE];
  int bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
  if (bytes_received < 0) {
    perror("recv");
    return 1;
  }

  // Print the HTTP response to the console.
  printf("%s", buffer);

  // Close the socket.
  close(sockfd);

  return 0;
}