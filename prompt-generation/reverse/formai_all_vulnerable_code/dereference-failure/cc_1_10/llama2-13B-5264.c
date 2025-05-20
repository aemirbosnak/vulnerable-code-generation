//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void server_recursive(int sock);
void handle_request(int sock, char *request_line);
void send_response(int sock, char *response);

int main(void) {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket failed");
    exit(1);
  }

  struct sockaddr_in server_addr = {
    .sin_family = AF_INET,
    .sin_port = htons(8080),
    .sin_addr.s_addr = INADDR_ANY
  };

  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    exit(1);
  }

  if (listen(sock, 3) < 0) {
    perror("listen failed");
    exit(1);
  }

  printf("Listening for incoming requests...\n");

  while (1) {
    int client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
      perror("accept failed");
      exit(1);
    }

    server_recursive(client_sock);

    close(client_sock);
  }

  return 0;
}

void server_recursive(int sock) {
  char buffer[BUFFER_SIZE];
  int bytes_read;

  printf("Received connection from client...\n");

  while (1) {
    bytes_read = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_read < 0) {
      perror("recv failed");
      exit(1);
    }

    if (bytes_read == 0) {
      printf("Client has closed connection...\n");
      break;
    }

    handle_request(sock, buffer);
  }

  send_response(sock, "Goodbye, world!");
}

void handle_request(int sock, char *request_line) {
  char *method, *path, *query_string;
  int len;

  method = strtok(request_line, " ");
  path = strtok(NULL, " ");
  query_string = strtok(NULL, "?");

  len = strlen(method) + strlen(path) + strlen(query_string) + 1;
  char *request = malloc(len);
  snprintf(request, len, "%s %s%s", method, path, query_string);

  printf("Received request: %s\n", request);

  free(request);
}

void send_response(int sock, char *response) {
  char *message = response;
  int bytes_written;

  while (*message != '\0') {
    bytes_written = send(sock, message, strlen(message), 0);
    if (bytes_written < 0) {
      perror("send failed");
      exit(1);
    }
    message += bytes_written;
  }
}