//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <pthread.h>

int main(int argc, char *argv[]) {
  int listen_socket, client_socket;
  struct sockaddr_in server_addr, client_addr;
  char *message = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n<!DOCTYPE html><html><head><title>Simple Web Server</title></head><body><h1>Welcome to the Simple Web Server</h1></body></html>";
  int addrlen;
  int yes = 1;
  int client_len;
  char buffer[1024];
  pthread_t thread_id;

  if (argc!= 2) {
    printf("Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  listen_socket = socket(AF_INET, SOCK_STREAM, 0);

  if (listen_socket == -1) {
    printf("Error creating socket\n");
    exit(1);
  }

  setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&yes, sizeof(yes));

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[1]));
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    printf("Error binding socket\n");
    exit(1);
  }

  if (listen(listen_socket, 5) == -1) {
    printf("Error listening on socket\n");
    exit(1);
  }

  addrlen = sizeof(client_addr);
  while (1) {
    client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);

    if (client_socket == -1) {
      printf("Error accepting connection\n");
      continue;
    }

    client_len = strlen(message);
    send(client_socket, message, client_len, 0);

    close(client_socket);
  }

  return 0;
}