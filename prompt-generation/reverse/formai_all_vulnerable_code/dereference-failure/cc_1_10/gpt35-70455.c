//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BACKLOG 10
#define BUFSIZE 1024

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  int port = atoi(argv[1]);

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    exit(1);
  }

  if (listen(sockfd, BACKLOG) < 0) {
    perror("listen");
    exit(1);
  }

  while(1) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd < 0) {
      perror("accept");
      continue;
    }

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
    printf("Connected to %s:%d\n", client_ip, ntohs(client_addr.sin_port));

    char buf[BUFSIZE];
    int bytes_read = read(client_sockfd, buf, BUFSIZE - 1);
    if (bytes_read < 0) {
      perror("read");
      close(client_sockfd);
      continue;
    }

    buf[bytes_read] = '\0';
    printf("Data received: %s\n", buf);

    char response[] = "HTTP/1.1 200 OK\r\nContent-Length: 12\r\n\r\nHello world!";
    write(client_sockfd, response, strlen(response));
    printf("Response sent\n");

    close(client_sockfd);
  }

  close(sockfd);
  return 0;
}