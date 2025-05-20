//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

int main(int argc, char **argv) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
    exit(0);
  }

  portno = atoi(argv[2]);
  server = gethostbyname(argv[1]);

  if (server == NULL) {
    fprintf(stderr, "Error: no such host\n");
    exit(0);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    fprintf(stderr, "Error: could not open socket\n");
    exit(0);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: could not connect to server\n");
    exit(0);
  }

  sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
  write(sockfd, buffer, strlen(buffer));

  while (read(sockfd, buffer, sizeof(buffer)) > 0) {
    printf("%s", buffer);
  }

  close(sockfd);
  return 0;
}