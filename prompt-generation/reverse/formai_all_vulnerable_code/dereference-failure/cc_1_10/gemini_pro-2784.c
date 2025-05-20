//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>
#include <time.h>

#define PCAP_ERRBUF_SIZE 256

int main(int argc, char **argv)
{
  char *device;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct pcap_pkthdr header;
  const unsigned char *packet;
  int i;
  int count = 0;
  char time_str[26];

  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  device = argv[1];

  handle = pcap_open_live(device, 65535, 1, 1000, errbuf);
  if (handle == NULL)
  {
    fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
    exit(EXIT_FAILURE);
  }

  while (1)
  {
    packet = pcap_next(handle, &header);
    if (packet == NULL)
    {
      if (errno == PCAP_ERROR)
      {
        fprintf(stderr, "pcap_next(): %s\n", pcap_geterr(handle));
      }
      continue;
    }
    else
    {
      strftime(time_str, 26, "%Y-%m-%d %H:%M:%S", localtime(&header.ts.tv_sec));
      printf("Packet %d:\n", count);
      printf("Time: %s\n", time_str);
      printf("Length: %d bytes\n", header.len);
      printf("Contents:\n");
      for (i = 0; i < header.len; i++)
      {
        if (i % 16 == 0)
        {
          printf("\n");
        }
        printf("%02X ", packet[i]);
      }
      printf("\n");
      count++;
    }
  }

  pcap_close(handle);

  return 0;
}