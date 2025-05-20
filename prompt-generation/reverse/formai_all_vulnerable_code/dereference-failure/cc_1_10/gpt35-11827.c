//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>

#define BUFLEN 1472  // Maximum packet size

int main(int argc, char *argv[]) {
   int sockfd;
   char buf[BUFLEN];
   struct sockaddr_in serv_addr, addr;
   int slen = sizeof(addr);
   struct timeval tvalStart, tvalEnd;
   double total_time = 0;
   double max_latency = 0;
   double min_latency = 1000000;
   double avg_latency = 0;
   double jitter = 0;
   int seq = 0;
   int n = 0;
   
   // Create socket
   if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
      perror("socket");
      exit(1);
   }
   
   // Set server address
   memset(&serv_addr, 0, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
   serv_addr.sin_port = htons(atoi(argv[2]));
   
   while (1) {
      // Prepare packet
      memset(buf, 'A', BUFLEN);
      struct sockaddr_in addr = {0};
      addr.sin_family = AF_INET;
      addr.sin_port = htons(1234);
      addr.sin_addr.s_addr = inet_addr(argv[1]);
      
      // Record send time
      gettimeofday(&tvalStart, NULL);
      
      // Send packet
      sendto(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
      
      // Receive packet
      n = recvfrom(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&addr, &slen);
      
      // Record receive time
      gettimeofday(&tvalEnd, NULL);
      
      // Calculate latency
      double latency = ((tvalEnd.tv_sec - tvalStart.tv_sec) * 1000.0) + ((tvalEnd.tv_usec - tvalStart.tv_usec) / 1000.0);
      
      // Calculate jitter
      if (seq != 0) {
         jitter += ((abs(latency - avg_latency)) - jitter) / seq;
      }
      
      // Update min and max latency
      if (latency < min_latency) {
         min_latency = latency;
      }
      if (latency > max_latency) {
         max_latency = latency;
      }
      
      // Update average latency
      avg_latency += ((latency - avg_latency)) / seq;
      
      // Display results
      printf("seq=%d, latency=%.2fms, min=%.2fms, max=%.2fms, avg=%.2fms, jitter=%.2fms\n", seq, latency, min_latency, max_latency, avg_latency, jitter);
      seq++;
      
      // Sleep for 1 second
      sleep(1);
   }
   
   close(sockfd);
   return 0;
}