//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#define MAX_MSG_LEN 512
#define MAX_CLIENTS 10
int sock_fd, client_fds[MAX_CLIENTS];
struct sockaddr_in serv_addr, client_addr;
bool running = true;
pthread_mutex_t lock;
void *client_thread(void *arg) {
  int client_fd = *(int *)arg;
  char msg_buf[MAX_MSG_LEN];
  while (running) {
    int recv_len = recv(client_fd, msg_buf, MAX_MSG_LEN, 0);
    if (recv_len <= 0) {
      printf("Client disconnected: %d\n", client_fd);
      close(client_fd);
      pthread_mutex_lock(&lock);
      int i;
      for (i = 0; i < MAX_CLIENTS; i++) {
        if (client_fds[i] == client_fd) {
          client_fds[i] = -1;
          break;
        }
      }
      pthread_mutex_unlock(&lock);
      break;
    }
    pthread_mutex_lock(&lock);
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
      int j;
      for (j = i + 1; j < MAX_CLIENTS; j++) {
        if (client_fds[i] != -1 && client_fds[j] != -1) {
          if (send(client_fds[i], msg_buf, recv_len, 0) == -1) {
            perror("send");
            exit(EXIT_FAILURE);
          }
          if (send(client_fds[j], msg_buf, recv_len, 0) == -1) {
            perror("send");
            exit(EXIT_FAILURE);
          }
        }
      }
    }
    pthread_mutex_unlock(&lock);
  }
  free(arg);
  return NULL;
}
int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  int port = atoi(argv[1]);
  sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
  serv_addr.sin_port = htons(port);
  if (bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }
  if (listen(sock_fd, 5) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }
  pthread_mutex_init(&lock, NULL);
  int i;
  for (i = 0; i < MAX_CLIENTS; i++) {
    client_fds[i] = -1;
  }
  while (running) {
    socklen_t client_addr_len = sizeof(client_addr);
    int client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_fd == -1) {
      perror("accept");
      continue;
    }
    pthread_t client_thread_id;
    int *client_fd_ptr = malloc(sizeof(int));
    *client_fd_ptr = client_fd;
    if (pthread_create(&client_thread_id, NULL, client_thread, client_fd_ptr) != 0) {
      perror("pthread_create");
      close(client_fd);
      continue;
    }
  }
  close(sock_fd);
  return EXIT_SUCCESS;
}