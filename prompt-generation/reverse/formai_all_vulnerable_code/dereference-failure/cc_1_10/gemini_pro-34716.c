//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of ports to scan
#define MAX_PORTS 100

// Define the timeout value for each port scan
#define TIMEOUT 1

// Function to scan a single port
int scan_port(char *ip, int port) {
  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return -1;
  }

  // Set the socket timeout
  struct timeval timeout;
  timeout.tv_sec = TIMEOUT;
  timeout.tv_usec = 0;
  if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
    perror("setsockopt");
    close(sock);
    return -1;
  }

  // Connect to the port
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip);
  addr.sin_port = htons(port);
  if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
    close(sock);
    return -1;
  }

  // Close the socket
  close(sock);

  // Return 0 if the port is open, -1 otherwise
  return 0;
}

// Function to scan a range of ports
int scan_ports(char *ip, int start_port, int end_port) {
  // Initialize the number of open ports
  int num_open_ports = 0;

  // Scan each port in the range
  for (int port = start_port; port <= end_port; port++) {
    if (scan_port(ip, port) == 0) {
      printf("Port %d is open\n", port);
      num_open_ports++;
    }
  }

  // Return the number of open ports
  return num_open_ports;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided enough arguments
  if (argc < 3) {
    printf("Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
    return -1;
  }

  // Get the IP address from the command line
  char *ip = argv[1];

  // Get the start and end ports from the command line
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  // Scan the ports
  int num_open_ports = scan_ports(ip, start_port, end_port);

  // Print the number of open ports
  printf("Found %d open ports\n", num_open_ports);

  return 0;
}