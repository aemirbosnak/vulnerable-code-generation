//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Claude Shannon
#include <pcap/pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/socket.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

struct shannon {
  char *device;
  char *filter;
  int promisc;
  int timeout;
};

struct shannon *shannon_create(char *device, char *filter, int promisc, int timeout) {
  struct shannon *s = malloc(sizeof(struct shannon));
  if (s == NULL) {
    return NULL;
  }
  s->device = device;
  s->filter = filter;
  s->promisc = promisc;
  s->timeout = timeout;
  return s;
}

void shannon_destroy(struct shannon *s) {
  free(s);
}

int shannon_capture(struct shannon *s, void (*callback)(u_char *, const struct pcap_pkthdr *, const u_char *)) {
  pcap_t *handle = pcap_open_live(s->device, BUFSIZ, s->promisc, s->timeout, s->filter);
  if (handle == NULL) {
    return -1;
  }
  int ret = pcap_loop(handle, -1, callback, NULL);
  pcap_close(handle);
  return ret;
}

void shannon_callback(u_char *user, const struct pcap_pkthdr *h, const u_char *bytes) {
  struct ether_header *eth = (struct ether_header *)bytes;
  struct ip *ip = (struct ip *)(bytes + sizeof(struct ether_header));
  struct tcphdr *tcp = (struct tcphdr *)(bytes + sizeof(struct ether_header) + sizeof(struct ip));
  struct udphdr *udp = (struct udphdr *)(bytes + sizeof(struct ether_header) + sizeof(struct ip));
  printf("Ethernet: %02x:%02x:%02x:%02x:%02x:%02x -> %02x:%02x:%02x:%02x:%02x:%02x\n",
         eth->ether_shost[0], eth->ether_shost[1], eth->ether_shost[2], eth->ether_shost[3], eth->ether_shost[4], eth->ether_shost[5],
         eth->ether_dhost[0], eth->ether_dhost[1], eth->ether_dhost[2], eth->ether_dhost[3], eth->ether_dhost[4], eth->ether_dhost[5]);
  printf("IP: %s -> %s\n", inet_ntoa(ip->ip_src), inet_ntoa(ip->ip_dst));
  if (ip->ip_p == IPPROTO_TCP) {
    printf("TCP: %d -> %d\n", ntohs(tcp->th_sport), ntohs(tcp->th_dport));
  } else if (ip->ip_p == IPPROTO_UDP) {
    printf("UDP: %d -> %d\n", ntohs(udp->uh_sport), ntohs(udp->uh_dport));
  }
}

int main(int argc, char **argv) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s device filter promisc timeout\n", argv[0]);
    return -1;
  }
  struct shannon *s = shannon_create(argv[1], argv[2], atoi(argv[3]), atoi(argv[4]));
  if (s == NULL) {
    fprintf(stderr, "Error creating shannon object\n");
    return -1;
  }
  int ret = shannon_capture(s, shannon_callback);
  if (ret == -1) {
    fprintf(stderr, "Error capturing packets\n");
    shannon_destroy(s);
    return -1;
  }
  shannon_destroy(s);
  return 0;
}