//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <time.h>

#define IP_HDRLEN 20
#define ICMP_HDRLEN 8
#define MAX_PACKET_SIZE 65536
#define MAX_INTERFACE_COUNT 128

// Structure for storing interface information
struct interface_info {
    char name[IFNAMSIZ];
    char ip_str[INET_ADDRSTRLEN];
    uint32_t ip_addr;
    uint32_t netmask;
};

// Function to get interface information
int get_interface_info(struct interface_info interface_list[]) {
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if (sock_fd < 0) {
        perror("socket error");
        return -1;
    }
    
    struct ifconf ifc;
    char buf[2048];
    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = buf;
    
    int retcode = ioctl(sock_fd, SIOCGIFCONF, &ifc);
    
    if (retcode < 0) {
        perror("ioctl error");
        return -1;
    }
    
    struct ifreq* ifr = ifc.ifc_req;
    
    for (int i = 0, cnt = 0; i < ifc.ifc_len; ) {
        struct sockaddr_in* sa = (struct sockaddr_in*)&ifr[i].ifr_addr;
        int family = sa->sin_family;
        
        if (family == AF_INET) {
            ++cnt;
            strncpy(interface_list[cnt-1].name, ifr[i].ifr_name, IFNAMSIZ);
            inet_ntop(AF_INET, &sa->sin_addr, interface_list[cnt-1].ip_str, INET_ADDRSTRLEN);
            interface_list[cnt-1].ip_addr = sa->sin_addr.s_addr;
            
            struct ifreq ifr_mask;
            strncpy(ifr_mask.ifr_name, ifr[i].ifr_name, IFNAMSIZ);
            retcode = ioctl(sock_fd, SIOCGIFNETMASK, &ifr_mask);
            
            if (retcode < 0) {
                perror("ioctl error");
                return -1;
            }
            
            struct sockaddr_in* sa_mask = (struct sockaddr_in*)&ifr_mask.ifr_netmask;
            interface_list[cnt-1].netmask = sa_mask->sin_addr.s_addr;
        }
        
        i += sizeof(struct ifreq);
    }
    
    return 0;
}

// Function to prepare packet
int prepare_packet(uint8_t* packet, uint32_t src_addr, uint32_t dest_addr) {
    struct ip* ip_hdr = (struct ip*)packet;
    ip_hdr->ip_v = 4;
    ip_hdr->ip_hl = IP_HDRLEN / 4;
    ip_hdr->ip_tos = 0;
    ip_hdr->ip_len = htons(MAX_PACKET_SIZE);
    ip_hdr->ip_id = htons(0);
    ip_hdr->ip_off = 0;
    ip_hdr->ip_ttl = 64;
    ip_hdr->ip_p = IPPROTO_ICMP;
    ip_hdr->ip_src.s_addr = src_addr;
    ip_hdr->ip_dst.s_addr = dest_addr;
    ip_hdr->ip_sum = htons(0);
    
    uint8_t* icmp_packet = packet + IP_HDRLEN;
    icmp_packet[0] = 8;
    icmp_packet[1] = 0;
    * (uint16_t*) (icmp_packet + 2) = htons(0);
    * (uint16_t*) (icmp_packet + 4) = htons(0);
    * (uint32_t*) (icmp_packet + 8) = htonl(time(NULL));
    
    uint16_t checksum = 0;
    
    for (int i = 0; i < ICMP_HDRLEN; i += 2) {
        checksum += * (uint16_t*) (icmp_packet + i);
    }
    
    checksum = (checksum & 0xffff) + (checksum >> 16);
    checksum = ~checksum;
    * (uint16_t*) (icmp_packet + 2) = htons(checksum);
    
    return IP_HDRLEN + ICMP_HDRLEN;
}

// Function to scan network
void scan_network(char* ip_str) {
    uint32_t src_addr, dest_addr;
    int interface_count;
    struct interface_info interface_list[MAX_INTERFACE_COUNT];
    uint8_t packet[MAX_PACKET_SIZE];
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(0);
    
    if (inet_pton(AF_INET, ip_str, &dest_addr) <= 0) {
        perror("inet_pton error");
        return;
    }
    
    if (get_interface_info(interface_list) < 0) {
        perror("get_interface_info error");
        return;
    }
    
    interface_count = sizeof(interface_list) / sizeof(interface_list[0]);
    
    for (int i = 0; i < interface_count; ++i) {
        src_addr = interface_list[i].ip_addr;
        sin.sin_addr.s_addr = src_addr;
        
        int sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
        
        if (sock_fd < 0) {
            perror("socket error");
            continue;
        }
        
        setsockopt(sock_fd, IPPROTO_IP, IP_HDRINCL, &(int){1}, sizeof(int));
        setsockopt(sock_fd, SOL_SOCKET, SO_BINDTODEVICE, interface_list[i].name, IFNAMSIZ);
        
        uint16_t packet_size = prepare_packet(packet, src_addr, dest_addr);
        
        if (sendto(sock_fd, packet, packet_size, 0, (struct sockaddr*)&sin, sizeof(sin)) < 0) {
            perror("sendto error");
        }
        
        uint8_t buffer[MAX_PACKET_SIZE];
        struct sockaddr_in recv_addr;
        socklen_t addr_len = sizeof(recv_addr);
        fd_set read_set;
        struct timeval timeout;
        timeout.tv_sec = 2;
        timeout.tv_usec = 0;
        
        FD_ZERO(&read_set);
        FD_SET(sock_fd, &read_set);
        
        if (select(sock_fd + 1, &read_set, NULL, NULL, &timeout) > 0) {
            int n = recvfrom(sock_fd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr*)&recv_addr, &addr_len);
            
            if (n <= 0) {
                perror("recvfrom error");
            } else if (recv_addr.sin_addr.s_addr == dest_addr) {
                printf("Device found on %s interface!\n", interface_list[i].name);
            }
        }
        
        close(sock_fd);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        return 0;
    }
    
    char* ip_str = argv[1];
    scan_network(ip_str);
    return 0;
}