//FormAI DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

void *thread_function(void *arg) {
  int sock_fd = *(int *)arg;
  char buffer[BUFFER_SIZE];
  char *message = "Welcome to my awesome server!\n";
  write(sock_fd, message, strlen(message));
  while (1) {
    memset(buffer, 0, BUFFER_SIZE);
    ssize_t recv_status = recv(sock_fd, buffer, BUFFER_SIZE, 0);
    if (recv_status == 0) {
      break;
    } else if (recv_status == -1) {
      perror("Error in receiving message from client");
      break;
    } else {
      printf("Received message from client: %s", buffer);
      write(sock_fd, buffer, strlen(buffer));
    }
  }
  close(sock_fd);
  printf("Connection closed\n");
  pthread_exit(NULL);
}

int main(int argc, char **argv) {
  int server_fd, client_fd, port_num;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len;

  if (argc != 2) {
    fprintf(stderr, "Usage: ./server <port_number>\n");
    exit(1);
  }

  port_num = atoi(argv[1]);

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Error in creating server socket");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(port_num);

  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error in binding server socket");
    exit(1);
  }

  if (listen(server_fd, MAX_CONNECTIONS) < 0) {
    perror("Error in listening to server socket");
    exit(1);
  }

  printf("Server running on port %d...\n", port_num);

  while (1) {
    client_len = sizeof(client_addr);
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
      perror("Error in accepting connection");
      exit(1);
    }

    printf("New connection established\n");

    pthread_t thread;
    if (pthread_create(&thread, NULL, thread_function, (void *)&client_fd) != 0) {
      perror("Error in creating thread");
      exit(1);
    }
  }

  return 0;
}