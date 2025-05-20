//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// HTTP methods
#define GET "GET"
#define POST "POST"
#define PUT "PUT"
#define DELETE "DELETE"

// HTTP headers
#define HOST "Host"
#define CONTENT_TYPE "Content-Type"
#define CONTENT_LENGTH "Content-Length"

// HTTP status codes
#define OK 200
#define CREATED 201
#define ACCEPTED 202
#define NO_CONTENT 204
#define BAD_REQUEST 400
#define UNAUTHORIZED 401
#define FORBIDDEN 403
#define NOT_FOUND 404
#define METHOD_NOT_ALLOWED 405
#define INTERNAL_SERVER_ERROR 500

// Maximum buffer size
#define MAX_BUFFER_SIZE 1024

// HTTP client function
int http_client(char *host, char *port, char *path, char *method, char *body) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(port));
  server_addr.sin_addr.s_addr = inet_addr(host);
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return -1;
  }

  // Send the request
  char request[MAX_BUFFER_SIZE];
  sprintf(request, "%s %s HTTP/1.1\r\n", method, path);
  sprintf(request, "%s%s: %s\r\n", request, HOST, host);
  if (strcmp(method, POST) == 0 || strcmp(method, PUT) == 0) {
    sprintf(request, "%s%s: %s\r\n", request, CONTENT_TYPE, "application/json");
    sprintf(request, "%s%s: %d\r\n", request, CONTENT_LENGTH, strlen(body));
  }
  sprintf(request, "%s\r\n", request);
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    return -1;
  }

  // Send the body
  if (strcmp(method, POST) == 0 || strcmp(method, PUT) == 0) {
    if (send(sockfd, body, strlen(body), 0) == -1) {
      perror("send");
      return -1;
    }
  }

  // Receive the response
  char response[MAX_BUFFER_SIZE];
  int bytes_received = recv(sockfd, response, MAX_BUFFER_SIZE, 0);
  if (bytes_received == -1) {
    perror("recv");
    return -1;
  }

  // Parse the response
  char *status_line = strtok(response, "\r\n");
  char *status_code = strtok(status_line, " ");
  char *status_message = strtok(NULL, "\r\n");

  // Print the response
  printf("HTTP/1.1 %s %s\r\n", status_code, status_message);
  char *header;
  while ((header = strtok(NULL, "\r\n")) != NULL) {
    printf("%s\r\n", header);
  }
  printf("\r\n");
  printf("%s", strtok(NULL, "\0"));

  // Close the socket
  close(sockfd);

  return 0;
}

// Main function
int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 6) {
    printf("Usage: %s <host> <port> <path> <method> <body>\n", argv[0]);
    return -1;
  }

  // Call the HTTP client function
  return http_client(argv[1], argv[2], argv[3], argv[4], argv[5]);
}