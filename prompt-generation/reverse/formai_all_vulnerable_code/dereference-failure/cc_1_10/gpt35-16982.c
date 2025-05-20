//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char pcap_errbuf[PCAP_ERRBUF_SIZE];
  struct bpf_program pcap_filter;
  bpf_u_int32 pcap_mask;
  bpf_u_int32 pcap_net;
  pcap_t *handle;

  // Open the pcap capture device
  handle = pcap_open_live("eth0", 65535, 1, 0, pcap_errbuf);
  if (handle == NULL) {
      printf("Could not open device eth0: %s\n", pcap_errbuf);
      exit(1);
  }

  // Determine the network number and mask
  if (pcap_lookupnet("eth0", &pcap_net, &pcap_mask, pcap_errbuf) == -1) {
    printf("Could not get netmask for eth0: %s\n", pcap_errbuf);
    pcap_net = 0;
    pcap_mask = 0xffffff;
  }

  // Compile and apply the pcap filter
  if (pcap_compile(handle, &pcap_filter, "tcp and port 80", 1, pcap_net) == -1) {
    printf("Could not compile pcap filter: %s\n", pcap_geterr(handle));
    pcap_close(handle);
    exit(1);
  }
  if (pcap_setfilter(handle, &pcap_filter) == -1) {
    printf("Could not apply pcap filter: %s\n", pcap_geterr(handle));
    pcap_close(handle);
    exit(1);
  }

  // Loop through captured packets
  struct pcap_pkthdr packet_header;
  const unsigned char *packet_data;
  while (1) {
    packet_data = pcap_next(handle, &packet_header);
    if (packet_data == NULL) continue;

    // Print packet details
    printf("Packet captured with length %u\n", packet_header.len);
    printf("Captured at: %s", ctime((const time_t *)&packet_header.ts.tv_sec));
    printf("Ethernet destination: %02x:%02x:%02x:%02x:%02x:%02x\n",
        packet_data[0], packet_data[1], packet_data[2],
        packet_data[3], packet_data[4], packet_data[5]);
    printf("Ethernet source: %02x:%02x:%02x:%02x:%02x:%02x\n",
        packet_data[6], packet_data[7], packet_data[8],
        packet_data[9], packet_data[10], packet_data[11]);
    printf("Ethernet type: %04x\n", ((uint16_t)(packet_data[12]) << 8) | packet_data[13]);
  }

  // Close the handle and exit
  pcap_close(handle);
  exit(0);
}