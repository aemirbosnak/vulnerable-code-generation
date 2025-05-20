//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

// Defines the maximum number of client connections that the proxy can handle at once.
#define MAX_CONNECTIONS 10

// Defines the maximum size of the buffer that the proxy will use to receive data from clients.
#define BUFFER_SIZE 1024

// Sets up the server socket for the proxy.
int setup_server_socket(int port) {
  int server_socket;
  struct sockaddr_in server_address;

  // Creates a new socket.
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    exit(1);
  }

  // Sets up the server address.
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port);

  // Binds the socket to the server address.
  if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
    perror("bind");
    exit(1);
  }

  // Listens for incoming connections on the server socket.
  if (listen(server_socket, MAX_CONNECTIONS) == -1) {
    perror("listen");
    exit(1);
  }

  return server_socket;
}

// Handles a client connection.
void handle_client_connection(int client_socket) {
  char buffer[BUFFER_SIZE];
  int bytes_received;

  // Reads the request from the client.
  bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
  if (bytes_received == -1) {
    perror("recv");
    close(client_socket);
    return;
  }

  // Parses the request.
  char *request_line = strtok(buffer, "\r\n");
  char *method = strtok(request_line, " ");
  char *url = strtok(NULL, " ");
  char *version = strtok(NULL, "\r\n");

  // Checks if the request is valid.
  if (method == NULL || url == NULL || version == NULL) {
    send(client_socket, "HTTP/1.1 400 Bad Request\r\n\r\n", 29, 0);
    close(client_socket);
    return;
  }

  // Connects to the destination server.
  struct hostent *host = gethostbyname(url);
  if (host == NULL) {
    send(client_socket, "HTTP/1.1 404 Not Found\r\n\r\n", 28, 0);
    close(client_socket);
    return;
  }

  struct sockaddr_in destination_address;
  destination_address.sin_family = AF_INET;
  destination_address.sin_addr.s_addr = ((struct in_addr *) host->h_addr)->s_addr;
  destination_address.sin_port = htons(80);

  int destination_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (destination_socket == -1) {
    perror("socket");
    close(client_socket);
    return;
  }

  if (connect(destination_socket, (struct sockaddr *) &destination_address, sizeof(destination_address)) == -1) {
    perror("connect");
    close(client_socket);
    close(destination_socket);
    return;
  }

  // Sends the request to the destination server.
  send(destination_socket, buffer, bytes_received, 0);

  // Receives the response from the destination server.
  bytes_received = recv(destination_socket, buffer, BUFFER_SIZE, 0);
  if (bytes_received == -1) {
    perror("recv");
    close(client_socket);
    close(destination_socket);
    return;
  }

  // Sends the response to the client.
  send(client_socket, buffer, bytes_received, 0);

  // Closes the client socket.
  close(client_socket);

  // Closes the destination socket.
  close(destination_socket);
}

int main(int argc, char *argv[]) {
  int server_socket;
  struct sockaddr_in client_address;
  socklen_t client_address_length;

  // Checks if the correct number of arguments have been provided.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  // Sets up the server socket.
  server_socket = setup_server_socket(atoi(argv[1]));

  // Accepts client connections.
  while (1) {
    int client_socket;

    // Accepts a client connection.
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Handles the client connection in a separate thread.
    pid_t pid = fork();
    if (pid == 0) {
      close(server_socket);
      handle_client_connection(client_socket);
      exit(0);
    } else {
      close(client_socket);
    }
  }

  // Closes the server socket.
  close(server_socket);

  return 0;
}