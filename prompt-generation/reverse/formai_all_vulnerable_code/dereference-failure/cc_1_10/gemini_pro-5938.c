//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int sockfd;
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  struct hostent *hostent = gethostbyname(argv[1]);
  if (!hostent) {
    fprintf(stderr, "Could not resolve host: %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  servaddr.sin_addr = *(struct in_addr *)hostent->h_addr;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Socket");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Connect");
    return EXIT_FAILURE;
  }

  char buf[BUFSIZE];
  while (1) {
    int n = read(sockfd, buf, BUFSIZE - 1);
    if (n < 0) {
      perror("Read");
      return EXIT_FAILURE;
    }
    buf[n] = '\0';
    printf("Received: %s\n", buf);
    if (strcmp(buf, "HTTP/1.1 200 OK") == 0) {
      printf("Uptime: %s\n", argv[1]);
      close(sockfd);
      return EXIT_SUCCESS;
    } else {
      printf("Downtime: %s\n", argv[1]);
      close(sockfd);
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}