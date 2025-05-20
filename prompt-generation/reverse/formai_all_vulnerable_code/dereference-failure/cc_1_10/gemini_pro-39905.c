//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define MAX_BYTES_TO_CAPTURE 2048

int main() {
  // Open the network interface for packet capture
  char *device = pcap_lookupdev(NULL);
  if (device == NULL) {
    fprintf(stderr, "Error: Could not find a suitable network device.\n");
    return EXIT_FAILURE;
  }

  pcap_t *handle = pcap_open_live(device, MAX_BYTES_TO_CAPTURE, 1, 1000, NULL);
  if (handle == NULL) {
    fprintf(stderr, "Error: Could not open the network device for packet capture.\n");
    return EXIT_FAILURE;
  }

  // Start the packet capture loop
  while (1) {
    // Wait for a packet to arrive on the network interface
    struct pcap_pkthdr *header;
    const u_char *data;
    int result = pcap_next_ex(handle, &header, &data);

    // Check if a packet was captured successfully
    if (result == 1) {
      // Print the packet header information
      printf("Packet length: %d\n", header->len);
      printf("Timestamp: %s\n", ctime((const time_t *)&header->ts.tv_sec));

      // Print the packet data
      for (int i = 0; i < header->caplen; i++) {
        printf("%02X ", data[i]);
      }
      printf("\n");
    } else if (result == 0) {
      // No packet was captured within the timeout period
      fprintf(stderr, "Error: No packet was captured within the timeout period.\n");
    } else if (result == -1) {
      // An error occurred during packet capture
      fprintf(stderr, "Error: An error occurred during packet capture.\n");
    } else if (result == -2) {
      // The packet capture loop was broken out of
      break;
    }
  }

  // Close the network interface and free any allocated resources
  pcap_close(handle);

  return EXIT_SUCCESS;
}