//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>

int main() {
  // Hey there, curious wanderer! Let's embark on a packet-capturing extravaganza.

  // First, let's summon our trusty pcap oracle.
  char *device;
  pcap_t *handle;
  char errbuf[PCAP_ERRBUF_SIZE];

  // Let's peek into the realm of devices.
  device = pcap_lookupdev(errbuf);
  if (device == NULL) {
    printf("Oops, no devices found! Time to go device-hunting.\n");
    return -1;
  }

  // Now, let's open a portal to the packet realm.
  handle = pcap_open_live(device, 65535, 1, 1000, errbuf);
  if (handle == NULL) {
    printf("Darn! Opening the portal failed. Let's try again.\n");
    return -1;
  }

  // Prepare for the packet torrent!
  struct pcap_pkthdr *header;
  const u_char *packet;

  // Now, let's unravel the packet mysteries.
  while (pcap_next_ex(handle, &header, &packet) >= 0) {
    printf("Behold! A packet has arrived!\n");

    // Let's dissect its headers, like a digital surgeon.
    printf("\tSource IP: %s\n", inet_ntoa(*(struct in_addr *)packet));
    printf("\tDestination IP: %s\n", inet_ntoa(*(struct in_addr *)(packet + 16)));

    // Time to decode the payload.
    printf("\tPayload: ");
    for (int i = 0; i < header->len; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n");
  }

  // Alas, our journey ends. Let's bid farewell to the packet stream.
  pcap_close(handle);

  return 0;
}