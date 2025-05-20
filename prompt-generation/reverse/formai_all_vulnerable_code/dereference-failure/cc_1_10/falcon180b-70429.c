//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <time.h>

#define MAX_PKT_SIZE 1500
#define MAX_PACKETS 100
#define INTERVAL 10 // in milliseconds
#define THRESHOLD 50 // in milliseconds

int main(int argc, char *argv[]) {
    int sock, ret;
    struct sockaddr_in server_addr;
    char buffer[MAX_PKT_SIZE];
    int pkt_size;
    int pkt_count = 0;
    int lost_packets = 0;
    int jitter = 0;
    int rtt_avg = 0;
    int rtt_min = -1;
    int rtt_max = -1;
    struct timeval start, end;
    struct timeval prev_start, prev_end;
    double elapsed_time;

    if (argc!= 4) {
        printf("Usage: %s <IP address> <port> <duration>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    while (1) {
        pkt_size = rand() % MAX_PKT_SIZE + 1;
        ret = sendto(sock, buffer, pkt_size, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (ret == -1) {
            printf("Error sending packet\n");
            exit(1);
        }
        pkt_count++;

        if (pkt_count == 1) {
            gettimeofday(&start, NULL);
        } else if (pkt_count == MAX_PACKETS) {
            gettimeofday(&end, NULL);
            break;
        }
    }

    close(sock);

    if (pkt_count < MAX_PACKETS) {
        printf("Not enough packets received\n");
        exit(1);
    }

    elapsed_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
    printf("Total packets sent: %d\n", pkt_count);
    printf("Total packets received: %d\n", pkt_count);
    printf("Lost packets: %d\n", lost_packets);
    printf("Jitter: %d ms\n", jitter);
    printf("Round trip time (RTT) average: %d ms\n", rtt_avg);
    printf("Round trip time (RTT) minimum: %d ms\n", rtt_min);
    printf("Round trip time (RTT) maximum: %d ms\n", rtt_max);
    printf("Duration: %d ms\n", elapsed_time);

    return 0;
}