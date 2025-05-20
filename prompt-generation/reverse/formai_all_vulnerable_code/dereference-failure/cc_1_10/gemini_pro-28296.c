//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PING_DATA_SIZE 56
#define PING_TIMEOUT 1000

typedef struct {
    char data[PING_DATA_SIZE];
    struct timeval sent_time;
    struct timeval recv_time;
} ping_packet;

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct addrinfo *res;
    if (getaddrinfo(argv[1], NULL, NULL, &res) != 0) {
        fprintf(stderr, "Error: getaddrinfo() failed\n");
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "Error: socket() failed\n");
        exit(EXIT_FAILURE);
    }

    ping_packet packet;
    memset(&packet, 0, sizeof(packet));
    packet.data[0] = 'P';
    packet.data[1] = 'I';
    packet.data[2] = 'N';
    packet.data[3] = 'G';
    gettimeofday(&packet.sent_time, NULL);

    int sent_bytes = sendto(sockfd, &packet, sizeof(packet), 0, res->ai_addr, res->ai_addrlen);
    if (sent_bytes == -1) {
        fprintf(stderr, "Error: sendto() failed\n");
        exit(EXIT_FAILURE);
    }

    fd_set readfds;
    struct timeval timeout;
    timeout.tv_sec = PING_TIMEOUT / 1000;
    timeout.tv_usec = (PING_TIMEOUT % 1000) * 1000;

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    int recv_bytes = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
    if (recv_bytes == -1) {
        fprintf(stderr, "Error: select() failed\n");
        exit(EXIT_FAILURE);
    } else if (recv_bytes == 0) {
        fprintf(stderr, "Error: ping timed out\n");
        exit(EXIT_FAILURE);
    }

    recv_bytes = recvfrom(sockfd, &packet, sizeof(packet), 0, NULL, NULL);
    if (recv_bytes == -1) {
        fprintf(stderr, "Error: recvfrom() failed\n");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&packet.recv_time, NULL);
    double rtt = (packet.recv_time.tv_sec - packet.sent_time.tv_sec) * 1000.0 +
                 (packet.recv_time.tv_usec - packet.sent_time.tv_usec) / 1000.0;

    printf("Round-trip time: %.3f ms\n", rtt);

    freeaddrinfo(res);
    close(sockfd);

    return EXIT_SUCCESS;
}