//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: futuristic
#include <stdio.h>
#include <pcap.h>

int main() {
  // Open a capture device
  char *device = "en0";
  pcap_t *handle = pcap_open_live(device, 65535, 1, 1000, NULL);
  if (handle == NULL) {
    perror("pcap_open_live");
    return -1;
  }

  // Set a filter to capture TCP packets
  struct bpf_program filter;
  if (pcap_compile(handle, &filter, "tcp", 1, 0) < 0) {
    perror("pcap_compile");
    return -1;
  }
  if (pcap_setfilter(handle, &filter) < 0) {
    perror("pcap_setfilter");
    return -1;
  }

  // Capture packets
  int packet_count = 0;
  while (1) {
    struct pcap_pkthdr *header;
    const u_char *packet;
    int res = pcap_next_ex(handle, &header, &packet);
    if (res < 0) {
      perror("pcap_next_ex");
      break;
    } else if (res == 0) {
      continue;
    }

    // Process the packet
    printf("Packet %d:\n", packet_count++);
    printf("  Timestamp: %ld.%06ld\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("  Length: %d\n", header->len);
    printf("  Data: ");
    for (int i = 0; i < header->len; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n");
  }

  // Close the capture device
  pcap_close(handle);

  return 0;
}