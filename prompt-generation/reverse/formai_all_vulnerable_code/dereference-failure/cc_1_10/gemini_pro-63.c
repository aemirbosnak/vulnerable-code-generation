//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <pthread.h>
#include <time.h>

#define BUF_SIZE 1024

struct sockaddr_in addr;

struct timeval start_time;
struct timeval end_time;

int sockfd;
int running = 1;

float latency = 0.0f;
float jitter = 0.0f;
float packet_loss = 0.0f;

int rx = 0;
int tx = 0;
int drop = 0;

void *recv_thread(void *arg);
void *tx_thread(void *arg);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    pthread_t recv_thread_id;
    pthread_t tx_thread_id;

    gettimeofday(&start_time);

    pthread_create(&recv_thread_id, NULL, recv_thread, NULL);
    pthread_create(&tx_thread_id, NULL, tx_thread, NULL);

    while (running) {
        sleep(1);

        if (tx > 0) {
            latency += (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0f;

            if (jitter > 0.0f) {
                jitter = (latency - jitter) / 2.0f + jitter;
            } else {
                jitter = latency;
            }

            packet_loss = (1.0f - ((float)rx / tx)) * 100.0f;

            printf("Latency: %.2fms Jitter: %.2fms Packet Loss: %.2f%%\n", latency, jitter, packet_loss);
        }
    }

    pthread_join(recv_thread_id, NULL);
    pthread_join(tx_thread_id, NULL);

    close(sockfd);

    return 0;
}

void *recv_thread(void *arg) {
    while (running) {
        struct sockaddr_in from;
        socklen_t fromlen = sizeof(from);

        unsigned char buf[BUF_SIZE];
        int recv_len = recvfrom(sockfd, buf, BUF_SIZE, 0, (struct sockaddr *)&from, &fromlen);

        if (recv_len == -1) {
            perror("recvfrom");
            continue;
        }

        if (recv_len >= sizeof(struct icmphdr)) {
            struct icmphdr *icmp_hdr = (struct icmphdr *)buf;

            if (icmp_hdr->type == ICMP_ECHOREPLY) {
                gettimeofday(&end_time);

                rx++;
            }
        }
    }

    return NULL;
}

void *tx_thread(void *arg) {
    unsigned char buf[BUF_SIZE];

    while (running) {
        struct icmphdr *icmp_hdr = (struct icmphdr *)buf;

        icmp_hdr->type = ICMP_ECHO;
        icmp_hdr->code = 0;
        icmp_hdr->checksum = 0;

        icmp_hdr->un.echo.id = getpid();
        icmp_hdr->un.echo.sequence = tx++;

        gettimeofday(&start_time);

        int send_len = sendto(sockfd, buf, sizeof(struct icmphdr), 0, (struct sockaddr *)&addr, sizeof(addr));

        if (send_len == -1) {
            perror("sendto");
            continue;
        }

        sleep(1);

        drop++;
    }

    return NULL;
}