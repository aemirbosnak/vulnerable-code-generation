//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: peaceful
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  int socket_fd, conn_fd;
  struct sockaddr_in server_addr, client_addr;
  struct hostent *server;
  char buffer[1024];

  if (argc < 2) {
    printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error: Unable to resolve server IP\n");
    exit(1);
  }

  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("Error: Failed to create socket\n");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
  server_addr.sin_port = htons(atoi(argv[2]));

  if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Error: Failed to connect to server\n");
    exit(1);
  }

  while (1) {
    if (read(socket_fd, buffer, sizeof(buffer)) == -1) {
      perror("Error: Failed to read from socket\n");
      exit(1);
    }
    printf("Server: %s\n", buffer);
  }

  return 0;
}