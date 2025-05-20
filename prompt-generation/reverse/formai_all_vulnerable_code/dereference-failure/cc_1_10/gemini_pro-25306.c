//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define HTTP_OK         "HTTP/1.1 200 OK\r\n"
#define HTTP_NOT_FOUND  "HTTP/1.1 404 Not Found\r\n"
#define HTTP_SERVER     "CxY SVR\r\n"
#define HTTP_TYPE       "Content-Type: text/html\r\n"
#define HTTP_LEN        "Content-Length: "
#define HTTP_CONN       "Connection: close\r\n"

int main(int argc, char *argv[]) {
  struct sockaddr_in addr;
  int sockfd, connfd, len;
  char buf[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) perror("socket");

  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[1]));
  addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) perror("bind");
  if (listen(sockfd, 10) < 0) perror("listen");

  while (1) {
    len = sizeof(addr);
    connfd = accept(sockfd, (struct sockaddr *)&addr, &len);
    if (connfd < 0) perror("accept");

    read(connfd, buf, sizeof(buf));

    if (strstr(buf, "GET /")) {
      snprintf(buf, sizeof(buf), "%s%s%s%s%s%d\r\n\r\n<h1>Hello, World!</h1>", HTTP_OK, HTTP_SERVER, HTTP_TYPE, HTTP_LEN, 22, 22);
    } else {
      snprintf(buf, sizeof(buf), "%s%s%s%s\r\n\r\n<h1>404 Not Found</h1>", HTTP_NOT_FOUND, HTTP_SERVER, HTTP_TYPE, HTTP_LEN);
    }

    write(connfd, buf, strlen(buf));

    close(connfd);
  }

  close(sockfd);

  return 0;
}