//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>
#include <signal.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

struct sockaddr_in dest_addr;
pid_t pid;

void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("\nPing test stopped.\n");
        exit(0);
    }
}

unsigned short checksum(void *b, int len) {    
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void ping(const char *ip_address) {
    int sockfd;
    struct icmp *icmp_hdr;
    char packet[PACKET_SIZE];
    struct timeval start, end, timeout;
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        fprintf(stderr, "Socket creation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(ip_address);

    for (int i = 1; i <= PING_COUNT; i++) {
        memset(packet, 0, sizeof(packet));
        
        icmp_hdr = (struct icmp *) packet;
        icmp_hdr->icmp_type = ICMP_ECHO;
        icmp_hdr->icmp_code = 0;
        icmp_hdr->icmp_id = getpid();
        icmp_hdr->icmp_seq = i;
        icmp_hdr->icmp_cksum = checksum(packet, sizeof(packet));

        gettimeofday(&start, NULL);

        if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) <= 0) {
            fprintf(stderr, "Send failed: %s\n", strerror(errno));
            continue;
        }

        socklen_t len = sizeof(dest_addr);
        if (recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, &len) <= 0) {
            fprintf(stderr, "Receive failed: %s\n", strerror(errno));
            continue;
        }

        gettimeofday(&end, NULL);
        timeout.tv_sec = end.tv_sec - start.tv_sec;
        timeout.tv_usec = end.tv_usec - start.tv_usec;
        if (timeout.tv_usec < 0) {
            timeout.tv_sec--;
            timeout.tv_usec += 1000000;
        }

        if (icmp_hdr->icmp_type == ICMP_ECHOREPLY && icmp_hdr->icmp_id == getpid()) {
            printf("Ping to %s: bytes=%d time=%ld.%03ld ms\n", ip_address, PACKET_SIZE, timeout.tv_sec * 1000 + timeout.tv_usec / 1000, timeout.tv_usec % 1000);
        } else {
            printf("Ping to %s: Request timed out.\n", ip_address);
        }

        usleep(1000000); // wait 1 second before sending the next ping
    }
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, sig_handler);

    printf("Pinging %s with %d bytes of data:\n", argv[1], PACKET_SIZE);
    ping(argv[1]);

    return 0;
}