//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65536

struct ipheader {
    unsigned char       ver_ihl;
    unsigned char       tos;
    unsigned short int  tlen;
    unsigned short int  id;
    unsigned short int  flags_fo;
    unsigned char       ttl;
    unsigned char       proto;
    unsigned short int  crc;
    unsigned int        saddr;
    unsigned int        daddr;
};

struct tcpheader {
    unsigned short int  sport;
    unsigned short int  dport;
    unsigned int        seqnum;
    unsigned int        acknum;
    unsigned char       doffset_res;
    unsigned char       flags;
    unsigned short int  win;
    unsigned short int  crc;
    unsigned short int  urgptr;
};

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    int sockfd, ret, iface_len;
    struct sockaddr_in saddr;
    unsigned char *buffer = (unsigned char *) malloc(MAX_PACKET_SIZE);

    if (!buffer) {
        error("Failed to allocate memory!");
    }

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

    if (sockfd < 0) {
        error("Failed to create socket!");
    }

    iface_len = strlen(argv[1]);

    memset(&saddr, 0, sizeof(struct sockaddr_in));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(0);
    saddr.sin_addr.s_addr = INADDR_ANY;

    if ((ret = bind(sockfd, (struct sockaddr *) &saddr, sizeof(struct sockaddr_in))) < 0) {
        error("Failed to bind socket!");
    }

    int total_packets = 0, total_bytes = 0;

    while (1) {

        int packet_len = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, NULL, NULL);

        if (packet_len < 0) {
            error("Failed to receive packet!");
        }

        struct ipheader *ip = (struct ipheader *) buffer;

        if (ip->proto == IPPROTO_TCP) {

            struct tcpheader *tcp = (struct tcpheader *) (buffer + sizeof(struct ipheader));

            total_packets++;
            total_bytes += packet_len;

            printf("Packet %d: SRC=%s:%d DST=%s:%d SEQ=%d ACK=%d\n",
                   total_packets,
                   inet_ntoa(*(struct in_addr *)&ip->saddr),
                   ntohs(tcp->sport),
                   inet_ntoa(*(struct in_addr *)&ip->daddr),
                   ntohs(tcp->dport),
                   ntohl(tcp->seqnum),
                   ntohl(tcp->acknum));

            printf("Total Packets: %d, Total Bytes: %d\n", total_packets, total_bytes);

        }
    }

    return 0;

}