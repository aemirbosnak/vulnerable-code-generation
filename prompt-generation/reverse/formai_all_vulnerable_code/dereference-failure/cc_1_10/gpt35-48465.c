//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>

#define BUFSIZE 1024

void print_error(char *msg) {
    fprintf(stderr, "Error: %s (%s)\n", msg, strerror(errno));
}

int main(int argc, char **argv) {
    // check for command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // create socket
    int s;
    if ((s = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        print_error("socket() failed");
        exit(EXIT_FAILURE);
    }

    // set socket options to receive IP packets
    int opt = 1;
    if (setsockopt(s, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(opt)) < 0) {
        print_error("setsockopt() failed");
        exit(EXIT_FAILURE);
    }

    // set timeout for receive socket
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if (setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv)) < 0) {
        print_error("setsockopt() failed");
        exit(EXIT_FAILURE);
    }

    // prepare address struct
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    if (inet_aton(argv[1], &addr.sin_addr) == 0) {
        print_error("inet_aton() failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming packets and print QoS information
    while (1) {
        char buf[BUFSIZE];
        struct sockaddr_in sender_addr;
        socklen_t sender_len = sizeof(sender_addr);

        int recvlen = recvfrom(s, buf, BUFSIZE, 0, (struct sockaddr*)&sender_addr, &sender_len);
        if (recvlen < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                // timeout, continue listening
                continue;
            } else {
                print_error("recvfrom() failed");
                exit(EXIT_FAILURE);
            }
        }

        // parse IP and TCP headers
        struct iphdr *iph = (struct iphdr*)buf;
        struct tcphdr *tcph = (struct tcphdr*)(buf + (iph->ihl * 4));

        // print QoS information
        printf("Received packet from %s:%d to %s:%d\n", inet_ntoa(sender_addr.sin_addr), ntohs(tcph->source), inet_ntoa(addr.sin_addr), ntohs(tcph->dest));
        printf("IP header length: %d\n", iph->ihl);
        printf("TCP header length: %d\n", tcph->doff * 4);
        printf("Total packet length: %d\n", ntohs(iph->tot_len));
        printf("Packet payload length: %d\n", ntohs(iph->tot_len) - (iph->ihl * 4) - (tcph->doff * 4));
        printf("TCP flags: %c%c%c%c%c%c\n", tcph->urg ? 'U' : '.', tcph->ack ? 'A' : '.', tcph->psh ? 'P' : '.', tcph->rst ? 'R' : '.', tcph->syn ? 'S' : '.', tcph->fin ? 'F' : '.');
        printf("Time to live: %d\n", iph->ttl);
        printf("Protocol: %d\n", iph->protocol);
        printf("Checksum: %d\n", ntohs(iph->check));

        // do some QoS evaluation here...

    }

    return 0;
}