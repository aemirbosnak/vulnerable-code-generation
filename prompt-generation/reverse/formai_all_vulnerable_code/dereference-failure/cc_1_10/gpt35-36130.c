//FormAI DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <errno.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define ICMP_HEADER_LEN 8

volatile int ping_loop;
struct timeval tv_begin, tv_end;

void intHandler(int dummy)
{
    ping_loop = 0;
}

unsigned short checksum(unsigned short *buf, int nword)
{
    unsigned long sum;
    unsigned short oddbyte;
    unsigned short answer;

    sum = 0;
    while(nword > 1){
        sum += *buf++;
        nword -= 2;
    }
    if(nword == 1){
        oddbyte = 0;
        *((unsigned char *) &oddbyte) = *(unsigned char *)buf;
        sum += oddbyte;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = (unsigned short) ~sum;

    return answer;
}

int recv_packet(int sockfd, struct sockaddr_in *addr)
{
    char recvbuf[1500];
    int ret;
    socklen_t addrlen = sizeof(struct sockaddr);

    ret = recvfrom(sockfd, recvbuf, sizeof(recvbuf), 0, (struct sockaddr*)addr, &addrlen);
    if (ret < 0) {
        printf("Error receiving packet: %s\n", strerror(errno));
        return -1;
    }

    return ret;
}

void send_packet(int sockfd, struct sockaddr_in *dest_addr)
{
    int bytes, n;
    char sendbuf[ICMP_HEADER_LEN], recvbuf[1500];

    struct icmphdr *icmphd;
    icmphd = (struct icmphdr *)sendbuf;

    icmphd->type = ICMP_ECHO_REQUEST;
    icmphd->code = 0;
    icmphd->checksum = 0;
    icmphd->un.echo.id = getpid();
    icmphd->un.echo.sequence = n++;

    gettimeofday(&tv_begin, NULL);
    icmphd->checksum = checksum((unsigned short *)icmphd, ICMP_HEADER_LEN);

    bytes = sendto(sockfd, sendbuf, ICMP_HEADER_LEN, 0, (struct sockaddr*)dest_addr, sizeof(*dest_addr));
    if (bytes < 0) {
        printf("Error sending packet: %s\n", strerror(errno));
    }
}

int ping_test(char *dest)
{
    struct hostent *hp;
    struct sockaddr_in dest_addr;
    int sockfd, ttl;
    float round_time;
    unsigned int pkg_sent = 0, pkg_recv = 0;

    signal(SIGINT, intHandler);

    hp = gethostbyname(dest);
    if (hp == NULL) {
        printf("Error resolving host: %s\n", strerror(h_errno));
        return -1;
    }

    memset(&dest_addr, 0, sizeof(struct sockaddr_in));
    dest_addr.sin_family = AF_INET;
    memcpy(&dest_addr.sin_addr.s_addr, hp->h_addr, hp->h_length);

    printf("PING %s (%s) 56(84) bytes of data.\n", dest, inet_ntoa(dest_addr.sin_addr));

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd < 0) {
        printf("Error creating raw socket: %s\n", strerror(errno));
        return -1;
    }

    while(ping_loop) {
        ttl = 64;
        setsockopt(sockfd, SOL_IP, IP_TTL, &ttl, sizeof(ttl));

        send_packet(sockfd, &dest_addr);

        pkg_sent++;

        if(recv_packet(sockfd, &dest_addr) > 0) {
            pkg_recv++;
            gettimeofday(&tv_end,NULL);
            round_time = (tv_end.tv_sec-tv_begin.tv_sec)*1000.0 + (tv_end.tv_usec-tv_begin.tv_usec)/1000.0;
            printf("%d bytes from %s: icmp_req=%d ttl=%d time=%.2f ms\n",
                   ICMP_HEADER_LEN, inet_ntoa(dest_addr.sin_addr), pkg_recv, ttl, round_time);
            sleep(1);
        } else {
            printf("Error: ping timed out\n");
            sleep(1);
        }
    }

    printf("\n--- %s ping statistics ---\n", dest);
    printf("%d packets transmitted, %d received, %%%d packet loss, time %dms\n",
           pkg_sent, pkg_recv, (pkg_sent-pkg_recv)*100/pkg_sent, (int)(round_time+0.5));
    close(sockfd);

    return 0;
}

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Usage: %s <dest_ip>\n", argv[0]);
        return -1;
    }

    ping_loop = 1;

    ping_test(argv[1]);

    return 0;
}