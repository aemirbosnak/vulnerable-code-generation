//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: active
#include <pcap/pcap.h>
#include <stdio.h>

int main() {
  char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct pcap_pkthdr *header;
  const u_char *packet;

  // Find a network device to capture packets from
  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    fprintf(stderr, "Error finding a network device: %s\n", errbuf);
    return 1;
  }

  // Open the device for capturing packets
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Error opening the network device: %s\n", errbuf);
    return 1;
  }

  // Loop forever, capturing packets
  while (1) {
    // Wait for a packet to arrive
    int res = pcap_next_ex(handle, &header, &packet);
    if (res == 0) {
      continue;
    } else if (res == -1) {
      fprintf(stderr, "Error reading the packet: %s\n", pcap_geterr(handle));
      return 1;
    }

    // Print the packet header
    printf("Packet length: %d\n", header->len);
    printf("Packet received at: %s\n", ctime((const time_t *)&header->ts.tv_sec));

    // Print the packet data
    int i;
    printf("Packet data: ");
    for (i = 0; i < header->len; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n");
  }

  // Close the device when finished
  pcap_close(handle);

  return 0;
}