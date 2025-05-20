//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define MAX_PACKET_SIZE 1024

struct sockaddr_in source, dest;
unsigned char buffer[MAX_PACKET_SIZE];

void print_packet_info(unsigned char* buffer, int size) {
    // Print packet hexdump
    printf("Packet Dump:\n");
    for(int i = 0; i < size; i++) {
        printf("%02X ", buffer[i]);
        if((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n\n");
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return -1;
    }

    char* server_ip = argv[1];
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sock < 0) {
        perror("Could not create socket");
        return -1;
    }

    // Set SO_REUSEADDR option to allow reuse of same socket
    int opt = 1;
    if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        return -1;
    }

    // Bind socket to local port
    struct sockaddr_in local;
    memset((char *)&local, 0, sizeof(local));
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = INADDR_ANY;
    local.sin_port = htons(0);
    if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0) {
        perror("bind");
        return -1;
    }

    // Resolve server hostname to IP address
    struct hostent *he;
    if((he=gethostbyname(server_ip)) == NULL) {
        perror("gethostbyname");
        return -1;
    }

    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_addr = *((struct in_addr *)he->h_addr);
    dest.sin_port = htons(0);

    memset(&source, 0, sizeof(source));
    source.sin_family = AF_INET;
    source.sin_addr.s_addr = INADDR_ANY;
    source.sin_port = htons(0);

    int sent_packet_count = 0;
    while(1) {
        // Allocate random packet content
        memset(buffer, 0, MAX_PACKET_SIZE);
        for(int i = 0; i < MAX_PACKET_SIZE; i++) {
            buffer[i] = rand() % 256;
        }

        // Send UDP packet to server
        int ret = sendto(sock, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr*)&dest, sizeof(dest));
        if(ret < 0) {
            perror("sendto failed");
            return -1;
        }
        printf("Send packet %d (size: %d) to %s:%d\n", ++sent_packet_count, MAX_PACKET_SIZE, server_ip, ntohs(dest.sin_port));

        // Wait 1 second to simulate traffic periodicity
        sleep(1);

        // Receive UDP packet from server
        memset(buffer, 0, MAX_PACKET_SIZE);
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        ret = recvfrom(sock, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr*)&client_addr, &client_addr_len);
        if(ret < 0) {
            perror("recvfrom failed");
            return -1;
        }
        printf("Received packet containing %d bytes from %s:%d (to %s:%d)\n", ret, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), server_ip, ntohs(dest.sin_port));
        print_packet_info(buffer, ret);
    }

    close(sock);
    return 0;
}