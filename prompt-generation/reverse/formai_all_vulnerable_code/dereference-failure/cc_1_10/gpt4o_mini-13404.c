//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

typedef struct {
    char *target;
    int count;
} PingArgs;

void print_divider() {
    printf("\n============================================\n");
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

void *ping(void *arguments) {
    PingArgs *args = (PingArgs *)arguments;
    struct sockaddr_in addr;
    struct icmphdr icmp_hdr;
    char packet[PACKET_SIZE];
    int sock_fd, i;
    struct timespec start, end;
    
    sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock_fd < 0) {
        perror("Socket Creation Failed!");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(args->target);

    print_divider();
    printf("Pinging %s with %d packets...\n", args->target, args->count);
    
    for (i = 0; i < args->count; i++) {
        memset(&icmp_hdr, 0, sizeof(icmp_hdr));
        memset(packet, 0, sizeof(packet));
        
        icmp_hdr.type = ICMP_ECHO;
        icmp_hdr.un.echo.id = getpid();
        icmp_hdr.un.echo.sequence = i + 1;
        icmp_hdr.checksum = checksum(&icmp_hdr, sizeof(icmp_hdr));
        
        memcpy(packet, &icmp_hdr, sizeof(icmp_hdr));
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        if (sendto(sock_fd, packet, sizeof(icmp_hdr), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Send Failed");
            continue;
        }

        char buffer[PACKET_SIZE];
        socklen_t addr_len = sizeof(addr);
        if (recvfrom(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addr_len) <= 0) {
            perror("Receive Failed");
            continue;
        }
        clock_gettime(CLOCK_MONOTONIC, &end);

        double time_taken = (end.tv_sec - start.tv_sec) * 1e9;
        time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-6;

        printf("Reply from %s: bytes=%d time=%.2f ms TTL=%d\n",
                inet_ntoa(addr.sin_addr), sizeof(icmp_hdr), time_taken, 64);
        
        sleep(1); // Pause before next ping
    }

    close(sock_fd);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Ping Count>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    PingArgs args;
    args.target = argv[1];
    args.count = atoi(argv[2]);

    if (args.count <= 0 || args.count > PING_COUNT) {
        fprintf(stderr, "Invalid ping count. It must be between 1 and %d.\n", PING_COUNT);
        exit(EXIT_FAILURE);
    }

    ping((void *)&args);
    print_divider();
    printf("Ping completed. 🌐✨\n");

    return 0;
}