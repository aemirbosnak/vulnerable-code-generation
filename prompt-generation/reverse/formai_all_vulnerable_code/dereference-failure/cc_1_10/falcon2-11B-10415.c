//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: cheerful
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_MESSAGE_SIZE 256

int main() {
  // Create a socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Set the socket to allow reuse
  int reuse_socket = 1;
  setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse_socket, sizeof(reuse_socket));

  // Set the port number and IP address
  int port = 12345;
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port);

  // Bind the socket to the port and IP address
  bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

  // Listen for incoming connections
  listen(server_socket, 5);

  // Accept a connection
  struct sockaddr_in client_address;
  socklen_t client_len = sizeof(client_address);
  int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_len);

  // Allocate memory for the message
  char *message = (char *)malloc(MAX_MESSAGE_SIZE * sizeof(char));

  // Receive the message from the client
  int bytes_received = recv(client_socket, message, MAX_MESSAGE_SIZE, 0);

  // Print the message
  printf("Received message from client: %s\n", message);

  // Close the socket
  close(client_socket);

  return 0;
}