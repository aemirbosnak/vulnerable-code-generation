//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_REQUESTS 10

int main() {
  int sockfd, newsockfd, portno;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[BUFFER_SIZE];
  int addrlen, bytes_received;
  char *message;
  int num_requests = 0;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Error creating socket.\n");
    exit(1);
  }

  bzero(&serv_addr, sizeof(serv_addr));
  portno = 8080;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error binding socket.\n");
    exit(1);
  }

  listen(sockfd, MAX_REQUESTS);
  addrlen = sizeof(cli_addr);

  while (1) {
    if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen)) < 0) {
      printf("Error accepting connection.\n");
      exit(1);
    }

    bytes_received = 0;
    message = (char *) malloc(BUFFER_SIZE);

    while ((bytes_received = recv(newsockfd, buffer, BUFFER_SIZE, 0)) > 0) {
      strncat(message, buffer, bytes_received);
    }

    if (bytes_received == -1) {
      printf("Error receiving data.\n");
      exit(1);
    }

    printf("Received request: %s\n", message);
    num_requests++;

    if (num_requests >= MAX_REQUESTS) {
      printf("Maximum number of requests reached.\n");
      exit(1);
    }

    close(newsockfd);
  }

  return 0;
}