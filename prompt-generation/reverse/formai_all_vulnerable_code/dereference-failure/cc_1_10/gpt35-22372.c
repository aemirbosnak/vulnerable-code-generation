//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>

/* Define the packet structure */
struct ping_packet {
    struct icmphdr hdr;
    char msg[64-sizeof(struct icmphdr)];
};

struct sockaddr_in host;

/* Function to calculate checksum */
unsigned short checksum(void *b, int len) {    
    unsigned short *buf = b;    
    unsigned int sum=0;    
    for (sum=0; len>1; len-=2)        
        sum += *buf++;    
    if (len==1)        
        sum += *(unsigned char*)buf;    
    sum = (sum >> 16) + (sum & 0xFFFF);    
    sum += (sum >> 16);    
    return ~sum;    
} 

/* Function to send the ICMP echo request packet */
int send_ping(int sock, struct sockaddr_in *addr, int seq) {
    struct ping_packet packet;
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.code = 0;
    packet.hdr.un.echo.id = getpid();
    packet.hdr.un.echo.sequence = seq;
    strcpy(packet.msg, "Test message");

    /* Calculate checksum and assign to packet */
    packet.hdr.checksum = 0;
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    /* Send packet and verify */
    if (sendto(sock, &packet, sizeof(packet), 0, (struct sockaddr*)addr, sizeof(*addr)) <= 0) {
        printf("Sendto error\n");
        return -1;
    }
    return 0;
}

/* Function to receive the ICMP echo reply packet */
int receive_ping(int sock) {
    char buf[1024];

    /* Set timeout for incoming packets */
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
        printf("Setsockopt error\n");
        return -1;
    }

    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);

    /* Receive packet and verify checksum */
    if (recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr*)&addr, &len) <= 0) {
        printf("Recvfrom error\n");
        return -1;
    }
    struct iphdr *ip = (struct iphdr*)buf;
    struct icmphdr *icmp = (struct icmphdr*)(buf + (ip->ihl<<2));
    if (icmp->type == ICMP_ECHOREPLY && icmp->un.echo.id == getpid()) {
        printf("Reply from %s: %d bytes in %dms\n", inet_ntoa(addr.sin_addr), 
        ntohs(ip->tot_len), 1000*(timeout.tv_sec)+timeout.tv_usec/1000);
        return 0;
    }
    return -1;
}

/* Main function */
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return -1;
    }

    memset(&host, 0, sizeof(host));
    host.sin_family = AF_INET;

    /* get host information */
    struct hostent* he;
    if ((he = gethostbyname(argv[1])) == NULL) {
        printf("Gethostname error\n");
        return -1;
    }
    memcpy(&host.sin_addr, he->h_addr_list[0], he->h_length);

    /* Create socket and set options */
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        printf("Socket error\n");
        return -1;
    }
    if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &(int){1}, sizeof(int)) < 0) {
        printf("Setsockopt error\n");
        return -1;
    }

    /* Ping the host 10 times */
    printf("Pinging %s [%s] with 64 bytes of data:\n", argv[1], inet_ntoa(host.sin_addr));
    int i;
    for (i = 1; i <= 10; i++) {
        if (send_ping(sock, &host, i) < 0) {
            printf("Send ping error\n");
            return -1;
        }
        if (receive_ping(sock) < 0) {
            printf("Receive ping error\n");
            return -1;
        }
        sleep(1);
    }
    return 0;
}