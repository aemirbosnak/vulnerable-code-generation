//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  char *device = NULL;              // Our network interface
  char errbuf[PCAP_ERRBUF_SIZE];     // Error buffer for pcap_open_live
  pcap_t *handle = NULL;            // Our packet capture handle
  struct bpf_program fp;            // The compiled filter
  char filter_exp[] = "type mgt subtype probe-req"; // Our capture filter expression
  bpf_u_int32 mask;                   // Our network mask
  bpf_u_int32 net;                   // Our network address
  struct pcap_pkthdr *header;       // Our packet header
  const u_char *packet;              // Our packet data

  printf("Wireless Network Scanner\n");

  if (argc < 2) {
    printf("Usage: %s <interface>\n", argv[0]);
    return 1;
  }

  device = argv[1];

  if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
    printf("Couldn't get netmask for %s: %s\n", device, errbuf);
    return 1;
  }

  handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
  if (!handle) {
    printf("Couldn't open device %s: %s\n", device, errbuf);
    return 1;
  }

  if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
    printf("Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return 1;
  }

  if (pcap_setfilter(handle, &fp) == -1) {
    printf("Couldn't set filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return 1;
  }

  printf("Scanning for wireless networks on %s...\n", device);

  while (1) {
    packet = pcap_next(handle, &header);
    if (!packet) continue;

    printf("Found a wireless network!\n");
    printf("  SSID: %s\n", packet + 36);
    printf("  BSSID: %02x:%02x:%02x:%02x:%02x:%02x\n", packet[16], packet[17], packet[18], packet[19], packet[20], packet[21]);
  }

  pcap_close(handle);

  return 0;
}