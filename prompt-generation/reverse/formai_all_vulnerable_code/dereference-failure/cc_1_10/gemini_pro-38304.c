//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// I am a network ping test program in C! I'm here to help you check if a remote host is reachable, and how long it takes to get a response from it.

// I start by getting the hostname or IP address of the remote host.
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <hostname or IP address>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *hostname = argv[1];

  // Then I resolve the hostname to an IP address.
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    printf("Error resolving hostname %s\n", hostname);
    return EXIT_FAILURE;
  }

  // I create a socket to send and receive data from the remote host.
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    printf("Error creating socket\n");
    return EXIT_FAILURE;
  }

  // I set up the socket address of the remote host.
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(33434);
  memcpy(&addr.sin_addr, host->h_addr, sizeof(addr.sin_addr));

  // I send a ping message to the remote host.
  char *message = "PING";
  int len = strlen(message);
  int sent = sendto(sockfd, message, len, 0, (struct sockaddr *)&addr, sizeof(addr));
  if (sent < 0) {
    printf("Error sending ping message\n");
    return EXIT_FAILURE;
  }

  // I wait for a response from the remote host.
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));
  int recvlen = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
  if (recvlen < 0) {
    printf("Error receiving response\n");
    return EXIT_FAILURE;
  }

  // I calculate the round-trip time (RTT) of the ping message.
  struct timeval tv;
  gettimeofday(&tv, NULL);
  long long start_time = tv.tv_sec * 1000000 + tv.tv_usec;
  long long end_time = start_time + (recvlen * 8) / 1000;
  long long rtt = end_time - start_time;

  // I print out the results of the ping test.
  printf("Ping to %s: %s bytes, RTT: %lld ms\n", hostname, buffer, rtt);

  // I close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}