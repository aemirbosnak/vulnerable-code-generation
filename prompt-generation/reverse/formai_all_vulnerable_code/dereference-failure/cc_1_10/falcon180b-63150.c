//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT "80"
#define SERVER_NAME "www.google.com"
#define SOCKET_TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int total_bytes_received = 0;
    double start_time, end_time;
    double elapsed_time;
    int speed;

    if (argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(SERVER_NAME, SERVER_PORT, &hints, &servinfo)!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(gai_error()));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

        if (sockfd == -1) {
            perror("socket error");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect error");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Cannot connect to %s:%s\n", SERVER_NAME, SERVER_PORT);
        exit(1);
    }

    start_time = time(NULL);
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes_received += bytes_received;
    }
    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    speed = (double)total_bytes_received / elapsed_time;

    printf("Internet speed: %.2f kB/s\n", speed);

    close(sockfd);
    freeaddrinfo(servinfo);

    return 0;
}