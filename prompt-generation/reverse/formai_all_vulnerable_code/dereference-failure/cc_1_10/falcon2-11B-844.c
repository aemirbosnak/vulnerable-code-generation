//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  // Check if the user provided the host to ping as a command-line argument
  if (argc!= 2) {
    printf("Usage: %s <host>\n", argv[0]);
    return 1;
  }

  // Convert the hostname to an IP address using gethostbyname()
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    printf("Error: Host not found\n");
    return 1;
  }

  // Create a UDP socket
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    return 1;
  }

  // Set the socket timeout
  int timeout = 3;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
    perror("Error setting socket timeout");
    return 1;
  }

  // Send ICMP echo request packet
  struct sockaddr_in dest;
  bzero((char *)&dest, sizeof(dest));
  dest.sin_family = AF_INET;
  dest.sin_port = htons(1);
  dest.sin_addr.s_addr = *(long *)host->h_addr;
  int sent = sendto(sockfd, "ping\0", 4, 0, (const struct sockaddr *)&dest, sizeof(dest));
  if (sent < 0) {
    perror("Error sending ping packet");
    return 1;
  }

  // Receive ICMP echo reply packet
  struct sockaddr_in source;
  socklen_t source_len = sizeof(source);
  char buffer[INET_ADDRSTRLEN];
  bzero(buffer, INET_ADDRSTRLEN);
  while (1) {
    int recv = recvfrom(sockfd, buffer, INET_ADDRSTRLEN, 0, (struct sockaddr *)&source, &source_len);
    if (recv <= 0) {
      perror("Error receiving ping reply");
      return 1;
    }
    if (strcmp(buffer, "pong\0") == 0) {
      printf("Ping successful!\n");
      return 0;
    }
  }
}