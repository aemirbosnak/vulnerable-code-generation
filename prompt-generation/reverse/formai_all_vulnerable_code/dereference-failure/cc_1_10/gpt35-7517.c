//FormAI DATASET v1.0 Category: Network Ping Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>

#define BUFSIZE 1500

int send_ping(int sockfd, struct sockaddr_in *address, int ttl);

int main(int argc, char *argv[]) {

    int sockfd, ttl, i, ping_count = 10, timeout = 3000;
    struct sockaddr_in address;
    struct hostent *hostinfo;

    if(argc != 2) {
        printf("Usage: ./pingtest <host>\n");
        exit(1);
    }

    if((hostinfo = gethostbyname(argv[1])) == NULL) {
        printf("Unable to resolve host %s\n", argv[1]);
        exit(1);
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr = *((struct in_addr *) hostinfo->h_addr);

    if((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Error creating raw socket");
        exit(1);
    }

    if(setsockopt(sockfd, SOL_IP, IP_TTL, &ttl, sizeof(ttl)) != 0) {
        perror("Error setting TTL");
        exit(1);
    }

    printf("Sending %d pings to %s with a timeout of %d ms.\n", ping_count, argv[1], timeout);

    for(i = 0; i < ping_count; i++) {
        if(send_ping(sockfd, &address, ttl) == -1) {
            printf("Ping %d failed!\n", i+1);
        }
        usleep(timeout*1000);
    }

    close(sockfd);

    return 0;
}

int send_ping(int sockfd, struct sockaddr_in *address, int ttl) {

    struct icmp icmp_hdr;
    struct timeval t1, t2;
    socklen_t slen;
    int recvlen, msglen, i;
    char recvbuf[BUFSIZE], sendbuf[BUFSIZE], addr[INET_ADDRSTRLEN];

    memset(&icmp_hdr, 0, sizeof(icmp_hdr));
    icmp_hdr.icmp_type = ICMP_ECHO;
    icmp_hdr.icmp_code = 0;
    icmp_hdr.icmp_id = getpid() & 0xFFFF;
    icmp_hdr.icmp_seq = (unsigned short int) 0;
    memset(&sendbuf, 0, BUFSIZE);
    memcpy(sendbuf, &icmp_hdr, sizeof(icmp_hdr));
    gettimeofday(&t1, NULL);
    msglen = sizeof(icmp_hdr);

    if(sendto(sockfd, sendbuf, msglen, 0, (struct sockaddr *) address, sizeof(*address)) <= 0) {
        perror("Error sending ping");
        return -1;
    }

    slen = sizeof(address);
    if((recvlen = recvfrom(sockfd, recvbuf, BUFSIZE, 0, (struct sockaddr *) address, &slen)) <= 0) {
        perror("Error receiving ping");
        return -1;
    }

    gettimeofday(&t2, NULL);
    long double ms = (long double) (t2.tv_sec - t1.tv_sec) * 1000.0 + (long double) (t2.tv_usec - t1.tv_usec) / 1000.0;
    inet_ntop(AF_INET, &(address->sin_addr), addr, INET_ADDRSTRLEN);

    printf("Reply from %s: icmp_seq=%u ttl=%d time=%.2Lf ms\n", addr, icmp_hdr.icmp_seq, ttl, ms);

    return 0;
}