//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535
#define MAX_HOST_LEN 256

void usage(char *program_name) {
  printf("Usage: %s <host> <port1> <port2> ... <portN>\n", program_name);
  printf("Example: %s 192.168.1.1 22 80 443\n", program_name);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    usage(argv[0]);
  }

  char *host = argv[1];
  int port_count = argc - 2;
  int ports[port_count];

  for (int i = 0; i < port_count; i++) {
    ports[i] = atoi(argv[i + 2]);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(host);
  serv_addr.sin_port = htons(0);

  int bind_status = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (bind_status == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in local_addr;
  socklen_t local_addr_len = sizeof(local_addr);
  int getsockname_status = getsockname(sockfd, (struct sockaddr *)&local_addr, &local_addr_len);
  if (getsockname_status == -1) {
    perror("getsockname");
    exit(EXIT_FAILURE);
  }

  unsigned short local_port = ntohs(local_addr.sin_port);

  printf("Local address: %s:%d\n", inet_ntoa(local_addr.sin_addr), local_port);

  for (int i = 0; i < port_count; i++) {
    serv_addr.sin_port = htons(ports[i]);
    int connect_status = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (connect_status == 0) {
      printf("Port %d is open on %s\n", ports[i], host);
    } else {
      printf("Port %d is closed on %s\n", ports[i], host);
    }
  }

  close(sockfd);

  return EXIT_SUCCESS;
}