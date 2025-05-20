//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main() {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("ERROR opening socket\n");
    return 1;
  }

  server = gethostbyname("www.google.com");
  if (server == NULL) {
    printf("ERROR, no such host\n");
    return 2;
  }

  bzero((char *)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(80);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("ERROR connecting\n");
    return 3;
  }

  printf("Connected to server\n");

  while (1) {
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
      printf("ERROR reading from socket\n");
      return 4;
    }
    printf("%s\n", buffer);
  }

  close(sockfd);
  return 0;
}