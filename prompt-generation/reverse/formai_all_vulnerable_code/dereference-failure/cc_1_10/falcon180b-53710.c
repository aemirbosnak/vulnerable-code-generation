//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024

void die(const char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char hostname[MAX_HOST_NAME];
    strcpy(hostname, argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        die("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        close(sockfd);
        die("inet_pton");
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        close(sockfd);
        die("connect");
    }

    char data[MAX_DATA_SIZE];
    int bytes_received = recv(sockfd, data, MAX_DATA_SIZE, 0);
    if (bytes_received <= 0) {
        close(sockfd);
        die("recv");
    }

    printf("Ping response from %s:\n%s\n", hostname, data);

    close(sockfd);
    return 0;
}