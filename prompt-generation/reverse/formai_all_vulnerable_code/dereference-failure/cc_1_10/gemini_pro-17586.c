//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
  // Introspection: Check if the program was invoked with proper arguments.
  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int port = atoi(argv[1]);

  // Introspection: Validate the port number.
  if (port <= 0 || port > 65535)
  {
    fprintf(stderr, "Invalid port number: %d\n", port);
    exit(EXIT_FAILURE);
  }

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // Introspection: Check if socket creation was successful.
  if (sockfd < 0)
  {
    perror("socket()");
    exit(EXIT_FAILURE);
  }

  // Bind the socket to an address.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(port);

  // Introspection: Check if binding was successful.
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
  {
    perror("bind()");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections.
  if (listen(sockfd, 5) < 0)
  {
    perror("listen()");
    exit(EXIT_FAILURE);
  }

  // Accept an incoming connection.
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);

  // Introspection: Check if connection was accepted successfully.
  if (client_sockfd < 0)
  {
    perror("accept()");
    exit(EXIT_FAILURE);
  }

  // Receive a message from the client.
  char buffer[1024];
  int n = recv(client_sockfd, buffer, sizeof(buffer), 0);

  // Introspection: Check if message was received successfully.
  if (n < 0)
  {
    perror("recv()");
    exit(EXIT_FAILURE);
  }

  // Print the received message.
  printf("Received message: %s\n", buffer);

  // Close the client socket.
  close(client_sockfd);

  // Close the server socket.
  close(sockfd);

  return 0;
}