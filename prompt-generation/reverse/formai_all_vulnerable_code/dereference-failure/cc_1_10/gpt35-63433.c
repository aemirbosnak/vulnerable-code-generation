//FormAI DATASET v1.0 Category: Chat server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 5000
#define MAX_CLIENTS 100

int clients[MAX_CLIENTS];
int num_clients = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast(char *message, int sender) {
  pthread_mutex_lock(&mutex);
  for (int i = 0; i < num_clients; i++) {
    if (clients[i] != sender) {
      send(clients[i], message, strlen(message), 0);
    }
  }
  pthread_mutex_unlock(&mutex);
}

void *handle_client(void *arg) {
  int client_sock = *(int*) arg;
  free(arg);

  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));

  while (recv(client_sock, buffer, sizeof(buffer), 0) > 0) {
    buffer[strcspn(buffer, "\n")] = 0;  // trim new line character
    printf("Received message: %s\n", buffer);
    broadcast(buffer, client_sock);
    memset(buffer, 0, sizeof(buffer));
  }

  pthread_mutex_lock(&mutex);
  for (int i = 0; i < num_clients; i++) {
    if (clients[i] == client_sock) {
      memmove(clients + i, clients + i + 1, (num_clients - i - 1) * sizeof(int));
      break;
    }
  }
  num_clients--;
  pthread_mutex_unlock(&mutex);

  close(client_sock);
  pthread_exit(NULL);
}

int main(int argc, char **argv) {
  int server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  int option = 1;
  if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) == -1) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  if (bind(server_sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  if (listen(server_sock, MAX_CLIENTS) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  printf("Server started on port %d.\n", PORT);

  while (1) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(server_sock, (struct sockaddr*) &client_addr, &client_len);
    if (client_sock == -1) {
      perror("accept");
      continue;
    }

    pthread_t tid;
    int *arg = malloc(sizeof(int));
    *arg = client_sock;
    pthread_create(&tid, NULL, &handle_client, arg);

    pthread_mutex_lock(&mutex);
    clients[num_clients++] = client_sock;
    pthread_mutex_unlock(&mutex);
  }

  close(server_sock);
  return 0;
}