//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PORTS 100

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port1> [port2] ... [portN]\n", argv[0]);
    return EXIT_FAILURE;
  }

  struct hostent *host = gethostbyname(argv[1]);
  if (!host) {
    herror("gethostbyname");
    return EXIT_FAILURE;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  int num_ports = argc - 2;
  int ports[num_ports];
  for (int i = 0; i < num_ports; i++) {
    ports[i] = atoi(argv[i + 2]);
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = host->h_addr_list[0];

  for (int i = 0; i < num_ports; i++) {
    addr.sin_port = htons(ports[i]);

    int ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == 0) {
      printf("Port %d is open\n", ports[i]);
    } else {
      printf("Port %d is closed\n", ports[i]);
    }
  }

  close(sockfd);

  return EXIT_SUCCESS;
}