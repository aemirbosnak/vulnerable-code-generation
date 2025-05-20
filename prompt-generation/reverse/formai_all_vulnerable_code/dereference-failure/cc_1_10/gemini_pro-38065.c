//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PING_PORT 33434
#define PING_TIMEOUT 1000

struct ping_packet {
  uint32_t timestamp;
  uint16_t seq_num;
  char data[1024];
};

int ping(const char *hostname) {
  int sockfd;
  struct sockaddr_in addr;
  struct hostent *host;
  struct ping_packet packet;
  time_t start_time;
  time_t end_time;
  struct timeval timeout;
  fd_set read_fds;
  int n;

  // Create a UDP socket.
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Set the socket timeout.
  timeout.tv_sec = PING_TIMEOUT / 1000;
  timeout.tv_usec = (PING_TIMEOUT % 1000) * 1000;
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

  // Resolve the hostname.
  host = gethostbyname(hostname);
  if (host == NULL) {
    herror("gethostbyname");
    return -1;
  }

  // Set up the sockaddr_in structure.
  addr.sin_family = AF_INET;
  memcpy(&addr.sin_addr, host->h_addr_list[0], host->h_length);
  addr.sin_port = htons(PING_PORT);

  // Send the ping packet.
  packet.timestamp = time(NULL);
  packet.seq_num = 0;
  memset(packet.data, 0, sizeof(packet.data));
  n = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr));
  if (n < 0) {
    perror("sendto");
    return -1;
  }

  // Start the timer.
  start_time = time(NULL);

  // Wait for the response.
  FD_ZERO(&read_fds);
  FD_SET(sockfd, &read_fds);
  n = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);
  if (n < 0) {
    perror("select");
    return -1;
  }

  // Stop the timer.
  end_time = time(NULL);

  // Check if the response was received.
  if (FD_ISSET(sockfd, &read_fds)) {
    // Receive the response.
    n = recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr));
    if (n < 0) {
      perror("recvfrom");
      return -1;
    }

    // Calculate the round-trip time.
    double rtt = difftime(end_time, start_time) * 1000.0 + (difftime(end_time, start_time) - difftime(end_time, start_time)) * 1000.0;

    // Print the response.
    printf("Response from %s: seq=%d, rtt=%.3f ms\n", hostname, packet.seq_num, rtt);

    return 0;
  } else {
    // The response was not received.
    printf("No response from %s\n", hostname);

    return -1;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    return -1;
  }

  return ping(argv[1]);
}