//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

// Obfuscate hidden message.
int decode(char *msg) {
  char *p = msg;
  while (*p) {
    *p++ -= 1;
  }
  return 0;
}

int main(int argc, char **argv) {
  int server_fd, client_fd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[1024];
  int opt = 1;

  // Create and bind server socket.
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt failed");
    exit(EXIT_FAILURE);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for connections.
  if (listen(server_fd, 3) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  // Accept connection from client.
  int addrlen = sizeof(client_addr);
  if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen)) < 0) {
    perror("accept failed");
    exit(EXIT_FAILURE);
  }

  // Receive message from client.
  if (read(client_fd, buffer, sizeof(buffer)) < 0) {
    perror("read failed");
    exit(EXIT_FAILURE);
  }

  // Decrypt and print message.
  decode(buffer);
  printf("Message from client: %s\n", buffer);

  // Clean up.
  close(client_fd);
  close(server_fd);

  return 0;
}