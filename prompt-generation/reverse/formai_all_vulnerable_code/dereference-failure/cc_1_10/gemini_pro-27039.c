//GEMINI-pro DATASET v1.0 Category: Networking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

// Function to send a message to the server
void send_message(int sockfd, char *message) {
  send(sockfd, message, strlen(message), 0);
}

// Function to receive a message from the server
char *receive_message(int sockfd) {
  char *message = (char *)malloc(MAXLINE);
  recv(sockfd, message, MAXLINE, 0);
  return message;
}

// Main function
int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send a message to the server
  char *message = "Hello, world!";
  send_message(sockfd, message);

  // Receive a message from the server
  char *reply = receive_message(sockfd);
  printf("%s\n", reply);

  // Close the socket
  close(sockfd);

  return 0;
}