//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
  int sock_client, sock_server;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len = sizeof(client_addr);
  char buffer[256];

  // Create the socket
  sock_client = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_client < 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Set up the server socket
  sock_server = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_server < 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Set up the server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

  // Bind the server socket
  if (bind(sock_server, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(sock_server, 3) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d...\n", PORT);

  // Accept an incoming connection
  sock_client = accept(sock_server, (struct sockaddr *)&client_addr, &client_len);
  if (sock_client < 0) {
    perror("accept failed");
    exit(EXIT_FAILURE);
  }

  printf("Client connected...\n");

  // Read message from client
  read(sock_client, buffer, 256);
  printf("Client message: %s\n", buffer);

  // Echo message back to client
  send(sock_client, buffer, strlen(buffer), 0);

  // Close the client socket
  close(sock_client);

  // Close the server socket
  close(sock_server);

  return 0;
}