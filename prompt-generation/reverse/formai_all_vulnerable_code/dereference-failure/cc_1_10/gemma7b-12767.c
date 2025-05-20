//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Request {
  char *method;
  char *path;
  char **headers;
  char *body;
} Request;

Request *parse_request(char *buffer) {
  Request *request = malloc(sizeof(Request));

  request->method = strchr(buffer, "GET") ? "GET" : strchr(buffer, "POST") ? "POST" : "";
  request->path = strchr(buffer, "/") + 1;

  request->headers = malloc(MAX_BUFFER_SIZE);
  request->headers[0] = NULL;

  char *header_start = strstr(buffer, "Header:");
  if (header_start) {
    char *header_end = strchr(header_start, "\r\n");
    int header_size = header_end - header_start - 1;
    request->headers[0] = malloc(header_size);
    memcpy(request->headers[0], header_start + 8, header_size);
  }

  request->body = strstr(buffer, "Body:") ? strchr(buffer, "\r\n") + 1 : NULL;

  return request;
}

int main() {
  char buffer[MAX_BUFFER_SIZE];

  // Read the request from the client
  printf("Enter the request: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  // Parse the request
  Request *request = parse_request(buffer);

  // Print the request information
  printf("Method: %s\n", request->method);
  printf("Path: %s\n", request->path);
  printf("Headers:\n");
  for (char **header = request->headers; *header; header++) {
    printf("%s\n", *header);
  }
  printf("Body: \n");
  if (request->body) {
    printf("%s\n", request->body);
  }

  // Free the memory allocated for the request
  free(request->headers);
  free(request);

  return 0;
}