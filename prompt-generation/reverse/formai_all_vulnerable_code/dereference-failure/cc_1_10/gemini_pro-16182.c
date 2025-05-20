//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: happy
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  pcap_t *handle;
  char *device;
  char errbuf[PCAP_ERRBUF_SIZE];

  // I'm so excited to hear what the network has to say!
  printf("Hooray! I'm ready to capture some packets! :)\n");

  // Let's find a device to listen on!
  device = pcap_lookupdev(errbuf);
  if (device == NULL) {
    fprintf(stderr, "Oops, couldn't find a device to listen on! :(\n");
    return EXIT_FAILURE;
  }

  // I promise to be patient and wait for some packets!
  handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Oh no, couldn't open the device! :(\n");
    return EXIT_FAILURE;
  }

  // Let's start listening!
  printf("Yay! I'm listening on %s! :D\n", device);

  // I'll keep listening until I hear from 10 packets!
  int num_packets = 0;
  struct pcap_pkthdr *header;
  const u_char *packet;
  while (num_packets < 10) {
    int res = pcap_next_ex(handle, &header, &packet);

    if (res == 0) {
      // No packets yet, I'll wait a little longer!
      continue;
    } else if (res == -1) {
      fprintf(stderr, "Oh dear, an error occurred! :(\n");
      return EXIT_FAILURE;
    } else if (res == -2) {
      // I've stopped listening, time to go home!
      break;
    }

    // I found a packet! Let's see what it's all about!
    printf("Hooray! I got a packet! :D\n");
    printf("Packet length: %d bytes\n", header->len);
    printf("Capture time: %s\n", ctime((const time_t *)&header->ts.tv_sec));

    // I'm not sure what's inside the packet yet, but I'll try my best to understand it!
    printf("Packet data:\n");
    for (int i = 0; i < header->len; i++) {
      printf("%02x ", packet[i]);
    }
    printf("\n\n");

    num_packets++;
  }

  // I've heard from enough packets! Time to say goodbye!
  printf("Goodbye, network! It was fun listening to your secrets! :D\n");

  // I'll close the connection and clean up my mess!
  pcap_close(handle);

  return EXIT_SUCCESS;
}