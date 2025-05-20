//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>

// Our trusty firewall!
int main() {
  // Create a raw socket to sniff packets.
  int raw_sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
  if (raw_sock < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set up the socket options.
  int optval = 1;
  if (setsockopt(raw_sock, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(optval)) < 0) {
    perror("setsockopt");
    return EXIT_FAILURE;
  }

  // Grab packets forever!
  while (1) {
    // Receive a packet.
    struct sockaddr_in src_addr, dst_addr;
    socklen_t src_addr_len = sizeof(src_addr), dst_addr_len = sizeof(dst_addr);
    char packet[4096];
    int nbytes = recvfrom(raw_sock, packet, sizeof(packet), 0, (struct sockaddr*)&src_addr, &src_addr_len);
    if (nbytes < 0) {
      perror("recvfrom");
      return EXIT_FAILURE;
    }

    // Parse the IP header.
    struct iphdr *ip_hdr = (struct iphdr*)packet;
    if (ip_hdr->protocol != IPPROTO_TCP) {
      // Not a TCP packet, ignore it.
      continue;
    }

    // Parse the TCP header.
    struct tcphdr *tcp_hdr = (struct tcphdr*)(packet + sizeof(struct iphdr));

    // Check if the packet is from a blocked IP address.
    char blocked_ips[][16] = { "192.168.1.1", "192.168.1.2" };
    int i;
    for (i = 0; i < sizeof(blocked_ips) / sizeof(blocked_ips[0]); i++) {
      if (strcmp(inet_ntoa(src_addr.sin_addr), blocked_ips[i]) == 0) {
        // The packet is from a blocked IP address, drop it.
        printf("Dropping packet from blocked IP address %s\n", inet_ntoa(src_addr.sin_addr));
        continue;
      }
    }

    // Allow the packet through.
    printf("Allowing packet from %s:%d to %s:%d\n", 
           inet_ntoa(src_addr.sin_addr), ntohs(tcp_hdr->source), 
           inet_ntoa(dst_addr.sin_addr), ntohs(tcp_hdr->dest));
  }

  // Clean up.
  close(raw_sock);
  return EXIT_SUCCESS;
}