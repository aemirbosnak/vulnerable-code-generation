//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <netdb.h>

#define BUFSIZE 1024

int main() {
  int sock, n, i;
  char buf[BUFSIZE];
  struct ifreq ifr;
  struct sockaddr_in *sin;
  struct hostent *host;

  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0) {
    perror("socket");
    exit(1);
  }

  strcpy(ifr.ifr_name, "wlan0");
  if (ioctl(sock, SIOCGIFADDR, &ifr) < 0) {
    perror("ioctl");
    exit(1);
  }

  sin = (struct sockaddr_in *)&ifr.ifr_addr;
  host = gethostbyaddr((char *)&sin->sin_addr, sizeof(sin->sin_addr), AF_INET);
  if (host == NULL) {
    perror("gethostbyaddr");
    exit(1);
  }

  printf("Interface: %s\n", ifr.ifr_name);
  printf("IP address: %s\n", inet_ntoa(sin->sin_addr));
  printf("Hostname: %s\n", host->h_name);

  while (1) {
    n = recv(sock, buf, BUFSIZE, 0);
    if (n < 0) {
      perror("recv");
      exit(1);
    }

    printf("Received %d bytes from %s\n", n, inet_ntoa(sin->sin_addr));

    for (i = 0; i < n; i++) {
      printf("%02X ", buf[i]);
    }

    printf("\n");
  }

  close(sock);

  return 0;
}