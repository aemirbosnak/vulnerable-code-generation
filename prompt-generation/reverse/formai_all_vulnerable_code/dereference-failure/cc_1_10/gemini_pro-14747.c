//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_PORTS 100

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port1> [port2] ... [port%d]\n", argv[0], MAX_PORTS);
    exit(EXIT_FAILURE);
  }

  char *hostname = argv[1];
  int ports[MAX_PORTS];
  int num_ports = argc - 2;
  for (int i = 0; i < num_ports; i++) {
    ports[i] = atoi(argv[i + 2]);
  }

  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < num_ports; i++) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
      fprintf(stderr, "Error: could not create socket\n");
      exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    addr.sin_port = htons(ports[i]);

    int res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (res == 0) {
      printf("Port %d is open\n", ports[i]);
    } else {
      printf("Port %d is closed\n", ports[i]);
    }

    close(sockfd);
  }

  return EXIT_SUCCESS;
}