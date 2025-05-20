//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/types.h>

#define MAX_HOPS 30
#define MAX_SIZE 1024
#define PORT 32768

struct packet {
    int hop;
    struct timeval send_time;
    struct timeval recv_time;
    char data[MAX_SIZE];
};

void usage(char *prog) {
    fprintf(stderr, "usage: %s <destination> <num_packets>\n", prog);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 3)
        usage(argv[0]);

    int num_packets = atoi(argv[2]);
    if (num_packets <= 0 || num_packets > 100)
        usage(argv[0]);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    for (int i = 0; i < num_packets; i++) {
        struct packet packet;
        packet.hop = 0;
        gettimeofday(&packet.send_time, NULL);
        sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *) &addr, sizeof(addr));
    }

    int hops = 0;
    int recvd = 0;
    int total_time = 0;
    while (recvd < num_packets) {
        struct sockaddr_in from_addr;
        socklen_t from_len = sizeof(from_addr);
        struct packet packet;
        recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *) &from_addr, &from_len);
        if (packet.hop > hops) {
            hops = packet.hop;
            printf("TTL reached %d\n", hops);
        }
        gettimeofday(&packet.recv_time, NULL);
        total_time += (packet.recv_time.tv_usec - packet.send_time.tv_usec) + 1000000 * (packet.recv_time.tv_sec - packet.send_time.tv_sec);
        recvd++;
    }
    gettimeofday(&end_time, NULL);

    close(sockfd);
    int elapsed_time = (end_time.tv_usec - start_time.tv_usec) + 1000000 * (end_time.tv_sec - start_time.tv_sec);

    float avg_time = (float) total_time / num_packets;

    printf("Average round-trip time: %f ms\n", avg_time / 1000.0);
    printf("Elapsed time: %d ms\n", elapsed_time);
    return 0;
}