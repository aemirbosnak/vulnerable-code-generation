//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} socket_info;

typedef struct {
    int num_pkts;
    int num_bytes;
    double avg_latency;
    double max_latency;
    double min_latency;
} qos_stats;

static socket_info init_socket(const char *ip, int port) {
    socket_info info;
    memset(&info, 0, sizeof(info));

    info.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (info.sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    info.addr.sin_family = AF_INET;
    info.addr.sin_port = htons(port);
    info.addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(info.sockfd, (struct sockaddr *)&info.addr, sizeof(info.addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return info;
}

static qos_stats measure_qos(socket_info *info, int num_pkts) {
    char buf[MAX_BUF_SIZE];
    qos_stats stats;
    memset(&stats, 0, sizeof(stats));

    struct timeval start, end;
    long long total_latency_us = 0;

    for (int i = 0; i < num_pkts; i++) {
        memset(buf, 0, sizeof(buf));

        gettimeofday(&start, NULL);
        int len = send(info->sockfd, buf, sizeof(buf), 0);
        if (len < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        len = recv(info->sockfd, buf, sizeof(buf), 0);
        if (len < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        gettimeofday(&end, NULL);

        long long latency_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
        total_latency_us += latency_us;

        stats.num_pkts++;
        stats.num_bytes += len;
        if (i == 0) {
            stats.min_latency = latency_us;
            stats.max_latency = latency_us;
        } else {
            stats.min_latency = fmin(stats.min_latency, latency_us);
            stats.max_latency = fmax(stats.max_latency, latency_us);
        }
    }

    stats.avg_latency = (double)total_latency_us / num_pkts;

    return stats;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <ip> <port> <num_pkts>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    socket_info info = init_socket(argv[1], atoi(argv[2]));
    qos_stats stats = measure_qos(&info, atoi(argv[3]));

    printf("QoS Statistics:\n");
    printf("Number of packets: %d\n", stats.num_pkts);
    printf("Number of bytes: %d\n", stats.num_bytes);
    printf("Average latency: %.2f ms\n", stats.avg_latency / 1000);
    printf("Minimum latency: %.2f ms\n", stats.min_latency / 1000);
    printf("Maximum latency: %.2f ms\n", stats.max_latency / 1000);

    close(info.sockfd);

    return EXIT_SUCCESS;
}