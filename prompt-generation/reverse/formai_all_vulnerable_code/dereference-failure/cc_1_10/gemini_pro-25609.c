//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 65535
#define MAX_ADDRESS_STR_LEN 16

typedef struct sockaddr_in SA_IN;

void dynamic_packet_monitoring(int sockfd) {
  // Dynamically allocate a buffer for the received packet
  uint8_t *packet_buffer = malloc(MAX_PACKET_SIZE);

  // Dynamically allocate a buffer for the source and destination IP addresses
  char src_addr_str[MAX_ADDRESS_STR_LEN], dst_addr_str[MAX_ADDRESS_STR_LEN];

  // Continuously receive and process packets
  while (1) {
    // Receive a packet
    int packet_len = recvfrom(sockfd, packet_buffer, MAX_PACKET_SIZE, 0, NULL, NULL);
    if (packet_len == -1) {
      perror("recvfrom");
      break;
    }

    // Extract the source and destination IP addresses from the packet
    SA_IN *src_addr = (SA_IN *) &packet_buffer[12];
    SA_IN *dst_addr = (SA_IN *) &packet_buffer[16];
    inet_ntop(AF_INET, &src_addr->sin_addr, src_addr_str, MAX_ADDRESS_STR_LEN);
    inet_ntop(AF_INET, &dst_addr->sin_addr, dst_addr_str, MAX_ADDRESS_STR_LEN);

    // Dynamically print the packet information
    char *packet_info = malloc(512);
    snprintf(packet_info, 512, "Packet received from %s:%d to %s:%d, length %d bytes\n",
      src_addr_str, ntohs(src_addr->sin_port),
      dst_addr_str, ntohs(dst_addr->sin_port),
      packet_len);
    printf("%s", packet_info);

    // Free the dynamically allocated memory
    free(packet_info);
  }

  // Free the dynamically allocated buffers
  free(packet_buffer);
}

int main() {
  // Create a raw socket to receive IP packets
  int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Start the dynamic packet monitoring
  dynamic_packet_monitoring(sockfd);

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}