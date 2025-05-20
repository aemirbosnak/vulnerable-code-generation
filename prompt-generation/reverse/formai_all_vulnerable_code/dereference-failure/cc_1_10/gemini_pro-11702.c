//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#define MAX_BUFF_SIZE 1024

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

void *handle_client(void *client_sock);

int main(int argc, char **argv) {
  int server_sock, client_sock, port_num;
  sockaddr_in server_addr, client_addr;
  pthread_t thread_id;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return 1;
  }

  port_num = atoi(argv[1]);

  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock == -1) {
    perror("socket");
    return 1;
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port_num);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(server_sock, (sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    return 1;
  }

  if (listen(server_sock, 5) == -1) {
    perror("listen");
    return 1;
  }

  while (1) {
    socklen_t client_addr_len = sizeof(client_addr);
    client_sock = accept(server_sock, (sockaddr *)&client_addr, &client_addr_len);
    if (client_sock == -1) {
      perror("accept");
      continue;
    }

    if (pthread_create(&thread_id, NULL, handle_client, (void *)client_sock) != 0) {
      perror("pthread_create");
      close(client_sock);
      continue;
    }

    pthread_detach(thread_id);
  }

  close(server_sock);
  return 0;
}

void *handle_client(void *client_sock) {
  int client_fd = (int)client_sock;
  char buff[MAX_BUFF_SIZE], req[MAX_BUFF_SIZE], resp[MAX_BUFF_SIZE];
  int bytes_recv, bytes_sent;
  int server_fd;
  char *host, *port, *path, *method;
  sockaddr_in server_addr;

  memset(buff, 0, MAX_BUFF_SIZE);
  bytes_recv = recv(client_fd, buff, MAX_BUFF_SIZE, 0);
  if (bytes_recv == -1) {
    perror("recv");
    close(client_fd);
    return NULL;
  }

  sscanf(buff, "%s %s %s", method, req, path);
  host = strstr(req, "Host:");
  if (host == NULL) {
    fprintf(stderr, "Invalid request: missing Host header\n");
    close(client_fd);
    return NULL;
  }

  host += 6;
  port = strchr(host, ':');
  if (port == NULL) {
    port = "80";
  } else {
    *port = '\0';
    port++;
  }

  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == -1) {
    perror("socket");
    close(client_fd);
    return NULL;
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(port));
  if (inet_pton(AF_INET, host, &server_addr.sin_addr) == -1) {
    perror("inet_pton");
    close(client_fd);
    close(server_fd);
    return NULL;
  }

  if (connect(server_fd, (sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    close(client_fd);
    close(server_fd);
    return NULL;
  }

  bytes_sent = send(server_fd, buff, bytes_recv, 0);
  if (bytes_sent == -1) {
    perror("send");
    close(client_fd);
    close(server_fd);
    return NULL;
  }

  while (1) {
    memset(resp, 0, MAX_BUFF_SIZE);
    bytes_recv = recv(server_fd, resp, MAX_BUFF_SIZE, 0);
    if (bytes_recv == -1) {
      perror("recv");
      close(client_fd);
      close(server_fd);
      return NULL;
    } else if (bytes_recv == 0) {
      break;
    }

    bytes_sent = send(client_fd, resp, bytes_recv, 0);
    if (bytes_sent == -1) {
      perror("send");
      close(client_fd);
      close(server_fd);
      return NULL;
    }
  }

  close(client_fd);
  close(server_fd);
  return NULL;
}