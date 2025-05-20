//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[1024];
  int yes = 1;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  listen(sockfd, 5);
  while (1) {
    sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
    if (sockfd < 0) {
      perror("accept failed");
      exit(EXIT_FAILURE);
    }

    printf("Connection from: %s\n", inet_ntoa(cli_addr.sin_addr));

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
      buffer[n] = '\0';
      printf("Message received from client: %s\n", buffer);
      send(sockfd, buffer, n, 0);
    }

    if (n < 0) {
      perror("recv failed");
      exit(EXIT_FAILURE);
    }

    close(sockfd);
    break;
  }

  return 0;
}