//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Custom headers, for fun!
#define HTTP_CAT_MIME_TYPE "text/heisencat"

// Maximum length of a request buffer
#define REQUEST_BUFFER_SIZE 1024

// Maximum length of a response buffer
#define RESPONSE_BUFFER_SIZE 4096

// Port number to listen on
#define PORT 8080

// Initialize a socket, bind it to a port, and start listening for connections
int start_listening() {
  // Create a socket
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("socket");
    exit(1);
  }

  // Set up the socket address structure
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // Bind the socket to the address
  if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    exit(1);
  }

  // Start listening for connections
  if (listen(socket_fd, 5) == -1) {
    perror("listen");
    exit(1);
  }

  printf("Listening on port %d...\n", PORT);

  return socket_fd;
}

// Handle an incoming connection
void handle_connection(int socket_fd) {
  // Read the request from the client
  char request_buffer[REQUEST_BUFFER_SIZE];
  int bytes_read = recv(socket_fd, request_buffer, REQUEST_BUFFER_SIZE - 1, 0);
  if (bytes_read == -1) {
    perror("recv");
    close(socket_fd);
    return;
  }

  // Null-terminate the request
  request_buffer[bytes_read] = '\0';

  // Parse the request
  char *method = strtok(request_buffer, " ");
  char *path = strtok(NULL, " ");
  char *protocol = strtok(NULL, "\r\n");

  // Handle the request
  char response_buffer[RESPONSE_BUFFER_SIZE];
  if (strcmp(method, "GET") == 0) {
    if (strcmp(path, "/") == 0) {
      // Serve the home page
      sprintf(response_buffer,
              "HTTP/1.1 200 OK\r\n"
              "Content-Type: text/html\r\n"
              "\r\n"
              "<h1>Welcome to my amazing web server!</h1>");
    } else if (strcmp(path, "/cat") == 0) {
      // Serve a cute cat picture
      sprintf(response_buffer,
              "HTTP/1.1 200 OK\r\n"
              "Content-Type: %s\r\n"
              "\r\n"
              "  |\      _,,,---,,_ \n"
              "   /,`.-'`'    -.  ;-;;,_ \n"
              "  |,4-  ) )-,_..;\ (  `'-' \n"
              " '---''(_/--'  `-'\_)  \n",
              HTTP_CAT_MIME_TYPE);
    } else {
      // Serve a 404 error page
      sprintf(response_buffer,
              "HTTP/1.1 404 Not Found\r\n"
              "Content-Type: text/html\r\n"
              "\r\n"
              "<h1>404 Not Found</h1>");
    }
  } else {
    // Serve a 405 error page
    sprintf(response_buffer,
            "HTTP/1.1 405 Method Not Allowed\r\n"
            "Content-Type: text/html\r\n"
            "\r\n"
            "<h1>405 Method Not Allowed</h1>");
  }

  // Send the response to the client
  send(socket_fd, response_buffer, strlen(response_buffer), 0);

  // Close the connection
  close(socket_fd);
}

// Main function
int main() {
  // Start listening for connections
  int socket_fd = start_listening();

  // Main loop: handle incoming connections
  while (1) {
    // Accept a connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_socket_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_socket_fd == -1) {
      perror("accept");
      continue;
    }

    // Handle the connection
    handle_connection(client_socket_fd);
  }

  return 0;
}