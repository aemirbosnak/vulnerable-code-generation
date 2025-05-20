//Falcon-180B DATASET v1.0 Category: Networking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *host = argv[1];
    char *port = argv[2];
    char buffer[BUFFER_SIZE];
    int ret;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "socket failed: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    ret = inet_pton(AF_INET, host, &server_addr.sin_addr);
    if (ret <= 0) {
        fprintf(stderr, "inet_pton failed: %s\n", strerror(errno));
        exit(1);
    }

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        fprintf(stderr, "connect failed: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        ret = read(sockfd, buffer, BUFFER_SIZE);
        if (ret <= 0) {
            fprintf(stderr, "read failed: %s\n", strerror(errno));
            exit(1);
        }
        buffer[ret] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}