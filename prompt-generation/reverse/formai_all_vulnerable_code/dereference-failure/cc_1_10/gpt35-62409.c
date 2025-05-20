//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65535

int main(int argc, char *argv[]) {
    int sockfd, ret, i, port, count=0, len;
    struct sockaddr_in target;
    char buffer[MAX_PACKET_SIZE], *payload;

    if(argc < 3) {
        printf("Usage: %s <Target IP> <Port> <Packet Payload>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if(sockfd < 0) {
        perror("Error: Could not create raw socket");
        exit(EXIT_FAILURE);
    }

    port = atoi(argv[2]);

    memset(&target, 0, sizeof target);
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);
    target.sin_port = htons(port);

    payload = argv[3];

    memset(buffer, 0, MAX_PACKET_SIZE);

    struct iphdr *ip = (struct iphdr *) buffer;
    struct tcphdr *tcp = (struct tcphdr *) (buffer + sizeof(struct ip));
    
    tcp->source = htons(1234);
    tcp->dest = htons(port);
    tcp->seq = 0;
    tcp->ack_seq = 0;
    tcp->doff = sizeof(struct tcphdr) / 4;
    tcp->syn = 1;
    tcp->window = htons(65535);
    tcp->check = 0;
    tcp->urg_ptr = 0;

    ip->ihl = 5;
    ip->version = 4;
    ip->tos = 0;
    ip->tot_len = sizeof(struct iphdr) + sizeof(struct tcphdr);
    ip->id = htons(54321);
    ip->frag_off = htons(0);
    ip->ttl = 255;
    ip->protocol = IPPROTO_TCP;
    ip->check = 0;
    ip->saddr = inet_addr("192.168.1.100");
    ip->daddr = target.sin_addr.s_addr;

    tcp->check = htons(htons(~(tcp->check)));

    printf("\nPacket Sent: %s\n", payload);
    while(1){
        ret = sendto(sockfd, buffer, ip->tot_len, 0, (struct sockaddr *)&target, sizeof target);
        if(ret < 0) {
            perror("Error: sendto failed");
            exit(EXIT_FAILURE);
        }
        printf("%d Packets Sent.\n", ++count);
        sleep(1);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}