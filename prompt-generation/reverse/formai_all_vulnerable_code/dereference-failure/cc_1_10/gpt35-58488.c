//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<netinet/udp.h>
#include<netinet/ether.h>
#include<netinet/if_ether.h>
#include<netinet/ip_icmp.h>
#include<string.h>
#include<ctype.h>

#define MAX_BUF_LEN 65536

int main(int argc, char *argv[]) {
  int sockfd, len;
  socklen_t slen = sizeof(struct sockaddr_in);
  char buffer[MAX_BUF_LEN];
  struct sockaddr_in servaddr, cliaddr;
  struct ether_header *eth_header;
  struct iphdr *ip_header;
  struct tcphdr *tcp_header;
  struct udphdr *udp_header;
  struct icmphdr *icmp_header;
  struct hostent *host;
  char *name;

  // Creating a raw socket to listen for incoming packets
  sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP | IPPROTO_UDP | IPPROTO_ICMP);
  if (sockfd < 0) {
    printf("Error: could not create raw socket\n");
    exit(1);
  }

  while (1) {
    //Waiting for incoming packet
    len = recvfrom(sockfd, buffer, MAX_BUF_LEN, 0, (struct sockaddr *) &cliaddr, &slen);
    printf("Packet received!!\n");
    // Extracting Ethernet header from the received packet
    eth_header = (struct ether_header *) buffer;
    if(ntohs(eth_header->ether_type) != ETHERTYPE_IP) {
        printf("Error: Not an IP packet!!\n");
    }
    // Extracting IP header from the received packet
    ip_header = (struct iphdr *) (buffer + sizeof(struct ether_header));

    // Filling server address structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = ip_header->saddr;
    servaddr.sin_port = htons(0);

    // Resolving hostname from IP address
    host = gethostbyaddr((char *) &servaddr.sin_addr.s_addr, 4, AF_INET);
    if (host != NULL) {
      name = host->h_name;
    } else {
      name = inet_ntoa(servaddr.sin_addr);
    }

    printf("\n\nPacket Details:\n");
    printf("----------------------------\n");
    printf("Source IP: %s\n", inet_ntoa(servaddr.sin_addr));
    printf("Source Hostname: %s\n", name);

    // Extracting transport layer protocol information from IP header
    switch (ip_header->protocol) {
      case IPPROTO_TCP:
        tcp_header = (struct tcphdr *) (buffer + sizeof(struct ether_header) + sizeof(struct iphdr));
        printf("Protocol: TCP\n");
        printf("Source Port: %d\n", ntohs(tcp_header->source));
        printf("Destination Port: %d\n", ntohs(tcp_header->dest));
        break;

      case IPPROTO_UDP:
        udp_header = (struct udphdr *) (buffer + sizeof(struct ether_header) + sizeof(struct iphdr));
        printf("Protocol: UDP\n");
        printf("Source Port: %d\n", ntohs(udp_header->source));
        printf("Destination Port: %d\n", ntohs(udp_header->dest));
        break;

      case IPPROTO_ICMP:
        icmp_header = (struct icmphdr *) (buffer + sizeof(struct ether_header) + sizeof(struct iphdr));
        printf("Protocol: ICMP\n");
        printf("Type: %d\n", icmp_header->type);
        printf("Code: %d\n", icmp_header->code);
        break;

      default:
        printf("Protocol: Unknown\n");
        break;
    }
  }
}