//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5
#define PORT_RANGE 1024

int main(int argc, char *argv[]) {
  int sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len = sizeof(client_addr);
  char buffer[1024];
  int port;

  if (argc < 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return 1;
  }

  port = atoi(argv[1]);

  if (port < 0 || port > PORT_RANGE) {
    printf("Invalid port number: %d\n", port);
    return 1;
  }

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket failed");
    return 1;
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(port);

  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    return 1;
  }

  if (listen(sock, MAX_CLIENTS) < 0) {
    perror("listen failed");
    return 1;
  }

  printf("Listening on port %d...\n", port);

  while (1) {
    client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
      perror("accept failed");
      continue;
    }

    printf("Connection from %s\n", inet_ntoa(client_addr.sin_addr));

    // Do something with the client connection
    recv(client_sock, buffer, 1024, 0);
    send(client_sock, "Hello, client!", 13, 0);

    close(client_sock);
  }

  close(sock);

  return 0;
}