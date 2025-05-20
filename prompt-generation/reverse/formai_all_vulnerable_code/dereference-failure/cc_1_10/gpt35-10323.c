//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define PCAP_ERRBUF_SIZE 1024

int main(int argc, char **argv) {
  const char *interface; // Interface name
  char error_buffer[PCAP_ERRBUF_SIZE]; // Error buffer
  pcap_t *session_handle; // Session handle
  struct pcap_pkthdr packet_header; // Packet header
  const u_char *packet_data; // Packet data
  int pcap_return; // Return value from pcap functions

  // Get the interface name from command-line argument
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
    return 1;
  } else {
    interface = argv[1];
  }

  // Open the network interface
  session_handle = pcap_open_live(interface, 65535, 1, 1000, error_buffer);
  if (session_handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", interface, error_buffer);
    return 1;
  }

  // Capturing packets
  printf("Starting packet capturing on interface %s...\n", interface);
  while (1) {
    // Get the next packet from the network
    packet_data = pcap_next(session_handle, &packet_header);
    if (packet_data != NULL) {
      // Print the capture time and packet length
      printf("%ld:%ld (%ld)\n", packet_header.ts.tv_sec, packet_header.ts.tv_usec, packet_header.len);

      // Print the packet data
      for (int i = 0; i < packet_header.len; i++) {
        printf("%02X ", packet_data[i]);
      }
      printf("\n");
    } else if (packet_data == NULL && pcap_next_ex(session_handle, &packet_header, &packet_data) == -2) {
      // No more packets to capture, exit the loop
      printf("No more packets to capture. Exiting...\n");
      break;
    } else {
      // Error occurred while capturing the packet
      fprintf(stderr, "Couldn't capture packet: %s\n", pcap_geterr(session_handle));
      return 1;
    }
  }

  // Close the network interface
  pcap_close(session_handle);

  return 0;
}