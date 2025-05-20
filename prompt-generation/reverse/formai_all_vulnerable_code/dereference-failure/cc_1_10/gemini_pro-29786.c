//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <sys/socket.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Create a UDP socket
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the socket options
  int optval = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
    perror("setsockopt");
    return EXIT_FAILURE;
  }

  // Get the host information
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  // Create the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  server_addr.sin_addr = *(struct in_addr *) host->h_addr;

  // Create the buffer
  char buf[BUFSIZE];

  // Send a message to the server
  int n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if (n < 0) {
    perror("sendto");
    return EXIT_FAILURE;
  }

  // Receive a message from the server
  n = recvfrom(sockfd, buf, BUFSIZE, 0, NULL, NULL);
  if (n < 0) {
    perror("recvfrom");
    return EXIT_FAILURE;
  }

  // Close the socket
  close(sockfd);

  // Calculate the round-trip time
  struct timeval tv1, tv2;
  gettimeofday(&tv1, NULL);
  gettimeofday(&tv2, NULL);
  double rtt = (tv2.tv_sec - tv1.tv_sec) * 1000.0 + (tv2.tv_usec - tv1.tv_usec) / 1000.0;

  // Print the statistics
  printf("RTT: %f ms\n", rtt);

  return EXIT_SUCCESS;
}