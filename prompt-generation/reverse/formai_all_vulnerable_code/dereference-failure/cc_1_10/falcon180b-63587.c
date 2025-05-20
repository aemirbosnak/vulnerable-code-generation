//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  int listen_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  char buffer[BUF_SIZE];
  int n, addr_len;

  if (argc!= 3) {
    printf("Usage: %s <IP address> <port>\n", argv[0]);
    exit(1);
  }

  listen_sock = socket(AF_INET, SOCK_STREAM, 0);

  if (listen_sock == -1) {
    printf("Error creating socket\n");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);

  if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    printf("Error binding socket\n");
    exit(1);
  }

  if (listen(listen_sock, 5) == -1) {
    printf("Error listening on socket\n");
    exit(1);
  }

  while (1) {
    addr_len = sizeof(client_addr);
    client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addr_len);

    if (client_sock == -1) {
      printf("Error accepting connection\n");
      exit(1);
    }

    printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (1) {
      n = recv(client_sock, buffer, BUF_SIZE, 0);

      if (n <= 0) {
        printf("Connection closed\n");
        break;
      }

      send(client_sock, buffer, n, 0);
    }

    close(client_sock);
  }

  return 0;
}