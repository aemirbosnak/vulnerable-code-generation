//FormAI DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main() {
  int server_socket, new_socket;
  struct sockaddr_in server_address, client_address;
  char buffer[256];

  // create socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  // set server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_address.sin_port = htons(5000);

  // bind socket to address
  if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
    perror("Error binding socket");
    exit(EXIT_FAILURE);
  }

  // start listening
  if (listen(server_socket, 1) < 0) {
    perror("Error listening on socket");
    exit(EXIT_FAILURE);
  }

  printf("Server started, waiting for clients...\n");

  // accept connection
  socklen_t client_address_len = sizeof(client_address);
  new_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_len);
  if (new_socket < 0) {
    perror("Error accepting connection");
    exit(EXIT_FAILURE);
  }

  printf("Client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

  // send message to client
  char message[256];
  sprintf(message, "O Romeo, Romeo, wherefore art thou Romeo?\n");
  write(new_socket, message, strlen(message));

  // receive message from client
  read(new_socket, buffer, sizeof(buffer));
  printf("Received message: %s", buffer);

  // close sockets
  close(new_socket);
  close(server_socket);

  return 0;
}