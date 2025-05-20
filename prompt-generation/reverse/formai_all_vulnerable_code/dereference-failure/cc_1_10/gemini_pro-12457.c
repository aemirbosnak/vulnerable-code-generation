//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: surprised
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  char *device = NULL;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  const u_char *packet;
  struct pcap_pkthdr header;
  char *payload;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <device>\n", argv[0]);
    exit(1);
  }

  device = argv[1];

  handle = pcap_open_live(device, 65535, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "pcap_open_live: %s\n", errbuf);
    exit(1);
  }

  while (1) {
    packet = pcap_next(handle, &header);
    if (packet == NULL) {
      continue;
    }

    payload = (char *)packet + 14;

    printf("Packet length: %d\n", header.len);
    printf("Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", payload[0], payload[1], payload[2], payload[3], payload[4], payload[5]);
    printf("Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", payload[6], payload[7], payload[8], payload[9], payload[10], payload[11]);
    printf("Protocol: %d\n", payload[12]);
    printf("Payload:\n");
    for (int i = 0; i < header.len - 14; i++) {
      if (i % 16 == 0) {
        printf("\n");
      }
      printf("%02x ", payload[i]);
    }
    printf("\n\n");
  }

  pcap_close(handle);
  return 0;
}