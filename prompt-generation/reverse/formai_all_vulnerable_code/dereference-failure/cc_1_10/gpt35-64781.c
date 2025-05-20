//FormAI DATASET v1.0 Category: Port Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define SCAN_TIMEOUT 5 // Timeout in seconds for port scanning
#define MAX_PORTS 10000 // Maximum number of ports to scan
#define BUFFER_SIZE 1024 // Buffer size for communication with hosts

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <host>\n", argv[0]);
    exit(1);
  }

  // Resolve host name
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    printf("Error: could not resolve host name\n");
    exit(1);
  }

  // Create socket for communication with host
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error: could not create socket\n");
    exit(1);
  }

  // Set up timeout for socket
  struct timeval timeout;
  timeout.tv_sec = SCAN_TIMEOUT;
  timeout.tv_usec = 0;
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
  setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

  // Scan ports
  printf("Scanning %s\n", argv[1]);
  printf("=================\n");
  int i, port;
  struct sockaddr_in serv_addr;
  char buffer[BUFFER_SIZE];
  for (i = 1; i <= MAX_PORTS; i++) {
    // Clear the buffer
    memset(buffer, 0, BUFFER_SIZE);

    // Set up socket address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(i);
    serv_addr.sin_addr = *((struct in_addr*) host->h_addr);

    // Try to connect to port
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      continue;
    }

    // If the port is open, report it
    printf("Port %d is open\n", i);
    close(sockfd);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
      printf("Error: could not create socket\n");
      exit(1);
    }
  }

  // Close the socket
  close(sockfd);
  printf("=================\n");
  printf("Scan completed\n");

  return 0;
}