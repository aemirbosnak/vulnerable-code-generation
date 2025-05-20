//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SOCKET_ERR -1

int scan_port(const char *ip, uint16_t port) {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == SOCKET_ERR) {
    perror("socket");
    return SOCKET_ERR;
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(ip);
  serv_addr.sin_port = htons(port);

  int conn = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (conn == SOCKET_ERR) {
    perror("connect");
    close(sockfd);
    return SOCKET_ERR;
  }

  printf("Port %d is open on IP %s\n", port, ip);

  close(sockfd);
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <ip> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  const char *ip = argv[1];
  int port = atoi(argv[2]);

  int ret = scan_port(ip, port);
  if (ret == SOCKET_ERR) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}