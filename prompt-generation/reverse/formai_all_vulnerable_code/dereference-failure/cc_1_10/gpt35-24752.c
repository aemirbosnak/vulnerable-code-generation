//FormAI DATASET v1.0 Category: Socket programming ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <ip> <port>\n", argv[0]);
    return 1;
  }

  // Create a socket for TCP/IP communication
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket() failed");
    return 1;
  }

  // Set up the server address and port
  struct sockaddr_in serv_addr;
  bzero((char *)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_addr.sin_port = htons(atoi(argv[2]));

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect() failed");
    return 1;
  }

  // Send and receive data
  char buffer[256];
  int n;
  printf("Please enter a message: ");
  bzero(buffer, 256);
  fgets(buffer, 255, stdin);
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("write() failed");
    close(sockfd);
    return 1;
  }
  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);
  if (n < 0) {
    perror("read() failed");
    close(sockfd);
    return 1;
  }
  printf("Server replied: %s\n", buffer);

  // Close the socket
  close(sockfd);
  return 0;
}