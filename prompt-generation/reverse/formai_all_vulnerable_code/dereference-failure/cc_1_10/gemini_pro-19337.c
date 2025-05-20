//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shape shifting
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BYTES 2048

int main(int argc, char **argv) {
  char *device;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  const unsigned char *packet;
  struct pcap_pkthdr header;
  int res;

  // Check if a device was specified.
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <device>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  device = argv[1];

  // Open the device for capturing.
  handle = pcap_open_live(device, MAX_BYTES, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Unable to open device: %s\n", errbuf);
    exit(EXIT_FAILURE);
  }

  // Capture packets until Ctrl-C is pressed.
  while (1) {
    res = pcap_next_ex(handle, &header, &packet);
    if (res == 0) continue;
    if (res == -1) {
      fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
      break;
    }

    // Print packet information.
    printf("Got a packet of length %d\n", header.len);
    printf("Capture time: %s\n", ctime((const time_t *)&header.ts.tv_sec));
    printf("Packet data:\n");
    for (int i = 0; i < header.len; i++) {
      printf("%02x ", packet[i]);
      if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
  }

  // Close the device.
  pcap_close(handle);

  return EXIT_SUCCESS;
}