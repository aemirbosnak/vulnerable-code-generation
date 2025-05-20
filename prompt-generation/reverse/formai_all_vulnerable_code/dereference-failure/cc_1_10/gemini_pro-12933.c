//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: satisfied
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *dev = pcap_lookupdev(NULL);
  if (!dev) {
    fprintf(stderr, "Couldn't find default device: %s\n", pcap_geterr(NULL));
    return EXIT_FAILURE;
  }

  pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, NULL);
  if (!handle) {
    fprintf(stderr, "Couldn't open device: %s\n", pcap_geterr(handle));
    pcap_freealldevs(dev);
    return EXIT_FAILURE;
  }

  struct pcap_pkthdr *header;
  const u_char *data;
  int res;
  while ((res = pcap_next_ex(handle, &header, &data)) >= 0) {
    if (res == 0) {
      continue;
    }

    // Parse packet header
    printf("Packet length: %d\n", header->len);
    printf("Capture time: %s\n", ctime((const time_t *)&header->ts.tv_sec));

    // Parse packet data
    printf("Src MAC: ");
    for (int i = 0; i < 6; i++) {
      printf("%02x:", data[i]);
    }
    printf("\n");

    printf("Dst MAC: ");
    for (int i = 6; i < 12; i++) {
      printf("%02x:", data[i]);
    }
    printf("\n");

    printf("Protocol: %d\n", header->len);

    // Print packet data as hex
    printf("Data: ");
    for (int i = 12; i < header->len; i++) {
      printf("%02x ", data[i]);
    }
    printf("\n\n");
  }

  if (res == -1) {
    fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
  }

  pcap_close(handle);
  pcap_freealldevs(dev);
  return EXIT_SUCCESS;
}