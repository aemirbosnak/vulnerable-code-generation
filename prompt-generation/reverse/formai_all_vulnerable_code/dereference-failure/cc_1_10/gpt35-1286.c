//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 4096
#define PORT 8080
#define REMOTE_HOST "www.example.com"
#define REMOTE_PORT 80

int create_socket() {
  int s = socket(AF_INET, SOCK_STREAM, 0);
  if (s == -1) {
    perror("Failed to create socket");
    exit(1);
  }
  return s;
}

void bind_socket(int sockfd, int port) {
  struct sockaddr_in addr = {0};
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(port);

  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("Failed to bind socket");
    exit(1);
  }
}

void connect_remote(int sockfd) {
  struct sockaddr_in addr = {0};
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(REMOTE_HOST);
  addr.sin_port = htons(REMOTE_PORT);

  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("Failed to connect to remote server");
    exit(1);
  }
}

void forward_data(int client_sockfd, int remote_sockfd) {
  char buf[BUF_SIZE];
  ssize_t bytes_read;

  while ((bytes_read = read(client_sockfd, buf, BUF_SIZE)) > 0) {
    if (write(remote_sockfd, buf, bytes_read) == -1) {
      perror("Failed to write to remote server");
      exit(1);
    }
  }
}

void handle_client(int client_sockfd) {
  int remote_sockfd = create_socket();
  connect_remote(remote_sockfd);

  pid_t pid = fork();
  if (pid == -1) {
    perror("Failed to fork");
    exit(1);
  } else if (pid == 0) {
    forward_data(remote_sockfd, client_sockfd);
    exit(0);
  }

  forward_data(client_sockfd, remote_sockfd);
  close(remote_sockfd);
}

void run_proxy() {
  int sockfd = create_socket();
  bind_socket(sockfd, PORT);

  if (listen(sockfd, 10) == -1) {
    perror("Failed to listen");
    exit(1);
  }

  printf("Proxy listening on port %d...\n", PORT);

  while (1) {
    int client_sockfd = accept(sockfd, NULL, NULL);
    if (client_sockfd == -1) {
      if (errno == EINTR) {
        continue;
      }
      perror("Failed to accept");
      exit(1);
    }

    handle_client(client_sockfd);
    close(client_sockfd);
  }
}

int main() {
  run_proxy();
  return 0;
}