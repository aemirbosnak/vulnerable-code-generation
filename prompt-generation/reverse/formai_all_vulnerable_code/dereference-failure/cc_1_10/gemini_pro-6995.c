//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_LINE 256
#define MAX_BUF 2048

struct client_info {
  int fd;
  struct sockaddr_in addr;
};

void *client_thread(void *arg) {
  struct client_info *client = (struct client_info *)arg;
  char buf[MAX_BUF];
  int n;

  while ((n = recv(client->fd, buf, MAX_BUF, 0)) > 0) {
    buf[n] = '\0';
    printf("Client: %s", buf);
    if (strcmp(buf, "QUIT\r\n") == 0) {
      break;
    }
  }

  close(client->fd);
  free(client);

  return NULL;
}

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in servaddr, cliaddr;
  int port = atoi(argv[1]);
  socklen_t len;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(port);

  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind");
    exit(1);
  }

  if (listen(sockfd, 5) < 0) {
    perror("listen");
    exit(1);
  }

  while (1) {
    len = sizeof(cliaddr);
    int newfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
    if (newfd < 0) {
      perror("accept");
      continue;
    }

    printf("Client connected: %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

    struct client_info *client = malloc(sizeof(struct client_info));
    client->fd = newfd;
    client->addr = cliaddr;

    pthread_t tid;
    pthread_create(&tid, NULL, client_thread, (void *)client);
  }

  close(sockfd);

  return 0;
}