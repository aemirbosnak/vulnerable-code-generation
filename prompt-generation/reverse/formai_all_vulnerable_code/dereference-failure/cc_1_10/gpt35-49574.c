//FormAI DATASET v1.0 Category: Network Ping Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PORT 80
#define MAX_TIMEOUTS 3
#define MAX_RETRIES 5

struct addrinfo* resolve_address(char* hostname) {
    struct addrinfo hints;
    struct addrinfo* results;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int error = getaddrinfo(hostname, NULL, &hints, &results);
    if (error != 0) {
        printf("Failed to resolve hostname: %s\n", gai_strerror(error));
        exit(1);
    }

    return results;
}

int ping_server(char* hostname, int retries, int timeout) {
    struct addrinfo* server;
    int sockfd, status;
    struct timeval tv;
    fd_set fds;

    server = resolve_address(hostname);

    sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sockfd == -1) {
        printf("Failed to create socket\n");
        exit(1);
    }

    status = connect(sockfd, server->ai_addr, server->ai_addrlen);
    if (status != 0) {
        printf("Failed to connect to server\n");
        close(sockfd);
        freeaddrinfo(server);
        return 0;
    }

    FD_ZERO(&fds);
    FD_SET(sockfd, &fds);

    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    status = send(sockfd, "PING", 4, 0);
    if (status <= 0) {
        printf("Failed to send ping\n");
        close(sockfd);
        freeaddrinfo(server);
        return 0;
    }

    status = select(sockfd+1, &fds, NULL, NULL, &tv);
    if (status == -1) {
        printf("Failed to select\n");
        close(sockfd);
        freeaddrinfo(server);
        return 0;
    } else if (status == 0) {
        printf("Timed out\n");
        close(sockfd);
        freeaddrinfo(server);
        return 0;
    }

    char buf[4];
    status = recv(sockfd, buf, 4, 0);
    if (status <= 0) {
        printf("Failed to receive response\n");
        close(sockfd);
        freeaddrinfo(server);
        return 0;
    }

    printf("%s is alive!\n", hostname);
    close(sockfd);
    freeaddrinfo(server);
    return 1;
}

int main() {
    char* servers[] = {"google.com", "facebook.com", "twitter.com"};
    int num_servers = sizeof(servers) / sizeof(servers[0]);
    int retries = MAX_RETRIES;
    int timeout = 1;
    int timeouts[num_servers];
    int i, j;

    for (i = 0; i < num_servers; i++) {
        timeouts[i] = 0;
    }

    for (i = 0; i < retries; i++) {
        for (j = 0; j < num_servers; j++) {
            if (timeouts[j] < MAX_TIMEOUTS) {
                int result = ping_server(servers[j], retries, timeout);
                if (result == 0) {
                    timeouts[j]++;
                } else {
                    timeouts[j] = 0;
                }
            }
        }
    }

    for (i = 0; i < num_servers; i++) {
        if (timeouts[i] == MAX_TIMEOUTS) {
            printf("%s is dead!\n", servers[i]);
        }
    }

    return 0;
}