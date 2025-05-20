//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

// Ethereal sniffing machine gun!
int main(int argc, char **argv) {
  char *device;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct pcap_pkthdr *header;
  const unsigned char *packet;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <device>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  device = argv[1];

  // Open the device for sniffing
  handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Error opening device %s: %s\n", device, errbuf);
    exit(EXIT_FAILURE);
  }

  // Loop forever, sniffing packets
  while (1) {
    // Grab the next packet
    int res = pcap_next_ex(handle, &header, &packet);
    if (res < 0) {
      fprintf(stderr, "Error while capturing packets: %s\n", pcap_geterr(handle));
      exit(EXIT_FAILURE);
    } else if (res == 0) {
      continue;
    }

    // Print out the packet header
    printf("Packet length: %d\n", header->len);
    printf("Number of bytes captured: %d\n", header->caplen);
    printf("Timestamp: %s\n", ctime((const time_t *)&header->ts.tv_sec));

    // Print out the first 16 bytes of the packet
    for (int i = 0; i < 16; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n");

    // Print out the rest of the packet
    for (int i = 16; i < header->caplen; i++) {
      if (i % 16 == 0) {
        printf("\n");
      }
      printf("%02x ", packet[i]);
    }
    printf("\n\n");
  }

  // Close the device
  pcap_close(handle);

  return EXIT_SUCCESS;
}