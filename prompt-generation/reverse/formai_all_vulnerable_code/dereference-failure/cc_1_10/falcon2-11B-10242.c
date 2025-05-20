//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <host>\n", argv[0]);
    return 1;
  }

  char host[256];
  strcpy(host, argv[1]);

  int sockfd;
  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int rv;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  rv = getaddrinfo(host, NULL, &hints, &result);
  if (rv!= 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    return 1;
  }

  for (rp = result; rp!= NULL; rp = rp->ai_next) {
    sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sockfd == -1) {
      perror("socket");
      continue;
    }

    if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) == -1) {
      perror("connect");
      close(sockfd);
      continue;
    }

    if (send(sockfd, "Hello, world!", strlen("Hello, world!"), 0) == -1) {
      perror("send");
      close(sockfd);
      continue;
    }

    if (recv(sockfd, "Received:", sizeof "Received:", 0) == -1) {
      perror("recv");
      close(sockfd);
      continue;
    }

    printf("%s\n", "Received: ");
    printf("%s\n", rp->ai_canonname);
    printf("Ping to %s succeeded\n", rp->ai_canonname);

    close(sockfd);
    break;
  }

  freeaddrinfo(result);

  return 0;
}