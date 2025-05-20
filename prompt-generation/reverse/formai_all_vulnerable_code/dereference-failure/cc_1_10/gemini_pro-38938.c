//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
    exit(1);
  }

  char *ip = argv[1];
  int port = atoi(argv[2]);

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip);
  addr.sin_port = htons(port);

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    exit(1);
  }

  if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    exit(1);
  }

  if (listen(sock, 5) == -1) {
    perror("listen");
    exit(1);
  }

  printf("Listening on %s:%d\n", ip, port);

  while (1) {
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    socklen_t client_addr_len = sizeof(client_addr);

    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock == -1) {
      perror("accept");
      continue;
    }

    printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    char buf[1024];
    int n;
    while ((n = read(client_sock, buf, sizeof(buf))) > 0) {
      buf[n] = '\0';
      printf("Received: %s\n", buf);

      if (strcmp(buf, "exit") == 0) {
        break;
      }

      write(client_sock, buf, n);
    }

    close(client_sock);
  }

  close(sock);

  return 0;
}