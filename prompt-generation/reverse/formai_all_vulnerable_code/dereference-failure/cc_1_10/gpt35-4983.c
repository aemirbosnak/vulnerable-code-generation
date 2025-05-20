//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 65535

int main(int argc, char **argv) {
  // Check if all required arguments are passed
  if (argc != 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  // Get host IP
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    perror("Error: could not resolve host");
    exit(1);
  }

  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error: could not create socket");
    exit(1);
  }

  // Connect to server
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[2]));
  memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error: could not connect to server");
    exit(1);
  }

  // Build HTTP request
  char request[MAX_BUFFER_SIZE];
  sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n",
          argv[1]);

  // Send HTTP request
  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("Error: could not send HTTP request");
    exit(1);
  }

  // Read HTTP response
  char response[MAX_BUFFER_SIZE];
  int total_bytes_read = 0;
  int num_bytes_read = 0;
  while ((num_bytes_read = recv(sockfd, response + total_bytes_read, 
                                MAX_BUFFER_SIZE - total_bytes_read - 1, 0)) > 0) {
    total_bytes_read += num_bytes_read;
  }
  if (num_bytes_read < 0) {
    perror("Error: could not read HTTP response");
    exit(1);
  }

  // Add null terminator to response
  response[total_bytes_read] = '\0';

  // Print HTTP response
  printf("%s", response);

  // Close socket
  close(sockfd);

  return 0;
}