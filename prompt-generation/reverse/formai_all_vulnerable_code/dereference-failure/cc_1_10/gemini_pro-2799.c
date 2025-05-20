//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535

// Function to check if a port is open
int is_port_open(char *ip, int port) {
  int sockfd;
  struct sockaddr_in serv_addr;

  // Create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return -1;
  }

  // Set the socket options
  int opt = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt");
    close(sockfd);
    return -1;
  }

  // Set the server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
    perror("inet_pton");
    close(sockfd);
    return -1;
  }

  // Try to connect to the server
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    close(sockfd);
    return 0;
  }

  // If the connection was successful, the port is open
  close(sockfd);
  return 1;
}

// Function to scan a range of ports
void scan_ports(char *ip, int start_port, int end_port) {
  for (int i = start_port; i <= end_port; i++) {
    if (is_port_open(ip, i)) {
      printf("Port %d is open\n", i);
    }
  }
}

// Main function
int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
    return 1;
  }

  // Get the IP address
  char *ip = argv[1];

  // Get the start and end ports
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  // Check if the start and end ports are valid
  if (start_port < 0 || start_port > MAX_PORTS || end_port < 0 || end_port > MAX_PORTS) {
    printf("Invalid port range\n");
    return 1;
  }

  // Scan the ports
  scan_ports(ip, start_port, end_port);

  return 0;
}