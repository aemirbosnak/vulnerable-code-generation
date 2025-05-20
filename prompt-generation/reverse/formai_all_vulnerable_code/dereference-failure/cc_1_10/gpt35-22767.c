//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: introspective
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <netinet/if_ether.h>
 
int main(int argc, char *argv[])
{
  char errbuf[PCAP_ERRBUF_SIZE];
 
  /* Check for the correct number of arguments */
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
 
  /* Open the specified interface for packet capture */
  pcap_t *capture_handle = pcap_open_live(argv[1], BUFSIZ, 1, 0, errbuf);
 
  if (capture_handle == NULL) {
    fprintf(stderr, "Failed to open %s: %s\n", argv[1], errbuf);
    exit(EXIT_FAILURE);
  }
 
  /* Begin the packet capture loop */
  struct pcap_pkthdr header;
  const uint8_t *packet;
  while ((packet = pcap_next(capture_handle, &header)) != NULL) {
    printf("Received packet of length %d\n", header.len);
 
    /* Parse the Ethernet header */
    const struct ether_header *ethernet_header = (const struct ether_header *) packet;
 
    printf("Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           ethernet_header->ether_shost[0],
           ethernet_header->ether_shost[1],
           ethernet_header->ether_shost[2],
           ethernet_header->ether_shost[3],
           ethernet_header->ether_shost[4],
           ethernet_header->ether_shost[5]);
 
    printf("Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
           ethernet_header->ether_dhost[0],
           ethernet_header->ether_dhost[1],
           ethernet_header->ether_dhost[2],
           ethernet_header->ether_dhost[3],
           ethernet_header->ether_dhost[4],
           ethernet_header->ether_dhost[5]);
 
    printf("\n");
  }
 
  /* Cleanup */
  pcap_close(capture_handle);
 
  return 0;
}