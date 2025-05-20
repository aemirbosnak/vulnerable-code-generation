//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: scalable
#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<errno.h>

#define BUFFER_SIZE 1024

char* build_http_request(char* host, char* path) {
  char* request_template = "GET /%s HTTP/1.0\r\nHost: %s\r\nUser-Agent: HTTPClient/1.0\r\n\r\n";
  char* request = malloc(strlen(request_template) + strlen(host) + strlen(path));
  sprintf(request, request_template, path, host);
  return request;
}

int main(int argc, char** argv) {
  if (argc != 3) {
    printf("Usage: ./http_client <host> <path>\n");
    return 1;
  }

  char* host = argv[1];
  char* path = argv[2];

  struct hostent* server = gethostbyname(host);
  if (server == NULL) {
    printf("Error resolving hostname: %s\n", strerror(errno));
    return 1;
  }

  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(80);
  memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    printf("Error creating socket: %s\n", strerror(errno));
    return 1;
  }

  if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
    printf("Error connecting to server: %s\n", strerror(errno));
    return 1;
  }

  char* request = build_http_request(host, path);

  if (send(socket_fd, request, strlen(request), 0) < 0) {
    printf("Error sending request to server: %s\n", strerror(errno));
    return 1;
  }

  char buffer[BUFFER_SIZE];
  int total_bytes_received = 0;
  int bytes_received = 0;

  while ((bytes_received = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
    buffer[bytes_received] = '\0';
    total_bytes_received += bytes_received;
    printf("%s", buffer);
  }

  printf("\nTotal bytes received: %d\n", total_bytes_received);

  close(socket_fd);
  free(request);
  return 0;
}