//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
  char *device = "en0";
  char *filter = "tcp and port 80";
  int snaplen = 1024;
  int promisc = 1;
  int timeout = 1000;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct pcap_pkthdr *header;
  const u_char *packet;

  handle = pcap_open_live(device, snaplen, promisc, timeout, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", device, errbuf);
    exit(1);
  }

  if (pcap_compile(handle, &filter, 1, 0, errbuf) == -1) {
    fprintf(stderr, "Couldn't parse filter %s: %s\n", filter, errbuf);
    exit(1);
  }

  if (pcap_setfilter(handle, &filter) == -1) {
    fprintf(stderr, "Couldn't set filter %s: %s\n", filter, errbuf);
    exit(1);
  }

  while (1) {
    int res = pcap_next_ex(handle, &header, &packet);
    if (res == -1) {
      fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
      exit(1);
    } else if (res == 0) {
      continue;
    }

    printf("Packet captured!\n");
    printf("Timestamp: %u.%u\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("Length: %d\n", header->len);
    printf("Data: ");
    for (int i = 0; i < header->len; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n\n");
  }

  pcap_close(handle);
  return 0;
}