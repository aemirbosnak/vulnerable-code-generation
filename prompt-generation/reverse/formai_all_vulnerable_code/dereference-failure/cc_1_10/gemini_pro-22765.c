//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  char *host = argv[1];
  int port = atoi(argv[2]);

  struct hostent *server = gethostbyname(host);
  if (server == NULL) {
    fprintf(stderr, "Error: could not resolve host %s\n", host);
    return 1;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error: could not create socket");
    return 1;
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(port);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error: could not connect to the server");
    return 1;
  }

  char request[] = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
  char buffer[4096];
  int n;

  snprintf(request, sizeof(request), request, host);
  if (write(sockfd, request, strlen(request)) < 0) {
    perror("Error: could not send request to the server");
    return 1;
  }

  while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
    if (write(STDOUT_FILENO, buffer, n) < 0) {
      perror("Error: could not write response from the server");
      return 1;
    }
  }

  if (n < 0) {
    perror("Error: could not read response from the server");
    return 1;
  }

  close(sockfd);

  return 0;
}