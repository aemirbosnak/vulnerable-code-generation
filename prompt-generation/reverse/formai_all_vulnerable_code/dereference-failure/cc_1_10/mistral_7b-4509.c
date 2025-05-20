//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_PACKET_SIZE 64
#define TIMEOUT 5000
#define NUM_PACKETS 5

int main(int argc, char *argv[]) {
    int sockfd, i, j, status;
    char buffer[MAX_PACKET_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc != 2) {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(0);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    for (i = 0; i < NUM_PACKETS; i++) {
        sendto(sockfd, "ping", 4, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
        memset(buffer, 0, MAX_PACKET_SIZE);
        j = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, NULL, NULL);

        if (j > 0) {
            printf("Received %d bytes from %s: %s\n", j, inet_ntoa(serv_addr.sin_addr), buffer);
            status = 0;
        } else {
            printf("No response from %s\n", argv[1]);
            status = 1;
            break;
        }

        usleep(TIMEOUT);
    }

    close(sockfd);
    return status;
}