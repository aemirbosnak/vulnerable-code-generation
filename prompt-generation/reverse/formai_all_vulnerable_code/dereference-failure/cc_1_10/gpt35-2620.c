//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/select.h>

#define BUF_SIZE 1024

void handle_client(int client_fd) {
  while (true) {
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(client_fd, &read_fds);

    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    int select_ret = select(client_fd + 1, &read_fds, NULL, NULL, &timeout);
    if (select_ret < 0) {
      perror("select");
      break;
    } else if (select_ret == 0) {
      printf("Client timed out, disconnecting.\n");
      break;
    }

    char buffer[BUF_SIZE];
    ssize_t recv_ret = recv(client_fd, buffer, BUF_SIZE, 0);
    if (recv_ret == -1) {
      perror("recv");
      break;
    } else if (recv_ret == 0) {
      printf("Client disconnected.\n");
      break;
    }

    buffer[recv_ret] = '\0';
    printf("Received from client: %s", buffer);

    ssize_t send_ret = send(client_fd, buffer, strlen(buffer), 0);
    if (send_ret == -1) {
      perror("send");
      break;
    }
  }

  close(client_fd);
}

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s [port]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int port = atoi(argv[1]);
  printf("Server is listening on port %d.\n", port);

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  int optval = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 10) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  while (true) {
    struct sockaddr_in client_addr;
    socklen_t client_addrlen = sizeof(client_addr);

    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addrlen);
    if (client_fd == -1) {
      perror("accept");
      continue;
    }

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
    printf("New client connected from %s:%d.\n", client_ip, ntohs(client_addr.sin_port));

    handle_client(client_fd);
  }

  close(server_fd);
  return EXIT_SUCCESS;
}