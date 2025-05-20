//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char* argv[]) {
  // Check for correct usage
  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <target hostname>\n", argv[0]);
    return 1;
  }

  struct addrinfo* hints = {0};
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM;
  hints->ai_flags = AI_PASSIVE;

  struct addrinfo* result = 0;
  int err = getaddrinfo(argv[1], "53", hints, &result);
  if (err) {
    fprintf(stderr, "Error: %s\n", gai_strerror(err));
    return 1;
  }

  for (struct addrinfo* p = result; p; p = p->ai_next) {
    int sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
    if (sockfd == -1) {
      perror("socket");
      continue;
    }

    struct hostent* host = gethostbyname(argv[1]);
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(53);
    sin.sin_addr = *((struct in_addr*) host->h_addr);

    err = connect(sockfd, (struct sockaddr*)&sin, sizeof(sin));
    if (err == 0) {
      printf("Port 53 is open on %s.\n", p->ai_canonname);
    } else if (err!= -1) {
      perror("connect");
    }

    close(sockfd);
  }

  freeaddrinfo(result);

  return 0;
}