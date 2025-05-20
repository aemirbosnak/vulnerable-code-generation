//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<time.h>

#define PACKET_SIZE 65536

struct sockaddr_in source;

void packetHandler(unsigned char* buffer, int size) {
  
  struct iphdr *iph = (struct iphdr*)buffer;
  
  unsigned short iphdrlen = iph->ihl*4;
  
  struct tcphdr *tcph=(struct tcphdr*)(buffer + iphdrlen);
      
  memset(&source, 0, sizeof(source));
  source.sin_addr.s_addr = iph->saddr;
  
  if(tcph->syn && !tcph->ack) {
      printf("SYN Flood Detected! Source IP: %s \n",inet_ntoa(source.sin_addr));
      printf("Cleaning up...");
      //Clean up procedures
      
      //Close Socket
      
      printf("Exiting... \n");
      exit(0);
  }
}

int main() {
    int sock_raw;
    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if(sock_raw<0) {
    printf("Socket creation error\n");
    return 1;
    }
    
    unsigned char* buffer = (unsigned char*)malloc(PACKET_SIZE);
    
    while(1) {
        printf("Packet Received\n");
        int len = recv(sock_raw, buffer, PACKET_SIZE, 0);
        if(len<0) {
            printf("Receive Error\n");
            return 1;
        }
        packetHandler(buffer, len);
    }
    close(sock_raw);
    printf("Socket Closed");
    return 0;
}