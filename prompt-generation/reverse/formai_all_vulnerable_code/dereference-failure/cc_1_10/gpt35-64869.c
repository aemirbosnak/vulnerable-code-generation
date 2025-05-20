//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <errno.h>
#include <signal.h>
#include <netdb.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <time.h>

#define MAXLINE 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

void handler(int signo) {
    if(signo == SIGALRM)
        return;
}

void monitor_qos(int sockfd, struct sockaddr_in address) {
    char buffer[MAXLINE];
    int n;

    struct iphdr *ip_header = (struct iphdr *) buffer;
    struct tcphdr *tcp_header = (struct tcphdr *) (buffer + sizeof(struct ip));

    while(1) {
        memset(buffer, 0, MAXLINE);
        n = recvfrom(sockfd, buffer, MAXLINE, 0, (struct sockaddr *)&address, sizeof(address));

        if(ip_header->protocol == IPPROTO_TCP) {
            printf("TCP packet received\n");
            printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&ip_header->saddr));
            printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *)&ip_header->daddr));

            printf("Total length: %d\n", ntohs(ip_header->tot_len));
            printf("TCP sequence number: %u\n", ntohl(tcp_header->seq));
            printf("TCP acknowledgement number: %u\n", ntohl(tcp_header->ack_seq));

            printf("TCP flags: ");
            if(tcp_header->fin) printf("FIN ");
            if(tcp_header->syn) printf("SYN ");
            if(tcp_header->rst) printf("RST ");
            if(tcp_header->psh) printf("PSH ");
            if(tcp_header->ack) printf("ACK ");
            if(tcp_header->urg) printf("URG ");
            printf("\n");

            printf("TCP window size: %d\n", ntohs(tcp_header->window));
            printf("TCP urgent pointer: %d\n", tcp_header->urg_ptr);
            printf("-----------------------------\n");
        }
    }
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in address;
    struct hostent *host;
    int port, n;
    char buffer[MAXLINE];

    if(argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(0);
    }

    port = atoi(argv[2]);

    if((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0)
        error("Error opening socket");

    host = gethostbyname(argv[1]);
    if(host == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(0);
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr = *((struct in_addr*)host->h_addr_list[0]);

    monitor_qos(sockfd, address);

    close(sockfd);
    return 0;
}