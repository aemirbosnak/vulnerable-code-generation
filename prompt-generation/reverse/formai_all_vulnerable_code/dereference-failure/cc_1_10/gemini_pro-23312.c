//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: introspective
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;

  // Open the network interface
  handle = pcap_open_live("en0", 65535, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "pcap_open_live: %s\n", errbuf);
    return 1;
  }

  // Set the filter
  struct bpf_program fp;
  if (pcap_compile(handle, &fp, "tcp and port 80", 1, 0) == -1) {
    fprintf(stderr, "pcap_compile: %s\n", pcap_geterr(handle));
    return 1;
  }
  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "pcap_setfilter: %s\n", pcap_geterr(handle));
    return 1;
  }

  // Capture packets
  int packets = 0;
  while (1) {
    struct pcap_pkthdr *header;
    const unsigned char *data;
    int res = pcap_next_ex(handle, &header, &data);
    if (res == -1) {
      fprintf(stderr, "pcap_next_ex: %s\n", pcap_geterr(handle));
      break;
    }
    if (res == 0) {
      continue;
    }
    packets++;
    printf("Packet %d: %d bytes\n", packets, header->len);
    for (int i = 0; i < header->len; i++) {
      printf("%02x ", data[i]);
    }
    printf("\n");
  }

  // Close the network interface
  pcap_close(handle);

  return 0;
}