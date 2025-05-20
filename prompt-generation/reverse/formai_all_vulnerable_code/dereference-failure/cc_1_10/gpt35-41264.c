//FormAI DATASET v1.0 Category: Network Ping Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFSIZE 1500

int ping(char *host, int timeout, int count);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ping <host>\n");
        exit(1);
    }
    ping(argv[1], 1000, 5);
    return 0;
}

int ping(char *host, int timeout, int count) {
    struct sockaddr_in addr;
    struct hostent *host_info;
    struct icmphdr icmp_hdr;
    char send_buf[BUFSIZE];
    char recv_buf[BUFSIZE];
    int sockfd, seq = 0, recv_cnt = 0;
    struct timeval start, end, tv;

    memset(&icmp_hdr, 0, sizeof(struct icmphdr));
    icmp_hdr.type = ICMP_ECHO;
    icmp_hdr.code = 0;
    icmp_hdr.un.echo.id = getpid();

    host_info = gethostbyname(host);
    if (!host_info) {
        printf("ping: unknown host %s\n", host);
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    memcpy(&addr.sin_addr, host_info->h_addr_list[0], host_info->h_length);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("ping: socket");
        return -1;
    }

    while (count--) {
        seq++;
        setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
        memcpy(&send_buf, &icmp_hdr, sizeof(struct icmphdr));
        memcpy(&send_buf[sizeof(struct icmphdr)], &seq, sizeof(seq));
        gettimeofday(&start, NULL);
        if (sendto(sockfd, &send_buf, sizeof(send_buf), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("ping: sendto");
            continue;
        }
        tv.tv_sec = timeout / 1000;
        tv.tv_usec = (timeout % 1000) * 1000;
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        int nready = select(sockfd + 1, &readfds, NULL, NULL, &tv);
        gettimeofday(&end, NULL);
        if (nready < 0) {
            perror("ping: select");
            continue;
        } else if (nready == 0) {
            printf("Timeout on icmp_seq %d\n", seq);
            continue;
        }
        if (recvfrom(sockfd, &recv_buf, sizeof(recv_buf), 0, NULL, NULL) < 0) {
            perror("ping: recvfrom");
            continue;
        }
        recv_cnt++;
        struct icmphdr *icmp_hdr_ptr = (struct icmphdr *)recv_buf;
        if (icmp_hdr_ptr->type == ICMP_ECHOREPLY && icmp_hdr_ptr->code == 0 && icmp_hdr_ptr->un.echo.id == getpid()) {
            int rtt = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
            struct in_addr s_addr;
            memcpy(&s_addr, &recv_buf[sizeof(struct iphdr)], sizeof(struct in_addr));
            printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%d ms\n", sizeof(recv_buf) - sizeof(struct iphdr), inet_ntoa(s_addr), seq, recv_buf[sizeof(struct iphdr) + sizeof(struct icmphdr) * 2 + sizeof(int)], rtt);
        } else {
            printf("Received ICMP packet with type %d and code %d\n", icmp_hdr_ptr->type, icmp_hdr_ptr->code);
        }
        sleep(1);
    }

    printf("--- %s ping statistics ---\n", host);
    printf("%d packets transmitted, %d packets received, %.0f%% packet loss\n", seq, recv_cnt, ((seq - recv_cnt) * 100.0 / seq));

    close(sockfd);
    return 0;
}