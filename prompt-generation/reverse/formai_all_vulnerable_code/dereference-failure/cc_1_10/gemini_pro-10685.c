//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of ports to scan
#define MAX_PORTS 100

// Define the default timeout for each port scan
#define DEFAULT_TIMEOUT 1

// Define the usage message
#define USAGE "Usage: %s <hostname> <port1> <port2> ... <portN>\n"

// Function to print the usage message and exit
void usage(char *argv[]) {
  fprintf(stderr, USAGE, argv[0]);
  exit(EXIT_FAILURE);
}

// Function to scan a single port
int scan_port(char *hostname, int port, int timeout) {
  int sockfd;
  struct sockaddr_in addr;
  struct hostent *host;

  // Create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    return -1;
  }

  // Set the socket timeout
  struct timeval tv;
  tv.tv_sec = timeout;
  tv.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv,
                 sizeof(tv)) == -1) {
    perror("setsockopt");
    close(sockfd);
    return -1;
  }

  // Resolve the hostname
  if ((host = gethostbyname(hostname)) == NULL) {
    herror("gethostbyname");
    close(sockfd);
    return -1;
  }

  // Set the address
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  memcpy(&addr.sin_addr, host->h_addr, host->h_length);
  addr.sin_port = htons(port);

  // Connect to the port
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    if (errno == ETIMEDOUT) {
      // The port is closed
      close(sockfd);
      return 0;
    } else {
      perror("connect");
      close(sockfd);
      return -1;
    }
  }

  // The port is open
  close(sockfd);
  return 1;
}

// Function to scan a range of ports
void scan_ports(char *hostname, int *ports, int num_ports, int timeout) {
  int i;
  for (i = 0; i < num_ports; i++) {
    if (scan_port(hostname, ports[i], timeout) == 1) {
      printf("Port %d is open\n", ports[i]);
    }
  }
}

int main(int argc, char *argv[]) {
  int i;
  int ports[MAX_PORTS];
  int num_ports;
  int timeout;

  // Check the number of arguments
  if (argc < 3) {
    usage(argv);
  }

  // Get the hostname
  char *hostname = argv[1];

  // Get the ports
  num_ports = argc - 2;
  for (i = 0; i < num_ports; i++) {
    ports[i] = atoi(argv[i + 2]);
  }

  // Get the timeout
  timeout = DEFAULT_TIMEOUT;

  // Scan the ports
  scan_ports(hostname, ports, num_ports, timeout);

  return EXIT_SUCCESS;
}