//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: relaxed
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <interface>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *device = argv[1];
  char errbuf[PCAP_ERRBUF_SIZE];

  // Open the device
  pcap_t *handle = pcap_open_live(device, 65535, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Error opening device: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  // Compile the filter
  struct bpf_program filter;
  if (pcap_compile(handle, &filter, "tcp port 80", 1, 0) == -1) {
    fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  // Set the filter
  if (pcap_setfilter(handle, &filter) == -1) {
    fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  // Capture the packets
  while (1) {
    struct pcap_pkthdr *header;
    const unsigned char *data;
    int res = pcap_next_ex(handle, &header, &data);

    if (res == -1) {
      fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
      break;
    } else if (res == 0) {
      // Timeout
      continue;
    }

    // Print the packet information
    printf("Packet length: %d\n", header->len);
    printf("Timestamp: %d.%d\n", header->ts.tv_sec, header->ts.tv_usec);

    // Print the data
    for (int i = 0; i < header->len; i++) {
      printf("%02x ", data[i]);
      if ((i + 1) % 16 == 0) {
        printf("\n");
      }
    }

    printf("\n");
  }

  // Cleanup
  pcap_close(handle);
  pcap_freecode(&filter);

  return EXIT_SUCCESS;
}