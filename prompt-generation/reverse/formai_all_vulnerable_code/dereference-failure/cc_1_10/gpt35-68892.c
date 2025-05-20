//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <fcntl.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <linux/if.h>
#include <linux/sockios.h>

#define MAX_BUF_SIZE 512
#define MAX_ADDR 16

struct sockaddr_in daddr;
char *src_dev = NULL;
char *dst_dev = NULL;
char *dst_ip = NULL;
int dst_port = 0;
int sock_raw, sock_snd;
fd_set rset; 

int qdisc_add() {
    char cmd[MAX_BUF_SIZE];
    memset(cmd, 0x00, sizeof(cmd));
    sprintf(cmd, "sudo tc qdisc add dev %s root handle 1: htb", dst_dev);

    if (system(cmd) < 0) {
        fprintf(stderr, "failed to add qdisc.\n");
        return -1;
    }

    memset(cmd, 0x00, sizeof(cmd));
    sprintf(cmd, "sudo tc class add dev %s parent 1: classid 1:%d htb rate 100mbit burst 15k", dst_dev, dst_port);
    if (system(cmd) < 0) {
        fprintf(stderr, "failed to add qdisc.\n");
        return -1;
    }

    memset(cmd, 0x00, sizeof(cmd));
    sprintf(cmd, "sudo tc filter add dev %s parent 1: protocol ip prio 1 u32 match ip dport %d 0xffff flowid 1:%d", dst_dev, dst_port, dst_port);
    if (system(cmd) < 0) {
        fprintf(stderr, "failed to add qdisc.\n");
        return -1;
    }

    fprintf(stdout, "qdisc added.\n");
    return 0;
}

int setsockopt_init() {
    struct timeval timeout;

    timeout.tv_sec = 3;
    timeout.tv_usec = 0;
    setsockopt(sock_raw, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    int enable = 1;
    setsockopt(sock_raw, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));
    setsockopt(sock_raw, IPPROTO_IP, IP_HDRINCL, &enable, sizeof(enable));

    struct ifreq ifr;
    memset(&ifr, 0x00, sizeof(ifr));
    strncpy(ifr.ifr_name, src_dev, sizeof(ifr.ifr_name)-1);
    int ifindex = 0;
    if (ioctl(sock_raw, SIOCGIFINDEX, &ifr) < 0) {
        perror("ioctl(SIOCGIFINDEX)");
        return -1;
    }
    ifindex = ifr.ifr_ifindex; 

    if (setsockopt(sock_raw, SOL_SOCKET, SO_BINDTODEVICE, src_dev, strlen(src_dev)+1) < 0) {
        perror("setsockopt(SO_BINDTODEVICE)");
        close(sock_raw);
        exit(EXIT_FAILURE);
    }

    sock_snd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_snd < 0) {
        perror("socket error");
        return -1;
    }

    struct sockaddr_in saddr;
    memset(&saddr, 0x00, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr(dst_ip);
    saddr.sin_port = htons(dst_port);

    if (connect(sock_snd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0) {
        perror("connect error");
        return -1;
    }

    fprintf(stdout, "socket option initialized.\n");
    return 0;
}

int sendto_packet() {
    struct iphdr *ip;
    struct tcphdr *tcp;
    char *packet;
    int pkt_len;
    int total_len;

    /* reset packet buffer */
    char buf[MAX_BUF_SIZE];
    memset(buf, 0, sizeof(buf));

    /* create tcp + ip packet */
    packet = buf;
    ip = (struct iphdr *)packet;
    tcp = (struct tcphdr *)(packet + sizeof(struct iphdr));
    strcpy(packet + sizeof(struct iphdr) + sizeof(struct tcphdr), "Hello from the other side, I must have called a thousand times...");

    /* IP header */
    ip->version = 4;
    ip->ihl = 5;
    ip->tos = 0;
    total_len = sizeof(struct iphdr) + sizeof(struct tcphdr) + strlen(packet + sizeof(struct iphdr) + sizeof(struct tcphdr));
    ip->tot_len = htons(total_len);
    ip->id = htons(0);
    ip->frag_off = 0;
    ip->ttl = 0xff;
    ip->protocol = IPPROTO_TCP;
    ip->daddr = daddr.sin_addr.s_addr;
    ip->saddr = inet_addr("192.168.0.20");
    ip->check = htons(0);

    /* TCP header */
    tcp->source = htons(1234);
    tcp->dest = htons(dst_port);
    tcp->seq = htonl(1);
    tcp->ack_seq = 0;
    tcp->res1 = 0;
    tcp->doff = 5;
    tcp->fin = 0;
    tcp->syn = 1;
    tcp->rst = 0;
    tcp->psh = 0;
    tcp->ack = 0;
    tcp->urg = 0;
    tcp->window = htons(32767);
    tcp->check = 0;
    tcp->urg_ptr = 0;

    /* checksum calculation */
    ip->check = htons(~(htons(ip->check) + ntohs(IPPROTO_TCP + total_len)));

    if (send(sock_snd, packet, total_len, 0) < 0) {
        fprintf(stderr, "failed to send packet.\n");
        return -1;
    }

    return 0;
}

int recv_packet() {
    int ret_len = 0;
    unsigned int addr_len;

    char buf[MAX_BUF_SIZE];
    addr_len = sizeof(struct sockaddr_in);

    if (FD_ISSET(sock_raw, &rset)) {
        if ((ret_len = recvfrom(sock_raw, buf, sizeof(buf), 0, (struct sockaddr *)&daddr, &addr_len)) < 0) {
            fprintf(stdout, "packet loss.\n");
            return -1;
        }
    }

    return ret_len;
}

void signal_handler(int signo) {
    if (signo == SIGINT) {
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage : %s <src dev> <dst dev> <dst ip> <dst port>\n", argv[0]);
        return -1;
    }

    src_dev = argv[1];
    dst_dev = argv[2];
    dst_ip = argv[3];
    dst_port = atoi(argv[4]);

    if ((sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        perror("socket error");
        return -1;
    }

    signal(SIGINT, signal_handler);

    if (setsockopt_init() < 0)
        return -1;

    if (qdisc_add() < 0)
        return -1;

    while (1) {
        static struct timeval tv;
        tv.tv_sec = 3;
        tv.tv_usec = 0;

        /* send packet */
        sendto_packet();

        /* wait for packet arrival */
        FD_ZERO(&rset);
        FD_SET(sock_raw, &rset);
        select(sock_raw+1, &rset, NULL, NULL, &tv);

        /* receive packet */
        if (recv_packet() < 0)
            continue;
    }

    close(sock_raw);
    close(sock_snd);
    return 0;
}