//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[BUFFER_SIZE];

  if (argc < 3) {
    fprintf(stderr, "usage: %s hostname port\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[2]);
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    error("ERROR, no such host");
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    error("ERROR opening socket");
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    error("ERROR connecting");
  }

  while (1) {
    printf("Enter HTTP request: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    if (strcmp(buffer, "exit\n") == 0) {
      break;
    }

    if (write(sockfd, buffer, strlen(buffer)) < 0) {
      error("ERROR writing to socket");
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
      error("ERROR reading from socket");
    }

    printf("Response: %s\n", buffer);
  }

  close(sockfd);
  return 0;
}