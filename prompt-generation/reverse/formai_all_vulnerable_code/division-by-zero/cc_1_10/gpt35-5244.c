//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int packets_received = 0;
   float average_latency = 0.0;
   int packet_loss = 0;
   int bandwidth_usage = 0;
   time_t start_time, end_time;

   printf("Welcome to the QoS monitor program!\n\n");

   start_time = time(NULL);
   printf("Monitoring network QoS...\n\n");

   while (1) {
      printf("Checking packet received... ");
      int packet_received = rand() % 2;
      if (packet_received) {
         printf("Packet received!\n");
         packets_received++;
      } else {
         printf("Packet lost!\n");
         packet_loss++;
      }

      printf("Checking latency... ");
      float latency = ((float) rand() / (float) RAND_MAX) * 100;
      printf("Latency: %.2fms\n", latency);
      average_latency = ((average_latency * (float) packets_received) + latency) / (float) (packets_received + 1);

      printf("Checking bandwidth usage... ");
      int bandwidth = rand() % 101;
      printf("Bandwidth usage: %d%%\n\n", bandwidth);
      bandwidth_usage += bandwidth;

      end_time = time(NULL);
      if (end_time - start_time >= 60) {
         printf("\n--QoS Summary--\n");
         printf("%d packets received\n", packets_received);
         printf("%d packets lost\n", packet_loss);
         printf("Average latency: %.2fms\n", average_latency);
         printf("Bandwidth usage: %d%%\n", bandwidth_usage / packets_received);
         printf("----------------\n\n");
         start_time = time(NULL);
      }

      sleep(1);
   }

   return 0;
}