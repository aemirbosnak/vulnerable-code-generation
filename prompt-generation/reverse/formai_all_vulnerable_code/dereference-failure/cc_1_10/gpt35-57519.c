//FormAI DATASET v1.0 Category: Firewall ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 65535

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s [port]\n", argv[0]);
        printf("Example: %s 8080\n", argv[0]);
        exit(0);
    }
    int port = atoi(argv[1]);

    // Create a socket for listening incoming packets
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sock == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        exit(1);
    }
    
    // Set socket option to receive IP header along with the packet
    int opt = 1;
    if(setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(opt)) == -1) {
        printf("Failed to set socket options: %s\n", strerror(errno));
        exit(1);
    }

    // Bind the socket to the specified port
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = INADDR_ANY;
    if(bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1) {
        printf("Failed to bind socket: %s\n", strerror(errno));
        exit(1);
    }

    // Listen and forward incoming packets
    while(1) {
        char buffer[MAX_PACKET_SIZE];
        struct sockaddr_in sin_recv;
        socklen_t sin_len = sizeof(sin_recv);
        ssize_t packet_size = recvfrom(sock, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&sin_recv, &sin_len);
        if(packet_size == -1) {
            printf("Failed to receive packet: %s\n", strerror(errno));
            continue;
        }

        // Check if packet is incoming or outgoing
        if(sin_recv.sin_addr.s_addr == INADDR_ANY) {
            printf("Outgoing packet received\n");
        } else {
            printf("Incoming packet received\n");
        }

        // Forward packet
        if(sendto(sock, buffer, packet_size, 0, (struct sockaddr *)&sin_recv, sin_len) == -1) {
            printf("Failed to forward packet: %s\n", strerror(errno));
            continue;
        }
    }
}