//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <server IP address> <port> <email address>\n", argv[0]);
    exit(1);
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  // Set the server address
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(1);
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Send the email address to the server
  char buffer[MAX_LINE];
  sprintf(buffer, "HELO %s\r\n", argv[3]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive the response from the server
  if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
    perror("recv");
    exit(1);
  }

  // Print the response to the console
  printf("%s\n", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}