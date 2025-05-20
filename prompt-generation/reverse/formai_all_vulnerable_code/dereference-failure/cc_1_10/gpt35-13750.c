//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: accurate
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

#define PACKET_SIZE 1024 // Define the size of packets to be monitored

void packet_monitor(char *ip, int port) {
    int sock = 0;
    struct sockaddr_in addr; // Structure to store internet address

    if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &addr.sin_addr);

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    while (1) { // Continuously monitor incoming packets
        char buffer[PACKET_SIZE] = {0};
        int recv_len = 0;
        struct sockaddr_in source_addr;
        socklen_t source_addr_len = sizeof(source_addr);

        if ((recv_len = recvfrom(sock, buffer, PACKET_SIZE, 0, 
            (struct sockaddr *)&source_addr, &source_addr_len)) < 0) {
            perror("Packet reception error");
            continue;
        }

        printf("Received packet of size %d bytes from %s:%d\n", recv_len, 
            inet_ntoa(source_addr.sin_addr), ntohs(source_addr.sin_port));

        // Parse the contents of the packet and perform any desired actions
        // ...

        memset(buffer, 0, PACKET_SIZE); // Clear the buffer for the next packet
    }
}

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 0;
    }

    char *ip = (char *)argv[1];
    int port = atoi(argv[2]);

    packet_monitor(ip, port);

    return 0;
}