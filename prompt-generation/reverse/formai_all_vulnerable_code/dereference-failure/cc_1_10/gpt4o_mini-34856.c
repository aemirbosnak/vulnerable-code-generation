//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <netinet/ip_icmp.h>

#define DEFAULT_HOST "8.8.8.8"
#define DEFAULT_COUNT 5

void print_help() {
    printf("Usage: qos_monitor [options]\n");
    printf("Options:\n");
    printf("  -h <host>    Specify the host to ping (default: %s)\n", DEFAULT_HOST);
    printf("  -c <count>   Number of pings to send (default: %d)\n", DEFAULT_COUNT);
    printf("  -t           Enable timestamping\n");
    printf("  -j           Calculate jitter\n");
    printf("  -h           Show help\n");
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

void send_ping(int sockfd, struct sockaddr_in *addr, int seq, int timestamping) {
    struct icmp packet;
    packet.icmp_type = ICMP_ECHO;
    packet.icmp_code = 0;
    packet.icmp_id = getpid();
    packet.icmp_seq = seq;
    packet.icmp_cksum = checksum(&packet, sizeof(packet));

    if (timestamping) {
        struct timespec time;
        clock_gettime(CLOCK_MONOTONIC, &time);
        printf("Sending packet %d at time %ld.%09ld\n", seq, time.tv_sec, time.tv_nsec);
    }

    sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr));
}

int receive_ping(int sockfd, int seq, int timestamping) {
    char buffer[1024];
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    int bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&r_addr, &addr_len);
    
    if (bytes_received <= 0) {
        return -1; // No response
    }

    struct iphdr *ip_header = (struct iphdr *)buffer;
    struct icmp *icmp_header = (struct icmp *)(buffer + (ip_header->ihl << 2));
    
    if (icmp_header->icmp_type == ICMP_ECHOREPLY && icmp_header->icmp_seq == seq) {
        if (timestamping) {
            struct timespec time;
            clock_gettime(CLOCK_MONOTONIC, &time);
            printf("Received packet %d at time %ld.%09ld\n", seq, time.tv_sec, time.tv_nsec);
        }
        return 0; // Success
    }

    return -1; // Invalid response
}

int main(int argc, char **argv) {
    char *host = DEFAULT_HOST;
    int count = DEFAULT_COUNT;
    int timestamping = 0;
    int jitter_mode = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "-t") == 0) {
            timestamping = 1;
        } else if (strcmp(argv[i], "-j") == 0) {
            jitter_mode = 1;
        } else if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            count = atoi(argv[++i]);
        } else {
            host = argv[i]; // Assume the first non-option is the host
        }
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, host, &addr.sin_addr);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        send_ping(sockfd, &addr, i + 1, timestamping);
        sleep(1); // Interval between pings

        if (receive_ping(sockfd, i + 1, timestamping) == 0) {
            printf("Packet %d received successfully.\n", i + 1);
        } else {
            printf("Packet %d lost.\n", i + 1);
        }
    }

    close(sockfd);
    return 0;
}