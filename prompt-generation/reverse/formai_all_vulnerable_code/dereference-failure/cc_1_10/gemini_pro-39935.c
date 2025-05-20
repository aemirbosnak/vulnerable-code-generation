//GEMINI-pro DATASET v1.0 Category: Networking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  struct sockaddr_in serv_addr, cli_addr;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s port\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(atoi(argv[1]));

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind");
    exit(1);
  }

  listen(sockfd, 5);

  clilen = sizeof(cli_addr);

  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("accept");
      exit(1);
    }

    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    int n = read(newsockfd, buffer, sizeof(buffer));
    if (n < 0) {
      perror("read");
      exit(1);
    }

    printf("Received: %s", buffer);

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "Hello World!");
    n = write(newsockfd, buffer, strlen(buffer));
    if (n < 0) {
      perror("write");
      exit(1);
    }

    close(newsockfd);
  }

  close(sockfd);
  return 0;
}