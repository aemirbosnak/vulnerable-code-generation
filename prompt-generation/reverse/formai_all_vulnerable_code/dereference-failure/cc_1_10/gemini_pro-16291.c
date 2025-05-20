//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifndef WIN32
#include <unistd.h>
#endif

#define HOST "127.0.0.1"
#define PORT 80
#define BUFFER_SIZE 1024

// This function sends a message to a server and prints the response.
int send_message(char *message, int length) {
  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  // Connect to the server.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = inet_addr(HOST);
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return -1;
  }

  // Send the message.
  if (send(sockfd, message, length, 0) == -1) {
    perror("send");
    return -1;
  }

  // Receive the response.
  char buffer[BUFFER_SIZE];
  int received = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (received == -1) {
    perror("recv");
    return -1;
  }

  // Print the response.
  printf("Received: %s\n", buffer);

  // Close the socket.
  close(sockfd);

  return 0;
}

// This function scans a range of ports on a host and prints the open ports.
int port_scan(char *host, int start_port, int end_port) {
  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  // Connect to the server.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(start_port);
  server_addr.sin_addr.s_addr = inet_addr(host);
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return -1;
  }

  // Scan the range of ports.
  for (int port = start_port; port <= end_port; port++) {
    // Set the port number.
    server_addr.sin_port = htons(port);

    // Send a message to the port.
    char message[BUFFER_SIZE];
    snprintf(message, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
    int length = strlen(message);
    if (send_message(message, length) == -1) {
      perror("send_message");
      return -1;
    }

    // Check if the port is open.
    int received = recv(sockfd, message, BUFFER_SIZE, 0);
    if (received > 0) {
      printf("Port %d is open\n", port);
    }
  }

  // Close the socket.
  close(sockfd);

  return 0;
}

// This function is the entry point of the program.
int main(int argc, char *argv[]) {
  // Check the arguments.
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <host> <start_port> <end_port>\n", argv[0]);
    return -1;
  }

  // Convert the arguments to integers.
  char *host = argv[1];
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  // Scan the range of ports.
  if (port_scan(host, start_port, end_port) == -1) {
    perror("port_scan");
    return -1;
  }

  return 0;
}