//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 100
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Error: Please specify a port number!\n");
    return 1;
  }

  int port = atoi(argv[1]);
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Socket creation failed");
    return 1;
  }

  struct sockaddr_in server_addr = {
    .sin_family = AF_INET,
    .sin_port = htons(port),
    .sin_addr.s_addr = INADDR_ANY
  };

  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Binding failed");
    return 1;
  }

  if (listen(sock, MAX_CLIENT_CONNECTIONS) < 0) {
    perror("Listening failed");
    return 1;
  }

  printf("Server listening on port %d...\n", port);

  while (1) {
    int client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
      perror("Accept failed");
      continue;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Read data from client
    read(client_sock, buffer, BUFFER_SIZE);

    // Print received message
    printf("Received message from client: %s\n", buffer);

    // Send a shocked response back to the client
    char *message = "OH MY GOD, YOU JUST CONNECTED TO MY SERVER!";
    send(client_sock, message, strlen(message), 0);

    // Close the client socket
    close(client_sock);
  }

  return 0;
}