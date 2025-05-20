//FormAI DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define MAX_WAIT_TIME 3
#define MAX_NO_PACKETS 5

char sendpacket[PACKET_SIZE];
char recvpacket[PACKET_SIZE];
int sockfd, datalen = 56;
int nsend = 0, nreceived = 0;
struct sockaddr_in dest_addr;

struct timeval start, end;
double rtt_min = 0.0, rtt_max = 0.0, rtt_sum = 0.0;

pid_t getpid()
{
   return 999; // Replace with valid process ID here
}

unsigned short cal_chksum(unsigned short *addr, int len)
{
   int nleft = len;
   int sum = 0;
   unsigned short *w = addr;
   unsigned short answer = 0;

   while (nleft > 1) {
      sum += *w++;
      nleft -= 2;
   }

   if (nleft == 1) {
      *(unsigned char *) (&answer) = *(unsigned char *) w;
      sum += answer;
   }

   sum = (sum >> 16) + (sum & 0xffff);
   sum += (sum >> 16);
   answer = ~sum;
   return answer;
}

void send_packet(void)
{
   nsend++;
   memset(sendpacket, 0, sizeof(sendpacket));
   struct icmp *icmp_hdr = (struct icmp*)sendpacket;
   icmp_hdr->icmp_type = ICMP_ECHO;
   icmp_hdr->icmp_code = 0;
   icmp_hdr->icmp_cksum = 0;
   icmp_hdr->icmp_id = getpid();
   icmp_hdr->icmp_seq = nsend;

   gettimeofday(&start, NULL);
   icmp_hdr->icmp_cksum = cal_chksum((unsigned short*)icmp_hdr, PACKET_SIZE);

   if (sendto(sockfd, sendpacket, sizeof(sendpacket), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
      printf("Error sending packet\n");
   }
}

int recv_packet(void)
{
   struct timeval timeout = {MAX_WAIT_TIME, 0};

   fd_set readfds;
   FD_ZERO(&readfds);
   FD_SET(sockfd, &readfds);

   int ret = select(sockfd+1, &readfds, NULL, NULL, &timeout);
   if (ret < 0) {
      printf("Error reading socket\n");
      return -1;
   } else if (ret == 0) {
      printf("Packet timed out\n");
      return 0;
   } else {
      if (recvfrom(sockfd, recvpacket, sizeof(recvpacket), 0, NULL, NULL) < 0) {
         printf("Error receiving packet\n");
         return -1;
      }

      nreceived++;
      struct ip *ip_hdr = (struct ip*)recvpacket;
      struct icmp *icmp_hdr = (struct icmp*)(recvpacket + (ip_hdr->ip_hl<<2));
      if (icmp_hdr->icmp_type != ICMP_ECHOREPLY || icmp_hdr->icmp_id != getpid()) {
         printf("Packet received with unexpected ID or type\n");
         return 0;
      }

      gettimeofday(&end, NULL);
      double rtt = (double)(end.tv_sec-start.tv_sec)*1000.0 + (double)(end.tv_usec-start.tv_usec)/1000.0;
      printf("Packet received from %s with RTT=%.3fms\n", inet_ntoa(ip_hdr->ip_src), rtt);

      if (rtt_min == 0.0 || rtt < rtt_min) {
         rtt_min = rtt;
      }
      if (rtt > rtt_max) {
         rtt_max = rtt;
      }
      rtt_sum += rtt;

      return 1;
   }
}

int main(int argc, char* argv[])
{

   if (argc != 2) {
      printf("Usage: %s <hostname>\n", argv[0]);
      return -1;
   }

   struct hostent* host = gethostbyname(argv[1]);
   if (host == NULL) {
      printf("Error resolving host\n");
      return -1;
   }

   dest_addr.sin_family = AF_INET;
   dest_addr.sin_addr = *((struct in_addr*)host->h_addr);
   dest_addr.sin_port = htons(0);

   sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
   if (sockfd < 0) {
      printf("Error creating socket\n");
      return -1;
   }

   printf("PING %s: %d data bytes\n", argv[1], datalen);
   int pkt_count = 0;
   while (pkt_count < MAX_NO_PACKETS) {
      send_packet();
      int ret = recv_packet();
      if (ret == 0) {
         pkt_count++;
      } else if (ret < 0) {
         return -1;
      }
      usleep(1000*500);
   }

   double rtt_avg = rtt_sum / nreceived;
   printf("--- %s ping statistics ---\n", argv[1]);
   printf("%d packets transmitted, %d received, %.0f%% packet loss, time %.0fms\n", nsend, nreceived, (double)(nsend-nreceived)/nsend*100.0, MAX_WAIT_TIME*1000.0);
   printf("rtt min/avg/max = %.3f/%.3f/%.3f ms\n", rtt_min, rtt_avg, rtt_max);

   return 0;
}