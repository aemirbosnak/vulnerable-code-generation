//FormAI DATASET v1.0 Category: Network Ping Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/time.h>

#define MAX_TIMEOUT 5
#define MAX_RETRIES 3
#define PACKET_SIZE 64

/* Function to calculate checksum */
unsigned short calculate_checksum(unsigned short *ptr, int length)
{
    unsigned long sum = 0;
    
    while (length > 1) {
        sum += *ptr++;
        length -= 2;
    }
    
    if (length == 1) {
        sum += *(unsigned char *)ptr;
    }
    
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    
    return (unsigned short)(~sum);
}

/* Function to send ICMP echo request */
int send_echo_request(int sockfd, struct sockaddr *addr, int seq_num)
{
    char packet[PACKET_SIZE];
    memset(packet, 0, PACKET_SIZE);
    
    struct icmphdr *icmp_header = (struct icmphdr *) packet;
    icmp_header->type = ICMP_ECHO;
    icmp_header->code = 0;
    icmp_header->un.echo.id = getpid();
    icmp_header->un.echo.sequence = seq_num;
    icmp_header->checksum = calculate_checksum((unsigned short *)icmp_header, PACKET_SIZE);
    
    if (sendto(sockfd, packet, PACKET_SIZE, 0, addr, sizeof(*addr)) < 0) {
        perror("sendto() error");
        return -1;
    }
    
    return 0;
}

/* Function to receive ICMP echo response */
int receive_echo_response(int sockfd, struct sockaddr *addr, int seq_num)
{
    char packet[PACKET_SIZE];
    socklen_t addr_len = sizeof(*addr);
    
    struct timeval timeout;
    timeout.tv_sec = MAX_TIMEOUT;
    timeout.tv_usec = 0;
    
    fd_set read_set;
    FD_ZERO(&read_set);
    FD_SET(sockfd, &read_set);
    
    int ret = select(sockfd+1, &read_set, NULL, NULL, &timeout);
    
    if (ret < 0) {
        perror("select() error");
        return -1;
    }
    
    if (ret == 0) {
        printf("Request timed out\n");
        return -1;
    }
    
    if (recvfrom(sockfd, packet, PACKET_SIZE, 0, addr, &addr_len) < 0) {
        perror("recvfrom() error");
        return -1;
    }
    
    struct iphdr *ip_header = (struct iphdr *) packet;
    struct icmphdr *icmp_header = (struct icmphdr *) (packet + (ip_header->ihl*4));
    
    if (icmp_header->type == ICMP_ECHOREPLY && icmp_header->un.echo.id == getpid() && icmp_header->un.echo.sequence == seq_num) {
        return 0;
    }
    
    return -1;
}

/* Function to perform ping test */
int ping_test(char *host)
{
    struct hostent *hostent;
    hostent = gethostbyname(host);
    
    if (hostent == NULL) {
        printf("Host not found\n");
        return -1;
    }
    
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    
    if (sockfd < 0) {
        perror("socket() error");
        return -1;
    }
    
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = *(long *)hostent->h_addr;
    
    int seq_num = 1;
    
    for (int i = 1; i <= MAX_RETRIES; i++) {
        sleep(1); /* Wait for 1 second between retries */
        printf("Pinging %s with %d bytes of data, attempt %d\n", host, PACKET_SIZE, i);
        
        if (send_echo_request(sockfd, (struct sockaddr *)&addr, seq_num) < 0) {
            return -1;
        }
        
        if (receive_echo_response(sockfd, (struct sockaddr *)&addr, seq_num) < 0) {
            continue;
        }
        
        printf("Reply from %s: bytes=%d time=1ms TTL=%d\n", host, PACKET_SIZE, 64);
        break;
    }
    
    close(sockfd);
    
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        return -1;
    }
    
    ping_test(argv[1]);
    
    return 0;
}