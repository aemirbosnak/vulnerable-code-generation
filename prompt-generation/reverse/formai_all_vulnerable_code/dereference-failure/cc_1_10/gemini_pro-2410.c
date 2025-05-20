//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: high level of detail
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

// Define the timeout value for each port scan in seconds
#define TIMEOUT_SECONDS 1

// Function to scan a single port
int scan_port(const char *ip_address, int port) {
  // Create a socket descriptor
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  // Set the socket timeout
  struct timeval timeout;
  timeout.tv_sec = TIMEOUT_SECONDS;
  timeout.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
    perror("setsockopt");
    close(sockfd);
    return -1;
  }

  // Construct the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(ip_address);
  server_addr.sin_port = htons(port);

  // Attempt to connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    close(sockfd);
    return -1;
  }

  // The port is open if we reach this point
  close(sockfd);
  return 0;
}

// Function to scan a range of ports
int scan_ports(const char *ip_address, int start_port, int end_port) {
  // Validate the input
  if (start_port < 0 || end_port < start_port || end_port > MAX_PORTS) {
    fprintf(stderr, "Invalid port range: %d-%d\n", start_port, end_port);
    return -1;
  }

  // Scan the ports
  int open_ports_count = 0;
  for (int port = start_port; port <= end_port; port++) {
    if (scan_port(ip_address, port) == 0) {
      printf("Port %d is open\n", port);
      open_ports_count++;
    }
  }

  // Return the number of open ports
  return open_ports_count;
}

// Main function
int main(int argc, char **argv) {
  // Check the number of arguments
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
    return -1;
  }

  // Get the IP address, start port, and end port from the arguments
  const char *ip_address = argv[1];
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  // Scan the ports
  int open_ports_count = scan_ports(ip_address, start_port, end_port);
  if (open_ports_count == -1) {
    return -1;
  }

  // Print the results
  printf("Scanned %d ports on %s\n", end_port - start_port + 1, ip_address);
  printf("%d open ports found\n", open_ports_count);

  return 0;
}