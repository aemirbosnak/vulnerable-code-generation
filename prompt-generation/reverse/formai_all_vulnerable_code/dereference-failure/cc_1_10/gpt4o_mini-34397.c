//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <time.h>

#define BUFFER_SIZE 65536

typedef struct {
    int packetCount;
    int byteCount;
    float averageLatency;
    float minLatency;
    float maxLatency;
} QoSStats;

void calculateLatency(QoSStats* stats, struct timeval *start, struct timeval *end) {
    float latency = (end->tv_sec - start->tv_sec) * 1000.0 + (end->tv_usec - start->tv_usec) / 1000.0;
    stats->packetCount++;
    stats->byteCount += sizeof(struct iphdr) + sizeof(struct tcphdr); // Assuming TCP packets

    if (stats->packetCount == 1) {
        stats->minLatency = latency;
        stats->maxLatency = latency;
    } else {
        if (latency < stats->minLatency) {
            stats->minLatency = latency;
        }
        if (latency > stats->maxLatency) {
            stats->maxLatency = latency;
        }
    }

    stats->averageLatency = ((stats->averageLatency * (stats->packetCount - 1)) + latency) / stats->packetCount;
}

void printQoSStats(QoSStats* stats) {
    printf("Packets: %d\n", stats->packetCount);
    printf("Bytes: %d\n", stats->byteCount);
    printf("Average Latency: %.2f ms\n", stats->averageLatency);
    printf("Min Latency: %.2f ms\n", stats->minLatency);
    printf("Max Latency: %.2f ms\n", stats->maxLatency);
}

void monitorNetworkTraffic() {
    int rawSocket;
    struct sockaddr saddr;
    socklen_t saddr_len = sizeof(saddr);
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);

    if ((rawSocket = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        perror("Socket Error");
        return;
    }

    QoSStats stats = {0, 0, 0.0, 0.0, 0.0};

    while (1) {
        struct timeval start, end;
        gettimeofday(&start, NULL);

        int dataSize = recvfrom(rawSocket, buffer, BUFFER_SIZE, 0, &saddr, &saddr_len);
        if (dataSize < 0) {
            perror("Receive Error");
            continue;
        }

        gettimeofday(&end, NULL);
        calculateLatency(&stats, &start, &end);
        printQoSStats(&stats);
        printf("---------------------------------------------------\n");

        usleep(100000); // Sleep for 100ms
    }

    close(rawSocket);
    free(buffer);
}

int main() {
    printf("Starting Network Quality of Service Monitor...\n");
    monitorNetworkTraffic();
    return 0;
}