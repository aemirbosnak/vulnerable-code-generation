//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

#define SERVER "smtp.server.com"
#define PORT "25"

int main(int argc, char *argv[]) {
  struct addrinfo hints, *res;
  int sockfd;

  // Set up the hints struct to filter results
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  // Try to get address info for the SMTP server
  if (getaddrinfo(SERVER, PORT, &hints, &res) != 0) {
    printf("getaddrinfo() failed\n");
    return 1;
  }
  
  // Attempt to create a socket
  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sockfd == -1) {
    printf("socket() failed\n");
    return 2;
  }

  // Connect to the SMTP server
  if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
    printf("connect() failed\n");
    return 3;
  }

  // Read the server's response
  char response[1024];
  if (recv(sockfd, response, sizeof(response), 0) == -1) {
    printf("recv() failed\n");
    return 4;
  }

  printf("%s", response);

  // Clean up
  freeaddrinfo(res);
  close(sockfd);

  return 0;
}