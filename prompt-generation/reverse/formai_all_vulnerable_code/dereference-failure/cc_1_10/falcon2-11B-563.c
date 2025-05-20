//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main() {
  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to server
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(110);
  server.sin_addr.s_addr = inet_addr("localhost");
  int conn_status = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
  if (conn_status == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send login command
  char buffer[256];
  sprintf(buffer, "USER %s\r\n", "username");
  int bytes_written = write(sockfd, buffer, strlen(buffer));
  if (bytes_written == -1) {
    perror("write");
    exit(EXIT_FAILURE);
  }

  // Send password command
  sprintf(buffer, "PASS %s\r\n", "password");
  bytes_written = write(sockfd, buffer, strlen(buffer));
  if (bytes_written == -1) {
    perror("write");
    exit(EXIT_FAILURE);
  }

  // Read response
  char response[256];
  memset(response, 0, sizeof(response));
  int bytes_read = read(sockfd, response, sizeof(response));
  if (bytes_read == -1) {
    perror("read");
    exit(EXIT_FAILURE);
  }
  printf("%s\n", response);

  // Close socket
  close(sockfd);
  return 0;
}