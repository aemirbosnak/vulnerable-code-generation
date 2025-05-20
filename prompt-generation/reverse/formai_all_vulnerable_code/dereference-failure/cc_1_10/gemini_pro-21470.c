//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main() {
  pcap_t *handle;
  char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  struct pcap_pkthdr *header;
  const u_char *packet;

  /* Find a device */
  dev = pcap_lookupdev(errbuf);
  if (!dev) {
    fprintf(stderr, "Error finding device: %s\n", errbuf);
    return 1;
  }

  /* Open the device */
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (!handle) {
    fprintf(stderr, "Error opening device: %s\n", errbuf);
    return 1;
  }

  /* Loop forever and capture packets */
  while (1) {
    /* Wait for a packet */
    int res = pcap_next_ex(handle, &header, &packet);
    if (res == -1) {
      fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
      return 1;
    } else if (res == 0) {
      /* Timeout elapsed */
      continue;
    }

    /* Print the packet header */
    printf("Timestamp: %u\n", header->ts.tv_sec);
    printf("Length: %u\n", header->len);

    /* Print the packet data */
    for (int i = 0; i < header->len; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n\n");
  }

  /* Close the device */
  pcap_close(handle);

  return 0;
}