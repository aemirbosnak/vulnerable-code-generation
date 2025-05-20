//GEMINI-pro DATASET v1.0 Category: Networking ; Style: interoperable
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Define the maximum buffer size.
#define MAX_BUFFER_SIZE 1024

// Define the port number.
#define PORT 8080

// Main function.
int main(int argc, char *argv[]) {
  // Check if the correct number of arguments have been provided.
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <message>\n", argv[0]);
    return 1;
  }

  // Get the hostname and message from the command line arguments.
  char *hostname = argv[1];
  char *message = argv[2];

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Get the IP address of the hostname.
  struct hostent *hostent = gethostbyname(hostname);
  if (hostent == NULL) {
    herror("gethostbyname");
    return 1;
  }

  // Create a sockaddr_in structure.
  struct sockaddr_in sockaddr_in;
  sockaddr_in.sin_family = AF_INET;
  sockaddr_in.sin_port = htons(PORT);
  sockaddr_in.sin_addr = *((struct in_addr *)hostent->h_addr);

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *)&sockaddr_in, sizeof(sockaddr_in)) == -1) {
    perror("connect");
    return 1;
  }

  // Send the message to the server.
  if (send(sockfd, message, strlen(message), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the response from the server.
  char buffer[MAX_BUFFER_SIZE];
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
    perror("recv");
    return 1;
  }

  // Print the response from the server.
  printf("%s\n", buffer);

  // Close the socket.
  if (close(sockfd) == -1) {
    perror("close");
    return 1;
  }

  return 0;
}