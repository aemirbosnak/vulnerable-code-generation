//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: statistical
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SNAPLEN 1518

int main(int argc, char **argv) {
  char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct bpf_program fp;
  char filter_exp[] = "tcp";
  bpf_u_int32 mask;
  bpf_u_int32 net;
  struct pcap_pkthdr *header;
  const unsigned char *packet;
  int i;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  dev = argv[1];

  if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
    fprintf(stderr, "pcap_lookupnet: %s\n", errbuf);
    exit(EXIT_FAILURE);
  }

  handle = pcap_open_live(dev, SNAPLEN, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "pcap_open_live: %s\n", errbuf);
    exit(EXIT_FAILURE);
  }

  if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
    fprintf(stderr, "pcap_compile: %s\n", pcap_geterr(handle));
    exit(EXIT_FAILURE);
  }

  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "pcap_setfilter: %s\n", pcap_geterr(handle));
    exit(EXIT_FAILURE);
  }

  while (1) {
    if (pcap_next_ex(handle, &header, &packet) == 1) {
      printf("Packet captured at %s\n", ctime((const time_t *) &header->ts.tv_sec));
      printf("Packet length: %d\n", header->len);
      printf("Packet data:\n");
      for (i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
      }
      printf("\n\n");
    }
  }

  pcap_close(handle);
  return EXIT_SUCCESS;
}