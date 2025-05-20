//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define MAXLINE 1024

int main(int argc, char *argv[])
{
  int sockfd, n, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[MAXLINE];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }
  portno = atoi(argv[2]);

  // create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // get the server's IP address
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  // fill in the server's address
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  // connect to the server
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // send a message to the server
  bzero(buffer, MAXLINE);
  strcpy(buffer, "Hello from the client!");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // receive a message from the server
  bzero(buffer, MAXLINE);
  n = read(sockfd, buffer, MAXLINE);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  printf("Message from the server: %s\n", buffer);

  // close the connection
  close(sockfd);
  return 0;
}