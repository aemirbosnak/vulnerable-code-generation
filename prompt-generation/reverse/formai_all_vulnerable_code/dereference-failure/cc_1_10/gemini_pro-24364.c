//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: surprised
#include <stdio.h>
#include <pcap.h>
#include <netinet/in.h>

int main() {
  char *device;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct pcap_pkthdr *header;
  const u_char *packet;
  int i;
  
  // Grab the first available network device
  device = pcap_lookupdev(errbuf);
  if (device == NULL) {
    printf("Couldn't find a network device: %s\n", errbuf);
    return -1;
  }
  
  // Open the device for packet capture
  handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    printf("Couldn't open the network device: %s\n", errbuf);
    return -1;
  }
  
  // Loop forever, capturing and printing packets
  while (1) {
    // Grab the next packet
    int ret = pcap_next_ex(handle, &header, &packet);
    if (ret == 1) {
      // Got a packet! Print the header
      printf("Captured packet with length %d\n", header->len);
      
      // Print the packet data
      for (i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
        if ((i+1) % 16 == 0) {
          printf("\n");
        }
      }
      printf("\n\n");
    } else if (ret == -1) {
      // An error occurred
      printf("An error occurred while capturing packets: %s\n", pcap_geterr(handle));
      break;
    } else {
      // No packets were captured
      printf("No packets were captured\n");
    }
  }
  
  // Close the device
  pcap_close(handle);
  
  return 0;
}