//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
  // Define the port range to scan
  int port_min = 1;
  int port_max = 1024;

  // Loop through the port range
  for (int i = port_min; i <= port_max; i++) {
    // Resolve the hostname to an IP address
    struct hostent* host = gethostbyname("google.com");
    if (host == NULL) {
      printf("Hostname not found.\n");
      continue;
    }

    // Resolve the IP address to a sockaddr_in structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(i);
    addr.sin_addr = *(struct in_addr *)host->h_addr_list[0];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
      printf("Failed to create socket.\n");
      continue;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
      printf("Failed to connect to server.\n");
      close(sock);
      continue;
    }

    // Send a request
    char request[1024] = "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n";
    if (send(sock, request, strlen(request), 0) == -1) {
      printf("Failed to send request.\n");
      close(sock);
      continue;
    }

    // Receive the response
    char response[1024] = {0};
    ssize_t bytes_read = recv(sock, response, sizeof(response), 0);
    if (bytes_read == -1) {
      printf("Failed to receive response.\n");
      close(sock);
      continue;
    }

    // Close the socket
    close(sock);

    // Print the response
    printf("%s\n", response);
  }

  return 0;
}