//GEMINI-pro DATASET v1.0 Category: Networking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

struct client_data {
  int sockfd;
  struct sockaddr_in addr;
};

void *client_handler(void *arg) {
  struct client_data *data = (struct client_data *)arg;
  char buf[1024];
  int n;

  while ((n = read(data->sockfd, buf, sizeof(buf))) > 0) {
    buf[n] = '\0';
    printf("Received: %s", buf);
    write(data->sockfd, buf, n);
  }

  close(data->sockfd);
  free(data);
  return NULL;
}

int main() {
  int sockfd, newsockfd, n;
  struct sockaddr_in serv_addr, cli_addr;
  socklen_t clilen;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind");
    exit(1);
  }

  listen(sockfd, 5);

  while (1) {
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("accept");
      exit(1);
    }

    struct client_data *data = malloc(sizeof(struct client_data));
    data->sockfd = newsockfd;
    data->addr = cli_addr;

    pthread_t thread;
    pthread_create(&thread, NULL, client_handler, (void *)data);
  }

  return 0;
}