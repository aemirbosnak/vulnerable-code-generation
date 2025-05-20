//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server IP> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set the socket options
  int optval = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Get the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
    perror("inet_pton");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Initialize the QoS parameters
  struct timeval timeout;
  timeout.tv_sec = 1;
  timeout.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Send a message to the server
  char *msg = "Hello world!";
  if (send(sockfd, msg, strlen(msg), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive a message from the server
  char buf[BUFSIZE];
  memset(buf, 0, BUFSIZE);
  if (recv(sockfd, buf, BUFSIZE, 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Print the QoS parameters
  struct timeval start_time, end_time;
  gettimeofday(&start_time, NULL);
  gettimeofday(&end_time, NULL);
  long elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
  printf("Round-trip time: %ld us\n", elapsed_time);

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}