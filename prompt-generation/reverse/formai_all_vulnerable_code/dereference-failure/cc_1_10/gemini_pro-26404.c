//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Donald Knuth
/*
** An enchanting packet capturing incantation, inspired by the esteemed Donald Knuth.
**
** Lo, this program weaveth a magical net to ensnare the ethereal packets that traverse the network.
** It doth employ the pcap library, a tool of great cunning and agility, to wield the power of libpcap.
**
** Let us now embark on this arcane adventure!
*/

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char errbuf[PCAP_ERRBUF_SIZE];
  char *device = pcap_lookupdev(errbuf);
  if (device == NULL) {
    fprintf(stderr, "Error: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  pcap_t *handle = pcap_open_live(device, 65535, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Error: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  struct pcap_pkthdr *header;
  const u_char *packet;

  while (1) {
    int res = pcap_next_ex(handle, &header, &packet);
    if (res == 0) {
      continue;
    } else if (res == -1) {
      fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
      break;
    }

    printf("A packet hath been captured, its length is %d bytes.\n", header->len);
    printf("The packet's time is %s\n", ctime((time_t *) &header->ts.tv_sec));

    for (int i = 0; i < header->len; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n\n");
  }

  pcap_close(handle);
  return EXIT_SUCCESS;
}