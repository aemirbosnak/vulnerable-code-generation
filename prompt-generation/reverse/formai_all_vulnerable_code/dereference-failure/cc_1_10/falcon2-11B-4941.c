//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  struct sockaddr_in serv_addr, cli_addr;
  int n;
  char buffer[1024];

  if (argc!= 2) {
    fprintf(stderr, "Usage: %s hostname\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[1]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  listen(sockfd, 3);

  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
    if (newsockfd < 0) {
      perror("ERROR on accept");
      exit(1);
    }

    bzero(buffer, 1024);
    n = read(newsockfd, buffer, 1024);
    if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
    }

    send(newsockfd, buffer, n, 0);
    close(newsockfd);
  }

  return 0;
}