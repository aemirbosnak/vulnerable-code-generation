//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scientific
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  // Open the network device for packet capture
  char *device = "en0";
  pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
  if (handle == NULL) {
    fprintf(stderr, "Error opening device %s: %s\n", device, pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  // Compile the filter expression
  struct bpf_program fp;
  if (pcap_compile(handle, &fp, "tcp and port 80", 0, PCAP_NETMASK_UNKNOWN) == -1) {
    fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  // Set the filter on the capture device
  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  // Start the packet capture loop
  int count = 0;
  while (1) {
    // Wait for a packet to arrive
    struct pcap_pkthdr *header;
    const u_char *data;
    int res = pcap_next_ex(handle, &header, &data);
    if (res == -1) {
      fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
      return EXIT_FAILURE;
    } else if (res == 0) {
      // No packets were captured
      continue;
    }

    // Process the packet
    printf("Packet %d: %d bytes\n", count++, header->len);
    for (int i = 0; i < header->len; i++) {
      printf("%02x ", data[i]);
    }
    printf("\n");
  }

  // Close the capture device
  pcap_close(handle);

  return EXIT_SUCCESS;
}