//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: real-life
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void packet_monitor(char *ip_address, int port) {
    int sockfd, n;
    struct sockaddr_in server_address;

    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    server_address.sin_port = htons(port);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &(int){1}, sizeof(int)) < 0) {
        printf("Error setting socket options\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);

    printf("Packet Monitor Started...\n");

    while (1) {
        n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (n < 0) {
            printf("Error receiving data\n");
            continue;
        }
        printf("Received packet of size %d bytes\n", n);
        printf("%s\n", buffer);
    }

    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: ./packet_monitor [ip_address] [port]\n");
        exit(1);
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);

    packet_monitor(ip_address, port);
    return 0;
}