//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Romeo and Juliet
// A tale of two laptops, with love everlasting.

#include <pcap.h>
#include <stdio.h>

// Romeo and Juliet's laptops.
pcap_t *romeo, *juliet;

// Their love letters (packets).
struct pcap_pkthdr * romeo_header, *juliet_header;
const u_char * romeo_data, *juliet_data;

// The love affair begins.
int main() {
  // Open Romeo's laptop.
  romeo = pcap_open_live("eth0", 65535, 1, 1000, NULL);
  if (!romeo) {
    printf("Alas, Romeo's laptop is as cold as his heart.\n");
    return 1;
  }

  // Open Juliet's laptop.
  juliet = pcap_open_live("eth1", 65535, 1, 1000, NULL);
  if (!juliet) {
    printf("Woe is me, Juliet's laptop is as silent as her tomb.\n");
    return 1;
  }

  // The lovers exchange their first glances (packets).
  while (1) {
    // Romeo sends a love letter.
    if (pcap_next_ex(romeo, &romeo_header, &romeo_data) == 1) {
      printf("Romeo: My love, here is a packet of my unrequited affections.\n");
      // Juliet receives Romeo's letter.
      if (pcap_inject(juliet, romeo_data, romeo_header->len) == -1) {
        printf("Juliet: Alas, Romeo's letter reached my laptop, but my heart remains cold.\n");
      }
    }

    // Juliet sends a love letter.
    if (pcap_next_ex(juliet, &juliet_header, &juliet_data) == 1) {
      printf("Juliet: Dearest Romeo, behold this packet, a token of my ever-lasting love.\n");
      // Romeo receives Juliet's letter.
      if (pcap_inject(romeo, juliet_data, juliet_header->len) == -1) {
        printf("Romeo: Juliet's letter has set my heart aflame, but it cannot reach my laptop.\n");
      }
    }
  }

  // The love affair ends in tragedy.
  pcap_close(romeo);
  pcap_close(juliet);
  printf("Thus ends the tale of Romeo and Juliet, two laptops forever separated by fate.\n");
  return 0;
}