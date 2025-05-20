//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

const int MAX_REQUEST_SIZE = 1000;
const int PORT = 80;
const int MAX_RESPONSE_SIZE = 50000;

void error(const char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[MAX_RESPONSE_SIZE];
  char request[MAX_REQUEST_SIZE];

  if (argc < 2) {
    fprintf(stderr,"usage %s hostname path\n", argv[0]);
    exit(0);
  }

  portno = PORT;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    error("ERROR opening socket");
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
    error("ERROR connecting");
  }

  sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", argv[2], argv[1]);

  n = write(sockfd,request,strlen(request));
  if (n < 0) {
    error("ERROR writing to socket");
  }

  bzero(buffer,MAX_RESPONSE_SIZE);
  n = read(sockfd,buffer,MAX_RESPONSE_SIZE);
  if (n < 0) {
    error("ERROR reading from socket");
  }

  printf("%s\n",buffer);

  close(sockfd);
  return 0;
}