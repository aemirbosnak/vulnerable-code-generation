//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65535

int main(int argc, char *argv[]) {
  char *interface = argv[1];
  char *filter = "tcp";
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;

  // Open the network interface
  handle = pcap_open_live(interface, MAX_PACKET_SIZE, 0, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Error opening interface: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  // Compile the filter
  struct bpf_program fp;
  if (pcap_compile(handle, &fp, filter, 0, 0) == -1) {
    fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  // Set the filter
  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  // Loop over the packets
  int packet_count = 0;
  while (1) {
    struct pcap_pkthdr *header;
    const u_char *packet;

    // Get the next packet
    int res = pcap_next_ex(handle, &header, &packet);
    if (res == -1) {
      fprintf(stderr, "Error getting packet: %s\n", pcap_geterr(handle));
      return EXIT_FAILURE;
    }

    // Print the packet information
    printf("Packet %d\n", packet_count++);
    printf("Timestamp: %s\n", ctime(&header->ts.tv_sec));
    printf("Length: %d bytes\n", header->len);

    // Print the packet data
    for (int i = 0; i < header->len; i++) {
      printf("%02X ", packet[i]);
    }
    printf("\n\n");
  }

  // Close the interface
  pcap_close(handle);

  return EXIT_SUCCESS;
}