//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[BUFFER_SIZE];
  int n;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  portno = atoi(argv[1]);

  memset((char *)&serv_addr, 0, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  listen(sockfd, 5);

  while (1) {
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("ERROR on accept");
      exit(1);
    }

    while (1) {
      memset(buffer, 0, BUFFER_SIZE);
      n = read(newsockfd, buffer, BUFFER_SIZE - 1);
      if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
      }
      if (n == 0) {
        printf("Client disconnected\n");
        break;
      }

      printf("%s", buffer);

      n = write(newsockfd, buffer, strlen(buffer));
      if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
      }
    }

    close(newsockfd);
  }

  close(sockfd);

  return 0;
}