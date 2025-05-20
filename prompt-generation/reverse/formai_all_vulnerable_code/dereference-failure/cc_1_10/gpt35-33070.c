//FormAI DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>

#define MAX_PACKET_SIZE 4096
#define MAX_IP_SIZE 16
#define PING_TIMEOUT 1000000
#define PING_INTERVAL 1000000

/* ICMP header structure */
struct icmphdr {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t identifier;
    uint16_t sequence_number;
};

/* IP header structure */
struct iphdr {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned int ihl:4;
    unsigned int version:4;
#elif __BYTE_ORDER == __BIG_ENDIAN
    unsigned int version:4;
    unsigned int ihl:4;
#else
#error "Please fix <bits/endian.h>"
#endif
    uint8_t tos;
    uint16_t tot_len;
    uint16_t id;
    uint16_t frag_off;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t checksum;
    uint32_t saddr;
    uint32_t daddr;
};

/* Utility function to calculate checksum */
unsigned short checksum(void *b, int len) {
    unsigned short *buf = (unsigned short *)b;
    unsigned int sum=0;
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

/* Utility function to set a time stamp */
void set_time(struct timeval *t) {
    gettimeofday(t, NULL);
}

/* Utility function to get the time difference between two time stamps */
long int time_diff(struct timeval *t1, struct timeval *t2) {
    return (t2->tv_sec - t1->tv_sec) * 1000000L + (t2->tv_usec - t1->tv_usec);
}

/* Main function */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./ping [IP address]\n");
        exit(1);
    }

    char *ip = argv[1];
    int sockfd, i, packet_len;
    struct sockaddr_in target_addr, source_addr;
    struct hostent *he;
    struct icmphdr *icmp_header;
    struct iphdr *ip_header;
    char packet[MAX_PACKET_SIZE], recv_packet[MAX_PACKET_SIZE];
    char recv_ip[MAX_IP_SIZE];
    int ttl = 64, sequence_number = 0;
    long int time_elapsed;
    struct timeval start_time, end_time;

    /* Resolve host name to IP address */
    if ((he = gethostbyname(ip)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    /* Set socket options */
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    /* Initialize target address and ICMP header */
    bzero(&target_addr, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr = *((struct in_addr *)he->h_addr);
    icmp_header = (struct icmphdr *)packet;

    /* Loop to continuously send ping requests and receive responses */
    for (i = 0; i < 10; i++) {
        /* Increment sequence number */
        sequence_number++;

        /* Set ICMP header */
        icmp_header->type = 8;
        icmp_header->code = 0;
        icmp_header->checksum = 0;
        icmp_header->identifier = getpid() & 0xFFFF;
        icmp_header->sequence_number = sequence_number;
        set_time(&start_time);

        /* Calculate ICMP checksum */
        icmp_header->checksum = checksum(icmp_header, sizeof(struct icmphdr));

        /* Send ICMP packet */
        if (sendto(sockfd, packet, sizeof(struct icmphdr), 0, (struct sockaddr *)&target_addr, sizeof(target_addr)) <= 0) {
            perror("sendto");
            continue;
        }

        /* Initialize source address and IP header */
        bzero(&source_addr, sizeof(source_addr));
        bzero(&ip_header, sizeof(ip_header));
        socklen_t source_addr_size = sizeof(source_addr);

        /* Wait for response */
        while (1) {
            fd_set set;
            struct timeval timeout;
            FD_ZERO(&set);
            FD_SET(sockfd, &set);
            timeout.tv_sec = 0;
            timeout.tv_usec = PING_TIMEOUT;
            
            /* Wait for timeout or response */
            if (select(sockfd + 1, &set, NULL, NULL, &timeout) > 0) {
                /* Receive ICMP packet */
                if (recvfrom(sockfd, recv_packet, MAX_PACKET_SIZE, 0, (struct sockaddr *)&source_addr, &source_addr_size) < 0) {
                    perror("recvfrom");
                    continue;
                }

                /* Parse IP header */
                ip_header = (struct iphdr *)recv_packet;

                /* Parse ICMP header */
                icmp_header = (struct icmphdr *)(recv_packet + ip_header->ihl * 4);

                /* Check if received packet is an ICMP echo response */
                if (icmp_header->type == 0 && icmp_header->code == 0 && icmp_header->identifier == getpid() & 0xFFFF && icmp_header->sequence_number == sequence_number) {
                    set_time(&end_time);
                    time_elapsed = time_diff(&start_time, &end_time);
                    inet_ntop(AF_INET, &(source_addr.sin_addr), recv_ip, MAX_IP_SIZE);
                    printf("Ping response from %s: time=%ldus\n", recv_ip, time_elapsed);
                    break;
                }
            } else {
                printf("Ping request timeout.\n");
                break;
            }
        }

        usleep(PING_INTERVAL);
    }

    /* Close socket */
    close(sockfd);

    return 0;
}