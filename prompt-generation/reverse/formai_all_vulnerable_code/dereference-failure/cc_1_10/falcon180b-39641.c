//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
  int server_socket = -1, client_socket = -1;
  struct sockaddr_in server_addr, client_addr;
  char buffer[BUFFER_SIZE];
  int addrlen = sizeof(struct sockaddr_in);
  int opt = 1;

  if (argc!= 3) {
    printf("Usage: %s <server> <port>\n", argv[0]);
    exit(1);
  }

  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    printf("Error: Failed to create socket\n");
    exit(1);
  }

  setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

  if (connect(server_socket, (struct sockaddr *)&server_addr, addrlen) == -1) {
    printf("Error: Failed to connect to server\n");
    exit(1);
  }

  while (1) {
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
      printf("Error: Failed to receive data from server\n");
      exit(1);
    }

    send(client_socket, buffer, bytes_received, 0);
  }

  close(server_socket);
  close(client_socket);

  return 0;
}