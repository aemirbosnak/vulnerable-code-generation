//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pcap.h>

#define MAX_BYTES 2048

int main(int argc, char *argv[]) {
  char *device;
  pcap_t *handle;
  char errbuf[PCAP_ERRBUF_SIZE];
  struct pcap_pkthdr *header;
  const u_char *packet;

  if (argc != 2) {
    printf("Usage: %s <interface>\n", argv[0]);
    return EXIT_FAILURE;
  }

  device = argv[1];

  handle = pcap_open_live(device, MAX_BYTES, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
    return EXIT_FAILURE;
  }

  while (1) {
    int res = pcap_next_ex(handle, &header, &packet);
    if (res == 0) continue;
    if (res == -1) {
      fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
      break;
    }

    printf("Packet captured at %s\n", ctime((const time_t *) &header->ts.tv_sec));
    printf("Packet length: %d bytes\n", header->len);

    printf("Packet data:\n");
    for (int i = 0; i < header->len; i++) {
      printf("%02x ", packet[i]);
      if (i % 16 == 15) printf("\n");
    }

    printf("\n\n");
  }

  pcap_close(handle);
  return EXIT_SUCCESS;
}