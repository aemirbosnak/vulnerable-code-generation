//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: decentralized
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define WEB_PORT 8080
#define WEB_ROOT "../"
#define BUFSZ 1024

char *get_content_type(char *path) {
  if (strstr(path, ".html"))
    return "text/html";
  else if (strstr(path, ".css"))
    return "text/css";
  else if (strstr(path, ".js"))
    return "text/javascript";
  else if (strstr(path, ".png"))
    return "image/png";
  else if (strstr(path, ".jpg"))
    return "image/jpeg";
  else if (strstr(path, ".svg"))
    return "image/svg+xml";
  return "text/plain";
}

void send_response(int client_fd, int status_code, char *content_type, char *content) {
  char buffer[BUFSZ];
  sprintf(buffer, "HTTP/1.1 %d %s\r\n", status_code,
          status_code == 200 ? "OK" : "Not Found");
  send(client_fd, buffer, strlen(buffer), 0);
  sprintf(buffer, "Content-Type: %s\r\n", content_type);
  send(client_fd, buffer, strlen(buffer), 0);
  sprintf(buffer, "Content-Length: %zu\r\n", strlen(content));
  send(client_fd, buffer, strlen(buffer), 0);
  send(client_fd, "\r\n", 2, 0);
  send(client_fd, content, strlen(content), 0);
}

void handle_client(int client_fd) {
  char request[BUFSZ];
  if (recv(client_fd, request, BUFSZ, 0) < 0) {
    perror("recv");
    close(client_fd);
    return;
  }
  char *path = strtok(request, " ");
  if (!path) {
    close(client_fd);
    return;
  }
  char *content_type = get_content_type(path);
  char *content;
  struct stat filestat;
  int fd = open(path, O_RDONLY);
  if (fd == -1) {
    send_response(client_fd, 404, content_type, "Not Found");
  } else {
    fstat(fd, &filestat);
    content = malloc(filestat.st_size + 1);
    read(fd, content, filestat.st_size);
    content[filestat.st_size] = '\0';
    send_response(client_fd, 200, content_type, content);
    free(content);
    close(fd);
  }
  close(client_fd);
}

int main() {
  int server_fd, client_fd;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_addr_len;
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("socket");
    return -1;
  }
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(WEB_PORT);
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    return -1;
  }
  if (listen(server_fd, 5) < 0) {
    perror("listen");
    return -1;
  }
  while (true) {
    client_addr_len = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr,
                       &client_addr_len);
    if (client_fd < 0) {
      perror("accept");
      continue;
    }
    if (fork() == 0) {
      close(server_fd);
      handle_client(client_fd);
      exit(0);
    }
    close(client_fd);
  }
  close(server_fd);
  return 0;
}