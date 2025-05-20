//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Declare the port scanner function
void scan_ports(char *ip_address, int start_port, int end_port);

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <IP address> <start port> <end port>\n", argv[0]);
    return 1;
  }

  // Get the IP address, start port, and end port from the command line arguments
  char *ip_address = argv[1];
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  // Scan the ports
  scan_ports(ip_address, start_port, end_port);

  return 0;
}

// Define the port scanner function
void scan_ports(char *ip_address, int start_port, int end_port) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Set the socket options
  int optval = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
    perror("setsockopt");
    exit(1);
  }

  // Set the socket timeout
  struct timeval timeout;
  timeout.tv_sec = 1;
  timeout.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
    perror("setsockopt");
    exit(1);
  }

  // Create the socket address
  struct sockaddr_in sockaddr;
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(start_port);
  if (inet_aton(ip_address, &sockaddr.sin_addr) == 0) {
    perror("inet_aton");
    exit(1);
  }

  // Scan the ports
  for (int port = start_port; port <= end_port; port++) {
    // Set the port number
    sockaddr.sin_port = htons(port);

    // Connect to the port
    if (connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == 0) {
      // The port is open
      printf("Port %d is open\n", port);
    }
  }

  // Close the socket
  close(sockfd);
}