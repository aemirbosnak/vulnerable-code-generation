//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: happy
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;

  printf("Let's capture some packets! 👻\n");

  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    fprintf(stderr, "Could not find a suitable device: %s\n", errbuf);
    return -1;
  }

  printf("Using device %s\n", dev);

  handle = pcap_open_live(dev, 65535, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Could not open the device: %s\n", errbuf);
    return -1;
  }

  while (1) {
    struct pcap_pkthdr *header;
    const u_char *packet;
    int res;

    res = pcap_next_ex(handle, &header, &packet);
    if (res == 0) {
      // No packet received
      continue;
    } else if (res == -1) {
      // Error
      fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
      break;
    }

    printf("Received packet!\n");
    printf("Packet length: %d\n", header->len);
    printf("Packet data:\n");
    for (int i = 0; i < header->len; i++) {
      printf("%02X ", packet[i]);
    }
    printf("\n\n");
  }

  pcap_close(handle);
  return 0;
}