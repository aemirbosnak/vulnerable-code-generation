//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>

#define PACKETSIZE 64

struct icmp_packet {
    struct icmphdr hdr;
    char msg[PACKETSIZE-sizeof(struct icmphdr)];
};

unsigned short calculate_checksum(void *addr, int len){
    unsigned short *buffer = addr;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2){
        sum += *buffer++;
    }

    if (len == 1){
        sum += *(unsigned char*) buffer;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

int main(int argc, char** argv){
    struct hostent *host = NULL;
    struct sockaddr_in addr;
    struct icmp_packet packet;
    int sockfd, reply_sockfd, packet_size;
    unsigned int ttl = 1, seq = 0;
    char *hostname;
    char recv_buf[PACKETSIZE];
    double elapsed_time = 0;
    struct timeval start, end;

    if (argc < 2){
        printf("Please provide hostname or IP address.\n");
        exit(1);
    }

    hostname = argv[1];
    inet_pton(AF_INET, hostname, &addr.sin_addr);

    if (addr.sin_addr.s_addr == 0){
        host = gethostbyname(hostname);

        if (host == NULL){
            printf("Could not resolve host name.\n");
            exit(1);
        }
 
        memcpy(&addr.sin_addr, host->h_addr_list[0], host->h_length);
    }

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0){
        printf("Could not create socket.\n");
        exit(1);
    }

    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();

    packet_size = sizeof(packet.hdr) + sizeof(packet.msg);
    packet.hdr.checksum = calculate_checksum(&packet, packet_size);

    printf("PING %s (%s) %d bytes of data.\n", hostname, inet_ntoa(addr.sin_addr), packet_size);

    while (ttl < 31){
        socklen_t len = sizeof(struct sockaddr_in);
        setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));
        seq++;
        gettimeofday(&start, NULL);
        packet.hdr.un.echo.sequence = seq;
        packet.hdr.checksum = 0;
        packet.hdr.checksum = calculate_checksum(&packet, packet_size);

        if (sendto(sockfd, &packet, packet_size, 0, (struct sockaddr*) &addr, sizeof(addr)) <= 0){
            printf("Could not send packet.\n");
            break;
        }

        if ((reply_sockfd = recvfrom(sockfd, recv_buf, PACKETSIZE, 0, (struct sockaddr*) &addr, &len)) <= 0){
            printf("Timeout expired.\n");
        } else {
            struct timeval tv;
            gettimeofday(&end, NULL);
            tv.tv_sec = end.tv_sec - start.tv_sec;
            tv.tv_usec = end.tv_usec - start.tv_usec;

            if (tv.tv_usec < 0){
                tv.tv_sec--;
                tv.tv_usec += 1000000;
            }

            elapsed_time = ((double) tv.tv_sec) * 1000.0 + ((double) tv.tv_usec) / 1000.0;

            struct icmphdr *icmp_hdr = (struct icmphdr*) recv_buf;

            if ((icmp_hdr->type == ICMP_ECHOREPLY) && (icmp_hdr->un.echo.id == getpid())){
                struct in_addr inaddr = addr.sin_addr;
                printf("%d bytes from %s (%s): icmp_seq=%d ttl=%d time=%.2f ms\n", reply_sockfd, hostname, inet_ntoa(inaddr), icmp_hdr->un.echo.sequence, ttl, elapsed_time);
            }
        }

        ttl++;
        sleep(1);
    }

    close(sockfd);
    exit(0);
}