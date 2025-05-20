//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: enthusiastic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BYTES_PER_PACKET 2048

void print_packet_info(const u_char *packet, struct pcap_pkthdr *header) {
  printf("\nPacket capture length: %d\n", header->len);
  printf("Packet total length: %d\n", header->caplen);
  printf("Packet timestamp: %s\n", ctime((const time_t *)&header->ts.tv_sec));

  const u_char *payload = packet + 14; // Skip Ethernet header
  int payload_len = header->caplen - 14;
  if (payload_len > MAX_BYTES_PER_PACKET) {
    payload_len = MAX_BYTES_PER_PACKET;
  }

  printf("Payload (first %d bytes):\n", payload_len);
  for (int i = 0; i < payload_len; i++) {
    printf("%02x ", payload[i]);
  }
  printf("\n\n");
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <network interface>\n", argv[0]);
    return 1;
  }

  char *device = argv[1];
  char errbuf[PCAP_ERRBUF_SIZE];

  // Open the network interface for packet capture
  pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Error opening device: %s\n", errbuf);
    return 1;
  }

  // Start the packet capture loop
  while (1) {
    struct pcap_pkthdr *header;
    const u_char *packet;
    int res = pcap_next_ex(handle, &header, &packet);
    if (res == 0) {
      // No packets were captured
      continue;
    }
    if (res == -1) {
      // An error occurred
      fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
      break;
    }

    // Print the packet information
    print_packet_info(packet, header);
  }

  // Close the capture handle
  pcap_close(handle);

  return 0;
}