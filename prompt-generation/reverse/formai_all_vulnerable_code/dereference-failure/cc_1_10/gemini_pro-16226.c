//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main() {
  char *device;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct pcap_pkthdr *header;
  const u_char *data;
  int i;

  // Find a suitable device
  device = pcap_lookupdev(errbuf);
  if (device == NULL) {
    fprintf(stderr, "Error finding a suitable device: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  // Open the device
  handle = pcap_open_live(device, 65535, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Error opening the device: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  // Start capturing packets
  while (1) {
    // Grab a packet
    int res = pcap_next_ex(handle, &header, &data);

    // Check for errors
    if (res == -1) {
      fprintf(stderr, "Error capturing a packet: %s\n", pcap_geterr(handle));
      return EXIT_FAILURE;
    }

    if (res == 0) {
      // No packets were captured
      continue;
    }

    // Print the packet header
    printf("Packet header:\n");
    printf("Timestamp: %ld.%ld\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("Captured length: %d\n", header->caplen);
    printf("Actual length: %d\n", header->len);

    // Print the packet data
    printf("Packet data:\n");
    for (i = 0; i < header->caplen; i++) {
      printf("%02x ", data[i]);
    }
    printf("\n\n");
  }

  // Close the device
  pcap_close(handle);

  return EXIT_SUCCESS;
}