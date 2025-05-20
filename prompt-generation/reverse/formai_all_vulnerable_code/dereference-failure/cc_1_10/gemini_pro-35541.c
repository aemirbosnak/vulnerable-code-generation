//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT_RANGE 65535

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *hostname = argv[1];

  struct hostent *host = gethostbyname(hostname);
  if (!host) {
    fprintf(stderr, "Could not resolve hostname '%s'\n", hostname);
    return EXIT_FAILURE;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr = *(struct in_addr *)host->h_addr;

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in target;
  memset(&target, 0, sizeof(target));
  target.sin_family = AF_INET;
  target.sin_port = htons(PORT_RANGE);

  printf("Scanning host '%s' for open ports...\n", hostname);

  for (int port = 0; port < PORT_RANGE; port++) {
    target.sin_port = htons(port);
    int result = connect(sock, (struct sockaddr *)&target, sizeof(target));

    if (result == 0) {
      printf("Port %d: open\n", port);
    }
  }

  close(sock);

  return EXIT_SUCCESS;
}