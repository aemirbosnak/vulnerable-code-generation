//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <server_address> <server_port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse the server address and port from the command line arguments.
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
    printf("Invalid server address: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Create a TCP socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send a greeting message to the server.
  char *greeting = "Hello, my beloved server!";
  if (send(sockfd, greeting, strlen(greeting), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive a response from the server.
  char buffer[MAX_BUFFER_SIZE];
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the server's response.
  printf("Server's response: %s\n", buffer);

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}