//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  char *host = argv[1];
  int port = atoi(argv[2]);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Resolve the host and port
  struct hostent *hostinfo = gethostbyname(host);
  if (hostinfo == NULL) {
    perror("gethostbyname");
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  memcpy(&server_addr.sin_addr, hostinfo->h_addr_list[0], hostinfo->h_length);
  server_addr.sin_port = htons(port);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return 1;
  }

  // Send a HTTP request
  char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the HTTP response
  char buffer[MAX_MSG_SIZE];
  int bytes_received = 0;
  while ((bytes_received = recv(sockfd, buffer, MAX_MSG_SIZE - 1, 0)) > 0) {
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
  }

  if (bytes_received == -1) {
    perror("recv");
    return 1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}