//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

  // Step 1: Get the host name and port number from the command line arguments.
  if (argc != 3) {
    fprintf(stderr, "Usage: %s host port\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *host = argv[1];
  int port = atoi(argv[2]);

  // Step 2: Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("error creating socket");
    exit(EXIT_FAILURE);
  }

  // Step 3: Find the IP address of the host.
  struct hostent *server = gethostbyname(host);
  if (server == NULL) {
    fprintf(stderr, "error: no such host\n");
    exit(EXIT_FAILURE);
  }

  // Step 4: Set up the socket address.
  struct sockaddr_in serveraddr;
  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  memcpy(&serveraddr.sin_addr.s_addr, server->h_addr, server->h_length);
  serveraddr.sin_port = htons(port);

  // Step 5: Connect to the server.
  if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
    perror("error connecting to server");
    exit(EXIT_FAILURE);
  }

  // Step 6: Build the HTTP request.
  char request[BUFFER_SIZE];
  snprintf(request, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);

  // Step 7: Send the HTTP request to the server.
  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("error sending request to server");
    exit(EXIT_FAILURE);
  }

  // Step 8: Receive the HTTP response from the server.
  char response[BUFFER_SIZE];
  int total = 0;
  for (;;) {
    int bytes_received = recv(sockfd, response + total, BUFFER_SIZE - total, 0);
    if (bytes_received < 0) {
      perror("error receiving response from server");
      exit(EXIT_FAILURE);
    } else if (bytes_received == 0) {
      break;
    } else {
      total += bytes_received;
      if (total >= BUFFER_SIZE) {
        fprintf(stderr, "error: response too large\n");
        exit(EXIT_FAILURE);
      }
    }
  }

  // Step 9: Print the HTTP response.
  printf("%s\n", response);

  // Step 10: Close the socket and return.
  close(sockfd);
  return 0;
}