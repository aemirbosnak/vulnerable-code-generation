//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
//Minimalistic C Network Topology Mapper example program 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_BUFF_LEN 1024
#define MAX_PORT 65535

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: %s <IP Address>\n", argv[0]);
    exit(1);
  }

  char *ip_address = argv[1];
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    perror("Error opening socket");
    exit(1);
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip_address);

  if (addr.sin_addr.s_addr == INADDR_NONE) {
    struct hostent *host = gethostbyname(ip_address);

    if (host == NULL) {
      printf("Error getting host by name %s: %s\n", ip_address, hstrerror(h_errno));
      exit(1);
    }

    addr.sin_addr = *(struct in_addr *)host->h_addr;
  }

  int port;
  for (port = 1; port <= MAX_PORT; port++) {
    addr.sin_port = htons(port);

    int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

    if (result < 0 && errno != ECONNREFUSED) {
      perror("Error connecting to port");
      exit(1);
    }

    if (result == 0) {
      printf("Port %d is open.\n", port);
    }
  }

  close(sockfd);

  return 0;
}