//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_PACKET_SIZE 100

typedef struct {
    int delay;
    int loss;
    int throughput;
} QoS_metrics;

int packet_count = 0;
int received_count = 0;

void *QoS_monitor(void *args) {
    int sock, delay, loss, throughput, i;
    struct sockaddr_in addr;
    char packet[MAX_PACKET_SIZE];
    QoS_metrics *metrics = (QoS_metrics *)args;
    
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == -1) {
        perror("socket() failed");
        exit(1);
    }
    
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(5000);
    
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind() failed");
        exit(1);
    }
    
    while (1) {
        if (recv(sock, packet, MAX_PACKET_SIZE, 0) != -1) {
            received_count++;
            
            // Simulate delay
            delay = rand() % 50;
            usleep(delay * 1000);
            metrics->delay += delay;
            
            // Simulate loss
            loss = rand() % 10;
            if (loss < 3) {
                // Packet lost
                continue;
            }
            
            // Simulate throughput
            throughput = strlen(packet);
            metrics->throughput += throughput;
            
            // Increment packet count
            packet_count++;
        } else {
            perror("recv() failed");
        }
    }
    
    close(sock);
}


int main() {
    QoS_metrics metrics;
    pthread_t thread_id;
    
    metrics.delay = 0;
    metrics.loss = 0;
    metrics.throughput = 0;
    
    if (pthread_create(&thread_id, NULL, QoS_monitor, &metrics) != 0) {
        perror("pthread_create() failed");
        exit(1);
    }
    
    while (1) {
        // Calculate packet loss percentage
        metrics.loss = ((packet_count - received_count) / (float)packet_count) * 100;
        
        printf("Delay: %d ms\n", metrics.delay / received_count);
        printf("Packet loss: %.2f%%\n", metrics.loss);
        printf("Throughput: %d bytes/s\n", metrics.throughput / received_count);
        
        // Wait for one second
        sleep(1);
    }
    
    return 0;
}