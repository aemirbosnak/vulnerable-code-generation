//FormAI DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int sockfd, packets;
    size_t size;
    double elapsed_time_ms;
    struct addrinfo hints, *res, *p;
    struct timespec start_time, end_time;
    char buffer[100];

    if (argc != 3) {
        printf("Usage: %s <hostname/IP address> <number of packets>\n", argv[0]);
        return 1;
    }

    packets = atoi(argv[2]);
    size = sizeof(buffer);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;

    if (getaddrinfo(argv[1], "http", &hints, &res) != 0) {
        printf("%s is not a valid IP address or hostname.\n", argv[1]);
        return 1;
    }

    for (p = res; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        break;
    }

    if (p == NULL) {
        printf("Failed to create socket.\n");
        return 1;
    }

    memset(buffer, 0, sizeof(buffer));

    clock_gettime(CLOCK_REALTIME, &start_time);

    for (int i = 1; i <= packets; i++) {
        sendto(sockfd, buffer, size, 0, p->ai_addr, p->ai_addrlen);
        usleep(100000); // wait some time before sending next packet
    }

    clock_gettime(CLOCK_REALTIME, &end_time);

    elapsed_time_ms = (end_time.tv_sec - start_time.tv_sec) * 1000.0;
    elapsed_time_ms += (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0;

    printf("Sent %d packets in %.2f milliseconds.\n", packets, elapsed_time_ms);

    freeaddrinfo(res);
    close(sockfd);

    return 0;
}