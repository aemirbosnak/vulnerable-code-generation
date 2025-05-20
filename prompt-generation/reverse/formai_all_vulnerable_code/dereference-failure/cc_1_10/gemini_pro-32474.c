//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

typedef struct {
  int socket;
  struct sockaddr_in addr;
} client_t;

void *handle_client(void *arg) {
  client_t *client = (client_t *)arg;

  // Receive data from the client
  char buffer[BUFFER_SIZE];
  int n;
  while ((n = recv(client->socket, buffer, BUFFER_SIZE, 0)) > 0) {
    // Process the data
    printf("Received data from client: %s\n", buffer);

    // Send data back to the client
    send(client->socket, "Hello from server!", strlen("Hello from server!") + 1, 0);
  }

  // Close the client socket
  close(client->socket);

  // Free the memory allocated to the client
  free(client);

  return NULL;
}

int main() {
  // Create a socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the socket options
  int opt = 1;
  if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
    perror("setsockopt");
    return EXIT_FAILURE;
  }

  // Bind the socket to the address
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);
  if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(server_socket, 5) == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept incoming connections
  while (1) {
    client_t *client = malloc(sizeof(client_t));
    if (client == NULL) {
      perror("malloc");
      return EXIT_FAILURE;
    }

    client->socket = accept(server_socket, (struct sockaddr *)&client->addr, (socklen_t *)&client->addr);
    if (client->socket == -1) {
      perror("accept");
      continue;
    }

    // Create a thread to handle the client
    pthread_t thread;
    if (pthread_create(&thread, NULL, handle_client, (void *)client) != 0) {
      perror("pthread_create");
      continue;
    }

    // Detach the thread so that it can run independently
    pthread_detach(thread);
  }

  // Close the server socket
  close(server_socket);

  return EXIT_SUCCESS;
}