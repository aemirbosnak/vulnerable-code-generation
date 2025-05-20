//FormAI DATASET v1.0 Category: Network Ping Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define MAX_HOPS 30
#define NUM_PACKETS 5

int send_packet(int fd, struct sockaddr_in *addr, int ttl);
int receive_packet(int fd, u_int16_t seq_num, struct sockaddr_in *addr, u_int32_t timeout);
u_int16_t calculate_icmp_checksum(u_int16_t *data, int size);
double calculate_elapsed_time(struct timespec *before, struct timespec *after);
char *get_hostname(struct sockaddr_in *addr);

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: ./ping <ip address>\n");
        return 0;
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    if(inet_pton(AF_INET, argv[1], &(dest_addr.sin_addr)) != 1) {
        printf("Invalid IP address.\n");
        return 0;
    }

    // create a raw socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd < 0) {
        printf("Failed to create socket.\n");
        return 0;
    }

    // set the TTL option on the socket
    int ttl = MAX_HOPS;
    if(setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) != 0) {
        printf("Failed to set TTL.\n");
        return 0;
    }

    char *dest_hostname = get_hostname(&dest_addr);
    printf("PING %s\n", dest_hostname);

    int num_received = 0;
    int num_sent = 0;
    int curr_ttl;
    struct timespec before, after;

    for(curr_ttl = 1; curr_ttl <= MAX_HOPS && num_received == 0; curr_ttl++) {
        printf("%d ", curr_ttl);
        fflush(stdout);

        // send NUM_PACKETS packets for the current TTL value
        int i;
        for(i = 0; i < NUM_PACKETS; i++) {
            if(send_packet(sockfd, &dest_addr, curr_ttl) == -1) {
                printf("Failed to send packet.\n");
            } else {
                num_sent++;
            }
        }

        // receive packets for the current TTL value
        for(i = 0; i < NUM_PACKETS; i++) {
            // set the timeout value for the socket
            struct timeval timeout;
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;
            if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) != 0) {
                printf("Failed to set receive timeout.\n");
            }

            // receive the packet and calculate the elapsed time
            if(clock_gettime(CLOCK_MONOTONIC, &before) == -1) {
                printf("Failed to get time.\n");
            }
            int ret = receive_packet(sockfd, i+1, &dest_addr, 1000);
            if(clock_gettime(CLOCK_MONOTONIC, &after) == -1) {
                printf("Failed to get time.\n");
            }
            if(ret == -1) {
                printf("* ");
            } else {
                num_received++;
                double elapsed_time = calculate_elapsed_time(&before, &after);
                printf("%.3f ms ", elapsed_time);
            }
        }

        printf("\n");

        // stop if we have received a reply from the destination host
        if(num_received > 0) {
            printf("%s is up.\n", dest_hostname);
            break;
        }
    }

    if(num_received == 0) {
        printf("%s is down.\n", dest_hostname);
    }

    printf("%d sent, %d received\n", num_sent, num_received);

    return 0;
}

int send_packet(int fd, struct sockaddr_in *addr, int ttl) {
    char packet[PACKET_SIZE];
    memset(packet, 0, PACKET_SIZE);

    // set up the ICMP header
    struct icmphdr *icmp_header = (struct icmphdr *)packet;
    icmp_header->type = ICMP_ECHO;
    icmp_header->code = 0;
    icmp_header->checksum = 0;
    icmp_header->un.echo.id = htons(getpid() & 0xffff);
    icmp_header->un.echo.sequence = 0;

    // set up the data
    char *data = packet + sizeof(struct icmphdr);
    snprintf(data, PACKET_SIZE - sizeof(struct icmphdr), "Ping");

    // calculate the ICMP checksum
    icmp_header->checksum = calculate_icmp_checksum((u_int16_t *)icmp_header, PACKET_SIZE);

    // set the TTL value
    if(setsockopt(fd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) != 0) {
        printf("Failed to set TTL.\n");
        return -1;
    }

    // send the packet
    if(sendto(fd, packet, PACKET_SIZE, 0, (struct sockaddr *)addr, sizeof(struct sockaddr_in)) == -1) {
        printf("Failed to send packet.\n");
        return -1;
    }

    return 0;
}

int receive_packet(int fd, u_int16_t seq_num, struct sockaddr_in *addr, u_int32_t timeout) {
    char buffer[PACKET_SIZE];
    struct sockaddr_in recv_addr;
    socklen_t addr_len = sizeof(recv_addr);
    memset(&recv_addr, 0, addr_len);

    struct timeval recv_timeout;
    recv_timeout.tv_sec = timeout / 1000;
    recv_timeout.tv_usec = (timeout % 1000) * 1000;

    // set the receive timeout
    if(setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &recv_timeout, sizeof(recv_timeout)) != 0) {
        printf("Failed to set receive timeout.\n");
        return -1;
    }

    // receive the packet
    int bytes_received = recvfrom(fd, buffer, PACKET_SIZE, 0, (struct sockaddr *)&recv_addr, &addr_len);
    if(bytes_received == -1) {
        if(errno == EAGAIN || errno == EWOULDBLOCK) {
            return -1;
        } else {
            printf("Failed to receive packet.\n");
            return -1;
        }
    }

    // check that the packet is an ICMP echo reply
    struct iphdr *ip_header = (struct iphdr *)buffer;
    struct icmphdr *icmp_header = (struct icmphdr *)(buffer + ip_header->ihl * 4);
    if(icmp_header->type != ICMP_ECHOREPLY) {
        return -1;
    }

    // check that the sequence number matches
    if(icmp_header->un.echo.sequence != htons(seq_num)) {
        return -1;
    }

    // check that the source address matches
    if(memcmp(&(recv_addr.sin_addr), &(addr->sin_addr), sizeof(struct in_addr)) != 0) {
        return -1;
    }

    return 0;
}

u_int16_t calculate_icmp_checksum(u_int16_t *data, int size) {
    u_int32_t sum = 0;

    while(size > 1) {
        sum += *data++;
        size -= 2;
    }

    if(size == 1) {
        sum += *(u_int8_t *)data;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);

    return (u_int16_t)~sum;
}

double calculate_elapsed_time(struct timespec *before, struct timespec *after) {
    return (after->tv_sec - before->tv_sec) * 1000.0 + (after->tv_nsec - before->tv_nsec) / 1000000.0;
}

char *get_hostname(struct sockaddr_in *addr) {
    struct hostent *host = gethostbyaddr(&(addr->sin_addr), sizeof(struct in_addr), AF_INET);
    if(host != NULL) {
        return host->h_name;
    } else {
        return inet_ntoa(addr->sin_addr);
    }
}