//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 100

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <hostname> <port1> <port2> ... <portN>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *hostname = argv[1];
  int ports[MAX_PORTS];
  int num_ports = argc - 2;
  for (int i = 0; i < num_ports; i++) {
    ports[i] = atoi(argv[i + 2]);
  }

  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    printf("Error: could not resolve hostname %s\n", hostname);
    return EXIT_FAILURE;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr = *(struct in_addr *) host->h_addr;

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    printf("Error: could not create socket\n");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < num_ports; i++) {
    addr.sin_port = htons(ports[i]);

    if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
      printf("Port %d is open\n", ports[i]);
    } else {
      printf("Port %d is closed\n", ports[i]);
    }
  }

  close(sock);

  return EXIT_SUCCESS;
}