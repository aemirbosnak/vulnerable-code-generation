//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_INTERVAL 1

// Function to calculate checksum
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

// Function to create ICMP packet
void create_icmp_packet(struct icmp *icmp_packet) {
    icmp_packet->icmp_type = ICMP_ECHO;
    icmp_packet->icmp_code = 0;
    icmp_packet->icmp_id = getpid();
    icmp_packet->icmp_seq = 1;
    memset(icmp_packet->icmp_data, 0, PACKET_SIZE);
    icmp_packet->icmp_cksum = checksum(icmp_packet, sizeof(struct icmp));
}

// Function to send ping request
int send_ping(int sockfd, struct sockaddr_in *addr) {
    struct icmp icmp_packet;
    create_icmp_packet(&icmp_packet);
    return sendto(sockfd, &icmp_packet, sizeof(icmp_packet), 0, (struct sockaddr *)addr, sizeof(*addr));
}

// Function to receive ping response
int receive_ping(int sockfd) {
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    char buffer[PACKET_SIZE];
    int bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &len);
    
    if (bytes_received < 0) {
        perror("Error receiving data");
        return -1;
    }
    
    struct iphdr *ip_header = (struct iphdr *)buffer;
    struct icmp *icmp_response = (struct icmp *)(buffer + (ip_header->ihl * 4));

    if (icmp_response->icmp_type == ICMP_ECHOREPLY) {
        return 0; // Successful response
    }
    return -1; // Not a valid ICMP Echo response
}

// Function to perform ping test
void ping_test(char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr;

    // Create a raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    
    printf("Pinging %s...\n", ip_addr);

    while (1) {
        if (send_ping(sockfd, &addr) < 0) {
            perror("Ping request failed");
            break;
        }
        
        if (receive_ping(sockfd) == 0) {
            printf("Reply from %s: bytes=%d\n", ip_addr, PACKET_SIZE);
        } else {
            printf("No reply from %s\n", ip_addr);
        }

        sleep(PING_INTERVAL);
    }

    close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping_test(argv[1]);
    return 0;
}