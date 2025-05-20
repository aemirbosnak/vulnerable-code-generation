//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PENDING_CONNECTIONS 5
#define BUFFER_SIZE 512
#define DEFAULT_PORT 5000
#define DEFAULT_HOST "127.0.0.1"

typedef struct {
  int socket_fd;
  struct sockaddr_in address;
} server_t;

void initialize_server(server_t* server, char* host, int port) {
  server->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server->socket_fd < 0) {
    fprintf(stderr, "Error: Could not create socket\n");
    exit(EXIT_FAILURE);
  }

  memset(&server->address, 0, sizeof(server->address));
  server->address.sin_family = AF_INET;
  server->address.sin_addr.s_addr = inet_addr(host);
  server->address.sin_port = htons(port);
}

void start_server(server_t* server) {
  if (bind(server->socket_fd, (struct sockaddr*)&server->address, sizeof(server->address)) < 0) {
    fprintf(stderr, "Error: Could not bind to address\n");
    exit(EXIT_FAILURE);
  }

  if (listen(server->socket_fd, MAX_PENDING_CONNECTIONS) < 0) {
    fprintf(stderr, "Error: Could not listen on socket\n");
    exit(EXIT_FAILURE);
  }
}

void handle_client(int client_fd) {
  char buffer[BUFFER_SIZE] = {0};
  ssize_t num_bytes;

  do {
    num_bytes = recv(client_fd, buffer, BUFFER_SIZE, 0);
    if (num_bytes > 0) {
      printf("Received %ld bytes from client: %s\n", num_bytes, buffer);
      // Here you can perform your QoS computations and act accordingly
      send(client_fd, buffer, num_bytes, 0);
    }
  } while (num_bytes > 0);

  close(client_fd);
}

void run_server(server_t* server) {
  printf("Server running on %s:%d\n", inet_ntoa(server->address.sin_addr), ntohs(server->address.sin_port));

  while (1) {
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_fd = accept(server->socket_fd, (struct sockaddr*)&client_address, &client_address_len);
    if (client_fd < 0) {
      fprintf(stderr, "Error: Could not accept client connection\n");
      continue;
    }

    printf("Accepted client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    handle_client(client_fd);
  }
}

int main(int argc, char** argv) {
  int port = DEFAULT_PORT;
  char* host = DEFAULT_HOST;

  if (argc > 1) {
    host = argv[1];
  }

  if (argc > 2) {
    port = atoi(argv[2]);
  }

  server_t server;
  initialize_server(&server, host, port);
  start_server(&server);
  run_server(&server);

  exit(EXIT_SUCCESS);
}