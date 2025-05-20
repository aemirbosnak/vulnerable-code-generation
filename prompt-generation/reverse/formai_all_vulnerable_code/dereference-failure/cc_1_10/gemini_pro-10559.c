//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Romeo and Juliet
#include <pcap/pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  char *device;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct pcap_pkthdr *header;
  const u_char *packet;
  int i;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <device>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  device = argv[1];

  handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Error opening device %s: %s\n", device, errbuf);
    exit(EXIT_FAILURE);
  }

  printf("Listening on device %s\n", device);

  while (1) {
    i = pcap_next_ex(handle, &header, &packet);
    if (i == 0) {
      continue;
    } else if (i == -1) {
      fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
      break;
    } else if (i == -2) {
      fprintf(stderr, "Error: pcap_next_ex() was called with invalid parameters.\n");
      break;
    } else {
      printf("Packet received: ");
      for (i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
      }
      printf("\n");
    }
  }

  pcap_close(handle);

  return 0;
}