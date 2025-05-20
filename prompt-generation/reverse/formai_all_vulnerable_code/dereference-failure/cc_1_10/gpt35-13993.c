//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX_PACKET_SIZE 65536

void ProcessPacket(unsigned char*, int);
void PrintTcpPacket(unsigned char*, int);

int main()
{
  int sock_raw;
  int saddr_size, data_size;
  struct sockaddr_in saddr;
  unsigned char* buffer = (unsigned char*)malloc(MAX_PACKET_SIZE);

  sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

  if (sock_raw < 0) {
    printf("Error creating socket!\n");
    return 1;
  }

  while (1) {
    saddr_size = sizeof saddr;
    data_size = recvfrom(sock_raw, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr*)&saddr, (socklen_t*)&saddr_size);

    if (data_size < 0) {
      printf("Error receiving packet!\n");
      return 1;
    }

    ProcessPacket(buffer, data_size);
  }

  close(sock_raw);
  printf("Socket closed!\n");

  return 0;
}

void ProcessPacket(unsigned char* buffer, int size) {
  struct iphdr* iph = (struct iphdr*)buffer;
  switch (iph->protocol) {
  case IPPROTO_TCP:
    PrintTcpPacket(buffer, size);
    break;
  default:
    printf("Protocol not supported.\n");
    break;
  }
}

void PrintTcpPacket(unsigned char* buffer, int size) {
  unsigned short iphdrlen;
  struct iphdr* iph = (struct iphdr*)buffer;
  iphdrlen = iph->ihl * 4;
  struct tcphdr* tcph = (struct tcphdr*)(buffer + iphdrlen);

  int source_port = ntohs(tcph->source);
  int dest_port = ntohs(tcph->dest);
  char* source_ip = inet_ntoa(*(struct in_addr*)&iph->saddr);
  char* dest_ip = inet_ntoa(*(struct in_addr*)&iph->daddr);

  printf("************************TCP Packet*************************\n");
  printf("Source IP: %s\n", source_ip);
  printf("Destination IP: %s\n", dest_ip);
  printf("Source Port: %d\n", source_port);
  printf("Destination Port: %d\n", dest_port);
  printf("************************End Packet*************************\n\n");
}