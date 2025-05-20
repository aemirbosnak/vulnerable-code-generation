//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: Cryptic
#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
#include <unistd.h>    
#include <arpa/inet.h>    
#include <netinet/ip.h>    
#include <netinet/tcp.h>    
#include <sys/types.h>    
#include <sys/socket.h>    
#include <errno.h>    

#define PORT 8080    
#define BLOCKED_IP "192.168.1.100"    
#define BUF_SIZE 1024    

void block_ip(char *ip) {    
    printf("Blocking IP: %s\n", ip);    
    // Placeholder for actual firewall logic, e.g., iptables
}    

int is_blocked_ip(char *src_ip) {    
    return strcmp(src_ip, BLOCKED_IP) == 0;    
}    

void handle_packet(unsigned char *buffer, int size) {    
    struct iphdr *iph = (struct iphdr *)buffer;    
    struct sockaddr_in source, dest;    

    memset(&source, 0, sizeof(source));    
    memset(&dest, 0, sizeof(dest));    

    source.sin_addr.s_addr = iph->saddr;    
    dest.sin_addr.s_addr = iph->daddr;    

    printf("Source IP: %s\n", inet_ntoa(source.sin_addr));    
    printf("Destination IP: %s\n", inet_ntoa(dest.sin_addr));    

    if (is_blocked_ip(inet_ntoa(source.sin_addr))) {    
        printf("Blocked packet from %s\n", BLOCKED_IP);    
        block_ip(BLOCKED_IP);    
        return;    
    }    

    printf("Packet from %s allowed.\n", inet_ntoa(source.sin_addr));    
}    

int create_raw_socket() {    
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);    
    if (sockfd < 0) {    
        perror("Socket creation failed");    
        exit(1);    
    }    
    return sockfd;    
}    

void main_loop() {    
    unsigned char *buffer = (unsigned char *)malloc(BUF_SIZE);    
    int sockfd = create_raw_socket();    
    struct sockaddr saddr;    
    socklen_t saddr_len = sizeof(saddr);    

    while (1) {    
        int packet_size = recvfrom(sockfd, buffer, BUF_SIZE, 0, &saddr, &saddr_len);    
        if (packet_size < 0) {    
            perror("Failed to receive packet");    
            continue;    
        }    
        handle_packet(buffer, packet_size);    
    }    
    free(buffer);    
    close(sockfd);    
}    

int main() {    
    printf("Starting Firewall...\n");    
    printf("Listening for incoming packets...\n");    
    main_loop();    
    return 0;    
}