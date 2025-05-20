//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 512

int check_website(char *host, int port) {
    int sockfd;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server.sin_addr) < 0) {
        return -1;
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        return -1;
    }
    snprintf(buffer, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host);
    write(sockfd, buffer, strlen(buffer));
    ssize_t n;
    while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, n, 1, stdout);
    }
    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 0;
    }
    char *host = argv[1];
    int port = atoi(argv[2]);
    while (1) {
        if (check_website(host, port) != 0) {
            printf("Website is down!\n");
        } else {
            printf("Website is up!\n");
        }
        usleep(5000000);
    }
    return 0;
}