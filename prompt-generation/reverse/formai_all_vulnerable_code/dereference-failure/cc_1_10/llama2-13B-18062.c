//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024  // scan range of ports
#define MAX_HOST_LEN 64   // maximum hostname length

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error: Please provide a target hostname or IP address as an argument.\n");
    return 1;
  }

  // initialize scan structure
  struct scan_params {
    int port_start, port_end;
    char *host;
  } scan_params;

  // set scan parameters
  scan_params.port_start = 1;
  scan_params.port_end = 65535;
  scan_params.host = argv[1];

  // create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // set address and port for connect()
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(scan_params.port_start);
  inet_pton(AF_INET, scan_params.host, &server_addr.sin_addr);

  // connect to server
  int connect_res = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_res < 0) {
    perror("connect failed");
    exit(EXIT_FAILURE);
  }

  // send SYN packet to initiate connection
  char *packet = (char *)"A";
  send(sock, packet, 1, 0);

  // enter scan loop
  for (int port = scan_params.port_start; port <= scan_params.port_end; port++) {
    // create packet with target port
    char *packet = (char *)"A";
    packet[0] = port;
    send(sock, packet, 1, 0);

    // receive response packet
    char buffer[1024];
    recv(sock, buffer, 1024, 0);

    // check if response is valid
    if (buffer[0] == port) {
      printf("Port %d is open on %s\n", port, scan_params.host);
    }
  }

  // close connection
  close(sock);

  return 0;
}