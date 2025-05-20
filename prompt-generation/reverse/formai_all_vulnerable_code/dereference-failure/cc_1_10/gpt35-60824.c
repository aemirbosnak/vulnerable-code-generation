//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {

  if (argc < 3) {
    printf("Usage: %s <server_host> <server_port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const char *host = argv[1];
  const int port = atoi(argv[2]);
  const char *message = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
  char buffer[MAX_BUFFER] = {0};
  int sock = 0, bytes_received = 0;
  struct sockaddr_in server_addr = {0};

  // Create socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("Socket creation error\n");
    exit(EXIT_FAILURE);
  }

  // Set server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
    printf("Invalid address/Address not supported\n");
    exit(EXIT_FAILURE);
  }

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("Failed to connect to server\n");
    exit(EXIT_FAILURE);
  }

  printf("Connected to %s:%d\n", host, port);

  // Send message
  char *request_message = (char *)malloc(strlen(message) + strlen(host) - 1);
  sprintf(request_message, message, host);
  if (send(sock, request_message, strlen(request_message), 0) < 0) {
    printf("Failed to send message to server\n");
    exit(EXIT_FAILURE);
  }

  printf("Message sent to server: \n%s\n", request_message);

  // Receive message
  bytes_received = recv(sock, buffer, MAX_BUFFER, 0);
  if (bytes_received < 0) {
    printf("Failed to receive message from server\n");
    exit(EXIT_FAILURE);
  }
  buffer[bytes_received] = '\0';

  printf("Response from server:\n%s\n", buffer);

  // Close socket
  close(sock);

  return 0;
}