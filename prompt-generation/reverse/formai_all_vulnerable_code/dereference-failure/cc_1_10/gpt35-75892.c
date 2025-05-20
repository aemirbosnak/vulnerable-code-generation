//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {

  // Ensure domain name is specified as argument
  if (argc < 2) {
    printf("Please specify the domain name.\n");
    return 0;
  }

  // Create socket for client
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
    printf("Error creating socket for client.\n");
    return 0;
  }
  
  // Define server address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(80);
  inet_pton(AF_INET, argv[1], &server_address.sin_addr);

  // Connect to server
  int connection_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
  if (connection_status < 0) {
    printf("Error connecting to server.\n");
    return 0;
  }

  // Define HTTP request
  char request[500];
  sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);

  // Send HTTP request to server
  send(client_socket, request, strlen(request), 0);

  // Receive response from server
  char response[10000];
  recv(client_socket, &response, sizeof(response), 0);

  // Print HTTP response
  printf("%s", response);
  
  // Close socket
  close(client_socket);
  
  return 0;
}