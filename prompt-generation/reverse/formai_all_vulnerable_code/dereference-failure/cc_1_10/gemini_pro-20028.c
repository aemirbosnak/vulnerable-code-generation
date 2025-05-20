//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024
#define MAX_BUF 1024

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[MAX_BUF];

  if (argc < 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    exit(0);
  }

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("ERROR opening socket\n");
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    printf("ERROR, no such host\n");
    exit(0);
  }

  memset((char *) &serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("ERROR connecting\n");
    exit(1);
  }

  printf("** Yahoo! You're now connected to the email server! **\n\n");

  while (1) {
    printf("> ");
    fgets(buffer, MAX_BUF, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
      printf("ERROR writing to socket\n");
      break;
    }

    n = read(sockfd, buffer, MAX_BUF);
    if (n < 0) {
      printf("ERROR reading from socket\n");
      break;
    }

    printf("%s", buffer);
  }

  close(sockfd);
  return 0;
}