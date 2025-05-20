//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: Cryptic
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    printf("Cannot create server socket: %s\n", strerror(errno));
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(12345);

  if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    printf("Cannot bind server socket to address: %s\n", strerror(errno));
    return 1;
  }

  if (listen(server_fd, 5) < 0) {
    printf("Cannot listen on server socket: %s\n", strerror(errno));
    return 1;
  }

  int client_fd;
  socklen_t client_addr_len;
  struct sockaddr_in client_addr;

  while (1) {
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
    if (client_fd < 0) {
      printf("Cannot accept client connection: %s\n", strerror(errno));
      continue;
    }

    char buffer[1024];
    int nread;

    while ((nread = read(client_fd, buffer, sizeof(buffer))) > 0) {
      printf("Received %d bytes from client: %s\n", nread, buffer);
      if (write(client_fd, buffer, nread) < 0) {
        printf("Cannot write to client: %s\n", strerror(errno));
        break;
      }
    }

    if (nread == 0) {
      printf("Client closed connection\n");
    } else if (nread < 0) {
      printf("Cannot read from client: %s\n", strerror(errno));
    }

    close(client_fd);
  }

  return 0;
}