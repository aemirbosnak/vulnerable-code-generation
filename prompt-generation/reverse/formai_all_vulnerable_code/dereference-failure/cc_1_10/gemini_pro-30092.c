//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: innovative
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *device;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct pcap_pkthdr *header;
  const u_char *packet;

  // Find the first network device
  device = pcap_lookupdev(errbuf);
  if (device == NULL) {
    fprintf(stderr, "pcap_lookupdev: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  // Open the network device for packet capture
  handle = pcap_open_live(device, BUFSIZ, 0, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "pcap_open_live: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  // Loop forever, capturing packets
  while (1) {
    // Wait for a packet to arrive
    int res = pcap_next_ex(handle, &header, &packet);
    if (res == 0) continue;
    if (res == -1) {
      fprintf(stderr, "pcap_next_ex: %s\n", pcap_geterr(handle));
      break;
    }

    // Print the packet header
    printf("Packet length: %d\n", header->len);
    printf("Timestamp: %s\n\n", ctime((const time_t *)&header->ts.tv_sec));

    // Print the packet data
    int i;
    for (i = 0; i < header->len; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n\n");
  }

  // Close the network device
  pcap_close(handle);

  return EXIT_SUCCESS;
}