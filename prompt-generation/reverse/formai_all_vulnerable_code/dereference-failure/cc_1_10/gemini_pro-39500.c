//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: asynchronous
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  char buf[BUF_SIZE];
  while (1) {
    memset(buf, 0, BUF_SIZE);
    if (fgets(buf, BUF_SIZE, stdin) == NULL) {
      break;
    }

    if (send(sockfd, buf, strlen(buf), 0) < 0) {
      perror("send");
      return EXIT_FAILURE;
    }

    memset(buf, 0, BUF_SIZE);
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
      perror("recv");
      return EXIT_FAILURE;
    }

    printf("%s", buf);
  }

  close(sockfd);
  return EXIT_SUCCESS;
}