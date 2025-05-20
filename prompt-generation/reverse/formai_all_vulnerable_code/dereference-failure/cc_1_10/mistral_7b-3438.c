//MISTRAL-7B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#define PKT_LEN 1514

void main(int argc, char **argv) {
  pcap_t *handle;
  char errbuf[PCAP_ERRBUF_SIZE];
  char filter_exp[] = "ip";
  struct pcap_pkthdr *header;
  u_char *packet;
  int i;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
    exit(1);
  }

  handle = pcap_open_live(argv[1], PKT_LEN, 1, 1000, errbuf);

  if (handle == NULL) {
    fprintf(stderr, "Error opening device: %s\n", errbuf);
    exit(1);
  }

  if (pcap_compile(handle, (struct bpf_program *)filter_exp, 0, 0, NULL) < 0) {
    fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
    exit(1);
  }

  if (pcap_setfilter(handle, (struct bpf_program *)filter_exp) < 0) {
    fprintf(stderr, "Error applying filter: %s\n", pcap_geterr(handle));
    exit(1);
  }

  while (1) {
    header = pcap_next(handle, &packet);

    if (header == NULL) continue;

    printf("Packet captured:\n");
    printf("  Length: %u\n", header->len);
    printf("  Timestamp: %u.%06u\n", header->ts.tv_sec, header->ts.tv_usec);

    for (i = 0; i < header->len; i++) {
      printf("%02x ", packet[i]);
    }

    printf("\n");
  }

  pcap_close(handle);
}