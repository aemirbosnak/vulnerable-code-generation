//FormAI DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0

typedef struct {
    unsigned char type;
    unsigned char code;
    unsigned short checksum;
    unsigned short id;
    unsigned short sequence;
    time_t timestamp;
} icmpheader;

unsigned short calculate_checksum(unsigned short *ptr, int len);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: ./ping <ip address>\n");
        exit(1);
    }

    struct hostent *host;
    struct sockaddr_in addr_dest;
    int sockfd;
    char buf[1024];
    int seq = 0;
    time_t start_time, end_time, delay;

    host = gethostbyname(argv[1]);
    if(host == NULL) {
        fprintf(stderr, "Could not get hostname\n");
        exit(1);
    }
    addr_dest.sin_family = host->h_addrtype;
    addr_dest.sin_addr = *(struct in_addr *) host->h_addr_list[0];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    printf("PING %s (%s)\n", argv[1], inet_ntoa(addr_dest.sin_addr));

    for(int i = 0; i < 5; i++) {
        seq++;
        icmpheader icmp_hdr;
        icmp_hdr.type = ICMP_ECHO_REQUEST;
        icmp_hdr.code = 0;
        icmp_hdr.id = getpid();
        icmp_hdr.sequence = seq;
        icmp_hdr.timestamp = time(NULL);
        icmp_hdr.checksum = 0;
        icmp_hdr.checksum = calculate_checksum((unsigned short *)&icmp_hdr, sizeof(icmp_hdr));

        sendto(sockfd, &icmp_hdr, sizeof(icmp_hdr), 0, (struct sockaddr *)&addr_dest, sizeof(addr_dest));

        socklen_t len = sizeof(addr_dest);
        if(recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr_dest, &len) < 0) {
            fprintf(stderr, "Error receiving ICMP packet\n");
        }
        else {
            time(&end_time);
            delay = end_time - icmp_hdr.timestamp;
            printf("%d bytes from %s: icmp_seq=%d ttl=64 time=%.0f ms\n",
                len, argv[1], icmp_hdr.sequence, delay * 1000.0);
        }
        sleep(1);
    }

    close(sockfd);
    return 0;
}

unsigned short calculate_checksum(unsigned short *ptr, int len) {
    unsigned long sum = 0;
    for(sum = 0; len > 1; len -= 2) {
        sum += *ptr++;
    }

    if (len == 1) {
        sum += *(unsigned char*)ptr;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);

    return ~sum;
}