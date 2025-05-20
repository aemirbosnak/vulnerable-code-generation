//FormAI DATASET v1.0 Category: Chat server ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *message) {
  perror(message);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  int server_fd, client_fd, port_num;
  struct sockaddr_in server_address, client_address;
  socklen_t address_size = sizeof(client_address);
  char buffer[BUFFER_SIZE] = {0};

  if (argc < 2) {
    printf("Usage: %s <port number>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  port_num = atoi(argv[1]);
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    error("Error creating socket.");
  }

  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port_num);

  if (bind(server_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
    error("Error binding to socket.");
  }

  if (listen(server_fd, 5) < 0) {
    error("Error listening on socket.");
  }

  printf("Server is running on port %d\n", port_num);

  while (1) {
    client_fd = accept(server_fd, (struct sockaddr*) &client_address, &address_size);
    if (client_fd < 0) {
      error("Error accepting incoming connection.");
    }

    while (1) {
      memset(buffer, 0, BUFFER_SIZE);
      if (recv(client_fd, buffer, BUFFER_SIZE, 0) < 0) {
        error("Error receiving message from client.");
      }

      if (strlen(buffer) > 0) {
        printf("Received message from client: %s", buffer);
        if (send(client_fd, buffer, strlen(buffer), 0) < 0) {
          error("Error sending message to client.");
        }
      }
    }

    close(client_fd);
  }

  return EXIT_SUCCESS;
}