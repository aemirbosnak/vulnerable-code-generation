//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  // Check for correct usage
  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the port number
  int port = atoi(argv[1]);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Bind the socket to the port
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(port);
  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(sockfd, 5) == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept an incoming connection
  struct sockaddr_in cliaddr;
  socklen_t clilen = sizeof(cliaddr);
  int connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
  if (connfd == -1) {
    perror("accept");
    return EXIT_FAILURE;
  }

  // Read data from the client
  char buffer[256];
  int nbytes;
  while ((nbytes = read(connfd, buffer, sizeof(buffer))) > 0) {
    // Write data back to the client
    if (write(connfd, buffer, nbytes) == -1) {
      perror("write");
      return EXIT_FAILURE;
    }
  }

  // Close the connection
  close(connfd);
  close(sockfd);

  return EXIT_SUCCESS;
}