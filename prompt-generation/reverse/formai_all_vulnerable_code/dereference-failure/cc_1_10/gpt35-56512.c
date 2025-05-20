//FormAI DATASET v1.0 Category: Firewall ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 65536

// Function to filter incoming packets and block malicious traffic
void process_packet(unsigned char* buffer, int size){
    // Extract the IP header from the packet
    struct iphdr *ip_header = (struct iphdr *) buffer;
    if(ip_header->protocol != IPPROTO_TCP) return; // Only handle TCP traffic

    // Extract the TCP header from the packet
    struct tcphdr *tcp_header = (struct tcphdr*) (buffer + sizeof(struct iphdr));

    // Check if incoming traffic is malicious based on rules defined below
    if(ntohs(tcp_header->dest) == 22 || ntohs(tcp_header->dest) == 23){
        printf("Blocking SSH/Telnet traffic from source IP: %s\n", inet_ntoa((struct in_addr) {ip_header->saddr}));
        return; // Block traffic
    }
    else if(ntohs(tcp_header->dest) == 80 || ntohs(tcp_header->dest) == 443){
        char *http_data = (char *) (buffer + sizeof(struct iphdr) + sizeof(struct tcphdr));
        if(strstr(http_data, "malware")){
            printf("Blocking HTTP/HTTPS traffic from source IP: %s\n", inet_ntoa((struct in_addr) {ip_header->saddr}));
            return; // Block traffic
        }
    }

    // If incoming traffic isn't malicious, let it pass through
    printf("Allowing traffic from source IP: %s\n", inet_ntoa((struct in_addr) {ip_header->saddr}));
    return;
}

int main(){
    int socket_raw;
    struct sockaddr_in servaddr;

    // Create a raw socket to handle incoming packets
    socket_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (socket_raw < 0) {
        perror("Error: Failed to create socket");
        return -1;
    }

    // Bind socket to port 0 to capture all incoming traffic
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = 0;

    if (bind(socket_raw, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        perror("Error: Failed to bind socket");
        return -1;
    }

    // Listen for incoming traffic
    unsigned char *buffer = malloc(MAX_PACKET_SIZE);
    while(1){
        int recv_size = recv(socket_raw, buffer, MAX_PACKET_SIZE, 0);
        if(recv_size > 0) process_packet(buffer, recv_size);
    }

    free(buffer);
    close(socket_raw);
    return 0;
}