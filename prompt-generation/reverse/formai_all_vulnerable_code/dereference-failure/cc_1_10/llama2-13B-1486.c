//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error: Please specify a port range to scan\n");
    return 1;
  }

  int start_port = atoi(argv[1]);
  int end_port = start_port + PORT_RANGE;

  struct sockaddr_in server_addr;
  socklen_t client_len = sizeof(server_addr);
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  if (sock < 0) {
    perror("Socket creation failed");
    return 1;
  }

  // Set up the server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(start_port);
  inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&server_addr, client_len) < 0) {
    perror("Connect failed");
    return 1;
  }

  // Scan for open ports
  for (int port = start_port; port <= end_port; port++) {
    char buffer[1024];
    int bytes_sent = send(sock, "hello", 5, 0);
    if (bytes_sent < 0) {
      perror("Send failed");
      continue;
    }

    int bytes_recv = recv(sock, buffer, 1024, 0);
    if (bytes_recv < 0) {
      perror("Recv failed");
      continue;
    }

    printf("Port %d is open! 😊\n", port);
  }

  close(sock);
  return 0;
}