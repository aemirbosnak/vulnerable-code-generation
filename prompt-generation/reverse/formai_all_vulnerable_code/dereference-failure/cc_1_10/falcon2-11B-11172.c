//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr, cli_addr;
  struct hostent *server;

  if (argc < 2) {
    printf("Usage: %s <port number>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[1]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket failed");
    exit(1);
  }

  server = gethostbyname("localhost");
  if (server == NULL) {
    fprintf(stderr, "gethostbyname: Unknown host\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind failed");
    exit(1);
  }

  listen(sockfd, 5);

  while (1) {
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_addr.s_addr = INADDR_ANY;
    cli_addr.sin_port = htons(0);

    if ((n = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *)&serv_addr)) < 0) {
      perror("accept");
      continue;
    }

    printf("Connection from %s port %d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    char buffer[MAX_DATA_SIZE];
    bzero(buffer, MAX_DATA_SIZE);

    while ((n = recv(n, buffer, MAX_DATA_SIZE, 0)) > 0) {
      printf("Received: %s\n", buffer);
      send(n, buffer, n, 0);
    }

    close(n);
    break;
  }

  close(sockfd);
  return 0;
}