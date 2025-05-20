//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUF_SIZE 1024

int create_socket() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  return sockfd;
}

void bind_socket(int sockfd, struct sockaddr_in *addr) {
  int bind_status = bind(sockfd, (struct sockaddr *)addr, sizeof(*addr));
  if (bind_status == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }
}

void listen_socket(int sockfd) {
  int listen_status = listen(sockfd, 5);
  if (listen_status == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }
}

int accept_connection(int sockfd, struct sockaddr_in *client_addr) {
  socklen_t client_addr_len = sizeof(*client_addr);
  int client_sockfd = accept(sockfd, (struct sockaddr *)client_addr, &client_addr_len);
  if (client_sockfd == -1) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  return client_sockfd;
}

void send_message(int sockfd, char *message) {
  int send_status = send(sockfd, message, strlen(message), 0);
  if (send_status == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }
}

char *receive_message(int sockfd) {
  char *buffer = malloc(MAX_BUF_SIZE);
  int recv_status = recv(sockfd, buffer, MAX_BUF_SIZE, 0);
  if (recv_status == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  return buffer;
}

void close_socket(int sockfd) {
  int close_status = close(sockfd);
  if (close_status == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  }
}

int main() {
  int sockfd = create_socket();

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  bind_socket(sockfd, &server_addr);
  listen_socket(sockfd);

  while (1) {
    struct sockaddr_in client_addr;
    int client_sockfd = accept_connection(sockfd, &client_addr);

    char *message = receive_message(client_sockfd);
    printf("Received message from client: %s\n", message);

    char *response = "Hello from server!";
    send_message(client_sockfd, response);

    close_socket(client_sockfd);
  }

  close_socket(sockfd);

  return 0;
}