//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Resolve the hostname to an IP address
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    printf("Error: Could not resolve hostname %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("Error: Could not create socket");
    exit(EXIT_FAILURE);
  }

  // Set up the socket address structure
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(80);  // HTTP port
  addr.sin_addr = *(struct in_addr *)host->h_addr;

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("Error: Could not connect to server");
    exit(EXIT_FAILURE);
  }

  // Send a HTTP HEAD request
  char buf[BUF_SIZE];
  snprintf(buf, BUF_SIZE, "HEAD / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("Error: Could not send request");
    exit(EXIT_FAILURE);
  }

  // Receive the response
  int bytes_received = recv(sock, buf, BUF_SIZE, 0);
  if (bytes_received == -1) {
    perror("Error: Could not receive response");
    exit(EXIT_FAILURE);
  }

  // Parse the response
  char *status_code = strstr(buf, "HTTP/1.1 ");
  if (status_code == NULL) {
    printf("Error: Could not parse response\n");
    exit(EXIT_FAILURE);
  }

  // Print the status code
  printf("Status code: %s\n", status_code + 9);

  // Close the socket
  close(sock);

  return 0;
}