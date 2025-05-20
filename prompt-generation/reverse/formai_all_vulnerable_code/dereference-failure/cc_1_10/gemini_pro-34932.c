//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT_MAX 65535
#define TIMEOUT_SEC 2
#define TIMEOUT_USEC 0

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    return 1;
  }

  char *hostname = argv[1];
  struct hostent *host = gethostbyname(hostname);
  if (!host) {
    printf("Error: could not resolve hostname '%s'\n", hostname);
    return 1;
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_addr = *(struct in_addr *)host->h_addr;
  addr.sin_port = htons(0);

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("Error: could not create socket");
    return 1;
  }

  struct timeval timeout;
  timeout.tv_sec = TIMEOUT_SEC;
  timeout.tv_usec = TIMEOUT_USEC;
  if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
    perror("Error: could not set socket timeout");
    return 1;
  }

  for (int port = 0; port <= PORT_MAX; port++) {
    addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
      printf("Port %d: open\n", port);
    }
  }

  close(sock);
  return 0;
}