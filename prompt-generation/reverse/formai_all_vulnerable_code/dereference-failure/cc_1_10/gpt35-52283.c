//FormAI DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

// function to check if a port is open or not
int is_port_open(const char *ip, int port_num) {
  // create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    exit(EXIT_FAILURE);
  }
  // set up the address for the remote server
  struct sockaddr_in remote_addr;
  remote_addr.sin_family = AF_INET;
  remote_addr.sin_port = htons(port_num);
  if (inet_pton(AF_INET, ip, &remote_addr.sin_addr) < 1) {
    perror("inet_pton() failed");
    exit(EXIT_FAILURE);
  }
  // connect to the remote server
  int connected = connect(sock, (struct sockaddr *) &remote_addr, sizeof(remote_addr));
  if (connected < 0) {
    close(sock);
    return 0;
  }
  close(sock);
  return 1;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("usage: %s <ip_address> <port_range>\n", argv[0]);
    printf("example: %s 127.0.0.1 1-1024\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *ip = argv[1];
  char *port_range = argv[2];

  // parse the port range
  int port_start, port_end;
  char *dash_position = strstr(port_range, "-");
  if (dash_position == NULL) {
    printf("invalid port range: %s\n", port_range);
    return EXIT_FAILURE;
  }
  *dash_position = '\0';
  port_start = atoi(port_range);
  port_end = atoi(dash_position + 1);

  // scan for open ports
  printf("Scanning ports %d to %d on %s...\n", port_start, port_end, ip);
  for (int port_num = port_start; port_num <= port_end; port_num++) {
    if (is_port_open(ip, port_num)) {
      printf("Port %d is open\n", port_num);
    }
  }

  return EXIT_SUCCESS;
}