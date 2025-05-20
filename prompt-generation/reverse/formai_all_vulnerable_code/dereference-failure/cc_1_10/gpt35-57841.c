//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_RESPONSE_SIZE 2048

struct Response {
  char message[MAX_RESPONSE_SIZE];
  int length;
};

struct Response build_request(const char* host, const char* path) {
  struct Response response;
  response.length = 0;

  char request[MAX_RESPONSE_SIZE];
  snprintf(request, MAX_RESPONSE_SIZE, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Unable to create socket");
    return response;
  }

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(host);
  server.sin_port = htons(80);

  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("Unable to connect");
    return response;
  }

  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("Unable to send request");
    return response;
  }

  char* message = (char*) malloc(MAX_RESPONSE_SIZE);
  int total = 0;
  int length;

  while ((length = recv(sockfd, message+total, MAX_RESPONSE_SIZE-total, 0)) > 0) {
    total += length;
    if (total >= MAX_RESPONSE_SIZE) {
      perror("Response too large");
      return response;
    }
  }

  if (length < 0) {
    perror("Unable to receive response");
    return response;
  }

  response.length = total;
  strncpy(response.message, message, total);

  return response;
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    printf("Usage: ./httpclient <host> <path>\n");
    return 1;
  }

  const char* host = argv[1];
  const char* path = argv[2];

  struct Response response = build_request(host, path);
  if (response.length == 0) {
    printf("Unable to complete request");
    return 1;
  }

  printf("%.*s\n", response.length, response.message);

  return 0;
}