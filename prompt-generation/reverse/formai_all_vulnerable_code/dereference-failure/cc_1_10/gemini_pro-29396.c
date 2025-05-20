//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

// Our very own HTTP client library
#define HTTP_BUF_SIZE 4096

typedef struct {
  char *host;
  int port;
  char *path;
} http_request_t;

typedef struct {
  int status_code;
  char *status_message;
  char *headers;
  char *body;
} http_response_t;

http_response_t* http_get(http_request_t *request) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return NULL;
  }

  // Resolve the hostname
  struct hostent *hostent = gethostbyname(request->host);
  if (hostent == NULL) {
    perror("gethostbyname");
    close(sockfd);
    return NULL;
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(request->port);
  server_addr.sin_addr = *(struct in_addr *)hostent->h_addr_list[0];

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    close(sockfd);
    return NULL;
  }

  // Send the HTTP request
  char request_str[HTTP_BUF_SIZE];
  snprintf(request_str, HTTP_BUF_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", request->path, request->host);

  if (send(sockfd, request_str, strlen(request_str), 0) == -1) {
    perror("send");
    close(sockfd);
    return NULL;
  }

  // Receive the HTTP response
  char response_str[HTTP_BUF_SIZE];
  int num_bytes_received = recv(sockfd, response_str, HTTP_BUF_SIZE, 0);
  if (num_bytes_received == -1) {
    perror("recv");
    close(sockfd);
    return NULL;
  }
  
  // Parse the HTTP response
  
  http_response_t *response = malloc(sizeof(http_response_t));
  if (response == NULL) {
    perror("malloc");
    close(sockfd);
    return NULL;
  }

  char *status_line = strtok(response_str, "\r\n");
  if (status_line == NULL) {
    perror("strtok");
    close(sockfd);
    free(response);
    return NULL;
  }

  sscanf(status_line, "HTTP/1.1 %d %s", &response->status_code, response->status_message);

  char *headers = strtok(NULL, "\r\n\r\n");
  if (headers == NULL) {
    perror("strtok");
    close(sockfd);
    free(response);
    return NULL;
  }

  response->headers = strdup(headers);
  if (response->headers == NULL) {
    perror("strdup");
    close(sockfd);
    free(response);
    return NULL;
  }

  response->body = strdup(strtok(NULL, ""));
  if (response->body == NULL) {
    perror("strdup");
    close(sockfd);
    free(response->headers);
    free(response);
    return NULL;
  }

  // Clean up
  close(sockfd);

  return response;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
    return 1;
  }

  http_request_t request;
  request.host = argv[1];
  request.port = 80;
  request.path = argv[2];

  http_response_t *response = http_get(&request);
  if (response == NULL) {
    fprintf(stderr, "Error fetching URL\n");
    return 1;
  }

  printf("HTTP/1.1 %d %s\n", response->status_code, response->status_message);
  printf("%s\n", response->headers);
  printf("\n");
  printf("%s", response->body);
  printf("\n");

  free(response->headers);
  free(response->body);
  free(response);

  return 0;
}