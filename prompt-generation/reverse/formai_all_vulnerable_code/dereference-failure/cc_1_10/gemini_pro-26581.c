//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CONNECTIONS 5

struct http_request {
  char method[10];
  char path[100];
  char version[10];
  char headers[1000];
  char body[1000];
};

struct http_response {
  char version[10];
  int status_code;
  char status_message[100];
  char headers[1000];
  char body[1000];
};

void handle_connection(int socket) {
  // Read the HTTP request
  struct http_request request;
  int bytes_read = recv(socket, &request, sizeof(request), 0);
  if (bytes_read == -1) {
    perror("recv");
    close(socket);
    return;
  }

  // Parse the HTTP request
  char *method = strtok(request.method, " ");
  char *path = strtok(NULL, " ");
  char *version = strtok(NULL, "\r\n");

  // Check if the request is valid
  if (strcmp(method, "GET") != 0) {
    // Send a 405 Method Not Allowed response
    struct http_response response;
    strcpy(response.version, "HTTP/1.1");
    response.status_code = 405;
    strcpy(response.status_message, "Method Not Allowed");
    strcpy(response.headers, "Content-Type: text/plain\r\n");
    strcpy(response.body, "The requested method is not allowed.");
    int bytes_sent = send(socket, &response, sizeof(response), 0);
    if (bytes_sent == -1) {
      perror("send");
    }
    close(socket);
    return;
  }

  // Send a 200 OK response with the requested file
  struct http_response response;
  strcpy(response.version, "HTTP/1.1");
  response.status_code = 200;
  strcpy(response.status_message, "OK");
  strcpy(response.headers, "Content-Type: text/plain\r\n");
  char *file_content = "Hello, world!";
  strcpy(response.body, file_content);
  int bytes_sent = send(socket, &response, sizeof(response), 0);
  if (bytes_sent == -1) {
    perror("send");
  }
  close(socket);
}

int main() {
  // Create a socket
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Bind the socket to the port
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    close(socket_fd);
    return EXIT_FAILURE;
  }

  // Listen for connections
  if (listen(socket_fd, MAX_CONNECTIONS) == -1) {
    perror("listen");
    close(socket_fd);
    return EXIT_FAILURE;
  }

  // Accept connections and handle them in a loop
  while (1) {
    // Accept a connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_socket_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_socket_fd == -1) {
      perror("accept");
      continue;
    }

    // Handle the connection in a separate thread
    pid_t pid = fork();
    if (pid == -1) {
      perror("fork");
      close(client_socket_fd);
      continue;
    } else if (pid == 0) {
      // Child process
      close(socket_fd);
      handle_connection(client_socket_fd);
      exit(0);
    } else {
      // Parent process
      close(client_socket_fd);
    }
  }

  // Close the socket
  close(socket_fd);
  return EXIT_SUCCESS;
}