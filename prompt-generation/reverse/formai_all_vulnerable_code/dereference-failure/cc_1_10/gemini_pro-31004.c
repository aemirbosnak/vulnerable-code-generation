//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: happy
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *dev;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct pcap_pkthdr header;
  const u_char *packet;
  char *filter_exp = "tcp and dst port 80";
  struct bpf_program fp;
  int i;

  // Find a device
  dev = pcap_lookupdev(errbuf);
  if (dev == NULL)
  {
    fprintf(stderr, "Couldn't find a device: %s\n", errbuf);
    return 2;
  }

  // Open the device
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL)
  {
    fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
    return 2;
  }

  // Compile the filter
  if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1)
  {
    fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return 2;
  }

  // Apply the filter
  if (pcap_setfilter(handle, &fp) == -1)
  {
    fprintf(stderr, "Couldn't apply filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return 2;
  }

  // Capture packets
  for (i = 0; i < 10; i++)
  {
    packet = pcap_next(handle, &header);
    if (packet == NULL)
    {
      fprintf(stderr, "Couldn't capture a packet: %s\n", pcap_geterr(handle));
      return 2;
    }

    // Print the packet
    printf("Packet %d:\n", i);
    printf("Timestamp: %s\n", ctime((const time_t *)&header.ts.tv_sec));
    printf("Length: %d bytes\n", header.len);
    printf("Data: ");
    for (i = 0; i < header.len; i++)
    {
      printf("%02x ", packet[i]);
    }
    printf("\n\n");
  }

  // Close the device
  pcap_close(handle);

  return 0;
}