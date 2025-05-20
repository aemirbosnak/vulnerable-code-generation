//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

// Define the maximum number of packets to send and receive
#define MAX_PACKET_COUNT 100

// Define the packet size in bytes
#define PACKET_SIZE 1024

// Define the QoS parameters
#define TOS_LOW_DELAY 0x10
#define TOS_HIGH_THROUGHPUT 0x80

// Create a raw socket
int create_raw_socket() {
  int sockfd;

  // Create a raw socket
  sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set the IP header inclusion option
  int on = 1;
  if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) == -1) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Set the QoS parameters
  int tos = TOS_LOW_DELAY | TOS_HIGH_THROUGHPUT;
  if (setsockopt(sockfd, IPPROTO_IP, IP_TOS, &tos, sizeof(tos)) == -1) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  return sockfd;
}

// Send a packet
void send_packet(int sockfd, struct sockaddr_in *addr, char *buf, int len) {
  // Send the packet
  if (sendto(sockfd, buf, len, 0, (struct sockaddr *)addr, sizeof(*addr)) == -1) {
    perror("sendto");
    exit(EXIT_FAILURE);
  }
}

// Receive a packet
void receive_packet(int sockfd, struct sockaddr_in *addr, char *buf, int len) {
  // Receive the packet
  if (recvfrom(sockfd, buf, len, 0, (struct sockaddr *)addr, sizeof(*addr)) == -1) {
    perror("recvfrom");
    exit(EXIT_FAILURE);
  }
}

// Main function
int main(int argc, char **argv) {
  // Check the arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the IP address and port
  char *ip_addr = argv[1];
  int port = atoi(argv[2]);

  // Create a raw socket
  int sockfd = create_raw_socket();

  // Create the destination address
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip_addr);
  addr.sin_port = htons(port);

  // Create the buffer
  char buf[PACKET_SIZE];
  memset(buf, 0, PACKET_SIZE);

  // Send the packets
  for (int i = 0; i < MAX_PACKET_COUNT; i++) {
    // Send the packet
    send_packet(sockfd, &addr, buf, PACKET_SIZE);

    // Receive the packet
    receive_packet(sockfd, &addr, buf, PACKET_SIZE);
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}