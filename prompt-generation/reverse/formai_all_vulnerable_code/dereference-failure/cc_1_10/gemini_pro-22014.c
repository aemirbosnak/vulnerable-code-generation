//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum size of the request and response buffers
#define MAX_BUFFER_SIZE 4096

// Define the port number for the proxy server
#define PROXY_PORT 8080

// Define the maximum number of connections that the proxy server can handle
#define MAX_CONNECTIONS 10

// Define the structure of a proxy connection
typedef struct {
  int client_fd;
  int server_fd;
  char request[MAX_BUFFER_SIZE];
  char response[MAX_BUFFER_SIZE];
} proxy_connection;

// Define the function to handle a client connection
void handle_client_connection(proxy_connection *connection) {
  // Read the request from the client
  int bytes_read = read(connection->client_fd, connection->request, MAX_BUFFER_SIZE);
  if (bytes_read < 0) {
    perror("read");
    close(connection->client_fd);
    return;
  }

  // Parse the request to get the hostname and port number of the server
  char *hostname = strtok(connection->request, " ");
  char *port = strtok(NULL, " ");

  // Create a socket to connect to the server
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("socket");
    close(connection->client_fd);
    return;
  }

  // Resolve the hostname to an IP address
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname");
    close(server_fd);
    close(connection->client_fd);
    return;
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(port));
  server_addr.sin_addr = *(struct in_addr *)host->h_addr;

  if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    close(server_fd);
    close(connection->client_fd);
    return;
  }

  // Send the request to the server
  if (write(server_fd, connection->request, bytes_read) < 0) {
    perror("write");
    close(server_fd);
    close(connection->client_fd);
    return;
  }

  // Read the response from the server
  bytes_read = read(server_fd, connection->response, MAX_BUFFER_SIZE);
  if (bytes_read < 0) {
    perror("read");
    close(server_fd);
    close(connection->client_fd);
    return;
  }

  // Send the response to the client
  if (write(connection->client_fd, connection->response, bytes_read) < 0) {
    perror("write");
    close(server_fd);
    close(connection->client_fd);
    return;
  }

  // Close the connections
  close(server_fd);
  close(connection->client_fd);
}

// Define the main function
int main(int argc, char *argv[]) {
  // Create a socket to listen for client connections
  int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_fd < 0) {
    perror("socket");
    return 1;
  }

  // Set the socket to be reusable
  int reuse = 1;
  if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
    perror("setsockopt");
    close(listen_fd);
    return 1;
  }

  // Bind the socket to the proxy port
  struct sockaddr_in listen_addr;
  memset(&listen_addr, 0, sizeof(listen_addr));
  listen_addr.sin_family = AF_INET;
  listen_addr.sin_port = htons(PROXY_PORT);
  listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
    perror("bind");
    close(listen_fd);
    return 1;
  }

  // Start listening for client connections
  if (listen(listen_fd, MAX_CONNECTIONS) < 0) {
    perror("listen");
    close(listen_fd);
    return 1;
  }

  // Accept client connections and handle them in a loop
  while (1) {
    // Accept a client connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_fd < 0) {
      perror("accept");
      continue;
    }

    // Create a new proxy connection
    proxy_connection *connection = malloc(sizeof(proxy_connection));
    connection->client_fd = client_fd;
    connection->server_fd = -1;
    memset(connection->request, 0, MAX_BUFFER_SIZE);
    memset(connection->response, 0, MAX_BUFFER_SIZE);

    // Handle the client connection in a separate thread
    pthread_t thread;
    if (pthread_create(&thread, NULL, (void *)handle_client_connection, connection) != 0) {
      perror("pthread_create");
      close(client_fd);
      free(connection);
      continue;
    }

    // Detach the thread so that it can run independently of the main thread
    if (pthread_detach(thread) != 0) {
      perror("pthread_detach");
      close(client_fd);
      free(connection);
      continue;
    }
  }

  // Close the listen socket
  close(listen_fd);

  return 0;
}