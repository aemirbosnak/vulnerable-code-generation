//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char *url = argv[1];
  int content_length = atoi(argv[2]);

  // create socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("ERROR opening socket");
    exit(1);
  }

  // create address structure for server
  server = gethostbyname("example.com");
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  // initialize address structure with server's address
  memset((char *) &serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(80);

  // connect to server
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // send HTTP GET request
  char request[1024];
  snprintf(request, sizeof(request), "GET /%s HTTP/1.0\r\nHost: example.com\r\n\r\n", url);
  write(sockfd, request, strlen(request));

  // receive HTTP response
  char response[1024];
  memset(response, 0, sizeof(response));
  n = read(sockfd, response, sizeof(response));

  // print HTTP response
  printf("HTTP/1.1 200 OK\r\n");
  printf("Content-Type: text/html\r\n");
  printf("Content-Length: %d\r\n\r\n", content_length);
  printf("%s", response);

  // close socket
  close(sockfd);

  return 0;
}