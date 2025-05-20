//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT 1

typedef struct {
    char *address;
    int count;
} ping_args;

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void *ping(void *arguments) {
    ping_args *args = (ping_args *)arguments;
    struct icmphdr packet;
    struct sockaddr_in addr;
    struct timespec start, end;
    int sockfd, i;
    socklen_t addr_len = sizeof(addr);
    char buf[PACKET_SIZE];
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, args->address, &addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sockfd);
        return NULL;
    }

    for (i = 0; i < args->count; i++) {
        memset(&packet, 0, sizeof(packet));
        packet.type = ICMP_ECHO;
        packet.un.echo.id = getpid();
        packet.un.echo.sequence = i + 1;
        packet.checksum = checksum(&packet, sizeof(packet));

        clock_gettime(CLOCK_MONOTONIC, &start);
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Send failed");
            continue;
        }

        fd_set readset;
        struct timeval tv;
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        FD_ZERO(&readset);
        FD_SET(sockfd, &readset);

        if (select(sockfd + 1, &readset, NULL, NULL, &tv) > 0) {
            if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, &addr_len) > 0) {
                clock_gettime(CLOCK_MONOTONIC, &end);
                long rtt = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;

                printf("Ping to %s: %ld ms\n", args->address, rtt);
            } else {
                perror("Receive failed");
            }
        } else {
            printf("Request timed out for %s\n", args->address);
        }
        sleep(1);
    }

    close(sockfd);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip1> <ip2> ... <count>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int ping_count = atoi(argv[argc - 1]);
    pthread_t threads[argc - 2];
    ping_args args[argc - 2];

    for (int i = 1; i < argc - 1; i++) {
        args[i - 1].address = argv[i];
        args[i - 1].count = ping_count;
        if (pthread_create(&threads[i - 1], NULL, ping, &args[i - 1]) != 0) {
            perror("Thread creation failed");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < argc - 2; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}