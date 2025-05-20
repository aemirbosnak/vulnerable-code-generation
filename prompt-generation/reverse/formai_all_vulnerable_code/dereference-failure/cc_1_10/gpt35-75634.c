//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[256];

  if (argc < 3) {
    fprintf(stderr,"usage %s hostname port\n", argv[0]);
    exit(0);
  }

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  server = gethostbyname(argv[1]);

  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }

  memset((char *) &serv_addr,0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;

  memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  char *request = "GET / HTTP/1.1\r\nHost: ";
  strcat(request, argv[1]);
  strcat(request, "\r\n\r\n");

  n = write(sockfd, request, strlen(request));

  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  memset(buffer, 0, sizeof(buffer));
  n = read(sockfd, buffer, sizeof(buffer) - 1);

  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  printf("%s", buffer);

  close(sockfd);
  return 0;
}