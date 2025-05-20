//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024 /* range of ports to scan */
#define MAX_IP_LEN 16 /* maximum length of an IP address */

int main(int argc, char *argv[]) {
  int sock, port, i, j;
  struct sockaddr_in server_addr;
  char ip_str[MAX_IP_LEN];

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <target_ip_address>\n", argv[0]);
    exit(1);
  }

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    exit(1);
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(0); /* random port */
  inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect() failed");
    exit(1);
  }

  printf("Scanning ports %d to %d...\n", PORT_RANGE, PORT_RANGE);

  for (i = PORT_RANGE; i >= 0; --i) {
    port = htons(i);
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &port, sizeof(port));

    for (j = 0; j < MAX_IP_LEN; ++j) {
      ip_str[j] = argv[1][j];
    }

    getsockname(sock, (struct sockaddr *)&server_addr, &port);
    printf("%d open on %s\n", port, inet_ntoa(server_addr.sin_addr));
  }

  close(sock);
  return 0;
}