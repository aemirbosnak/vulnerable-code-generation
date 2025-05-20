//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: cheerful
#include <stdio.h>
#include <pcap.h>

int main() {
  char *dev;
  pcap_t *handle;
  char errbuf[PCAP_ERRBUF_SIZE];
  struct pcap_pkthdr *header;
  const u_char *packet;

  printf("Hello! Let's capture some packets!\n");

  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    fprintf(stderr, "Error finding device: %s\n", errbuf);
    return 1;
  }

  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Error opening device: %s\n", errbuf);
    return 1;
  }

  printf("Yay! We're ready to capture!\n");

  while (1) {
    int res = pcap_next_ex(handle, &header, &packet);
    if (res == 0) {
      // Timeout
      continue;
    } else if (res == -1) {
      // Error
      fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
      break;
    } else {
      // We got a packet!
      printf("Wohoo! We caught a packet! 🎉\n");
      printf("Packet length: %d bytes\n", header->len);
      printf("Packet data:\n");
      for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
      }
      printf("\n\n");
    }
  }

  pcap_close(handle);

  printf("Bye-bye! See you next time! 🌟");

  return 0;
}