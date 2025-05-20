//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Get the host and port from the user
  char host[1024];
  int port;
  printf("Enter the host name: ");
  scanf("%s", host);
  printf("Enter the port number: ");
  scanf("%d", &port);

  // Create a sockaddr_in struct
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  struct hostent *server = gethostbyname(host);
  if (server == NULL) {
    perror("gethostbyname");
    return -1;
  }
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return -1;
  }

  // Send a request to the server
  char request[] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
  if (write(sockfd, request, strlen(request)) < 0) {
    perror("write");
    return -1;
  }

  // Receive a response from the server
  char response[4096];
  int n = read(sockfd, response, sizeof(response));
  if (n < 0) {
    perror("read");
    return -1;
  }

  // Print the response
  printf("%s", response);

  // Close the socket
  close(sockfd);

  return 0;
}