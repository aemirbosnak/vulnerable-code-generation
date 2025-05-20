//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HTTP_RESPONSE_SIZE 4096
#define MAX_HOSTNAME_SIZE 256

int http_client(char* hostname, char* path, int port) {
  struct hostent* host = gethostbyname(hostname);
  if (host == NULL) {
    fprintf(stderr, "Error: Unknown host '%s'\n", hostname);
    return 1;
  }

  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd < 0) {
    perror("Error creating socket");
    return 1;
  }

  struct sockaddr_in server_address;
  memset(&server_address, '0', sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);
  memcpy(&server_address.sin_addr, host->h_addr_list[0], host->h_length);

  if (connect(sock_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
    perror("Error connecting to server");
    return 1;
  }

  char request[1024];
  sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

  if (write(sock_fd, request, strlen(request)) < 0) {
    perror("Error writing to socket");
    return 1;
  }

  char response[MAX_HTTP_RESPONSE_SIZE];
  int response_len = read(sock_fd, response, sizeof(response) - 1);
  if (response_len < 0) {
    perror("Error reading from socket");
    return 1;
  }

  response[response_len] = '\0';
  printf("Response:\n%s", response);

  close(sock_fd);

  return 0;
}

int main() {
  char hostname[MAX_HOSTNAME_SIZE];
  char path[MAX_HTTP_RESPONSE_SIZE];
  int port;
  printf("Welcome to the HTTP Client in the Medieval Style\n");
  printf("Enter the hostname: ");
  fgets(hostname, MAX_HOSTNAME_SIZE, stdin);
  hostname[strcspn(hostname, "\n")] = 0;

  printf("Enter the path: ");
  fgets(path, MAX_HTTP_RESPONSE_SIZE, stdin);
  path[strcspn(path, "\n")] = 0;

  printf("Enter the port: ");
  scanf("%d", &port);

  printf("Performing HTTP GET request...\n");
  http_client(hostname, path, port);

  return 0;
}