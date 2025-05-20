//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <url>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Parse the URL
  char *url = argv[1];
  char *host = strtok(url, "/");
  char *path = strtok(NULL, "");

  if (!host || !path) {
    printf("Invalid URL\n");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);

  if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
    printf("Invalid address\n");
    exit(EXIT_FAILURE);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send the HTTP request
  char request[BUFFER_SIZE];
  snprintf(request, BUFFER_SIZE, "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the response
  char response[BUFFER_SIZE];
  int total_bytes = 0;
  int bytes_received;

  do {
    bytes_received = recv(sockfd, response + total_bytes, BUFFER_SIZE - total_bytes, 0);
    if (bytes_received < 0) {
      perror("recv");
      exit(EXIT_FAILURE);
    }
    total_bytes += bytes_received;
  } while(bytes_received > 0);

  // Print the response
  printf("HTTP Response:\n%s\n", response);

  // Close the socket
  close(sockfd);

  return 0;
}