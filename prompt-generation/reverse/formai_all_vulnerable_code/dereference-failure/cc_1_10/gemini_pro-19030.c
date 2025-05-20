//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: safe
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define DEFAULT_PORT 80
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in serv_addr;
  char buf[MAX_BUF_SIZE];
  memset(buf, 0, MAX_BUF_SIZE);

  // Check if the correct number of arguments were provided
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the socket to non-blocking mode
  int flags = fcntl(sockfd, F_GETFL, 0);
  if (flags == -1) {
    perror("fcntl");
    goto cleanup;
  }
  if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
    perror("fcntl");
    goto cleanup;
  }

  // Resolve the hostname
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    herror("gethostbyname");
    goto cleanup;
  }

  // Set up the server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[2]));
  memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
    if (errno != EINPROGRESS) {
      perror("connect");
      goto cleanup;
    }
  }

  // Send a message to the server
  const char *msg = "Hello, world!\n";
  if (send(sockfd, msg, strlen(msg), 0) == -1) {
    perror("send");
    goto cleanup;
  }

  // Receive a message from the server
  int n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (n == -1) {
    perror("recv");
    goto cleanup;
  }

  // Print the message from the server
  printf("Received from server: %s\n", buf);

cleanup:
  close(sockfd);
  return EXIT_SUCCESS;
}