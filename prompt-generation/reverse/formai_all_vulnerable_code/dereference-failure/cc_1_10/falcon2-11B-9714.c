//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc!= 3) {
    printf("Usage: %s <target_ip> <port>\n", argv[0]);
    return 1;
  }

  struct addrinfo hints, *ai, *ai_res;
  int rv;
  char buffer[1024];

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((rv = getaddrinfo(argv[1], argv[2], &hints, &ai_res))!= 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    return 1;
  }

  for (ai = ai_res; ai!= NULL; ai = ai->ai_next) {
    int sockfd;
    if ((sockfd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol)) == -1) {
      perror("socket");
      continue;
    }

    if (connect(sockfd, ai->ai_addr, ai->ai_addrlen) == -1) {
      perror("connect");
      close(sockfd);
      continue;
    }

    printf("Port %d is open\n", ntohs(ai->ai_addr->sa_family));

    if (send(sockfd, buffer, 1024, 0) < 0) {
      perror("send");
      close(sockfd);
      continue;
    }

    if (recv(sockfd, buffer, 1024, 0) < 0) {
      perror("recv");
      close(sockfd);
      continue;
    }

    close(sockfd);
  }

  freeaddrinfo(ai_res);

  return 0;
}