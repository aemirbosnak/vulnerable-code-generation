//GEMINI-pro DATASET v1.0 Category: Networking ; Style: complex
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Define some constants
#define MAX_BUF_SIZE 1024
#define LISTEN_PORT 8080

// Struct representing a client connection
typedef struct client_connection {
  int sockfd;
  struct sockaddr_in addr;
} client_connection;

// Function to initialize a client connection
client_connection* init_client_connection(int sockfd, struct sockaddr_in addr) {
  client_connection* conn = malloc(sizeof(client_connection));
  conn->sockfd = sockfd;
  conn->addr = addr;
  return conn;
}

// Function to handle client connections
void handle_client_connection(client_connection* conn) {
  // Receive data from the client
  char buf[MAX_BUF_SIZE];
  int recv_size = recv(conn->sockfd, buf, MAX_BUF_SIZE, 0);
  if (recv_size < 0) {
    perror("recv");
    return;
  }

  // Parse the received data
  char* request_line = strtok(buf, "\r\n");
  char* method = strtok(request_line, " ");
  char* path = strtok(NULL, " ");
  char* http_version = strtok(NULL, "\r\n");

  // Handle the request
  if (strcmp(method, "GET") == 0) {
    // Send the requested file
    char* file_name = path + 1;
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
      // File not found
      send(conn->sockfd, "HTTP/1.1 404 Not Found\r\n", 25, 0);
      send(conn->sockfd, "Content-Type: text/plain\r\n", 27, 0);
      send(conn->sockfd, "\r\n", 2, 0);
      send(conn->sockfd, "File not found", 14, 0);
    } else {
      // Read the file contents
      fseek(file, 0, SEEK_END);
      long file_size = ftell(file);
      rewind(file);

      // Send the HTTP response header
      char* response_header = malloc(1024);
      sprintf(response_header, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %ld\r\n\r\n", file_size);
      send(conn->sockfd, response_header, strlen(response_header), 0);

      // Send the file contents
      char* file_contents = malloc(file_size);
      fread(file_contents, file_size, 1, file);
      send(conn->sockfd, file_contents, file_size, 0);

      free(response_header);
      free(file_contents);
      fclose(file);
    }
  } else {
    // Unsupported method
    send(conn->sockfd, "HTTP/1.1 405 Method Not Allowed\r\n", 33, 0);
    send(conn->sockfd, "Content-Type: text/plain\r\n", 27, 0);
    send(conn->sockfd, "\r\n", 2, 0);
    send(conn->sockfd, "Method not allowed", 19, 0);
  }

  // Close the client connection
  close(conn->sockfd);
  free(conn);
}

// Main function
int main() {
  // Create a listening socket
  int listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the socket options
  int optval = 1;
  if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
    perror("setsockopt");
    return EXIT_FAILURE;
  }

  // Bind the socket to the listening port
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(LISTEN_PORT);
  if (bind(listenfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(listenfd, 10) < 0) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept incoming connections and handle them
  while (1) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int clientfd = accept(listenfd, (struct sockaddr*)&client_addr, &client_addr_len);
    if (clientfd < 0) {
      perror("accept");
      continue;
    }

    // Create a client connection object
    client_connection* conn = init_client_connection(clientfd, client_addr);

    // Spawn a new thread to handle the client connection
    pthread_t thread;
    pthread_create(&thread, NULL, (void*)&handle_client_connection, conn);
    pthread_detach(thread);
  }

  // Close the listening socket
  close(listenfd);

  return EXIT_SUCCESS;
}