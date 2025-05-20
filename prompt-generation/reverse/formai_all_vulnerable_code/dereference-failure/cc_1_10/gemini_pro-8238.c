//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// HTTP request methods
#define GET "GET"
#define POST "POST"
#define PUT "PUT"
#define DELETE "DELETE"

// HTTP response codes
#define OK 200
#define NOT_FOUND 404
#define INTERNAL_SERVER_ERROR 500

// Maximum buffer size
#define MAX_BUFFER_SIZE 4096

// Function to send an HTTP request
int send_http_request(char *host, char *port, char *method, char *path, char *body) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  // Resolve the hostname
  struct hostent *hostent = gethostbyname(host);
  if (hostent == NULL) {
    perror("gethostbyname");
    return -1;
  }

  // Create a sockaddr_in structure
  struct sockaddr_in sockaddr_in;
  sockaddr_in.sin_family = AF_INET;
  sockaddr_in.sin_port = htons(atoi(port));
  sockaddr_in.sin_addr = *(struct in_addr *)hostent->h_addr_list[0];

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&sockaddr_in, sizeof(sockaddr_in)) == -1) {
    perror("connect");
    return -1;
  }

  // Send the HTTP request
  char request[MAX_BUFFER_SIZE];
  snprintf(request, MAX_BUFFER_SIZE, "%s %s HTTP/1.1\r\nHost: %s\r\nContent-Length: %zu\r\n\r\n%s", method, path, host, strlen(body), body);
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    return -1;
  }

  // Receive the HTTP response
  char response[MAX_BUFFER_SIZE];
  memset(response, 0, MAX_BUFFER_SIZE);
  if (recv(sockfd, response, MAX_BUFFER_SIZE, 0) == -1) {
    perror("recv");
    return -1;
  }

  // Close the socket
  close(sockfd);

  // Parse the HTTP response
  char *status_line = strtok(response, "\r\n");
  char *status_code = strtok(status_line, " ");
  char *status_message = strtok(NULL, "\r\n");

  // Print the HTTP response
  printf("%s\n", status_line);

  // Return the status code
  return atoi(status_code);
}

// Main function
int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <host> <port> <method> <path>\n", argv[0]);
    return -1;
  }

  // Send the HTTP request
  int status_code = send_http_request(argv[1], argv[2], argv[3], argv[4], "");

  // Print the status code
  printf("Status code: %d\n", status_code);

  // Return 0
  return 0;
}