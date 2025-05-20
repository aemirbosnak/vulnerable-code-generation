//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 100

// Function to print the error message and exit
void error(char *message) {
    perror(message);
    exit(1);
}

// Function to send a ping packet
int send_ping(int sockfd, struct sockaddr *servaddr) {
    char buffer[MAX];
    int len = strlen("PING");
    strcpy(buffer, "PING");
    sendto(sockfd, buffer, len, 0, servaddr, strlen(servaddr));
    return 0;
}

// Function to receive a ping response
int receive_ping(int sockfd, struct sockaddr *servaddr, char *buffer, int len) {
    int n = recvfrom(sockfd, buffer, len, 0, servaddr, NULL);
    if (n <= 0) {
        error("Recvfrom error");
    }
    return 0;
}

// Function to perform a ping test
int ping_test(char *host, int count) {
    int sockfd, n, i;
    struct sockaddr_in servaddr;
    char buffer[MAX];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        error("Socket error");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, host, &servaddr.sin_addr);
    servaddr.sin_port = htons(7);

    for (i = 0; i < count; i++) {
        send_ping(sockfd, (struct sockaddr *)&servaddr);
        receive_ping(sockfd, (struct sockaddr *)&servaddr, buffer, MAX);
        if (strcmp(buffer, "PONG")!= 0) {
            printf("Host %s is not reachable\n", host);
            close(sockfd);
            return 1;
        }
    }

    printf("Host %s is reachable\n", host);
    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s host count\n", argv[0]);
        exit(1);
    }

    ping_test(argv[1], atoi(argv[2]));

    return 0;
}