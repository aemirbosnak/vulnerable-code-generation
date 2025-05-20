//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 10240

struct client_data {
  int client_socket;
  int server_socket;
};

void *handle_client(void *arg) {
  struct client_data *client = (struct client_data *)arg;
  char buffer[BUFFER_SIZE];
  int num_bytes;

  // Receive data from the client
  while ((num_bytes = recv(client->client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
    // Send the data to the server
    send(client->server_socket, buffer, num_bytes, 0);
  }

  // Close the client and server sockets
  close(client->client_socket);
  close(client->server_socket);

  // Free the client data
  free(client);

  return NULL;
}

int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_addr_len;

  // Create the server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    perror("socket");
    exit(1);
  }

  // Set the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Bind the server socket to the address
  if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(server_socket, 5) < 0) {
    perror("listen");
    exit(1);
  }

  while (1) {
    // Accept an incoming connection
    client_addr_len = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_socket < 0) {
      perror("accept");
      continue;
    }

    // Create a new thread to handle the client
    pthread_t thread;
    struct client_data *client = malloc(sizeof(struct client_data));
    client->client_socket = client_socket;

    // Connect to the server
    client->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->server_socket < 0) {
      perror("socket");
      close(client_socket);
      continue;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client->server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("connect");
      close(client_socket);
      close(client->server_socket);
      continue;
    }

    pthread_create(&thread, NULL, handle_client, client);
  }

  // Close the server socket
  close(server_socket);

  return 0;
}