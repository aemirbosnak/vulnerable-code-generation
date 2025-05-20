//FormAI DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <math.h>

#define PACKETSIZE      64
#define ICMP_HDR_SIZE   sizeof(struct icmphdr)
#define MAX_HOPS        30
#define MAX_TRIES       3
#define WAIT_MSEC       3000

// Compute check sum
unsigned short check_sum(void *b, int len) {    
    unsigned short *buf = b; 
    unsigned int sum=0; 

    for(sum=0; len>1; len-=2) sum += *buf++; 
    if(len==1) sum += *(unsigned char*)buf;  
    sum = (sum >> 16) + (sum & 0xFFFF); 
    sum += (sum >> 16); 
    return ~sum; 
}

// Send ICMP packet
void send_packet(int sock, struct sockaddr_in *dest_addr, int ttl, int seq) {
    struct icmphdr icmp_hdr = {0};
    struct timespec ts = {0};
    char packet[PACKETSIZE] = {0};
    
    // Fill ICMP header
    icmp_hdr.type = ICMP_ECHO;
    icmp_hdr.code = 0;
    icmp_hdr.un.echo.id = getpid();
    icmp_hdr.un.echo.sequence = seq;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    memcpy(packet+ICMP_HDR_SIZE, &ts, sizeof(struct timespec));
    icmp_hdr.checksum = check_sum(&icmp_hdr, ICMP_HDR_SIZE+sizeof(struct timespec));
    
    // Set Time to Live (TTL)
    setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(int));
    
    // Send packet
    memcpy(packet, &icmp_hdr, ICMP_HDR_SIZE);
    sendto(sock, packet, PACKETSIZE, 0, (struct sockaddr*)dest_addr, sizeof(struct sockaddr_in));
}

// Receive ICMP packet
int recv_packet(int sock, struct sockaddr_in *from_addr, int seq, struct timespec *req) {
    struct icmphdr icmp_hdr = {0};
    char packet[PACKETSIZE] = {0};
    int from_addr_len = sizeof(struct sockaddr_in);
    ssize_t bytes_rcvd = 0;
    
    while(1) {
        // Wait for response
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(sock, &rfds);
        struct timeval tv = {0, WAIT_MSEC * 1000};
        int retval = select(sock+1, &rfds, NULL, NULL, &tv);
        if (retval == -1) {
            // Error occurred
            perror("select()");
            return -1;
        } else if (retval == 0) {
            // Timeout occurred
            printf("*\t");
            fflush(stdout);
            return -2;
        }
        
        // Receive packet
        bytes_rcvd = recvfrom(sock, packet, PACKETSIZE, 0, (struct sockaddr*)from_addr, &from_addr_len);
        clock_gettime(CLOCK_MONOTONIC, req);

        // Ignore packets that are not ICMP_ECHOREPLY or with a wrong ID
        memcpy(&icmp_hdr, packet, ICMP_HDR_SIZE);
        if (icmp_hdr.type == ICMP_ECHOREPLY && icmp_hdr.un.echo.id == getpid() && icmp_hdr.un.echo.sequence == seq) {
            printf("%ldms\t", (long)round((req->tv_sec - ((struct timespec *)(packet+ICMP_HDR_SIZE))->tv_sec)*1000.0 + (req->tv_nsec - ((struct timespec *)(packet+ICMP_HDR_SIZE))->tv_nsec)/1000000.0));
            fflush(stdout);
            return 0;
        } else if (icmp_hdr.type == ICMP_TIME_EXCEEDED) {
            printf("!\t");
            fflush(stdout);
            return -3;
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Parse command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const char *hostname = argv[1];
    
    // DNS lookup
    struct addrinfo hints = {0};
    hints.ai_family = AF_INET;
    struct addrinfo *res;
    if (getaddrinfo(hostname, NULL, &hints, &res) != 0) {
        fprintf(stderr, "DNS lookup failed: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        perror("socket()");
        exit(EXIT_FAILURE);
    }
    
    // Connect to target IP address
    struct sockaddr_in dest_addr = {0};
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = ((struct sockaddr_in*)res->ai_addr)->sin_addr.s_addr;
    if (connect(sock, (struct sockaddr*)&dest_addr, sizeof(struct sockaddr)) < 0) {
        perror("connect()");
        exit(EXIT_FAILURE);
    }
    
    int hops;
    for (hops = 1; hops <= MAX_HOPS; hops++) {
        printf("%d: ", hops);

        // Limit number of tries
        int tries;
        for (tries = 1; tries <= MAX_TRIES; tries++) {
            struct timespec req = {0};
            send_packet(sock, &dest_addr, hops, tries);
            if (recv_packet(sock, &dest_addr, tries, &req) == 0) break;
        }

        printf("\n");
        if (tries > MAX_TRIES) {
            // Maximum tries reached, give up
            break;
        } else if (dest_addr.sin_addr.s_addr == ((struct sockaddr_in*)res->ai_addr)->sin_addr.s_addr) {
            // Destination reached, stop
            break;
        }
    }

    close(sock);
    freeaddrinfo(res);
    return EXIT_SUCCESS;
}