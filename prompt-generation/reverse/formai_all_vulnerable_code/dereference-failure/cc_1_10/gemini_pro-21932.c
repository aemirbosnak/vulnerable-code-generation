//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Parses the HTTP response and prints the body
void parse_response(char *response) {
  // Skip the HTTP header
  char *body = strstr(response, "\r\n\r\n");
  if (body == NULL) {
    printf("Error: Invalid HTTP response\n");
    return;
  }

  // Print the body
  body += 4;  // Skip the "\r\n\r\n"
  printf("%s", body);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the hostname and port
  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the server
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return EXIT_FAILURE;
  }
  if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the HTTP request
  char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the HTTP response
  char response[4096];
  int recvlen = recv(sockfd, response, sizeof(response), 0);
  if (recvlen < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Parse the HTTP response
  parse_response(response);

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}