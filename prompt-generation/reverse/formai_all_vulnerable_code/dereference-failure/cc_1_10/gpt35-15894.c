//FormAI DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <time.h>

#define PACKETSIZE 64

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }

    if (len == 1) {
        sum += *(unsigned char *)buf;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

double time_diff(struct timeval *a, struct timeval *b) {
    double diff = (b->tv_sec - a->tv_sec) * 1000.0;
    diff += (b->tv_usec - a->tv_usec) / 1000.0;
    return diff;
}

int main(int argc, char **argv) {
    struct sockaddr_in addr_ping, addr_pong;
    struct timeval start, stop, response;
    int s, i, packetsize = PACKETSIZE, ack = 0, received = 0, sent = 0;
    char *packet, *pong;
    double rtt_min, rtt_max, rtt_avg, rtt_ms;
    struct hostent *hname;
    struct iphdr *ip;
    struct icmphdr *icmp;

    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    if ((hname = gethostbyname(argv[1])) == NULL) {
        perror("Error: Cannot resolve specified hostname");
        exit(1);
    }

    s = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (s < 0) {
        perror("socket failed");
        exit(1);
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = hname->h_addr_list[0][0];

    packet = malloc(packetsize);
    pong = malloc(packetsize);

    memset(packet, 0, packetsize);
    memset(pong, 0, packetsize);

    icmp = (struct icmphdr *) packet;
    icmp->type = ICMP_ECHO;
    icmp->code = 0;
    icmp->checksum = 0;
    icmp->un.echo.id = getpid();

    for (i = 0; i < packetsize - 8; i++) {
        packet[i + 8] = i % 26 + 'A';
    }

    srand(time(NULL));

    while (sent < 5) {
        icmp->un.echo.sequence = sent++;
        icmp->checksum = 0;
        icmp->checksum = checksum(packet, packetsize);

        gettimeofday(&start, NULL);

        if (sendto(s, packet, packetsize, 0, (struct sockaddr *) &addr_ping, sizeof(addr_ping)) <= 0) {
            perror("sendto failed");
            ack = 0;
        } else {
            response.tv_sec = 2;
            response.tv_usec = 0;
            fd_set fds;
            FD_ZERO(&fds);
            FD_SET(s, &fds);

            ack = select(s + 1, &fds, NULL, NULL, &response);

            if (ack > 0) {
                if (recvfrom(s, pong, packetsize, 0, (struct sockaddr *) &addr_pong,
                             (socklen_t *) &packetsize) > 0) {
                    ip = (struct iphdr *) pong;
                    if (ip->protocol != IPPROTO_ICMP) {
                        continue;
                    }
                    icmp = (struct icmphdr *) (pong + ip->ihl * 4);
                    if ((icmp->type == ICMP_ECHOREPLY) && (icmp->un.echo.id == getpid())) {
                        received++;
                        gettimeofday(&stop, NULL);
                        rtt_ms = time_diff(&start, &stop);
                        if (received == 1) {
                            rtt_min = rtt_max = rtt_avg = rtt_ms;
                        } else {
                            rtt_min = (rtt_min > rtt_ms) ? rtt_ms : rtt_min;
                            rtt_max = (rtt_max < rtt_ms) ? rtt_ms : rtt_max;
                            rtt_avg += rtt_ms;
                        }
                        printf("%d bytes from %s (%s) seq=%d time=%0.2f ms\n",
                               packetsize, argv[1], inet_ntoa(addr_pong.sin_addr), sent - 1, rtt_ms);
                    }
                }
            } else {
                printf("Request timed out.\n");
            }
        }
        sleep(rand() % 3 + 1);
    }

    if (received == 0) {
        printf("No replies received.\n");
    } else {
        rtt_avg = rtt_avg / received;
        printf("\n%d packets transmitted, %d received, %.0f%% packet loss\n", sent, received,
               ((sent - received) / (float) sent) * 100.0);
        printf("rtt min/avg/max = %0.2f/%0.2f/%0.2f ms\n", rtt_min, rtt_avg, rtt_max);
    }

    free(packet);
    free(pong);
    close(s);
    return 0;
}