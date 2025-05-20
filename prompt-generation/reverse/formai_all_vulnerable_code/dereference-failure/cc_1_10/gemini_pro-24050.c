//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <errno.h>

#define PORT_RANGE 65535
#define MAX_CONNECTIONS 1000
#define TIMEOUT_SECONDS 3
#define SOCKET_ERROR -1
#define INVALID_SOCKET -1

struct sockaddr_in server_addr;
int server_sockfd;
int client_sockfd;
int port_list[PORT_RANGE];
int connection_count;

void create_server_socket() {
  server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sockfd == INVALID_SOCKET) {
    perror("socket");
    exit(EXIT_FAILURE);
  }
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(0);
}

void bind_server_socket() {
  if (bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
    perror("bind");
    exit(EXIT_FAILURE);
  }
}

void listen_to_server_socket() {
  if (listen(server_sockfd, MAX_CONNECTIONS) == SOCKET_ERROR) {
    perror("listen");
    exit(EXIT_FAILURE);
  }
}

void accept_client_connections() {
  struct sockaddr_in client_addr;
  socklen_t client_addr_len;
  fd_set read_fds;
  struct timeval timeout;
  while (connection_count < MAX_CONNECTIONS) {
    FD_ZERO(&read_fds);
    FD_SET(server_sockfd, &read_fds);
    timeout.tv_sec = TIMEOUT_SECONDS;
    timeout.tv_usec = 0;
    if (select(server_sockfd + 1, &read_fds, NULL, NULL, &timeout) > 0) {
      client_addr_len = sizeof(client_addr);
      client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
      if (client_sockfd == SOCKET_ERROR) {
        perror("accept");
      } else {
        connection_count++;
      }
    } else {
      break;
    }
  }
}

void scan_ports() {
  int i;
  int port;
  int success;
  struct timeval start, end;
  double time_taken;
  for (i = 0; i < PORT_RANGE; i++) {
    port = i + 1;
    server_addr.sin_port = htons(port);
    gettimeofday(&start, NULL);
    success = connect(client_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0;
    gettimeofday(&end, NULL);
    time_taken = (double)(end.tv_usec - start.tv_usec) / 1000000 + (double)(end.tv_sec - start.tv_sec);
    if (success && time_taken < TIMEOUT_SECONDS) {
      port_list[i] = port;
    }
  }
}

void close_sockets() {
  close(server_sockfd);
  close(client_sockfd);
}

void print_port_list() {
  int i;
  for (i = 0; i < PORT_RANGE; i++) {
    if (port_list[i] != 0) {
      printf("%d\n", port_list[i]);
    }
  }
}

int main() {
  srand(time(NULL));
  connection_count = 0;
  create_server_socket();
  bind_server_socket();
  listen_to_server_socket();
  accept_client_connections();
  scan_ports();
  print_port_list();
  close_sockets();
  return EXIT_SUCCESS;
}