//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
    return 1;
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Create a server address structure
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return 1;
  }

  // Create a buffer for the data
  char buffer[BUFFERSIZE];

  // Send a message to the server
  const char *message = "Hello world!";
  if (send(sockfd, message, strlen(message), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive a message from the server
  if (recv(sockfd, buffer, BUFFERSIZE, 0) == -1) {
    perror("recv");
    return 1;
  }

  // Print the message from the server
  printf("Received message: %s\n", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}