//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024 // range of ports to scan

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <IP address>\n", argv[0]);
    return 1;
  }

  char *ip_addr = argv[1];
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket creation failed");
    return 2;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(0); // scan all ports
  inet_pton(AF_INET, ip_addr, &server_addr.sin_addr);

  // send SYN packet to initiate connection
  char *packet = (char *)malloc(1024);
  packet[0] = 0x12; // SYN packet
  memset(packet + 1, 0x00, 1022); // fill with zeros
  sendto(sock, packet, 1024, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // receive response packet
  char buffer[1024];
  recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // check for RST packet (connection reset)
  if (buffer[0] == 0x13) { // RST packet
    printf("Connection reset by peer\n");
    return 3;
  }

  // scan ports
  for (int i = 1; i <= PORT_RANGE; i++) {
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(i);
    inet_pton(AF_INET, ip_addr, &client_addr.sin_addr);

    // send ACK packet to establish connection
    packet[0] = 0x15; // ACK packet
    memset(packet + 1, 0x00, 1022); // fill with zeros
    sendto(sock, packet, 1024, 0, (struct sockaddr *)&client_addr, sizeof(client_addr));

    // receive response packet
    recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)&client_addr, sizeof(client_addr));

    // check for RST packet (connection reset)
    if (buffer[0] == 0x13) { // RST packet
      printf("Connection reset by peer on port %d\n", ntohs(client_addr.sin_port));
      continue;
    }

    // found open port, print it
    printf("Open port found on IP %s: %d\n", ip_addr, ntohs(client_addr.sin_port));
  }

  close(sock);
  return 0;
}