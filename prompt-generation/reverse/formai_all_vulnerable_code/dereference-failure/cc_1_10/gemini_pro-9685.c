//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

typedef struct {
  int fd;
  struct sockaddr_in addr;
} connection;

connection* make_connection(const char* ip, int port) {
  connection* conn = malloc(sizeof(connection));
  conn->fd = socket(AF_INET, SOCK_STREAM, 0);
  if (conn->fd == -1) {
    perror("socket");
    return NULL;
  }
  conn->addr.sin_family = AF_INET;
  conn->addr.sin_port = htons(port);
  if (inet_pton(AF_INET, ip, &conn->addr.sin_addr) != 1) {
    perror("inet_pton");
    return NULL;
  }
  return conn;
}

int send_message(connection* conn, const char* msg) {
  int nbytes = send(conn->fd, msg, strlen(msg), 0);
  if (nbytes == -1) {
    perror("send");
    return -1;
  }
  return nbytes;
}

int receive_message(connection* conn, char* buf, int buf_size) {
  int nbytes = recv(conn->fd, buf, buf_size, 0);
  if (nbytes == -1) {
    perror("recv");
    return -1;
  }
  return nbytes;
}

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: %s <ip> <port>\n", argv[0]);
    return 1;
  }

  connection* conn = make_connection(argv[1], atoi(argv[2]));
  if (conn == NULL) {
    return 1;
  }

  char buf[BUF_SIZE];
  while (1) {
    printf("> ");
    fgets(buf, BUF_SIZE, stdin);
    if (feof(stdin)) {
      break;
    }
    if (send_message(conn, buf) == -1) {
      break;
    }
  }

  close(conn->fd);
  free(conn);

  return 0;
}