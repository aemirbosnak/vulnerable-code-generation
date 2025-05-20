//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define SERVER_PORT 80
#define USER_AGENT "ApocalypseHTTPClient/1.0"

char *build_request(char *url) {
  char *request = calloc(strlen(url) + 128, sizeof(char));
  sprintf(request, "GET %s HTTP/1.1\r\n"
          "Host: %s\r\n"
          "User-Agent: %s\r\n"
          "Connection: close\r\n\r\n",
          url, url, USER_AGENT);
  return request;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: %s <url>\n", argv[0]);
    return 1;
  }

  char *url = argv[1];

  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr(url);
  server_address.sin_port = htons(SERVER_PORT);

  int connect_result = connect(client_socket,
                               (struct sockaddr *)&server_address,
                               sizeof(server_address));
  if (connect_result == -1) {
    perror("connect");
    return 1;
  }

  char *request = build_request(url);
  printf("request:\n%s", request);

  ssize_t send_result = send(client_socket, request, strlen(request), 0);
  if (send_result == -1) {
    perror("send");
    return 1;
  }

  ssize_t recv_count = 0;
  char recv_buffer[1024];
  while ((recv_count = recv(client_socket, recv_buffer, sizeof(recv_buffer), 0)) > 0) {
    fwrite(recv_buffer, sizeof(char), recv_count, stdout);
  }

  free(request);
  close(client_socket);
  return 0;
}