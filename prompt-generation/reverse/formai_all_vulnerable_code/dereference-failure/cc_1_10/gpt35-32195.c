//FormAI DATASET v1.0 Category: Network Ping Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define PACKET_SIZE 64
#define PING_TIMEOUT 2

struct icmphdr icmp_hdr; 

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for ( sum = 0; len > 1; len -= 2 ) {
        sum += *buf++;
    }

    if ( len == 1 ) {
        sum += *(unsigned char*)buf;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

void ping(struct sockaddr_in *target_addr, int ttl) {
    int sockfd, ttl_counter = ttl, received = 0;
    double response_time;
    char recv_packet[PACKET_SIZE], pack[PACKET_SIZE];
    struct timeval timeout = { PING_TIMEOUT, 0 };
    struct hostent *host;
    struct sockaddr_in recv_addr;
    memset(&recv_addr, 0, sizeof(recv_addr));

    icmp_hdr.type = ICMP_ECHO;
    icmp_hdr.code = 0;
    icmp_hdr.un.echo.sequence = 1;
    icmp_hdr.un.echo.id = getpid();

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    setsockopt(sockfd, IPPROTO_IP, IP_TTL, (char *)&ttl_counter, sizeof(int));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(struct timeval));

    if(sockfd < 0) {
        fprintf(stderr, "socket() error\n");
        return;
    }

    if(sendto(sockfd, &icmp_hdr, sizeof(icmp_hdr), 0, (struct sockaddr*)target_addr, sizeof(*target_addr)) <= 0) {
        fprintf(stderr, "sendto() error\n");
        close(sockfd);
        return;
    }

    socklen_t len = sizeof(recv_addr);

    if(recvfrom(sockfd, &recv_packet, sizeof(recv_packet), 0, (struct sockaddr*)&recv_addr, &len) <= 0) {
        fprintf(stdout, "%d:   *   *   *\n", ttl_counter); 
    } else {
        response_time = (double)(clock()) / CLOCKS_PER_SEC;
        received = 1;
    }

    if(received) {
        host = gethostbyaddr((char *)&recv_addr.sin_addr.s_addr, 4, AF_INET);
        fprintf(stdout, "%d:   %s   %.2f ms\n", ttl_counter, inet_ntoa(recv_addr.sin_addr), response_time);
    }

    close(sockfd);
}

void ping_server(char* address, int max_ttl) {
    struct sockaddr_in target_addr;
    struct hostent *host;
    memset(&target_addr, 0, sizeof(target_addr));

    target_addr.sin_family = AF_INET;
    target_addr.sin_port = 0;

    if(inet_addr(address) != INADDR_NONE) {
        memcpy(&target_addr.sin_addr.s_addr, &address, sizeof(target_addr.sin_addr.s_addr));
        host = gethostbyaddr((char *)&target_addr.sin_addr.s_addr, 4, AF_INET);
    } else {
        host = gethostbyname(address);
        memcpy(&target_addr.sin_addr.s_addr, host->h_addr, sizeof(target_addr.sin_addr.s_addr));
    }

    printf("Pinging %s [%s] with %d bytes of data:\n\n", host->h_name, inet_ntoa(target_addr.sin_addr), PACKET_SIZE);

    for(int i = 1; i <= max_ttl; i++) {
        ping(&target_addr, i);
    }
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: '%s <IP address / hostname> [max TTL]'\n", argv[0]);
        return 1;
    }

    int max_ttl = 10;

    if(argc == 3) {
        max_ttl = atoi(argv[2]);

        if(max_ttl > 30) {
            printf("Max TTL can be 30 at most!\n");
            return 1;
        }
    }

    ping_server(argv[1], max_ttl);

    return 0;
}