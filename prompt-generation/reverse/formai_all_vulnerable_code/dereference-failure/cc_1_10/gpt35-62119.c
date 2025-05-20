//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

#define BUFF_SIZE 1024
#define PACKET_SIZE 64

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <destination>\n", argv[0]);
        exit(1);
    }

    struct addrinfo hints, *res, *p;
    char ipstr[INET6_ADDRSTRLEN];
    int status;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(2);
    }

    printf("Ping test to: %s\n", argv[1]);

    for (p = res; p != NULL; p = p->ai_next) {
        void *addr = NULL;
        char *ipver = NULL;
        if (p->ai_family == AF_INET) {
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        }
        else {
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf("  %s: %s\n", ipver, ipstr);

        int sockfd;
        if ((sockfd = socket(p->ai_family, SOCK_RAW, IPPROTO_ICMP)) == -1) {
            perror("socket");
            continue;
        }

        int sequence = 1;
        struct timespec timestamp;
        char sent_packet[PACKET_SIZE] = {0};
        char recv_packet[PACKET_SIZE] = {0};
        struct sockaddr_storage dest_addr;
        socklen_t addr_len;
        int timeouts = 0;
        int total_time = 0;
        int received_packets = 0;
        int sent_packets = 0;

        while (sent_packets < 10) {
            clock_gettime(CLOCK_MONOTONIC, &timestamp);
            snprintf(sent_packet, PACKET_SIZE, "PING %d %ld", sequence++, timestamp.tv_nsec);

            if (sendto(sockfd, sent_packet, PACKET_SIZE, 0, p->ai_addr, p->ai_addrlen) == -1) {
                perror("sendto");
                exit(3);
            }

            sent_packets++;

            struct timespec start_time;
            clock_gettime(CLOCK_MONOTONIC, &start_time);

            struct timeval timeout;
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;
            setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof timeout);

            if (recvfrom(sockfd, recv_packet, PACKET_SIZE, 0, (struct sockaddr *)&dest_addr, &addr_len) == -1) {
                printf("icmp_seq=%d timeout\n", sequence);
                timeouts++;
            }
            else {
                struct timespec end_time;
                clock_gettime(CLOCK_MONOTONIC, &end_time);

                int elapsed_time = (end_time.tv_nsec - start_time.tv_nsec) / 1000;
                total_time += elapsed_time;

                printf("icmp_seq=%d time=%dus\n", sequence, elapsed_time);
                received_packets++;
            }

            sleep(1);
        }

        float loss_rate = timeouts / (float)sent_packets * 100;
        float average_time = total_time / (float)received_packets;
        printf("\n--- %s ping statistics ---\n", ipstr);
        printf("%d packets transmitted, %d received, %.0f%% packet loss, time %dms\n", sent_packets, received_packets, loss_rate, total_time);
        printf("rtt min/avg/max/mdev = %d/%.2f/%d/%dus\n\n", 0, average_time, total_time, 0);

        close(sockfd);
    }

    freeaddrinfo(res);
    return 0;
}