//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 65536

struct ipheader {
    unsigned char      ip_ihl:4, ip_ver:4;
    unsigned char      ip_tos;
    unsigned short int ip_len;
    unsigned short int ip_id;
    unsigned short int ip_off;
    unsigned char      ip_ttl;
    unsigned char      ip_p;
    unsigned short int ip_sum;
    struct in_addr     ip_src, ip_dst;
};

struct icmpheader {
    unsigned char icmp_type;
    unsigned char icmp_code;
    unsigned short int icmp_chksum;
};

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: ./mapper <ip-address>\n");
        return -1;
    }

    // create raw socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("Error creating raw socket.\n");
        return -1;
    }

    // resolve hostname to IP address
    struct hostent* hp;
    hp = gethostbyname(argv[1]);
    if (hp == NULL) {
        printf("Error resolving hostname.\n");
        return -1;
    }
    struct in_addr ip_addr;
    memcpy(&ip_addr, hp->h_addr, sizeof(ip_addr));

    // build ICMP request packet
    char buffer[BUFFER_SIZE];
    struct ipheader* ip_hdr = (struct ipheader*) buffer;
    struct icmpheader* icmp_hdr = (struct icmpheader*) (buffer + sizeof(struct ipheader));
    
    memset(buffer, 0, BUFFER_SIZE);
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_chksum = 0;
    icmp_hdr->icmp_chksum = htons(~(ICMP_ECHO << 8));

    // set IP header fields
    ip_hdr->ip_ihl = 5;
    ip_hdr->ip_ver = 4;
    ip_hdr->ip_tos = 0;
    ip_hdr->ip_len = sizeof(struct ipheader) + sizeof(struct icmpheader);
    ip_hdr->ip_id = htons(54321);
    ip_hdr->ip_off = 0;
    ip_hdr->ip_ttl = 255;
    ip_hdr->ip_p = IPPROTO_ICMP;
    ip_hdr->ip_src.s_addr = INADDR_ANY;
    ip_hdr->ip_dst = ip_addr;

    // send ICMP request packet
    struct sockaddr_in si_dest;
    si_dest.sin_family = AF_INET;
    si_dest.sin_addr = ip_addr;
    memset(&si_dest.sin_zero, 0, sizeof(si_dest.sin_zero));
    if (sendto(sockfd, buffer, ip_hdr->ip_len, 0, (struct sockaddr*)&si_dest, sizeof(si_dest)) < 0) {
        printf("Error sending packet: %s\n", strerror(errno));
        return -1;
    }

    // receive ICMP reply packet
    struct sockaddr_in si_recv;
    unsigned int slen = sizeof(si_recv);
    if (recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&si_recv, &slen) < 0) {
        printf("Error receiving packet: %s\n", strerror(errno));
        return -1;
    }

    // extract IP header and display it
    printf("IP Header\n");
    printf("  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("  |Version|%d|      %d      |%d|         %d           |%d|\n",
        ip_hdr->ip_ver, ip_hdr->ip_tos, ntohs(ip_hdr->ip_len), ntohs(ip_hdr->ip_id), ntohs(ip_hdr->ip_off));
    printf("  |  %d    |%d|    %d    |%d|%d|%d|%d|      %3d      |\n",
        ip_hdr->ip_ttl, ip_hdr->ip_p, ntohs(ip_hdr->ip_sum),
        (int)(ip_hdr->ip_src.s_addr), (int)(ip_hdr->ip_dst.s_addr),
        ntohs(ip_hdr->ip_len) - sizeof(struct ipheader));
    
    // extract ICMP header and display it
    struct icmpheader* icmp_reply = (struct icmpheader*) (buffer + sizeof(struct ipheader));
    printf("ICMP Header\n");
    printf("  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("  |     Type      |     Code      |          Checksum           |\n");
    printf("  |     %3d      |      %3d      |             %4d             |\n",
        icmp_reply->icmp_type, icmp_reply->icmp_code, ntohs(icmp_reply->icmp_chksum));

    close(sockfd);
    return 0;
}