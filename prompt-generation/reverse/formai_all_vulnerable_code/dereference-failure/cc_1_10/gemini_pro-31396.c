//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: accurate
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SNAPLEN 1518

int main(int argc, char *argv[])
{
  char *device;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct pcap_pkthdr *header;
  const u_char *packet;
  int res;

  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
    return EXIT_FAILURE;
  }

  device = argv[1];

  handle = pcap_open_live(device, SNAPLEN, 1, 1000, errbuf);
  if (handle == NULL)
  {
    fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
    return EXIT_FAILURE;
  }

  while ((res = pcap_next_ex(handle, &header, &packet)) >= 0)
  {
    if (res == 0)
    {
      continue;
    }

    printf("Packet length: %d\n", header->len);
    printf("Number of bytes captured: %d\n", header->caplen);
    printf("Time stamp: %ld.%06ld\n", header->ts.tv_sec, header->ts.tv_usec);

    // Print the packet data
    for (int i = 0; i < header->caplen; i++)
    {
      printf("%02x ", packet[i]);
      if ((i + 1) % 16 == 0)
      {
        printf("\n");
      }
    }

    printf("\n\n");
  }

  if (res == -1)
  {
    fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  pcap_close(handle);
  return EXIT_SUCCESS;
}