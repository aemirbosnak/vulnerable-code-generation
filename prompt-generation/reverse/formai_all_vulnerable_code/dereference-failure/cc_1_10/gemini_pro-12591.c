//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: portable
#include <stdlib.h>
#include <stdio.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_BYTES_TO_CAPTURE 2048

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *device = argv[1];
  char errbuf[PCAP_ERRBUF_SIZE];

  // Open the network device for packet capture.
  pcap_t *handle = pcap_open_live(device, MAX_BYTES_TO_CAPTURE, 0, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
    exit(EXIT_FAILURE);
  }

  // Start a loop to capture packets.
  while (1) {
    // Wait for a packet to arrive.
    struct pcap_pkthdr *header;
    const u_char *packet;
    int res = pcap_next_ex(handle, &header, &packet);

    // If there was an error, print it and continue.
    if (res == -1) {
      fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
      continue;
    }

    // If there was no packet, continue.
    if (res == 0) {
      continue;
    }

    // Print the timestamp of the packet.
    struct tm *tm = gmtime(&header->ts.tv_sec);
    printf("%02d:%02d:%02d.%06ld ", tm->tm_hour, tm->tm_min, tm->tm_sec, header->ts.tv_usec);

    // Print the source and destination IP addresses.
    struct in_addr src_addr, dst_addr;
    memcpy(&src_addr, packet + 12, sizeof(struct in_addr));
    memcpy(&dst_addr, packet + 16, sizeof(struct in_addr));
    printf("%s -> %s\n", inet_ntoa(src_addr), inet_ntoa(dst_addr));

    // Print the first 16 bytes of the packet.
    for (int i = 0; i < 16; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n\n");
  }

  // Close the network device.
  pcap_close(handle);

  return EXIT_SUCCESS;
}