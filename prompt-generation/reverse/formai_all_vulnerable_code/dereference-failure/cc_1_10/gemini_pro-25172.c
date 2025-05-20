//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

// Montague & Capulet
void montague(char* dev) {
  pcap_t* handle;
  struct pcap_pkthdr* header;
  const u_char* packet;
  int i = 0;
  char errbuf[PCAP_ERRBUF_SIZE];

  // Open the network device
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
    exit(1);
  }

  // Capture packets
  while ((packet = pcap_next(handle, &header)) != NULL) {
    printf("Packet %d:\n", ++i);

    // Ethernet header
    struct ether_header* eth = (struct ether_header*)packet;
    printf("  Ethernet:\n");
    printf("    Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
        eth->ether_shost[0], eth->ether_shost[1], eth->ether_shost[2],
        eth->ether_shost[3], eth->ether_shost[4], eth->ether_shost[5]);
    printf("    Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
        eth->ether_dhost[0], eth->ether_dhost[1], eth->ether_dhost[2],
        eth->ether_dhost[3], eth->ether_dhost[4], eth->ether_dhost[5]);

    // IP header
    struct ip* ip = (struct ip*)(packet + sizeof(struct ether_header));
    printf("  IP:\n");
    printf("    Source IP: %s\n", inet_ntoa(ip->ip_src));
    printf("    Destination IP: %s\n", inet_ntoa(ip->ip_dst));

    // TCP header
    struct tcphdr* tcp = (struct tcphdr*)(packet + sizeof(struct ether_header) + sizeof(struct ip));
    printf("  TCP:\n");
    printf("    Source Port: %d\n", ntohs(tcp->th_sport));
    printf("    Destination Port: %d\n", ntohs(tcp->th_dport));
  }

  // Close the device
  pcap_close(handle);
}

// Capulet & Montague
void capulet(char* dev) {
  pcap_t* handle;
  struct pcap_pkthdr* header;
  const u_char* packet;
  int i = 0;
  char errbuf[PCAP_ERRBUF_SIZE];

  // Open the network device
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
    exit(1);
  }

  // Capture packets
  while ((packet = pcap_next(handle, &header)) != NULL) {
    printf("Packet %d:\n", ++i);

    // Ethernet header
    struct ether_header* eth = (struct ether_header*)packet;
    printf("  Ethernet:\n");
    printf("    Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
        eth->ether_dhost[0], eth->ether_dhost[1], eth->ether_dhost[2],
        eth->ether_dhost[3], eth->ether_dhost[4], eth->ether_dhost[5]);
    printf("    Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
        eth->ether_shost[0], eth->ether_shost[1], eth->ether_shost[2],
        eth->ether_shost[3], eth->ether_shost[4], eth->ether_shost[5]);

    // IP header
    struct ip* ip = (struct ip*)(packet + sizeof(struct ether_header));
    printf("  IP:\n");
    printf("    Source IP: %s\n", inet_ntoa(ip->ip_dst));
    printf("    Destination IP: %s\n", inet_ntoa(ip->ip_src));

    // TCP header
    struct tcphdr* tcp = (struct tcphdr*)(packet + sizeof(struct ether_header) + sizeof(struct ip));
    printf("  TCP:\n");
    printf("    Source Port: %d\n", ntohs(tcp->th_dport));
    printf("    Destination Port: %d\n", ntohs(tcp->th_sport));
  }

  // Close the device
  pcap_close(handle);
}

int main(int argc, char** argv) {
  if (argc != 3) {
    printf("Usage: %s <interface> <romeo|juliet>\n", argv[0]);
    exit(1);
  }

  if (strcmp(argv[2], "romeo") == 0) {
    montague(argv[1]);
  } else if (strcmp(argv[2], "juliet") == 0) {
    capulet(argv[1]);
  } else {
    printf("Invalid argument: %s\n", argv[2]);
    exit(1);
  }

  return 0;
}