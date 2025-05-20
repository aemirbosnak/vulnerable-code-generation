//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];

  portno = 80;
  server = gethostbyname("www.example.com");

  if (server == NULL) {
    fprintf(stderr, "Error: no such host\n");
    exit(0);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    fprintf(stderr, "Error: cannot open socket\n");
    exit(0);
  }

  memset(&serv_addr, '\0', sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: cannot connect to host\n");
    exit(0);
  }

  snprintf(buffer, sizeof(buffer), "GET / HTTP/1.1\nHost: www.example.com\n\n");

  n = write(sockfd, buffer, strlen(buffer));

  if (n < 0) {
    fprintf(stderr, "Error: cannot write to socket\n");
    exit(0);
  }

  memset(buffer, '\0', sizeof(buffer));

  while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
    printf("%s", buffer);
  }

  if (n < 0) {
    fprintf(stderr, "Error: cannot read from socket\n");
    exit(0);
  }

  close(sockfd);

  return 0;
}