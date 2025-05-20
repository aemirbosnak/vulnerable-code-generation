//FormAI DATASET v1.0 Category: Network Ping Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define ICMP_HEADER_SIZE 8

struct icmp_packet {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t id;
    uint16_t seq;
};

unsigned short checksum(void* b, int len) {    
    unsigned short* buf = (unsigned short*) b;
    unsigned int sum=0;
    unsigned short result;
    
    for ( sum = 0; len > 1; len -= 2 )
        sum += *buf++;

    if ( len == 1 )
        sum += *(unsigned char*)buf;
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void ping(struct sockaddr_in* target, int ttl) {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if ( sock < 0 ) {
        perror("socket");
        return;
    }
    
    struct timeval timeout = { 1, 0 };
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof timeout);
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof timeout);

    struct icmp_packet p;
    p.type = ICMP_ECHO_REQUEST;
    p.code = 0;
    p.id = htons(getpid() & 0xFFFF);
    
    for ( int i = 0; i < 5; ++i ) {
        p.seq = htons(i+1);
        p.checksum = 0;
        p.checksum = checksum(&p, sizeof p);
        printf("PING %s (packet %d)\n", inet_ntoa(target->sin_addr), i+1);
        sendto(sock, &p, sizeof p, 0, (struct sockaddr*)target, sizeof(struct sockaddr_in));
        
        struct sockaddr_in from;
        socklen_t fromlen = sizeof from;
        struct icmp_packet response;
        
        if (recvfrom(sock, &response, sizeof response, 0, (struct sockaddr*)&from, &fromlen) == sizeof response && response.type == ICMP_ECHO_REPLY && response.seq == p.seq ) {
            printf("PONG %s (packet %d)\n", inet_ntoa(from.sin_addr), i+1);
        } else {
            printf("ERROR: No pong received\n");
        }
    }

    close(sock);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        return 1;
    }
    
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        target.sin_addr.s_addr = inet_addr(argv[1]);
        if (target.sin_addr.s_addr == INADDR_NONE) {
            printf("Invalid hostname or IP address: %s\n", argv[1]);
            return 1;
        }
    } else {
        target.sin_addr.s_addr = *(uint32_t*)host->h_addr_list[0];
    }

    printf("Starting ping test to %s\n\n", inet_ntoa(target.sin_addr));

    for ( int i = 1; i <= 5; ++i ) {
        printf("PING %s (packet %d)\n", inet_ntoa(target.sin_addr), i);
        ping(&target, i);
        printf("\n");
        sleep(1);
    }  
    return 0;
}