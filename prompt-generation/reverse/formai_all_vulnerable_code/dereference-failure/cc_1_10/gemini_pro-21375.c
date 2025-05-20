//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
  char *host, *port, *path;
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];

  if (argc < 4) {
    fprintf(stderr, "usage: %s host port path\n", argv[0]);
    exit(1);
  }

  host = argv[1];
  port = argv[2];
  path = argv[3];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  server = gethostbyname(host);
  if (server == NULL) {
    fprintf(stderr, "error: no such host\n");
    exit(1);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(atoi(port));

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("write");
    exit(1);
  }

  memset(buffer, 0, sizeof(buffer));

  while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
    fwrite(buffer, 1, n, stdout);
  }

  if (n < 0) {
    perror("read");
    exit(1);
  }

  close(sockfd);

  return 0;
}