//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

// Our beloved and trusty IMAP client
int main(int argc, char **argv) {
  // Let's start with the usual incantations
  int sockfd, portno;
  struct sockaddr_in serv_addr;

  // Check if we have the right number of arguments
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
    exit(1);
  }

  // Let's grab the server and port number from the command line
  char *server = argv[1];
  portno = atoi(argv[2]);

  // Now, we create a socket, like a magical portal
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    exit(2);
  }

  // Time to connect to the server, like a knight errant seeking adventure
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  inet_pton(AF_INET, server, &serv_addr.sin_addr);
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    exit(3);
  }

  // Now, the fun part begins! We'll start by logging in
  char *login = "a login command";
  send(sockfd, login, strlen(login), 0);
  char buffer[1024];
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("Server response: %s\n", buffer);

  // Let's send some commands to fetch our precious emails
  char *list = "a list command";
  send(sockfd, list, strlen(list), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("Server response: %s\n", buffer);

  // Time to log out, bid farewell to the server
  char *logout = "a logout command";
  send(sockfd, logout, strlen(logout), 0);
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("Server response: %s\n", buffer);

  // We're all done, close the socket and bid farewell
  close(sockfd);
  return 0;
}