//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <time.h>

#define PACKET_SIZE 64
#define MAX_HOPS 30

static char recv_packet[PACKET_SIZE];
static char send_packet[PACKET_SIZE];

// Calculate the internet checksum
unsigned short calculate_checksum(unsigned short *paddress, int len) {
    int nleft = len;
    int sum = 0;
    unsigned short* w = paddress;
    unsigned short answer = 0;
    while (nleft > 1) {
        sum += *w++;
        nleft -= 2;
    }
    if (nleft == 1) {
        *(unsigned char*)(&answer) = *(unsigned char*)w;
        sum += answer;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = ~sum;
    return answer;
}

// Ping the host at the given IP address/IP name
void ping_host(char *ip_address) {
    struct sockaddr_in dest;
    struct timeval start, end;
    struct icmp* icmp;
    int sockfd, ttl, nbytes, recv_len, hlen;
    double rtt;
    struct hostent* host;
    char host_ip[16];
    memset(&dest, 0, sizeof(dest));
    inet_pton(AF_INET, ip_address, &dest.sin_addr);
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);    
    ttl = 1;
    setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int));
    memset(send_packet, 0, sizeof(send_packet));
    icmp = (struct icmp*)send_packet;    
    icmp->icmp_type = ICMP_ECHO;        
    icmp->icmp_code = 0;
    icmp->icmp_id = getpid();
    icmp->icmp_seq = 0;
    gettimeofday(&start, NULL);        
    icmp->icmp_cksum = calculate_checksum((unsigned short*)icmp, PACKET_SIZE);    
    nbytes = sendto(sockfd, send_packet, sizeof(send_packet), 0, (struct sockaddr*)&dest, sizeof(dest));
    if (nbytes <= 0) {
        printf("Packet delivery failed\n");
        close(sockfd);
        return;
    }
    hlen = 0;
    memset(recv_packet, 0, sizeof(recv_packet));
    recv_len = recv(sockfd, recv_packet, sizeof(recv_packet), 0);
    gettimeofday(&end, NULL);
    rtt = (double)(end.tv_sec - start.tv_sec) * 1000 + (double)(end.tv_usec - start.tv_usec) / 1000;
    if (recv_packet[hlen + 20] != getpid()) {
        printf("Packet delivery failed\n");
        close(sockfd);
        return;
    }    
    printf("%d bytes from %s (%s): icmp_seq=%d ttl=%d time=%.3f ms\n", PACKET_SIZE, inet_ntoa(dest.sin_addr), ip_address, icmp->icmp_seq, ttl, rtt);
    close(sockfd);
} 

// Traceroute the host at the given IP address/IP name
void traceroute_host(char *ip_address) {
    struct sockaddr_in dest;
    struct timeval start, end;
    struct icmp* icmp;
    struct hostent* host;
    char host_ip[16];
    int sockfd, ttl, nbytes, recv_len, hlen, i;
    double rtt;
    memset(&dest, 0, sizeof(dest));
    inet_pton(AF_INET, ip_address, &dest.sin_addr);
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); 
    icmp = (struct icmp*)send_packet; 
    gettimeofday(&start, NULL);   
    for (i = 1; i <= MAX_HOPS; i++) {
        ttl = i; 
        setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int));
        icmp->icmp_type = ICMP_ECHO;   
        icmp->icmp_code = 0;
        icmp->icmp_id = getpid();
        icmp->icmp_seq = i;
        icmp->icmp_cksum = 0;
        icmp->icmp_cksum = calculate_checksum((unsigned short*)icmp, PACKET_SIZE);    
        memset(recv_packet, 0, sizeof(recv_packet));
        nbytes = sendto(sockfd, send_packet, sizeof(send_packet), 0, (struct sockaddr*)&dest, sizeof(dest));
        if (nbytes <= 0) {
            printf("Packet delivery failed\n");
            close(sockfd);
            return;
        }        
        recv_len = recv(sockfd, recv_packet, sizeof(recv_packet), 0);
        gettimeofday(&end, NULL);
        rtt = (double)(end.tv_sec - start.tv_sec) * 1000 + (double)(end.tv_usec - start.tv_usec) / 1000;
        if (recv_packet[hlen + 20] != getpid()) {
            printf("Packet delivery failed\n");
            close(sockfd);
            return;
        }        
        host = gethostbyaddr((char*)&dest.sin_addr, sizeof(dest.sin_addr), AF_INET);
        if (host == NULL) {
            printf("%d traceroute hop(s) away: no response\n", i);
        }
        else {
            strncpy(host_ip, inet_ntoa(dest.sin_addr), sizeof(host_ip));
            printf("%d traceroute hop(s) away: %s (%s) time=%.3f ms\n", i, host->h_name, host_ip, rtt);
        } 
    } 
    close(sockfd);
}

int main(int argc, char** argv) {
    char *ip_address;
    int mode = 0;
    if (argc == 1) {
        printf("Usage: ping <IP address>/<host name> <-t for traceroute>\n");
        return 0;
    }
    else if (argc == 2) {
        ip_address = argv[1];
    }
    else {
        ip_address = argv[1];
        if (strcmp(argv[2], "-t") == 0) {
            mode = 1;
        }
    }
    if (mode == 0) {
        printf("Pinging %s\n", ip_address);
        ping_host(ip_address);
    }
    else {
        printf("Tracerouting %s\n", ip_address);
        traceroute_host(ip_address);
    }
    return 0;
}