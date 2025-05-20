//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void callback(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
  int *count = (int *) args;
  (*count)++;
}

int introspect_network_packets(char *device, int count, int timeout) {
  pcap_t *handle;
  bpf_u_int32 net, mask;
  char errbuf[PCAP_ERRBUF_SIZE];

  if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
    fprintf(stderr, "Error: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  handle = pcap_open_live(device, BUFSIZ, 1, timeout, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Error: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  if (pcap_setnonblock(handle, 1, errbuf) == -1) {
    fprintf(stderr, "Error: %s\n", errbuf);
    pcap_close(handle);
    return EXIT_FAILURE;
  }

  int packet_count = 0;
  if (pcap_loop(handle, count, callback, (u_char *) &packet_count) == -1) {
    fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
    pcap_close(handle);
    return EXIT_FAILURE;
  }

  pcap_close(handle);
  printf("Introspected %d packets from %s.\n", packet_count, device);

  return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <device> <count> <timeout>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *device = argv[1];
  int count = atoi(argv[2]);
  int timeout = atoi(argv[3]);

  return introspect_network_packets(device, count, timeout);
}