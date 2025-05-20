//FormAI DATASET v1.0 Category: Network Ping Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>
#include <signal.h>
#include <sys/time.h>

// Function to calculate checksum
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum=0;
    unsigned short result;

    for ( sum = 0; len > 1; len -= 2 ) {
        sum += *buf++;
    }

    if ( len == 1 ) {
        sum += *(unsigned char*)buf;
    }

    sum = ( sum >> 16 ) + ( sum & 0xFFFF );
    sum += ( sum >> 16 );
    result = ~sum;
    return result;
}

int ping(char *ip_addr) {
    struct sockaddr_in server;
    int sockfd, val = 1, seq_no = 0;
    char buffer[1024];
    unsigned char *data = buffer + sizeof(struct icmphdr);
    struct icmphdr *icmp_hdr = (struct icmphdr*)buffer;
    struct timeval timestamp;
    struct timeval timeout;
    struct sockaddr_in response_addr;
    socklen_t from_size = sizeof(response_addr);
    struct hostent *host = gethostbyname(ip_addr);

    if ( host == NULL ) {
        printf("Could not resolve host\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if ( sockfd < 0 ) {
        printf("Could not create socket\n");
        return -1;
    }

    timeout.tv_sec = 2;
    timeout.tv_usec = 0;

    if ( setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1 ) {
        printf("Error setting socket options\n");
        return -1;
    }

    if ( setsockopt(sockfd, IPPROTO_IP, IP_TTL, &val, sizeof(val)) == -1) {
        printf("Error setting socket options\n");
        return -1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr = *((struct in_addr*)host->h_addr);

    printf("Starting ping...\n");

    while ( seq_no++ < 10 ) {
        bzero(buffer, sizeof(buffer));
        icmp_hdr->type = ICMP_ECHO;
        icmp_hdr->code = 0;
        icmp_hdr->un.echo.id = getpid();
        icmp_hdr->un.echo.sequence = seq_no;
        memset(data, 255, 1024 - sizeof(struct icmphdr));

        gettimeofday(&timestamp, NULL);
        icmp_hdr->checksum = 0;
        icmp_hdr->checksum = checksum(icmp_hdr, sizeof(struct icmphdr) + 1024);
        
        if ( sendto(sockfd, buffer, sizeof(struct icmphdr) + 1024, 0, (struct sockaddr*) &server, sizeof(server)) <= 0 ) {
            printf("Error sending packet\n");
        }

        if ( recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&response_addr, &from_size) < 0 ) {
            printf("No response from server (%s)\n", ip_addr);
        } else {
            gettimeofday(&timestamp, NULL);

            printf("Ping response from %s: icmp_seq=%d time=%lu us\n", ip_addr, seq_no, ((timestamp.tv_sec * 1000000) + timestamp.tv_usec));
        }

        sleep(1);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if ( argc != 2 ) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return -1;
    }

    return ping(argv[1]);
}