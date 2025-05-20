//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#define PACKET_SIZE 4096

int main(int argc, char *argv[]) {
    if(argc!=2) {
        printf("\nUsage: %s <IP address>\n",argv[0]);
        return 0;
    }

    int sock, sock_icmp;
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    sock_icmp=socket(AF_INET,SOCK_RAW,IPPROTO_ICMP);

    int on = 1;
    const int *val = &on;
    if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, val, sizeof(on)) < 0) {
        printf("Error setting IP_HDRINCL\n");
        return 0;
    }

    struct sockaddr_in addr, daddr;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(0);
    bind(sock, (const struct sockaddr*)&addr, sizeof(addr));

    memset(&daddr, 0, sizeof(daddr));
    daddr.sin_family = AF_INET;
    daddr.sin_addr.s_addr = inet_addr(argv[1]);

    int ttl = 1;
    char packet[PACKET_SIZE];
    memset(packet, 0, PACKET_SIZE);

    struct iphdr *ip = (struct iphdr*) packet;
    struct icmphdr *icmp = (struct icmphdr*) (packet + sizeof(struct iphdr));

    icmp->type = ICMP_ECHO;
    icmp->code = 0;
    icmp->checksum = 0;
    icmp->un.echo.id = getpid();
    icmp->un.echo.sequence = 0;

    ip->ihl = 5;
    ip->version = 4;
    ip->tos = 0;
    ip->tot_len = sizeof(struct iphdr) + sizeof(struct icmphdr);
    ip->id = htons(0);
    ip->frag_off = htons(0);
    ip->ttl = ttl;
    ip->protocol = IPPROTO_ICMP;
    ip->check = htons(0);
    ip->saddr = inet_addr("192.168.1.2");
    ip->daddr = daddr.sin_addr.s_addr;

    char *data = packet + sizeof(struct iphdr) + sizeof(struct icmphdr);

    socklen_t socklen = sizeof(struct sockaddr_in);
    int recv = -1;
    int sent = -1;

    while(ttl<30) {
        ip->ttl = ttl++;
        ip->check = htons(0);

        icmp->checksum = 0;
        icmp->checksum = htons(~(ICMP_ECHO << 8));

        sent = sendto(sock, packet, ip->tot_len, 0, (struct sockaddr*)&daddr, sizeof(daddr));
        if(sent<=0)
            break;

        recv = recvfrom(sock_icmp, packet, PACKET_SIZE, 0, (struct sockaddr*)&daddr, &socklen);
        if(recv<=0)
            break;

        struct iphdr *iprecv = (struct iphdr*) packet;
        data = (packet + sizeof(struct iphdr) + sizeof(struct icmphdr));
        char *sender = strdup(inet_ntoa(*(struct in_addr*)&iprecv->saddr));

        printf("Received from %s with ttl=%d\n", sender, iprecv->ttl);
    }

    close(sock);
    close(sock_icmp);

    return 0;
}