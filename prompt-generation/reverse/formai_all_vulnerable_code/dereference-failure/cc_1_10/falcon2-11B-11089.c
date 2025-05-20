//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BACKLOG 10
#define BUFSIZE 4096

int main(int argc, char *argv[]) {
  int listen_fd, conn_fd, nread;
  char buffer[BUFSIZE];
  struct sockaddr_in server_addr, client_addr;

  if (argc!= 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return 1;
  }

  listen_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_fd < 0) {
    perror("Error opening socket");
    return 1;
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(atoi(argv[1]));

  if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error on binding");
    return 1;
  }

  if (listen(listen_fd, BACKLOG) < 0) {
    perror("Error on listening");
    return 1;
  }

  while (1) {
    conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, (socklen_t*)&nread);
    if (conn_fd < 0) {
      perror("Error on accept");
      continue;
    }

    printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while ((nread = recv(conn_fd, buffer, BUFSIZE, 0)) > 0) {
      printf("%s\n", buffer);
      send(conn_fd, buffer, nread, 0);
    }

    close(conn_fd);
  }

  close(listen_fd);
  return 0;
}