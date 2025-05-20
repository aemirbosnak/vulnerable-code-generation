//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Client function
int client(char *ip, int port) {
  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return -1;
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(ip);
  server_addr.sin_port = htons(port);

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return -1;
  }

  // Send a message to the server
  char *message = "Hello, server!";
  if (send(sock, message, strlen(message), 0) == -1) {
    perror("send");
    return -1;
  }

  // Receive a message from the server
  char buffer[1024];
  int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv");
    return -1;
  }

  // Print the message from the server
  printf("Received from server: %s\n", buffer);

  // Close the socket
  close(sock);

  return 0;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided enough arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
    return -1;
  }

  // Convert the IP address and port to integers
  char *ip = argv[1];
  int port = atoi(argv[2]);

  // Call the client function
  client(ip, port);

  return 0;
}