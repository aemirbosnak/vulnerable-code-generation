//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

typedef struct {
  int sockfd;
  struct sockaddr_in addr;
  socklen_t addrlen;
} connection_t;

connection_t *new_connection() {
  connection_t *conn = malloc(sizeof(connection_t));
  if (conn == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  conn->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (conn->sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }
  conn->addr.sin_family = AF_INET;
  conn->addr.sin_addr.s_addr = INADDR_ANY;
  conn->addr.sin_port = htons(PORT);
  conn->addrlen = sizeof(conn->addr);
  return conn;
}

void close_connection(connection_t *conn) {
  close(conn->sockfd);
  free(conn);
}

int main() {
  connection_t *conn = new_connection();

  if (bind(conn->sockfd, (struct sockaddr *)&conn->addr, conn->addrlen) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  if (listen(conn->sockfd, 5) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  while (1) {
    int newsockfd = accept(conn->sockfd, (struct sockaddr *)&conn->addr, &conn->addrlen);
    if (newsockfd == -1) {
      perror("accept");
      continue;
    }

    char buffer[1024];
    int n = read(newsockfd, buffer, sizeof(buffer));
    if (n == -1) {
      perror("read");
      close(newsockfd);
      continue;
    }

    char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello, world!";
    n = write(newsockfd, response, strlen(response));
    if (n == -1) {
      perror("write");
      close(newsockfd);
      continue;
    }

    close(newsockfd);
  }

  close_connection(conn);

  return EXIT_SUCCESS;
}