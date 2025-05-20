//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    return 1;
  }

  struct hostent *host;
  struct sockaddr_in server_addr;
  int sockfd;
  int bytes_sent, bytes_received;
  char buffer[BUFFER_SIZE];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  // Get the host by name
  host = gethostbyname(argv[1]);
  if (host == NULL) {
    perror("gethostbyname");
    return 1;
  }

  // Fill in the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
  server_addr.sin_port = htons(80);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send a request to the server
  memset(buffer, 0, BUFFER_SIZE);
  sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
  bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes_sent < 0) {
    perror("send");
    return 1;
  }

  // Receive a response from the server
  memset(buffer, 0, BUFFER_SIZE);
  bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (bytes_received < 0) {
    perror("recv");
    return 1;
  }

  // Print the response from the server
  printf("%s", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}