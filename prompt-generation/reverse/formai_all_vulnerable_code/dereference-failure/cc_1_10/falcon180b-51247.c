//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_NAME "speedtest.net"
#define SERVER_PORT 80

int main() {
    int sockfd, n;
    struct addrinfo hints, *serverinfo;
    char *server_ip;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time;

    srand(time(NULL));
    server_ip = rand() % 2? "www.speedtest.net" : "www2.speedtest.net";
    printf("Connecting to %s...\n", server_ip);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(server_ip, "http", &hints, &serverinfo)!= 0) {
        printf("getaddrinfo error\n");
        exit(1);
    }

    sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol);
    if (sockfd == -1) {
        printf("socket error\n");
        exit(1);
    }

    if (connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen) == -1) {
        printf("connect error\n");
        exit(1);
    }

    start_time = time(NULL);
    send(sockfd, "GET / HTTP/1.1\r\nHost: " SERVER_NAME "\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: " SERVER_NAME "\r\nConnection: close\r\n\r\n"), 0);
    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    end_time = time(NULL);

    close(sockfd);

    printf("\nTransfer rate: %d bytes/sec\n", (int)((double)n / (end_time - start_time)));

    return 0;
}