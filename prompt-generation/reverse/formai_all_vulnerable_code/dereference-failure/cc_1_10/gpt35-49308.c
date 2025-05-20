//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[4096];
  char request[4096];

  char *host = "example.com";
  char *path = "/index.html";
  portno = 80; // default HTTP port

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  server = gethostbyname(host);
  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

  n = write(sockfd, request, strlen(request));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  bzero(buffer, 4096);
  while ((n = read(sockfd, buffer, 4096)) > 0) {
    fwrite(buffer, sizeof(char), n, stdout);
    bzero(buffer, 4096);
  }

  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  close(sockfd);
  return 0;
}