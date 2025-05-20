//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define MAX_HOSTNAME_LEN 256
#define PING_TIMEOUT_MS 5000
#define PING_RETRY_COUNT 3
#define PING_RETRY_DELAY_MS 1000

int ping(const char* hostname, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    char* ip_addr = malloc(MAX_HOSTNAME_LEN);
    if (gethostbyname(hostname, ip_addr, MAX_HOSTNAME_LEN) == -1) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    inet_pton(AF_INET, ip_addr, &server_addr.sin_addr);

    struct timeval timeout;
    timeout.tv_sec = PING_TIMEOUT_MS / 1000;
    timeout.tv_usec = (PING_TIMEOUT_MS % 1000) * 1000;

    int retries = 0;
    while (retries < PING_RETRY_COUNT) {
        if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
            close(sockfd);
            return 0;
        } else if (errno!= ECONNREFUSED) {
            perror("connect");
            close(sockfd);
            return -1;
        }

        retries++;
        usleep(PING_RETRY_DELAY_MS * 1000);
    }

    close(sockfd);
    return -1;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    int result = ping(argv[1], atoi(argv[2]));
    if (result == 0) {
        printf("Host is reachable\n");
    } else {
        printf("Host is unreachable\n");
    }

    return result;
}