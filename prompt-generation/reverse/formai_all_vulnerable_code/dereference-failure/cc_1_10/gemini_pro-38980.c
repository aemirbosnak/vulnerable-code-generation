//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Constants
#define HTTP_PORT 80
#define MAX_HTTP_HEADER_SIZE 4096

// Function prototypes
int create_proxy_socket(const char *ip, unsigned int port);
int proxy_request(int proxy_socket, const char *host, const char *path);
int proxy_response(int proxy_socket, int client_socket);

int main(int argc, char **argv) {
  // Check if the user has provided the correct number of arguments
  if (argc != 3) {
    printf("Usage: %s <proxy_ip> <proxy_port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Create the proxy socket
  int proxy_socket = create_proxy_socket(argv[1], atoi(argv[2]));
  if (proxy_socket == -1) {
    return EXIT_FAILURE;
  }

  // Wait for incoming client connections
  while (1) {
    // Accept the client connection
    int client_socket = accept(proxy_socket, NULL, NULL);
    if (client_socket == -1) {
      printf("Error: accept() failed.\n");
      continue;
    }

    // Read the client's request
    char request[MAX_HTTP_HEADER_SIZE];
    memset(request, 0, sizeof(request));
    int request_length = read(client_socket, request, sizeof(request) - 1);
    if (request_length == -1) {
      printf("Error: read() failed.\n");
      close(client_socket);
      continue;
    }

    // Parse the client's request
    char host[256];
    memset(host, 0, sizeof(host));
    char path[1024];
    memset(path, 0, sizeof(path));
    sscanf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n", path, host);

    // Send the client's request to the web server
    int request_status = proxy_request(proxy_socket, host, path);
    if (request_status == -1) {
      close(client_socket);
      continue;
    }

    // Read the web server's response
    char response[MAX_HTTP_HEADER_SIZE];
    memset(response, 0, sizeof(response));
    int response_length = read(proxy_socket, response, sizeof(response) - 1);
    if (response_length == -1) {
      printf("Error: read() failed.\n");
      close(client_socket);
      continue;
    }

    // Send the web server's response to the client
    proxy_response(proxy_socket, client_socket);

    // Close the client connection
    close(client_socket);
  }

  // Close the proxy socket
  close(proxy_socket);

  return EXIT_SUCCESS;
}

int create_proxy_socket(const char *ip, unsigned int port) {
  // Create a new socket
  int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (proxy_socket == -1) {
    printf("Error: socket() failed.\n");
    return -1;
  }

  // Set the socket options
  int optval = 1;
  setsockopt(proxy_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

  // Bind the socket to the specified IP address and port
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip);
  addr.sin_port = htons(port);
  if (bind(proxy_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    printf("Error: bind() failed.\n");
    close(proxy_socket);
    return -1;
  }

  // Listen for incoming connections
  if (listen(proxy_socket, 10) == -1) {
    printf("Error: listen() failed.\n");
    close(proxy_socket);
    return -1;
  }

  // Return the proxy socket
  return proxy_socket;
}

int proxy_request(int proxy_socket, const char *host, const char *path) {
  // Connect to the web server
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(host);
  addr.sin_port = htons(HTTP_PORT);
  if (connect(proxy_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    printf("Error: connect() failed.\n");
    return -1;
  }

  // Send the request to the web server
  char request[MAX_HTTP_HEADER_SIZE];
  memset(request, 0, sizeof(request));
  sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
  if (send(proxy_socket, request, strlen(request), 0) == -1) {
    printf("Error: send() failed.\n");
    return -1;
  }

  // Return the request status
  return 0;
}

int proxy_response(int proxy_socket, int client_socket) {
  // Read the response from the web server
  char response[MAX_HTTP_HEADER_SIZE];
  memset(response, 0, sizeof(response));
  int response_length = read(proxy_socket, response, sizeof(response) - 1);
  if (response_length == -1) {
    printf("Error: read() failed.\n");
    return -1;
  }

  // Send the response to the client
  if (send(client_socket, response, response_length, 0) == -1) {
    printf("Error: send() failed.\n");
    return -1;
  }

  // Return the response status
  return 0;
}