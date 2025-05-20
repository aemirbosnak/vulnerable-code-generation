//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
  // Check if the user has provided enough arguments.
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the host and port from the user.
  char *host = argv[1];
  int port = atoi(argv[2]);

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Get the host's IP address.
  struct hostent *hostent = gethostbyname(host);
  if (hostent == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  // Create the server address.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  memcpy(&server_addr.sin_addr, hostent->h_addr, hostent->h_length);

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send a message to the server.
  char *message = "Hello, world!";
  if (send(sockfd, message, strlen(message), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive a message from the server.
  char buffer[1024];
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the message from the server.
  printf("Message from the server: %s\n", buffer);

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}