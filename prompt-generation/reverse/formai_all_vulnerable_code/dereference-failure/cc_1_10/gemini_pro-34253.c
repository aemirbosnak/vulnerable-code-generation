//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define ICMP_HEADER_LEN 8
#define ICMP_ECHO 8
#define ICMP_ECHOREPLY 0
#define ICMP_MAX_DATA 512

typedef struct {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t id;
    uint16_t sequence;
    uint32_t timestamp;
    uint8_t data[ICMP_MAX_DATA];
} icmp_header;

double time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <Hostname or IP Address>\n", argv[0]);
        return -1;
    }

    int sfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sfd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) != 1) {
        herror("inet_pton");
        close(sfd);
        return -1;
    }

    char *hostname = argv[1];
    if (strchr(hostname, ':') != NULL) {
        // IPv6 address
        addr.sin_port = htons(0xF00D);
        sfd = socket(AF_INET6, SOCK_RAW, IPPROTO_ICMPV6);
        if (sfd < 0) {
            perror("socket");
            close(sfd);
            return -1;
        }
    } else {
        // IPv4 address
        addr.sin_port = htons(0);
    }

    int seq = 0;
    while (1) {
        icmp_header header;
        memset(&header, 0, sizeof(header));
        header.type = ICMP_ECHO;
        header.code = 0;
        header.id = htons(getpid());
        header.sequence = htons(seq++);
        struct timeval start;
        gettimeofday(&start, NULL);
        memcpy(header.data, &start, sizeof(start));

        ssize_t sent = sendto(sfd, &header, sizeof(header), 0,
                              (struct sockaddr *) &addr, sizeof(addr));
        if (sent < 0) {
            perror("sendto");
            continue;
        }

        struct timeval now;
        fd_set readset;
        FD_ZERO(&readset);
        FD_SET(sfd, &readset);
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        int rc = select(sfd + 1, &readset, NULL, NULL, &timeout);
        if (rc < 0) {
            perror("select");
            continue;
        } else if (rc == 0) {
            printf("Request timed out\n");
            continue;
        }

        if (FD_ISSET(sfd, &readset)) {
            struct sockaddr_in raddr;
            socklen_t raddrlen = sizeof(raddr);
            ssize_t recv = recvfrom(sfd, &header, sizeof(header), 0,
                                    (struct sockaddr *) &raddr, &raddrlen);
            if (recv < 0) {
                perror("recvfrom");
                continue;
            }

            if (header.type != ICMP_ECHOREPLY || header.id != htons(getpid()) ||
                header.sequence != htons(seq - 1)) {
                continue;
            }

            gettimeofday(&now, NULL);
            double elapsed = time_diff(start, now);
            memcpy(&start, header.data, sizeof(start));
            double rtt = time_diff(start, now);

            printf("%s (%s): %.3f ms (%.3f ms rtt)\n", hostname, inet_ntoa(raddr.sin_addr),
                   elapsed * 1000, rtt * 1000);
        }
    }

    close(sfd);
    return 0;
}