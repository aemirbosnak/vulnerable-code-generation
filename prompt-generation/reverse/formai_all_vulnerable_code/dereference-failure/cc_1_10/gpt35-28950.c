//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <fcntl.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 4096

void error(char* msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  if (argc < 2) error("Usage: ./proxy <port>");
  int server_port = atoi(argv[1]);
  int server_sockfd, client_sockfd;
  char buffer[BUFFER_SIZE];
  
  // Create a socket for the server
  if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    error("Error: Failed to create server socket");

  // Set socket options to avoid "Address already in use" error
  int yes = 1;
  if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    error("Error: Failed to set socket options");

  // Bind socket to server port
  struct sockaddr_in server_addr = {0};
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(server_port);
  if (bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    error("Error: Failed to bind server socket");

  // Start listening for incoming connections
  if (listen(server_sockfd, MAX_CLIENTS) == -1)
    error("Error: Failed to listen for connections");

  // Accept incoming client connections
  while(1) {
    struct sockaddr_in client_addr = {0};
    socklen_t client_len = sizeof(client_addr);
    client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &client_len);
    if (client_sockfd == -1) {
      printf("Error: Failed to accept client connection\n");
      continue;
    }
    printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Read request from client
    int nbytes = read(client_sockfd, buffer, BUFFER_SIZE);
    if (nbytes == -1)
      error("Error: Failed to read from client");
    buffer[nbytes] = '\0';

    // Parse host and port from request
    char *host;
    int port;
    char *req = strtok(buffer, "\r\n");
    char *method = strtok(req, " ");
    char *url = strtok(NULL, " ");
    char *version = strtok(NULL, "");
    if (!strncmp(url, "http://", 7)) {
      host = strtok(url+7, "/");
    }
    else {
      host = strtok(url, "/");
    }
    port = 80;
    char *p = strchr(host, ':');
    if (p) {
      *p = '\0';
      port = atoi(p+1);
    }

    // Connect to server
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent *he = gethostbyname(host);
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *(struct in_addr*)he->h_addr;
    server_addr.sin_port = htons(port);
    if (connect(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
      close(client_sockfd);
      continue;
    }

    // Forward request to server
    if (write(server_sockfd, buffer, nbytes) == -1) {
      close(client_sockfd);
      close(server_sockfd);
      continue;
    }

    // Forward response to client
    while((nbytes = read(server_sockfd, buffer, BUFFER_SIZE)) > 0) {
      if (write(client_sockfd, buffer, nbytes) == -1) {
        close(client_sockfd);
        close(server_sockfd);
        continue;
      }
    }
    if (nbytes == -1) {
      close(client_sockfd);
      close(server_sockfd);
      continue;
    }

    // Close connections
    close(client_sockfd);
    close(server_sockfd);
  }
  return 0;
}