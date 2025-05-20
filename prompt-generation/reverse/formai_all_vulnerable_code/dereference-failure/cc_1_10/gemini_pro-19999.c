//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/select.h>
#include <errno.h>

#define MAX_PACKET_SIZE 1024

struct ping_packet {
    uint16_t seq;
    uint32_t timestamp;
    char data[MAX_PACKET_SIZE - 8];
};

int create_socket(char *host, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return -1;
    }

    return sockfd;
}

int send_packet(int sockfd, struct sockaddr_in *servaddr, struct ping_packet *packet) {
    int n;

    n = sendto(sockfd, packet, sizeof(struct ping_packet), 0, (struct sockaddr *)servaddr, sizeof(struct sockaddr_in));
    if (n < 0) {
        perror("sendto");
        return -1;
    }

    return n;
}

int recv_packet(int sockfd, struct sockaddr_in *servaddr, struct ping_packet *packet) {
    int n;
    socklen_t len;

    len = sizeof(struct sockaddr_in);
    n = recvfrom(sockfd, packet, sizeof(struct ping_packet), 0, (struct sockaddr *)servaddr, &len);
    if (n < 0) {
        perror("recvfrom");
        return -1;
    }

    return n;
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct ping_packet packet;
    fd_set rfds;
    struct timeval tv;
    int n;
    int i;
    int seq;
    double avg_rtt;
    double min_rtt;
    double max_rtt;

    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return -1;
    }

    sockfd = create_socket(argv[1], atoi(argv[2]));
    if (sockfd < 0) {
        return -1;
    }

    memset(&packet, 0, sizeof(struct ping_packet));
    packet.timestamp = time(NULL);
    packet.seq = 0;
    for (i = 0; i < MAX_PACKET_SIZE - 8; i++) {
        packet.data[i] = 'a' + (i % 26);
    }

    avg_rtt = 0.0;
    min_rtt = 1000000.0;
    max_rtt = 0.0;
    for (i = 0; i < 10; i++) {
        printf("Sending packet %d\n", i + 1);
        if (send_packet(sockfd, &servaddr, &packet) < 0) {
            return -1;
        }

        FD_ZERO(&rfds);
        FD_SET(sockfd, &rfds);
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        n = select(sockfd + 1, &rfds, NULL, NULL, &tv);
        if (n == 0) {
            printf("Timeout\n");
            continue;
        }

        if (recv_packet(sockfd, &servaddr, &packet) < 0) {
            return -1;
        }

        avg_rtt += (time(NULL) - packet.timestamp) * 1000.0;
        min_rtt = fmin(min_rtt, (time(NULL) - packet.timestamp) * 1000.0);
        max_rtt = fmax(max_rtt, (time(NULL) - packet.timestamp) * 1000.0);

        seq++;
        printf("Received packet %d\n", seq);
    }

    printf("Average RTT: %.2f ms\n", avg_rtt / seq);
    printf("Minimum RTT: %.2f ms\n", min_rtt);
    printf("Maximum RTT: %.2f ms\n", max_rtt);

    close(sockfd);
    return 0;
}