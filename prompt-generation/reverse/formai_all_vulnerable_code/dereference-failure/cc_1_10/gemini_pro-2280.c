//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 4096

int main(int argc, char *argv[]) {
  // Check the command line arguments
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <server IP address> <server port> <email address>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Create a socket
  int sockfd;
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the server
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return EXIT_FAILURE;
  }
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the email address to the server
  if (send(sockfd, argv[3], strlen(argv[3]), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the email from the server
  char buf[MAX_LINE];
  memset(buf, 0, sizeof(buf));
  if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the email
  printf("%s\n", buf);

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}