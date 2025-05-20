//FormAI DATASET v1.0 Category: Client Server Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10

void *handle_client(void *);

int main(int argc, char const *argv[]) {
  int server_fd, client_fd;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len;
  pthread_t threads[MAX_CLIENTS];

  // create server socket
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == -1) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  // set server address details
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(8080);

  // bind the socket with the server address
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // start server to listen for incoming connections
  if (listen(server_fd, MAX_CLIENTS) == -1) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server started on port %d\n", ntohs(server_addr.sin_port));

  // wait for incoming connections and create threads to handle each client
  while (1) {
    client_len = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd == -1) {
      perror("accept failed");
      exit(EXIT_FAILURE);
    }

    // create a new thread to handle the client
    pthread_create(&threads[MAX_CLIENTS], NULL, handle_client, (void *)&client_fd);
  }

  close(server_fd);

  return 0;
}

void *handle_client(void *arg) {
  int client_fd = *(int *)arg;
  int bytes_read;
  char buffer[1024];

  printf("Client connected\n");

  // send welcome message to client
  const char *message = "Welcome to the server!";
  if (send(client_fd, message, strlen(message), 0) == -1) {
    perror("send failed");
    close(client_fd);
    return NULL;
  }

  // read data from client and print to console
  while ((bytes_read = recv(client_fd, buffer, sizeof(buffer), 0)) > 0) {
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);

    // send response to client
    if (send(client_fd, buffer, bytes_read, 0) == -1) {
      perror("send failed");
      close(client_fd);
      return NULL;
    }
  }

  close(client_fd);
  printf("Client disconnected\n");

  return NULL;
}