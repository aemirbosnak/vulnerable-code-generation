//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr,"usage: %s hostname\n", argv[0]);
    exit(0);
  }

  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(0);
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, '0', sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(80);
  memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);

  if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(0);
  }

  char *request = "GET / HTTP/1.1\r\nHost: ";
  strcat(request, argv[1]);
  strcat(request, "\r\n\r\n");

  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("ERROR sending request");
    exit(0);
  }

  char response[4096];
  memset(&response, '0', sizeof(response));
  if (recv(sockfd, response, sizeof(response), 0) < 0) {
    perror("ERROR receiving response");
    exit(0);
  }

  printf("Response:\n%s", response);

  close(sockfd);

  return 0;
}