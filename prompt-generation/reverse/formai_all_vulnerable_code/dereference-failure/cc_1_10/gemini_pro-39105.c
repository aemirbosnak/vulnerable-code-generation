//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <signal.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define PING_TIMEOUT_SEC 1
#define PING_TIMEOUT_USEC 0

static volatile int got_reply = 0;

void sigalrm_handler(int signo) {
    got_reply = 1;
}

int send_ping(int sockfd, struct sockaddr_in *addr, size_t packet_size) {
    char *packet = malloc(packet_size);
    if (!packet) {
        return -1;
    }

    struct timeval start_time;
    gettimeofday(&start_time, NULL);

    memset(packet, 0, packet_size);
    packet[0] = ICMP_ECHO_REQUEST;
    packet[1] = 0;  // code
    packet[2] = 0;  // checksum
    *(uint16_t *)(packet + 4) = getpid();

    int bytes_sent = sendto(sockfd, packet, packet_size, 0, (struct sockaddr *)addr, sizeof(*addr));
    if (bytes_sent < 0) {
        free(packet);
        return -1;
    }

    got_reply = 0;
    alarm(PING_TIMEOUT_SEC);

    struct timeval end_time;
    gettimeofday(&end_time, NULL);

    if (!got_reply) {
        free(packet);
        return -1;
    }

    double elapsed = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;
    printf("Reply from %s: bytes=%d time=%f ms\n", inet_ntoa(addr->sin_addr), bytes_sent, elapsed);

    free(packet);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <ip_address> <packet_size>\n", argv[0]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    int packet_size = atoi(argv[2]);
    if (packet_size <= 0 || packet_size > 65535) {
        printf("Invalid packet size: %s\n", argv[2]);
        close(sockfd);
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    signal(SIGALRM, sigalrm_handler);

    int num_pings = 10;
    for (int i = 0; i < num_pings; i++) {
        if (send_ping(sockfd, &addr, packet_size)) {
            printf("Failed to send ping to %s\n", argv[1]);
            break;
        }
    }

    close(sockfd);
    return 0;
}