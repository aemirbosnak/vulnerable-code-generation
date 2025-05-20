//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[BUFFER_SIZE];
  int addrlen, n;

  if (argc < 3) {
    printf("Usage: %s <IP address> <port number>\n", argv[0]);
    exit(0);
  }

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error opening socket\n");
    exit(0);
  }

  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error connecting to server\n");
    exit(0);
  }

  while (1) {
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
      printf("Error reading from socket\n");
      exit(0);
    }
    printf("Received message: %s\n", buffer);
  }

  close(sockfd);
  return 0;
}