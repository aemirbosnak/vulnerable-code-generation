//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <server-ip> <server-port> <command>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse command line arguments
  const char *server_ip = argv[1];
  const int server_port = atoi(argv[2]);
  const char *command = argv[3];

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Resolve server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(server_ip);
  server_addr.sin_port = htons(server_port);

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send command to server
  if (send(sockfd, command, strlen(command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive response from server
  char buf[MAX_BUF_SIZE];
  int num_bytes_received;
  while ((num_bytes_received = recv(sockfd, buf, MAX_BUF_SIZE, 0)) > 0) {
    // Print response to stdout
    printf("%s", buf);
  }

  // Close socket
  close(sockfd);

  return EXIT_SUCCESS;
}