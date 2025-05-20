//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: imaginative
#include <pcap/pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The main function is the entry point of the program.
int main() {
  // Define the network interface to capture packets from.
  char *device = "wlan0";
  // Define the filter expression to capture only TCP packets.
  char *filter = "tcp";
  // Define the number of packets to capture.
  int num_packets = 10;

  // Open the network interface for packet capture.
  pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
  if (handle == NULL) {
    fprintf(stderr, "Unable to open the network interface for packet capture.\n");
    return -1;
  }

  // Compile the filter expression.
  struct bpf_program fp;
  if (pcap_compile(handle, &fp, filter, 0, PCAP_NETMASK_UNKNOWN) == -1) {
    fprintf(stderr, "Unable to compile the filter expression.\n");
    return -1;
  }

  // Set the filter on the network interface.
  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Unable to set the filter on the network interface.\n");
    return -1;
  }

  // Create a packet buffer to store the captured packets.
  u_char *buffer = (u_char *)malloc(BUFSIZ);
  if (buffer == NULL) {
    fprintf(stderr, "Unable to allocate memory for the packet buffer.\n");
    return -1;
  }

  // Capture packets until the specified number of packets is reached.
  int count = 0;
  while (count < num_packets) {
    // Wait for a packet to arrive.
    struct pcap_pkthdr *header;
    const u_char *data;
    int res = pcap_next_ex(handle, &header, &data);
    if (res == -1) {
      fprintf(stderr, "Unable to capture a packet.\n");
      return -1;
    } else if (res == 0) {
      continue;
    }

    // Print the packet header.
    printf("Packet number: %d\n", count + 1);
    printf("Packet length: %d bytes\n", header->len);
    printf("Capture time: %s\n", ctime((const time_t *)&header->ts.tv_sec));

    // Print the packet data.
    for (int i = 0; i < header->len; i++) {
      printf("%02x ", data[i]);
      if ((i + 1) % 16 == 0) {
        printf("\n");
      }
    }

    printf("\n");

    count++;
  }

  // Free the packet buffer.
  free(buffer);

  // Close the network interface.
  pcap_close(handle);

  return 0;
}