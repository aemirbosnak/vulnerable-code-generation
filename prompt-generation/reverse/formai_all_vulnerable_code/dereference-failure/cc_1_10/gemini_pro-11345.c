//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: introspective
// Network packet capture using libpcap

#include <pcap.h>
#include <stdio.h>

int main() {
  // Open a network interface for packet capture
  char *device = pcap_lookupdev(NULL);
  if (!device) {
    perror("pcap_lookupdev");
    return -1;
  }

  pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
  if (!handle) {
    perror("pcap_open_live");
    return -1;
  }

  // Define a packet capture filter
  struct bpf_program filter;
  if (pcap_compile(handle, &filter, "tcp", 1, 0)) {
    perror("pcap_compile");
    return -1;
  }
  if (pcap_setfilter(handle, &filter)) {
    perror("pcap_setfilter");
    return -1;
  }

  // Loop through captured packets
  struct pcap_pkthdr *header;
  const u_char *data;
  while (1) {
    int res = pcap_next_ex(handle, &header, &data);
    if (res == -1) {
      perror("pcap_next_ex");
      return -1;
    } else if (res == 0) {
      printf("No packets captured.\n");
      break;
    }

    // Process the captured packet
    printf("Packet length: %d\n", header->len);
    printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *) &data[30]));
    printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *) &data[34]));

    // Check if we have a TCP packet
    if (data[23] == 0x06) {
      printf("TCP packet\n");
      printf("Source port: %d\n", data[38]);
      printf("Destination port: %d\n", data[40]);
    }

    // Print the packet data
    printf("Packet data:\n");
    for (int i = 0; i < header->len; i++) {
      printf("%02x ", data[i]);
    }
    printf("\n");
  }

  // Close the network interface
  pcap_close(handle);

  return 0;
}