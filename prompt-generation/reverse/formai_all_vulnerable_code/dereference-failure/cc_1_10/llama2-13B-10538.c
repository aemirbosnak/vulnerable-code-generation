//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024  // range of ports to scan
#define MAX_HOSTNAME_LEN 50  // maximum length of hostname

// structure to hold host and port information
typedef struct {
  char *hostname;  // hostname of the target system
  unsigned short port;  // port number of the target system
} host_port_t;

// function to scan a range of ports on a host
void scan_ports(host_port_t *hosts, int num_hosts, int port_start, int port_end) {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    exit(EXIT_FAILURE);
  }

  // loop through the range of ports
  for (int i = port_start; i <= port_end; i++) {
    // create a socket address structure
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(i);

    // get the hostname of the target system
    char hostname[MAX_HOSTNAME_LEN];
    gethostname(hostname, MAX_HOSTNAME_LEN);

    // create a host_port_t structure to hold the host and port information
    host_port_t host;
    host.hostname = hostname;
    host.port = i;

    // add the host and port to the list of hosts to scan
    hosts[num_hosts].hostname = host.hostname;
    hosts[num_hosts].port = host.port;

    // connect to the target system on the current port
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
      perror("connect() failed");
      exit(EXIT_FAILURE);
    }

    // send a request to the target system to see if it's listening
    char request[1024];
    request[0] = '!';  // marker to indicate a request
    send(sock, request, 1, 0);

    // receive the response from the target system
    char response[1024];
    recv(sock, response, 1024, 0);

    // check if the response indicates that the port is open
    if (response[0] == '!') {
      // port is open, so print the host and port information
      printf("Open port %d on %s\n", host.port, host.hostname);
    }

    // close the socket
    close(sock);

    // increment the number of hosts scanned
    num_hosts++;
  }

  // clean up
  close(sock);
}

int main() {
  // create an array of host_port_t structures to hold the host and port information
  host_port_t hosts[10];

  // scan the range of ports on the current host
  scan_ports(hosts, 10, 1024, 65535);

  return 0;
}