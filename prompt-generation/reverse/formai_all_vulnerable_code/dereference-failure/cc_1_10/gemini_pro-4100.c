//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;

  if (argc < 2) {
    fprintf(stderr, "Error: no port number specified\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error: could not open socket\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: could not bind socket to port\n");
    exit(1);
  }

  listen(sockfd, 5);

  clilen = sizeof(cli_addr);

  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
      fprintf(stderr, "Error: could not accept connection\n");
      exit(1);
    }

    bzero(buffer, 256);
    int n = read(newsockfd, buffer, 255);
    if (n < 0) {
      fprintf(stderr, "Error: could not read from socket\n");
      exit(1);
    }

    printf("Client: %s\n", buffer);

    bzero(buffer, 256);
    sprintf(buffer, "Hello, client!");
    n = write(newsockfd, buffer, strlen(buffer));
    if (n < 0) {
      fprintf(stderr, "Error: could not write to socket\n");
      exit(1);
    }

    close(newsockfd);
  }

  close(sockfd);

  return 0;
}