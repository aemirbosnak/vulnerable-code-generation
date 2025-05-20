//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_IP_LEN 15
#define MAX_PORTS 65536

int main(int argc, char *argv[]) {
  int sock, port;
  struct sockaddr_in server_addr;
  char buffer[256];
  char *ip_str;
  int i, j;

  if (argc < 2) {
    printf("Usage: %s <IP_range>\n", argv[0]);
    return 0;
  }

  ip_str = argv[1];

  // Parse IP range
  int ip_start = atoi(ip_str);
  int ip_end = atoi(ip_str + strlen(ip_str) - 1);

  // Create socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    return 1;
  }

  // Set server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(0);
  inet_pton(AF_INET, ip_str, &server_addr.sin_addr);

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect() failed");
    return 1;
  }

  // Send SYN packet to open connection
  send(sock, "SYN", 3, 0);

  // Receive response packet
  recv(sock, buffer, 256, 0);

  // Parse response packet
  for (i = 0; i < 256; i++) {
    if (buffer[i] == '\0') {
      break;
    }

    // Extract port number
    port = atoi(&buffer[i]);

    // Check if port is open
    if (port != 0) {
      printf("%d is open\n", port);
    }
  }

  // Close connection
  close(sock);

  return 0;
}