//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define FTP_PORT 21
#define MAX_BUF 1024

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char *hostname;
  char buf[MAX_BUF];
  int n;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  hostname = argv[1];
  portno = atoi(argv[2]);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    error("ERROR opening socket");

  // Get the server's IP address
  server = gethostbyname(hostname);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host: %s\n", hostname);
    exit(1);
  }

  // Fill in the server's address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR connecting");

  // Receive the welcome message
  memset(buf, 0, MAX_BUF);
  n = read(sockfd, buf, MAX_BUF);
  if (n < 0)
    error("ERROR reading from socket");
  printf("%s", buf);

  // Send the USER command
  strcpy(buf, "USER anonymous\n");
  n = write(sockfd, buf, strlen(buf));
  if (n < 0)
    error("ERROR writing to socket");

  // Receive the response
  memset(buf, 0, MAX_BUF);
  n = read(sockfd, buf, MAX_BUF);
  if (n < 0)
    error("ERROR reading from socket");
  printf("%s", buf);

  // Send the PASS command
  strcpy(buf, "PASS anonymous@example.com\n");
  n = write(sockfd, buf, strlen(buf));
  if (n < 0)
    error("ERROR writing to socket");

  // Receive the response
  memset(buf, 0, MAX_BUF);
  n = read(sockfd, buf, MAX_BUF);
  if (n < 0)
    error("ERROR reading from socket");
  printf("%s", buf);

  // Send the LIST command
  strcpy(buf, "LIST\n");
  n = write(sockfd, buf, strlen(buf));
  if (n < 0)
    error("ERROR writing to socket");

  // Receive the response
  memset(buf, 0, MAX_BUF);
  n = read(sockfd, buf, MAX_BUF);
  if (n < 0)
    error("ERROR reading from socket");
  printf("%s", buf);

  // Close the socket
  close(sockfd);

  return 0;
}