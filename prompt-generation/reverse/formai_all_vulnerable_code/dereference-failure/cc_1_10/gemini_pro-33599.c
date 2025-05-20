//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

typedef struct {
  int sockfd;
  struct sockaddr_in addr;
} connection;

typedef struct {
  connection client;
  connection server;
} proxy;

// Create a new connection.
connection new_connection(int sockfd, struct sockaddr_in addr) {
  connection conn;
  conn.sockfd = sockfd;
  conn.addr = addr;
  return conn;
}

// Close a connection.
void close_connection(connection conn) {
  close(conn.sockfd);
}

// Send data to a connection.
int send_data(connection conn, const char *buf, int len) {
  return send(conn.sockfd, buf, len, 0);
}

// Receive data from a connection.
int receive_data(connection conn, char *buf, int len) {
  return recv(conn.sockfd, buf, len, 0);
}

// Create a new proxy.
proxy new_proxy(connection client, connection server) {
  proxy proxy;
  proxy.client = client;
  proxy.server = server;
  return proxy;
}

// Close a proxy.
void close_proxy(proxy proxy) {
  close_connection(proxy.client);
  close_connection(proxy.server);
}

// Handle a client request.
void handle_client(proxy proxy) {
  char buf[BUFSIZE];
  int len;

  // Receive the request from the client.
  len = receive_data(proxy.client, buf, BUFSIZE);

  // Send the request to the server.
  send_data(proxy.server, buf, len);

  // Receive the response from the server.
  len = receive_data(proxy.server, buf, BUFSIZE);

  // Send the response to the client.
  send_data(proxy.client, buf, len);
}

// Start the proxy.
void start_proxy(int port) {
  int sockfd;
  struct sockaddr_in addr;

  // Create a socket.
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // Bind the socket to the specified port.
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;
  bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));

  // Listen for incoming connections.
  listen(sockfd, 5);

  // Accept incoming connections.
  while (1) {
    connection client;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Accept a new connection.
    client.sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);

    // Create a new proxy.
    proxy proxy = new_proxy(client, new_connection(sockfd, addr));

    // Handle the client request.
    handle_client(proxy);

    // Close the proxy.
    close_proxy(proxy);
  }

  // Close the socket.
  close(sockfd);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Start the proxy.
  start_proxy(atoi(argv[1]));

  return EXIT_SUCCESS;
}