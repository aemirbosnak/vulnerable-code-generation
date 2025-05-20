//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 5 // seconds

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <server address>\n", argv[0]);
        return -1;
    }
    char* server_address = argv[1];

    int sockfd;
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int s = getaddrinfo(server_address, "http", &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        return -1;
    }

    struct addrinfo *p;
    for (p = result; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }
        break;
    }
    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        return -1;
    }
    freeaddrinfo(result);

    printf("Connected to server\n");

    double total_time = 0;
    int i;
    for (i = 0; i < 10; i++) {
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        clock_t start = clock();

        ssize_t data_sent = write(sockfd, buffer, BUFFER_SIZE);
        if (data_sent < 0) {
            perror("write");
            return -1;
        }

        ssize_t data_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (data_received < 0) {
            perror("recv");
            return -1;
        }

        clock_t end = clock();
        total_time += ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Round %d: %ld bytes received in %f seconds \n", i + 1, data_received, (double) (end - start) / CLOCKS_PER_SEC);
    }

    close(sockfd);

    printf("Average response time: %f seconds\n", total_time / 10);

    return 0;
}