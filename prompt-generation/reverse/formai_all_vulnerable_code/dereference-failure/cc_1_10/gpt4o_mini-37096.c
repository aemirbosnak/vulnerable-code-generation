//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>

#define BUFFER_SIZE 65536
#define ALLOWED_IP "192.168.1.1"

void process_packet(unsigned char *buffer, int size) {
    struct iphdr *ip = (struct iphdr*) buffer;

    if (ip->protocol == IPPROTO_ICMP) {
        struct in_addr src_addr;
        src_addr.s_addr = ip->saddr;

        if (strcmp(inet_ntoa(src_addr), ALLOWED_IP) == 0) {
            printf("[ALLOWED]: Packet from %s\n", inet_ntoa(src_addr));
        } else {
            printf("[BLOCKED]: Packet from %s\n", inet_ntoa(src_addr));
        }
    }
}

int main() {
    int sockfd;
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);
    struct sockaddr_in addr;
    int addr_len = sizeof(addr);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }
    
    while (1) {
        int data_size = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&addr, (socklen_t*)&addr_len);
        if (data_size < 0) {
            perror("Packet recv failed");
            close(sockfd);
            free(buffer);
            return 1;
        }

        process_packet(buffer, data_size);
    }

    close(sockfd);
    free(buffer);
    return 0;
}