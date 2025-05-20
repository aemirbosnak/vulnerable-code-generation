//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  // Initialize variables
  struct sockaddr_in serverAddr;
  struct hostent *server;
  int sockfd, port, len, numbytes;
  char buffer[BUFFER_SIZE];

  // Parse command line arguments
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    exit(1);
  }
  char *url = argv[1];

  // Resolve server address
  server = gethostbyname(url);
  if (server == NULL) {
    fprintf(stderr, "Error: Unknown host.\n");
    exit(1);
  }

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error: Unable to create socket.\n");
    exit(1);
  }

  // Connect to server
  port = ((struct sockaddr_in *)server->h_addr)->sin_port;
  len = sizeof(struct sockaddr_in);
  if (connect(sockfd, (struct sockaddr *)server->h_addr, len) < 0) {
    fprintf(stderr, "Error: Connection failed.\n");
    exit(1);
  }

  // Send HTTP request
  snprintf(buffer, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", url, url);
  numbytes = send(sockfd, buffer, strlen(buffer), 0);
  if (numbytes < 0) {
    fprintf(stderr, "Error: Failed to send request.\n");
    exit(1);
  }

  // Receive HTTP response
  memset(buffer, 0, BUFFER_SIZE);
  numbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (numbytes < 0) {
    fprintf(stderr, "Error: Failed to receive response.\n");
    exit(1);
  }

  // Print HTTP response
  printf("HTTP/1.1 %d %s\r\n", ((struct sockaddr_in *)server->h_addr)->sin_port, buffer);
  printf("%s", buffer);

  // Close socket
  close(sockfd);

  return 0;
}