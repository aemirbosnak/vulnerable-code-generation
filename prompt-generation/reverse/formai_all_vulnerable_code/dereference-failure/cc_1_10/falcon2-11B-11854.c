//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <time.h>
#include <sys/time.h>

#define BUF_SIZE 1024

void print_usage(const char* prog) {
    printf("Usage: %s <server_ip> <server_port>\n", prog);
    exit(0);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        print_usage(argv[0]);
    }

    char* server_ip = argv[1];
    int server_port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    bzero((char*)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        printf("Invalid server IP address\n");
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection to server failed\n");
        exit(1);
    }

    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    while (1) {
        int n = select(sockfd + 1, &readfds, NULL, NULL, &tv);
        if (n < 0) {
            perror("select error");
            exit(1);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            char buffer[BUF_SIZE];
            int bytes_read = read(sockfd, buffer, sizeof(buffer));
            if (bytes_read < 0) {
                perror("read error");
                exit(1);
            }
            printf("%s", buffer);
            send(sockfd, buffer, bytes_read, 0);
        }
    }

    close(sockfd);
    return 0;
}