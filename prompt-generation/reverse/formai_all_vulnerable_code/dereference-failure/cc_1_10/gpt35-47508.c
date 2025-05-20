//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: configurable
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 16384

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in addr;
    char buffer[MAX_BUFFER_SIZE];
    int read_size;
    int port = 8080;
    char ip_address[16] = "127.0.0.1";

    if(argc > 2) {
        strcpy(ip_address, argv[1]);
        port = atoi(argv[2]);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Cannot create socket");
        return 1;
    }

    // Configure socket
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &(addr.sin_addr));

    // Bind socket to interface
    if(bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Cannot bind to interface");
        return 1;
    }

    // Monitor network packet
    while ((read_size = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, NULL, NULL)) > 0) {
        // Process packet 
        printf("%s:%d ->", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
        printf(" %s:%d\n", inet_ntoa(((struct sockaddr_in*)buffer)->sin_addr),
                           ntohs(((struct sockaddr_in*)buffer)->sin_port));
        printf("Payload:\n");
        printf("[HEX] ");
        for (int i = 0; i < read_size; i++) {
            printf("%02X ", (unsigned char)buffer[i]);
            if (i % 16 == 15) printf("\n      ");
        }
        printf("\n[ASCII] ");
        for (int i = 0; i < read_size; i++) {
            if (isprint(buffer[i]))
                printf("%c", buffer[i]);
            else
                printf(".");
            if (i % 16 == 15) printf("\n        ");
        }
        printf("\n");
    }
    return 0;
}