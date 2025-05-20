//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[BUFSIZE];

  if (argc < 3) {
    fprintf(stderr, "usage: %s hostname port\n", argv[0]);
    exit(0);
  }
  portno = atoi(argv[2]);

  /* create a socket */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  /* get the server's IP address */
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(0);
  }

  /* fill in the server's address */
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  /* connect to the server */
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  /* send a HTTP GET request to the server */
  sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  /* receive the server's response */
  memset(buffer, 0, BUFSIZE);
  n = recv(sockfd, buffer, BUFSIZE - 1, 0);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  /* print the server's response */
  printf("%s", buffer);

  close(sockfd);
  return 0;
}