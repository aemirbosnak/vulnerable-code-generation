//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: Alan Turing
// Embark on an enigmatic journey into the digital realm with this Network Packet Monitoring program!

#include <stdio.h>
#include <pcap.h>

int main() {
  // Declare a pcap structure to capture network packets
  pcap_t *handle;

  // Specify the network interface to monitor, e.g. "eth0" or "en0"
  char *device = "eth0";

  // Set the capture filter to capture all packets
  char *filter = "tcp";

  // Open the network device for packet capture
  handle = pcap_open_live(device, 65535, 1, 1000, NULL);
  if (handle == NULL) {
    perror("pcap_open_live() failed");
    return -1;
  }

  // Compile the capture filter
  struct bpf_program fp;
  if (pcap_compile(handle, &fp, filter, 1, 0) == -1) {
    perror("pcap_compile() failed");
    return -1;
  }

  // Set the capture filter
  if (pcap_setfilter(handle, &fp) == -1) {
    perror("pcap_setfilter() failed");
    return -1;
  }

  // Initialize the packet counter
  int count = 0;

  // Start the packet capture loop
  while (1) {
    // Get the next packet
    struct pcap_pkthdr *header;
    const u_char *data;
    int res = pcap_next_ex(handle, &header, &data);
    if (res == -1) {
      perror("pcap_next_ex() failed");
      break;
    }
    if (res == 0) {
      continue;
    }

    // Increment the packet counter
    count++;

    // Print the packet timestamp
    printf("Packet %d captured at %s\n", count, asctime(localtime(&header->ts.tv_sec)));

    // Print the packet length
    printf("Packet length: %d bytes\n", header->len);

    // Print the packet data
    printf("Packet data:\n");
    for (int i = 0; i < header->len; i++) {
      printf("%02x ", data[i]);
    }
    printf("\n");
  }

  // Close the network device
  pcap_close(handle);

  return 0;
}