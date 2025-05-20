//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: introspective
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void print_packet_info(const u_char *packet, struct pcap_pkthdr *header) {
  struct in_addr src_addr, dst_addr;
  u_short src_port, dst_port;

  // Extract source and destination IP and port numbers
  memcpy(&src_addr, packet + 12, sizeof(src_addr));
  memcpy(&dst_addr, packet + 16, sizeof(dst_addr));
  memcpy(&src_port, packet + 20, sizeof(src_port));
  memcpy(&dst_port, packet + 22, sizeof(dst_port));

  // Convert port numbers to host byte order
  src_port = ntohs(src_port);
  dst_port = ntohs(dst_port);

  // Print packet information
  printf("Packet length: %d bytes\n", header->len);
  printf("Timestamp: %s", ctime((const time_t *) &header->ts.tv_sec));
  printf("Source IP: %s\n", inet_ntoa(src_addr));
  printf("Source port: %d\n", src_port);
  printf("Destination IP: %s\n", inet_ntoa(dst_addr));
  printf("Destination port: %d\n\n", dst_port);
}

int main() {
  // Open the network interface for packet capture
  char *device = pcap_lookupdev(NULL);
  if (!device) {
    fprintf(stderr, "Error: No suitable network device found\n");
    return EXIT_FAILURE;
  }

  // Create a packet capture handle
  pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
  if (!handle) {
    fprintf(stderr, "Error: Unable to open network device %s\n", device);
    return EXIT_FAILURE;
  }

  // Listen for and capture packets
  while (1) {
    struct pcap_pkthdr *header;
    const u_char *packet;
    int res = pcap_next_ex(handle, &header, &packet);

    if (res == 1) {
      // Print packet information
      print_packet_info(packet, header);
    } else if (res < 0) {
      fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
      break;
    }
  }

  // Close the packet capture handle
  pcap_close(handle);

  return EXIT_SUCCESS;
}