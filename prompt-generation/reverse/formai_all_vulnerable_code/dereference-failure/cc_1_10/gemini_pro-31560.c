//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>

int main() {
  char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct pcap_pkthdr *header;
  const u_char *packet;

  // Select the network interface to monitor
  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    fprintf(stderr, "pcap_lookupdev(): %s\n", errbuf);
    exit(EXIT_FAILURE);
  }

  // Open the network interface for packet capture
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
    exit(EXIT_FAILURE);
  }

  // Capture packets and print their information
  while (1) {
    int res = pcap_next_ex(handle, &header, &packet);

    if (res == -1) {
      fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
      exit(EXIT_FAILURE);
    } else if (res == 0) {
      continue;
    }

    // Get the source and destination IP addresses
    struct in_addr src_addr, dst_addr;
    memcpy(&src_addr, packet + 26, sizeof(src_addr));
    memcpy(&dst_addr, packet + 30, sizeof(dst_addr));

    // Get the source and destination ports
    u_int16_t src_port = ntohs(*(u_int16_t *)(packet + 34));
    u_int16_t dst_port = ntohs(*(u_int16_t *)(packet + 36));

    // Print the packet information
    printf("Packet captured from interface %s\n", dev);
    printf("Source IP: %s\n", inet_ntoa(src_addr));
    printf("Destination IP: %s\n", inet_ntoa(dst_addr));
    printf("Source port: %d\n", src_port);
    printf("Destination port: %d\n", dst_port);
    printf("Payload: ");

    // Print the payload data
    for (int i = 42; i < header->caplen; i++) {
      printf("%02x ", packet[i]);
    }

    printf("\n\n");
  }

  // Close the network interface
  pcap_close(handle);

  return EXIT_SUCCESS;
}