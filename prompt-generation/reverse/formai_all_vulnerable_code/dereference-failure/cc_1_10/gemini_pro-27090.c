//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/types.h>

#define MAX_PACKET_SIZE 1024
#define MAX_NUM_PACKETS 10000
#define MAX_NUM_THREADS 100

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    int num_packets;
    int num_bytes;
    double avg_rtt;
    double avg_throughput;
} thread_args;

void *thread_func(void *args) {
    thread_args *arg = (thread_args *)args;

    int sockfd = arg->sockfd;
    struct sockaddr_in addr = arg->addr;
    int num_packets = arg->num_packets;

    char buf[MAX_PACKET_SIZE];
    struct timeval start, end;
    double total_rtt = 0;
    int total_bytes = 0;

    for (int i = 0; i < num_packets; i++) {
        // Send packet
        gettimeofday(&start, NULL);
        int bytes_sent = sendto(sockfd, buf, MAX_PACKET_SIZE, 0, (struct sockaddr *)&addr, sizeof(addr));
        gettimeofday(&end, NULL);

        // Receive packet
        int bytes_recv = recvfrom(sockfd, buf, MAX_PACKET_SIZE, 0, NULL, NULL);

        // Calculate RTT
        double rtt = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
        total_rtt += rtt;

        // Increment bytes count
        total_bytes += bytes_sent + bytes_recv;
    }

    // Calculate average RTT and throughput
    arg->avg_rtt = total_rtt / num_packets;
    arg->avg_throughput = (double)total_bytes / (num_packets * MAX_PACKET_SIZE) * 8;

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <ip_address> <port> <num_packets>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);
    int num_packets = atoi(argv[3]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        return 1;
    }

    // Bind socket
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Create threads
    pthread_t threads[MAX_NUM_THREADS];
    thread_args args[MAX_NUM_THREADS];

    int num_threads = num_packets / 100;
    if (num_threads > MAX_NUM_THREADS) {
        num_threads = MAX_NUM_THREADS;
    }

    for (int i = 0; i < num_threads; i++) {
        args[i].sockfd = sockfd;
        args[i].addr = addr;
        args[i].num_packets = num_packets / num_threads;
        pthread_create(&threads[i], NULL, thread_func, &args[i]);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Calculate average RTT and throughput
    double avg_rtt = 0;
    double avg_throughput = 0;
    for (int i = 0; i < num_threads; i++) {
        avg_rtt += args[i].avg_rtt;
        avg_throughput += args[i].avg_throughput;
    }

    avg_rtt /= num_threads;
    avg_throughput /= num_threads;

    // Print results
    printf("Average RTT: %.2f ms\n", avg_rtt);
    printf("Average Throughput: %.2f Mbps\n", avg_throughput);

    // Close socket
    close(sockfd);

    return 0;
}