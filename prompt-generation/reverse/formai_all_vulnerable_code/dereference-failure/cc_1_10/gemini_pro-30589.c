//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main() {
  char *device;
  pcap_t *handle;
  struct pcap_pkthdr *header;
  const unsigned char *packet;
  char errbuf[PCAP_ERRBUF_SIZE];

  printf("**Prepare for Shock: The Ultimate C Packet Capturer**\n\n");

  // Grab the default device for capturing packets
  device = pcap_lookupdev(errbuf);
  if (device == NULL) {
    printf("**Shock!** Couldn't find a suitable device: %s\n", errbuf);
    exit(1);
  }

  // Open the device for capturing
  handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    printf("**Shock!** Couldn't open the device: %s\n", errbuf);
    exit(1);
  }

  // Loop to capture and print packets
  while (1) {
    // Capture a packet
    int res = pcap_next_ex(handle, &header, &packet);
    if (res == 1) {
      // We got a packet!
      printf("**Shock!** I've snagged a packet!\n");
      printf("Packet length: %d\n", header->len);
      printf("Packet data:");

      for (int i = 0; i < header->len; i++) {
        printf(" %02x", packet[i]);
      }

      printf("\n\n");
    } else if (res == 0) {
      // Timeout
      printf("**Shock!** No packets received in the last few moments...\n");
    } else if (res == -1) {
      // Error
      printf("**Shock!** Something terrible happened: %s\n", pcap_geterr(handle));
      break;
    }
  }

  // Close the device and release resources
  pcap_close(handle);

  printf("\n**Shock!** Mission terminated. Brace yourself for the adrenaline rush!\n");

  return 0;
}