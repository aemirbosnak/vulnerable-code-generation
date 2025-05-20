//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: future-proof
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_CLIENTS 100
#define MAX_BUFFER_SIZE 4096

struct client {
  int fd;
  pthread_t thread;
  bool connected;
  struct sockaddr_in addr;
  char *hostname;
  int port;
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void *client_thread(void *arg) {
  struct client *client = (struct client *)arg;
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return NULL;
  }
  struct sockaddr_in serveraddr;
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(client->port);
  if (inet_pton(AF_INET, client->hostname, &serveraddr.sin_addr) <= 0) {
    perror("inet_pton");
    return NULL;
  }
  if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
    perror("connect");
    return NULL;
  }
  char buffer[MAX_BUFFER_SIZE];
  while (1) {
    int bytes_read = recv(client->fd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_read == -1) {
      perror("recv");
      break;
    } else if (bytes_read == 0) {
      break;
    }
    if (send(sockfd, buffer, bytes_read, 0) == -1) {
      perror("send");
      break;
    }
  }
  close(sockfd);
  close(client->fd);
  client->connected = false;
  return NULL;
}

void signal_handler(int signum) {
  for (int i = 0; i < num_clients; i++) {
    if (clients[i].connected) {
      pthread_cancel(clients[i].thread);
      close(clients[i].fd);
    }
  }
  exit(0);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <port> <hostname>\n", argv[0]);
    return 1;
  }
  int port = atoi(argv[1]);
  char *hostname = argv[2];
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }
  struct sockaddr_in serveraddr;
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = INADDR_ANY;
  serveraddr.sin_port = htons(port);
  if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
    perror("bind");
    return 1;
  }
  if (listen(sockfd, MAX_CLIENTS) == -1) {
    perror("listen");
    return 1;
  }
  signal(SIGINT, signal_handler);
  while (1) {
    struct sockaddr_in clientaddr;
    socklen_t clientaddrlen = sizeof(clientaddr);
    int clientfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientaddrlen);
    if (clientfd == -1) {
      perror("accept");
      continue;
    }
    if (num_clients == MAX_CLIENTS) {
      close(clientfd);
      continue;
    }
    char *client_hostname = inet_ntoa(clientaddr.sin_addr);
    int client_port = ntohs(clientaddr.sin_port);
    struct client client = {
      .fd = clientfd,
      .connected = true,
      .addr = clientaddr,
      .hostname = strdup(client_hostname),
      .port = client_port,
    };
    clients[num_clients++] = client;
    pthread_create(&client.thread, NULL, client_thread, &client);
  }
  close(sockfd);
  return 0;
}