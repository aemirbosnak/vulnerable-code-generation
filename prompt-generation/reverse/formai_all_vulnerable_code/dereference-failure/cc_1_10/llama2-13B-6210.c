//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024 // range of ports to scan (1024-65535)
#define HOST_MAX_LEN 256 // maximum length of hostname (256 characters)

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <host> [<port>...]\n", argv[0]);
    return 1;
  }

  // parse command-line arguments
  char *host = argv[1];
  int port_start = 1024;
  int port_end = 65535;
  int i;

  // check if host is a valid IP address or hostname
  if (!inet_pton(AF_INET, host, &(struct in_addr) {0})) {
    printf("Invalid hostname or IP address: %s\n", host);
    return 1;
  }

  // check if port range is valid
  if (port_start > port_end) {
    printf("Invalid port range: %d-%d\n", port_start, port_end);
    return 1;
  }

  // create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    return 1;
  }

  // set up the socket address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port_start);
  inet_pton(AF_INET, host, &server_addr.sin_addr);

  // connect to the target host
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect() failed");
    close(sock);
    return 1;
  }

  // scan for open ports
  for (i = port_start; i <= port_end; i++) {
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(i);
    inet_pton(AF_INET, host, &client_addr.sin_addr);

    // send a SYN packet to the target port
    int packet_len = sizeof(client_addr) + sizeof(struct sockaddr_in);
    char *packet = (char *)malloc(packet_len);
    memcpy(packet, &client_addr, packet_len);

    if (sendto(sock, packet, packet_len, 0, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
      perror("sendto() failed");
      free(packet);
      continue;
    }

    // receive a SYN-ACK packet
    packet_len = sizeof(client_addr) + sizeof(struct sockaddr_in);
    packet = (char *)malloc(packet_len);
    if (recvfrom(sock, packet, packet_len, 0, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
      perror("recvfrom() failed");
      free(packet);
      continue;
    }

    // check if the port is open
    if (ntohl(client_addr.sin_port) != i) {
      printf("Port %d is open on %s\n", i, host);
    }

    free(packet);
  }

  // close the socket
  close(sock);

  return 0;
}