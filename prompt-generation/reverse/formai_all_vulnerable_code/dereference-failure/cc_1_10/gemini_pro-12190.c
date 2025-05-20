//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

void proxy(int client_socket, struct sockaddr_in *client_addr, socklen_t client_addr_len) {
  int server_socket;
  struct sockaddr_in server_addr;
  char buffer[4096];
  int bytes_recv, bytes_sent;

  // Receive the HTTP request from the client
  bytes_recv = recvfrom(client_socket, buffer, sizeof(buffer), 0, (struct sockaddr *)client_addr, &client_addr_len);
  if (bytes_recv < 0) {
    perror("recvfrom()");
    exit(1);
  }

  // Parse the HTTP request to get the hostname and port number of the server
  char *hostname = strtok(buffer, " ");
  char *port = strtok(NULL, " ");
  if (hostname == NULL || port == NULL) {
    printf("Invalid HTTP request\n");
    exit(1);
  }

  // Create a socket to connect to the server
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    perror("socket()");
    exit(1);
  }

  // Resolve the hostname to an IP address
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    printf("Invalid hostname\n");
    exit(1);
  }

  // Set the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = ((struct in_addr *)host->h_addr)->s_addr;
  server_addr.sin_port = htons(atoi(port));

  // Connect to the server
  if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect()");
    exit(1);
  }

  // Send the HTTP request to the server
  bytes_sent = send(server_socket, buffer, bytes_recv, 0);
  if (bytes_sent < 0) {
    perror("send()");
    exit(1);
  }

  // Receive the HTTP response from the server
  bytes_recv = recv(server_socket, buffer, sizeof(buffer), 0);
  if (bytes_recv < 0) {
    perror("recv()");
    exit(1);
  }

  // Send the HTTP response to the client
  bytes_sent = sendto(client_socket, buffer, bytes_recv, 0, (struct sockaddr *)client_addr, client_addr_len);
  if (bytes_sent < 0) {
    perror("sendto()");
    exit(1);
  }

  // Close the client and server sockets
  close(client_socket);
  close(server_socket);
}

int main(int argc, char *argv[]) {
  int client_socket;
  struct sockaddr_in client_addr;
  socklen_t client_addr_len;

  // Create a socket to listen for client connections
  client_socket = socket(AF_INET, SOCK_DGRAM, 0);
  if (client_socket < 0) {
    perror("socket()");
    exit(1);
  }

  // Set the client address
  memset(&client_addr, 0, sizeof(client_addr));
  client_addr.sin_family = AF_INET;
  client_addr.sin_addr.s_addr = INADDR_ANY;
  client_addr.sin_port = htons(8080);

  // Bind the socket to the client address
  if (bind(client_socket, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
    perror("bind()");
    exit(1);
  }

  // Listen for client connections
  while (1) {
    client_addr_len = sizeof(client_addr);

    // Accept a client connection
    proxy(client_socket, &client_addr, client_addr_len);
  }

  // Close the client socket
  close(client_socket);

  return 0;
}