//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ada Lovelace
// Ada Lovelace style C Packet Capturer with pcap library
// Demonstrate capturing and printing packets on a given network interface

#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>

// Function to capture packets
void capturePackets(char *interface) {
  // Open the network interface for packet capture
  pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, NULL);
  if (handle == NULL) {
    perror("pcap_open_live() failed");
    exit(1);
  }

  // Define the packet filter expression
  struct bpf_program filter;
  if (pcap_compile(handle, &filter, "tcp", 1, 0) == -1) {
    perror("pcap_compile() failed");
    exit(1);
  }

  // Set the packet filter
  if (pcap_setfilter(handle, &filter) == -1) {
    perror("pcap_setfilter() failed");
    exit(1);
  }

  // Capture packets continuously
  while (1) {
    // Define the packet header and data
    struct pcap_pkthdr *header;
    const u_char *data;

    // Wait for a packet to arrive
    int res = pcap_next_ex(handle, &header, &data);
    if (res == -1) {
      perror("pcap_next_ex() failed");
      exit(1);
    }

    // Print packet information
    printf("Packet length: %d bytes\n", header->len);
    printf("Timestamp: %u.%06u\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)data));
    printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *)(data + 16)));
    printf("Source port: %d\n", ntohs(*(unsigned short *)(data + 20)));
    printf("Destination port: %d\n", ntohs(*(unsigned short *)(data + 22)));
    printf("Protocol: %d\n\n", *(data + 9));
  }

  // Close the network interface
  pcap_close(handle);
}

int main(int argc, char *argv[]) {
  // Check if the network interface is specified
  if (argc != 2) {
    printf("Usage: %s <network interface>\n", argv[0]);
    exit(1);
  }

  // Capture packets on the specified network interface
  capturePackets(argv[1]);

  return 0;
}