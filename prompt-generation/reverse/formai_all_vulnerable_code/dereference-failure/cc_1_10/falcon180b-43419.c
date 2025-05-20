//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_RETRIES 3
#define PING_INTERVAL 1 //seconds

void ping(int sockfd, struct sockaddr *addr) {
    char buffer[BUFFER_SIZE];
    int bytes_sent, bytes_received;
    struct timeval timeout;

    timeout.tv_sec = 0;
    timeout.tv_usec = 500000; //500ms

    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    for (int i = 0; i < MAX_RETRIES; i++) {
        bytes_sent = sendto(sockfd, "PING", strlen("PING"), 0, addr, sizeof(*addr));

        if (bytes_sent == -1) {
            printf("Sendto error: %s\n", strerror(errno));
            return;
        }

        bytes_received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);

        if (bytes_received == -1) {
            printf("Recvfrom error: %s\n", strerror(errno));
            continue;
        } else if (bytes_received == 0) {
            printf("No response received\n");
            continue;
        } else if (strcmp(buffer, "PONG") == 0) {
            printf("Ping successful\n");
            return;
        }
    }

    printf("Ping failed\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./ping <IP address> <port number>\n");
        return 1;
    }

    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == -1) {
        printf("Socket creation error: %s\n", strerror(errno));
        return 1;
    }

    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        printf("Connection error: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        ping(sockfd, (struct sockaddr *)&addr);
        sleep(PING_INTERVAL);
    }

    return 0;
}