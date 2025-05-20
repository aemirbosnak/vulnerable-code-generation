//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: Cryptic
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#define PORT 31337
#define MAX_CLIENTS 10

struct client {
  int sockfd;
  struct sockaddr_in addr;
};

struct thread_args {
  int sockfd;
  struct sockaddr_in addr;
};

void *handle_client(void *args) {
  struct thread_args *arg = args;
  int sockfd = arg->sockfd;
  struct sockaddr_in addr = arg->addr;
  char buf[1024];

  while (1) {
    int n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
      perror("recv");
      break;
    } else if (n == 0) {
      printf("Client %s disconnected\n", inet_ntoa(addr.sin_addr));
      break;
    }
    printf("Received message from %s: %s\n", inet_ntoa(addr.sin_addr), buf);
    if (strcmp(buf, "quit") == 0) {
      break;
    }
    if (n > 0) {
      send(sockfd, buf, n, 0);
    }
  }

  close(sockfd);
  pthread_exit(NULL);
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in addr, cli_addr;
  socklen_t cli_addr_len;
  pthread_t threads[MAX_CLIENTS];
  int i = 0;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    return 1;
  }

  if (listen(sockfd, MAX_CLIENTS) == -1) {
    perror("listen");
    return 1;
  }

  while (1) {
    cli_addr_len = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_addr_len);
    if (newsockfd == -1) {
      perror("accept");
      continue;
    }

    struct thread_args *arg = malloc(sizeof(struct thread_args));
    arg->sockfd = newsockfd;
    arg->addr = cli_addr;

    pthread_create(&threads[i++], NULL, handle_client, arg);
  }

  close(sockfd);
  return 0;
}