//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define PING_PORT 25565

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
    return EXIT_FAILURE;
  }

  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_flags = AI_PASSIVE;

  if (getaddrinfo(argv[1], NULL, &hints, &res) != 0) {
    perror("getaddrinfo()");
    return EXIT_FAILURE;
  }

  int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sockfd == -1) {
    perror("socket()");
    return EXIT_FAILURE;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PING_PORT);
  addr.sin_addr.s_addr = ((struct sockaddr_in *)res->ai_addr)->sin_addr.s_addr;

  int nbytes;
  char buf[1024];
  while (1) {
    nbytes = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, sizeof(addr));
    if (nbytes == -1) {
      perror("sendto()");
      break;
    }

    nbytes = recvfrom(sockfd, buf, sizeof(buf), 0, NULL, NULL);
    if (nbytes == -1) {
      perror("recvfrom()");
      break;
    }

    printf("Received %d bytes from %s\n", nbytes, argv[1]);
  }

  close(sockfd);

  freeaddrinfo(res);

  return EXIT_SUCCESS;
}