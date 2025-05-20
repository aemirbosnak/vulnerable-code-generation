//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[BUFSIZE];
  char *username, *password;

  // Check arguments
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
    exit(1);
  }

  // Get server information
  portno = atoi(argv[2]);
  username = argv[3];
  password = argv[4];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    exit(1);
  }

  // Get server IP
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error getting server IP\n");
    exit(1);
  }

  // Set server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Send login information
  sprintf(buffer, "USER %s\r\n", username);
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, BUFSIZE, 0);

  sprintf(buffer, "PASS %s\r\n", password);
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, BUFSIZE, 0);

  // Send command
  sprintf(buffer, "LIST\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, BUFSIZE, 0);

  // Print response
  printf("%s", buffer);

  // Close socket
  close(sockfd);

  return 0;
}