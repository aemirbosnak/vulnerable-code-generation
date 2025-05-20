//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65535

struct attack_signature {
  char *pattern;
  int pattern_length;
  int offset;
};

struct attack_signature sigs[] = {
  { "GET / HTTP/1.1", 15, 0 },
  { "POST / HTTP/1.1", 16, 0 },
  { "PUT / HTTP/1.1", 15, 0 },
  { "DELETE / HTTP/1.1", 18, 0 },
  { "HEAD / HTTP/1.1", 16, 0 },
  { "OPTIONS / HTTP/1.1", 19, 0 },
  { "TRACE / HTTP/1.1", 17, 0 },
  { "CONNECT / HTTP/1.1", 19, 0 },
  { "Host: ", 6, 0 },
  { "User-Agent: ", 12, 0 },
  { "Accept-Language: ", 17, 0 },
  { "Accept-Encoding: ", 17, 0 },
  { "Accept-Charset: ", 16, 0 },
  { "Content-Type: ", 13, 0 },
  { "Content-Length: ", 15, 0 }
};

int num_sigs = sizeof(sigs) / sizeof(struct attack_signature);

int main(int argc, char **argv) {
  char *interface;
  char *filter;
  pcap_t *handle;
  struct bpf_program fp;
  struct pcap_pkthdr header;
  const unsigned char *packet;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <interface> <filter>\n", argv[0]);
    return EXIT_FAILURE;
  }

  interface = argv[1];
  filter = argv[2];

  handle = pcap_open_live(interface, MAX_PACKET_SIZE, 1, 1000, NULL);
  if (handle == NULL) {
    fprintf(stderr, "Error opening interface %s: %s\n", interface, pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  if (pcap_compile(handle, &fp, filter, 0, 0) == -1) {
    fprintf(stderr, "Error compiling filter %s: %s\n", filter, pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Error setting filter %s: %s\n", filter, pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  while (1) {
    int ret = pcap_next_ex(handle, &header, &packet);
    if (ret == -1) {
      fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
      break;
    } else if (ret == 0) {
      continue;
    }

    for (int i = 0; i < num_sigs; i++) {
      if (strstr(packet, sigs[i].pattern) != NULL) {
        printf("Attack detected: %s\n", sigs[i].pattern);
      }
    }
  }

  pcap_close(handle);

  return EXIT_SUCCESS;
}