//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>

// Define the maximum number of ports to scan
#define MAX_PORTS 100

// Define the timeout for each port scan (in seconds)
#define TIMEOUT 1

// Define the port range to scan (start and end ports)
#define START_PORT 1
#define END_PORT 65535

// Define the message to print when a port is open
#define OPEN_PORT_MESSAGE "Port %d is open!"

// Define the message to print when a port is closed
#define CLOSED_PORT_MESSAGE "Port %d is closed."

// Define the message to print when an error occurs
#define ERROR_MESSAGE "An error occurred: %s"

// Function to scan a single port
int scan_port(char *ip_address, int port) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Set the socket timeout
  struct timeval tv;
  tv.tv_sec = TIMEOUT;
  tv.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
    perror("setsockopt");
    close(sockfd);
    return -1;
  }

  // Set the socket address
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(ip_address);

  // Connect to the port
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    if (errno == ETIMEDOUT) {
      // The port is closed
      return 0;
    } else {
      // An error occurred
      perror("connect");
      close(sockfd);
      return -1;
    }
  } else {
    // The port is open
    return 1;
  }
}

// Function to scan a range of ports
int scan_ports(char *ip_address, int start_port, int end_port) {
  int num_open_ports = 0;

  // Iterate over the range of ports
  for (int port = start_port; port <= end_port; port++) {
    // Scan the port
    int result = scan_port(ip_address, port);

    // Print the result
    if (result == 1) {
      printf(OPEN_PORT_MESSAGE, port);
      num_open_ports++;
    } else if (result == 0) {
      printf(CLOSED_PORT_MESSAGE, port);
    } else {
      printf(ERROR_MESSAGE, strerror(errno));
    }
  }

  return num_open_ports;
}

int main(int argc, char *argv[]) {
  // Check if the user has provided an IP address
  if (argc != 2) {
    printf("Usage: %s <IP address>\n", argv[0]);
    return 1;
  }

  // Get the IP address from the user
  char *ip_address = argv[1];

  // Scan the range of ports
  int num_open_ports = scan_ports(ip_address, START_PORT, END_PORT);

  // Print the results
  printf("Found %d open ports on %s.\n", num_open_ports, ip_address);

  return 0;
}