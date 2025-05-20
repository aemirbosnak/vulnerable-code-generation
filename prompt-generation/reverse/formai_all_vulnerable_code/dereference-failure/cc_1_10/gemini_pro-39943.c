//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <local port> <remote IP>\n", argv[0]);
    exit(1);
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Bind the socket to the local port
  struct sockaddr_in localaddr;
  memset(&localaddr, 0, sizeof(localaddr));
  localaddr.sin_family = AF_INET;
  localaddr.sin_port = htons(atoi(argv[1]));
  localaddr.sin_addr.s_addr = INADDR_ANY;
  if (bind(sockfd, (struct sockaddr *)&localaddr, sizeof(localaddr)) == -1) {
    perror("bind");
    exit(1);
  }

  // Listen for connections
  if (listen(sockfd, 5) == -1) {
    perror("listen");
    exit(1);
  }

  // Accept connections
  struct sockaddr_in remoteaddr;
  socklen_t remoteaddrlen = sizeof(remoteaddr);
  int connfd;
  while ((connfd = accept(sockfd, (struct sockaddr *)&remoteaddr, &remoteaddrlen)) != -1) {
    // Check if the remote IP is allowed
    if (strcmp(inet_ntoa(remoteaddr.sin_addr), argv[2]) != 0) {
      close(connfd);
      continue;
    }

    // Handle the connection
    char buffer[1024];
    while (read(connfd, buffer, sizeof(buffer)) > 0) {
      write(connfd, buffer, sizeof(buffer));
    }

    // Close the connection
    close(connfd);
  }

  // Close the socket
  close(sockfd);

  return 0;
}