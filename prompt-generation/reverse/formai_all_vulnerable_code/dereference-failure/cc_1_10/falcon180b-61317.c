//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_PKT_SIZE 1500
#define MAX_PKTS_PER_SEC 1000
#define MAX_RTT_MS 100

struct pkt_stats {
    int num_pkts;
    int num_lost_pkts;
    int num_dup_pkts;
    int rtt_ms;
};

int main(int argc, char *argv[]) {
    int sock, ret;
    struct sockaddr_in server_addr;
    char *server_ip = "192.168.1.1";
    int server_port = 80;
    int pkt_size = MAX_PKT_SIZE;
    int num_pkts = 100;
    int pkts_per_sec = MAX_PKTS_PER_SEC;
    int rtt_ms = MAX_RTT_MS;
    int i, j, k;
    char *send_buf;
    char *recv_buf;
    struct timeval start_time, end_time, diff_time;
    struct pkt_stats stats;

    send_buf = malloc(pkt_size);
    recv_buf = malloc(pkt_size);

    if (send_buf == NULL || recv_buf == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    for (i = 0; i < num_pkts; i++) {
        for (j = 0; j < pkts_per_sec; j++) {
            gettimeofday(&start_time, NULL);

            for (k = 0; k < pkt_size; k++) {
                send_buf[k] = 'A' + i * pkt_size + j * pkt_size + k;
            }

            ret = sendto(sock, send_buf, pkt_size, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
            if (ret!= pkt_size) {
                stats.num_lost_pkts++;
            }

            gettimeofday(&end_time, NULL);
            timersub(&end_time, &start_time, &diff_time);

            if (diff_time.tv_usec > 1000000) {
                stats.rtt_ms += diff_time.tv_usec / 1000;
            }
        }
    }

    close(sock);

    printf("Number of packets sent: %d\n", num_pkts);
    printf("Number of lost packets: %d\n", stats.num_lost_pkts);
    printf("Round trip time (ms): %d\n", stats.rtt_ms);

    free(send_buf);
    free(recv_buf);

    return 0;
}