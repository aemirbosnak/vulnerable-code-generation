//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s <hostname> <port1> [port2] ...\n", argv[0]);
    return EXIT_FAILURE;
  }

  const char *hostname = argv[1];
  int num_ports = argc - 2;
  unsigned short ports[num_ports];

  for (int i = 0; i < num_ports; i++) {
    ports[i] = (unsigned short) atoi(argv[i + 2]);
  }

  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < num_ports; i++) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
      perror("socket");
      return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr *) host->h_addr);
    addr.sin_port = htons(ports[i]);

    int result = connect(sock, (struct sockaddr *) &addr, sizeof(addr));
    if (result == 0) {
      printf("Port %d is open!\n", ports[i]);
    } else {
      printf("Port %d is closed.\n", ports[i]);
    }

    close(sock);
  }

  return EXIT_SUCCESS;
}