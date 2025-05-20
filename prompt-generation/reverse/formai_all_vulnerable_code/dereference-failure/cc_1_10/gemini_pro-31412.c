//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 1024

// Define the proxy server's listening port
#define PROXY_PORT 8080

// Define the maximum number of connections the proxy server can handle simultaneously
#define MAX_CONNECTIONS 5

// Create a socket for the proxy server to listen on
int create_proxy_socket() {
  int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (proxy_socket == -1) {
    perror("socket");
    exit(1);
  }
  return proxy_socket;
}

// Bind the proxy server socket to the specified port
void bind_proxy_socket(int proxy_socket, int port) {
  struct sockaddr_in proxy_addr;
  memset(&proxy_addr, 0, sizeof(proxy_addr));
  proxy_addr.sin_family = AF_INET;
  proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  proxy_addr.sin_port = htons(port);
  if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
    perror("bind");
    exit(1);
  }
}

// Listen for incoming connections on the proxy server socket
void listen_on_proxy_socket(int proxy_socket) {
  if (listen(proxy_socket, MAX_CONNECTIONS) == -1) {
    perror("listen");
    exit(1);
  }
}

// Accept an incoming connection on the proxy server socket
int accept_connection(int proxy_socket) {
  struct sockaddr_in client_addr;
  socklen_t client_addr_len;
  int client_socket = accept(proxy_socket, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_socket == -1) {
    perror("accept");
    exit(1);
  }
  return client_socket;
}

// Handle a client request
void handle_client_request(int client_socket) {
  char request[MAX_REQUEST_SIZE];
  memset(request, 0, MAX_REQUEST_SIZE);
  if (recv(client_socket, request, MAX_REQUEST_SIZE, 0) == -1) {
    perror("recv");
    exit(1);
  }

  // Parse the client request
  char *method = strtok(request, " ");
  char *path = strtok(NULL, " ");
  char *version = strtok(NULL, "\r\n");

  // Check if the client request is valid
  if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
    send(client_socket, "HTTP/1.1 400 Bad Request\r\n\r\n", strlen("HTTP/1.1 400 Bad Request\r\n\r\n"), 0);
    close(client_socket);
    return;
  }

  // Get the host and port of the destination server
  char *host = strtok(path, "/");
  char *port = strtok(NULL, "/");
  if (port == NULL) {
    port = "80";
  }

  // Create a socket for the connection to the destination server
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    exit(1);
  }

  // Resolve the destination server's IP address
  struct hostent *server_host = gethostbyname(host);
  if (server_host == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  // Connect to the destination server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = ((struct in_addr *)server_host->h_addr)->s_addr;
  server_addr.sin_port = htons(atoi(port));
  if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(1);
  }

  // Forward the client request to the destination server
  if (send(server_socket, request, strlen(request), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Receive the response from the destination server
  char response[MAX_RESPONSE_SIZE];
  memset(response, 0, MAX_RESPONSE_SIZE);
  if (recv(server_socket, response, MAX_RESPONSE_SIZE, 0) == -1) {
    perror("recv");
    exit(1);
  }

  // Forward the response to the client
  if (send(client_socket, response, strlen(response), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Close the client and server sockets
  close(client_socket);
  close(server_socket);
}

// Main function
int main() {
  // Create a socket for the proxy server to listen on
  int proxy_socket = create_proxy_socket();

  // Bind the proxy server socket to the specified port
  bind_proxy_socket(proxy_socket, PROXY_PORT);

  // Listen for incoming connections on the proxy server socket
  listen_on_proxy_socket(proxy_socket);

  while (1) {
    // Accept an incoming connection on the proxy server socket
    int client_socket = accept_connection(proxy_socket);

    // Handle the client request
    handle_client_request(client_socket);
  }

  // Close the proxy server socket
  close(proxy_socket);

  return 0;
}