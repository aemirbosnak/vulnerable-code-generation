//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <signal.h>

#define PACKET_SIZE 64
#define PING_INTERVAL 1
#define MAX_WAIT_TIME 2
#define MAX_PINGS 5

struct icmp_packet {
    struct icmphdr header;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

static volatile int running = 1;

void handle_sigint(int sig) {
    running = 0;
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;
    
    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    
    if (len == 1) {
        sum += *(unsigned char *)buf;
    }
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp_packet packet;
    struct timeval start_time, end_time, timeout;
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    memset(&packet, 0, sizeof(packet));
    packet.header.type = ICMP_ECHO;
    packet.header.un.echo.id = getpid();
    packet.header.un.echo.sequence = 1;
    strcpy(packet.msg, "PING");

    packet.header.checksum = checksum(&packet, sizeof(packet));

    signal(SIGINT, handle_sigint);

    for (int i = 0; i < MAX_PINGS && running; i++) {
        gettimeofday(&start_time, NULL);
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            printf("Ping failed: %s\n", strerror(errno));
            continue;
        }

        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);
        timeout.tv_sec = MAX_WAIT_TIME;
        timeout.tv_usec = 0;

        if (select(sockfd + 1, &fds, NULL, NULL, &timeout) > 0) {
            char response_buffer[PACKET_SIZE];
            socklen_t addr_len = sizeof(addr);
            if (recvfrom(sockfd, response_buffer, sizeof(response_buffer), 0, (struct sockaddr *)&addr, &addr_len) > 0) {
                gettimeofday(&end_time, NULL);
                double time_taken = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + 
                                    (end_time.tv_usec - start_time.tv_usec) / 1000.0;
                printf("Reply from %s: time=%.2f ms\n", ip_address, time_taken);
            } else {
                printf("Ping timeout for %s\n", ip_address);
            }
        } else {
            printf("Ping timeout for %s\n", ip_address);
        }
        
        sleep(PING_INTERVAL);
        packet.header.un.echo.sequence++;
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ping(argv[1]);

    return EXIT_SUCCESS;
}