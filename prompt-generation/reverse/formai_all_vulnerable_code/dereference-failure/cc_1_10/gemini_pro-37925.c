//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUF 1024

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error opening socket\n");
    return 1;
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error getting host by name\n");
    return 1;
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error connecting to server\n");
    return 1;
  }

  char buf[MAX_BUF];
  while (1) {
    memset(buf, 0, MAX_BUF);
    printf("> ");
    fgets(buf, MAX_BUF, stdin);

    if (strncmp(buf, "quit", 4) == 0) {
      break;
    }

    send(sockfd, buf, strlen(buf), 0);

    memset(buf, 0, MAX_BUF);
    recv(sockfd, buf, MAX_BUF, 0);
    printf("%s\n", buf);
  }

  close(sockfd);

  return 0;
}