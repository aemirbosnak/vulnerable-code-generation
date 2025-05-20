//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

void print_usage() {
  printf("Port scanner, the rhyming edition\n");
  printf(" usage: %s <ip_address>\n", strcmp(getenv("PROGRAM_NAME"), "scanner") ? "scanner" : "scanner2");
  printf(" - scan ports 1-65535 on the given IP address\n");
  printf(" - output format: <ip_address>:port\n");
  printf(" - example: %s 192.168.1.1\n", strcmp(getenv("PROGRAM_NAME"), "scanner") ? "scanner" : "scanner2");
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    print_usage();
    exit(EXIT_FAILURE);
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(0);
  inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

  char buffer[INET_ADDRSTRLEN];
  printf("Scanning %s...\n", inet_ntop(AF_INET, &server_addr.sin_addr, buffer, INET_ADDRSTRLEN));

  for (int i = 1; i <= PORT_RANGE; i++) {
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(i);
    client_addr.sin_addr = server_addr.sin_addr;

    int connect_status = connect(sock, (struct sockaddr *)&client_addr, sizeof(client_addr));
    if (connect_status < 0) {
      perror("connect failed");
      continue;
    }

    char buffer2[INET_ADDRSTRLEN];
    printf("%s:%d\n", inet_ntop(AF_INET, &client_addr.sin_addr, buffer2, INET_ADDRSTRLEN));

    close(sock);
  }

  return 0;
}