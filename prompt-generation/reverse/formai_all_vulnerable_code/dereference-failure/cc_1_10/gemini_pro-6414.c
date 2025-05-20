//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

// Maximum number of hops to trace
#define MAX_HOPS 30

// Maximum size of the message to send
#define MAX_MSG_SIZE 1024

// The port number to use
#define PORT 33434

// The traceroute() function
int traceroute(char *hostname) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Set the socket timeout
  struct timeval timeout;
  timeout.tv_sec = 1;
  timeout.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
    perror("setsockopt");
    return -1;
  }

  // Get the destination IP address
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname");
    return -1;
  }
  struct sockaddr_in dest_addr;
  dest_addr.sin_family = AF_INET;
  dest_addr.sin_port = htons(PORT);
  dest_addr.sin_addr = *(struct in_addr *)*host->h_addr_list;

  // Send the first probe
  char msg[MAX_MSG_SIZE];
  memset(msg, 0, MAX_MSG_SIZE);
  msg[0] = 1;
  if (sendto(sockfd, msg, 1, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
    perror("sendto");
    return -1;
  }

  // Receive the response
  char recv_buf[MAX_MSG_SIZE];
  struct sockaddr_in recv_addr;
  socklen_t recv_addr_len = sizeof(recv_addr);
  int recv_len = recvfrom(sockfd, recv_buf, MAX_MSG_SIZE, 0, (struct sockaddr *)&recv_addr, &recv_addr_len);
  if (recv_len < 0) {
    perror("recvfrom");
    return -1;
  }

  // Print the hop information
  int hop = 1;
  while (recv_len > 0) {
    // Get the timestamp
    struct timeval timestamp;
    memcpy(&timestamp, recv_buf, sizeof(timestamp));

    // Get the IP address
    char ip_addr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &recv_addr.sin_addr, ip_addr, INET_ADDRSTRLEN);

    // Print the hop information
    printf("Hop %d: %s (%d ms)\n", hop, ip_addr, (int)(timestamp.tv_sec * 1000 + timestamp.tv_usec / 1000));

    // Increment the hop count
    hop++;

    // Send the next probe
    msg[0]++;
    if (sendto(sockfd, msg, 1, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
      perror("sendto");
      return -1;
    }

    // Receive the response
    recv_len = recvfrom(sockfd, recv_buf, MAX_MSG_SIZE, 0, (struct sockaddr *)&recv_addr, &recv_addr_len);
    if (recv_len < 0) {
      perror("recvfrom");
      return -1;
    }
  }

  // Close the socket
  close(sockfd);

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
    return -1;
  }

  return traceroute(argv[1]);
}