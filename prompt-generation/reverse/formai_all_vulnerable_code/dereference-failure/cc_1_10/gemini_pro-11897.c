//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 100

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s <hostname> <port1> [port2] ... [port%d]\n", argv[0], MAX_PORTS);
    exit(1);
  }

  char *hostname = argv[1];
  int ports[MAX_PORTS];
  for (int i = 2; i < argc; i++) {
    ports[i - 2] = atoi(argv[i]);
  }

  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    printf("Error: Could not resolve hostname %s\n", hostname);
    exit(1);
  }

  for (int i = 0; i < MAX_PORTS; i++) {
    int port = ports[i];

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);
    addr.sin_port = htons(port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
      printf("Error: Could not create socket\n");
      exit(1);
    }

    int result = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (result == 0) {
      printf("Port %d is open\n", port);
    } else {
      printf("Port %d is closed\n", port);
    }

    close(sock);
  }

  return 0;
}