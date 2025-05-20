//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CONNECTIONS 10
#define BUFFERSIZE 1024

struct client_info {
  int socket;
  struct sockaddr_in addr;
  socklen_t addr_len;
};

void *handle_client(void *arg) {
  struct client_info *client = (struct client_info *)arg;
  char buffer[BUFFERSIZE];
  int bytes_received;

  while ((bytes_received = recv(client->socket, buffer, BUFFERSIZE, 0)) > 0) {
    printf("Received %d bytes from client %s:%d\n", bytes_received, inet_ntoa(client->addr.sin_addr), ntohs(client->addr.sin_port));

    // Process the request here...

    // Send a response back to the client
    send(client->socket, "HTTP/1.1 200 OK\r\n\r\nHello, world!", 35, 0);
  }

  if (bytes_received == 0) {
    printf("Client %s:%d disconnected\n", inet_ntoa(client->addr.sin_addr), ntohs(client->addr.sin_port));
  } else {
    perror("recv() failed");
  }

  close(client->socket);
  free(client);
  return NULL;
}

int main(int argc, char **argv) {
  int server_socket, client_socket;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_len;
  pthread_t thread;

  // Create a server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket() failed");
    return 1;
  }

  // Set up the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(80);

  // Bind the server socket to the address
  if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind() failed");
    return 1;
  }

  // Listen for incoming connections
  if (listen(server_socket, MAX_CONNECTIONS) == -1) {
    perror("listen() failed");
    return 1;
  }

  printf("Server listening on port 80\n");

  // Accept incoming connections and handle them in a separate thread
  while (1) {
    addr_len = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
    if (client_socket == -1) {
      perror("accept() failed");
      return 1;
    }

    printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    struct client_info *client = malloc(sizeof(struct client_info));
    client->socket = client_socket;
    client->addr = client_addr;
    client->addr_len = addr_len;

    pthread_create(&thread, NULL, handle_client, (void *)client);
  }

  // Close the server socket
  close(server_socket);

  return 0;
}