//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: ephemeral
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 65535

void monitor_packets(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in sender_addr;
    socklen_t addr_len = sizeof(sender_addr);

    while(1) {
        memset(buffer, 0, MAX_BUFFER_SIZE);
        recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr*)&sender_addr, &addr_len);
        printf("\nPacket received from %s:%d\n", inet_ntoa(sender_addr.sin_addr), ntohs(sender_addr.sin_port));
        printf("Packet contents:\n%s\n", buffer);
    }
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    int port;

    if(argc != 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        return -1;
    }

    port = atoi(argv[1]);
    if(port <= 0 || port > 65535) {
        printf("Invalid port number\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0) {
        printf("Error creating socket\n");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if(bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding the socket to the address and port\n");
        return -1;
    }

    printf("Packet monitor started on port %d\n", port);

    monitor_packets(sockfd);

    close(sockfd);

    return 0;
}