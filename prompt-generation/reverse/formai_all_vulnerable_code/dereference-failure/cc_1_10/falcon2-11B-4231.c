//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <string.h>

int main(int argc, char *argv[]) {
  struct addrinfo hints, *servinfo, *p;
  int status;
  int sockfd, portno;
  char hostname[NI_MAXHOST];

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  status = getaddrinfo(argv[1], "80", &hints, &servinfo);
  if (status!= 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    return 1;
  }

  for (p = servinfo; p!= NULL; p = p->ai_next) {
    sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
    if (sockfd == -1) {
      perror("client: socket");
      continue;
    }

    portno = p->ai_addrlen;
    if (connect(sockfd, p->ai_addr, portno) == -1) {
      perror("client: connect");
      close(sockfd);
      continue;
    }

    if (send(sockfd, "GET / HTTP/1.1\r\nHost: ", 28, 0) == -1) {
      perror("client: send");
      close(sockfd);
      continue;
    }

    if (recv(sockfd, hostname, NI_MAXHOST, 0) == -1) {
      perror("client: recv");
      close(sockfd);
      continue;
    }

    printf("Received response from %s\n", hostname);

    close(sockfd);
  }

  freeaddrinfo(servinfo);
  return 0;
}