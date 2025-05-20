//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pcap.h>

int main(int argc, char *argv[]) {
  char *device;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct bpf_program fp;
  char filter_exp[] = "type mgt subtype probe-req";
  bpf_u_int32 mask;
  bpf_u_int32 net;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
    return EXIT_FAILURE;
  }

  device = argv[1];

  if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
    fprintf(stderr, "Error: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  handle = pcap_open_live(device, 65535, 1, 1000, errbuf);

  if (handle == NULL) {
    fprintf(stderr, "Error: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
    fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  for (;;) {
    struct pcap_pkthdr *header;
    const u_char *packet;

    int res = pcap_next_ex(handle, &header, &packet);

    if (res == -1) {
      fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
      return EXIT_FAILURE;
    } else if (res == 0) {
      continue;
    }

    printf("SSID: %s\n", packet + 36);
    printf("BSSID: %02x:%02x:%02x:%02x:%02x:%02x\n",
           packet[10], packet[11], packet[12], packet[13], packet[14], packet[15]);
    printf("Channel: %d\n", packet[26] + 1);
    printf("Signal: %d dBm\n", (int)packet[27] - 95);
  }

  pcap_freecode(&fp);
  pcap_close(handle);

  return EXIT_SUCCESS;
}