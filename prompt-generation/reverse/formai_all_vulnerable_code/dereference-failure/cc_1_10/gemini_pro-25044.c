//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

struct ping_packet {
    uint16_t type;
    uint16_t code;
    uint16_t checksum;
    uint16_t id;
    uint16_t seq_num;
    char data[BUFSIZE];
};

int checksum(struct ping_packet *packet) {
    int sum = 0;
    uint16_t *words = (uint16_t *)packet;
    for (size_t i = 0; i < sizeof(struct ping_packet) / sizeof(uint16_t); i++) {
        sum += words[i];
    }
    while (sum >> 16) {
        sum = (sum >> 16) + (sum & 0xFFFF);
    }
    return ~sum;
}

int create_ping_socket() {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }
    int on = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) == -1) {
        perror("setsockopt");
        return -1;
    }
    return sockfd;
}

int send_ping(int sockfd, struct sockaddr_in *dst, char *buffer, size_t buffer_size) {
    struct ping_packet packet = {
        .type = 8,
        .code = 0,
        .checksum = 0,
        .id = getpid(),
        .seq_num = 0,
    };
    memcpy(packet.data, buffer, buffer_size);
    packet.checksum = checksum(&packet);
    ssize_t sent = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)dst, sizeof(*dst));
    if (sent == -1) {
        perror("sendto");
        return -1;
    }
    return 0;
}

int receive_ping(int sockfd, struct sockaddr_in *src, char *buffer, size_t buffer_size) {
    socklen_t addrlen = sizeof(*src);
    ssize_t received = recvfrom(sockfd, buffer, buffer_size, 0, (struct sockaddr *)src, &addrlen);
    if (received == -1) {
        perror("recvfrom");
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <destination IP> <message>\n", argv[0]);
        return 1;
    }
    struct sockaddr_in dst;
    memset(&dst, 0, sizeof(dst));
    dst.sin_family = AF_INET;
    dst.sin_addr.s_addr = inet_addr(argv[1]);
    int sockfd = create_ping_socket();
    if (sockfd == -1) {
        return 1;
    }
    char buffer[BUFSIZE];
    memset(buffer, 0, BUFSIZE);
    strncpy(buffer, argv[2], strlen(argv[2]));
    if (send_ping(sockfd, &dst, buffer, strlen(buffer)) == -1) {
        close(sockfd);
        return 1;
    }
    struct sockaddr_in src;
    memset(&src, 0, sizeof(src));
    if (receive_ping(sockfd, &src, buffer, BUFSIZE) == -1) {
        close(sockfd);
        return 1;
    }
    struct ping_packet *packet = (struct ping_packet *)buffer;
    if (packet->type != 0 || packet->code != 0) {
        printf("Received an ICMP error message.\n");
    } else {
        printf("Received a ping response from %s: seq=%d time=%.3f ms\n",
            inet_ntoa(src.sin_addr), packet->seq_num,
            (double)packet->data[0] * 1000.0 / 256.0);
    }
    close(sockfd);
    return 0;
}