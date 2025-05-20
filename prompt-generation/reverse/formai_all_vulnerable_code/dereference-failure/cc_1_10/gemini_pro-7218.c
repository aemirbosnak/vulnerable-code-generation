//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#define MAX_PORTS 1024
#define MAX_HOST_LEN 256

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    return 1;
  }

  char *hostname = argv[1];
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    printf("Invalid hostname: %s\n", hostname);
    return 1;
  }

  printf("Scanning host: %s (%s)\n", hostname, inet_ntoa(*((struct in_addr *)host->h_addr)));

  for (int i = 0; i < MAX_PORTS; i++) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
      printf("Error creating socket: %s\n", strerror(errno));
      return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(i);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    int res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (res < 0) {
      close(sockfd);
      continue;
    }

    printf("Port %d: open\n", i);
    close(sockfd);
  }

  return 0;
}