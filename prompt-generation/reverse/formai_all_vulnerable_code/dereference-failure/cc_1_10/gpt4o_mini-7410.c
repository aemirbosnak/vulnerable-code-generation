//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <sys/socket.h>

#define BUFFER_SIZE 65536
#define ALLOW 1
#define BLOCK 0

// Define a rule structure
typedef struct Rule {
    struct in_addr src_ip;
    int src_port;
    int action; // ALLOW or BLOCK
} Rule;

// Global rules array
Rule rules[100];
int rule_count = 0;

// Function to add a rule
void add_rule(const char *ip, int port, int action) {
    if (rule_count >= 100) {
        fprintf(stderr, "Max rule limit reached!\n");
        return;
    }
    inet_pton(AF_INET, ip, &rules[rule_count].src_ip);
    rules[rule_count].src_port = port;
    rules[rule_count].action = action;
    rule_count++;
}

// Function to check if a packet matches any rule
int check_rules(struct iphdr *ip_header, struct tcphdr *tcp_header) {
    for (int i = 0; i < rule_count; i++) {
        if (rules[i].src_ip.s_addr == ip_header->saddr && 
            (ntohs(tcp_header->source) == rules[i].src_port)) {
            return rules[i].action;
        }
    }
    return ALLOW; // Default is allow if no rules match
}

// Function to process packets
void process_packet(unsigned char *buffer, ssize_t size) {
    struct iphdr *ip_header = (struct iphdr *)buffer;

    if (ip_header->protocol == IPPROTO_TCP) {
        struct tcphdr *tcp_header = (struct tcphdr *)(buffer + (ip_header->ihl * 4));
        
        int action = check_rules(ip_header, tcp_header);
        if (action == BLOCK) {
            printf("Packet from %s:%d blocked!\n", inet_ntoa(*(struct in_addr *)&ip_header->saddr), ntohs(tcp_header->source));
            return;
        }
        printf("Packet from %s:%d allowed.\n", inet_ntoa(*(struct in_addr *)&ip_header->saddr), ntohs(tcp_header->source));
    }
}

// Main function
int main() {
    int socket_fd;
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);
    
    // Create raw socket
    socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (socket_fd < 0) {
        perror("Socket creation failed");
        return 1;
    }
    
    // Set incoming packet filter options
    int opt = 1;
    if (setsockopt(socket_fd, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(opt)) < 0) {
        perror("Setsockopt failed");
        return 1;
    }

    // Example rules
    add_rule("192.168.1.10", 80, BLOCK);
    add_rule("10.0.0.5", 443, BLOCK);
    
    // Listening for packets
    while (1) {
        ssize_t size = recv(socket_fd, buffer, BUFFER_SIZE, 0);
        if (size < 0) {
            perror("Failed to receive packet");
            break;
        }
        process_packet(buffer, size);
    }

    close(socket_fd);
    free(buffer);
    
    return 0;
}