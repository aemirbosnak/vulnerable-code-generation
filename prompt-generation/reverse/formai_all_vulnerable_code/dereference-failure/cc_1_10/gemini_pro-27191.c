//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: shape shifting
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

#define SNAP_LEN 1518

int main() {
  char *dev = NULL;                        // Device to sniff on
  char errbuf[PCAP_ERRBUF_SIZE];          // Error buffer
  pcap_t *handle;                          // Packet capture handle
  const u_char *packet;                     // Pointer to packet data
  struct pcap_pkthdr header;                // Packet header
  int res;                                  // Result of pcap_next()

  // Find a suitable device to sniff on
  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    printf("pcap_lookupdev() failed: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  // Open the device for sniffing
  handle = pcap_open_live(dev, SNAP_LEN, 1, 100, errbuf);
  if (handle == NULL) {
    printf("pcap_open_live() failed: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  // Print the device name
  printf("Sniffing on device %s\n", dev);

  // Loop forever and capture packets
  while (1) {
    // Get the next packet
    res = pcap_next_ex(handle, &header, &packet);
    if (res == -1) {
      printf("pcap_next_ex() failed: %s\n", pcap_geterr(handle));
      return EXIT_FAILURE;
    } else if (res == -2) {
      // Timeout
      continue;
    }

    // Print the packet header
    printf("Packet length: %d\n", header.len);
    printf("Packet capture timestamp: %s\n", ctime((const time_t *)&header.ts.tv_sec));

    // Print the packet data
    for (int i = 0; i < header.len; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n");
  }

  // Close the device
  pcap_close(handle);

  return EXIT_SUCCESS;
}