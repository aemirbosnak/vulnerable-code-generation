//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define MAX_MSG_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t client_sockets_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
  int client_socket = *(int *)arg;
  char msg[MAX_MSG_SIZE];

  while (1) {
    // Receive message from client
    int recv_len = recv(client_socket, msg, MAX_MSG_SIZE, 0);
    if (recv_len == 0) {
      // Client disconnected
      pthread_mutex_lock(&client_sockets_mutex);
      for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == client_socket) {
          client_sockets[i] = 0;
          num_clients--;
          break;
        }
      }
      pthread_mutex_unlock(&client_sockets_mutex);
      break;
    }

    // Process message
    // ...

    // Send message to all clients
    pthread_mutex_lock(&client_sockets_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
      if (client_sockets[i] != 0) {
        send(client_sockets[i], msg, recv_len, 0);
      }
    }
    pthread_mutex_unlock(&client_sockets_mutex);
  }

  // Cleanup
  close(client_socket);
  free(arg);
  return NULL;
}

int main() {
  // Create server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return 1;
  }

  // Bind server socket to port
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);
  if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    return 1;
  }

  // Listen for incoming connections
  if (listen(server_socket, MAX_CLIENTS) == -1) {
    perror("listen");
    return 1;
  }

  while (1) {
    // Accept incoming connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Add client socket to list of client sockets
    pthread_mutex_lock(&client_sockets_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
      if (client_sockets[i] == 0) {
        client_sockets[i] = client_socket;
        num_clients++;
        break;
      }
    }
    pthread_mutex_unlock(&client_sockets_mutex);

    // Create thread to handle client
    pthread_t *client_thread = malloc(sizeof(pthread_t));
    pthread_create(client_thread, NULL, handle_client, &client_socket);
  }

  // Cleanup
  close(server_socket);
  pthread_mutex_destroy(&client_sockets_mutex);
  return 0;
}