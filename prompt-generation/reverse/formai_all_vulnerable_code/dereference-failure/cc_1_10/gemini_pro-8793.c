//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: mind-bending
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

void handle_error(const char *err) {
  fprintf(stderr, "%s: %s\n", err, strerror(errno));
  exit(1);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    exit(1);
  }

  // Parse the host and port arguments.
  const char *host = argv[1];
  const char *port = argv[2];
  int port_num = atoi(port);

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    handle_error("socket");
  }

  // Resolve the host and port.
  struct hostent *hostent = gethostbyname(host);
  if (hostent == NULL) {
    handle_error("gethostbyname");
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port_num);
  memcpy(&server_addr.sin_addr, hostent->h_addr, hostent->h_length);

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    handle_error("connect");
  }

  // Send a username and password to the server.
  char username[MAX_BUFFER_SIZE];
  char password[MAX_BUFFER_SIZE];
  printf("Enter username: ");
  scanf("%s", username);
  printf("Enter password: ");
  scanf("%s", password);

  char buffer[MAX_BUFFER_SIZE];
  sprintf(buffer, "USER %s\r\n", username);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    handle_error("send");
  }
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
    handle_error("recv");
  }
  printf("%s", buffer);

  sprintf(buffer, "PASS %s\r\n", password);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    handle_error("send");
  }
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
    handle_error("recv");
  }
  printf("%s", buffer);

  // Close the socket.
  close(sockfd);

  return 0;
}