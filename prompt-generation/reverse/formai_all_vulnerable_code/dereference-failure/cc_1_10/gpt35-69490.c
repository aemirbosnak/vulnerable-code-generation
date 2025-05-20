//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

  //parse parameters
  if (argc < 2) {
    printf("Usage: ./http_client url\n");
    exit(1);
  }

  //get host and path from url
  char host[256];
  char path[256];
  sscanf(argv[1], "http://%[^/]/%s", host, path);
  
  //print host and path
  printf("Host: %s\n", host);
  printf("Path: %s\n", path);

  //create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket error");
    exit(1);
  }

  //resolve host name
  struct hostent *he = gethostbyname(host);
  if (he == NULL) {
    perror("gethostbyname error");
    exit(1);
  }

  //create server address
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  server_addr.sin_addr = *((struct in_addr *) he->h_addr);
  memset(&(server_addr.sin_zero), '\0', 8);

  //connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
    perror("connect error");
    exit(1);
  }

  //send GET request
  char request[512];
  sprintf(request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);
  if (send(sock, request, strlen(request), 0) == -1) {
    perror("send error");
    exit(1);
  }

  //receive response
  char response[4096];
  int num_received = 0;
  bool body_started = false;
  while ((num_received = recv(sock, response, 4096, 0)) > 0) {
    response[num_received] = '\0';
    printf("%s", response);
    //check if body started
    if (!body_started) {
      char *body_start = strstr(response, "\r\n\r\n");
      if (body_start != NULL) {
        body_started = true;
        printf("%s", body_start + 4);
      }
    }
  }
  if (num_received < 0) {
    perror("recv error");
  }

  //close socket
  close(sock);

  return 0;
}