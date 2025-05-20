//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  // Create a socket
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
    perror("Error creating socket");
    return -1;
  }

  // Define server address
  struct hostent *server = gethostbyname("example.com");
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(80);
  bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);

  // Connect to server
  if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Error connecting to server");
    return -1;
  }

  // Prepare HTTP request
  char *message = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
  if (send(client_socket, message, strlen(message), 0) < 0) {
    perror("Error sending message");
    return -1;
  }

  // Receive HTTP response
  char response[4096];
  if (recv(client_socket, response, 4096, 0) < 0) {
    perror("Error receiving response");
    return -1;
  }

  // Print HTTP response
  printf("%s", response);

  // Close socket
  close(client_socket);

  return 0;
}