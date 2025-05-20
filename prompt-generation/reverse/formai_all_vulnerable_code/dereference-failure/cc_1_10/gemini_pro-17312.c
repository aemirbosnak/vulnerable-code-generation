//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

// Define the maximum size of the request and response buffers.
#define MAX_BUFFER_SIZE 4096

// Define the port number that the proxy will listen on.
#define PROXY_PORT 8080

// Define the IP address of the remote server that the proxy will forward requests to.
#define REMOTE_SERVER_IP "127.0.0.1"

// Define the port number of the remote server that the proxy will forward requests to.
#define REMOTE_SERVER_PORT 80

// Function to handle client requests.
void handle_client_request(int client_socket) {
  // Read the request from the client.
  char request[MAX_BUFFER_SIZE];
  int request_length = recv(client_socket, request, MAX_BUFFER_SIZE, 0);
  if (request_length < 0) {
    perror("recv");
    close(client_socket);
    return;
  }

  // Parse the request.
  char *method = strtok(request, " ");
  char *path = strtok(NULL, " ");
  char *http_version = strtok(NULL, "\r\n");

  // Check if the request is valid.
  if (strcmp(method, "GET") != 0 && strcmp(method, "POST") != 0) {
    // Send a 400 Bad Request response.
    char response[] = "HTTP/1.1 400 Bad Request\r\n\r\n";
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
    return;
  }

  // Connect to the remote server.
  int remote_server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (remote_server_socket < 0) {
    perror("socket");
    close(client_socket);
    return;
  }

  struct sockaddr_in remote_server_address;
  remote_server_address.sin_family = AF_INET;
  remote_server_address.sin_port = htons(REMOTE_SERVER_PORT);
  remote_server_address.sin_addr.s_addr = inet_addr(REMOTE_SERVER_IP);

  if (connect(remote_server_socket, (struct sockaddr *)&remote_server_address, sizeof(remote_server_address)) < 0) {
    perror("connect");
    close(client_socket);
    close(remote_server_socket);
    return;
  }

  // Forward the request to the remote server.
  send(remote_server_socket, request, request_length, 0);

  // Read the response from the remote server.
  char response[MAX_BUFFER_SIZE];
  int response_length = recv(remote_server_socket, response, MAX_BUFFER_SIZE, 0);
  if (response_length < 0) {
    perror("recv");
    close(client_socket);
    close(remote_server_socket);
    return;
  }

  // Forward the response to the client.
  send(client_socket, response, response_length, 0);

  // Close the client and remote server sockets.
  close(client_socket);
  close(remote_server_socket);
}

// Function to start the proxy server.
void start_proxy_server() {
  // Create a socket for the proxy server.
  int proxy_server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (proxy_server_socket < 0) {
    perror("socket");
    exit(1);
  }

  // Set the socket to be reusable.
  int reuseaddr = 1;
  if (setsockopt(proxy_server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr)) < 0) {
    perror("setsockopt");
    exit(1);
  }

  // Bind the socket to the proxy port.
  struct sockaddr_in proxy_server_address;
  proxy_server_address.sin_family = AF_INET;
  proxy_server_address.sin_port = htons(PROXY_PORT);
  proxy_server_address.sin_addr.s_addr = INADDR_ANY;

  if (bind(proxy_server_socket, (struct sockaddr *)&proxy_server_address, sizeof(proxy_server_address)) < 0) {
    perror("bind");
    exit(1);
  }

  // Listen for incoming client connections.
  if (listen(proxy_server_socket, 5) < 0) {
    perror("listen");
    exit(1);
  }

  // Accept incoming client connections and handle them in a separate thread.
  while (1) {
    int client_socket = accept(proxy_server_socket, NULL, NULL);
    if (client_socket < 0) {
      perror("accept");
      continue;
    }

    pthread_t thread;
    pthread_create(&thread, NULL, (void *)handle_client_request, (void *)client_socket);
  }

  // Close the proxy server socket.
  close(proxy_server_socket);
}

int main() {
  // Start the proxy server.
  start_proxy_server();

  return 0;
}