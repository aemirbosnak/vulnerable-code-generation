//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <ctype.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
  int sock;
  struct sockaddr_in sin;
  unsigned long resolv;
  char buf[BUFFER_SIZE], ip[16];
  int i, j;

  if (argc < 2) {
    printf("[*] Usage: %s <hostname or IP address>\n", argv[0]);
    exit(0);
  }

  /* resolve address */
  resolv = inet_addr(argv[1]);
  if (resolv == INADDR_NONE) {
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
      printf("[!] Could not resolve %s: %s\n", argv[1], hstrerror(h_errno));
      exit(1);
    }
    memcpy(&resolv, host->h_addr_list[0], sizeof(resolv));
  }
  snprintf(ip, 16, "%lu.%lu.%lu.%lu",
    (resolv      ) & 0xff,
    (resolv >>  8) & 0xff,
    (resolv >> 16) & 0xff,
    (resolv >> 24) & 0xff
  );
  
  printf("[*] Scanning wireless network at %s...\n", ip);

  for (i = 1; i <= 254; i++) {
    snprintf(buf, BUFFER_SIZE, "%d.%d.%d.%d", (int)(resolv >> 24 & 0xff), (int)(resolv >> 16 & 0xff), (int)(resolv >> 8 & 0xff), i);

    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    memset(&sin, 0x00, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(buf);
    sin.sin_port = htons(80);

    if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
      if (errno == ECONNREFUSED) {
        printf("[!] Found wireless network '%s'\n", buf);
      }
    }
    close(sock);
  }
  printf("[*] Scan complete!\n");

  return 0;
}