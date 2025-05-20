//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  // Check if the user provided an IP address and a port number.
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
    return 1;
  }

  // Parse the IP address and the port number.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  if (inet_aton(argv[1], &server_addr.sin_addr) == 0) {
    fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
    return 1;
  }

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error creating socket");
    return 1;
  }

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Error connecting to server");
    return 1;
  }

  // Send a message to the server.
  char *message = "Hello, world!";
  if (send(sockfd, message, strlen(message), 0) == -1) {
    perror("Error sending message to server");
    return 1;
  }

  // Receive a message from the server.
  char buffer[1024];
  int n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("Error receiving message from server");
    return 1;
  }

  // Print the message from the server.
  printf("Received message from server: %s\n", buffer);

  // Close the socket.
  close(sockfd);

  return 0;
}