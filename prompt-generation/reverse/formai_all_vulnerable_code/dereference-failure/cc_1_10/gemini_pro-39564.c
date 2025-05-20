//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: scientific
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
  char *dev = "eth0";
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct bpf_program fp;
  char filter_exp[] = "tcp and port 80";
  bpf_u_int32 net;
  pcap_addr_t *netmask;
  struct pcap_pkthdr *header;
  const u_char *packet;

  if (pcap_lookupnet(dev, &net, &netmask, errbuf) == -1) {
    fprintf(stderr, "pcap_lookupnet: %s\n", errbuf);
    return 1;
  }

  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "pcap_open_live: %s\n", errbuf);
    return 1;
  }

  if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
    fprintf(stderr, "pcap_compile: %s\n", pcap_geterr(handle));
    return 1;
  }

  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "pcap_setfilter: %s\n", pcap_geterr(handle));
    return 1;
  }

  while (1) {
    int res = pcap_next_ex(handle, &header, &packet);
    if (res == -1) {
      fprintf(stderr, "pcap_next_ex: %s\n", pcap_geterr(handle));
      break;
    } else if (res == 0) {
      continue;
    }

    printf("Packet length: %d\n", header->len);
    printf("Number of bytes captured: %d\n", header->caplen);
    printf("Time stamp: %s\n", ctime((const time_t *)&header->ts.tv_sec));

    printf("Source address: %s\n", inet_ntoa(*(struct in_addr *)&packet[12]));
    printf("Destination address: %s\n", inet_ntoa(*(struct in_addr *)&packet[16]));

    printf("Source port: %d\n", ntohs(*(unsigned short *)&packet[20]));
    printf("Destination port: %d\n", ntohs(*(unsigned short *)&packet[22]));

    printf("Protocol: %d\n", packet[9]);

    printf("Payload:\n");
    for (int i = 0; i < header->caplen; i++) {
      printf("%02x ", packet[i]);
      if ((i + 1) % 16 == 0) {
        printf("\n");
      }
    }

    printf("\n\n");
  }

  pcap_freecode(&fp);
  pcap_close(handle);

  return 0;
}