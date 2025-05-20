//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_PORT 143

int main(int argc, char **argv) {
  int sockfd;
  struct sockaddr_in servaddr;
  char buf[1024];

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <username>\n", argv[0]);
    exit(1);
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Connect to the server
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "Error resolving hostname: %s\n", argv[1]);
    exit(1);
  }
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(IMAP_PORT);
  servaddr.sin_addr = *(struct in_addr *)host->h_addr;
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    exit(1);
  }

  // Send the login command
  sprintf(buf, "LOGIN %s\r\n", argv[2]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Receive the response
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    exit(1);
  }

  // Display the response
  printf("%s", buf);

  // Close the socket
  close(sockfd);

  return 0;
}