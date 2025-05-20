//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
  int sockfd, portno, newsockfd;
  struct sockaddr_in serv_addr, cli_addr;
  int n;
  char buf[256];

  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[1]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  memset((char *) &serv_addr, '0', sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  listen(sockfd, 5);

  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
    if (newsockfd < 0) {
      perror("ERROR on accept");
      exit(1);
    }

    bzero(buf, 256);
    recv(newsockfd, buf, 255, 0);
    printf("Received: %s\n", buf);
    send(newsockfd, "ACK", 3, 0);
    close(newsockfd);
  }

  close(sockfd);

  return 0;
}