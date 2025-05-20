//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: random
#include <pcap/pcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BYTES 2048
#define MAX_PACKETS 100

// Callback function that is called for every packet that is captured
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
  printf("Captured a packet with length %d\n", header->len);
  // Print out the first 100 bytes of the packet
  for (int i = 0; i < 100 && i < header->len; i++) {
    printf("%02x ", packet[i]);
  }
  printf("\n");
}

int main(int argc, char **argv) {
  char *device;
  char *filter;
  int promisc;
  int timeout;
  int snaplen;
  int count;
  pcap_t *handle;
  struct bpf_program fp;
  pcap_dumper_t *dumper;

  // Parse command-line arguments
  if (argc < 2) {
    printf("Usage: %s <device> [<filter>] [<promisc>] [<timeout>] [<snaplen>] [<count>]\n", argv[0]);
    exit(1);
  }
  device = argv[1];
  if (argc > 2) {
    filter = argv[2];
  } else {
    filter = NULL;
  }
  if (argc > 3) {
    promisc = atoi(argv[3]);
  } else {
    promisc = 0;
  }
  if (argc > 4) {
    timeout = atoi(argv[4]);
  } else {
    timeout = 1000;
  }
  if (argc > 5) {
    snaplen = atoi(argv[5]);
  } else {
    snaplen = MAX_BYTES;
  }
  if (argc > 6) {
    count = atoi(argv[6]);
  } else {
    count = MAX_PACKETS;
  }

  // Open the device for capturing
  handle = pcap_open_live(device, snaplen, promisc, timeout, NULL);
  if (handle == NULL) {
    perror("pcap_open_live");
    exit(1);
  }

  // Compile the filter
  if (filter != NULL) {
    if (pcap_compile(handle, &fp, filter, 0, 0) == -1) {
      perror("pcap_compile");
      exit(1);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
      perror("pcap_setfilter");
      exit(1);
    }
  }

  // Open a file for dumping the packets
  dumper = pcap_dump_open(handle, "packets.pcap");
  if (dumper == NULL) {
    perror("pcap_dump_open");
    exit(1);
  }

  // Capture packets
  pcap_loop(handle, count, packet_handler, NULL);

  // Close the device and the dump file
  pcap_close(handle);
  pcap_dump_close(dumper);

  return 0;
}