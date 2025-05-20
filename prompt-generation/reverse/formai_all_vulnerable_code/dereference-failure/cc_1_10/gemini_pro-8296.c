//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 2048

void usage() {
  fprintf(stderr, "Usage: wireless-scanner <interface> <timeout>\n");
  fprintf(stderr, "  <interface> is the network interface to scan\n");
  fprintf(stderr, "  <timeout> is the timeout in seconds\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    usage();
  }

  char *interface = argv[1];
  int timeout = atoi(argv[2]);

  int sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(9);
  addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);

  char buf[BUFSIZE];
  memset(buf, 0, BUFSIZE);

  snprintf(buf, BUFSIZE, "DISCOVER_REQUEST");

  if (sendto(sock, buf, strlen(buf), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("sendto");
    exit(EXIT_FAILURE);
  }

  fd_set rfds;
  FD_ZERO(&rfds);
  FD_SET(sock, &rfds);

  struct timeval tv;
  tv.tv_sec = timeout;
  tv.tv_usec = 0;

  int ret = select(sock + 1, &rfds, NULL, NULL, &tv);
  if (ret < 0) {
    perror("select");
    exit(EXIT_FAILURE);
  } else if (ret == 0) {
    printf("No responses received\n");
    exit(EXIT_SUCCESS);
  }

  int addrlen = sizeof(addr);
  while (FD_ISSET(sock, &rfds)) {
    if (recvfrom(sock, buf, BUFSIZE, 0, (struct sockaddr *)&addr, &addrlen) < 0) {
      perror("recvfrom");
      exit(EXIT_FAILURE);
    }

    printf("Received response from %s: %s\n", inet_ntoa(addr.sin_addr), buf);

    FD_CLR(sock, &rfds);
  }

  close(sock);

  return EXIT_SUCCESS;
}