//FormAI DATASET v1.0 Category: Client Server Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int server_socket, client_socket, port_number, client_count = 0;
  struct sockaddr_in server_address, client_address;
  socklen_t client_address_len = sizeof(client_address);
  char buffer[BUFFER_SIZE];

  // Check if port number is provided
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create socket
  if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Set server address properties
  memset(&server_address, 0, sizeof(server_address));
  port_number = atoi(argv[1]);
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port_number);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // Bind socket to server address
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("Socket bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for client connections
  if (listen(server_socket, MAX_CLIENTS) == -1) {
    perror("Socket listen failed");
    exit(EXIT_FAILURE);
  }

  // Accept and handle client connections
  while ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len))) {
    client_count++;
    printf("Client %d connected.\n", client_count);

    // Receive and send data with client
    while (recv(client_socket, buffer, BUFFER_SIZE, 0) > 0) {
      printf("Received data: %s", buffer);
      strcat(buffer, " (Server Response)");
      send(client_socket, buffer, strlen(buffer), 0);
      memset(buffer, 0, BUFFER_SIZE);
    }

    // Close connection
    printf("Client %d disconnected.\n", client_count);
    close(client_socket);
  }

  // Close server socket
  close(server_socket);

  return 0;
}