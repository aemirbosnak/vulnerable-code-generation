//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int sockfd;
  struct sockaddr_in servaddr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Set the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(143);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    exit(1);
  }

  // Send the login command
  char *login_command = "LOGIN \"username\" \"password\"\r\n";
  if (write(sockfd, login_command, strlen(login_command)) == -1) {
    perror("write");
    exit(1);
  }

  // Receive the login response
  char *login_response = malloc(1024);
  if (read(sockfd, login_response, 1024) == -1) {
    perror("read");
    exit(1);
  }

  // Print the login response
  printf("%s", login_response);

  // Send the list command
  char *list_command = "LIST \"\" \"\"\r\n";
  if (write(sockfd, list_command, strlen(list_command)) == -1) {
    perror("write");
    exit(1);
  }

  // Receive the list response
  char *list_response = malloc(1024);
  if (read(sockfd, list_response, 1024) == -1) {
    perror("read");
    exit(1);
  }

  // Print the list response
  printf("%s", list_response);

  // Close the socket
  close(sockfd);

  return 0;
}