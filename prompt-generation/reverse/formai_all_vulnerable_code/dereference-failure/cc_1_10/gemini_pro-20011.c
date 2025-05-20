//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *hostname = argv[1];
  int sockfd;
  struct sockaddr_in servaddr;
  struct hostent *host;
  struct timeval start, end;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Get the host's IP address
  host = gethostbyname(hostname);
  if (host == NULL) {
    fprintf(stderr, "gethostbyname: %s\n", hostname);
    exit(EXIT_FAILURE);
  }

  // Fill in the server's address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(80);
  memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

  // Send a ping request
  char buf[BUF_SIZE];
  memset(buf, 0, BUF_SIZE);
  strcpy(buf, "PING");
  gettimeofday(&start, NULL);
  sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));

  // Wait for a response
  memset(buf, 0, BUF_SIZE);
  socklen_t len = sizeof(servaddr);
  int n = recvfrom(sockfd, buf, BUF_SIZE, 0, (struct sockaddr *)&servaddr, &len);
  gettimeofday(&end, NULL);

  // Calculate the round-trip time
  long elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

  // Print the results
  printf("Round-trip time: %ld microseconds\n", elapsed);

  // Close the socket
  close(sockfd);

  return 0;
}