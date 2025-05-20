//MISTRAL-7B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pcap.h>

#define BUF_SIZE 65536

void die(const char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  char errbuf[PCAP_ERRBUF_SIZE];
  char filter_exp[] = "ip";
  pcap_t *handle;
  struct pcap_pkthdr *header;
  const u_char *packet;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if ((handle = pcap_open_live(argv[1], BUF_SIZE, 1, 1000, errbuf)) == NULL)
    die("pcap_open_live");

  if (pcap_compile(handle, filter_exp, 0, 0, errbuf) < 0)
    die("pcap_compile");

  if (pcap_setfilter(handle, filter_exp) < 0)
    die("pcap_setfilter");

  printf("Capture started on %s\n", argv[1]);

  while ((packet = pcap_next(handle, &header)) != NULL) {
    int i;
    printf("Packet captured: \n");
    printf("  Time: %u.%03u sec\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("  Length: %u bytes\n", header->len);

    for (i = 0; i < header->len; i++)
      printf("%.2x ", packet[i]);
    printf("\n");
  }

  pcap_close(handle);
  printf("Capture finished\n");

  return EXIT_SUCCESS;
}