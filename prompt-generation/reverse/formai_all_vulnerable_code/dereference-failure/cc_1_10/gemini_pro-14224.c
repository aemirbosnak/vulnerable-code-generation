//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

// function to resolve a hostname to its IP address
int resolve_hostname(char *hostname, struct sockaddr_in *addr) {
  struct hostent *host_entry;

  // get the host entry for the hostname
  host_entry = gethostbyname(hostname);
  if (host_entry == NULL) {
    return -1;
  }

  // copy the IP address into the sockaddr_in structure
  memcpy(&addr->sin_addr, host_entry->h_addr_list[0], host_entry->h_length);
  return 0;
}

// function to scan a port on a remote host
int scan_port(char *hostname, int port) {
  struct sockaddr_in addr;
  int sockfd;

  // resolve the hostname to its IP address
  if (resolve_hostname(hostname, &addr) != 0) {
    return -1;
  }

  // create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    return -1;
  }

  // set the socket timeout to 1 second
  struct timeval timeout;
  timeout.tv_sec = 1;
  timeout.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
    return -1;
  }

  // connect to the remote host and port
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
    // the port is open
    return 1;
  }

  // the port is closed
  return 0;
}

int main(int argc, char **argv) {
  int port;
  char *hostname;

  // get the hostname and port from the command line arguments
  if (argc != 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    return -1;
  }

  hostname = argv[1];
  port = atoi(argv[2]);

  // scan the port
  int result = scan_port(hostname, port);

  // print the results
  if (result == 1) {
    printf("Port %d is open on host %s\n", port, hostname);
  } else if (result == 0) {
    printf("Port %d is closed on host %s\n", port, hostname);
  } else {
    printf("Error scanning port %d on host %s\n", port, hostname);
  }

  return 0;
}