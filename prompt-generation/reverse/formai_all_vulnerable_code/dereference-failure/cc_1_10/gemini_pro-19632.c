//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define SERVER_PORT 80
#define MAX_REQUEST_SIZE 4096

// Function to send an HTTP request to a server and receive the response
int send_http_request(const char *hostname, const char *path, char *response) {
  // Create a socket for the HTTP request
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  // Get the IP address of the server
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname");
    close(sockfd);
    return -1;
  }

  // Create the socket address for the server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  server_addr.sin_addr = *((struct in_addr *)host->h_addr);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    close(sockfd);
    return -1;
  }

  // Create the HTTP request
  char request[MAX_REQUEST_SIZE];
  snprintf(request, MAX_REQUEST_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

  // Send the HTTP request to the server
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    close(sockfd);
    return -1;
  }

  // Receive the HTTP response from the server
  int bytes_received = 0;
  while ((bytes_received = recv(sockfd, response, MAX_REQUEST_SIZE, 0)) > 0) {
    response += bytes_received;
  }
  if (bytes_received == -1) {
    perror("recv");
    close(sockfd);
    return -1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s hostname path\n", argv[0]);
    return 1;
  }

  // Send the HTTP request to the server
  char response[MAX_REQUEST_SIZE];
  if (send_http_request(argv[1], argv[2], response) == -1) {
    return 1;
  }

  // Print the HTTP response
  printf("%s\n", response);

  return 0;
}