//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: brave
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define PORT 8083
#define BUFSIZE 1024

char buf[BUFSIZE];
int parent_sock;

void handle_connection(int client_sock) {
  printf("Handling connection on socket %d.\n", client_sock);

  while (1) {
    // Receive data from the client.
    int bytes_received = recv(client_sock, buf, BUFSIZE, 0);
    if (bytes_received == 0) {
      // Client has closed the connection.
      break;
    } else if (bytes_received < 0) {
      // Error receiving data.
      perror("recv");
      break;
    }

    // Parse the HTTP request.
    char *method = strtok(buf, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the request is valid.
    if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
      // Invalid request.
      char *error_response = "HTTP/1.1 400 Bad Request\r\n\r\n";
      send(client_sock, error_response, strlen(error_response), 0);
      break;
    }

    // Connect to the remote server.
    int remote_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (remote_sock < 0) {
      // Error creating socket.
      perror("socket");
      break;
    }

    struct hostent *remote_host = gethostbyname(path);
    if (remote_host == NULL) {
      // Error resolving hostname.
      perror("gethostbyname");
      break;
    }

    struct sockaddr_in remote_addr;
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(PORT);
    remote_addr.sin_addr = *(struct in_addr *)remote_host->h_addr;

    if (connect(remote_sock, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) < 0) {
      // Error connecting to remote server.
      perror("connect");
      break;
    }

    // Send the request to the remote server.
    send(remote_sock, buf, bytes_received, 0);

    // Receive the response from the remote server.
    int bytes_read;
    while ((bytes_read = recv(remote_sock, buf, BUFSIZE, 0)) > 0) {
      // Send the response to the client.
      send(client_sock, buf, bytes_read, 0);
    }

    // Close the remote socket.
    close(remote_sock);
  }

  // Close the client socket.
  close(client_sock);
}

int main() {
  // Create a parent socket.
  parent_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (parent_sock < 0) {
    // Error creating socket.
    perror("socket");
    return 1;
  }

  // Set the socket to be reusable.
  int reuseaddr = 1;
  if (setsockopt(parent_sock, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr)) < 0) {
    // Error setting socket option.
    perror("setsockopt");
    return 1;
  }

  // Bind the socket to the port.
  struct sockaddr_in parent_addr;
  memset(&parent_addr, 0, sizeof(parent_addr));
  parent_addr.sin_family = AF_INET;
  parent_addr.sin_port = htons(PORT);
  parent_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(parent_sock, (struct sockaddr *)&parent_addr, sizeof(parent_addr)) < 0) {
    // Error binding socket.
    perror("bind");
    return 1;
  }

  // Listen for connections.
  if (listen(parent_sock, 5) < 0) {
    // Error listening for connections.
    perror("listen");
    return 1;
  }

  // Accept connections.
  while (1) {
    int client_sock = accept(parent_sock, NULL, NULL);
    if (client_sock < 0) {
      // Error accepting connection.
      perror("accept");
      continue;
    }

    // Handle the connection in a child process.
    pid_t child_pid = fork();
    if (child_pid == 0) {
      // Child process.
      close(parent_sock);
      handle_connection(client_sock);
      exit(0);
    } else if (child_pid > 0) {
      // Parent process.
      close(client_sock);
    } else {
      // Error creating child process. 
      perror("fork");
      continue;
    }
  }

  // Close the parent socket.
  close(parent_sock);

  return 0;
}