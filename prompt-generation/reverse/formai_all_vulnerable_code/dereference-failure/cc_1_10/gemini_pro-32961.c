//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 2048

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s <url>\n", argv[0]);
    return 1;
  }

  // parse url
  char* url = argv[1];
  char* host = strstr(url, "://");
  if (!host) {
    fprintf(stderr, "invalid url: %s\n", url);
    return 1;
  }
  host += 3;
  char* path = strchr(host, '/');
  if (!path) {
    path = "/";
  }

  // create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // connect to server
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(80);
  addr.sin_addr.s_addr = inet_addr(host);
  if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return 1;
  }

  // send request
  char request[BUFSIZE];
  sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
  if (send(sock, request, strlen(request), 0) < 0) {
    perror("send");
    return 1;
  }

  // receive response
  char response[BUFSIZE];
  int n;
  while ((n = recv(sock, response, BUFSIZE, 0)) > 0) {
    fwrite(response, 1, n, stdout);
  }
  if (n < 0) {
    perror("recv");
    return 1;
  }

  // cleanup
  close(sock);
  return 0;
}