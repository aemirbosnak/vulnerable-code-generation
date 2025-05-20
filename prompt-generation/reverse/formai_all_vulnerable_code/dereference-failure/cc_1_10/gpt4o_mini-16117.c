//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>
#include <pthread.h>

#define BUFFER_SIZE 65536

// Packet options
#define ALLOW_TCP 1
#define ALLOW_UDP 2

// Function to check protocol type
int allow_packet(int protocol_type) {
    if (protocol_type == IPPROTO_TCP) {
        return ALLOW_TCP;
    } else if (protocol_type == IPPROTO_UDP) {
        return ALLOW_UDP;
    }
    return 0;
}

// Packet processing thread
void *packet_handler(void *args) {
    int sockfd = *(int *)args;
    struct sockaddr saddr;
    socklen_t saddr_len = sizeof(saddr);
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);

    if (buffer == NULL) {
        perror("Unable to allocate memory");
        close(sockfd);
        pthread_exit(NULL);
    }

    while (1) {
        // Receive raw packets
        int received_bytes = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, &saddr, &saddr_len);
        if (received_bytes < 0) {
            perror("Failed to receive packets");
            break;
        }

        struct iphdr *iph = (struct iphdr *)buffer;

        int protocol_type = allow_packet(iph->protocol);
        if (protocol_type) {
            if (protocol_type == ALLOW_TCP) {
                struct tcphdr *tcph = (struct tcphdr *)(buffer + iph->ihl * 4);
                printf("Packet allowed: TCP | Source Port: %d | Destination Port: %d\n", ntohs(tcph->source), ntohs(tcph->dest));
            } else if (protocol_type == ALLOW_UDP) {
                struct udphdr *udph = (struct udphdr *)(buffer + iph->ihl * 4);
                printf("Packet allowed: UDP | Source Port: %d | Destination Port: %d\n", ntohs(udph->source), ntohs(udph->dest));
            }
        } else {
            printf("Packet blocked: Unknown protocol\n");
        }
    }

    free(buffer);
    close(sockfd);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [tcp|udp]\n", argv[0]);
        return 1;
    }

    int sockfd;
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Socket creation failed for TCP");
        return 1;
    }

    if (strcmp(argv[1], "udp") == 0) {
        sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
        if (sockfd < 0) {
            perror("Socket creation failed for UDP");
            return 1;
        }
    }

    // Set socket options to include protocol headers (necessary for raw sockets)
    int opt = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(opt)) < 0) {
        perror("Setting socket options failed");
        close(sockfd);
        return 1;
    }

    pthread_t thread_id;
    
    // Start the packet handler thread
    if (pthread_create(&thread_id, NULL, packet_handler, (void *)&sockfd) != 0) {
        perror("Failed to create thread");
        close(sockfd);
        return 1;
    }

    // Join the thread
    pthread_join(thread_id, NULL);
    return 0;
}