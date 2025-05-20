//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: realistic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int sock, buffer_size, content_length = -1;
  char *hostname = argv[1];
  char *path = argv[2];
  char request[BUFFER_SIZE] = {0};
  char response[BUFFER_SIZE] = {0};

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);

  if (inet_pton(AF_INET, hostname, &server_address.sin_addr) <= 0) {
    printf("Invalid address/ Address not supported\n");
    return -1;
  }

  // create socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("Socket creation error\n");
    return -1;
  }

  // connect to server
  if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    printf("Connection failed\n");
    return -1;
  }

  // create HTTP request
  sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

  // send request
  if (send(sock, request, strlen(request), 0) < 0) {
    printf("Send request failed\n");
    return -1;
  }

  // receive response
  buffer_size = read(sock, response, BUFFER_SIZE);

  // check for content length
  char *p1 = strstr(response, "Content-Length:");
  if (p1 != NULL) {
    content_length = atoi(p1 + 16);
  }

  // print response
  printf("%s", response);

  // keep receiving until full response is received
  while (buffer_size < content_length) {
    buffer_size += read(sock, response + buffer_size, BUFFER_SIZE - buffer_size);
  }

  // print full response
  printf("%s", response);

  // close socket
  close(sock);

  return 0;
}