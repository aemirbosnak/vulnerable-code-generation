//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_PORT 143

int main() {
  int sockfd;
  struct sockaddr_in servaddr;
  char *server = "localhost";

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(IMAP_PORT);

  struct hostent *host = gethostbyname(server);
  if (!host) {
    perror("gethostbyname");
    exit(1);
  }
  memcpy(&servaddr.sin_addr, host->h_addr_list[0], host->h_length);

  if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    exit(1);
  }

  char buffer[1024];
  int n;

  while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
    buffer[n] = '\0';
    printf("%s", buffer);
  }

  if (n == -1) {
    perror("read");
    exit(1);
  }

  close(sockfd);

  return 0;
}