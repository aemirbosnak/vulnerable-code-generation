//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 64
#define TIMEOUT 500
#define SERVER_PORT 80
#define NUM_PACKETS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, i, j, status;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char packet[MAX_PACKET_SIZE], buffer[BUFFER_SIZE];
    fd_set readfds;
    struct timeval tv;

    if (argc != 2) {
        printf("Usage: %s <server_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(packet, 0, MAX_PACKET_SIZE);
    memset(buffer, 0, BUFFER_SIZE);

    if ((server = gethostbyname(argv[1])) == NULL) {
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server->h_addr_list[0], &server_addr.sin_addr);

    for (i = 0; i < NUM_PACKETS; i++) {
        sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        tv.tv_sec = TIMEOUT / 1000;
        tv.tv_usec = (TIMEOUT % 1000) * 1000;
        if (select(sockfd + 1, &readfds, NULL, NULL, &tv) <= 0) {
            printf("Packet %d timed out.\n", i + 1);
            continue;
        }
        if (recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL) > 0) {
            printf("Packet %d received with %d bytes: %s\n", i + 1, recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL), buffer);
            status = 0;
        } else {
            printf("Packet %d received error\n", i + 1);
            status = 1;
        }
        if (i == NUM_PACKETS - 1) {
            if (status == 0) {
                printf("Host %s is up\n", argv[1]);
            } else {
                printf("Host %s is down\n", argv[1]);
            }
        }
    }

    close(sockfd);
    return 0;
}