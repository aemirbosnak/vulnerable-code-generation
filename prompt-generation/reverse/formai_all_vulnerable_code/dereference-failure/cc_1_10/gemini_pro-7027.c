//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 100

typedef struct {
  int client_sockfd;
  int server_sockfd;
} connection_t;

void *handle_connection(void *arg) {
  connection_t *connection = (connection_t *)arg;

  // Read the request from the client
  char request[4096];
  int request_len = read(connection->client_sockfd, request, sizeof(request));
  if (request_len == -1) {
    perror("read");
    close(connection->client_sockfd);
    close(connection->server_sockfd);
    free(connection);
    pthread_exit(NULL);
  }

  // Parse the request
  char *host = NULL;
  char *path = NULL;
  int port = 80;
  if (sscanf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host) == 2) {
    char *port_str = strchr(host, ':');
    if (port_str != NULL) {
      port = atoi(port_str + 1);
      *port_str = '\0';
    }
  } else {
    // Handle malformed requests
    char error[] = "HTTP/1.1 400 Bad Request\r\n\r\n";
    write(connection->client_sockfd, error, sizeof(error));
    close(connection->client_sockfd);
    close(connection->server_sockfd);
    free(connection);
    pthread_exit(NULL);
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(host);
  int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sockfd == -1) {
    perror("socket");
    close(connection->client_sockfd);
    free(connection);
    pthread_exit(NULL);
  }
  if (connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    close(connection->client_sockfd);
    close(server_sockfd);
    free(connection);
    pthread_exit(NULL);
  }

  // Forward the request to the server
  write(server_sockfd, request, request_len);

  // Read the response from the server
  char response[4096];
  int response_len = read(server_sockfd, response, sizeof(response));
  if (response_len == -1) {
    perror("read");
    close(connection->client_sockfd);
    close(server_sockfd);
    free(connection);
    pthread_exit(NULL);
  }

  // Forward the response to the client
  write(connection->client_sockfd, response, response_len);

  // Close the connections
  close(connection->client_sockfd);
  close(server_sockfd);

  // Free the memory
  free(connection);

  // Exit the thread
  pthread_exit(NULL);
}

int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Bind the socket to the address
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    exit(1);
  }

  // Listen for connections
  if (listen(sockfd, MAX_CONNECTIONS) == -1) {
    perror("listen");
    exit(1);
  }

  // Accept connections
  while (1) {
    int client_sockfd = accept(sockfd, NULL, NULL);
    if (client_sockfd == -1) {
      perror("accept");
      continue;
    }

    // Create a new thread to handle the connection
    pthread_t thread;
    connection_t *connection = malloc(sizeof(connection_t));
    connection->client_sockfd = client_sockfd;
    pthread_create(&thread, NULL, handle_connection, connection);
  }

  // Close the socket
  close(sockfd);

  return 0;
}