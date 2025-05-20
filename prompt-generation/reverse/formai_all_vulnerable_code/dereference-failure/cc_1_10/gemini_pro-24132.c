//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

typedef struct client {
  int fd;
  struct sockaddr_in addr;
  char name[32];
  pthread_t thread;
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;
int sockfd;

void handle_client(void *arg) {
  client_t *client = (client_t *)arg;
  char buf[MAX_MSG_SIZE];
  int n;

  while ((n = recv(client->fd, buf, MAX_MSG_SIZE, 0)) > 0) {
    buf[n] = '\0';
    printf("Client %s: %s\n", client->name, buf);

    for (int i = 0; i < num_clients; i++) {
      if (clients[i].fd != client->fd) {
        send(clients[i].fd, buf, n, 0);
      }
    }
  }

  if (n == 0) {
    printf("Client %s disconnected\n", client->name);
  } else {
    printf("Error receiving from client %s: %s\n", client->name, strerror(errno));
  }

  close(client->fd);
  num_clients--;
}

int main(int argc, char **argv) {
  struct sockaddr_in servaddr;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket()");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(atoi(argv[1]));

  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind()");
    exit(1);
  }

  if (listen(sockfd, MAX_CLIENTS) < 0) {
    perror("listen()");
    exit(1);
  }

  while (1) {
    struct sockaddr_in cliaddr;
    socklen_t cliaddr_len = sizeof(cliaddr);
    int client_fd;

    if ((client_fd = accept(sockfd, (struct sockaddr *)&cliaddr, &cliaddr_len)) < 0) {
      perror("accept()");
      continue;
    }

    if (num_clients >= MAX_CLIENTS) {
      printf("Maximum number of clients reached\n");
      close(client_fd);
      continue;
    }

    clients[num_clients].fd = client_fd;
    clients[num_clients].addr = cliaddr;
    sprintf(clients[num_clients].name, "Client %d", num_clients + 1);
    pthread_create(&clients[num_clients].thread, NULL, handle_client, &clients[num_clients]);
    num_clients++;

    printf("Client %s connected\n", clients[num_clients - 1].name);
  }

  return 0;
}