//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {

  int sockfd, port, n;
  struct sockaddr_in serv_addr;
  char buffer[1024];

  if(argc < 3) {
    printf("Usage: %s server port\n", argv[0]);
    exit(1);
  }

  port = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    error("Error opening socket.");
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_addr.sin_port = htons(port);

  if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    error("Error connecting to server.");
  }

  while(1) {
    printf("Enter message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);

    n = write(sockfd, buffer, strlen(buffer));
    if(n < 0) {
      error("Error writing to socket.");
    }

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if(n < 0) {
      error("Error reading from socket.");
    }

    printf("%s\n", buffer);
  }

  close(sockfd);

  return 0;
}