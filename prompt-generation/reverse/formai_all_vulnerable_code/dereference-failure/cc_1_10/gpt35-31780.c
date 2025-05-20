//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int client_socket, response_length;
  char buffer[BUFFER_SIZE], *hostname, *path;
  struct sockaddr_in server_address;
  struct hostent* server;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Parse the URL to get hostname and path
  char* url = argv[1];
  char* protocol = strtok(url, "://");
  if (strcmp(protocol, "http") != 0) {
    fprintf(stderr, "Error: Invalid protocol\n");
    exit(EXIT_FAILURE);
  }
  hostname = strtok(NULL, "/");
  path = strtok(NULL, "") ? : "/";

  // Create socket
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  // Get server info
  server = gethostbyname(hostname);
  if (server == NULL) {
    fprintf(stderr, "Error: No such host\n");
    exit(EXIT_FAILURE);
  }

  // Set up server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(80);
  memcpy(&server_address.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

  // Connect to server
  if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
    perror("Error connecting to server");
    exit(EXIT_FAILURE);
  }

  // Send request to server
  sprintf(buffer, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);
  if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
    perror("Error sending request");
    exit(EXIT_FAILURE);
  }

  // Receive response from server
  while ((response_length = recv(client_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
    buffer[response_length] = '\0';
    printf("%s", buffer);
  }
  
  // Close socket
  close(client_socket);
  
  return EXIT_SUCCESS;
}