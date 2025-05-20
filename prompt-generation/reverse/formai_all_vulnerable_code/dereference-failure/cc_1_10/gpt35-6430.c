//FormAI DATASET v1.0 Category: Firewall ; Style: scientific
// A Unique C Firewall Example Program
// By [Your Name]
// Date: [Date]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define PACKET_SIZE 65536
#define IPPROTO_ICMP 1
#define IPPROTO_TCP 6
#define IPPROTO_UDP 17

// Function to display error messages
void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Function to validate IP address
int validateIpAddress(char *ipAddress) {
    struct sockaddr_in sa;
    inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    return sa.sin_addr.s_addr != 0;
}

// Function to check port range
int checkPort(char *port, char *proto) {
    int portNum = atoi(port);
    if (proto == "TCP" && (portNum >= 1 && portNum <= 65535)) {
        return 1;
    } else if (proto == "UDP" && (portNum >= 1 && portNum <= 65535)) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr, myaddr;
    char packet_buffer[PACKET_SIZE];
    unsigned long pkt_count = 0;
    char *src_ip, *dst_ip, *src_port, *dst_port, *proto;

    // Validate input arguments
    if (argc != 6) {
        fprintf(stderr,"usage: %s <src_ip> <dst_ip> <src_port> <dst_port> <tcp/udp>\n", argv[0]);
        exit(1);
    }

    // Get source and destination IP addresses
    src_ip = argv[1];
    dst_ip = argv[2];

    // Validate IP addresses
    if (!validateIpAddress(src_ip) || !validateIpAddress(dst_ip)) {
        error("Invalid IP address");
    }

    // Get source port
    src_port = argv[3];
    if (!checkPort(src_port, argv[5])) {
        error("Invalid source port number");
    }

    // Get destination port
    dst_port = argv[4];
    if (!checkPort(dst_port, argv[5])) {
        error("Invalid destination port number");
    }

    // Get protocol type
    proto = argv[5];
    if (strcmp(proto, "TCP") != 0 && strcmp(proto, "UDP") != 0) {
        error("Invalid protocol type");
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) == -1) {
        error("Error creating socket");
    }

    // Set socket options
    const int on = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) == -1) {
        error("Error setting socket options");
    }

    // Create packet buffer
    memset(packet_buffer, 0, PACKET_SIZE);
    struct iphdr *ip_header = (struct iphdr *) packet_buffer;
    struct tcphdr *tcp_header = (struct tcphdr *) (packet_buffer + sizeof(struct iphdr));

    // Set source and destination IP addresses
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(dst_port));
    inet_pton(AF_INET, dst_ip, &(servaddr.sin_addr));

    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(atoi(src_port));
    inet_pton(AF_INET, src_ip, &(myaddr.sin_addr));

    // Fill in IP header
    ip_header->ihl = 5;
    ip_header->version = 4;
    ip_header->tos = 0;
    ip_header->tot_len = sizeof(struct iphdr) + sizeof(struct tcphdr);
    ip_header->id = htons(31337);
    ip_header->frag_off = 0;
    ip_header->ttl = 255;
    ip_header->protocol = proto == "TCP" ? IPPROTO_TCP : IPPROTO_UDP;
    ip_header->check = 0;
    ip_header->saddr = myaddr.sin_addr.s_addr;
    ip_header->daddr = servaddr.sin_addr.s_addr;

    // Fill in TCP header
    tcp_header->th_sport = htons(atoi(src_port));
    tcp_header->th_dport = htons(atoi(dst_port));
    tcp_header->th_seq = htonl(0);
    tcp_header->th_ack = htonl(0);
    tcp_header->th_x2 = 0;
    tcp_header->th_off = sizeof(struct tcphdr) / 4;
    tcp_header->th_flags = proto == "TCP" ? TH_SYN : 0;
    tcp_header->th_win = htons(16384);
    tcp_header->th_sum = 0;
    tcp_header->th_urp = 0;

    // Send packet
    if ((n = sendto(sockfd, packet_buffer, ip_header->tot_len, 0, (struct sockaddr *)&servaddr, sizeof(servaddr))) < 0) {
        error("Error sending packet");
    }

    printf("Packet sent successfully.\n");

    return 0;
}