//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: decentralized
#include <stdlib.h> // malloc, free
#include <stdint.h> // uint8_t, uint16_t, uint32_t
#include <stdbool.h> // bool
#include <unistd.h> // getpid
#include <sys/socket.h> // socket, connect, sendto, recvfrom, close
#include <arpa/inet.h> // inet_addr

typedef struct {
    uint32_t timestamp;
    uint16_t identifier;
    uint16_t sequence;
} ping_packet;

typedef struct {
    uint32_t sent;
    uint32_t received;
    float min_rtt;
    float max_rtt;
    float avg_rtt;
} ping_stats;


bool ping(const char *host, unsigned int count, unsigned int timeout) {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr(host),
    };

    ping_packet *packets = malloc(sizeof(ping_packet) * count);
    ping_stats stats = {
        .sent = 0,
        .received = 0,
        .min_rtt = -1.0f,
        .max_rtt = -1.0f,
        .avg_rtt = 0.0f,
    };

    for (unsigned int i = 0; i < count; i++) {
        packets[i].timestamp = time(NULL);
        packets[i].identifier = getpid();
        packets[i].sequence = i;
        sendto(sockfd, &packets[i], sizeof(ping_packet), 0, (struct sockaddr *)&addr, sizeof(addr));
        stats.sent++;
    }

    fd_set rset;
    FD_ZERO(&rset);
    struct timeval tv = {
        .tv_sec = timeout,
        .tv_usec = 0,
    };

    while (stats.received < count) {
        FD_SET(sockfd, &rset);
        select(sockfd + 1, &rset, NULL, NULL, &tv);
        if (FD_ISSET(sockfd, &rset)) {
            ping_packet packet;
            socklen_t addrlen = sizeof(addr);
            recvfrom(sockfd, &packet, sizeof(ping_packet), 0, (struct sockaddr *)&addr, &addrlen);
            if (packet.identifier == getpid() && packet.sequence < count) {
                float rtt = difftime(time(NULL), packet.timestamp);
                if (stats.min_rtt < 0.0f || rtt < stats.min_rtt) {
                    stats.min_rtt = rtt;
                }
                if (stats.max_rtt < 0.0f || rtt > stats.max_rtt) {
                    stats.max_rtt = rtt;
                }
                stats.avg_rtt += rtt;
                stats.received++;
            }
        } else {
            break;
        }
    }

    free(packets);
    close(sockfd);

    printf("Ping statistics for %s:\n", host);
    printf("  Packets: Sent = %u, Received = %u, Lost = %u (%.2f%% loss)\n",
        stats.sent, stats.received, stats.sent - stats.received,
        100.0f * (stats.sent - stats.received) / stats.sent);
    if (stats.received > 0) {
        stats.avg_rtt /= (float)stats.received;
        printf("  RTT: Min = %.3f ms, Max = %.3f ms, Avg = %.3f ms\n",
            stats.min_rtt * 1000.0f, stats.max_rtt * 1000.0f, stats.avg_rtt * 1000.0f);
    } else {
        printf("  RTT: No responses received\n");
    }

    return stats.received > 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host> <count>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int count = atoi(argv[2]);
    unsigned int timeout = 1;

    if (ping(argv[1], count, timeout)) {
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}