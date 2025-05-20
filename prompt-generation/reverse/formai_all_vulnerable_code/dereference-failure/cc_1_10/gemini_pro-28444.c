//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define IMAP_PORT 143

int main(int argc, char **argv) {
  int sockfd = -1;
  int ret = -1;
  struct sockaddr_in server_addr = {0};
  char buf[1024] = {0};
  struct timeval timeout = {10, 0};

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create a TCP socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Set the socket to non-blocking mode
  if (fcntl(sockfd, F_SETFL, O_NONBLOCK) == -1) {
    fprintf(stderr, "Error setting socket to non-blocking mode: %s\n", strerror(errno));
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  // Set the socket timeout
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
    fprintf(stderr, "Error setting socket timeout: %s\n", strerror(errno));
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  // Resolve the server's hostname
  struct hostent *hostent = gethostbyname(argv[1]);
  if (hostent == NULL) {
    fprintf(stderr, "Error resolving server hostname: %s\n", strerror(errno));
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  // Set the server's address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(IMAP_PORT);
  memcpy(&server_addr.sin_addr, hostent->h_addr_list[0], sizeof(server_addr.sin_addr));

  // Connect to the server
  ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (ret == -1 && errno != EINPROGRESS) {
    fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  // Send the username to the server
  sprintf(buf, "USER %s\r\n", argv[2]);
  ret = send(sockfd, buf, strlen(buf), 0);
  if (ret == -1) {
    fprintf(stderr, "Error sending username to server: %s\n", strerror(errno));
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  // Receive the server's response
  ret = recv(sockfd, buf, sizeof(buf), 0);
  if (ret == -1) {
    fprintf(stderr, "Error receiving server's response: %s\n", strerror(errno));
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  // Print the server's response
  printf("%s", buf);

  // Close the socket
  close(sockfd);

  return 0;
}