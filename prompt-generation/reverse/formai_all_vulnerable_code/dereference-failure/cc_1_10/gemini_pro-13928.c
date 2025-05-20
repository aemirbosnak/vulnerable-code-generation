//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the IP address and port number from the command line arguments.
  char *ip_address = argv[1];
  int port_number = atoi(argv[2]);

  // Create a socket.
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set up the socket address.
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port_number);
  if (inet_aton(ip_address, &addr.sin_addr) == 0) {
    fprintf(stderr, "Invalid IP address: %s\n", ip_address);
    exit(EXIT_FAILURE);
  }

  // Connect to the server.
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send a message to the server.
  char *message = "Hello, world!\n";
  if (send(sock, message, strlen(message), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive a message from the server.
  char buffer[1024];
  int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Print the message from the server.
  printf("Received from server: %s\n", buffer);

  // Close the socket.
  if (close(sock) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}