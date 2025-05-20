//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_HOSTNAME_LEN 100

int main(int argc, char *argv[]) {
  int sock = 0;
  struct hostent *he;
  struct sockaddr_in sa;
  char hostname[MAX_HOSTNAME_LEN];
  char port_str[10];
  int port;

  if (argc < 2) {
    printf("Usage: %s <host>\n", argv[0]);
    return 1;
  }

  // Initialize the socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    return 1;
  }

  // Get the hostname and port from the command line arguments
  strcpy(hostname, argv[1]);
  port = atoi(argv[2]);

  // Check if the port is within the range
  if (port < 0 || port > PORT_RANGE) {
    printf("Invalid port %d\n", port);
    return 1;
  }

  // Convert the port number to a string
  snprintf(port_str, 10, "%d", port);

  // Create the socket address
  memset(&sa, 0, sizeof(sa));
  sa.sin_family = AF_INET;
  sa.sin_port = htons(port);
  if (inet_pton(AF_INET, hostname, &sa.sin_addr) <= 0) {
    perror("inet_pton() failed");
    return 1;
  }

  // Connect to the host and port
  if (connect(sock, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
    perror("connect() failed");
    return 1;
  }

  // Print the host and port
  printf("Host: %s, Port: %s\n", hostname, port_str);

  // Close the socket
  close(sock);

  return 0;
}