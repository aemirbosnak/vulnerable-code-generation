//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_REQUEST_SIZE 4096
#define MAX_RESPONSE_SIZE 8192
#define PORT 8080

typedef struct {
  char *host;
  int port;
} proxy_target_t;

static void send_request(int sock, proxy_target_t *target, char *request) {
  char buffer[MAX_REQUEST_SIZE];
  int request_len = strlen(request);

  snprintf(buffer, sizeof(buffer),
           "POST %s HTTP/1.1\r\n"
           "Host: %s:%d\r\n"
           "Content-Length: %d\r\n"
           "\r\n"
           "%s",
           target->host, target->host, target->port, request_len, request);

  send(sock, buffer, strlen(buffer), 0);
}

static void handle_client(int client_sock) {
  char request[MAX_REQUEST_SIZE];
  int request_len;
  char response[MAX_RESPONSE_SIZE];
  int response_len;
  int target_sock;
  struct hostent *target_host;
  struct sockaddr_in target_addr;
  proxy_target_t target;

  // Receive the request from the client
  request_len = recv(client_sock, request, sizeof(request) - 1, 0);
  if (request_len <= 0) {
    perror("recv");
    close(client_sock);
    return;
  }

  // Parse the request to get the target host and port
  target.host = strtok(request, ":");
  target.port = atoi(strtok(NULL, "\r\n"));

  // Resolve the target host
  target_host = gethostbyname(target.host);
  if (!target_host) {
    perror("gethostbyname");
    close(client_sock);
    return;
  }

  // Create a socket to connect to the target
  target_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (target_sock < 0) {
    perror("socket");
    close(client_sock);
    return;
  }

  // Connect to the target
  target_addr.sin_family = AF_INET;
  target_addr.sin_port = htons(target.port);
  memcpy(&target_addr.sin_addr, target_host->h_addr, target_host->h_length);
  if (connect(target_sock, (struct sockaddr *) &target_addr, sizeof(target_addr)) < 0) {
    perror("connect");
    close(target_sock);
    close(client_sock);
    return;
  }

  // Send the request to the target
  send_request(target_sock, &target, request);

  // Receive the response from the target
  response_len = recv(target_sock, response, sizeof(response) - 1, 0);
  if (response_len <= 0) {
    perror("recv");
    close(target_sock);
    close(client_sock);
    return;
  }

  // Send the response to the client
  send(client_sock, response, response_len, 0);

  // Close the sockets
  close(target_sock);
  close(client_sock);
}

int main(int argc, char **argv) {
  int listen_sock;
  struct sockaddr_in listen_addr;
  int client_sock;
  struct sockaddr_in client_addr;
  socklen_t client_addr_len;

  // Create a listening socket
  listen_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_sock < 0) {
    perror("socket");
    return 1;
  }

  // Set the listening socket options
  listen_addr.sin_family = AF_INET;
  listen_addr.sin_port = htons(PORT);
  listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(listen_sock, (struct sockaddr *) &listen_addr, sizeof(listen_addr)) < 0) {
    perror("bind");
    close(listen_sock);
    return 1;
  }

  if (listen(listen_sock, 5) < 0) {
    perror("listen");
    close(listen_sock);
    return 1;
  }

  while(1) {
    // Accept a client connection
    client_addr_len = sizeof(client_addr);
    client_sock = accept(listen_sock, (struct sockaddr *) &client_addr, &client_addr_len);
    if (client_sock < 0) {
      perror("accept");
      continue;
    }

    // Handle the client connection in a separate thread
    handle_client(client_sock);
  }

  // Close the listening socket
  close(listen_sock);

  return 0;
}